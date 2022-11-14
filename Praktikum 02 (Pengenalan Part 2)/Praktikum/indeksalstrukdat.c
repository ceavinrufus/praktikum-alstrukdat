#include <stdio.h>

int main(){
	int bil, total = 0, count = 0, lulus = 0;
	float rerata=0.0;
	char indeks;

	scanf("%d", &bil);

	while(bil != -999){
		if (bil >= 0 && bil <= 4){
			total += bil;
			count++;
			if (bil >= 3){
				lulus += 1;
			}
		}
		scanf("%d", &bil);
	}

	if (count == 0){
		printf("Tidak ada data\n");
	} else {
		rerata = (float) total/count;
		printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
		printf("Nilai rata-rata = %.2f\n", rerata);	
		(rerata == 4) ? indeks = 'A' : (rerata >= 3 && rerata < 4) ? indeks = 'B' : (rerata >= 2 && rerata < 3) ? indeks = 'C' : (rerata >= 1 && rerata < 2) ? indeks = 'D' : (indeks = 'E');
		printf("Indeks akhir kelas = %c\n", indeks);
	}
	

	return 0;
}