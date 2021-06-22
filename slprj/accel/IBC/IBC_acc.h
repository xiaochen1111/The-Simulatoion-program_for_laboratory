#ifndef RTW_HEADER_IBC_acc_h_
#define RTW_HEADER_IBC_acc_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#ifndef IBC_acc_COMMON_INCLUDES_
#define IBC_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "IBC_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_0_0_0 ; } B_SampleandHold_IBC_T ; typedef struct {
int32_T SampleandHold_sysIdxToRun ; int8_T SampleandHold_SubsysRanBC ; char_T
pad_SampleandHold_SubsysRanBC [ 3 ] ; } DW_SampleandHold_IBC_T ; typedef
struct { real_T SampleandHold_Trig_ZC ; } ZCV_SampleandHold_IBC_T ; typedef
struct { ZCSigState SampleandHold_Trig_ZCE ; } ZCE_SampleandHold_IBC_T ;
typedef struct { real_T B_2_0_0 [ 17 ] ; real_T B_2_0_1 [ 9 ] ; real_T
B_2_1_0 ; real_T B_2_4_0 ; real_T B_2_7_0 ; real_T B_2_8_0 ; real_T B_2_9_0 ;
real_T B_2_11_0 ; real_T B_2_16_0 ; real_T B_2_17_0 ; real_T B_2_18_0 ;
real_T B_2_19_0 ; real_T B_2_20_0 ; real_T B_2_22_0 ; real_T B_2_24_0 ;
real_T B_2_25_0 ; real_T B_2_26_0 ; real_T B_2_31_0 ; real_T B_2_32_0 ;
real_T B_2_63_0 ; real_T B_2_64_0 ; real_T B_2_74_0 ; real_T B_2_84_0 ;
real_T B_2_85_0 ; real_T B_2_86_0 ; real_T B_2_114_0 ; real_T B_2_115_0 ;
real_T B_2_118_0 ; real_T B_2_121_0 ; real_T B_2_123_0 ; real_T B_2_126_0 ;
real_T B_2_127_0 ; real_T B_2_129_0 ; real_T B_2_132_0 ; real_T B_2_135_0 ;
real_T B_2_0_0_m [ 9 ] ; real_T B_2_1_0_c ; real_T B_2_2_0 ; real_T B_2_3_0 ;
real_T B_2_4_0_k ; real_T B_2_5_0 ; real_T B_2_6_0 ; real_T B_2_7_0_c ;
real_T B_2_8_0_b ; real_T B_2_9_0_p ; real_T B_2_10_0 ; real_T B_2_10_0_c [ 3
] ; boolean_T B_2_27_0 ; boolean_T B_2_28_0 ; boolean_T B_2_29_0 ; char_T
pad_B_2_29_0 [ 5 ] ; B_SampleandHold_IBC_T SampleandHold1 ;
B_SampleandHold_IBC_T SampleandHold ; } B_IBC_T ; typedef struct { real_T
StateSpace_DSTATE [ 4 ] ; struct { real_T modelTStart ; }
TransportDelay1_RWORK ; struct { real_T modelTStart ; } TransportDelay2_RWORK
; struct { real_T modelTStart ; } TransportDelay_RWORK ; struct { void * AS ;
void * BS ; void * CS ; void * DS ; void * DX_COL ; void * BD_COL ; void *
TMP1 ; void * TMP2 ; void * XTMP ; void * SWITCH_STATUS ; void *
SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ; void * USWLAST ; void *
XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ; void * IDX_SW_CHG ; void
* Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW ; void *
SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } StateSpace_PWORK ; void *
Scope_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay1_PWORK ;
struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay2_PWORK ; void *
Scope1_PWORK [ 2 ] ; void * Scope2_PWORK [ 3 ] ; void * Scope3_PWORK [ 4 ] ;
void * Scope4_PWORK [ 2 ] ; void * Scope5_PWORK [ 2 ] ; void * Scope9_PWORK [
3 ] ; void * Scope_PWORK_a ; void * Scope1_PWORK_a [ 3 ] ; void *
Scope_PWORK_i [ 4 ] ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK ; void * Scope1_PWORK_ag [ 2 ] ; int_T StateSpace_IWORK
[ 11 ] ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay1_IWORK ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay2_IWORK ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; int_T Saturation1_MODE ; int_T Saturation_MODE ; int_T
Step_MODE ; boolean_T Compare_Mode ; boolean_T RelationalOperator_Mode ;
boolean_T RelationalOperator1_Mode ; boolean_T RelationalOperator2_Mode ;
DW_SampleandHold_IBC_T SampleandHold1 ; DW_SampleandHold_IBC_T SampleandHold
; } DW_IBC_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_e ; real_T TransferFcn1_CSTATE [ 2 ] ; } X_IBC_T ; typedef
struct { real_T Integrator_CSTATE ; real_T Integrator_CSTATE_e ; real_T
TransferFcn1_CSTATE [ 2 ] ; } XDot_IBC_T ; typedef struct { boolean_T
Integrator_CSTATE ; boolean_T Integrator_CSTATE_e ; boolean_T
TransferFcn1_CSTATE [ 2 ] ; } XDis_IBC_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_e ; real_T TransferFcn1_CSTATE [
2 ] ; } CStateAbsTol_IBC_T ; typedef struct { real_T Integrator_CSTATE ;
real_T Integrator_CSTATE_e ; real_T TransferFcn1_CSTATE [ 2 ] ; }
CXPtMin_IBC_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_e ; real_T TransferFcn1_CSTATE [ 2 ] ; } CXPtMax_IBC_T ;
typedef struct { real_T Compare_RelopInput_ZC ; real_T Saturation1_UprLim_ZC
; real_T Saturation1_LwrLim_ZC ; real_T Saturation_UprLim_ZC ; real_T
Saturation_LwrLim_ZC ; real_T RelationalOperator_RelopInput_ZC ; real_T
RelationalOperator1_RelopInput_ZC ; real_T RelationalOperator2_RelopInput_ZC
; real_T Step_StepTime_ZC ; ZCV_SampleandHold_IBC_T SampleandHold1 ;
ZCV_SampleandHold_IBC_T SampleandHold ; } ZCV_IBC_T ; typedef struct {
ZCSigState Compare_RelopInput_ZCE ; ZCSigState Saturation1_UprLim_ZCE ;
ZCSigState Saturation1_LwrLim_ZCE ; ZCSigState Saturation_UprLim_ZCE ;
ZCSigState Saturation_LwrLim_ZCE ; ZCSigState
RelationalOperator_RelopInput_ZCE ; ZCSigState
RelationalOperator1_RelopInput_ZCE ; ZCSigState
RelationalOperator2_RelopInput_ZCE ; ZCSigState Step_StepTime_ZCE ;
ZCE_SampleandHold_IBC_T SampleandHold1 ; ZCE_SampleandHold_IBC_T
SampleandHold ; } PrevZCX_IBC_T ; typedef struct { const real_T B_2_0_0 ; }
ConstB_IBC_T ;
#define IBC_rtC(S) ((ConstB_IBC_T *) _ssGetConstBlockIO(S))
struct P_SampleandHold_IBC_T_ { real_T P_0 ; } ; struct P_IBC_T_ { real_T P_0
; real_T P_1 [ 2 ] ; real_T P_2 [ 16 ] ; real_T P_3 [ 2 ] ; real_T P_4 [ 52 ]
; real_T P_5 [ 2 ] ; real_T P_6 [ 68 ] ; real_T P_7 [ 2 ] ; real_T P_8 [ 221
] ; real_T P_9 [ 2 ] ; real_T P_10 [ 4 ] ; real_T P_11 ; real_T P_12 [ 3 ] ;
real_T P_13 [ 3 ] ; real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ;
real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T
P_23 ; real_T P_24 ; real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ;
real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T
P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ;
real_T P_40 [ 3 ] ; real_T P_41 [ 3 ] ; real_T P_42 [ 3 ] ; real_T P_43 [ 3 ]
; real_T P_44 ; real_T P_45 ; real_T P_46 [ 3 ] ; real_T P_47 [ 3 ] ; real_T
P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 [
2 ] ; real_T P_54 [ 2 ] ; real_T P_55 [ 9 ] ; real_T P_56 ; real_T P_57 ;
real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T
P_63 ; real_T P_64 ; real_T P_65 ; P_SampleandHold_IBC_T SampleandHold1 ;
P_SampleandHold_IBC_T SampleandHold ; } ; extern P_IBC_T IBC_rtDefaultP ;
extern const ConstB_IBC_T IBC_rtInvariant ;
#endif
