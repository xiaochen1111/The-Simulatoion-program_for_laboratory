/*
 * test1_data.c
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

/* Block parameters (default storage) */
P_test1_T test1_P = {
  /* Mask Parameter: _Fs
   * Referenced by:
   *   '<S1>/Transport Delay1'
   *   '<S1>/Transport Delay2'
   */
  10000.0,

  /* Mask Parameter: RepeatingSequence_rep_seq_y
   * Referenced by: '<S8>/Look-Up Table1'
   */
  { 0.0, 1000.0, 0.0 },

  /* Mask Parameter: RepeatingSequence1_rep_seq_y
   * Referenced by: '<S9>/Look-Up Table1'
   */
  { 0.0, 1000.0, 0.0 },

  /* Mask Parameter: RepeatingSequence2_rep_seq_y
   * Referenced by: '<S10>/Look-Up Table1'
   */
  { 0.0, 1000.0, 0.0 },

  /* Mask Parameter: RepeatingSequence4_rep_seq_y
   * Referenced by: '<S11>/Look-Up Table1'
   */
  { 0.0, 1000.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 500
   * Referenced by: '<Root>/Constant1'
   */
  500.0,

  /* Expression: period
   * Referenced by: '<S8>/Constant'
   */
  0.0001,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S8>/Look-Up Table1'
   */
  { 0.0, 5.0E-5, 0.0001 },

  /* Expression: 0
   * Referenced by: '<S1>/Transport Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Transport Delay2'
   */
  0.0,

  /* Expression: 999
   * Referenced by: '<S1>/Constant'
   */
  999.0,

  /* Expression: period
   * Referenced by: '<S9>/Constant'
   */
  0.0001,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S9>/Look-Up Table1'
   */
  { 0.0, 4.9999999999999996E-5, 0.0001 },

  /* Expression: period
   * Referenced by: '<S10>/Constant'
   */
  0.0001,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S10>/Look-Up Table1'
   */
  { 0.0, 4.9999999999999996E-5, 9.9999999999999991E-5 },

  /* Expression: 1./100e3./3
   * Referenced by: '<S1>/Transport Delay'
   */
  3.3333333333333337E-6,

  /* Expression: 0
   * Referenced by: '<S1>/Transport Delay'
   */
  0.0,

  /* Expression: period
   * Referenced by: '<S11>/Constant'
   */
  1.0E-5,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S11>/Look-Up Table1'
   */
  { 0.0, 5.0E-6, 1.0E-5 }
};
