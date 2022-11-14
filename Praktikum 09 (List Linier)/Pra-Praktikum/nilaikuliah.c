#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

int main(){
	List nilai;
	boolean inputValid = true;
	int input;

	CreateEmpty(&nilai);

	while (inputValid){
		scanf("%d", &input);
		if (input >= 0 && input <= 100){
			InsVFirst(&nilai, input);
		} else {
			inputValid = false;
		}
	}

	if (NbElmt(nilai) > 0){
		printf("%d\n", NbElmt(nilai));
		printf("%d\n", Max(nilai));
		printf("%d\n", Min(nilai));
		printf("%.2f\n", Average(nilai));
		InversList(&nilai);
		PrintInfo(nilai);
		printf("\n");
		InversList(&nilai);
		PrintInfo(nilai);
		printf("\n");
	} else {
		printf("Daftar nilai kosong\n");
	}
	return 0;
}