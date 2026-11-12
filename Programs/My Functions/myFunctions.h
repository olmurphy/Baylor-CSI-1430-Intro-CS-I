/*
Author: Owen Murphy
Assignment Title: My Functions
Assignment Description: Write functions that can be tested and used
Due Date: 11/06/2019
Date Created: 11/02/2019
Date Last Modified: 11/06/2019
*/

#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

#include <iostream>
#include <cassert>


/*
 Description:
    Function returns the value of the larger of two integers.
 Return:
    integer the bigger integer of the two.
 Precondition:
    two integer values exist
 Postcondition:
    the value of the largest integer is returned.
    the orignial integers are unchanged
    if the integers have the same value then the value of either integer is
        returned
 */
int max(int, int);

/*
 Description:
    Function returns the value of the larger of two doubles.
 Return:
    return the biggest double of the two values passed in
 Precondition:
    two double values exist
 Postcondition:
    The value of the larger double is returned.
    The original doubles are unchanged
    If the doubles have the same value then the value of either double is
        returned.
 */
double max(double, double);

/*
Description:
    an array of integer values exist
Return:
    return the biggest integer of the array with size of array passed in
Precondition:
    an array of integer values exist
Postcondition:
    The largest value in the array is returned.
    The original array is unchanged
*/
int max(int m[], int n);

/*
Description:
    Function returns the value of the largest doubles in an array.
Return:
    return the biggest double in the array and size of array passed in
Precondition:
    an array of double values exist
Postcondition:
    The largest value in the array is returned.
    The original array is unchanged
*/
double max(double m[], int n);

/*
Description:
    Function returns the value of the smaller of two integers.
Return:
    return the smaller integer of the two integers passed in
Precondition:
    two integer values exist
Postcondition:
    The value of the smallest integer is returned.
    The original integers are unchanged
    If the integers have the same value then the value of either integer is
        returned.
*/
int min(int, int);

/*
Description:
    Function returns the value of the smaller of two double.
Return:
    retunr the smaller double of the two double values passed in
Precondition:
    two double values exist
Postcondition:
    The value of the smaller double is returned.
    The original double are unchanged
    If the double have the same value then the value of either double is
    returned.
*/
double min(double, double);

/*
Description:
    Function returns the value of the smallest integer in an array.
Return:
    return the smaller integer of the two values passed in
Precondition:
    an array of integer values exist
Postcondition:
    The smallest value in the array is returned.
    The original array is unchanged
*/
int min(int m[], int n);

/*
Description:
    Function returns the value of the smallest doubles in an array.
Return:
    return the smallest double in array with size of array passed in
Precondition:
    an array of double values exist
Postcondition:
    The smallest value in the array is returned.
    The original array is unchanged
*/
double min(double m[], int n);

/*
Description:
    This function returns the absolute value of an integer
Return:
    return the absolute value of the integer passed in
Precondition:
    Some integer value exists
Postcondition:
    Integer value is unchanged
*/
int absoluteValue(int);

/*
Description:
    This function returns the absolute value of a double
Return:
    return the absolute value of the double passed in
Precondition:
    Some double value exists
Postcondition:
    double value is unchanged
*/
double absoluteValue(double);

/*
Description:
    The function calculates factorial
Return:
    return the factorial of the integer passed in
Precondition:
    Some integer value N exists
Postcondition:
    the value of N unchanged
*/
double factorial(int);

/*
Description:
    The function calculates the number of combinations of M items taken N at a
        time.
Return:
    Return The number of combinations of M items taken N at a time.
Precondition:
    Two integer value M and N exists
Postcondition:
    The value of the M and N unchanged
*/
double combination(int M, int N);

/*
Description:
    The function calculates the number of permutations of M items taken N at a
        time.
Return:
    The number of permutations of M items taken N at a time.
Precondition:
    Two integer value M and N exists
Postcondition:
    The value of the M and N unchanged
*/
double permutation(int M, int N);

#endif /* myFunctions_H_INCLUDED */
