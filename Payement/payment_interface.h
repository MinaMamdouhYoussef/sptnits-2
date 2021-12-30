#ifndef __PAYMENT__INTERFACE__
#define __PAYMENT__INTERFACE__


#define u8_INTIAL_COUNT            					 0
#define u8_SPACE_ASCII             					 32
#define u8_ARR_NAME_SIZE           					 25
#define u8_ARR_EXP_DATE_SIZE       					 6
#define u8_ARR_ACC_NUM_SIZE        					 20
#define u8_ARR_TRANS_DATE_SIZE     					 11
#define s8_PROCESS_FAILED		     				 -1
#define u8_PROCESS_DONE	     				 		 1
#define s8_DATE_EXPIRED								 -2
#define u8_DATE_EXISTS								 2
#define u8_MAX_ARR_DATA_SIZE                         10
#define f32_MAX_TRANS_AMOUNT						 5000.00
#define u8_PROCESS_DECLINED                          0

typedef struct ST_cardData_t
{
    uint8_t cpu8_cardHolderName[25] ;
    uint8_t cpu8_primaryAccountNumber[20] ;
    uint8_t cpu8_cardExpirationDate[6] ;
}ST_cardData_t;


typedef struct ST_terminalData_t
{
    float32_t f32_transAmount ;
    float32_t f32_maxTransAmount ;
    uint8_t cpu8_transactionDate[11] ;
}ST_terminalData_t;


typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED
}EN_transStat_t;

typedef struct ST_transaction
{
    ST_cardData_t cardHolderData ;
    ST_terminalData_t transData ;
    EN_transStat_t transStat ;
}ST_transaction ;


typedef struct ST_accountBalance_t
{
    float32_t f32_balance;
    uint8_t cpu8_primaryAccountNumber[20] ;
}ST_accountBalance_t;




void InputCardData(ST_cardData_t* const pcarddata_userData) ;

uint8_t u8_InputTerminalData(ST_terminalData_t* const pterminaldata_userData) ;

uint8_t u8_IsExpired(const ST_cardData_t* const pcarddata_userData,const ST_terminalData_t* const pterminaldata_userData) ;


void ServerDataCheck(const ST_cardData_t* const pcarddata_userData,const ST_terminalData_t* const pterminaldata_userData,ST_transaction* const ptransaction_ReturnData) ;



#endif // __PAYMENT__INTERFACE__
