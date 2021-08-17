/*
 * test1.c
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

#include "test1.h"
#include "test1_private.h"

/* Block signals (default storage) */
B_test1_T test1_B;

/* Block states (default storage) */
DW_test1_T test1_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_test1_T test1_Y;

/* Real-time model */
static RT_MODEL_test1_T test1_M_;
RT_MODEL_test1_T *const test1_M = &test1_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;
  real_T* tBuf = uBuf + bufSz;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model step function */
void test1_step(void)
{
  /* local block i/o variables */
  real_T rtb_LookUpTable1;
  real_T rtb_LookUpTable1_g;
  real_T LookUpTable1_tmp;

  /* Clock: '<S8>/Clock' incorporates:
   *  Clock: '<S10>/Clock'
   *  Clock: '<S11>/Clock'
   *  Clock: '<S9>/Clock'
   */
  LookUpTable1_tmp = test1_M->Timing.t[0];

  /* Lookup_n-D: '<S8>/Look-Up Table1' incorporates:
   *  Clock: '<S8>/Clock'
   *  Constant: '<S8>/Constant'
   *  Math: '<S8>/Math Function'
   */
  test1_B.LookUpTable1 = look1_binlxpw(rt_remd_snf(LookUpTable1_tmp,
    test1_P.Constant_Value_b), test1_P.LookUpTable1_bp01Data,
    test1_P.RepeatingSequence_rep_seq_y, 2U);

  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  RelationalOperator: '<S1>/Relational Operator'
   */
  test1_Y.Out1 = (test1_P.Constant1_Value > test1_B.LookUpTable1);

  /* TransportDelay: '<S1>/Transport Delay1' */
  {
    real_T **uBuffer = (real_T**)&test1_DW.TransportDelay1_PWORK.TUbufferPtrs[0];
    real_T simTime = test1_M->Timing.t[0];
    real_T tMinusDelay = simTime - (1.0 / test1_P._Fs / 3.0);
    test1_B.TransportDelay1 = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *uBuffer,
      test1_DW.TransportDelay1_IWORK.CircularBufSize,
      &test1_DW.TransportDelay1_IWORK.Last,
      test1_DW.TransportDelay1_IWORK.Tail,
      test1_DW.TransportDelay1_IWORK.Head,
      test1_P.TransportDelay1_InitOutput,
      0,
      0);
  }

  /* Outport: '<Root>/Out2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  RelationalOperator: '<S1>/Relational Operator1'
   */
  test1_Y.Out2 = (test1_P.Constant1_Value > test1_B.TransportDelay1);

  /* Outport: '<Root>/Out3' */
  test1_Y.Out3 = test1_B.LookUpTable1;

  /* TransportDelay: '<S1>/Transport Delay2' */
  {
    real_T **uBuffer = (real_T**)&test1_DW.TransportDelay2_PWORK.TUbufferPtrs[0];
    real_T simTime = test1_M->Timing.t[0];
    real_T tMinusDelay = simTime - (2.0 / test1_P._Fs / 3.0);
    test1_B.TransportDelay2 = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *uBuffer,
      test1_DW.TransportDelay2_IWORK.CircularBufSize,
      &test1_DW.TransportDelay2_IWORK.Last,
      test1_DW.TransportDelay2_IWORK.Tail,
      test1_DW.TransportDelay2_IWORK.Head,
      test1_P.TransportDelay2_InitOutput,
      0,
      0);
  }

  /* Outport: '<Root>/Out4' incorporates:
   *  Constant: '<Root>/Constant1'
   *  RelationalOperator: '<S1>/Relational Operator2'
   */
  test1_Y.Out4 = (test1_P.Constant1_Value > test1_B.TransportDelay2);

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   */
  test1_B.Sum = test1_P.Constant_Value_av - test1_B.LookUpTable1;

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   */
  test1_B.Compare = (test1_B.Sum <= test1_P.Constant_Value_a);

  /* Outport: '<Root>/Out5' */
  test1_Y.Out5 = test1_B.Compare;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  test1_B.Sum1 = test1_P.Constant_Value_av - test1_B.TransportDelay1;

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  test1_B.Compare_c = (test1_B.Sum1 <= test1_P.Constant_Value_d);

  /* Outport: '<Root>/Out6' */
  test1_Y.Out6 = test1_B.Compare_c;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<S1>/Constant'
   */
  test1_B.Sum2 = test1_P.Constant_Value_av - test1_B.TransportDelay2;

  /* Outport: '<Root>/Out7' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  test1_Y.Out7 = (test1_B.Sum2 <= test1_P.Constant_Value_ln);

  /* Outport: '<Root>/Out8' */
  test1_Y.Out8 = test1_B.LookUpTable1;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  test1_B.Compare_l = (test1_B.LookUpTable1 == test1_P.Constant_Value);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   */
  test1_B.Compare_h = (test1_B.TransportDelay1 == test1_P.Constant_Value_l);

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  test1_B.Compare_ln = (test1_B.TransportDelay2 == test1_P.Constant_Value_c);

  /* Lookup_n-D: '<S9>/Look-Up Table1' incorporates:
   *  Constant: '<S9>/Constant'
   *  Math: '<S9>/Math Function'
   */
  rtb_LookUpTable1 = look1_binlxpw(rt_remd_snf(LookUpTable1_tmp,
    test1_P.Constant_Value_j), test1_P.LookUpTable1_bp01Data_a,
    test1_P.RepeatingSequence1_rep_seq_y, 2U);

  /* Lookup_n-D: '<S10>/Look-Up Table1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Math: '<S10>/Math Function'
   */
  rtb_LookUpTable1_g = look1_binlxpw(rt_remd_snf(LookUpTable1_tmp,
    test1_P.Constant_Value_k), test1_P.LookUpTable1_bp01Data_aw,
    test1_P.RepeatingSequence2_rep_seq_y, 2U);

  /* TransportDelay: '<S1>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&test1_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T simTime = test1_M->Timing.t[0];
    real_T tMinusDelay = simTime - (test1_P.TransportDelay_Delay);
    test1_B.TransportDelay = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *uBuffer,
      test1_DW.TransportDelay_IWORK.CircularBufSize,
      &test1_DW.TransportDelay_IWORK.Last,
      test1_DW.TransportDelay_IWORK.Tail,
      test1_DW.TransportDelay_IWORK.Head,
      test1_P.TransportDelay_InitOutput,
      0,
      0);
  }

  /* Lookup_n-D: '<S11>/Look-Up Table1' incorporates:
   *  Constant: '<S11>/Constant'
   *  Math: '<S11>/Math Function'
   */
  test1_B.LookUpTable1_o = look1_binlxpw(rt_remd_snf(LookUpTable1_tmp,
    test1_P.Constant_Value_kc), test1_P.LookUpTable1_bp01Data_p,
    test1_P.RepeatingSequence4_rep_seq_y, 2U);

  /* Matfile logging */
  rt_UpdateTXYLogVars(test1_M->rtwLogInfo, (test1_M->Timing.t));

  /* Update for TransportDelay: '<S1>/Transport Delay1' */
  {
    real_T **uBuffer = (real_T**)&test1_DW.TransportDelay1_PWORK.TUbufferPtrs[0];
    real_T simTime = test1_M->Timing.t[0];
    test1_DW.TransportDelay1_IWORK.Head = ((test1_DW.TransportDelay1_IWORK.Head <
      (test1_DW.TransportDelay1_IWORK.CircularBufSize-1)) ?
      (test1_DW.TransportDelay1_IWORK.Head+1) : 0);
    if (test1_DW.TransportDelay1_IWORK.Head ==
        test1_DW.TransportDelay1_IWORK.Tail) {
      test1_DW.TransportDelay1_IWORK.Tail =
        ((test1_DW.TransportDelay1_IWORK.Tail <
          (test1_DW.TransportDelay1_IWORK.CircularBufSize-1)) ?
         (test1_DW.TransportDelay1_IWORK.Tail+1) : 0);
    }

    (*uBuffer + test1_DW.TransportDelay1_IWORK.CircularBufSize)
      [test1_DW.TransportDelay1_IWORK.Head] = simTime;
    (*uBuffer)[test1_DW.TransportDelay1_IWORK.Head] = rtb_LookUpTable1;
  }

  /* Update for TransportDelay: '<S1>/Transport Delay2' */
  {
    real_T **uBuffer = (real_T**)&test1_DW.TransportDelay2_PWORK.TUbufferPtrs[0];
    real_T simTime = test1_M->Timing.t[0];
    test1_DW.TransportDelay2_IWORK.Head = ((test1_DW.TransportDelay2_IWORK.Head <
      (test1_DW.TransportDelay2_IWORK.CircularBufSize-1)) ?
      (test1_DW.TransportDelay2_IWORK.Head+1) : 0);
    if (test1_DW.TransportDelay2_IWORK.Head ==
        test1_DW.TransportDelay2_IWORK.Tail) {
      test1_DW.TransportDelay2_IWORK.Tail =
        ((test1_DW.TransportDelay2_IWORK.Tail <
          (test1_DW.TransportDelay2_IWORK.CircularBufSize-1)) ?
         (test1_DW.TransportDelay2_IWORK.Tail+1) : 0);
    }

    (*uBuffer + test1_DW.TransportDelay2_IWORK.CircularBufSize)
      [test1_DW.TransportDelay2_IWORK.Head] = simTime;
    (*uBuffer)[test1_DW.TransportDelay2_IWORK.Head] = rtb_LookUpTable1_g;
  }

  /* Update for TransportDelay: '<S1>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&test1_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T simTime = test1_M->Timing.t[0];
    test1_DW.TransportDelay_IWORK.Head = ((test1_DW.TransportDelay_IWORK.Head <
      (test1_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
      (test1_DW.TransportDelay_IWORK.Head+1) : 0);
    if (test1_DW.TransportDelay_IWORK.Head == test1_DW.TransportDelay_IWORK.Tail)
    {
      test1_DW.TransportDelay_IWORK.Tail = ((test1_DW.TransportDelay_IWORK.Tail <
        (test1_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
        (test1_DW.TransportDelay_IWORK.Tail+1) : 0);
    }

    (*uBuffer + test1_DW.TransportDelay_IWORK.CircularBufSize)
      [test1_DW.TransportDelay_IWORK.Head] = simTime;
    (*uBuffer)[test1_DW.TransportDelay_IWORK.Head] = test1_B.LookUpTable1_o;
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(test1_M)!=-1) &&
        !((rtmGetTFinal(test1_M)-test1_M->Timing.t[0]) > test1_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(test1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test1_M->Timing.clockTick0)) {
    ++test1_M->Timing.clockTickH0;
  }

  test1_M->Timing.t[0] = test1_M->Timing.clockTick0 * test1_M->Timing.stepSize0
    + test1_M->Timing.clockTickH0 * test1_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.004s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.004, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    test1_M->Timing.clockTick1++;
    if (!test1_M->Timing.clockTick1) {
      test1_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void test1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test1_M, 0,
                sizeof(RT_MODEL_test1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test1_M->solverInfo, &test1_M->Timing.simTimeStep);
    rtsiSetTPtr(&test1_M->solverInfo, &rtmGetTPtr(test1_M));
    rtsiSetStepSizePtr(&test1_M->solverInfo, &test1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test1_M->solverInfo, (&rtmGetErrorStatus(test1_M)));
    rtsiSetRTModelPtr(&test1_M->solverInfo, test1_M);
  }

  rtsiSetSimTimeStep(&test1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&test1_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(test1_M, &test1_M->Timing.tArray[0]);
  rtmSetTFinal(test1_M, 0.2);
  test1_M->Timing.stepSize0 = 0.004;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    test1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(test1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(test1_M->rtwLogInfo, (NULL));
    rtliSetLogT(test1_M->rtwLogInfo, "tout");
    rtliSetLogX(test1_M->rtwLogInfo, "");
    rtliSetLogXFinal(test1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(test1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(test1_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(test1_M->rtwLogInfo, 0);
    rtliSetLogDecimation(test1_M->rtwLogInfo, 1);
    rtliSetLogY(test1_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(test1_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(test1_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &test1_B), 0,
                sizeof(B_test1_T));

  /* states (dwork) */
  (void) memset((void *)&test1_DW, 0,
                sizeof(DW_test1_T));

  /* external outputs */
  (void) memset((void *)&test1_Y, 0,
                sizeof(ExtY_test1_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(test1_M->rtwLogInfo, 0.0, rtmGetTFinal
    (test1_M), test1_M->Timing.stepSize0, (&rtmGetErrorStatus(test1_M)));

  /* Start for TransportDelay: '<S1>/Transport Delay1' */
  {
    real_T *pBuffer = &test1_DW.TransportDelay1_RWORK.TUbufferArea[0];
    test1_DW.TransportDelay1_IWORK.Tail = 0;
    test1_DW.TransportDelay1_IWORK.Head = 0;
    test1_DW.TransportDelay1_IWORK.Last = 0;
    test1_DW.TransportDelay1_IWORK.CircularBufSize = 1024;
    pBuffer[0] = test1_P.TransportDelay1_InitOutput;
    pBuffer[1024] = test1_M->Timing.t[0];
    test1_DW.TransportDelay1_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
  }

  /* Start for TransportDelay: '<S1>/Transport Delay2' */
  {
    real_T *pBuffer = &test1_DW.TransportDelay2_RWORK.TUbufferArea[0];
    test1_DW.TransportDelay2_IWORK.Tail = 0;
    test1_DW.TransportDelay2_IWORK.Head = 0;
    test1_DW.TransportDelay2_IWORK.Last = 0;
    test1_DW.TransportDelay2_IWORK.CircularBufSize = 1024;
    pBuffer[0] = test1_P.TransportDelay2_InitOutput;
    pBuffer[1024] = test1_M->Timing.t[0];
    test1_DW.TransportDelay2_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
  }

  /* Start for TransportDelay: '<S1>/Transport Delay' */
  {
    real_T *pBuffer = &test1_DW.TransportDelay_RWORK.TUbufferArea[0];
    test1_DW.TransportDelay_IWORK.Tail = 0;
    test1_DW.TransportDelay_IWORK.Head = 0;
    test1_DW.TransportDelay_IWORK.Last = 0;
    test1_DW.TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = test1_P.TransportDelay_InitOutput;
    pBuffer[1024] = test1_M->Timing.t[0];
    test1_DW.TransportDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
  }
}

/* Model terminate function */
void test1_terminate(void)
{
  /* (no terminate code required) */
}
