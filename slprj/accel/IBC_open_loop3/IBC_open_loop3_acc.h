#ifndef RTW_HEADER_IBC_open_loop3_acc_h_
#define RTW_HEADER_IBC_open_loop3_acc_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#ifndef IBC_open_loop3_acc_COMMON_INCLUDES_
#define IBC_open_loop3_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "IBC_open_loop3_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_0_0_0 ; } B_SampleIL1_IBC_open_loop3_T ; typedef
struct { int32_T SampleIL1_sysIdxToRun ; int8_T SampleIL1_SubsysRanBC ;
char_T pad_SampleIL1_SubsysRanBC [ 3 ] ; } DW_SampleIL1_IBC_open_loop3_T ;
typedef struct { real_T SampleIL1_Trig_ZC ; } ZCV_SampleIL1_IBC_open_loop3_T
; typedef struct { ZCSigState SampleIL1_Trig_ZCE ; }
ZCE_SampleIL1_IBC_open_loop3_T ; typedef struct { real_T B_4_0_0 [ 20 ] ;
real_T B_4_0_1 [ 9 ] ; real_T B_4_2_0 ; real_T B_4_5_0 ; real_T B_4_6_0 ;
real_T B_4_8_0 ; real_T B_4_9_0 ; real_T B_4_10_0 ; real_T B_4_11_0 ; real_T
B_4_12_0 ; real_T B_4_13_0 ; real_T B_4_15_0 ; real_T B_4_21_0 ; real_T
B_4_22_0 ; real_T B_4_23_0 ; real_T B_4_24_0 ; real_T B_4_26_0 ; real_T
B_4_28_0 ; real_T B_4_29_0 ; real_T B_4_30_0 ; real_T B_4_33_0 ; real_T
B_4_35_0 ; real_T B_4_38_0 ; real_T B_4_40_0 ; real_T B_4_47_0 ; real_T
B_4_60_0 ; real_T B_4_61_0 ; real_T B_4_62_0 ; real_T B_4_79_0 ; real_T
B_4_99_0 ; real_T B_4_100_0 ; real_T B_4_110_0 ; real_T B_4_111_0 ; real_T
B_4_112_0 ; real_T B_4_140_0 ; real_T B_4_141_0 ; real_T B_4_151_0 ; real_T
B_4_154_0 ; real_T B_4_156_0 ; real_T B_4_159_0 ; real_T B_4_160_0 ; real_T
B_4_162_0 ; real_T B_4_165_0 ; real_T B_4_0_0_m [ 9 ] ; real_T B_4_1_0 ;
real_T B_4_2_0_c ; real_T B_4_3_0 ; real_T B_4_4_0 ; real_T B_4_5_0_k ;
real_T B_4_6_0_c ; real_T B_4_7_0 ; real_T B_4_8_0_b ; real_T B_4_9_0_p ;
real_T B_4_10_0_c ; real_T B_4_11_0_f ; real_T B_4_12_0_g ; uint8_T B_4_17_0
; boolean_T B_4_16_0 ; boolean_T B_4_32_0 ; boolean_T B_4_34_0 ; boolean_T
B_4_36_0 ; boolean_T B_4_39_0 ; boolean_T B_4_41_0 ; boolean_T B_4_144_0 ;
boolean_T B_4_145_0 ; boolean_T B_4_146_0 ; char_T pad_B_4_146_0 [ 6 ] ;
B_SampleIL1_IBC_open_loop3_T SampleandHold1 ; B_SampleIL1_IBC_open_loop3_T
SampleIL3 ; B_SampleIL1_IBC_open_loop3_T SampleIL2 ;
B_SampleIL1_IBC_open_loop3_T SampleIL1 ; } B_IBC_open_loop3_T ; typedef
struct { real_T StateSpace_DSTATE [ 4 ] ; struct { real_T modelTStart ; }
TransportDelay1_RWORK ; struct { real_T modelTStart ; } TransportDelay2_RWORK
; struct { real_T modelTStart ; } TransportDelay_RWORK ; struct { void * AS ;
void * BS ; void * CS ; void * DS ; void * DX_COL ; void * BD_COL ; void *
TMP1 ; void * TMP2 ; void * XTMP ; void * SWITCH_STATUS ; void *
SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ; void * USWLAST ; void *
XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ; void * IDX_SW_CHG ; void
* Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW ; void *
SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } StateSpace_PWORK ; void *
Scope1_PWORK ; void * Scope10_PWORK [ 3 ] ; void * Scope11_PWORK [ 4 ] ; void
* Scope12_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay1_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay2_PWORK ; void * Scope2_PWORK [ 3 ] ; void * Scope3_PWORK [ 9 ]
; void * Scope4_PWORK [ 4 ] ; void * Scope5_PWORK [ 2 ] ; void * Scope6_PWORK
[ 2 ] ; void * Scope9_PWORK [ 3 ] ; void * Scope_PWORK ; void *
Scope2_PWORK_m [ 5 ] ; void * Scope1_PWORK_a [ 3 ] ; void * Scope2_PWORK_k ;
void * Scope3_PWORK_a [ 3 ] ; void * Scope4_PWORK_f [ 3 ] ; void *
Scope5_PWORK_e ; void * Scope6_PWORK_h [ 3 ] ; struct { void * TUbufferPtrs [
2 ] ; } TransportDelay_PWORK ; void * Scope1_PWORK_ag [ 2 ] ; int_T
StateSpace_IWORK [ 11 ] ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay1_IWORK ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay2_IWORK ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; int_T Saturation1_MODE ; int_T Saturation_MODE ; int_T
Step_MODE ; boolean_T Compare_Mode ; boolean_T RelationalOperator_Mode ;
boolean_T RelationalOperator1_Mode ; boolean_T RelationalOperator2_Mode ;
boolean_T Compare_Mode_j ; boolean_T Compare_Mode_c ; boolean_T
Compare_Mode_k ; boolean_T Compare_Mode_f ; boolean_T Compare_Mode_jh ;
char_T pad_Compare_Mode_jh [ 3 ] ; DW_SampleIL1_IBC_open_loop3_T
SampleandHold1 ; DW_SampleIL1_IBC_open_loop3_T SampleIL3 ;
DW_SampleIL1_IBC_open_loop3_T SampleIL2 ; DW_SampleIL1_IBC_open_loop3_T
SampleIL1 ; } DW_IBC_open_loop3_T ; typedef struct { real_T Integrator_CSTATE
; real_T Integrator_CSTATE_e ; } X_IBC_open_loop3_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_e ; } XDot_IBC_open_loop3_T ;
typedef struct { boolean_T Integrator_CSTATE ; boolean_T Integrator_CSTATE_e
; } XDis_IBC_open_loop3_T ; typedef struct { real_T Integrator_CSTATE ;
real_T Integrator_CSTATE_e ; } CStateAbsTol_IBC_open_loop3_T ; typedef struct
{ real_T Integrator_CSTATE ; real_T Integrator_CSTATE_e ; }
CXPtMin_IBC_open_loop3_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_e ; } CXPtMax_IBC_open_loop3_T ; typedef struct { real_T
Compare_RelopInput_ZC ; real_T Saturation1_UprLim_ZC ; real_T
Saturation1_LwrLim_ZC ; real_T Saturation_UprLim_ZC ; real_T
Saturation_LwrLim_ZC ; real_T RelationalOperator_RelopInput_ZC ; real_T
RelationalOperator1_RelopInput_ZC ; real_T RelationalOperator2_RelopInput_ZC
; real_T Compare_RelopInput_ZC_f ; real_T Compare_RelopInput_ZC_h ; real_T
Step_StepTime_ZC ; real_T Compare_RelopInput_ZC_j ; real_T
Compare_RelopInput_ZC_g ; real_T Compare_RelopInput_ZC_o ;
ZCV_SampleIL1_IBC_open_loop3_T SampleandHold1 ;
ZCV_SampleIL1_IBC_open_loop3_T SampleIL3 ; ZCV_SampleIL1_IBC_open_loop3_T
SampleIL2 ; ZCV_SampleIL1_IBC_open_loop3_T SampleIL1 ; } ZCV_IBC_open_loop3_T
; typedef struct { ZCSigState Compare_RelopInput_ZCE ; ZCSigState
Saturation1_UprLim_ZCE ; ZCSigState Saturation1_LwrLim_ZCE ; ZCSigState
Saturation_UprLim_ZCE ; ZCSigState Saturation_LwrLim_ZCE ; ZCSigState
RelationalOperator_RelopInput_ZCE ; ZCSigState
RelationalOperator1_RelopInput_ZCE ; ZCSigState
RelationalOperator2_RelopInput_ZCE ; ZCSigState Compare_RelopInput_ZCE_d ;
ZCSigState Compare_RelopInput_ZCE_e ; ZCSigState Step_StepTime_ZCE ;
ZCSigState Compare_RelopInput_ZCE_i ; ZCSigState Compare_RelopInput_ZCE_m ;
ZCSigState Compare_RelopInput_ZCE_ik ; ZCE_SampleIL1_IBC_open_loop3_T
SampleandHold1 ; ZCE_SampleIL1_IBC_open_loop3_T SampleIL3 ;
ZCE_SampleIL1_IBC_open_loop3_T SampleIL2 ; ZCE_SampleIL1_IBC_open_loop3_T
SampleIL1 ; } PrevZCX_IBC_open_loop3_T ; typedef struct { const real_T
B_4_0_0 ; const real_T B_4_1_0 ; const real_T B_4_2_0 ; const real_T B_4_3_0
; const real_T B_4_4_0 ; const real_T B_4_5_0 ; } ConstB_IBC_open_loop3_T ;
#define IBC_open_loop3_rtC(S) ((ConstB_IBC_open_loop3_T *) _ssGetConstBlockIO(S))
struct P_SampleIL1_IBC_open_loop3_T_ { real_T P_0 ; } ; struct
P_IBC_open_loop3_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 [ 2 ] ; real_T P_7 [ 16 ] ; real_T P_8 [
2 ] ; real_T P_9 [ 52 ] ; real_T P_10 [ 2 ] ; real_T P_11 [ 80 ] ; real_T
P_12 [ 2 ] ; real_T P_13 [ 260 ] ; real_T P_14 [ 2 ] ; real_T P_15 [ 4 ] ;
real_T P_16 [ 3 ] ; real_T P_17 [ 3 ] ; real_T P_18 ; real_T P_19 ; real_T
P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ;
real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T
P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ;
real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T
P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T P_47 ;
real_T P_48 ; real_T P_49 [ 3 ] ; real_T P_50 [ 3 ] ; real_T P_51 [ 3 ] ;
real_T P_52 [ 3 ] ; real_T P_53 ; real_T P_54 ; real_T P_55 [ 3 ] ; real_T
P_56 [ 3 ] ; real_T P_57 [ 9 ] ; real_T P_58 ; real_T P_59 ; real_T P_60 ;
real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T
P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ; uint8_T P_70 ; char_T
pad_P_70 [ 7 ] ; P_SampleIL1_IBC_open_loop3_T SampleandHold1 ;
P_SampleIL1_IBC_open_loop3_T SampleIL3 ; P_SampleIL1_IBC_open_loop3_T
SampleIL2 ; P_SampleIL1_IBC_open_loop3_T SampleIL1 ; } ; extern
P_IBC_open_loop3_T IBC_open_loop3_rtDefaultP ; extern const
ConstB_IBC_open_loop3_T IBC_open_loop3_rtInvariant ;
#endif
