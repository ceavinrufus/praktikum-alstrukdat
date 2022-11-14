#include "hashmap.h"

#define KEY(M, i) (M).Elements[(i)].Key
#define VALUE(M, i) (M).Elements[(i)].Value

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M){
	(*M).Count = Nil;
	for (int i = 0; i < MaxEl; i++)
	{
        	KEY(*M,i) = Undefined;
        	VALUE(*M,i) = Undefined;
    	}
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
	return K % MaxEl;
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k){
	int i = 0;
        boolean found = false;
        while (!found && i < MaxEl){
                if (KEY(M, i) == k){
                        found = true;
                } else {
                        i += 1;
                }
        }
        if (found){
		return VALUE(M, i);
        } else {
        	return Undefined;
        }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v){
	int idx, i = 0;
	boolean found;
	boolean isMember = false;
	while (i < MaxEl && !isMember) {
		if (KEY(*M, i) == k){
			isMember = true;
		} else {
			i += 1;
		}
	}

	if (!isMember){
		idx = Hash(k);
		while (KEY(*M, idx) != Undefined){
			idx = (idx + 1) % MaxEl;
		}
		KEY(*M, idx) = k;
		VALUE(*M, idx) = v;
		(*M).Count += 1;
	}
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */
