#include "selfprot.h"

/* Size of a character in bits */
int CHAR_BITS = (sizeof(char)*8);

/*
 * Function: MorseToBinary
 * --------------------------------------------
 * converts morse string input bits
 *
 * input: the convertable morse string
 * output: morse in bits
 *
 * returns: the number of used bits for morse
 */
int MorseToBinary(char input[], char output[]) {
	int i;
	/* Stores how many bits are used to store the actually processed part of the input */
	int j = 0;
	/* Process the caught morse code */
	for(i=0; i<250 && input[i]!='\0'; i++) {
		char act = input[i];
		switch (act) {
			case '.':
				/* Convert dot */
				if((j/CHAR_BITS) != ((j+1)/CHAR_BITS)) {
					/* if the full binary equivalent cannot stored
					 * at the end of the current element of the array */
					/* then the first part is stored at the end of it */
					int bitsInNext = j+1 - ((j)/CHAR_BITS+1)*CHAR_BITS;
					output[j/CHAR_BITS] |= 0x01>>bitsInNext;
				}
				/* store the rest of the binaries in the proper place */
				j++;
				output[j/CHAR_BITS] |= (0x01 << (CHAR_BITS-(j%CHAR_BITS)));
				break;
			case '-':
				/* Convert dash just like dot */
				if((j/CHAR_BITS) != ((j+3)/CHAR_BITS)) {
					int bitsInNext = j+3 - ((j)/CHAR_BITS+1)*CHAR_BITS;
					output[j/CHAR_BITS] |= 0x07>>bitsInNext;
				}
				j+=3;
				output[j/CHAR_BITS] |= (0x07 << (CHAR_BITS-(j%CHAR_BITS)));
				break;
			case ' ':
				/* Process inter-element gap: the value of the next bit is kept as zero */
				j++;
				break;
			case '/':
				/* Process short gap between letters: the value of next three bit is kept as zero */
				j+=3;
				break;
			case '\t':
				/* Process medium gap between words: the value of next seven bit is kept as zero */
				j+=7;
				break;
			default:
				printf("ERROR\n");
				break;
		}
	}
    return j;
}
