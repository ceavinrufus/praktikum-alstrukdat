#include <stdio.h>

int main(){
	long int bil, jumlah;

	scanf("%ld", &bil),

	jumlah = 0;

	while (bil != 0){
		jumlah = jumlah + bil - (bil/10) * 10;
		bil = (bil/10);
	}

	printf("%ld\n", jumlah);
	return 0;
}