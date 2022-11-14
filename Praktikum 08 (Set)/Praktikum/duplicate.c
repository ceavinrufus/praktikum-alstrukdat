// NIM: 18221162
// Nama: Ceavin Rufus De Prayer Purba
// Tanggal: 31/10/2022
// Topik: Set, Map, dan Hash
// Deskripsi: Nomor 1

#include <stdio.h>
#include "duplicate.h"

/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize){
	Set S;
	CreateEmpty(&S);
	for (int i = 0; i < arrSize; ++i)
	{
		Insert(&S,arr[i]);

	}
	return S;
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize){
	Set S;
	int temp;
	S = arrToSet(arr, arrSize);
	for (int i = 0; i < S.Count; ++i)
	{
		arrRes[i] = S.Elements[i];
	}
	(*arrResSize) = S.Count;


	for (int i = 0; i < (*arrResSize)-1; ++i)
	{
		for (int j = 0; j < (*arrResSize) - i - 1; ++j)
		{
			if (arrRes[j] < arrRes[j+1]){
				temp = arrRes[j];
				arrRes[j] = arrRes[j+1];
				arrRes[j+1]=temp;
			}
		}
	}
}
