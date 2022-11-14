#include <stdio.h>
#include "hitungkarakter.h"

char currentChar;
boolean EOP;

int hitungkarakter(char karakter){
	START();
	int count = 0;
	while (!IsEOP()) {
		if (GetCC() == karakter) {
			count += 1;
		}
		ADV();
	}
	return count;
}