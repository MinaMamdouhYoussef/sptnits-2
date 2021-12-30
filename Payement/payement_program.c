
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"primitive_data_types.h"
#include "payment_interface.h"





ST_accountBalance_t gArr_serverData[u8_MAX_ARR_DATA_SIZE] = {{100.00,{"123456789"}},{6000.00,{"234567891"}},{3250.25,{"567891234"}},{1500.12,{"456789123"}},{500.00,{"258649173"}},{2100.00,{"654823719"}},{0.00,{"971362485"}},{1.00,{"793148625}"}},{10.12,{"123123456"}},{0.55,{"456789321"}}} ;



void InputCardData(ST_cardData_t* const pcarddata_userData)
{
    printf("Please Enter Card Data: \n") ;
    printf("Please Enter Card Holder Name: \n") ;
	gets(pcarddata_userData->cpu8_cardHolderName) ;
	printf("Please Enter primary account Number: \n") ;
	gets(pcarddata_userData->cpu8_primaryAccountNumber) ;
	printf("Please Enter Card Expiry Date :\n") ;
    gets(pcarddata_userData->cpu8_cardExpirationDate) ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint8_t s8_InputTerminalData(ST_terminalData_t* const pterminaldata_userData)
{
	sint8_t s8_ErrorFlag= u8_PROCESS_DONE ;
	pterminaldata_userData->f32_maxTransAmount =  f32_MAX_TRANS_AMOUNT ;
	printf("Please Enter Terminal Data:\n") ;
	printf("Please Enter The Transaction Amount:\n") ;
	scanf("%f",&(pterminaldata_userData->f32_transAmount)) ;
	fflush(stdin) ;
	if(pterminaldata_userData->f32_transAmount>f32_MAX_TRANS_AMOUNT)
	{
		printf("The Transaction is DECLINED. \n") ;
		s8_ErrorFlag = u8_PROCESS_DECLINED ;
	}
	else
	{
        printf("Please Enter The Transaction Date:\n") ;
	    gets(pterminaldata_userData->cpu8_transactionDate) ;
        fflush(stdin) ;
	}

	return s8_ErrorFlag ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t u8_IsExpired(const ST_cardData_t* const pcarddata_userData,const ST_terminalData_t* const pterminaldata_userData)
{
	uint8_t u8_ReturnDateState ;
	uint8_t u8_CardDateMM = ((pcarddata_userData->cpu8_cardExpirationDate[0]-'0')*10)+ (pcarddata_userData->cpu8_cardExpirationDate[1]-'0');
	uint8_t u8_CardDateYY = ((pcarddata_userData->cpu8_cardExpirationDate[3]-'0')*10)+ (pcarddata_userData->cpu8_cardExpirationDate[4]-'0');
	uint8_t u8_TerminalDateMM = ((pterminaldata_userData->cpu8_transactionDate[3]-'0')*10)+(pterminaldata_userData->cpu8_transactionDate[4]-'0') ;
	uint8_t u8_TerminalDateYY = ((pterminaldata_userData->cpu8_transactionDate[8]-'0')*10)+(pterminaldata_userData->cpu8_transactionDate[9]-'0') ;

	if(u8_TerminalDateYY<=u8_CardDateYY)
	{
		if(u8_TerminalDateYY<u8_CardDateYY)
		{
			u8_ReturnDateState = u8_DATE_EXISTS ;
		}
		else
		{
			if(u8_TerminalDateMM < u8_CardDateMM)
			{
				u8_ReturnDateState = u8_DATE_EXISTS ;
			}
			else
			{
				u8_ReturnDateState = u8_PROCESS_DECLINED ;

				printf("The Transaction is DECLINED. \n") ;
			}
		}
	}
	else
	{
		u8_ReturnDateState = u8_PROCESS_DECLINED ;
		printf("The Transaction is DECLINED. \n") ;
	}
	return u8_ReturnDateState ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ServerDataCheck(const ST_cardData_t* const pcarddata_userData,const ST_terminalData_t* const pterminaldata_userData,ST_transaction* const ptransaction_ReturnData)
{
	uint8_t u8_ServerDataCounter = u8_INTIAL_COUNT , u8_accNumReachedFlag ;
	ptransaction_ReturnData->cardHolderData =  (*pcarddata_userData) ;
        ptransaction_ReturnData->transData =  (*pterminaldata_userData) ;
	EN_transStat_t state = DECLINED ;
	printf("Verifying Data From The Server...\n") ;
	for(u8_ServerDataCounter = u8_INTIAL_COUNT ; u8_ServerDataCounter<10 ; u8_ServerDataCounter++)
	{
		u8_accNumReachedFlag =  strcmp((pcarddata_userData->cpu8_primaryAccountNumber),(gArr_serverData[u8_ServerDataCounter].cpu8_primaryAccountNumber) );
		if(u8_accNumReachedFlag == 0 )
		{
			break ;
		}
	}
	if(u8_accNumReachedFlag==0)
	{
		if(gArr_serverData[u8_ServerDataCounter].f32_balance >= pterminaldata_userData->f32_transAmount)
		{
			state = APPROVED ; ;
		}
		else
        {
            printf("The Transaction is DECLINED. \n") ;
            state = DECLINED ;
        }
	}
	else
	{
		printf("The Transaction is DECLINED. \n") ;
        state = DECLINED ;
	}
    ptransaction_ReturnData->transStat = state ;
}
