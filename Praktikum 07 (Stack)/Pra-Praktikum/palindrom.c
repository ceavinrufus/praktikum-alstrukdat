#include "stack.h"
#include <stdio.h>
#include "boolean.h"

int main(){
	int top_s1, bil, bil1, bil2, i=0;
	Stack S1, S2;
	boolean palindrom;

	CreateEmpty(&S1);
	CreateEmpty(&S2);

	scanf("%d", &bil);
	while (bil != 0){
		Push(&S1, bil);
		scanf("%d", &bil);
	}
	

	if (IsEmpty(S1)){
		printf("Stack kosong\n");
	} else {
		top_s1 = Top(S1);
		
		while (i <= top_s1/2){
			Pop(&S1, &bil);
			Push(&S2, bil);
			i++;
		}
		
		if (Top(S1) != Top(S2)){
			Pop(&S2, &bil);
		}
		
		palindrom = true;
		while (palindrom && !IsEmpty(S1)){
			Pop(&S1, &bil1);
			Pop(&S2, &bil2);
			palindrom = (bil1 == bil2);
		}

		if (palindrom){
			printf("Palindrom\n");
		} else {
			printf("Bukan Palindrom\n");
		}
	}

	return 0;
}