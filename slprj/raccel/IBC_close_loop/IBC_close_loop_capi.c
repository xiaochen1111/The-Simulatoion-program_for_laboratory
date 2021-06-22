#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "IBC_close_loop_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "IBC_close_loop.h"
#include "IBC_close_loop_capi.h"
#include "IBC_close_loop_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"IBC_close_loop/Sample and Hold" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 2 , TARGET_STRING ( "IBC_close_loop/Sample and Hold1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"IBC_close_loop/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 3 ,
0 , TARGET_STRING ( "IBC_close_loop/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 4 , 0 , TARGET_STRING ( "IBC_close_loop/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"IBC_close_loop/Saturation1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 6 , 0 , TARGET_STRING ( "IBC_close_loop/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING ( "IBC_close_loop/IBC/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 8 , 1 , TARGET_STRING (
"IBC_close_loop/Sample and Hold/In" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 9 , 2 , TARGET_STRING ( "IBC_close_loop/Sample and Hold1/In" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Relational Operator" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 2 } , { 11 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Relational Operator1" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 2 } , { 12 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Relational Operator2" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 2 } , { 13 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Transport Delay" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Transport Delay1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Transport Delay2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement1/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 17 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement2/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 18 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement3/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 19 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement4/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 20 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement6/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 21 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement7/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 22 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement8/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 23 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 24 , 0 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 3 } , { 25 , 0 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( ""
) , 1 , 0 , 3 , 0 , 3 } , { 26 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence/Output" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence1/Look-Up Table1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence2/Look-Up Table1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence4/Output" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"IBC_close_loop/PID Controller/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"IBC_close_loop/PID Controller/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
"IBC_close_loop/PID Controller/Sum/Sum_PI/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"IBC_close_loop/PID Controller1/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 34 , 0 , TARGET_STRING (
"IBC_close_loop/PID Controller1/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
 "IBC_close_loop/PID Controller1/Parallel P Gain/Internal Parameters/Proportional Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 36 , 0 , TARGET_STRING (
"IBC_close_loop/PID Controller1/Sum/Sum_PI/Sum" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 37 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/Mosfet1/Ideal Switch/Model/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 38 , 0 , TARGET_STRING (
"IBC_close_loop/IBC/Mosfet6/Ideal Switch/Model/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 39 , TARGET_STRING ( "IBC_close_loop/IBC" ) ,
TARGET_STRING ( "Vin" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"IBC_close_loop/PID Controller" ) , TARGET_STRING ( "P" ) , 0 , 0 , 0 } , {
41 , TARGET_STRING ( "IBC_close_loop/PID Controller" ) , TARGET_STRING ( "I"
) , 0 , 0 , 0 } , { 42 , TARGET_STRING ( "IBC_close_loop/PID Controller" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 43 ,
TARGET_STRING ( "IBC_close_loop/PID Controller1" ) , TARGET_STRING ( "P" ) ,
0 , 0 , 0 } , { 44 , TARGET_STRING ( "IBC_close_loop/PID Controller1" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"IBC_close_loop/PID Controller1" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"IBC_close_loop/命令信号生产" ) , TARGET_STRING ( "Fs" ) , 0 , 0 , 0 } , { 47
, TARGET_STRING ( "IBC_close_loop/Constant" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 48 , TARGET_STRING ( "IBC_close_loop/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING ( "IBC_close_loop/Saturation" )
, TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"IBC_close_loop/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 51 , TARGET_STRING ( "IBC_close_loop/Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING (
"IBC_close_loop/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 53 , TARGET_STRING ( "IBC_close_loop/Sine Wave1" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"IBC_close_loop/Sine Wave1" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 55
, TARGET_STRING ( "IBC_close_loop/Sine Wave1" ) , TARGET_STRING ( "Frequency"
) , 0 , 0 , 0 } , { 56 , TARGET_STRING ( "IBC_close_loop/Sine Wave1" ) ,
TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"IBC_close_loop/Transfer Fcn1" ) , TARGET_STRING ( "A" ) , 0 , 4 , 0 } , { 58
, TARGET_STRING ( "IBC_close_loop/Transfer Fcn1" ) , TARGET_STRING ( "C" ) ,
0 , 5 , 0 } , { 59 , TARGET_STRING ( "IBC_close_loop/IBC/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
"IBC_close_loop/IBC/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 61 ,
TARGET_STRING ( "IBC_close_loop/IBC/Step" ) , TARGET_STRING ( "Before" ) , 0
, 0 , 0 } , { 62 , TARGET_STRING ( "IBC_close_loop/IBC/Step" ) ,
TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"IBC_close_loop/IBC/Switch" ) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } ,
{ 64 , TARGET_STRING ( "IBC_close_loop/Sample and Hold/ " ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"IBC_close_loop/Sample and Hold1/ " ) , TARGET_STRING ( "InitialOutput" ) , 0
, 0 , 0 } , { 66 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence" ) , TARGET_STRING (
"rep_seq_y" ) , 0 , 6 , 0 } , { 67 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence1" ) , TARGET_STRING (
"rep_seq_y" ) , 0 , 6 , 0 } , { 68 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence2" ) , TARGET_STRING (
"rep_seq_y" ) , 0 , 6 , 0 } , { 69 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence4" ) , TARGET_STRING (
"rep_seq_y" ) , 0 , 6 , 0 } , { 70 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Transport Delay" ) , TARGET_STRING ( "DelayTime"
) , 0 , 0 , 0 } , { 71 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Transport Delay1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Transport Delay2" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement1/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement2/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement3/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement4/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement6/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 79 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement7/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING (
"IBC_close_loop/IBC/ Measurement8/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING (
"IBC_close_loop/IBC/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"AS_param" ) , 0 , 7 , 0 } , { 83 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"BS_param" ) , 0 , 8 , 0 } , { 84 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"CS_param" ) , 0 , 9 , 0 } , { 85 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"DS_param" ) , 0 , 10 , 0 } , { 86 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"X0_param" ) , 0 , 11 , 0 } , { 87 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Compare To Zero/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence/Look-Up Table1" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 6 , 0 } , { 90 ,
TARGET_STRING ( "IBC_close_loop/命令信号生产/Repeating Sequence1/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence1/Look-Up Table1" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 6 , 0 } , { 92 ,
TARGET_STRING ( "IBC_close_loop/命令信号生产/Repeating Sequence2/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 93 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence2/Look-Up Table1" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 6 , 0 } , { 94 ,
TARGET_STRING ( "IBC_close_loop/命令信号生产/Repeating Sequence4/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"IBC_close_loop/命令信号生产/Repeating Sequence4/Look-Up Table1" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 6 , 0 } , { 96 ,
TARGET_STRING ( "IBC_close_loop/IBC/Diode1/Model/eee" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 97 , TARGET_STRING (
"IBC_close_loop/IBC/Diode2/Model/eee" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 98 , TARGET_STRING ( "IBC_close_loop/IBC/Diode6/Model/eee" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING (
"IBC_close_loop/powergui/EquivalentModel1/Sources/SwitchCurrents" ) ,
TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 100 , TARGET_STRING (
"alp" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . bbl254ocw35 . p5wwiu03ls , & rtB
. mpxykrjyje . p5wwiu03ls , & rtB . dvjrtmyu4l [ 0 ] , & rtB . gjh4vpxeef , &
rtB . iyxr5frzyq , & rtB . f5grkow3lv , & rtB . jj5htd1qpd , & rtB .
mwfeqafa0o , & rtB . bbl254ocw35 . p5wwiu03ls , & rtB . mpxykrjyje .
p5wwiu03ls , & rtB . dphockrl25 , & rtB . cibd5iyhfd , & rtB . pl55r2bbaf , &
rtB . i1ollxafrx , & rtB . njyqw3gypd , & rtB . krjlzhi2hw , & rtB .
hvbnfudyrr , & rtB . mcgxsf0lqd , & rtB . ekt10g5oul , & rtB . eekajp3dsw , &
rtB . dpijkcpfpb , & rtB . eh0txmg2mg , & rtB . amqaipqoht , & rtB .
idzaeea1lj , & rtB . agn4x3drjs [ 0 ] , & rtB . irxwz2klfa [ 0 ] , & rtB .
jirgucywty , & rtB . jmnr504r1m , & rtB . nhlx1d2f35 , & rtB . hofz3ldwny , &
rtB . g3iapqckrv , & rtB . iqodxjvqjm , & rtB . pkdqnlyvhd , & rtB .
kagelnoork , & rtB . cy0apjvkno , & rtB . g4ttm0jd3j , & rtB . eitgvaqdla , &
rtB . opwmy0qdum , & rtB . hac1mxz2pn , & rtP . IBC_Vin , & rtP .
PIDController_P , & rtP . PIDController_I , & rtP .
PIDController_InitialConditionForIntegrator , & rtP . PIDController1_P , &
rtP . PIDController1_I , & rtP . PIDController1_InitialConditionForIntegrator
, & rtP . _Fs , & rtP . Constant_Value_oa4sl44jdq , & rtP . Gain_Gain , & rtP
. Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP . SineWave1_Amp ,
& rtP . SineWave1_Bias , & rtP . SineWave1_Freq , & rtP . SineWave1_Phase , &
rtP . TransferFcn1_A [ 0 ] , & rtP . TransferFcn1_C [ 0 ] , & rtP .
Constant_Value_dsqxhplhg3 , & rtP . Step_Time , & rtP . Step_Y0 , & rtP .
Step_YFinal , & rtP . Switch_Threshold , & rtP . bbl254ocw35 . _Y0 , & rtP .
mpxykrjyje . _Y0 , & rtP . RepeatingSequence_rep_seq_y [ 0 ] , & rtP .
RepeatingSequence1_rep_seq_y [ 0 ] , & rtP . RepeatingSequence2_rep_seq_y [ 0
] , & rtP . RepeatingSequence4_rep_seq_y [ 0 ] , & rtP . TransportDelay_Delay
, & rtP . TransportDelay_InitOutput , & rtP . TransportDelay1_InitOutput , &
rtP . TransportDelay2_InitOutput , & rtP .
donotdeletethisgain_Gain_cthxcecbau , & rtP .
donotdeletethisgain_Gain_ctalfroa4m , & rtP .
donotdeletethisgain_Gain_o54pdurymu , & rtP .
donotdeletethisgain_Gain_dojjjvjkoc , & rtP .
donotdeletethisgain_Gain_cswjbtqcc2 , & rtP .
donotdeletethisgain_Gain_nwj215l5x1 , & rtP .
donotdeletethisgain_Gain_fy4vzgl50q , & rtP . donotdeletethisgain_Gain , &
rtP . StateSpace_AS_param [ 0 ] , & rtP . StateSpace_BS_param [ 0 ] , & rtP .
StateSpace_CS_param [ 0 ] , & rtP . StateSpace_DS_param [ 0 ] , & rtP .
StateSpace_X0_param [ 0 ] , & rtP . Constant_Value , & rtP .
Constant_Value_gsv0vdx1vo , & rtP . LookUpTable1_bp01Data [ 0 ] , & rtP .
Constant_Value_gdp532zjna , & rtP . LookUpTable1_bp01Data_p4fekf0sau [ 0 ] ,
& rtP . Constant_Value_otf0qt4owd , & rtP . LookUpTable1_bp01Data_eancggqfkt
[ 0 ] , & rtP . Constant_Value_gwvmohj4ou , & rtP .
LookUpTable1_bp01Data_fwaln5kcoo [ 0 ] , & rtP . eee_Value , & rtP .
eee_Value_pohmtfwesc , & rtP . eee_Value_jlbhkxjaia , & rtP .
SwitchCurrents_Value [ 0 ] , & rtP . alp , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 18 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 20 , 2 , 0 } , { rtwCAPI_VECTOR , 22 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 , 3 , 1 , 17 , 1
, 9 , 1 , 2 , 1 , 1 , 2 , 1 , 3 , 4 , 4 , 4 , 13 , 17 , 4 , 17 , 13 , 4 , 1 }
; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 , 2.5E-8 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , - 1 , 0 } , { ( const void *
) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
0 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 2 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 2 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 39 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 61 ,
rtModelParameters , 1 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 929389569U , 2019389511U , 1737148957U , 3003249467U } , ( NULL ) , 0 , 0
, rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo *
IBC_close_loop_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void IBC_close_loop_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void IBC_close_loop_host_InitializeDataMapInfo (
IBC_close_loop_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
