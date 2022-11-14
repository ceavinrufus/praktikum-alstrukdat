// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 7 November 2022
// Topik: List Linier
// Deskripsi: Nomor 1

#include "listlinier.h"
#include <stdio.h>

int main()
{
	int n, x;
	List L;
	address P;
	scanf("%d", &n);
	CreateEmpty(&L);
	for (int i = 0; i < n; ++i)
	{
		P = Alokasi(n - i);
		InsertFirst(&L, P);
	}

	int sum;
	scanf("%d", &sum);
	for (int i = 0; i < sum; ++i)
	{
		scanf("%d", &x);
		P = Search(L, x);
		if (P != Nil)
		{
			DelP(&L, x);
			P = Alokasi(x);
			InsertFirst(&L, P);
			printf("hit ");
			PrintInfo(L);
			printf("\n");
		}
		else
		{
			DelLast(&L, &P);
			P = Alokasi(x);
			InsertFirst(&L, P);
			printf("miss ");
			PrintInfo(L);
			printf("\n");
		}
	}
}