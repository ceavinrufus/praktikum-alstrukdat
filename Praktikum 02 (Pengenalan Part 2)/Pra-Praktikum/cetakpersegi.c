#include <stdio.h>

int main(){
	int i, j, n, sisi;

	scanf("%d", &n);

	sisi = 2*n - 1;

	for (i=0; i<sisi; i++){
		for (j=0; j<sisi; j++){
			if ((i+j) % 2 == 1){
				printf("X");
			} else {
				printf("O");
			};
		};
		printf("\n");
	};

	return 0;
}