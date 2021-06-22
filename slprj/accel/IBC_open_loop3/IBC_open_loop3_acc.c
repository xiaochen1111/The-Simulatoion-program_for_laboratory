#include <math.h>
#include "IBC_open_loop3_acc.h"
#include "IBC_open_loop3_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T IBC_open_loop3_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr
, int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay ,
int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T
bufSz = * bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ; real_T * xBuf = (
NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf
= * uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 )
: 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
IBC_open_loop3_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart
, real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } real_T look1_binlxpw ( real_T
u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) {
real_T frac ; real_T yL_0d0 ; uint32_T bpIdx ; uint32_T iLeft ; uint32_T
iRght ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / (
bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx =
maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U )
{ if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; }
bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [
iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = ( u0
- bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; }
yL_0d0 = table [ iLeft ] ; return ( table [ iLeft + 1U ] - yL_0d0 ) * frac +
yL_0d0 ; } void rt_ssGetBlockPath ( SimStruct * S , int_T sysIdx , int_T
blkIdx , char_T * * path ) { _ssGetBlockPath ( S , sysIdx , blkIdx , path ) ;
} void rt_ssSet_slErrMsg ( void * S , void * diag ) { SimStruct * castedS = (
SimStruct * ) S ; if ( ! _ssIsErrorStatusAslErrMsg ( castedS ) ) {
_ssSet_slErrMsg ( castedS , diag ) ; } else { _ssDiscardDiagnostic ( castedS
, diag ) ; } } void rt_ssReportDiagnosticAsWarning ( void * S , void * diag )
{ _ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } void
IBC_open_loop3_SampleIL1_Init ( SimStruct * S , B_SampleIL1_IBC_open_loop3_T
* localB , P_SampleIL1_IBC_open_loop3_T * localP ) { localB -> B_0_0_0 =
localP -> P_0 ; } void IBC_open_loop3_SampleIL1 ( SimStruct * S , boolean_T
rtu_Trigger , real_T rtu_In , B_SampleIL1_IBC_open_loop3_T * localB ,
DW_SampleIL1_IBC_open_loop3_T * localDW , ZCE_SampleIL1_IBC_open_loop3_T *
localZCE ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( rtu_Trigger && (
localZCE -> SampleIL1_Trig_ZCE != POS_ZCSIG ) ) { localB -> B_0_0_0 = rtu_In
; localDW -> SampleIL1_SubsysRanBC = 4 ; } localZCE -> SampleIL1_Trig_ZCE =
rtu_Trigger ; } } void IBC_open_loop3_SampleIL1_Term ( SimStruct * const S )
{ } static void mdlOutputs ( SimStruct * S , int_T tid ) { B_IBC_open_loop3_T
* _rtB ; DW_IBC_open_loop3_T * _rtDW ; P_IBC_open_loop3_T * _rtP ;
PrevZCX_IBC_open_loop3_T * _rtZCE ; X_IBC_open_loop3_T * _rtX ; real_T
rtb_B_4_20_0 ; real_T tmp ; int32_T isHit ; _rtDW = ( ( DW_IBC_open_loop3_T *
) ssGetRootDWork ( S ) ) ; _rtZCE = ( ( PrevZCX_IBC_open_loop3_T * )
_ssGetPrevZCSigState ( S ) ) ; _rtX = ( ( X_IBC_open_loop3_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_IBC_open_loop3_T * ) ssGetModelRtp ( S
) ) ; _rtB = ( ( B_IBC_open_loop3_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 4
, 0 , SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_4_5_0 = look1_binlxpw (
muDoubleScalarRem ( ssGetT ( S ) - _rtB -> B_4_2_0 , _rtB -> B_4_9_0_p ) ,
_rtP -> P_17 , _rtP -> P_16 , 2U ) ; _rtB -> B_4_6_0 = _rtP -> P_18 * _rtB ->
B_4_5_0 ; ssCallAccelRunBlock ( S , 4 , 7 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_4_8_0 = _rtP ->
P_19 * _rtB -> B_4_0_0 [ 16 ] ; _rtB -> B_4_9_0 = _rtP -> P_20 * _rtB ->
B_4_0_0 [ 9 ] ; _rtB -> B_4_10_0 = _rtP -> P_21 * _rtB -> B_4_0_0 [ 13 ] ;
_rtB -> B_4_11_0 = _rtP -> P_22 * _rtB -> B_4_0_0 [ 14 ] ; _rtB -> B_4_12_0 =
_rtP -> P_23 * _rtB -> B_4_0_0 [ 15 ] ; _rtB -> B_4_13_0 = ( _rtB -> B_4_10_0
+ _rtB -> B_4_11_0 ) + _rtB -> B_4_12_0 ; ssCallAccelRunBlock ( S , 4 , 14 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_4_15_0 = _rtB -> B_4_8_0_b - _rtB ->
B_4_5_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> Compare_Mode = ( _rtB -> B_4_15_0
<= IBC_open_loop3_rtC ( S ) -> B_4_3_0 ) ; } _rtB -> B_4_16_0 = _rtDW ->
Compare_Mode ; _rtB -> B_4_17_0 = ( uint8_T ) ( _rtB -> B_4_16_0 ? ( int32_T
) _rtP -> P_70 : 0 ) ; ssCallAccelRunBlock ( S , 4 , 18 , SS_CALL_MDL_OUTPUTS
) ; IBC_open_loop3_SampleIL1 ( S , _rtB -> B_4_16_0 , _rtB -> B_4_8_0 , &
_rtB -> SampleandHold1 , & _rtDW -> SampleandHold1 , & _rtZCE ->
SampleandHold1 ) ; rtb_B_4_20_0 = _rtB -> B_4_1_0 - _rtB -> SampleandHold1 .
B_0_0_0 ; _rtB -> B_4_21_0 = _rtP -> P_24 * rtb_B_4_20_0 ; } _rtB -> B_4_22_0
= _rtX -> Integrator_CSTATE ; _rtB -> B_4_23_0 = _rtB -> B_4_21_0 + _rtB ->
B_4_22_0 ; if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Saturation1_MODE =
_rtB -> B_4_23_0 >= _rtP -> P_26 ? 1 : _rtB -> B_4_23_0 > _rtP -> P_27 ? 0 :
- 1 ; } _rtB -> B_4_24_0 = _rtDW -> Saturation1_MODE == 1 ? _rtP -> P_26 :
_rtDW -> Saturation1_MODE == - 1 ? _rtP -> P_27 : _rtB -> B_4_23_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { IBC_open_loop3_SampleIL1 (
S , _rtB -> B_4_16_0 , _rtB -> B_4_8_0 , & _rtB -> SampleIL1 , & _rtDW ->
SampleIL1 , & _rtZCE -> SampleIL1 ) ; } _rtB -> B_4_26_0 = _rtB -> B_4_24_0 -
_rtB -> SampleIL1 . B_0_0_0 ; _rtB -> B_4_28_0 = _rtX -> Integrator_CSTATE_e
; _rtB -> B_4_29_0 = _rtP -> P_28 * _rtB -> B_4_26_0 + _rtB -> B_4_28_0 ; if
( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Saturation_MODE = _rtB ->
B_4_29_0 >= _rtP -> P_30 ? 1 : _rtB -> B_4_29_0 > _rtP -> P_31 ? 0 : - 1 ; }
_rtB -> B_4_30_0 = _rtDW -> Saturation_MODE == 1 ? _rtP -> P_30 : _rtDW ->
Saturation_MODE == - 1 ? _rtP -> P_31 : _rtB -> B_4_29_0 ;
ssCallAccelRunBlock ( S , 4 , 31 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> RelationalOperator_Mode = ( _rtB
-> B_4_2_0_c > _rtB -> B_4_5_0 ) ; } _rtB -> B_4_32_0 = _rtDW ->
RelationalOperator_Mode ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay1_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_32 ; _rtB -> B_4_33_0 =
IBC_open_loop3_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
_rtDW -> TransportDelay1_IWORK . CircularBufSize , & _rtDW ->
TransportDelay1_IWORK . Last , _rtDW -> TransportDelay1_IWORK . Tail , _rtDW
-> TransportDelay1_IWORK . Head , _rtP -> P_33 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> RelationalOperator1_Mode = ( _rtB
-> B_4_2_0_c > _rtB -> B_4_33_0 ) ; } _rtB -> B_4_34_0 = _rtDW ->
RelationalOperator1_Mode ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay2_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_34 ; _rtB -> B_4_35_0 =
IBC_open_loop3_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
_rtDW -> TransportDelay2_IWORK . CircularBufSize , & _rtDW ->
TransportDelay2_IWORK . Last , _rtDW -> TransportDelay2_IWORK . Tail , _rtDW
-> TransportDelay2_IWORK . Head , _rtP -> P_35 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> RelationalOperator2_Mode = ( _rtB
-> B_4_2_0_c > _rtB -> B_4_35_0 ) ; } _rtB -> B_4_36_0 = _rtDW ->
RelationalOperator2_Mode ; ssCallAccelRunBlock ( S , 4 , 37 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_4_38_0 = _rtB -> B_4_8_0_b - _rtB ->
B_4_33_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> Compare_Mode_j = ( _rtB ->
B_4_38_0 <= IBC_open_loop3_rtC ( S ) -> B_4_4_0 ) ; } _rtB -> B_4_39_0 =
_rtDW -> Compare_Mode_j ; } _rtB -> B_4_40_0 = _rtB -> B_4_8_0_b - _rtB ->
B_4_35_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> Compare_Mode_c = ( _rtB ->
B_4_40_0 <= IBC_open_loop3_rtC ( S ) -> B_4_5_0 ) ; } _rtB -> B_4_41_0 =
_rtDW -> Compare_Mode_c ; ssCallAccelRunBlock ( S , 4 , 42 ,
SS_CALL_MDL_OUTPUTS ) ; IBC_open_loop3_SampleIL1 ( S , _rtB -> B_4_39_0 ,
_rtB -> B_4_8_0 , & _rtB -> SampleIL2 , & _rtDW -> SampleIL2 , & _rtZCE ->
SampleIL2 ) ; IBC_open_loop3_SampleIL1 ( S , _rtB -> B_4_41_0 , _rtB ->
B_4_8_0 , & _rtB -> SampleIL3 , & _rtDW -> SampleIL3 , & _rtZCE -> SampleIL3
) ; ssCallAccelRunBlock ( S , 4 , 45 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 46 , SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_4_47_0
= _rtP -> P_36 * _rtB -> B_4_5_0 ; ssCallAccelRunBlock ( S , 4 , 48 ,
SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { ssCallAccelRunBlock ( S , 4 , 49 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 4
, 50 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_60_0 = _rtP -> P_37 * _rtB ->
B_4_0_0 [ 17 ] ; _rtB -> B_4_61_0 = _rtP -> P_38 * _rtB -> B_4_0_0 [ 19 ] ;
_rtB -> B_4_62_0 = _rtP -> P_39 * _rtB -> B_4_0_0 [ 18 ] ;
ssCallAccelRunBlock ( S , 4 , 63 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_4_79_0 = _rtB ->
B_4_34_0 ; _rtDW -> Step_MODE = ( ssGetTaskTime ( S , 1 ) >= _rtP -> P_40 ) ;
if ( _rtDW -> Step_MODE == 1 ) { tmp = _rtP -> P_42 ; } else { tmp = _rtP ->
P_41 ; } if ( tmp > _rtP -> P_43 ) { _rtB -> B_4_99_0 = _rtB -> B_4_36_0 ; }
else { _rtB -> B_4_99_0 = _rtB -> B_4_3_0 ; } _rtB -> B_4_100_0 = _rtB ->
B_4_32_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_4_110_0 = _rtP -> P_44 * _rtB -> B_4_0_0 [ 10 ] ; _rtB -> B_4_111_0 =
_rtP -> P_45 * _rtB -> B_4_0_0 [ 11 ] ; _rtB -> B_4_112_0 = _rtP -> P_46 *
_rtB -> B_4_0_0 [ 12 ] ; ssCallAccelRunBlock ( S , 4 , 113 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_4_140_0 = _rtP -> P_47 * _rtB -> B_4_26_0
; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_4_141_0
= _rtP -> P_48 * rtb_B_4_20_0 ; } ssCallAccelRunBlock ( S , 4 , 142 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 143 ,
SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { if ( ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> Compare_Mode_k = ( _rtB
-> B_4_5_0 == IBC_open_loop3_rtC ( S ) -> B_4_0_0 ) ; } _rtB -> B_4_144_0 =
_rtDW -> Compare_Mode_k ; if ( ssGetIsOkayToUpdateMode ( S ) ) { _rtDW ->
Compare_Mode_f = ( _rtB -> B_4_33_0 == IBC_open_loop3_rtC ( S ) -> B_4_1_0 )
; } _rtB -> B_4_145_0 = _rtDW -> Compare_Mode_f ; if (
ssGetIsOkayToUpdateMode ( S ) ) { _rtDW -> Compare_Mode_jh = ( _rtB ->
B_4_35_0 == IBC_open_loop3_rtC ( S ) -> B_4_2_0 ) ; } _rtB -> B_4_146_0 =
_rtDW -> Compare_Mode_jh ; ssCallAccelRunBlock ( S , 4 , 147 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 148 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 4 , 149 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_154_0 = look1_binlxpw ( muDoubleScalarRem
( ssGetT ( S ) - _rtB -> B_4_151_0 , _rtB -> B_4_10_0_c ) , _rtP -> P_50 ,
_rtP -> P_49 , 2U ) ; _rtB -> B_4_159_0 = look1_binlxpw ( muDoubleScalarRem (
ssGetT ( S ) - _rtB -> B_4_156_0 , _rtB -> B_4_11_0_f ) , _rtP -> P_52 , _rtP
-> P_51 , 2U ) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_53 ; _rtB -> B_4_160_0 =
IBC_open_loop3_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
_rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW ->
TransportDelay_IWORK . Head , _rtP -> P_54 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } _rtB -> B_4_165_0 = look1_binlxpw ( muDoubleScalarRem ( ssGetT ( S ) -
_rtB -> B_4_162_0 , _rtB -> B_4_12_0_g ) , _rtP -> P_56 , _rtP -> P_55 , 2U )
; ssCallAccelRunBlock ( S , 4 , 166 , SS_CALL_MDL_OUTPUTS ) ;
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID3 ( SimStruct * S ,
int_T tid ) { B_IBC_open_loop3_T * _rtB ; P_IBC_open_loop3_T * _rtP ; _rtP =
( ( P_IBC_open_loop3_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_IBC_open_loop3_T * ) _ssGetModelBlockIO ( S ) ) ; memcpy ( & _rtB ->
B_4_0_0_m [ 0 ] , & _rtP -> P_57 [ 0 ] , 9U * sizeof ( real_T ) ) ; _rtB ->
B_4_1_0 = _rtP -> P_58 ; _rtB -> B_4_2_0_c = _rtP -> P_59 ; _rtB -> B_4_3_0 =
_rtP -> P_60 ; _rtB -> B_4_4_0 = _rtP -> P_61 ; _rtB -> B_4_5_0_k = _rtP ->
P_62 ; _rtB -> B_4_6_0_c = _rtP -> P_63 ; _rtB -> B_4_7_0 = _rtP -> P_64 ;
_rtB -> B_4_8_0_b = _rtP -> P_65 ; _rtB -> B_4_9_0_p = _rtP -> P_66 ; _rtB ->
B_4_10_0_c = _rtP -> P_67 ; _rtB -> B_4_11_0_f = _rtP -> P_68 ; _rtB ->
B_4_12_0_g = _rtP -> P_69 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_IBC_open_loop3_T *
_rtB ; DW_IBC_open_loop3_T * _rtDW ; P_IBC_open_loop3_T * _rtP ; int32_T
isHit ; _rtDW = ( ( DW_IBC_open_loop3_T * ) ssGetRootDWork ( S ) ) ; _rtP = (
( P_IBC_open_loop3_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_IBC_open_loop3_T * ) _ssGetModelBlockIO ( S ) ) ; isHit = ssIsSampleHit ( S
, 2 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 4 , 0 ,
SS_CALL_MDL_UPDATE ) ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay1_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay1_IWORK . Head = ( ( _rtDW -> TransportDelay1_IWORK .
Head < ( _rtDW -> TransportDelay1_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW
-> TransportDelay1_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay1_IWORK . Head == _rtDW -> TransportDelay1_IWORK . Tail ) { if
( ! IBC_open_loop3_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay1_IWORK . CircularBufSize , & _rtDW -> TransportDelay1_IWORK .
Tail , & _rtDW -> TransportDelay1_IWORK . Head , & _rtDW ->
TransportDelay1_IWORK . Last , simTime - _rtP -> P_32 , uBuffer , ( boolean_T
) 0 , false , & _rtDW -> TransportDelay1_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay1_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay1_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay1_IWORK . Head ] = _rtB -> B_4_154_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay2_PWORK . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay2_IWORK . Head = ( ( _rtDW ->
TransportDelay2_IWORK . Head < ( _rtDW -> TransportDelay2_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay2_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay2_IWORK . Head == _rtDW ->
TransportDelay2_IWORK . Tail ) { if ( !
IBC_open_loop3_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay2_IWORK . CircularBufSize , & _rtDW -> TransportDelay2_IWORK .
Tail , & _rtDW -> TransportDelay2_IWORK . Head , & _rtDW ->
TransportDelay2_IWORK . Last , simTime - _rtP -> P_34 , uBuffer , ( boolean_T
) 0 , false , & _rtDW -> TransportDelay2_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay2_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay2_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay2_IWORK . Head ] = _rtB -> B_4_159_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK . Head = ( ( _rtDW ->
TransportDelay_IWORK . Head < ( _rtDW -> TransportDelay_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay_IWORK . Head == _rtDW -> TransportDelay_IWORK
. Tail ) { if ( ! IBC_open_loop3_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW
-> TransportDelay_IWORK . CircularBufSize , & _rtDW -> TransportDelay_IWORK .
Tail , & _rtDW -> TransportDelay_IWORK . Head , & _rtDW ->
TransportDelay_IWORK . Last , simTime - _rtP -> P_53 , uBuffer , ( boolean_T
) 0 , false , & _rtDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = _rtB -> B_4_165_0 ; } UNUSED_PARAMETER ( tid
) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_IBC_open_loop3_T * _rtB ;
XDot_IBC_open_loop3_T * _rtXdot ; _rtXdot = ( ( XDot_IBC_open_loop3_T * )
ssGetdX ( S ) ) ; _rtB = ( ( B_IBC_open_loop3_T * ) _ssGetModelBlockIO ( S )
) ; _rtXdot -> Integrator_CSTATE = _rtB -> B_4_141_0 ; _rtXdot ->
Integrator_CSTATE_e = _rtB -> B_4_140_0 ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_IBC_open_loop3_T * _rtB ;
P_IBC_open_loop3_T * _rtP ; ZCV_IBC_open_loop3_T * _rtZCSV ; _rtZCSV = ( (
ZCV_IBC_open_loop3_T * ) ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( (
P_IBC_open_loop3_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_IBC_open_loop3_T
* ) _ssGetModelBlockIO ( S ) ) ; _rtZCSV -> Compare_RelopInput_ZC = _rtB ->
B_4_15_0 - IBC_open_loop3_rtC ( S ) -> B_4_3_0 ; _rtZCSV ->
Saturation1_UprLim_ZC = _rtB -> B_4_23_0 - _rtP -> P_26 ; _rtZCSV ->
Saturation1_LwrLim_ZC = _rtB -> B_4_23_0 - _rtP -> P_27 ; _rtZCSV ->
Saturation_UprLim_ZC = _rtB -> B_4_29_0 - _rtP -> P_30 ; _rtZCSV ->
Saturation_LwrLim_ZC = _rtB -> B_4_29_0 - _rtP -> P_31 ; _rtZCSV ->
RelationalOperator_RelopInput_ZC = _rtB -> B_4_2_0_c - _rtB -> B_4_5_0 ;
_rtZCSV -> RelationalOperator1_RelopInput_ZC = _rtB -> B_4_2_0_c - _rtB ->
B_4_33_0 ; _rtZCSV -> RelationalOperator2_RelopInput_ZC = _rtB -> B_4_2_0_c -
_rtB -> B_4_35_0 ; _rtZCSV -> Compare_RelopInput_ZC_f = _rtB -> B_4_38_0 -
IBC_open_loop3_rtC ( S ) -> B_4_4_0 ; _rtZCSV -> Compare_RelopInput_ZC_h =
_rtB -> B_4_40_0 - IBC_open_loop3_rtC ( S ) -> B_4_5_0 ; _rtZCSV ->
Step_StepTime_ZC = ssGetT ( S ) - _rtP -> P_40 ; _rtZCSV ->
Compare_RelopInput_ZC_j = _rtB -> B_4_5_0 - IBC_open_loop3_rtC ( S ) ->
B_4_0_0 ; _rtZCSV -> Compare_RelopInput_ZC_g = _rtB -> B_4_33_0 -
IBC_open_loop3_rtC ( S ) -> B_4_1_0 ; _rtZCSV -> Compare_RelopInput_ZC_o =
_rtB -> B_4_35_0 - IBC_open_loop3_rtC ( S ) -> B_4_2_0 ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 724955154U
) ; ssSetChecksumVal ( S , 1 , 3394252110U ) ; ssSetChecksumVal ( S , 2 ,
3714687224U ) ; ssSetChecksumVal ( S , 3 , 2859961531U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "10.3" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( DW_IBC_open_loop3_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_IBC_open_loop3_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_IBC_open_loop3_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & IBC_open_loop3_rtDefaultP ) ; _ssSetConstBlockIO ( S , &
IBC_open_loop3_rtInvariant ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; }
static void mdlInitializeSampleTimes ( SimStruct * S ) { slAccRegPrmChangeFcn
( S , mdlOutputsTID3 ) ; } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
