// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 7 November 2022
// Topik: List Linier
// Deskripsi: Nomor 3

#include "removeDuplicate.h"
#include <stdlib.h>

List removeDuplicate(List l){
	List unique;
	address p = First(l);
	infotype temp;

	CreateEmpty(&unique);
	InsVLast(&unique, Info(p));

	while (Next(p) != Nil){
		temp = Info(p);
		p = Next(p);
		if (Info(p) != temp){
			InsVLast(&unique, Info(p));
		}
	}
	return unique;
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/