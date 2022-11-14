#include <stdio.h>
#include <string.h>

int main(){
	int i;
	char kata[10];
	char frekuensi[10] = {0,0,0,0,0,0,0,0,0,0};

	scanf("%s", kata);

	for (i=0; i<=strlen(kata); i++){
		if (kata[i] == '0'){
			frekuensi[0]++;			
		} else if (kata[i] == '1'){
			frekuensi[1]++;			
		} else if (kata[i] == '2'){
			frekuensi[2]++;			
		} else if (kata[i] == '3'){
			frekuensi[3]++;			
		} else if (kata[i] == '4'){
			frekuensi[4]++;			
		} else if (kata[i] == '5'){
			frekuensi[5]++;			
		} else if (kata[i] == '6'){
			frekuensi[6]++;			
		} else if (kata[i] == '7'){
			frekuensi[7]++;			
		} else if (kata[i] == '8'){
			frekuensi[8]++;			
		} else if (kata[i] == '9'){
			frekuensi[9]++;			
		}
			
	}

	for (i=0; i<10; i++){
		printf("%d", frekuensi[i]);
	};

	printf("\n");
	return 0;
}