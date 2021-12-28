#ifndef __SEARCH__SORT__INTERFACE__
#define __SEARCH__SORT__INTERFACE__






#define u8_INTIAL_SORTING_COUNT   				0

#define u8_INTIAL_SWITCH_NUM				0

#define u8_UNCHECKED_ARR					0
#define u8_GO_FORWARD_INDEX					1
#define u8_GO_BACKWARD_INDEX				-1
#define u8_UNSORTED_ARR						2
#define u8_SORTED_ARR                       3
#define s8_VAL_NOT_FOUND					-1






sint16_t u8_BinarySearch(uint32_t* pu32_arr,uint8_t ArrSize,uint32_t u32_SearchNum) ;
void void_SelectionSort(uint32_t* pu32_arr,uint8_t ArrSize) 					   ;
uint8_t u8_CheckIfSorted(uint32_t* pu32_arr,uint8_t ArrSize)					   ;
void printArr(uint32_t* pu32_arr,uint8_t ArrSize) ;


#endif
