// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 7 November 2022
// Topik: List Linier
// Deskripsi: Nomor 2

#include <stdio.h>
#include "listlinier.h"
#include "boolean.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype banyak, el, el2;
    scanf("%d", &banyak);

    if (banyak == 0) {
        PrintInfo(fibonacci);
        return 0;
    } else if (banyak == 1) {
    	scanf("%d", &el);
    	InsVFirst(&fibonacci, el);
        PrintInfo(fibonacci);
        return 0;
    } else {
    	int jumlah;
    	scanf("%d", &el);
    	scanf("%d", &el2);
    	InsVLast(&fibonacci, el);
    	InsVLast(&fibonacci, el2);
    	for (int i = 2; i < banyak; ++i)
    	{
    		jumlah = el + el2;
    		el = el2;
    		el2 = jumlah;
    		InsVLast(&fibonacci, el2);
    	}
        PrintInfo(fibonacci);
    }

    return 0;
}