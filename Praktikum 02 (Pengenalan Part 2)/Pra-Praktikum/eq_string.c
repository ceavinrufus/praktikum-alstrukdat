#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
	char i, str1[100], str2[100], selisih;
	bool same;

	scanf("%s", str1);
	scanf("%s", str2);

	same = true;

	if (strlen(str1) == strlen(str2)){
		for (i=0; i<strlen(str1); i++){
			if (str2[i] > str1[i]){
				selisih = str2[i] - str1[i];
			} else {
				selisih = str1[i] - str2[i];
			}
			if (!(selisih == 0) && !(selisih == 32)){
				same = false;
			}
		};
	} else {
		same = false;
	};

	if (same){
		printf("Ya\n");
	} else {
		printf("Tidak\n");
	}
	return 0;
}