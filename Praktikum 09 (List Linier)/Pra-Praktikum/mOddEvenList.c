#include <stdio.h>
#include "OddEvenList.h"

int main(){
	List L, Odd, Even;
	boolean inputValid = true;
	int input;

	CreateEmpty(&L);
	CreateEmpty(&Odd);
	CreateEmpty(&Even);

	while (inputValid){
		scanf("%d", &input);
		if (input >= 0 && input <= 100){
			InsVLast(&L, input);
		} else {
			inputValid = false;
		}
	}

	OddEvenList(L, &Odd, &Even);

	return 0;
}
