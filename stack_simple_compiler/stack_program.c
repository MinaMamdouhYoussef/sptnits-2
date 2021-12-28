#include <stdio.h>
#include <stdlib.h>
#include "primitive_data_types.h"
#include "stack_interface.h"


stack_node* head = NULL_POINTER ;



void Push(uint8_t u8_data)  //push node with given data to linked list using LIFO algorithm
{
	stack_node* ptostack_node_NewNode = (stack_node*)malloc(sizeof(stack_node)) ; //make new dynamic node and point to it
	ptostack_node_NewNode->NextNode = head ; // make the next of the new node point to head
	ptostack_node_NewNode->BracketsCheck = u8_data ; // put the data in the new node
	head = ptostack_node_NewNode ; //make the head point to the new node

}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t u8_Pull(void) // pull node from list if list not empty using LIFO algorithm and return the data in the pulled node
{
	uint8_t u8_PulledData ; //the data pulled
	stack_node* ptostack_node_TempNode = NULL_POINTER ; // temp pointer to node to point to the node needed to be pulled
	if(head!=NULL_POINTER) // check if the list is empty or not
	{
		u8_PulledData = head->BracketsCheck ; // take the data pulled so that it can be returned
		ptostack_node_TempNode = head ; // make the temp node point to what head points to
		head = head->NextNode ; // make the head points to the next node
		free(ptostack_node_TempNode) ; // delete the pulled node
	}
	else
	{
		u8_PulledData = u8_ERROR_FLAG ; // return flag if the list is empty
	}
	return u8_PulledData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteList(void) // function to delete all the list if the list contain any data
{
   while (head!=NULL_POINTER)
   {
       u8_Pull( ) ;
   }

}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintStack(void) // print all the linked list
{
	stack_node* ptostack_node_TempNode = head ;
    while(ptostack_node_TempNode!=NULL_POINTER)
    {
        printf("%c\n",(ptostack_node_TempNode->BracketsCheck)) ;
        ptostack_node_TempNode = ptostack_node_TempNode->NextNode ;
    }


}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t* pu8_BalancedParentheses(uint8_t* pu8_StringCheck)
{
    /* variables help for check if Parentheses are balanced (u8_TempCompareParentheses - u8_BalanceFlag)
	 * and u8_StringIndex so that string send can be accessed to all its characters stored
  	 */
	uint8_t u8_TempCompareParentheses,u8_BalanceFlag = u8_STRING_UNDER_TEST, u8_StringIndex = u8_FRINST_STR_ITEM ;
	uint8_t* pu8_StrStringState =NULL_POINTER ; // pointer to the returned string
	if(pu8_StringCheck!=NULL_POINTER) // check if string is empty or not
	{
		while(pu8_StringCheck[u8_StringIndex]!=NULL_CHAR) // loop to check if the array send is balanced or not
		{
			if(pu8_StringCheck[u8_StringIndex]=='{'||pu8_StringCheck[u8_StringIndex]=='['||pu8_StringCheck[u8_StringIndex]=='(')
			{
				Push(pu8_StringCheck[u8_StringIndex]) ; // push the open parenthesis to the stack
			}
			else if(pu8_StringCheck[u8_StringIndex]=='}'||pu8_StringCheck[u8_StringIndex]==']'||pu8_StringCheck[u8_StringIndex]==')')
			{
				u8_TempCompareParentheses = u8_Pull() ; // pull if there is closed parenthesis
				if(u8_TempCompareParentheses != u8_ERROR_FLAG) // don't enter if the stack is empty
				{

					switch(u8_TempCompareParentheses) /* if the closed parenthesis is not of the same type as the pulled parenthesis
                                                       * make u8_BalanceFlag = u8_UNBALANCED_STR so that UNBALANCED can be returned
                                                       */
					{
						case '{':  u8_BalanceFlag = (pu8_StringCheck[u8_StringIndex]-2)== u8_TempCompareParentheses ?  u8_BALANCED_STR : u8_UNBALANCED_STR ;
								 break ;
						case '[':  u8_BalanceFlag = (pu8_StringCheck[u8_StringIndex]-2)== u8_TempCompareParentheses ?  u8_BALANCED_STR : u8_UNBALANCED_STR ;
								break ;
						case '(':  u8_BalanceFlag = (pu8_StringCheck[u8_StringIndex]-1)== u8_TempCompareParentheses ?  u8_BALANCED_STR : u8_UNBALANCED_STR ;
								break ;
					}
				}
				else /* if there is a close parenthesis and no parenthesis remain in the stack,
                      * make u8_BalanceFlag = u8_UNBALANCED_STR so that UNBALANCED can be returned

                      */
				{
					u8_BalanceFlag = u8_UNBALANCED_STR ;
				}

				if(u8_BalanceFlag==u8_UNBALANCED_STR) /*if, in any time, unbalanced flag raised, make the return string
                                                       * UNBALANCED to return it and get out of the loop
                                                       */
				{
					pu8_StrStringState = "UNBALANCED" ;
					break ;
				}
			}
			u8_StringIndex++ ; // increase index of sting given in argument by 1 to loop again
		}
		if(head!=NULL_POINTER) // if there is parenthesis in stack then the sting isn't balanced
        {
            u8_BalanceFlag = u8_UNBALANCED_STR ;
            pu8_StrStringState = "UNBALANCED" ;
            DeleteList() ;
        }
		if(u8_BalanceFlag==u8_BALANCED_STR) // if u8_BalanceFlag = u8_BALANCED_STR after the loop ended then sting is balanced
		{
			pu8_StrStringState = "BALANCED" ;
		}
	}

	return pu8_StrStringState ;
}
