#include <stdio.h>
#include <stdlib.h>
#include "primitive_data_types.h"
#include "bit_wise.h"
#include "x_o_game_interface.h"

int main()
{
    uint16_t u16_Player1XPlaces = u16_PRINT_EMPTY_TABLE ;
	uint16_t u16_Player2OPlaces = u16_PRINT_EMPTY_TABLE ;
    uint8_t u8_WantedPlace ;
    uint8_t pu8_UserInput[30] ;
    uint8_t u8_ValidPlaysCount =  u8_GAME_NOT_BEGIN ;
    uint8_t u8_ErrorCheckFlag = u8_NO_ERROR,u8_WinnerStateFlag = u8_CONTINUE_PLAY_STATE;
    printf("Welcome to X-O game.\nplayer 1 will play with x and player 2 play with o\n") ;
    print_x_o_table(&u16_Player1XPlaces,&u16_Player2OPlaces) ;

    CLEAR_BIT(u16_Player1XPlaces,9) ;
    CLEAR_BIT(u16_Player2OPlaces,9) ;
    while(u8_ValidPlaysCount<=8)
    {
      printf("player 1, please enter the place number you want to play x in \n") ;
      do
      {

        gets(pu8_UserInput) ;
        if((pu8_UserInput[0]<='0'&&pu8_UserInput[0]>='9')||pu8_UserInput[1]!=NULL)
        {
            printf("you entered invalid character or number, please enter valid number from 0 to 8 \n") ;
            u8_ErrorCheckFlag = u8_LAST_ENTERED_VAL_NOT_VALID ;
            continue ;
        }
        u8_WantedPlace=pu8_UserInput[0]-'0' ;
        u8_ErrorCheckFlag = SetCheckInputValidity(&u16_Player1XPlaces,&u16_Player2OPlaces,u8_LAST_ENTERED_VAL_X,u8_WantedPlace) ;

      }while(u8_ErrorCheckFlag == u8_LAST_ENTERED_VAL_NOT_VALID) ;
      u8_ValidPlaysCount++ ;
      print_x_o_table(&u16_Player1XPlaces,&u16_Player2OPlaces) ;
      u8_WinnerStateFlag = CheckWinnerState(&u16_Player1XPlaces,u8_LAST_ENTERED_VAL_X) ;
      if(u8_WinnerStateFlag == u8_X_WIN)
      {
          printf("congrats, player X win \n") ;
          break ;
      }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       if(u8_ValidPlaysCount<9)
       {

           printf("player 2 , please enter the place number you want to play o in \n") ;
           do
            {
                gets(pu8_UserInput) ;
                if((pu8_UserInput[0]<='0'&&pu8_UserInput[0]>='9')||pu8_UserInput[1]!=NULL)
                {
                    printf("you entered invalid character or number, please enter valid number from 0 to 8 \n") ;
                    u8_ErrorCheckFlag = u8_LAST_ENTERED_VAL_NOT_VALID ;
                    continue ;
                }
                u8_WantedPlace=pu8_UserInput[0]-'0' ;
                u8_ErrorCheckFlag = SetCheckInputValidity(&u16_Player1XPlaces,&u16_Player2OPlaces,u8_LAST_ENTERED_VAL_O,u8_WantedPlace) ;

            }while(u8_ErrorCheckFlag== u8_LAST_ENTERED_VAL_NOT_VALID) ;
		   u8_ValidPlaysCount++ ;
           print_x_o_table(&u16_Player1XPlaces,&u16_Player2OPlaces) ;
           u8_WinnerStateFlag = CheckWinnerState(&u16_Player2OPlaces,u8_LAST_ENTERED_VAL_O) ;
           if(u8_WinnerStateFlag == u8_O_WIN)
		   {
               printf("congrats, player O win \n") ;
               break ;
           }
       }

    }
     if(u8_WinnerStateFlag!=u8_O_WIN && u8_WinnerStateFlag!=u8_X_WIN )
      {
          printf("no win, please try again. \n") ;

      }
    system("pause") ;
    return 0;
}
