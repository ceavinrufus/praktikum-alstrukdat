#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER(arr) (arr).A
#define CAPACITY(arr) (arr).Capacity
#define NEFF(arr) (arr).Neff

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
	ArrayDin arr;

	BUFFER(arr) = (ElType*) malloc(InitialSize * sizeof(ElType));
	CAPACITY(arr) = InitialSize;
	NEFF(arr) = 0;

	return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
	free(BUFFER(*array));
	// CAPACITY(*array) = 0;
	// NEFF(*array) = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
	return NEFF(array) == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
	return NEFF(array);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
	return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
	return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    IdxType j;
    if (Length(*array)<(*array).Capacity){
        for (j=(*array).Neff;j>i;j--){
            (*array).A[j]=(*array).A[j-1];
        }
        (*array).A[i]=el;
        (*array).Neff+=1;
    }
    else {
        (*array).A=(ElType *) malloc (20 *sizeof(ElType));
        for (j=(*array).Neff;j>i;j--){
            (*array).A[j]=(*array).A[j-1];
        }
        (*array).A[i]=el;
        (*array).Neff+=1;
        (*array).Capacity*=2;
    }
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
	IdxType idx;
	for (idx=i; idx<Length(*array);idx++){
		(*array).A[idx] = (*array).A[idx+1]; 
	}
	NEFF(*array)--;
}
