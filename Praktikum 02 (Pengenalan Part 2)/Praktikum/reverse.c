#include <stdio.h>

int main(){
	int bil, reversed = 0;

	scanf("%d", &bil);

	while (bil != 0){
		reversed = reversed*10 + (bil % 10);
		bil = (bil - (bil % 10)) / 10;
	}
	printf("%d\n", reversed);
	return 0;
}