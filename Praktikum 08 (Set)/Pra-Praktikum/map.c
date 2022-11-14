#include "map.h"

#define KEY(M, i) (M).Elements[(i)].Key
#define VALUE(M, i) (M).Elements[(i)].Value

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
{
	(*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M)
{
	return (M).Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M)
{
	return (M).Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
{
	int i = 0;
	boolean found = false;
	while (!found && i < M.Count)
	{
		if (KEY(M, i) == k)
		{
			found = true;
		}
		else
		{
			i += 1;
		}
	}
	if (found)
	{
		return VALUE(M, i);
	}
	else
	{
		return Undefined;
	}
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v)
{
	if (!IsMember(*M, k))
	{
		if (IsEmpty(*M))
		{
			KEY(*M, 0) = k;
			VALUE(*M, 0) = v;
		}
		else
		{
			KEY(*M, (*M).Count) = k;
			VALUE(*M, (*M).Count) = v;
		}
		(*M).Count += 1;
	}
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
		M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k)
{
	int i = 0;
	boolean found = false;
	while (!found && i < (*M).Count)
	{
		if (KEY(*M, i) == k)
		{
			found = true;
		}
		else
		{
			i += 1;
		}
	}
	if (found)
	{
		while (i < (*M).Count - 1)
		{
			KEY(*M, i) = KEY(*M, i + 1);
			VALUE(*M, i) = VALUE(*M, i + 1);
			i += 1;
		}
		(*M).Count -= 1;
	}
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
		element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k)
{
	int i = 0;
	boolean found = false;
	while (!found && i < (M).Count)
	{
		if (KEY(M, i) == k)
		{
			found = true;
		}
		else
		{
			i += 1;
		}
	}
	return found;
}
/* Mengembalikan true jika k adalah member dari M */
