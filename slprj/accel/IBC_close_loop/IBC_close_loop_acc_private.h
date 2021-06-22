#ifndef RTW_HEADER_IBC_close_loop_acc_private_h_
#define RTW_HEADER_IBC_close_loop_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "IBC_close_loop_acc.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T IBC_close_loop_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr
, int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay ,
int_T * maxNewBufSzPtr ) ; real_T IBC_close_loop_acc_rt_TDelayInterpolate (
real_T tMinusDelay , real_T tStart , real_T * uBuf , int_T bufSz , int_T *
lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput , boolean_T
discrete , boolean_T minorStepAndTAtLastMajorOutput ) ; extern real_T
look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T maxIndex ) ; void IBC_close_loop_SampleandHold_Init ( SimStruct * S
, B_SampleandHold_IBC_close_loop_T * localB ,
P_SampleandHold_IBC_close_loop_T * localP ) ; void
IBC_close_loop_SampleandHold ( SimStruct * S , boolean_T rtu_Trigger , real_T
rtu_In , B_SampleandHold_IBC_close_loop_T * localB ,
DW_SampleandHold_IBC_close_loop_T * localDW ,
ZCE_SampleandHold_IBC_close_loop_T * localZCE ) ; void
IBC_close_loop_SampleandHold_Term ( SimStruct * const S ) ;
#endif
