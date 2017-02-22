#include "selfprot.h"
#include "stdio.h"

#define toString(s) (s==OK?"OK":(s==HIGH_ACCELERATION?"HIGH ACCELERATION":(s==HIGH_TEMP?"HIGH TEMP":"HIGH ACCELERATION AND TEMP")))

const char *EXPECTED_OUTPUT =	"OK\n"
								"- - -/- . -\n"
								"... ... ...   ... . ...\n"
								"\n"
								"HIGH TEMP\n"
								". . . ./. ./- - ./. . . .	-/./- -/. - - .\n"
								". . . .   . .   ... ... .   . . . .       ...   .   ... ...   . ... ... .\n"
								"\n"
								"HIGH ACCELERATION\n"
								". . . ./. ./- - ./. . . .	. -/- . - ./- . - ././. - . ././. - ./. -/-/. ./- - -/- .\n"
								". . . .   . .   ... ... .   . . . .       . ...   ... . ... .   ... . ... .   .   . ... . .   .   . ... .   . ...   ...   . .   ... ... ...   ... .\n"
								"\n"
								"HIGH ACCELERATION AND TEMP\n"
								". . . ./. ./- - ./. . . .	. -/- . - ./- . - ././. - . ././. - ./. -/-/. ./- - -/- .	. -/- ./- . .	-/./- -/. - - .\n"
								". . . .   . .   ... ... .   . . . .       . ...   ... . ... .   ... . ... .   .   . ... . .   .   . ... .   . ...   ...   . .   ... ... ...   ... .       . ...   ... .   ... . .       ...   .   ... ...   . ... ... .";
char GENERATED_OUTPUT[846] =	{""};

void test(float acc_x, float acc_y, float acc_z, unsigned int light);

int main() {
	int testOk = 0;
    test(0,0,0,0);      /* OK */
    strcat(GENERATED_OUTPUT, "\n\n");
    test(0,0,1,35);    /* HIGH TEMP */
    strcat(GENERATED_OUTPUT, "\n\n");
    test(5,0,0,0);      /* HIGH ACCELERATION */
    strcat(GENERATED_OUTPUT, "\n\n");
    test(2,2,2,40);    /* HIGH ACCELERATION AND TEMP */
    testOk = (strcmp(EXPECTED_OUTPUT, GENERATED_OUTPUT)==0);
    printf("TEST: %s\n", (testOk?"OK":"FAILED"));
    if(!testOk) {
    	printf("Expected:\n%s\n", EXPECTED_OUTPUT);
    	printf("Generated:\n%s\n", GENERATED_OUTPUT);
    }
}

void test(float acc_x, float acc_y, float acc_z, unsigned int light) {
    EnvironmentData ed;
    char word[250] = {""};
    char morseWord[250] = {""};
    char morseBin[32] = {""};
    int numOfUsedBits;
    int i;

    ed = CreateEnvironmentData(acc_x, acc_y, acc_z, light);
    CalculateSystemState(&ed);
    strcpy(word, toString(ed.state));
    strcat(GENERATED_OUTPUT, word);
    strcat(GENERATED_OUTPUT, "\n");
    CharToMorse(word, morseWord);
    strcat(GENERATED_OUTPUT, morseWord);
    strcat(GENERATED_OUTPUT, "\n");
    numOfUsedBits = MorseToBinary(morseWord, morseBin);
    for(i=0;i<32 && i<numOfUsedBits;i++) {
    	int j;
    	for(j=0;j<sizeof(char)*8 && (i*((sizeof(char)*8))+j)<numOfUsedBits;j++) {
    		strcat(GENERATED_OUTPUT, ((morseBin[i]>>(sizeof(char)*8-j-1)&1)?".":" "));
    	}
    }
}
