/*
 * test1.h
 *
 * Code generation for model "test1".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jul 16 20:45:21 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test1_h_
#define RTW_HEADER_test1_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef test1_COMMON_INCLUDES_
#define test1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* test1_COMMON_INCLUDES_ */

#include "test1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T LookUpTable1;                 /* '<S8>/Look-Up Table1' */
  real_T TransportDelay1;              /* '<S1>/Transport Delay1' */
  real_T TransportDelay2;              /* '<S1>/Transport Delay2' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T TransportDelay;               /* '<S1>/Transport Delay' */
  real_T LookUpTable1_o;               /* '<S11>/Look-Up Table1' */
  boolean_T Compare;                   /* '<S5>/Compare' */
  boolean_T Compare_c;                 /* '<S6>/Compare' */
  boolean_T Compare_l;                 /* '<S2>/Compare' */
  boolean_T Compare_h;                 /* '<S3>/Compare' */
  boolean_T Compare_ln;                /* '<S4>/Compare' */
} B_test1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay1_RWORK;             /* '<S1>/Transport Delay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay2_RWORK;             /* '<S1>/Transport Delay2' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK;              /* '<S1>/Transport Delay' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay1_PWORK;             /* '<S1>/Transport Delay1' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay2_PWORK;             /* '<S1>/Transport Delay2' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S1>/Transport Delay' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay1_IWORK;             /* '<S1>/Transport Delay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay2_IWORK;             /* '<S1>/Transport Delay2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S1>/Transport Delay' */
} DW_test1_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Out1;                      /* '<Root>/Out1' */
  boolean_T Out2;                      /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
  boolean_T Out4;                      /* '<Root>/Out4' */
  boolean_T Out5;                      /* '<Root>/Out5' */
  boolean_T Out6;                      /* '<Root>/Out6' */
  boolean_T Out7;                      /* '<Root>/Out7' */
  real_T Out8;                         /* '<Root>/Out8' */
} ExtY_test1_T;

/* Parameters (default storage) */
struct P_test1_T_ {
  real_T _Fs;                          /* Mask Parameter: _Fs
                                        * Referenced by:
                                        *   '<S1>/Transport Delay1'
                                        *   '<S1>/Transport Delay2'
                                        */
  real_T RepeatingSequence_rep_seq_y[3];
                                  /* Mask Parameter: RepeatingSequence_rep_seq_y
                                   * Referenced by: '<S8>/Look-Up Table1'
                                   */
  real_T RepeatingSequence1_rep_seq_y[3];
                                 /* Mask Parameter: RepeatingSequence1_rep_seq_y
                                  * Referenced by: '<S9>/Look-Up Table1'
                                  */
  real_T RepeatingSequence2_rep_seq_y[3];
                                 /* Mask Parameter: RepeatingSequence2_rep_seq_y
                                  * Referenced by: '<S10>/Look-Up Table1'
                                  */
  real_T RepeatingSequence4_rep_seq_y[3];
                                 /* Mask Parameter: RepeatingSequence4_rep_seq_y
                                  * Referenced by: '<S11>/Look-Up Table1'
                                  */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant_Value_ln;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 500
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: period
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[3];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S8>/Look-Up Table1'
                                        */
  real_T TransportDelay1_InitOutput;   /* Expression: 0
                                        * Referenced by: '<S1>/Transport Delay1'
                                        */
  real_T TransportDelay2_InitOutput;   /* Expression: 0
                                        * Referenced by: '<S1>/Transport Delay2'
                                        */
  real_T Constant_Value_av;            /* Expression: 999
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: period
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_a[3];   /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T Constant_Value_k;             /* Expression: period
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_aw[3];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S10>/Look-Up Table1'
                                        */
  real_T TransportDelay_Delay;         /* Expression: 1./100e3./3
                                        * Referenced by: '<S1>/Transport Delay'
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S1>/Transport Delay'
                                        */
  real_T Constant_Value_kc;            /* Expression: period
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_p[3];   /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S11>/Look-Up Table1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test1_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_test1_T test1_P;

/* Block signals (default storage) */
extern B_test1_T test1_B;

/* Block states (default storage) */
extern DW_test1_T test1_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_test1_T test1_Y;

/* Model entry point functions */
extern void test1_initialize(void);
extern void test1_step(void);
extern void test1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test1_T *const test1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test1'
 * '<S1>'   : 'test1/命令信号生产'
 * '<S2>'   : 'test1/命令信号生产/Compare To Zero'
 * '<S3>'   : 'test1/命令信号生产/Compare To Zero1'
 * '<S4>'   : 'test1/命令信号生产/Compare To Zero2'
 * '<S5>'   : 'test1/命令信号生产/Compare To Zero3'
 * '<S6>'   : 'test1/命令信号生产/Compare To Zero4'
 * '<S7>'   : 'test1/命令信号生产/Compare To Zero5'
 * '<S8>'   : 'test1/命令信号生产/Repeating Sequence'
 * '<S9>'   : 'test1/命令信号生产/Repeating Sequence1'
 * '<S10>'  : 'test1/命令信号生产/Repeating Sequence2'
 * '<S11>'  : 'test1/命令信号生产/Repeating Sequence4'
 * '<S12>'  : 'test1/命令信号生产/powergui'
 */
#endif                                 /* RTW_HEADER_test1_h_ */
