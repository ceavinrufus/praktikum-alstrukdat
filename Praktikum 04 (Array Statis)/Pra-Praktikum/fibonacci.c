#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result){
	int n1 = 1, n2 = 1;

	if (n == 0 || n == 1){
		*result = 1;
	}
	else {	
		for (int i=2; i<=n; i++){
			*result = n1 + n2;
			n1 = n2;
			n2 = *result;
		}
	}
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n){
	int result=0;
	fibonacci1(n, &result);

	return result;
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result){
	int n1 = 1, n2 = 1, temp = 0;
	
	if (n == 0){
		(result)[0] = 1;
	} else if (n == 1){
		(result)[0] = 1;
		(result)[1] = 1;
	} else {
		result[0] = 1;
		result[1] = 1;

		for (int i=2; i<=n; i++){
			temp = n1 + n2;
			(result)[i] = temp;
			n1 = n2;
			n2 = temp;
		}	
	}
}
