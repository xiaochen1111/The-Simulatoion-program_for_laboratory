#ifndef RTW_HEADER_IBC_close_loop2_acc_h_
#define RTW_HEADER_IBC_close_loop2_acc_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#ifndef IBC_close_loop2_acc_COMMON_INCLUDES_
#define IBC_close_loop2_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "IBC_close_loop2_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_1_0_0 ; } B_SampleIL1_IBC_close_loop2_T ; typedef
struct { int32_T SampleIL1_sysIdxToRun ; int8_T SampleIL1_SubsysRanBC ;
char_T pad_SampleIL1_SubsysRanBC [ 3 ] ; } DW_SampleIL1_IBC_close_loop2_T ;
typedef struct { real_T SampleIL1_Trig_ZC ; } ZCV_SampleIL1_IBC_close_loop2_T
; typedef struct { ZCSigState SampleIL1_Trig_ZCE ; }
ZCE_SampleIL1_IBC_close_loop2_T ; typedef struct { real_T B_5_4_0 ; real_T
B_5_5_0 ; real_T B_5_6_0 ; real_T B_5_7_0 [ 18 ] ; real_T B_5_7_1 [ 9 ] ;
real_T B_5_7_2 ; real_T B_5_9_0 ; real_T B_5_12_0 ; real_T B_5_13_0 ; real_T
B_5_15_0 ; real_T B_5_16_0 ; real_T B_5_20_0 ; real_T B_5_21_0 ; real_T
B_5_22_0 ; real_T B_5_23_0 ; real_T B_5_24_0 ; real_T B_5_26_0 ; real_T
B_5_28_0 ; real_T B_5_29_0 ; real_T B_5_30_0 ; real_T B_5_32_0 ; real_T
B_5_34_0 ; real_T B_5_37_0 ; real_T B_5_38_0 ; real_T B_5_40_0 ; real_T
B_5_41_0 ; real_T B_5_43_0 ; real_T B_5_69_0 ; real_T B_5_80_0 ; real_T
B_5_88_0 ; real_T B_5_98_0 ; real_T B_5_99_0 ; real_T B_5_100_0 ; real_T
B_5_135_0 ; real_T B_5_136_0 ; real_T B_5_146_0 ; real_T B_5_149_0 ; real_T
B_5_151_0 ; real_T B_5_154_0 ; real_T B_5_155_0 ; real_T B_5_157_0 ; real_T
B_5_160_0 ; real_T B_5_0_0 [ 9 ] ; real_T B_5_1_0 ; real_T B_5_2_0 ; real_T
B_5_3_0 ; real_T B_5_4_0_m ; real_T B_5_5_0_c ; real_T B_5_6_0_k ; real_T
B_5_7_0_c ; real_T B_5_8_0 ; real_T B_5_9_0_b ; real_T B_5_10_0 ; real_T
B_5_11_0 ; real_T B_5_12_0_p ; real_T B_5_13_0_c ; real_T B_5_14_0 ;
boolean_T B_5_17_0 ; boolean_T B_5_31_0 ; boolean_T B_5_33_0 ; boolean_T
B_5_35_0 ; boolean_T B_5_39_0 ; boolean_T B_5_42_0 ; boolean_T B_5_139_0 ;
boolean_T B_5_140_0 ; boolean_T B_5_141_0 ; char_T pad_B_5_141_0 [ 7 ] ;
B_SampleIL1_IBC_close_loop2_T SampleandHold1 ; B_SampleIL1_IBC_close_loop2_T
SampleIL3 ; B_SampleIL1_IBC_close_loop2_T SampleIL2 ;
B_SampleIL1_IBC_close_loop2_T SampleIL1 ; } B_IBC_close_loop2_T ; typedef
struct { real_T UnitDelay_DSTATE ; real_T StateSpace_DSTATE [ 4 ] ; real_T
StateSpace_RWORK ; struct { real_T modelTStart ; } TransportDelay1_RWORK ;
struct { real_T modelTStart ; } TransportDelay2_RWORK ; struct { real_T
modelTStart ; } TransportDelay_RWORK ; void * StateSpace_PWORK [ 65 ] ; void
* Scope1_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay1_PWORK
; struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay2_PWORK ; void *
Scope2_PWORK [ 3 ] ; void * Scope3_PWORK [ 9 ] ; void * Scope4_PWORK [ 4 ] ;
void * Scope5_PWORK [ 2 ] ; void * Scope9_PWORK [ 3 ] ; void * Scope_PWORK ;
void * Scope10_PWORK [ 4 ] ; void * Scope1_PWORK_a [ 3 ] ; void *
Scope2_PWORK_k ; void * Scope3_PWORK_a [ 3 ] ; void * Scope4_PWORK_f [ 3 ] ;
void * Scope5_PWORK_e ; void * Scope6_PWORK [ 4 ] ; struct { void *
TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK ; void * Scope1_PWORK_ag [ 2 ] ;
int32_T TmpAtomicSubsysAtSwitchInport3_sysIdxToRun ; int_T StateSpace_IWORK [
12 ] ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize
; int_T MaxNewBufSize ; } TransportDelay1_IWORK ; struct { int_T Tail ; int_T
Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay2_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK ; int_T
Step1_MODE ; int_T Saturation3_MODE ; int_T Saturation2_MODE ; int_T
Step_MODE ; boolean_T Compare_Mode ; boolean_T RelationalOperator_Mode ;
boolean_T RelationalOperator1_Mode ; boolean_T RelationalOperator2_Mode ;
boolean_T Compare_Mode_j ; boolean_T Compare_Mode_c ; boolean_T
Compare_Mode_k ; boolean_T Compare_Mode_f ; boolean_T Compare_Mode_jh ;
char_T pad_Compare_Mode_jh [ 7 ] ; DW_SampleIL1_IBC_close_loop2_T
SampleandHold1 ; DW_SampleIL1_IBC_close_loop2_T SampleIL3 ;
DW_SampleIL1_IBC_close_loop2_T SampleIL2 ; DW_SampleIL1_IBC_close_loop2_T
SampleIL1 ; } DW_IBC_close_loop2_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_k ; } X_IBC_close_loop2_T ;
typedef struct { real_T Integrator_CSTATE ; real_T Integrator_CSTATE_k ; }
XDot_IBC_close_loop2_T ; typedef struct { boolean_T Integrator_CSTATE ;
boolean_T Integrator_CSTATE_k ; } XDis_IBC_close_loop2_T ; typedef struct {
real_T Integrator_CSTATE ; real_T Integrator_CSTATE_k ; }
CStateAbsTol_IBC_close_loop2_T ; typedef struct { real_T Integrator_CSTATE ;
real_T Integrator_CSTATE_k ; } CXPtMin_IBC_close_loop2_T ; typedef struct {
real_T Integrator_CSTATE ; real_T Integrator_CSTATE_k ; }
CXPtMax_IBC_close_loop2_T ; typedef struct { real_T Step1_StepTime_ZC ;
real_T Compare_RelopInput_ZC ; real_T Saturation3_UprLim_ZC ; real_T
Saturation3_LwrLim_ZC ; real_T Saturation2_UprLim_ZC ; real_T
Saturation2_LwrLim_ZC ; real_T RelationalOperator_RelopInput_ZC ; real_T
RelationalOperator1_RelopInput_ZC ; real_T RelationalOperator2_RelopInput_ZC
; real_T Compare_RelopInput_ZC_f ; real_T Compare_RelopInput_ZC_h ; real_T
Step_StepTime_ZC ; real_T Compare_RelopInput_ZC_j ; real_T
Compare_RelopInput_ZC_g ; real_T Compare_RelopInput_ZC_o ;
ZCV_SampleIL1_IBC_close_loop2_T SampleandHold1 ;
ZCV_SampleIL1_IBC_close_loop2_T SampleIL3 ; ZCV_SampleIL1_IBC_close_loop2_T
SampleIL2 ; ZCV_SampleIL1_IBC_close_loop2_T SampleIL1 ; }
ZCV_IBC_close_loop2_T ; typedef struct { ZCSigState Step1_StepTime_ZCE ;
ZCSigState Compare_RelopInput_ZCE ; ZCSigState Saturation3_UprLim_ZCE ;
ZCSigState Saturation3_LwrLim_ZCE ; ZCSigState Saturation2_UprLim_ZCE ;
ZCSigState Saturation2_LwrLim_ZCE ; ZCSigState
RelationalOperator_RelopInput_ZCE ; ZCSigState
RelationalOperator1_RelopInput_ZCE ; ZCSigState
RelationalOperator2_RelopInput_ZCE ; ZCSigState Compare_RelopInput_ZCE_d ;
ZCSigState Compare_RelopInput_ZCE_e ; ZCSigState Step_StepTime_ZCE ;
ZCSigState Compare_RelopInput_ZCE_i ; ZCSigState Compare_RelopInput_ZCE_m ;
ZCSigState Compare_RelopInput_ZCE_ik ; ZCE_SampleIL1_IBC_close_loop2_T
SampleandHold1 ; ZCE_SampleIL1_IBC_close_loop2_T SampleIL3 ;
ZCE_SampleIL1_IBC_close_loop2_T SampleIL2 ; ZCE_SampleIL1_IBC_close_loop2_T
SampleIL1 ; } PrevZCX_IBC_close_loop2_T ; typedef struct { const real_T
B_5_0_0 ; const real_T B_5_1_0 ; const real_T B_5_2_0 ; const real_T B_5_3_0
; const real_T B_5_4_0 ; const real_T B_5_5_0 ; } ConstB_IBC_close_loop2_T ;
#define IBC_close_loop2_rtC(S) ((ConstB_IBC_close_loop2_T *) _ssGetConstBlockIO(S))
struct P_SampleIL1_IBC_close_loop2_T_ { real_T P_0 ; } ; struct
P_IBC_close_loop2_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 [ 2 ] ; real_T P_13 ; real_T P_14 [ 2
] ; real_T P_15 [ 16 ] ; real_T P_16 [ 2 ] ; real_T P_17 [ 56 ] ; real_T P_18
[ 2 ] ; real_T P_19 [ 72 ] ; real_T P_20 [ 2 ] ; real_T P_21 [ 252 ] ; real_T
P_22 [ 2 ] ; real_T P_23 [ 4 ] ; real_T P_24 [ 2 ] ; real_T P_25 ; real_T
P_26 [ 2 ] ; real_T P_27 [ 3 ] ; real_T P_28 [ 2 ] ; real_T P_30 [ 2 ] ;
real_T P_31 ; real_T P_32 [ 2 ] ; real_T P_33 ; real_T P_34 [ 2 ] ; real_T
P_36 [ 2 ] ; real_T P_37 ; real_T P_38 [ 2 ] ; real_T P_39 ; real_T P_40 [ 2
] ; real_T P_42 [ 2 ] ; real_T P_43 ; real_T P_44 [ 2 ] ; real_T P_45 ;
real_T P_46 [ 2 ] ; real_T P_47 ; real_T P_48 [ 2 ] ; real_T P_49 ; real_T
P_50 [ 2 ] ; real_T P_51 [ 9 ] ; real_T P_52 [ 2 ] ; real_T P_53 [ 9 ] ;
real_T P_54 [ 2 ] ; real_T P_55 [ 9 ] ; real_T P_56 [ 2 ] ; real_T P_57 [ 9 ]
; real_T P_58 [ 2 ] ; real_T P_59 ; real_T P_60 [ 3 ] ; real_T P_61 [ 3 ] ;
real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T
P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ;
real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T
P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ;
real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ; real_T
P_89 [ 3 ] ; real_T P_90 [ 3 ] ; real_T P_91 [ 3 ] ; real_T P_92 [ 3 ] ;
real_T P_93 ; real_T P_94 ; real_T P_95 [ 3 ] ; real_T P_96 [ 3 ] ; real_T
P_97 [ 9 ] ; real_T P_98 ; real_T P_99 ; real_T P_100 ; real_T P_101 ; real_T
P_102 ; real_T P_103 ; real_T P_104 ; real_T P_105 ; real_T P_106 ; real_T
P_107 ; real_T P_108 ; real_T P_109 ; real_T P_110 ; real_T P_111 ;
P_SampleIL1_IBC_close_loop2_T SampleandHold1 ; P_SampleIL1_IBC_close_loop2_T
SampleIL3 ; P_SampleIL1_IBC_close_loop2_T SampleIL2 ;
P_SampleIL1_IBC_close_loop2_T SampleIL1 ; } ; extern P_IBC_close_loop2_T
IBC_close_loop2_rtDefaultP ; extern const ConstB_IBC_close_loop2_T
IBC_close_loop2_rtInvariant ;
#endif
