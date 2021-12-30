#include <stdio.h>
#include <stdlib.h>
#include"primitive_data_types.h"
#include "payment_interface.h"



int main()
{
    ST_cardData_t carddata_UserData ;
    ST_terminalData_t terminalData_UserData;
    ST_transaction transServerReturnData ;
    uint8_t u8_RepeatTrans , u8_ExpireState ;
    sint8_t s8_TermialState ;

    do{
        InputCardData(&carddata_UserData) ;
        s8_TermialState=s8_InputTerminalData(&terminalData_UserData) ;
        if(s8_TermialState!=u8_PROCESS_DECLINED)
         {
            u8_ExpireState=u8_IsExpired(&carddata_UserData,&terminalData_UserData) ;
            if(u8_ExpireState==u8_DATE_EXISTS)
            {
                ServerDataCheck(&carddata_UserData,&terminalData_UserData,&transServerReturnData) ;
                if (transServerReturnData.transStat == APPROVED)
                {
                    printf("transaction is approved \n") ;
                }
            }

         }
        printf("Do you want to continue(y/n)?: \n") ;
        u8_RepeatTrans=getchar() ;
        fflush(stdin) ;

      }while(u8_RepeatTrans=='Y' || u8_RepeatTrans == 'y') ;

    return 0;
}
