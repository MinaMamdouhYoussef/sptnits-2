#include <stdio.h>
#include <stdlib.h>
#include "primitive_data_types.h"
#include "search_sort_interfeace.h"

uint8_t u8_CheckIfSorted(uint32_t* pu32_arr,uint8_t ArrSize) //check if the array sorted or not 
{
	uint8_t u8_CheckCount = u8_INTIAL_SORTING_COUNT ; //counter for the for loop so that all array variables could be checked
	uint8_t u8_SortFlag = u8_UNCHECKED_ARR ; // sort flag to return if the array is sorted or not  
	uint32_t u32_BeforeReachedNum = pu32_arr[u8_INTIAL_SORTING_COUNT] ;

	for(u8_CheckCount= (u8_INTIAL_SORTING_COUNT+1);u8_CheckCount < ArrSize;u8_CheckCount++) //check if the array is in ascending order
	{
		if(u32_BeforeReachedNum<=pu32_arr[u8_CheckCount])
		{
			u32_BeforeReachedNum = pu32_arr[u8_CheckCount] ;
		}
		else
		{
			u8_SortFlag = u8_UNSORTED_ARR ;
			break ; 
		}
	}
	//	if the sort flag get out from the for loop and sort flag not equal u8_UNSORTED_ARR then array is sorted 
	if(u8_SortFlag != u8_UNSORTED_ARR) 
	{
		u8_SortFlag = u8_SORTED_ARR ;
	}

	return u8_SortFlag ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void void_SelectionSort(uint32_t* pu32_arr,uint8_t ArrSize)
{
	uint8_t u8_CheckCount1 = u8_INTIAL_SORTING_COUNT,u8_CheckCount2 = u8_INTIAL_SORTING_COUNT ; // the two couters needed for the for loop 
	uint32_t u32_SwitchNum = u8_INTIAL_SWITCH_NUM ; // temp variable to switch numbers in
	// pass to all the variables, compare between variables, and switch smaller one to front side of array .  	
	for(u8_CheckCount1=u8_INTIAL_SORTING_COUNT;u8_CheckCount1<ArrSize;u8_CheckCount1++) 
	{ 
		for(u8_CheckCount2=u8_CheckCount1;u8_CheckCount2<ArrSize;u8_CheckCount2++)
		{
			if(pu32_arr[u8_CheckCount1]>pu32_arr[u8_CheckCount2])
			{
				u32_SwitchNum = pu32_arr[u8_CheckCount1] ;
				pu32_arr[u8_CheckCount1] = pu32_arr[u8_CheckCount2] ;
				pu32_arr[u8_CheckCount2] = u32_SwitchNum ;
			}
		}
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

sint16_t u8_BinarySearch(uint32_t* pu32_arr,const uint8_t ArrSize,uint32_t u32_SearchNum)
{
	// flag to check if the array sorted and (start- mid- End ) needed for binary search 
	uint8_t u8_CheckSortFlag = u8_UNCHECKED_ARR , u8_Start=u8_INTIAL_SORTING_COUNT , u8_Mid = u8_INTIAL_SORTING_COUNT ; 
	uint8_t u8_End = (ArrSize+u8_GO_BACKWARD_INDEX) ;
	sint16_t s16_ReturnIndex ; // the returned index variable that return index of the number needed if found and -1 if not found
	u8_CheckSortFlag = u8_CheckIfSorted(pu32_arr,ArrSize) ; // check if the array is sorted 
	if(u8_CheckSortFlag == u8_UNSORTED_ARR ) 
	{
		void_SelectionSort(pu32_arr,ArrSize) ;
	}
	if (ArrSize%2 == 0 ) // check if the array size can divided by 2 or not to give mid the right value 
	{
		u8_Mid = ArrSize/2 ;
	}
	else
	{
		u8_Mid = (ArrSize+u8_GO_FORWARD_INDEX)/2 ;
	}

	while((pu32_arr[u8_Mid]!= u32_SearchNum)&&(u8_Start!=u8_End) ) //search for number using binary search algorithm
	{

		if(u8_Mid!=u8_Start && u8_Mid!=u8_End && pu32_arr[u8_Mid]<u32_SearchNum)
		{
			u8_Start = u8_Mid+u8_GO_FORWARD_INDEX ;
			u8_Mid = (u8_Start + u8_End)/2 ;

		}
		else if(u8_Mid!=u8_Start&& u8_Mid!=u8_End && pu32_arr[u8_Mid]>u32_SearchNum)
		{
			u8_End = u8_Mid + u8_GO_BACKWARD_INDEX ;
			u8_Mid = (u8_Start + u8_End)/2 ;
		}
		else if(u8_Mid==u8_Start)
        {
            u8_End = u8_Start ;
        }
        else if (u8_Mid==u8_End)
        {
            u8_Start = u8_End ;
        }
	}

	if(pu32_arr[u8_Mid]!= u32_SearchNum) //check if the number is found or the while loop ended due to (u8_Start!=u8_End)
	{
		s16_ReturnIndex = (sint16_t)s8_VAL_NOT_FOUND ; // give s16_ReturnIndex flag value to tell the value not found
	}
	else
	{
		s16_ReturnIndex = u8_Mid ; //  give s16_ReturnIndex the int value of index
	}
	return s16_ReturnIndex ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void printArr(uint32_t* pu32_arr,uint8_t ArrSize)
{
	uint8_t u8_PrintCount = u8_INTIAL_SORTING_COUNT  ;
	for (u8_PrintCount= u8_INTIAL_SORTING_COUNT;u8_PrintCount<ArrSize;u8_PrintCount++ )
	{
	    if(u8_PrintCount<(ArrSize+u8_GO_BACKWARD_INDEX))
		{
		    printf("  %d  ,",pu32_arr[u8_PrintCount]) ;
		}
		else
        {
            printf("  %d  ",pu32_arr[u8_PrintCount]) ;
        }
	}
	printf("\n\n") ;

}
