// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 17 Oktober 2022
// Topik: Queue
// Deskripsi: Nomor 1

#include "boolean.h"
#include <stdio.h>
#include "queue.h"

Queue tanpaBomb(Queue queue, ElType bomb){
	for (int i = 0; i < length(queue); i++){
		ElType val;
		dequeue(&queue, &val);
		if (val != bomb){
			enqueue(&queue, val);
		}
	}
	return queue;
}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/

