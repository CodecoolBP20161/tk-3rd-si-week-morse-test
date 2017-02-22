#include "selfprot.h"

/* Helper array (necessary bits for morse code of different characters) */
static const int ALPHA_SIZE[] = {
    3, //A
    7, //B
    7, //C
    5, //D
    1, //E
    7, //F
    5, //G
    7, //H
    3, //I
    7, //J
    5, //K
    7, //L
    3, //M
    3, //N
    5, //O
    7, //P
    7, //Q
    5, //R
    5, //S
    1, //T
    5, //U
    7, //V
    5, //W
    7, //X
    7, //Y
    7, //Z
};

/* Helper constant (necessary bits for morse code of every numeric value) */
static const int NUM_SIZE = 9;

/*
 * Function: CharToMorse
 * --------------------------------------------
 * convert characters/numbers to dots and dashes (morse code).
 * the function use the character-morse and number-morse maps
 * from the common header.
 *
 * input: the convertable string
 * output: converted morse string
 *
 * returns: the index of the last converted character of the input
 */
int CharToMorse(char input[], char *output) {
	int i;
	/* stores where are we in the output array */
	int j = 0;
	/* Process all character of the input */
	for(i=0; i<250 && input[i]!='\0'; i++) {
		char act = input[i];
		if(act>='A' && act<='Z') {
			/* If the processed character is an alphabetic one */
			/* then copy the proper morse code into the correct place */
			strcpy(output + j, CHAR_TO_MORSE_ALPHA[act-'A']);
			/* set the current output place after the new part */
			j += ALPHA_SIZE[act-'A'];
			/* and if the end of the input is not reached
			 * and the next character is not the end of the string
			 * or a space between word */
			if(i<249 && input[i+1]!='\0' && input[i+1]!=' ') {
				/* then add character separator morse code */
				strcpy(output + j, "/");
				j++;
			}
		} else if(act>='0' && act<='9') {
			/* else if the processed character is a number */
			/* then copy the proper morse code into the correct place */
			strcpy(output + j, CHAR_TO_MORSE_NUMBER[act-'0']);
			/* set the current output place after the new part */
			j += NUM_SIZE;
			/* and if the end of the input is not reached
			 * and the next character is not the end of the string
			 * or a space between word */
			if(i<249 && input[i+1]!='\0' && input[i+1]!=' ') {
				/* then add character separator morse code */
				strcpy(output + j, "/");
				j++;
			}
		} else if(act==' ') {
			/* else if the processed character is a space */
			/* then add the word separator morse code (one tab) */
			strcpy(output + j, "\t");
			j++;
		}
	}
    return i;
}
