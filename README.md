# Multiple_Equations_Solver
First Year Electrical Project.

## Descrption
This program solves System of linear equations. The programs reads first an integer n which is the number of equations. Then the equations themselves are inserted, then the operations.

## Operations Supported by the Program
1.num_vars -> Print the number of variables.

2.equation i -> Print equation number i (i is integer).

3.column x2 -> Print the column of coefficients of variable (x2).

4.add 1 3 -> Add equation 1 and equation 3 and print the result equation.

5.subtract 1 3 -> Subtract equation 1 minus equation 3 and print the result equation.

6.substitute x2 1 3 -> Substitutes the variable x2 in equation 1 by its equation in equation 3 and print the result equation.

7.D -> Cramer’s Coefficient matrix.

8.D x1 -> Cramer’s Coefficient matrix of variable x1.

9.D_value -> Cramer’s coefficient matrix determinant value.

10.solve -> Print the solution of the equations (Only 3x3 equations is supported here).


## Test Cases


#### **Example 1 (num_vars operation)**


7

7.56x+89-4apple-15banana+3.4choc-y=22-9blue

82blue-25+6choc+17apple-5.8x+10banana+5y=4

choc+4apple-9blue+14banana-5y+4x=26

23apple+4.789x+2y-banana+blue=77

4y-5banana-8x+7.65apple+9choc-9blue=7

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12

15green+5yellow=12

*num_vars*

8





#### **Example 2 (equation i operation)**



6

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12

4y-5banana-8x+7.65apple+9choc-9blue=7

23apple+4.789x+2y-banana+blue=77

choc+4apple-9blue+14banana-5y+4x=26

2x+9y-88.4choc+3banana-2apple-20blue=1

82blue-25+6choc+17apple-5.8x+10banana+5y=4

*equation 1*

49.9apple-10banana-99blue-21choc+5x+1y=20.4

*equation 2*

7.65apple-5banana-9blue+9choc-8x+4y=7

*equation 3*

23apple-1banana+1blue+4.789x+2y=77

*equation 4*

4apple+14banana-9blue+1choc+4x-5y=26

*equation 5*

-2apple+3banana-20blue-88.4choc+2x+9y=1

*equation 6*

17apple+10banana+82blue+6choc-5.8x+5y=29





#### **Example 3 (column operation)**



6

7.56x+89-4apple-15banana+3.4choc-y=22-9blue

82blue-25+6choc+17apple-5.8x+10banana+5y=4

choc+4apple-9blue+14banana-5y+4x=26

23apple+4.789x+2y-banana+blue=77

4y-5banana-8x+7.65apple+9choc-9blue=7

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12



*column choc*

3.4

6

1

0

9

-21

*column apple*

-4

17

4

23

7.65

49.9

*column banana*

-15

10

14

-1

-5

-10

*column x*

7.56

-5.8

4

4.789

-8

5

*column y*

-1

5

-5

2

4

1

*column blue*

9

82

-9

1

-9

-99







#### **Example 4 (Add operation)**



6

7.56x+89-4apple-15banana+3.4choc-y=22-9blue

82blue-25+6choc+17apple-5.8x+10banana+5y=4

choc+4apple-9blue+14banana-5y+4x=26

23apple+4.789x+2y-banana+blue=77

4y-5banana-8x+7.65apple+9choc-9blue=7

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12



*add 1 3*

0apple-1banana+0blue+4.4choc+11.56x-6y=-41

*add 2 4*

40apple+9banana+83blue+6choc-1.011x+7y=106

*add 5 6*

57.55apple-15banana-108blue-12choc-3x+5y=27.4






#### **Example 5 (subtract operation)**



6

7.56x+89-4apple-15banana+3.4choc-y=22-9blue

82blue-25+6choc+17apple-5.8x+10banana+5y=4

choc+4apple-9blue+14banana-5y+4x=26

23apple+4.789x+2y-banana+blue=77

4y-5banana-8x+7.65apple+9choc-9blue=7

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12



*subtract 1 3*

-8apple-29banana+18blue+2.4choc+3.56x+4y=-93

*subtract 2 5*

9.35apple+15banana+91blue-3choc+2.2x+1y=22

*subtract 3 6*

-45.9apple+24banana+90blue+22choc-1x-6y=5.6







#### **Example 6 (substitute operation)**





6

7.56x+89-4apple-15banana+3.4choc-y=22-9blue

82blue-25+6choc+17apple-5.8x+10banana+5y=4

choc+4apple-9blue+14banana-5y+4x=26

23apple+4.789x+2y-banana+blue=77

4y-5banana-8x+7.65apple+9choc-9blue=7

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12

*substitute banana 1 3*

0.019047apple-0.042857blue+0.298096choc+0.789714x-0.42381y=-2.60953

*substitute choc 2 3*

1.16667apple+12.3333banana-22.6667blue+4.96667x-5.83333y=21.1667

*substitute x 5 6*

10.9362apple-2.625banana-20.925blue-3.075choc+0.7y=4.955






#### **Example 7 (D operation)**



6

7.56x+89-4apple-15banana+3.4choc-y=22-9blue

82blue-25+6choc+17apple-5.8x+10banana+5y=4

choc+4apple-9blue+14banana-5y+4x=26

23apple+4.789x+2y-banana+blue=77

4y-5banana-8x+7.65apple+9choc-9blue=7

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12



*D*

-4       -15      9         3.4       7.56      -1 

17       10       82       6        -5.8     5

4        14       -9       1        4        -5

23       -1       1        0        4.789    2

7.65     -5       -9       9        -8       4

49.9     -10      -99      -21      5        1





#### **Example 8 (D x2 operation)**




6

7.56x+89-4apple-15banana+3.4choc-y=22-9blue

82blue-25+6choc+17apple-5.8x+10banana+5y=4

choc+4apple-9blue+14banana-5y+4x=26

23apple+4.789x+2y-banana+blue=77

4y-5banana-8x+7.65apple+9choc-9blue=7

44.9apple-10banana-21choc-8.4+5x+y-99blue+5apple=12



*D choc*

-4      -15     9       -67     7.56    -1

17      10      82      29      -5.8    5

4       14      -9      26      4       -5

23      -1      1       77      4.789   2

7.65    -5      -9      7       -8      4

49.9    -10     -99     20.4    5       1

*D apple*

-67      -15      9        3.4      7.56     -1
 
29       10       82       6        -5.8     5

26       14       -9       1        4        -5

77       -1       1        0        4.789    2

7        -5       -9       9        -8       4

20.4     -10      -99      -21      5        1

*D blue*

-4       -15      -67      3.4      7.56     -1 

17       10       29       6        -5.8     5 

4        14       26       1        4        -5

23       -1       77       0        4.789    2

7.65     -5       7        9        -8       4

49.9     -10      20.4     -21      5        1






#### **Example 8 (D_value operation)**



2

2green-5yellow=15

3green+yellow=31

*D_value*

17



3

cad+2kit-bounty=2

2cad+2kit+2bounty=12

cad-kit+2bounty=5

*D_value*

6




#### **Example 9 (solve operation)**


2

2green-5yellow=15

3green+yellow=31

*solve*

green=10

yellow=1




3

cad+2kit-bounty=2

2cad+2kit+2bounty=12

cad-kit+2bounty=5

*solve*

bounty=3

cad=1

kit=2


