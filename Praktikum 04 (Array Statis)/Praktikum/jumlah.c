// NIM: 18221162
// Nama: Ceavin Rufus De Prayer Purba
// Tanggal: 26 September 2022
// Topik Praktikum: List Statik
// Deskripsi: 

#include <stdio.h>
// #include 

int main(){
	int N, q, l, r, i, j, count;
	scanf("%d", &N);
	int arr[N];

	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}

	scanf("%d", &q);
	for (i = 0; i<q; i++){
		count = 0;
		scanf("%d %d", &l, &r);

		for (j = l-1; j < r; j++){
			count += arr[j%N];
		}

		printf("%d\n", count);
	}

}