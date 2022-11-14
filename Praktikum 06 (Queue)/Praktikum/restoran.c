// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 17 Oktober 2022
// Topik: Queue
// Deskripsi: Nomor 3

#include "boolean.h"
#include "queue.h"
#include <stdio.h>


int cariMin(Queue queue){
	if (!isEmpty(queue)){
		int min = HEAD(queue);
		for (int i = 0; i < length(queue); i++){
			ElType val;
			dequeue(&queue, &val);
			if (val < min){
				min = val;
			}
			enqueue(&queue, val);
		}
		return min;
	} else{
		return 0;
	}
	
}

int main(){
	int angka, waktu, min = 0, max = 0, pesanan = 0;
	Queue layanan, selesai;
    CreateQueue(&layanan);
    CreateQueue(&selesai);

	scanf("%d",&angka);

	if (angka != 0){
		while (angka != 0){
			pesanan = 0;
			if (angka == 1){
				scanf("%d", &waktu);
				if (waktu > 0){
					enqueue(&layanan, waktu);
				}
			} else if (angka == 2){
				if (!isEmpty(layanan)){
					dequeue(&layanan, &pesanan);
				}
				if (pesanan != 0){
					enqueue(&selesai, pesanan);
					if (pesanan > max){
						max = pesanan;
					}
				}
				
			}
			scanf("%d",&angka);
		}
	}

	printf("%d\n", length(selesai));
	printf("%d\n", (cariMin(selesai)));
	printf("%d\n", (max));


	return 0;
}