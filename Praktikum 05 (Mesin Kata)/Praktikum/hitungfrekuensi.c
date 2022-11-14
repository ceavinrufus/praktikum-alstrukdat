// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 03/10/2022
// Topik: Mesin karakter dan kata
// Deskripsi: Nomor 1

#include "mesinkarakter.h"
#include <stdio.h>
#include <ctype.h>

char currentChar;

void cekTiga(int *count){
	if (tolower(currentChar) == 't'){
		ADV();
		cekTiga(count);
	} else {
		if (tolower(currentChar) == 'i'){
			ADV();
			if (tolower(currentChar) == 'g'){
				ADV();
				if (tolower(currentChar) == 'a'){
					ADV();
					*count = *count + 1;
				}
			}
		}
	}
}

int hitungfrekuensi(){
	START();
	int count = 0;
	while (!IsEOP()){
		cekTiga(&count);
		if (!IsEOP()){
			ADV();
		}
	}
	return count;
}