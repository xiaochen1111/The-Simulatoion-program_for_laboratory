#include "IBC_close_loop.h"
#include "IBC_close_loop_private.h"
P rtP = { 0.5 , 10000.0 , 186020.6134968 , 500.0 , 0.0 , 0.0 , 0.01 , 140.0 ,
12.0 , { 0.0 , 1000.0 , 0.0 } , { 0.0 , 1000.0 , 0.0 } , { 0.0 , 1000.0 , 0.0
} , { 0.0 , 1000.0 , 0.0 } , 0.0 , { 0.99994318343228894 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.23076923076923084 , 0.0 , 0.0 , 0.0 , 0.0 , 0.23076923076923084 , 0.0
, 0.0 , 0.0 , 0.0 , 0.23076923076923084 } , { 0.0 , 3.0769230769230768E+7 ,
0.0 , 0.0 , 0.0 , 0.0 , 3.0769230769230768E+7 , 0.0 , 0.0 , 0.0 , 0.0 ,
3.0769230769230768E+7 , 4545.3254168915655 , 3.0769230769230768E+7 , 0.0 ,
0.0 , 4545.3254168915655 , 0.0 , 3.0769230769230768E+7 , 0.0 ,
4545.3254168915655 , 0.0 , 0.0 , 3.0769230769230768E+7 , 0.0 , -
3.0769230769230768E+7 , 0.0 , 0.0 , 0.0 , 0.0 , - 3.0769230769230768E+7 , 0.0
, 0.0 , 0.0 , 0.0 , - 3.0769230769230768E+7 , 0.0 , 307.69230769230774 ,
307.69230769230774 , 307.69230769230774 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , { 0.0 , 0.0 , 0.0 , -
2.4999289792903612E-8 , - 2.4999289792903612E-8 , - 2.4999289792903612E-8 ,
0.0 , 0.0 , 0.0 , 2.4999289792903612E-8 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0015384615384615385 , 0.0 , 0.0 , 0.0015384615384615385 , 0.0 , 0.0 ,
- 0.0015384615384615385 , 0.0 , 0.0 , 0.0 , 1.5384615384615385E-8 , 0.0 , 0.0
, 1.5384615384615385E-8 , 0.0 , 0.0 , 1.5384615384615385E-8 , 0.0 ,
0.0015384615384615385 , 0.0 , 0.0 , 0.0015384615384615385 , 0.0 , 0.0 , -
0.0015384615384615385 , 0.0 , 0.0 , 0.0 , 1.5384615384615385E-8 , 0.0 , 0.0 ,
1.5384615384615385E-8 , 0.0 , 1.5384615384615385E-8 , 0.0 , 0.0 ,
0.0015384615384615385 , 0.0 , 0.0 , 0.0015384615384615385 , 0.0 , 0.0 , -
0.0015384615384615385 , 0.0 , 0.0 , 0.0 , 1.5384615384615385E-8 , 0.0 , 0.0 ,
1.5384615384615385E-8 , 1.5384615384615385E-8 } , { - 61538.461538461546 ,
0.0 , 0.0 , - 61538.461538461546 , 0.0 , 0.0 , 61538.461538461546 , 0.0 , 0.0
, 0.0 , 0.38461538461538458 , 0.0 , 0.0 , 0.38461538461538458 , 0.0 , 0.0 ,
0.38461538461538458 , 0.0 , - 61538.461538461546 , 0.0 , 0.0 , -
61538.461538461546 , 0.0 , 0.0 , 61538.461538461546 , 0.0 , 0.0 , 0.0 ,
0.38461538461538458 , 0.0 , 0.0 , 0.38461538461538458 , 0.0 ,
0.38461538461538458 , 0.0 , 0.0 , - 61538.461538461546 , 0.0 , 0.0 , -
61538.461538461546 , 0.0 , 0.0 , 61538.461538461546 , 0.0 , 0.0 , 0.0 ,
0.38461538461538458 , 0.0 , 0.0 , 0.38461538461538458 , 0.38461538461538458 ,
- 61538.461538461546 , 0.0 , 0.0 , - 61538.461595278117 , -
5.6816567711144567E-5 , - 5.6816567711144567E-5 , 61538.461538461546 , 0.0 ,
0.0 , 5.6816567711144567E-5 , - 0.61538461538461542 , 0.0 , 0.0 ,
0.38461538461538458 , 0.0 , 0.0 , 0.38461538461538458 , 0.0 , -
61538.461538461546 , 0.0 , - 5.6816567711144567E-5 , - 61538.461595278117 , -
5.6816567711144567E-5 , 0.0 , 61538.461538461546 , 0.0 ,
5.6816567711144567E-5 , 0.0 , - 0.61538461538461542 , 0.0 , 0.0 ,
0.38461538461538458 , 0.0 , 0.38461538461538458 , 0.0 , 0.0 , -
61538.461538461546 , - 5.6816567711144567E-5 , - 5.6816567711144567E-5 , -
61538.461595278117 , 0.0 , 0.0 , 61538.461538461546 , 5.6816567711144567E-5 ,
0.0 , 0.0 , - 0.61538461538461542 , 0.0 , 0.0 , 0.38461538461538458 ,
0.38461538461538458 , 61538.461538461546 , 0.0 , 0.0 , 61538.461538461546 ,
0.0 , 0.0 , - 61538.461538461546 , 0.0 , 0.0 , 0.0 , - 0.38461538461538458 ,
0.0 , 0.0 , - 0.38461538461538458 , 0.0 , 0.0 , - 0.38461538461538458 , 0.0 ,
61538.461538461546 , 0.0 , 0.0 , 61538.461538461546 , 0.0 , 0.0 , -
61538.461538461546 , 0.0 , 0.0 , 0.0 , - 0.38461538461538458 , 0.0 , 0.0 , -
0.38461538461538458 , 0.0 , - 0.38461538461538458 , 0.0 , 0.0 ,
61538.461538461546 , 0.0 , 0.0 , 61538.461538461546 , 0.0 , 0.0 , -
61538.461538461546 , 0.0 , 0.0 , 0.0 , - 0.38461538461538458 , 0.0 , 0.0 , -
0.38461538461538458 , - 0.38461538461538458 , 0.38461538461538458 ,
0.38461538461538458 , 0.38461538461538458 , 0.38461538461538458 ,
0.38461538461538458 , 0.38461538461538458 , - 0.38461538461538458 , -
0.38461538461538458 , - 0.38461538461538458 , 0.0 , 3.8461538461538468E-6 ,
3.8461538461538468E-6 , 3.8461538461538468E-6 , 3.8461538461538468E-6 ,
3.8461538461538468E-6 , 3.8461538461538468E-6 , 1.153846153846154E-5 , 0.0 ,
0.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
- 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , {
0.0 , 4800.0000000000027 , 4800.0000000000027 , 4800.0000000000027 } , 1.0 ,
{ 0.0 , 5.0E-5 , 0.0001 } , 0.0 , 0.0 , 0.00038 , 1.0 , 5.0 , 0.0 , 1.0 ,
900.0 , 100.0 , 1.0 , 1.0 , 0.008 , 1.0 , 0.0 , 0.5 , 1.0 , 1.0 , 1.0 , { 0.0
, 4.9999999999999996E-5 , 0.0001 } , { 0.0 , 4.9999999999999996E-5 ,
9.9999999999999991E-5 } , 3.3333333333333337E-6 , 0.0 , { 0.0 , 5.0E-6 ,
1.0E-5 } , 0.01 , 0.5 , 31415.926535897932 , 0.0 , { - 416.66666666666663 , -
1.5624999999999998E+6 } , { - 7222.2222222222226 , 2.7083333333333332E+7 } ,
{ 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , 19.0 , 0.0 , 0.8 ,
0.8 , 0.8 , 0.0001 , 0.0001 , 0.0001 , 1.0E-5 , { 0.0 } , { 0.0 } } ;
