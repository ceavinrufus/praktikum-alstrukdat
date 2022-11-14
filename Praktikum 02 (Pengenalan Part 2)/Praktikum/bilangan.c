#include <stdio.h>

int ada7(int bil){
	int temp = bil;
	while (bil != 0){
		if (bil % 10 == 7){
			return temp;
		}
		bil = bil / 10;
	}
}

int main(){
	int M, N, jumlah, i, j;

	scanf("%d", &N);
	for (i=0; i < N; i++){
		scanf("%d", &M);
		jumlah = 0;
		for (j=1; j <= M; j++){
			if (j % 7 == 0){
				jumlah += j;
			} else {
				jumlah += ada7(j);
			}
		}
		printf("%d\n", jumlah);
	}

	return 0;
}