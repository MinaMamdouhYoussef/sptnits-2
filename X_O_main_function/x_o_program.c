
#include <stdio.h>
#include <stdlib.h>
#include "primitive_data_types.h"
#include "bit_wise.h"
#include "x_o_game_interface.h"


void print_x_o_table(const uint16_t* const pu16_x_places,const uint16_t* const pu16_o_places)
{
	uint8_t u8_CounterPrintTable = u8_TABLE_EMPTY ;
    if((*pu16_x_places)<u16_PRINT_EMPTY_TABLE || (*pu16_o_places)<u16_PRINT_EMPTY_TABLE )
    {
        for(u8_CounterPrintTable= u8_TABLE_EMPTY ; u8_CounterPrintTable<=u8_TABLE_FULL_SIZE;u8_CounterPrintTable++)
        {
            if(GET_BIT((*pu16_x_places),u8_CounterPrintTable)==u8_XO_PLACE)
            {
                printf("X |") ;

            }
            else if(GET_BIT((*pu16_o_places),u8_CounterPrintTable)==u8_XO_PLACE)
            {
                printf("O |") ;

            }
            else
            {
                printf("  |") ;
            }

            if(u8_CounterPrintTable%3==2)
            {
                printf("\n--|--|--|\n") ;
            }
        }
        printf("\n\n") ;
    }
    else if((*pu16_x_places)==u16_PRINT_EMPTY_TABLE && (*pu16_o_places)==u16_PRINT_EMPTY_TABLE )
    {
        for(u8_CounterPrintTable= u8_TABLE_EMPTY ; u8_CounterPrintTable<=u8_TABLE_FULL_SIZE;u8_CounterPrintTable++)
        {
            printf("%d |",u8_CounterPrintTable) ;
            if(u8_CounterPrintTable%3==2)
            {
                printf("\n--|--|--|\n") ;
            }
        }
        printf("\n\n") ;
    }
    else
    {
        printf("Error: the values given for X or O places are above the maximum limit places \n") ;
    }


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t CheckWinnerState(const uint16_t* const pu16_x_or_o_places,uint8_t last_entered_value )
{
	uint8_t u8_WinnerFlag = u8_CONTINUE_PLAY_STATE ;
	uint8_t u8_WhoWinFlag = u8_GAME_NOT_END ;
	if(last_entered_value == u8_LAST_ENTERED_VAL_X || last_entered_value == u8_LAST_ENTERED_VAL_O )
	{
			if(((*pu16_x_or_o_places) & u16_WINNER_STATE1)==u16_WINNER_STATE1)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else if(((*pu16_x_or_o_places) & u16_WINNER_STATE2)==u16_WINNER_STATE2)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else if(((*pu16_x_or_o_places) & u16_WINNER_STATE3)==u16_WINNER_STATE3)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else if(((*pu16_x_or_o_places) & u16_WINNER_STATE4)==u16_WINNER_STATE4)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else if(((*pu16_x_or_o_places) & u16_WINNER_STATE5)==u16_WINNER_STATE5)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else if(((*pu16_x_or_o_places) & u16_WINNER_STATE6)==u16_WINNER_STATE6)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else if(((*pu16_x_or_o_places) & u16_WINNER_STATE7)==u16_WINNER_STATE7)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else if(((*pu16_x_or_o_places) & u16_WINNER_STATE8)==u16_WINNER_STATE8)
			{ u8_WinnerFlag = u8_WIN_STATE ;}
			else
            {
                u8_WinnerFlag = u8_CONTINUE_PLAY_STATE ;
            }

		if(u8_WinnerFlag == u8_WIN_STATE )
		{
			if(last_entered_value == u8_LAST_ENTERED_VAL_X)
			{
				u8_WhoWinFlag = u8_X_WIN ;
			}
            else
			{
				u8_WhoWinFlag = u8_O_WIN ;
			}
		}
	}
	else
	{
		printf("one of function check_winner_state arguments isn't correct \n") ;
		u8_WhoWinFlag = u8_ERROR_STATE ;
	}
	return u8_WhoWinFlag ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t SetCheckInputValidity(uint16_t* const pu16_x_places,uint16_t* const pu16_o_places,uint8_t u8_LastEnteredVal,uint8_t u8_place_num)
{
   uint8_t u8_PlaceValditiy = u8_PLACE_NOT_VALID ,u8_StrIndex = u8_INTIAL_INDEX_VAL ;

   if(u8_place_num<=8)
   {
      if(u8_LastEnteredVal == u8_LAST_ENTERED_VAL_O)
      {
         if(GET_BIT((*pu16_o_places),u8_place_num)== u8_EMPTY_PLACE
            && GET_BIT((*pu16_x_places),u8_place_num)== u8_EMPTY_PLACE)
         {
            SET_BIT((*pu16_o_places),u8_place_num) ;
            u8_PlaceValditiy = u8_PLACE_VALID ;
         }
         else
         {
            printf("the place you entered is not empty; please enter another place from 0 to 8\n") ;
            u8_PlaceValditiy = u8_LAST_ENTERED_VAL_NOT_VALID ;
         }
      }
      else if(u8_LastEnteredVal == u8_LAST_ENTERED_VAL_X)
      {
         if(GET_BIT((*pu16_o_places),u8_place_num)== u8_EMPTY_PLACE
            && GET_BIT((*pu16_x_places),u8_place_num)== u8_EMPTY_PLACE)
         {
            SET_BIT((*pu16_x_places),u8_place_num) ;
            u8_PlaceValditiy = u8_PLACE_VALID ;
         }
         else
         {
            printf("the place you entered is not empty; please enter another place from 0 to 8\n") ;
            u8_PlaceValditiy = u8_LAST_ENTERED_VAL_NOT_VALID ;
         }
      }
   }
   else
    {
         printf("the place you entered is invalid ; please enter another place from 0 to 8\n") ;
         u8_PlaceValditiy = u8_LAST_ENTERED_VAL_NOT_VALID ;
    }
return u8_PlaceValditiy ;
}
