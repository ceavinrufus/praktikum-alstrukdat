#include <stdio.h>


int faktorial(int bilangan){
	int i, faktorial = 1;

	for (i=1; i<=bilangan; i++){
		faktorial = faktorial * i;
	};
	return faktorial;
}

int main(){
	int k, bil, asli, faktorial2;

	scanf("%d", &bil);

	asli = bil;
	k = 10;
	faktorial2 = 0;

	while (bil/k != 0){
		faktorial2 = faktorial2 + faktorial(bil - (bil/k)*10);
		bil = bil/k;
	};

	faktorial2 = faktorial2 + faktorial(bil);

	if (faktorial2 == asli){
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}