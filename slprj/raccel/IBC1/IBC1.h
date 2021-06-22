#ifndef RTW_HEADER_IBC1_h_
#define RTW_HEADER_IBC1_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef IBC1_COMMON_INCLUDES_
#define IBC1_COMMON_INCLUDES_
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
#include "IBC1_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME IBC1
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
typedef struct { real_T gqyueovf0x ; } jfroyqp1l2 ; typedef struct { int8_T
ikjnmtqwv0 ; } lanvlpt135 ; typedef struct { real_T ml5elt412n ; } clee2sapju
; typedef struct { ZCSigState dp1i3lb5ph ; } au24en4dzs ; typedef struct {
real_T odazhmwpn0 [ 17 ] ; real_T oukfsqx50f [ 9 ] ; real_T avcatdltyc ;
real_T otoroldxt1 ; real_T lhmqma0bj3 ; real_T pkmdbed0es ; real_T cl2qzwvkbj
[ 3 ] ; real_T c0t5jmfaeg ; real_T cwpjvxmr0i ; real_T l3f0j0025k ; real_T
nkqprozo1a ; real_T cruaxvmogz ; real_T h1gogwi5ku ; real_T bdou3bnea4 ;
real_T bg2jknexx5 ; real_T dpjtgbbiz2 ; real_T aadob0orwm ; real_T gqvdelah3i
; real_T hxoya3o5lr ; real_T j2wnh3irqk ; real_T d3eaa0fx0a ; real_T
dzkiqmr43p ; real_T ar5fz2uoyk ; real_T myup1cfdlk ; real_T defpijlxd3 ;
real_T mczadyhg2m ; real_T dzvsubkdwz ; real_T l1j1ioj0sv ; real_T lsx1razqc1
; real_T ohzinl1asd ; real_T huhtwrsccb ; real_T hvvgc3xdmn ; boolean_T
bn0ratt3ev ; boolean_T brs0dgmc1a ; boolean_T efbnt10xks ; jfroyqp1l2
adxwqzxxlf ; jfroyqp1l2 hhoyo4a5hdp ; } B ; typedef struct { real_T
kbsai0di0v [ 4 ] ; struct { real_T modelTStart ; } ih1wy1g0a5 ; struct {
real_T modelTStart ; } o5rvrjh2wy ; struct { real_T modelTStart ; }
dcsgtlggye ; struct { void * AS ; void * BS ; void * CS ; void * DS ; void *
DX_COL ; void * BD_COL ; void * TMP1 ; void * TMP2 ; void * XTMP ; void *
SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ;
void * USWLAST ; void * XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ;
void * IDX_SW_CHG ; void * Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW
; void * SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } gr1muksbyf ; struct {
void * LoggedData ; } py4fwtjufu ; struct { void * TUbufferPtrs [ 2 ] ; }
layaov5mlt ; struct { void * TUbufferPtrs [ 2 ] ; } e5i1astk5k ; struct {
void * LoggedData [ 2 ] ; } pidpl03h2e ; struct { void * LoggedData [ 3 ] ; }
fwdaf2hwel ; struct { void * LoggedData [ 4 ] ; } lg0040upns ; struct { void
* LoggedData [ 2 ] ; } ijmd3pa0bm ; struct { void * LoggedData [ 2 ] ; }
ntvjnhct52 ; struct { void * LoggedData [ 3 ] ; } k4nfq4y0nz ; struct { void
* LoggedData ; } n10mme0d0t ; struct { void * LoggedData [ 3 ] ; } d1ypcdq1l4
; struct { void * LoggedData [ 4 ] ; } knbfx43f4o ; struct { void *
TUbufferPtrs [ 2 ] ; } nmpmd1jh5e ; struct { void * LoggedData [ 2 ] ; }
ezgsnm2ktm ; int_T mld3hblakv [ 11 ] ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; } coigdooovo ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } nen2ftgc0l ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } lkazb3z1og ; int_T
dmdu1pxmxg ; int_T bgqwuyroks ; int_T mrajto30cb ; boolean_T hzzdjgpnti ;
boolean_T ovfa2w42nr ; boolean_T humgsssfcu ; boolean_T apgwaguobm ;
lanvlpt135 adxwqzxxlf ; lanvlpt135 hhoyo4a5hdp ; } DW ; typedef struct {
real_T hbkyjaqpk0 ; real_T k1kxb5arpk ; real_T ma50ol3eb4 [ 2 ] ; } X ;
typedef struct { real_T hbkyjaqpk0 ; real_T k1kxb5arpk ; real_T ma50ol3eb4 [
2 ] ; } XDot ; typedef struct { boolean_T hbkyjaqpk0 ; boolean_T k1kxb5arpk ;
boolean_T ma50ol3eb4 [ 2 ] ; } XDis ; typedef struct { real_T hbkyjaqpk0 ;
real_T k1kxb5arpk ; real_T ma50ol3eb4 [ 2 ] ; } CStateAbsTol ; typedef struct
{ real_T hbkyjaqpk0 ; real_T k1kxb5arpk ; real_T ma50ol3eb4 [ 2 ] ; } CXPtMin
; typedef struct { real_T hbkyjaqpk0 ; real_T k1kxb5arpk ; real_T ma50ol3eb4
[ 2 ] ; } CXPtMax ; typedef struct { real_T cxvmlo54tq ; real_T i1qguydf5f ;
real_T hwifdzglhr ; real_T fqe3m5uk4o ; real_T ccibpnss55 ; real_T ouj3m1afdg
; real_T iylnquiyuq ; real_T gc0ar4rht3 ; real_T hm3wlvfwem ; clee2sapju
adxwqzxxlf ; clee2sapju hhoyo4a5hdp ; } ZCV ; typedef struct { au24en4dzs
adxwqzxxlf ; au24en4dzs hhoyo4a5hdp ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct ci4qpemhrm_ { real_T
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
donotdeletethisgain_Gain_dojjjvjkoc ; real_T
donotdeletethisgain_Gain_cswjbtqcc2 ; real_T
donotdeletethisgain_Gain_nwj215l5x1 ; real_T
donotdeletethisgain_Gain_fy4vzgl50q ; real_T Step_Time ; real_T Step_Y0 ;
real_T Step_YFinal ; real_T Switch_Threshold ; real_T
donotdeletethisgain_Gain_cthxcecbau ; real_T
donotdeletethisgain_Gain_ctalfroa4m ; real_T
donotdeletethisgain_Gain_o54pdurymu ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T LookUpTable1_bp01Data_p4fekf0sau [ 3 ] ; real_T
LookUpTable1_bp01Data_eancggqfkt [ 3 ] ; real_T TransportDelay_Delay ; real_T
TransportDelay_InitOutput ; real_T LookUpTable1_bp01Data_fwaln5kcoo [ 3 ] ;
real_T SineWave1_Amp ; real_T SineWave1_Bias ; real_T SineWave1_Freq ; real_T
SineWave1_Phase ; real_T TransferFcn1_A [ 2 ] ; real_T TransferFcn1_C [ 2 ] ;
real_T SwitchCurrents_Value [ 9 ] ; real_T Constant_Value_oa4sl44jdq ; real_T
Constant1_Value ; real_T Constant_Value_dsqxhplhg3 ; real_T eee_Value ;
real_T eee_Value_pohmtfwesc ; real_T eee_Value_jlbhkxjaia ; real_T
Constant_Value_gsv0vdx1vo ; real_T Constant_Value_gdp532zjna ; real_T
Constant_Value_otf0qt4owd ; real_T Constant_Value_gwvmohj4ou ; ci4qpemhrm
adxwqzxxlf ; ci4qpemhrm hhoyo4a5hdp ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray * mr_IBC1_GetDWork (
) ; extern void mr_IBC1_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_IBC1_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * IBC1_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
