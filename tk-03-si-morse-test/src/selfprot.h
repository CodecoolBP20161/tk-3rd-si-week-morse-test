#ifndef SELFPROT_H
#define SELFPROT_H



/**************************************************************************/
/************************ USEABLE CUSTOM DATA TYPES ***********************/
/**************************************************************************/

/* The possible states of the system */
typedef enum {
  OK,
  HIGH_ACCELERATION,
  HIGH_TEMP,
  HIGH_ACCELERATION_AND_TEMP
} SystemState;

/* Data structure to store environment data
 * and system state together */
typedef struct EnvironmentData {
   signed int acc_x     : 7;
   signed int acc_y     : 7;
   signed int acc_z     : 7;
   signed int temp  	: 8;
   SystemState state	: 2;
} EnvironmentData;



/**************************************************************************/
/********************* FUNCTIONS SHALL BE IMPLEMENTED *********************/
/**************************************************************************/

/* Functions shall be implemented */
EnvironmentData CreateEnvironmentData(float acc_x, float acc_y, float acc_z, int temp);
void CalculateSystemState(EnvironmentData *env);
int CharToMorse(char input[], char *output);
int MorseToBinary(char input[], char output[]);



/**************************************************************************/
/**************************** HELPER CONSTANTS ****************************/
/**************************************************************************/

/* Morse codes of alphabetic characters */
static const char CHAR_TO_MORSE_ALPHA[26][8] = {
    ". -",		//A
    "- . . .",	//B
    "- . - .",	//C
    "- . .",	//D
    ".", 		//E
    ". . - .",	//F
    "- - .",	//G
    ". . . .",	//H
    ". .",		//I
    ". - - -",	//J
    "- . -",	//K
    ". - . .",	//L
    "- -",		//M
    "- .",		//N
    "- - -",	//O
    ". - - .",	//P
    "- - . -",	//Q
    ". - .",	//R
    ". . .",	//S
    "-",		//T
    ". . -",	//U
    ". . . -",	//V
    ". - -",	//W
    "- . . -",	//X
    "- . - -",	//Y
    "- - . .",	//Z
};

/* Morse codes of numbers */
static const char CHAR_TO_MORSE_NUMBER[10][10] = {
    "- - - - -",	//0
    ". - - - -",	//1
    ". . - - -",	//2
    ". . . - -",	//3
    ". . . . -",	//4
    ". . . . .",	//5
    "- . . . .",	//6
    "- - . . .",	//7
    "- - - . .",	//8
    "- - - - .",	//9
};

#endif /* SELFPROT_H */
