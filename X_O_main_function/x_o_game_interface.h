#ifndef __X__O__GAME__INTERFACE__
#define __X__O__GAME__INTERFACE__


#define u16_PRINT_EMPTY_TABLE			    	512
#define u8_LAST_ENTERED_VAL_NOT_VALID		    14
#define u8_PLACE_NOT_VALID						13
#define u8_PLACE_VALID							12
#define u8_NO_ERROR								11
#define u8_ERROR_STATE							10
#define u8_GAME_NOT_END							9
#define u8_TABLE_FULL_SIZE						8
#define u8_X_WIN								7
#define u8_O_WIN								6
#define u8_WIN_STATE							5
#define u8_CONTINUE_PLAY_STATE					4
#define u8_LAST_ENTERED_VAL_X  					3
#define u8_LAST_ENTERED_VAL_O  					2
#define u8_XO_PLACE								1
#define u8_TABLE_EMPTY							0

#define u8_EMPTY_PLACE							0

#define u8_INTIAL_INDEX_VAL						0

#define u8_GAME_NOT_BEGIN               	    0

#define u16_WINNER_STATE1						7
#define u16_WINNER_STATE2						56
#define u16_WINNER_STATE3						73
#define u16_WINNER_STATE4						84
#define u16_WINNER_STATE5						146
#define u16_WINNER_STATE6						273
#define u16_WINNER_STATE7						292
#define u16_WINNER_STATE8						448


void print_x_o_table(const uint16_t* const pu16_x_places,const uint16_t* const pu16_o_places) ;
uint8_t CheckWinnerState(const uint16_t* const pu16_x_or_o_places,uint8_t last_entered_value ) ;
uint8_t SetCheckInputValidity(uint16_t* const pu16_x_places,uint16_t* const pu16_o_places,uint8_t u8_LastEnteredVal,uint8_t u8_place_num) ;



#endif
