// NIM: 18221162
// Nama: Ceavin Rufus De Prayer Purba
// Tanggal: 26 September 2022
// Topik Praktikum: List Statik
// Deskripsi: 

#include <stdio.h>
#include "MinMax.h"

#define BUFFER(T) T.A

List MinMax(List L){
	List output = MakeList();

	for (int i = 0; i<Length(L); i++){
	    BUFFER(output)[i] = BUFFER(L)[i];
	}

	// if (!IsEmpty(L)){
		
	    int min = BUFFER(output)[0];
	    int minIdx = 0;
	    for (int i=1; i<=LastIdx(output); i++){
	        if (BUFFER(output)[i] < min){
	            min = BUFFER(output)[i];
	            minIdx = i;
	        }
	    }

	    DeleteAt(&output, minIdx);

	    int max = BUFFER(output)[0];
		int maxIdx = 0;
	    for (int i=1; i<=LastIdx(output); i++){
	        if (BUFFER(output)[i] > max){
	            max = BUFFER(output)[i];
	            maxIdx = i;
	        }
	    }

	    DeleteAt(&output, maxIdx);

	    InsertLast(&output, min);
	    InsertLast(&output, max);

	// }
	return output;
}