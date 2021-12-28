#ifndef __STACK__INTERFACE__
#define __STACK__INTERFACE__



#define u8_ERROR_FLAG			5
#define u8_FRINST_STR_ITEM		0
#define u8_BALANCED_STR 		1
#define u8_UNBALANCED_STR 		2
#define u8_STRING_UNDER_TEST	3


typedef struct
{
	uint8_t BracketsCheck ;
	struct stack_node *NextNode ;

}stack_node;





void DeleteList(void) ;
void Push(uint8_t u8_data) ;
uint8_t u8_Pull(void);
void PrintStack(void) ;
uint8_t* pu8_BalancedParentheses(uint8_t* pu8_StringCheck) ;







#endif
