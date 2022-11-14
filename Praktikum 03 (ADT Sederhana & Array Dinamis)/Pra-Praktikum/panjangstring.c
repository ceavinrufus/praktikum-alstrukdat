#include <stdio.h>
#include "panjangstring.h"

int panjangString(char* a){
	int i = 0;
	while(a[i] != '\0'){
		i++;
	};

	return i;
};