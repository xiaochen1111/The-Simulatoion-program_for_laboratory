#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_IknB0lRFE3XEak14ctm4IE" , 14 ,
3376 } } ; static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof (
real32_T ) , sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) ,
sizeof ( uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof (
boolean_T ) , sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( void * ) ,
sizeof ( action_T ) , 2 * sizeof ( uint32_T ) , sizeof (
struct_IknB0lRFE3XEak14ctm4IE ) } ; static const char_T * rtDataTypeNames [ ]
= { "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "struct_IknB0lRFE3XEak14ctm4IE" } ;
static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
odazhmwpn0 [ 0 ] ) , 0 , 0 , 58 } , { ( char_T * ) ( & rtB . bn0ratt3ev ) , 8
, 0 , 3 } , { ( char_T * ) ( & rtB . adxwqzxxlf . gqyueovf0x ) , 0 , 0 , 1 }
, { ( char_T * ) ( & rtB . hhoyo4a5hdp . gqyueovf0x ) , 0 , 0 , 1 } , { (
char_T * ) ( & rtDW . kbsai0di0v [ 0 ] ) , 0 , 0 , 7 } , { ( char_T * ) ( &
rtDW . gr1muksbyf . AS ) , 11 , 0 , 34 } , { ( char_T * ) ( & rtDW .
mld3hblakv [ 0 ] ) , 10 , 0 , 17 } , { ( char_T * ) ( & rtDW . hzzdjgpnti ) ,
8 , 0 , 4 } , { ( char_T * ) ( & rtDW . adxwqzxxlf . ikjnmtqwv0 ) , 2 , 0 , 1
} , { ( char_T * ) ( & rtDW . hhoyo4a5hdp . ikjnmtqwv0 ) , 2 , 0 , 1 } } ;
static DataTypeTransitionTable rtBTransTable = { 10U , rtBTransitions } ;
static DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . alp
) , 0 , 0 , 443 } , { ( char_T * ) ( & rtP . adxwqzxxlf . _Y0 ) , 0 , 0 , 1 }
, { ( char_T * ) ( & rtP . hhoyo4a5hdp . _Y0 ) , 0 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 3U , rtPTransitions } ;
