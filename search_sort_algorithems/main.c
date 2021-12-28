#include <stdio.h>
#include <stdlib.h>
#include "primitive_data_types.h"
#include "search_sort_interfeace.h"

int main()
{
	sint16_t	s16_IndexIfFound = u8_UNCHECKED_ARR ;
	uint32_t pu32_arrTest1[] = {1,2,3,4,5,6,7,8,9,10,11} ;
	uint32_t pu32_arrTest2[] = {100,200,300,400,500,600,700,800,900,1000,1100} ;
	uint32_t pu32_arrTest3[] = {1000,2,3000,4,5000,6,7000,8,9000,1,5000} ;
	uint32_t pu32_arrTest4[] = {11,10,9,8,7,6,5,4,3,2,1} ;
	uint32_t pu32_arrTest5[] = {11,10,9,8,7,6,1,2,3,4,5} ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 1 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

    printf("\nTEST CASE %d\n",1) ;
    printf("Array of case %d before sorted \n",1) ;
	printArr(pu32_arrTest1,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest1,11,1000) ; //expected output : not found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",1000,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",1000) ;
	}
	printf("Array of case %d after sorted \n",1) ;
	printArr(pu32_arrTest1,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 2 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	printf("\nTEST CASE %d\n",2) ;
	printf("Array of case %d before sorted \n",2) ;
	printArr(pu32_arrTest1,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest1,11,11) ; //expected output : found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",11,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",11) ;
	}
	printf("Array of case %d after sorted \n",2) ;
	printArr(pu32_arrTest1,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 3 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	printf("\nTEST CASE %d\n",3) ;
	printf("Array of case %d before sorted \n",3) ;
	printArr(pu32_arrTest2,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest2,11,101) ; //expected output : not found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",101,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",101) ;
	}
	printf("Array of case %d after sorted \n",3) ;
	printArr(pu32_arrTest2,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 4 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	printf("\nTEST CASE %d\n",4) ;
    printf("Array of case %d before sorted \n",4) ;
	printArr(pu32_arrTest3,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest3,11,1000) ; //expected output : found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",1000,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",1000) ;
	}
	printf("Array of case %d after sorted \n",4) ;
	printArr(pu32_arrTest3,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 5 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

    printf("\nTEST CASE %d\n",5) ;
    printf("Array of case %d before sorted \n",5) ;
	printArr(pu32_arrTest4,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest4,11,3) ; //expected output : found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",3,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",3) ;
	}
	printf("Array of case %d after sorted \n",5) ;
	printArr(pu32_arrTest4,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 6 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	printf("\nTEST CASE %d\n",6) ;
	printf("Array of case %d before sorted \n",6) ;
	printArr(pu32_arrTest5,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest5,11,12) ; //expected output : not found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",12,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",12) ;
	}
	printf("Array of case %d after sorted \n",6) ;
	printArr(pu32_arrTest5,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 7 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	printf("\nTEST CASE %d\n",7) ;
    printf("Array of case %d before sorted \n",7) ;
	printArr(pu32_arrTest5,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest5,11,0) ; //expected output : not found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",0,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",0) ;
	}
	printf("Array of case %d after sorted \n",7) ;
	printArr(pu32_arrTest5,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 8 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	printf("\nTEST CASE %d\n",8) ;
    printf("Array of case %d before sorted \n",8) ;
	printArr(pu32_arrTest3,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest3,11,1) ; //expected output : found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",1,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",1) ;
	}
	printf("Array of case %d after sorted \n",8) ;
	printArr(pu32_arrTest3,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 9 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

    printf("\nTEST CASE %d\n",9) ;
    printf("Array of case %d before sorted \n",9) ;
	printArr(pu32_arrTest3,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest3,11,3) ; //expected output : found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",3,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",3) ;
	}
	printf("Array of case %d after sorted \n",9) ;
	printArr(pu32_arrTest3,11) ;

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////// TEST case 10 /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	printf("\nTEST CASE %d\n",10) ;
    printf("Array of case %d before sorted \n",10) ;
	printArr(pu32_arrTest3,11) ;
	s16_IndexIfFound = u8_BinarySearch(pu32_arrTest3,11,3100) ; //expected output : found
	if(s16_IndexIfFound != s8_VAL_NOT_FOUND)
	{
		printf("number %d found in index %d \n",3100,s16_IndexIfFound) ;
	}
	else
	{
		printf("the value %d entered not found \n",3100) ;
	}
	printf("Array of case %d after sorted \n",10) ;
	printArr(pu32_arrTest3,11) ;

    return 0;
}
