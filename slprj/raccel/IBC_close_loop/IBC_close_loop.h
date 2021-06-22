#ifndef RTW_HEADER_IBC_close_loop_h_
#define RTW_HEADER_IBC_close_loop_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef IBC_close_loop_COMMON_INCLUDES_
#define IBC_close_loop_COMMON_INCLUDES_
#include <stdio.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "IBC_close_loop_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME IBC_close_loop
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (37) 
#define NUM_ZC_EVENTS (2) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T p5wwiu03ls ; } p0ohp5dzcn ; typedef struct { int8_T
jyt15m5n5h ; } gsasfxrjvu ; typedef struct { real_T l5fs0ns53n ; } plkmby4hvs
; typedef struct { ZCSigState ada3agjfan ; } npsps4asxr ; typedef struct {
real_T agn4x3drjs [ 17 ] ; real_T irxwz2klfa [ 9 ] ; real_T idzaeea1lj ;
real_T jirgucywty ; real_T njyqw3gypd ; real_T krjlzhi2hw ; real_T dvjrtmyu4l
[ 3 ] ; real_T eekajp3dsw ; real_T g4ttm0jd3j ; real_T cy0apjvkno ; real_T
eitgvaqdla ; real_T f5grkow3lv ; real_T amqaipqoht ; real_T jj5htd1qpd ;
real_T iqodxjvqjm ; real_T pkdqnlyvhd ; real_T iyxr5frzyq ; real_T dpijkcpfpb
; real_T eh0txmg2mg ; real_T mwfeqafa0o ; real_T hac1mxz2pn ; real_T
opwmy0qdum ; real_T hvbnfudyrr ; real_T mcgxsf0lqd ; real_T ekt10g5oul ;
real_T g3iapqckrv ; real_T kagelnoork ; real_T jmnr504r1m ; real_T nhlx1d2f35
; real_T i1ollxafrx ; real_T hofz3ldwny ; real_T gjh4vpxeef ; boolean_T
dphockrl25 ; boolean_T cibd5iyhfd ; boolean_T pl55r2bbaf ; p0ohp5dzcn
mpxykrjyje ; p0ohp5dzcn bbl254ocw35 ; } B ; typedef struct { real_T
ezqniqrzfs [ 4 ] ; struct { real_T modelTStart ; } gkp3oik3j1 ; struct {
real_T modelTStart ; } lb0zviipkc ; struct { real_T modelTStart ; }
izbfxxh1df ; struct { void * AS ; void * BS ; void * CS ; void * DS ; void *
DX_COL ; void * BD_COL ; void * TMP1 ; void * TMP2 ; void * XTMP ; void *
SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ;
void * USWLAST ; void * XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ;
void * IDX_SW_CHG ; void * Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW
; void * SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } dovginqio5 ; struct {
void * LoggedData ; } kgdautj2em ; struct { void * TUbufferPtrs [ 2 ] ; }
i2wglovkhg ; struct { void * TUbufferPtrs [ 2 ] ; } bwajcs0k3f ; struct {
void * LoggedData [ 2 ] ; } mwrrp12s1e ; struct { void * LoggedData [ 3 ] ; }
cphqenwi0j ; struct { void * LoggedData [ 4 ] ; } g4u2peeyzh ; struct { void
* LoggedData [ 2 ] ; } hcwvjzomrk ; struct { void * LoggedData [ 2 ] ; }
jnbhswzni2 ; struct { void * LoggedData [ 3 ] ; } mddrxtspjz ; struct { void
* LoggedData ; } pn4hj5ts5w ; struct { void * LoggedData [ 3 ] ; } l5cuukvckv
; struct { void * LoggedData [ 4 ] ; } lvwscoupef ; struct { void *
TUbufferPtrs [ 2 ] ; } cv4dngi50w ; struct { void * LoggedData [ 2 ] ; }
gln2uf24nm ; int_T mdhj3jmr2m [ 11 ] ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; } bhyxixrkat ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } f0mexgzhmf ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } aqlhy4dn2h ; int_T
ckvi3kfspw ; int_T lrunokatih ; int_T duktatxh0g ; boolean_T cf10juf2yd ;
boolean_T m1ehop2vyv ; boolean_T ers0xtszdu ; boolean_T juaxs13w1s ;
gsasfxrjvu mpxykrjyje ; gsasfxrjvu bbl254ocw35 ; } DW ; typedef struct {
real_T f4b2akr1xr ; real_T imglxcmvbb ; real_T am24gftgqk [ 2 ] ; } X ;
typedef struct { real_T f4b2akr1xr ; real_T imglxcmvbb ; real_T am24gftgqk [
2 ] ; } XDot ; typedef struct { boolean_T f4b2akr1xr ; boolean_T imglxcmvbb ;
boolean_T am24gftgqk [ 2 ] ; } XDis ; typedef struct { real_T f4b2akr1xr ;
real_T imglxcmvbb ; real_T am24gftgqk [ 2 ] ; } CStateAbsTol ; typedef struct
{ real_T f4b2akr1xr ; real_T imglxcmvbb ; real_T am24gftgqk [ 2 ] ; } CXPtMin
; typedef struct { real_T f4b2akr1xr ; real_T imglxcmvbb ; real_T am24gftgqk
[ 2 ] ; } CXPtMax ; typedef struct { real_T p1tz0xkgp3 ; real_T ktdcqf1rh0 ;
real_T d225dfblzs ; real_T i1axyh4zp4 ; real_T l3w3xz0qkj ; real_T memsrtnyjm
; real_T h4x50iiqvq ; real_T gklr0wicg2 ; real_T gnv3lf1c3y ; plkmby4hvs
mpxykrjyje ; plkmby4hvs bbl254ocw35 ; } ZCV ; typedef struct { npsps4asxr
mpxykrjyje ; npsps4asxr bbl254ocw35 ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct imgabiow3g_ { real_T
_Y0 ; } ; struct P_ { real_T alp ; real_T _Fs ; real_T PIDController_I ;
real_T PIDController1_I ; real_T PIDController1_InitialConditionForIntegrator
; real_T PIDController_InitialConditionForIntegrator ; real_T
PIDController1_P ; real_T PIDController_P ; real_T IBC_Vin ; real_T
RepeatingSequence_rep_seq_y [ 3 ] ; real_T RepeatingSequence1_rep_seq_y [ 3 ]
; real_T RepeatingSequence2_rep_seq_y [ 3 ] ; real_T
RepeatingSequence4_rep_seq_y [ 3 ] ; real_T Constant_Value ; real_T
StateSpace_AS_param [ 16 ] ; real_T StateSpace_BS_param [ 52 ] ; real_T
StateSpace_CS_param [ 68 ] ; real_T StateSpace_DS_param [ 221 ] ; real_T
StateSpace_X0_param [ 4 ] ; real_T donotdeletethisgain_Gain ; real_T
LookUpTable1_bp01Data [ 3 ] ; real_T TransportDelay1_InitOutput ; real_T
TransportDelay2_InitOutput ; real_T Gain_Gain ; real_T
donotdeletethisgain_Gain_dojjjvjkoc ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T donotdeletethisgain_Gain_fy4vzgl50q ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
donotdeletethisgain_Gain_cswjbtqcc2 ; real_T
donotdeletethisgain_Gain_nwj215l5x1 ; real_T Step_Time ; real_T Step_Y0 ;
real_T Step_YFinal ; real_T Switch_Threshold ; real_T
donotdeletethisgain_Gain_cthxcecbau ; real_T
donotdeletethisgain_Gain_ctalfroa4m ; real_T
donotdeletethisgain_Gain_o54pdurymu ; real_T LookUpTable1_bp01Data_p4fekf0sau
[ 3 ] ; real_T LookUpTable1_bp01Data_eancggqfkt [ 3 ] ; real_T
TransportDelay_Delay ; real_T TransportDelay_InitOutput ; real_T
LookUpTable1_bp01Data_fwaln5kcoo [ 3 ] ; real_T SineWave1_Amp ; real_T
SineWave1_Bias ; real_T SineWave1_Freq ; real_T SineWave1_Phase ; real_T
TransferFcn1_A [ 2 ] ; real_T TransferFcn1_C [ 2 ] ; real_T
SwitchCurrents_Value [ 9 ] ; real_T Constant_Value_oa4sl44jdq ; real_T
Constant_Value_dsqxhplhg3 ; real_T eee_Value ; real_T eee_Value_pohmtfwesc ;
real_T eee_Value_jlbhkxjaia ; real_T Constant_Value_gsv0vdx1vo ; real_T
Constant_Value_gdp532zjna ; real_T Constant_Value_otf0qt4owd ; real_T
Constant_Value_gwvmohj4ou ; imgabiow3g mpxykrjyje ; imgabiow3g bbl254ocw35 ;
} ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X
rtX ; extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern P rtP ; extern
mxArray * mr_IBC_close_loop_GetDWork ( ) ; extern void
mr_IBC_close_loop_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_IBC_close_loop_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * IBC_close_loop_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
