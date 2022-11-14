/* Tuliskan header di sini berisi nama, dll */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
	address p = First(L);

	int idx = 0;
	while (idx < r){
		p = Next(p);
		idx = idx + 1;
	}

	return Info(p);

}

int main () {
	List L;
	int r;

	scanf("%d", &r);
	while (r){
		InsVLast(&L, r);
		scanf("%d", &r);
	}

	scanf("%d", &r);
	if (!IsEmpty(L)){
		printf("%d\n", ElemenKeN(L, r));
	} else {
		printf("List Kosong\n");
	}
	return 0;
}