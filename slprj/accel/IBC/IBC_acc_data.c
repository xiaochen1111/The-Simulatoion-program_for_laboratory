#include "IBC_acc.h"
#include "IBC_acc_private.h"
const ConstB_IBC_T IBC_rtInvariant = { 0.0 } ; P_IBC_T IBC_rtDefaultP = { 0.0
, { 4.0 , 4.0 } , { 0.99988637009260839 , 0.0 , 0.0 , 0.0 , 0.0 , -
0.35135135135135126 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.35135135135135126 , 0.0 ,
0.0 , 0.0 , 0.0 , - 0.35135135135135126 } , { 4.0 , 13.0 } , { 0.0 ,
5.4054054054054052E+7 , 0.0 , 0.0 , 0.0 , 0.0 , 5.4054054054054052E+7 , 0.0 ,
0.0 , 0.0 , 0.0 , 5.4054054054054052E+7 , 45451.96295665019 ,
5.4054054054054052E+7 , 0.0 , 0.0 , 45451.96295665019 , 0.0 ,
5.4054054054054052E+7 , 0.0 , 45451.96295665019 , 0.0 , 0.0 ,
5.4054054054054052E+7 , 0.0 , - 5.4054054054054052E+7 , 0.0 , 0.0 , 0.0 , 0.0
, - 5.4054054054054052E+7 , 0.0 , 0.0 , 0.0 , 0.0 , - 5.4054054054054052E+7 ,
0.0 , 540.54054054054063 , 540.54054054054063 , 540.54054054054063 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , { 17.0 ,
4.0 } , { 0.0 , 0.0 , 0.0 , - 2.4998579626157604E-8 , - 2.4998579626157604E-8
, - 2.4998579626157604E-8 , 0.0 , 0.0 , 0.0 , 2.4998579626157604E-8 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.00081081081081081077 , 0.0 , 0.0 ,
0.00081081081081081077 , 0.0 , 0.0 , - 0.00081081081081081077 , 0.0 , 0.0 ,
0.0 , 8.108108108108109E-9 , 0.0 , 0.0 , 8.108108108108109E-9 , 0.0 , 0.0 ,
8.108108108108109E-9 , 0.0 , 0.00081081081081081077 , 0.0 , 0.0 ,
0.00081081081081081077 , 0.0 , 0.0 , - 0.00081081081081081077 , 0.0 , 0.0 ,
0.0 , 8.108108108108109E-9 , 0.0 , 0.0 , 8.108108108108109E-9 , 0.0 ,
8.108108108108109E-9 , 0.0 , 0.0 , 0.00081081081081081077 , 0.0 , 0.0 ,
0.00081081081081081077 , 0.0 , 0.0 , - 0.00081081081081081077 , 0.0 , 0.0 ,
0.0 , 8.108108108108109E-9 , 0.0 , 0.0 , 8.108108108108109E-9 ,
8.108108108108109E-9 } , { 17.0 , 13.0 } , { - 32432.432432432441 , 0.0 , 0.0
, - 32432.432432432441 , 0.0 , 0.0 , 32432.432432432441 , 0.0 , 0.0 , 0.0 ,
0.67567567567567566 , 0.0 , 0.0 , 0.67567567567567566 , 0.0 , 0.0 ,
0.67567567567567566 , 0.0 , - 32432.432432432441 , 0.0 , 0.0 , -
32432.432432432441 , 0.0 , 0.0 , 32432.432432432441 , 0.0 , 0.0 , 0.0 ,
0.67567567567567566 , 0.0 , 0.0 , 0.67567567567567566 , 0.0 ,
0.67567567567567566 , 0.0 , 0.0 , - 32432.432432432441 , 0.0 , 0.0 , -
32432.432432432441 , 0.0 , 0.0 , 32432.432432432441 , 0.0 , 0.0 , 0.0 ,
0.67567567567567566 , 0.0 , 0.0 , 0.67567567567567566 , 0.67567567567567566 ,
- 32432.432432432441 , 0.0 , 0.0 , - 32432.433000581979 , -
0.00056814953695812737 , - 0.00056814953695812737 , 32432.432432432441 , 0.0
, 0.0 , 0.00056814953695812737 , - 0.32432432432432434 , 0.0 , 0.0 ,
0.67567567567567566 , 0.0 , 0.0 , 0.67567567567567566 , 0.0 , -
32432.432432432441 , 0.0 , - 0.00056814953695812737 , - 32432.433000581979 ,
- 0.00056814953695812737 , 0.0 , 32432.432432432441 , 0.0 ,
0.00056814953695812737 , 0.0 , - 0.32432432432432434 , 0.0 , 0.0 ,
0.67567567567567566 , 0.0 , 0.67567567567567566 , 0.0 , 0.0 , -
32432.432432432441 , - 0.00056814953695812737 , - 0.00056814953695812737 , -
32432.433000581979 , 0.0 , 0.0 , 32432.432432432441 , 0.00056814953695812737
, 0.0 , 0.0 , - 0.32432432432432434 , 0.0 , 0.0 , 0.67567567567567566 ,
0.67567567567567566 , 32432.432432432441 , 0.0 , 0.0 , 32432.432432432441 ,
0.0 , 0.0 , - 32432.432432432441 , 0.0 , 0.0 , 0.0 , - 0.67567567567567566 ,
0.0 , 0.0 , - 0.67567567567567566 , 0.0 , 0.0 , - 0.67567567567567566 , 0.0 ,
32432.432432432441 , 0.0 , 0.0 , 32432.432432432441 , 0.0 , 0.0 , -
32432.432432432441 , 0.0 , 0.0 , 0.0 , - 0.67567567567567566 , 0.0 , 0.0 , -
0.67567567567567566 , 0.0 , - 0.67567567567567566 , 0.0 , 0.0 ,
32432.432432432441 , 0.0 , 0.0 , 32432.432432432441 , 0.0 , 0.0 , -
32432.432432432441 , 0.0 , 0.0 , 0.0 , - 0.67567567567567566 , 0.0 , 0.0 , -
0.67567567567567566 , - 0.67567567567567566 , 0.67567567567567566 ,
0.67567567567567566 , 0.67567567567567566 , 0.67567567567567566 ,
0.67567567567567566 , 0.67567567567567566 , - 0.67567567567567566 , -
0.67567567567567566 , - 0.67567567567567566 , 0.0 , 6.7567567567567575E-6 ,
6.7567567567567575E-6 , 6.7567567567567575E-6 , 6.7567567567567575E-6 ,
6.7567567567567575E-6 , 6.7567567567567575E-6 , 2.0270270270270273E-5 , 0.0 ,
0.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
- 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , {
4.0 , 1.0 } , { 0.0 , 4800.0000000000018 , 4800.0000000000018 ,
4800.0000000000018 } , 1.0 , { 0.0 , 1000.0 , 0.0 } , { 0.0 , 5.0E-5 , 0.0001
} , 3.3333333333333335E-5 , 0.0 , 6.666666666666667E-5 , 0.0 , 0.00038 , 1.0
, 0.001 , 0.0 , 5.0 , 0.0 , 1.0 , 100.845772666184 , 0.0 , 900.0 , 100.0 ,
1.0 , 1.0 , 0.025 , 1.0 , 0.0 , 0.5 , 1.0 , 1.0 , 1.0 , 483600.3763248 ,
1000.0 , { 0.0 , 1000.0 , 0.0 } , { 0.0 , 4.9999999999999996E-5 , 0.0001 } ,
{ 0.0 , 1000.0 , 0.0 } , { 0.0 , 4.9999999999999996E-5 ,
9.9999999999999991E-5 } , 3.3333333333333337E-6 , 0.0 , { 0.0 , 1000.0 , 0.0
} , { 0.0 , 5.0E-6 , 1.0E-5 } , 0.01 , 0.5 , 31415.926535897932 , 0.0 , 2.0 ,
{ - 416.66666666666663 , - 1.5624999999999998E+6 } , { - 7222.2222222222226 ,
2.7083333333333332E+7 } , { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 } , 19.0 , 0.0 , 12.0 , 0.8 , 0.8 , 0.8 , 0.0001 , 0.0001 , 0.0001 ,
1.0E-5 , { 0.0 } , { 0.0 } } ;