#include "rt_logging_mmi.h"
#include "IBC1_capi.h"
#include <math.h>
#include "IBC1.h"
#include "IBC1_private.h"
#include "IBC1_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.5 (R2021a) 14-Nov-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ;
if ( istransportdelay ) { numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; }
testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <=
tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T *
tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T
newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr ) { *
maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer *
newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false )
; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * uBuf ,
int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T
initOutput , boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput )
{ int_T i ; real_T yout , t1 , t2 , u1 , u2 ; real_T * tBuf = uBuf + bufSz ;
if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ; uint32_T bpIdx ;
uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac
= ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [
maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while
( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else {
iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [
iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft =
maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] -
bp0 [ maxIndex - 1U ] ) ; } yL_0d0 = table [ iLeft ] ; return ( table [ iLeft
+ 1U ] - yL_0d0 ) * frac + yL_0d0 ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void nljhrmd2hu (
jfroyqp1l2 * localB , ci4qpemhrm * localP ) { localB -> gqyueovf0x = localP
-> _Y0 ; } void hhoyo4a5hd ( SimStruct * rtS_e , boolean_T lqdbga2zcp ,
real_T njlsbuv1yy , jfroyqp1l2 * localB , lanvlpt135 * localDW , au24en4dzs *
localZCE ) { if ( ssIsMajorTimeStep ( rtS_e ) ) { if ( lqdbga2zcp && (
localZCE -> dp1i3lb5ph != POS_ZCSIG ) ) { localB -> gqyueovf0x = njlsbuv1yy ;
localDW -> ikjnmtqwv0 = 4 ; } localZCE -> dp1i3lb5ph = lqdbga2zcp ; } } void
MdlInitialize ( void ) { { int32_T i , j ; real_T * As = ( real_T * ) rtDW .
gr1muksbyf . AS ; real_T * Bs = ( real_T * ) rtDW . gr1muksbyf . BS ; real_T
* Cs = ( real_T * ) rtDW . gr1muksbyf . CS ; real_T * Ds = ( real_T * ) rtDW
. gr1muksbyf . DS ; real_T * X0 = ( real_T * ) & rtDW . kbsai0di0v [ 0 ] ;
for ( i = 0 ; i < 4 ; i ++ ) { X0 [ i ] = ( rtP . StateSpace_X0_param [ i ] )
; } for ( i = 0 ; i < 4 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) As [ i * 4 +
j ] = ( rtP . StateSpace_AS_param [ i + j * 4 ] ) ; for ( j = 0 ; j < 13 ; j
++ ) Bs [ i * 13 + j ] = ( rtP . StateSpace_BS_param [ i + j * 4 ] ) ; } for
( i = 0 ; i < 17 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) Cs [ i * 4 + j ] = (
rtP . StateSpace_CS_param [ i + j * 17 ] ) ; } for ( i = 0 ; i < 17 ; i ++ )
{ for ( j = 0 ; j < 13 ; j ++ ) Ds [ i * 13 + j ] = ( rtP .
StateSpace_DS_param [ i + j * 17 ] ) ; } { int_T * switch_status = ( int_T *
) rtDW . gr1muksbyf . SWITCH_STATUS ; int_T * gState = ( int_T * ) rtDW .
gr1muksbyf . G_STATE ; real_T * yswitch = ( real_T * ) rtDW . gr1muksbyf .
Y_SWITCH ; int_T * switchTypes = ( int_T * ) rtDW . gr1muksbyf . SWITCH_TYPES
; int_T * idxOutSw = ( int_T * ) rtDW . gr1muksbyf . IDX_OUT_SW ; int_T *
switch_status_init = ( int_T * ) rtDW . gr1muksbyf . SWITCH_STATUS_INIT ;
switch_status [ 0 ] = 0 ; switch_status_init [ 0 ] = 0 ; gState [ 0 ] = (
int_T ) 0.0 ; yswitch [ 0 ] = 1 / 0.1 ; switchTypes [ 0 ] = ( int_T ) 1.0 ;
idxOutSw [ 0 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 1 ] = 0 ;
switch_status_init [ 1 ] = 0 ; gState [ 1 ] = ( int_T ) 0.0 ; yswitch [ 1 ] =
1 / 0.1 ; switchTypes [ 1 ] = ( int_T ) 1.0 ; idxOutSw [ 1 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 2 ] = 0 ; switch_status_init [ 2 ] = 0 ; gState [
2 ] = ( int_T ) 0.0 ; yswitch [ 2 ] = 1 / 0.1 ; switchTypes [ 2 ] = ( int_T )
1.0 ; idxOutSw [ 2 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 3 ] = 0 ;
switch_status_init [ 3 ] = 0 ; gState [ 3 ] = ( int_T ) 0.0 ; yswitch [ 3 ] =
1 / 0.001 ; switchTypes [ 3 ] = ( int_T ) 3.0 ; idxOutSw [ 3 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 4 ] = 0 ; switch_status_init [ 4 ] = 0 ; gState [
4 ] = ( int_T ) 0.0 ; yswitch [ 4 ] = 1 / 0.001 ; switchTypes [ 4 ] = ( int_T
) 3.0 ; idxOutSw [ 4 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 5 ] = 0 ;
switch_status_init [ 5 ] = 0 ; gState [ 5 ] = ( int_T ) 0.0 ; yswitch [ 5 ] =
1 / 0.001 ; switchTypes [ 5 ] = ( int_T ) 3.0 ; idxOutSw [ 5 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 6 ] = 0 ; switch_status_init [ 6 ] = 0 ; gState [
6 ] = ( int_T ) 0.0 ; yswitch [ 6 ] = 1 / 0.01 ; switchTypes [ 6 ] = ( int_T
) 3.0 ; idxOutSw [ 6 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 7 ] = 0 ;
switch_status_init [ 7 ] = 0 ; gState [ 7 ] = ( int_T ) 0.0 ; yswitch [ 7 ] =
1 / 0.01 ; switchTypes [ 7 ] = ( int_T ) 3.0 ; idxOutSw [ 7 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 8 ] = 0 ; switch_status_init [ 8 ] = 0 ; gState [
8 ] = ( int_T ) 0.0 ; yswitch [ 8 ] = 1 / 0.01 ; switchTypes [ 8 ] = ( int_T
) 3.0 ; idxOutSw [ 8 ] = ( ( int_T ) 0.0 ) - 1 ; } } rtX . hbkyjaqpk0 = rtP .
PIDController1_InitialConditionForIntegrator ; rtX . k1kxb5arpk = rtP .
PIDController_InitialConditionForIntegrator ; rtX . ma50ol3eb4 [ 0 ] = 0.0 ;
rtX . ma50ol3eb4 [ 1 ] = 0.0 ; nljhrmd2hu ( & rtB . hhoyo4a5hdp , & rtP .
hhoyo4a5hdp ) ; nljhrmd2hu ( & rtB . adxwqzxxlf , & rtP . adxwqzxxlf ) ; }
void MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ; void
* pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { rtDW . gr1muksbyf . AS = ( real_T * ) calloc ( 4 * 4 , sizeof ( real_T )
) ; rtDW . gr1muksbyf . BS = ( real_T * ) calloc ( 4 * 13 , sizeof ( real_T )
) ; rtDW . gr1muksbyf . CS = ( real_T * ) calloc ( 17 * 4 , sizeof ( real_T )
) ; rtDW . gr1muksbyf . DS = ( real_T * ) calloc ( 17 * 13 , sizeof ( real_T
) ) ; rtDW . gr1muksbyf . DX_COL = ( real_T * ) calloc ( 17 , sizeof ( real_T
) ) ; rtDW . gr1muksbyf . TMP2 = ( real_T * ) calloc ( 13 , sizeof ( real_T )
) ; rtDW . gr1muksbyf . BD_COL = ( real_T * ) calloc ( 4 , sizeof ( real_T )
) ; rtDW . gr1muksbyf . TMP1 = ( real_T * ) calloc ( 4 , sizeof ( real_T ) )
; rtDW . gr1muksbyf . XTMP = ( real_T * ) calloc ( 4 , sizeof ( real_T ) ) ;
rtDW . gr1muksbyf . SWITCH_STATUS = ( int_T * ) calloc ( 9 , sizeof ( int_T )
) ; rtDW . gr1muksbyf . SW_CHG = ( int_T * ) calloc ( 9 , sizeof ( int_T ) )
; rtDW . gr1muksbyf . G_STATE = ( int_T * ) calloc ( 9 , sizeof ( int_T ) ) ;
rtDW . gr1muksbyf . Y_SWITCH = ( real_T * ) calloc ( 9 , sizeof ( real_T ) )
; rtDW . gr1muksbyf . SWITCH_TYPES = ( int_T * ) calloc ( 9 , sizeof ( int_T
) ) ; rtDW . gr1muksbyf . IDX_OUT_SW = ( int_T * ) calloc ( 9 , sizeof (
int_T ) ) ; rtDW . gr1muksbyf . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 9 ,
sizeof ( int_T ) ) ; rtDW . gr1muksbyf . USWLAST = ( real_T * ) calloc ( 9 ,
sizeof ( real_T ) ) ; } { char ptrKey [ 1024 ] ; { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } rtDW . coigdooovo . Tail = 0 ; rtDW . coigdooovo . Head = 0 ; rtDW
. coigdooovo . Last = 0 ; rtDW . coigdooovo . CircularBufSize = 1024 ;
pBuffer [ 0 ] = rtP . TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT
( rtS ) ; rtDW . layaov5mlt . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ]
; sprintf ( ptrKey , "IBC1/命令信号生产/Transport\nDelay1_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
layaov5mlt . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , NULL ,
NULL ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . nen2ftgc0l . Tail = 0 ; rtDW . nen2ftgc0l . Head = 0 ; rtDW .
nen2ftgc0l . Last = 0 ; rtDW . nen2ftgc0l . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay2_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . e5i1astk5k . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey , "IBC1/命令信号生产/Transport\nDelay2_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
e5i1astk5k . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , NULL ,
NULL ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . lkazb3z1og . Tail = 0 ; rtDW . lkazb3z1og . Head = 0 ; rtDW .
lkazb3z1og . Last = 0 ; rtDW . lkazb3z1og . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . nmpmd1jh5e . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; sprintf
( ptrKey , "IBC1/命令信号生产/Transport\nDelay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
nmpmd1jh5e . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , NULL ,
NULL ) ; } } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { boolean_T
cspoaxzzcz ; real_T kxu0aoeena ; real_T tmp ; srClearBC ( rtDW . hhoyo4a5hdp
. ikjnmtqwv0 ) ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { { real_T accum ;
int_T * switch_status = ( int_T * ) rtDW . gr1muksbyf . SWITCH_STATUS ; int_T
* switch_status_init = ( int_T * ) rtDW . gr1muksbyf . SWITCH_STATUS_INIT ;
int_T * SwitchChange = ( int_T * ) rtDW . gr1muksbyf . SW_CHG ; int_T *
gState = ( int_T * ) rtDW . gr1muksbyf . G_STATE ; real_T * yswitch = (
real_T * ) rtDW . gr1muksbyf . Y_SWITCH ; int_T * switchTypes = ( int_T * )
rtDW . gr1muksbyf . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * ) rtDW .
gr1muksbyf . IDX_OUT_SW ; real_T * DxCol = ( real_T * ) rtDW . gr1muksbyf .
DX_COL ; real_T * tmp2 = ( real_T * ) rtDW . gr1muksbyf . TMP2 ; real_T *
BDcol = ( real_T * ) rtDW . gr1muksbyf . BD_COL ; real_T * tmp1 = ( real_T *
) rtDW . gr1muksbyf . TMP1 ; real_T * uswlast = ( real_T * ) rtDW .
gr1muksbyf . USWLAST ; int_T newState ; int_T swChanged = 0 ; int loopsToDo =
20 ; real_T temp ; memcpy ( switch_status_init , switch_status , 9 * sizeof (
int_T ) ) ; memcpy ( uswlast , & rtB . odazhmwpn0 [ 0 ] , 9 * sizeof ( real_T
) ) ; do { if ( loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0
; i1 < 9 ; i1 ++ ) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init
[ i1 ] - switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ]
= switch_status_init [ i1 ] ; } } } else { real_T * Cs = ( real_T * ) rtDW .
gr1muksbyf . CS ; real_T * Ds = ( real_T * ) rtDW . gr1muksbyf . DS ; { int_T
i1 ; real_T * y0 = & rtB . odazhmwpn0 [ 0 ] ; for ( i1 = 0 ; i1 < 17 ; i1 ++
) { accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . kbsai0di0v [ 0 ] ; accum += *
( Cs ++ ) * rtDW . kbsai0di0v [ 1 ] ; accum += * ( Cs ++ ) * rtDW .
kbsai0di0v [ 2 ] ; accum += * ( Cs ++ ) * rtDW . kbsai0di0v [ 3 ] ; { int_T
i2 ; const real_T * u0 = & rtP . SwitchCurrents_Value [ 0 ] ; for ( i2 = 0 ;
i2 < 9 ; i2 ++ ) { accum += * ( Ds ++ ) * u0 [ i2 ] ; } accum += * ( Ds ++ )
* rtP . IBC_Vin ; accum += * ( Ds ++ ) * rtP . eee_Value ; accum += * ( Ds ++
) * rtP . eee_Value_pohmtfwesc ; accum += * ( Ds ++ ) * rtP .
eee_Value_jlbhkxjaia ; } y0 [ i1 ] = accum ; } } swChanged = 0 ; { int_T i1 ;
real_T * y0 = & rtB . odazhmwpn0 [ 0 ] ; for ( i1 = 0 ; i1 < 9 ; i1 ++ ) {
switch ( switchTypes [ i1 ] ) { case 1 : newState = gState [ i1 ] > 0 ? 1 : 0
; break ; case 3 : newState = y0 [ i1 ] > 0.0 ? 1 : ( ( y0 [ i1 ] < 0.0 ) ? 0
: switch_status [ i1 ] ) ; break ; } swChanged = ( ( SwitchChange [ i1 ] =
newState - switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1
] = newState ; } } } if ( swChanged ) { real_T * As = ( real_T * ) rtDW .
gr1muksbyf . AS ; real_T * Cs = ( real_T * ) rtDW . gr1muksbyf . CS ; real_T
* Bs = ( real_T * ) rtDW . gr1muksbyf . BS ; real_T * Ds = ( real_T * ) rtDW
. gr1muksbyf . DS ; real_T a1 ; { int_T i1 ; for ( i1 = 0 ; i1 < 9 ; i1 ++ )
{ if ( SwitchChange [ i1 ] != 0 ) { a1 = yswitch [ i1 ] * SwitchChange [ i1 ]
; temp = 1 / ( 1 - Ds [ i1 * 14 ] * a1 ) ; { int_T i2 ; for ( i2 = 0 ; i2 <
17 ; i2 ++ ) { DxCol [ i2 ] = Ds [ i2 * 13 + i1 ] * temp * a1 ; } } DxCol [
i1 ] = temp ; BDcol [ 0 ] = Bs [ 0 + i1 ] * a1 ; BDcol [ 1 ] = Bs [ 13 + i1 ]
* a1 ; BDcol [ 2 ] = Bs [ 26 + i1 ] * a1 ; BDcol [ 3 ] = Bs [ 39 + i1 ] * a1
; memcpy ( tmp1 , & Cs [ i1 * 4 ] , 4 * sizeof ( real_T ) ) ; memset ( & Cs [
i1 * 4 ] , '\0' , 4 * sizeof ( real_T ) ) ; memcpy ( tmp2 , & Ds [ i1 * 13 ]
, 13 * sizeof ( real_T ) ) ; memset ( & Ds [ i1 * 13 ] , '\0' , 13 * sizeof (
real_T ) ) ; { int_T i2 ; for ( i2 = 0 ; i2 < 17 ; i2 ++ ) { a1 = DxCol [ i2
] ; Cs [ i2 * 4 + 0 ] += a1 * tmp1 [ 0 ] ; Cs [ i2 * 4 + 1 ] += a1 * tmp1 [ 1
] ; Cs [ i2 * 4 + 2 ] += a1 * tmp1 [ 2 ] ; Cs [ i2 * 4 + 3 ] += a1 * tmp1 [ 3
] ; { int_T i3 ; for ( i3 = 0 ; i3 < 13 ; i3 ++ ) { Ds [ i2 * 13 + i3 ] += a1
* tmp2 [ i3 ] ; } } } } a1 = BDcol [ 0 ] ; As [ 0 + 0 ] += a1 * Cs [ i1 * 4 +
0 ] ; As [ 0 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 0 + 2 ] += a1 * Cs [ i1 *
4 + 2 ] ; As [ 0 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0
; i2 < 13 ; i2 ++ ) { Bs [ 0 + i2 ] += a1 * Ds [ i1 * 13 + i2 ] ; } } a1 =
BDcol [ 1 ] ; As [ 4 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 4 + 1 ] += a1 *
Cs [ i1 * 4 + 1 ] ; As [ 4 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 4 + 3 ] +=
a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 13 ; i2 ++ ) { Bs [
13 + i2 ] += a1 * Ds [ i1 * 13 + i2 ] ; } } a1 = BDcol [ 2 ] ; As [ 8 + 0 ]
+= a1 * Cs [ i1 * 4 + 0 ] ; As [ 8 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 8 +
2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 8 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; {
int_T i2 ; for ( i2 = 0 ; i2 < 13 ; i2 ++ ) { Bs [ 26 + i2 ] += a1 * Ds [ i1
* 13 + i2 ] ; } } a1 = BDcol [ 3 ] ; As [ 12 + 0 ] += a1 * Cs [ i1 * 4 + 0 ]
; As [ 12 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 12 + 2 ] += a1 * Cs [ i1 * 4
+ 2 ] ; As [ 12 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ;
i2 < 13 ; i2 ++ ) { Bs [ 39 + i2 ] += a1 * Ds [ i1 * 13 + i2 ] ; } } } } } }
} while ( swChanged > 0 && -- loopsToDo > 0 ) ; if ( loopsToDo == 0 ) {
real_T * Cs = ( real_T * ) rtDW . gr1muksbyf . CS ; real_T * Ds = ( real_T *
) rtDW . gr1muksbyf . DS ; { int_T i1 ; real_T * y0 = & rtB . odazhmwpn0 [ 0
] ; for ( i1 = 0 ; i1 < 17 ; i1 ++ ) { accum = 0.0 ; accum += * ( Cs ++ ) *
rtDW . kbsai0di0v [ 0 ] ; accum += * ( Cs ++ ) * rtDW . kbsai0di0v [ 1 ] ;
accum += * ( Cs ++ ) * rtDW . kbsai0di0v [ 2 ] ; accum += * ( Cs ++ ) * rtDW
. kbsai0di0v [ 3 ] ; { int_T i2 ; const real_T * u0 = & rtP .
SwitchCurrents_Value [ 0 ] ; for ( i2 = 0 ; i2 < 9 ; i2 ++ ) { accum += * (
Ds ++ ) * u0 [ i2 ] ; } accum += * ( Ds ++ ) * rtP . IBC_Vin ; accum += * (
Ds ++ ) * rtP . eee_Value ; accum += * ( Ds ++ ) * rtP . eee_Value_pohmtfwesc
; accum += * ( Ds ++ ) * rtP . eee_Value_jlbhkxjaia ; } y0 [ i1 ] = accum ; }
} } { int_T i1 ; real_T * y1 = & rtB . oukfsqx50f [ 0 ] ; for ( i1 = 0 ; i1 <
9 ; i1 ++ ) { y1 [ i1 ] = ( real_T ) switch_status [ i1 ] ; } } } rtB .
avcatdltyc = rtP . donotdeletethisgain_Gain * rtB . odazhmwpn0 [ 9 ] ; } rtB
. otoroldxt1 = look1_binlxpw ( muDoubleScalarRem ( ssGetT ( rtS ) - 0.0 , rtP
. Constant_Value_gsv0vdx1vo ) , rtP . LookUpTable1_bp01Data , rtP .
RepeatingSequence_rep_seq_y , 2U ) ; { real_T * * uBuffer = ( real_T * * ) &
rtDW . layaov5mlt . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - ( 1.0 / rtP . _Fs / 3.0 ) ; rtB . lhmqma0bj3 =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . coigdooovo .
CircularBufSize , & rtDW . coigdooovo . Last , rtDW . coigdooovo . Tail ,
rtDW . coigdooovo . Head , rtP . TransportDelay1_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . e5i1astk5k .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - ( 2.0 / rtP . _Fs / 3.0 ) ; rtB . pkmdbed0es = rt_TDelayInterpolate
( tMinusDelay , 0.0 , * uBuffer , rtDW . nen2ftgc0l . CircularBufSize , &
rtDW . nen2ftgc0l . Last , rtDW . nen2ftgc0l . Tail , rtDW . nen2ftgc0l .
Head , rtP . TransportDelay2_InitOutput , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS
) ) ) ) ; } rtB . cl2qzwvkbj [ 0 ] = rtP . Gain_Gain * rtB . otoroldxt1 ; rtB
. cl2qzwvkbj [ 1 ] = rtP . Gain_Gain * rtB . lhmqma0bj3 ; rtB . cl2qzwvkbj [
2 ] = rtP . Gain_Gain * rtB . pkmdbed0es ; if ( ssIsSampleHit ( rtS , 2 , 0 )
) { rtB . c0t5jmfaeg = rtP . donotdeletethisgain_Gain_dojjjvjkoc * rtB .
odazhmwpn0 [ 13 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetIsOkayToUpdateMode ( rtS ) ) { rtDW . hzzdjgpnti = ( rtB . hvvgc3xdmn >
rtB . otoroldxt1 ) ; } rtB . bn0ratt3ev = rtDW . hzzdjgpnti ; if (
ssGetIsOkayToUpdateMode ( rtS ) ) { rtDW . ovfa2w42nr = ( rtB . hvvgc3xdmn >
rtB . lhmqma0bj3 ) ; } rtB . brs0dgmc1a = rtDW . ovfa2w42nr ; if (
ssGetIsOkayToUpdateMode ( rtS ) ) { rtDW . humgsssfcu = ( rtB . hvvgc3xdmn >
rtB . pkmdbed0es ) ; } rtB . efbnt10xks = rtDW . humgsssfcu ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . cwpjvxmr0i = rtP .
donotdeletethisgain_Gain_cswjbtqcc2 * rtB . odazhmwpn0 [ 14 ] ; rtB .
l3f0j0025k = rtP . donotdeletethisgain_Gain_nwj215l5x1 * rtB . odazhmwpn0 [
15 ] ; rtB . nkqprozo1a = rtP . donotdeletethisgain_Gain_fy4vzgl50q * rtB .
odazhmwpn0 [ 16 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetIsOkayToUpdateMode ( rtS ) ) { rtDW . apgwaguobm = ( rtB . otoroldxt1 ==
rtP . Constant_Value ) ; } cspoaxzzcz = rtDW . apgwaguobm ; hhoyo4a5hd ( rtS
, cspoaxzzcz , rtB . nkqprozo1a , & rtB . hhoyo4a5hdp , & rtDW . hhoyo4a5hdp
, & rtPrevZCX . hhoyo4a5hdp ) ; hhoyo4a5hd ( rtS , cspoaxzzcz , rtB .
avcatdltyc , & rtB . adxwqzxxlf , & rtDW . adxwqzxxlf , & rtPrevZCX .
adxwqzxxlf ) ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { } if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtDW . dmdu1pxmxg = ( ssGetTaskTime ( rtS , 1 ) >= rtP .
Step_Time ) ; if ( rtDW . dmdu1pxmxg == 1 ) { tmp = rtP . Step_YFinal ; }
else { tmp = rtP . Step_Y0 ; } if ( tmp > rtP . Switch_Threshold ) { rtB .
cruaxvmogz = rtB . brs0dgmc1a ; } else { rtB . cruaxvmogz = rtP .
Constant_Value_dsqxhplhg3 ; } rtB . h1gogwi5ku = rtB . efbnt10xks ; rtB .
bdou3bnea4 = rtB . bn0ratt3ev ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB
. bg2jknexx5 = rtP . donotdeletethisgain_Gain_cthxcecbau * rtB . odazhmwpn0 [
10 ] ; rtB . dpjtgbbiz2 = rtP . donotdeletethisgain_Gain_ctalfroa4m * rtB .
odazhmwpn0 [ 11 ] ; rtB . aadob0orwm = rtP .
donotdeletethisgain_Gain_o54pdurymu * rtB . odazhmwpn0 [ 12 ] ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { kxu0aoeena = rtP .
Constant_Value_oa4sl44jdq - rtB . adxwqzxxlf . gqyueovf0x ; rtB . gqvdelah3i
= rtP . PIDController1_P * kxu0aoeena ; } rtB . hxoya3o5lr = rtX . hbkyjaqpk0
; rtB . j2wnh3irqk = rtB . gqvdelah3i + rtB . hxoya3o5lr ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . bgqwuyroks = rtB . j2wnh3irqk >= rtP .
Saturation1_UpperSat ? 1 : rtB . j2wnh3irqk > rtP . Saturation1_LowerSat ? 0
: - 1 ; } rtB . d3eaa0fx0a = rtDW . bgqwuyroks == 1 ? rtP .
Saturation1_UpperSat : rtDW . bgqwuyroks == - 1 ? rtP . Saturation1_LowerSat
: rtB . j2wnh3irqk ; rtB . dzkiqmr43p = rtB . d3eaa0fx0a - rtB . hhoyo4a5hdp
. gqyueovf0x ; rtB . ar5fz2uoyk = rtP . PIDController_I * rtB . dzkiqmr43p ;
rtB . myup1cfdlk = rtX . k1kxb5arpk ; rtB . defpijlxd3 = rtP .
PIDController_P * rtB . dzkiqmr43p + rtB . myup1cfdlk ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . mczadyhg2m = rtP . PIDController1_I * kxu0aoeena ; }
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . mrajto30cb = rtB . defpijlxd3 >=
rtP . Saturation_UpperSat ? 1 : rtB . defpijlxd3 > rtP . Saturation_LowerSat
? 0 : - 1 ; } rtB . dzvsubkdwz = look1_binlxpw ( muDoubleScalarRem ( ssGetT (
rtS ) - 0.0 , rtP . Constant_Value_gdp532zjna ) , rtP .
LookUpTable1_bp01Data_p4fekf0sau , rtP . RepeatingSequence1_rep_seq_y , 2U )
; rtB . l1j1ioj0sv = look1_binlxpw ( muDoubleScalarRem ( ssGetT ( rtS ) - 0.0
, rtP . Constant_Value_otf0qt4owd ) , rtP . LookUpTable1_bp01Data_eancggqfkt
, rtP . RepeatingSequence2_rep_seq_y , 2U ) ; { real_T * * uBuffer = ( real_T
* * ) & rtDW . nmpmd1jh5e . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
rtS ) ; real_T tMinusDelay = simTime - ( rtP . TransportDelay_Delay ) ; rtB .
lsx1razqc1 = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW .
lkazb3z1og . CircularBufSize , & rtDW . lkazb3z1og . Last , rtDW . lkazb3z1og
. Tail , rtDW . lkazb3z1og . Head , rtP . TransportDelay_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } rtB . ohzinl1asd = look1_binlxpw ( muDoubleScalarRem
( ssGetT ( rtS ) - 0.0 , rtP . Constant_Value_gwvmohj4ou ) , rtP .
LookUpTable1_bp01Data_fwaln5kcoo , rtP . RepeatingSequence4_rep_seq_y , 2U )
; rtB . huhtwrsccb = ( muDoubleScalarSin ( rtP . SineWave1_Freq *
ssGetTaskTime ( rtS , 0 ) + rtP . SineWave1_Phase ) * rtP . SineWave1_Amp +
rtP . SineWave1_Bias ) * ( 1.0 / rtP . alp ) ; UNUSED_PARAMETER ( tid ) ; }
void MdlOutputsTID3 ( int_T tid ) { rtB . hvvgc3xdmn = rtP . Constant1_Value
; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { { const real_T * As = ( real_T * ) rtDW .
gr1muksbyf . AS ; const real_T * Bs = ( real_T * ) rtDW . gr1muksbyf . BS ;
real_T * xtmp = ( real_T * ) rtDW . gr1muksbyf . XTMP ; real_T accum ; accum
= 0.0 ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 0 ] ; accum += * ( As ++ )
* rtDW . kbsai0di0v [ 1 ] ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 2 ] ;
accum += * ( As ++ ) * rtDW . kbsai0di0v [ 3 ] ; { int_T i1 ; const real_T *
u0 = rtP . SwitchCurrents_Value ; for ( i1 = 0 ; i1 < 9 ; i1 ++ ) { accum +=
* ( Bs ++ ) * u0 [ i1 ] ; } accum += * ( Bs ++ ) * rtP . IBC_Vin ; accum += *
( Bs ++ ) * rtP . eee_Value ; accum += * ( Bs ++ ) * rtP .
eee_Value_pohmtfwesc ; accum += * ( Bs ++ ) * rtP . eee_Value_jlbhkxjaia ; }
xtmp [ 0 ] = accum ; accum = 0.0 ; accum += * ( As ++ ) * rtDW . kbsai0di0v [
0 ] ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 1 ] ; accum += * ( As ++ ) *
rtDW . kbsai0di0v [ 2 ] ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 3 ] ; {
int_T i1 ; const real_T * u0 = rtP . SwitchCurrents_Value ; for ( i1 = 0 ; i1
< 9 ; i1 ++ ) { accum += * ( Bs ++ ) * u0 [ i1 ] ; } accum += * ( Bs ++ ) *
rtP . IBC_Vin ; accum += * ( Bs ++ ) * rtP . eee_Value ; accum += * ( Bs ++ )
* rtP . eee_Value_pohmtfwesc ; accum += * ( Bs ++ ) * rtP .
eee_Value_jlbhkxjaia ; } xtmp [ 1 ] = accum ; accum = 0.0 ; accum += * ( As
++ ) * rtDW . kbsai0di0v [ 0 ] ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 1
] ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 2 ] ; accum += * ( As ++ ) *
rtDW . kbsai0di0v [ 3 ] ; { int_T i1 ; const real_T * u0 = rtP .
SwitchCurrents_Value ; for ( i1 = 0 ; i1 < 9 ; i1 ++ ) { accum += * ( Bs ++ )
* u0 [ i1 ] ; } accum += * ( Bs ++ ) * rtP . IBC_Vin ; accum += * ( Bs ++ ) *
rtP . eee_Value ; accum += * ( Bs ++ ) * rtP . eee_Value_pohmtfwesc ; accum
+= * ( Bs ++ ) * rtP . eee_Value_jlbhkxjaia ; } xtmp [ 2 ] = accum ; accum =
0.0 ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 0 ] ; accum += * ( As ++ ) *
rtDW . kbsai0di0v [ 1 ] ; accum += * ( As ++ ) * rtDW . kbsai0di0v [ 2 ] ;
accum += * ( As ++ ) * rtDW . kbsai0di0v [ 3 ] ; { int_T i1 ; const real_T *
u0 = rtP . SwitchCurrents_Value ; for ( i1 = 0 ; i1 < 9 ; i1 ++ ) { accum +=
* ( Bs ++ ) * u0 [ i1 ] ; } accum += * ( Bs ++ ) * rtP . IBC_Vin ; accum += *
( Bs ++ ) * rtP . eee_Value ; accum += * ( Bs ++ ) * rtP .
eee_Value_pohmtfwesc ; accum += * ( Bs ++ ) * rtP . eee_Value_jlbhkxjaia ; }
xtmp [ 3 ] = accum ; rtDW . kbsai0di0v [ 0 ] = xtmp [ 0 ] ; rtDW . kbsai0di0v
[ 1 ] = xtmp [ 1 ] ; rtDW . kbsai0di0v [ 2 ] = xtmp [ 2 ] ; rtDW . kbsai0di0v
[ 3 ] = xtmp [ 3 ] ; { int_T * gState = ( int_T * ) rtDW . gr1muksbyf .
G_STATE ; * ( gState ++ ) = ( int_T ) rtB . bdou3bnea4 ; * ( gState ++ ) = (
int_T ) rtB . cruaxvmogz ; * ( gState ++ ) = ( int_T ) rtB . h1gogwi5ku ; * (
gState ++ ) = ( int_T ) 0.0 ; * ( gState ++ ) = ( int_T ) 0.0 ; * ( gState ++
) = ( int_T ) 0.0 ; * ( gState ++ ) = ( int_T ) 0.0 ; * ( gState ++ ) = (
int_T ) 0.0 ; * ( gState ++ ) = ( int_T ) 0.0 ; } } } { real_T * * uBuffer =
( real_T * * ) & rtDW . layaov5mlt . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . coigdooovo . Head = ( ( rtDW . coigdooovo . Head < (
rtDW . coigdooovo . CircularBufSize - 1 ) ) ? ( rtDW . coigdooovo . Head + 1
) : 0 ) ; if ( rtDW . coigdooovo . Head == rtDW . coigdooovo . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . coigdooovo . CircularBufSize , &
rtDW . coigdooovo . Tail , & rtDW . coigdooovo . Head , & rtDW . coigdooovo .
Last , simTime - ( 1.0 / rtP . _Fs / 3.0 ) , uBuffer , ( boolean_T ) 0 ,
false , & rtDW . coigdooovo . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"IBC1/命令信号生产/Transport\nDelay1_TUbuffer0" , ( void * * ) ( & uBuffer [
0 ] ) , 2 * rtDW . coigdooovo . CircularBufSize * sizeof ( real_T ) , NULL ,
NULL ) ; } ( * uBuffer + rtDW . coigdooovo . CircularBufSize ) [ rtDW .
coigdooovo . Head ] = simTime ; ( * uBuffer ) [ rtDW . coigdooovo . Head ] =
rtB . dzvsubkdwz ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
e5i1astk5k . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
nen2ftgc0l . Head = ( ( rtDW . nen2ftgc0l . Head < ( rtDW . nen2ftgc0l .
CircularBufSize - 1 ) ) ? ( rtDW . nen2ftgc0l . Head + 1 ) : 0 ) ; if ( rtDW
. nen2ftgc0l . Head == rtDW . nen2ftgc0l . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . nen2ftgc0l . CircularBufSize , & rtDW
. nen2ftgc0l . Tail , & rtDW . nen2ftgc0l . Head , & rtDW . nen2ftgc0l . Last
, simTime - ( 2.0 / rtP . _Fs / 3.0 ) , uBuffer , ( boolean_T ) 0 , false , &
rtDW . nen2ftgc0l . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"IBC1/命令信号生产/Transport\nDelay2_TUbuffer0" , ( void * * ) ( & uBuffer [
0 ] ) , 2 * rtDW . nen2ftgc0l . CircularBufSize * sizeof ( real_T ) , NULL ,
NULL ) ; } ( * uBuffer + rtDW . nen2ftgc0l . CircularBufSize ) [ rtDW .
nen2ftgc0l . Head ] = simTime ; ( * uBuffer ) [ rtDW . nen2ftgc0l . Head ] =
rtB . l1j1ioj0sv ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
nmpmd1jh5e . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
lkazb3z1og . Head = ( ( rtDW . lkazb3z1og . Head < ( rtDW . lkazb3z1og .
CircularBufSize - 1 ) ) ? ( rtDW . lkazb3z1og . Head + 1 ) : 0 ) ; if ( rtDW
. lkazb3z1og . Head == rtDW . lkazb3z1og . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . lkazb3z1og . CircularBufSize , & rtDW
. lkazb3z1og . Tail , & rtDW . lkazb3z1og . Head , & rtDW . lkazb3z1og . Last
, simTime - ( rtP . TransportDelay_Delay ) , uBuffer , ( boolean_T ) 0 ,
false , & rtDW . lkazb3z1og . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"IBC1/命令信号生产/Transport\nDelay_TUbuffer0" , ( void * * ) ( & uBuffer [ 0
] ) , 2 * rtDW . lkazb3z1og . CircularBufSize * sizeof ( real_T ) , NULL ,
NULL ) ; } ( * uBuffer + rtDW . lkazb3z1og . CircularBufSize ) [ rtDW .
lkazb3z1og . Head ] = simTime ; ( * uBuffer ) [ rtDW . lkazb3z1og . Head ] =
rtB . ohzinl1asd ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID3 ( int_T
tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot *
_rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> hbkyjaqpk0 =
rtB . mczadyhg2m ; _rtXdot -> k1kxb5arpk = rtB . ar5fz2uoyk ; _rtXdot ->
ma50ol3eb4 [ 0 ] = 0.0 ; _rtXdot -> ma50ol3eb4 [ 0 ] += rtP . TransferFcn1_A
[ 0 ] * rtX . ma50ol3eb4 [ 0 ] ; _rtXdot -> ma50ol3eb4 [ 1 ] = 0.0 ; _rtXdot
-> ma50ol3eb4 [ 0 ] += rtP . TransferFcn1_A [ 1 ] * rtX . ma50ol3eb4 [ 1 ] ;
_rtXdot -> ma50ol3eb4 [ 1 ] += rtX . ma50ol3eb4 [ 0 ] ; _rtXdot -> ma50ol3eb4
[ 0 ] += rtB . huhtwrsccb ; } void MdlProjection ( void ) { } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> cxvmlo54tq = rtB .
hvvgc3xdmn - rtB . otoroldxt1 ; _rtZCSV -> i1qguydf5f = rtB . hvvgc3xdmn -
rtB . lhmqma0bj3 ; _rtZCSV -> hwifdzglhr = rtB . hvvgc3xdmn - rtB .
pkmdbed0es ; _rtZCSV -> fqe3m5uk4o = rtB . otoroldxt1 - rtP . Constant_Value
; _rtZCSV -> ccibpnss55 = ssGetT ( rtS ) - rtP . Step_Time ; _rtZCSV ->
ouj3m1afdg = rtB . j2wnh3irqk - rtP . Saturation1_UpperSat ; _rtZCSV ->
iylnquiyuq = rtB . j2wnh3irqk - rtP . Saturation1_LowerSat ; _rtZCSV ->
gc0ar4rht3 = rtB . defpijlxd3 - rtP . Saturation_UpperSat ; _rtZCSV ->
hm3wlvfwem = rtB . defpijlxd3 - rtP . Saturation_LowerSat ; } void
MdlTerminate ( void ) { { free ( rtDW . gr1muksbyf . AS ) ; free ( rtDW .
gr1muksbyf . BS ) ; free ( rtDW . gr1muksbyf . CS ) ; free ( rtDW .
gr1muksbyf . DS ) ; free ( rtDW . gr1muksbyf . DX_COL ) ; free ( rtDW .
gr1muksbyf . TMP2 ) ; free ( rtDW . gr1muksbyf . BD_COL ) ; free ( rtDW .
gr1muksbyf . TMP1 ) ; free ( rtDW . gr1muksbyf . XTMP ) ; free ( rtDW .
gr1muksbyf . G_STATE ) ; free ( rtDW . gr1muksbyf . SWITCH_STATUS ) ; free (
rtDW . gr1muksbyf . SW_CHG ) ; free ( rtDW . gr1muksbyf . SWITCH_STATUS_INIT
) ; } rt_TDelayFreeBuf ( rtDW . layaov5mlt . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . e5i1astk5k . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . nmpmd1jh5e . TUbufferPtrs [ 0 ] ) ; } static void
mr_IBC1_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const
void * srcData , size_t numBytes ) ; static void mr_IBC1_cacheDataAsMxArray (
mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) { mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1
, numBytes , mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData (
newArray ) , ( const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber (
destArray , i , j , newArray ) ; } static void mr_IBC1_restoreDataFromMxArray
( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) ; static void mr_IBC1_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_IBC1_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) ; static void mr_IBC1_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber (
destArray , i , j , mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static
uint_T mr_IBC1_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_IBC1_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_IBC1_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_IBC1_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_IBC1_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_IBC1_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_IBC1_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_IBC1_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber
( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( double ) fieldVal )
) ; } static uint_T mr_IBC1_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_IBC1_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_IBC1_GetDWork ( ) { static const char * ssDWFieldNames [ 3
] = { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_IBC1_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 17 ] = {
"rtDW.kbsai0di0v" , "rtDW.ih1wy1g0a5" , "rtDW.o5rvrjh2wy" , "rtDW.dcsgtlggye"
, "rtDW.mld3hblakv" , "rtDW.coigdooovo" , "rtDW.nen2ftgc0l" ,
"rtDW.lkazb3z1og" , "rtDW.dmdu1pxmxg" , "rtDW.bgqwuyroks" , "rtDW.mrajto30cb"
, "rtDW.hzzdjgpnti" , "rtDW.ovfa2w42nr" , "rtDW.humgsssfcu" ,
"rtDW.apgwaguobm" , "rtDW.adxwqzxxlf.ikjnmtqwv0" ,
"rtDW.hhoyo4a5hdp.ikjnmtqwv0" , } ; mxArray * rtdwData = mxCreateStructMatrix
( 1 , 1 , 17 , rtdwDataFieldNames ) ; mr_IBC1_cacheDataAsMxArray ( rtdwData ,
0 , 0 , ( const void * ) & ( rtDW . kbsai0di0v ) , sizeof ( rtDW . kbsai0di0v
) ) ; mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . ih1wy1g0a5 ) , sizeof ( rtDW . ih1wy1g0a5 ) ) ;
mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW .
o5rvrjh2wy ) , sizeof ( rtDW . o5rvrjh2wy ) ) ; mr_IBC1_cacheDataAsMxArray (
rtdwData , 0 , 3 , ( const void * ) & ( rtDW . dcsgtlggye ) , sizeof ( rtDW .
dcsgtlggye ) ) ; mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void
* ) & ( rtDW . mld3hblakv ) , sizeof ( rtDW . mld3hblakv ) ) ;
mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW .
coigdooovo ) , sizeof ( rtDW . coigdooovo ) ) ; mr_IBC1_cacheDataAsMxArray (
rtdwData , 0 , 6 , ( const void * ) & ( rtDW . nen2ftgc0l ) , sizeof ( rtDW .
nen2ftgc0l ) ) ; mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void
* ) & ( rtDW . lkazb3z1og ) , sizeof ( rtDW . lkazb3z1og ) ) ;
mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & ( rtDW .
dmdu1pxmxg ) , sizeof ( rtDW . dmdu1pxmxg ) ) ; mr_IBC1_cacheDataAsMxArray (
rtdwData , 0 , 9 , ( const void * ) & ( rtDW . bgqwuyroks ) , sizeof ( rtDW .
bgqwuyroks ) ) ; mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const
void * ) & ( rtDW . mrajto30cb ) , sizeof ( rtDW . mrajto30cb ) ) ;
mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & ( rtDW .
hzzdjgpnti ) , sizeof ( rtDW . hzzdjgpnti ) ) ; mr_IBC1_cacheDataAsMxArray (
rtdwData , 0 , 12 , ( const void * ) & ( rtDW . ovfa2w42nr ) , sizeof ( rtDW
. ovfa2w42nr ) ) ; mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const
void * ) & ( rtDW . humgsssfcu ) , sizeof ( rtDW . humgsssfcu ) ) ;
mr_IBC1_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & ( rtDW .
apgwaguobm ) , sizeof ( rtDW . apgwaguobm ) ) ; mr_IBC1_cacheDataAsMxArray (
rtdwData , 0 , 15 , ( const void * ) & ( rtDW . adxwqzxxlf . ikjnmtqwv0 ) ,
sizeof ( rtDW . adxwqzxxlf . ikjnmtqwv0 ) ) ; mr_IBC1_cacheDataAsMxArray (
rtdwData , 0 , 16 , ( const void * ) & ( rtDW . hhoyo4a5hdp . ikjnmtqwv0 ) ,
sizeof ( rtDW . hhoyo4a5hdp . ikjnmtqwv0 ) ) ; mxSetFieldByNumber ( ssDW , 0
, 1 , rtdwData ) ; } mr_IBC1_cacheDataAsMxArray ( ssDW , 0 , 2 , ( const void
* ) & ( rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW ; } void
mr_IBC1_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof
( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 )
; mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . kbsai0di0v ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . kbsai0di0v ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . ih1wy1g0a5 ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . ih1wy1g0a5 ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . o5rvrjh2wy ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . o5rvrjh2wy ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . dcsgtlggye ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . dcsgtlggye ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . mld3hblakv ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . mld3hblakv ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . coigdooovo ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . coigdooovo ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . nen2ftgc0l ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . nen2ftgc0l ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . lkazb3z1og ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . lkazb3z1og ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . dmdu1pxmxg ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . dmdu1pxmxg ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . bgqwuyroks ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . bgqwuyroks ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . mrajto30cb ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . mrajto30cb ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . hzzdjgpnti ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . hzzdjgpnti ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . ovfa2w42nr ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . ovfa2w42nr ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . humgsssfcu ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . humgsssfcu ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . apgwaguobm ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . apgwaguobm ) ) ;
mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . adxwqzxxlf .
ikjnmtqwv0 ) , rtdwData , 0 , 15 , sizeof ( rtDW . adxwqzxxlf . ikjnmtqwv0 )
) ; mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtDW . hhoyo4a5hdp .
ikjnmtqwv0 ) , rtdwData , 0 , 16 , sizeof ( rtDW . hhoyo4a5hdp . ikjnmtqwv0 )
) ; } mr_IBC1_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW , 0
, 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_IBC1_GetSimStateDisallowedBlocks ( ) { mxArray * data = mxCreateCellMatrix
( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const char * blockType [
10 ] = { "S-Function" , "Scope" , "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , "Scope" , "Scope" , } ; static const char * blockPath [
10 ] = { "IBC1/powergui/EquivalentModel1/State-Space" , "IBC1/Scope" ,
"IBC1/Scope1" , "IBC1/Scope2" , "IBC1/Scope3" , "IBC1/Scope4" , "IBC1/Scope5"
, "IBC1/Scope9" , "IBC1/IBC/Scope" , "IBC1/IBC/Scope1" , } ; static const int
reason [ 10 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0
] = 0 ; subs [ 0 ] < 10 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 153 ) ; ssSetNumBlockIO ( rtS , 37 ) ;
ssSetNumBlockParams ( rtS , 445 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 2.5E-8 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2765813247U ) ;
ssSetChecksumVal ( rtS , 1 , 2697726608U ) ; ssSetChecksumVal ( rtS , 2 ,
1612699770U ) ; ssSetChecksumVal ( rtS , 3 , 806894874U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 15 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
IBC1_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS , true )
; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 )
; ssSetModelName ( rtS , "IBC1" ) ; ssSetPath ( rtS , "IBC1" ) ; ssSetTStart
( rtS , 0.0 ) ; ssSetTFinal ( rtS , 0.01 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 2 , 4 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 2 , 4 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
} ; static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = {
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "DSTATE" } ;
static const char_T * rt_LoggedStateBlockNames [ ] = {
"IBC1/PID Controller1/Integrator/Continuous/Integrator" ,
"IBC1/PID Controller/Integrator/Continuous/Integrator" , "IBC1/Transfer Fcn1"
, "IBC1/powergui/EquivalentModel1/State-Space" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 0 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 4 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 4 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . hbkyjaqpk0 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . k1kxb5arpk ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ma50ol3eb4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) rtDW . kbsai0di0v ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 4 ] ;
static real_T absTol [ 4 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static
uint8_T absTolControl [ 4 ] = { 0U , 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 4 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 4 ] ; static uint8_T zcAttributes [ 11 ] = {
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( 0xc0 | ZC_EVENT_ALL_UP ) , ( 0xc0 | ZC_EVENT_ALL_UP ) }
; static ssNonContDerivSigInfo nonContDerivSigInfo [ 3 ] = { { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . mczadyhg2m ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . gqvdelah3i ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . hhoyo4a5hdp . gqyueovf0x ) , ( NULL ) } } ; {
int i ; for ( i = 0 ; i < 4 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] =
0 ; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } }
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 2.5E-8 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 3 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS
, 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 1 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 11 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 0 ) ;
ssSetSolverZcThreshold ( rtS , 0.001 ) ; ssSetSolverMaxConsecutiveMinStep (
rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS
, INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS )
; ssSetNumNonsampledZCs ( rtS , 9 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . adxwqzxxlf . dp1i3lb5ph = POS_ZCSIG ; rtPrevZCX .
hhoyo4a5hdp . dp1i3lb5ph = POS_ZCSIG ; } ssSetChecksumVal ( rtS , 0 ,
2765813247U ) ; ssSetChecksumVal ( rtS , 1 , 2697726608U ) ; ssSetChecksumVal
( rtS , 2 , 1612699770U ) ; ssSetChecksumVal ( rtS , 3 , 806894874U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 3 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . hhoyo4a5hdp . ikjnmtqwv0 ; systemRan [ 2 ] = (
sysRanDType * ) & rtDW . adxwqzxxlf . ikjnmtqwv0 ; rteiSetModelMappingInfoPtr
( ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_IBC1_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_IBC1_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS , mr_IBC1_SetDWork )
; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS )
) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
