#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return (First(L) == Nil && Last(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
	Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	address p;
	p = (address) malloc(sizeof(ElmtList));

	Info(p) = X;
	Next(p) = Nil;
	Prev(p) = Nil;

	return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address loc = First(L);
	boolean found = false;

	while (!found && loc != Nil){
		if (Info(loc) == X){
			found = true;
		} else {
			loc = Next(loc);
		}
	}

	return loc;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address el = Alokasi(X);

	if (el != Nil){
		InsertFirst(L, el);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address el = Alokasi(X);

	if (el != Nil){
		InsertLast(L, el);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	address P;
	DelFirst(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	Next(P) = First(*L);
	if (!IsEmpty(*L)){
		Prev(Next(P)) = P;
	} else {
		Last(*L) = P;
	}
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
	Prev(P) = Last(*L);
	if (!IsEmpty(*L)){
		Next(Prev(P)) = P;
	} else {
		First(*L) = P;
	}
	Last(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
	if (Prec == Last(*L)){
		InsertLast(L, P);
	} else {
		Next(P) = Next(Prec);
		Prev(Next(P)) = P;
		Next(Prec) = P;
		Prev(P) = Prec;
	}
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
	if (Succ == First(*L)){
		InsertFirst(L, P);
	} else {
		Prev(P) = Prev(Succ);
		Next(Prev(Succ)) = P;
		Prev(Succ) = P;
		Next(P) = Succ;
	}
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	*P = First(*L);

	if (First(*L) == Last(*L)){
		Last(*L) = Nil;
	} else {
		Prev(Next(*P)) = Nil;
	}
	First(*L) = Next(*P);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
	*P = Last(*L);

	if (First(*L) == Last(*L)){
		First(*L) = Nil;
	} else {
		Next(Prev(*P)) = Nil;
	}
	Last(*L) = Prev(*P);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
	address P = Search(*L, X);

	if (P != Nil){
		if (P == First(*L)){
			DelFirst(L, &P);
		} else {
			address prec = First(*L);
			while (Next(prec) != P){
				prec = Next(prec);
			}
			DelAfter(L, &P, prec);
		}
		Dealokasi(P);
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	if (Next(Prec) != Nil)
	{
		if (Next(Next(Prec)) == Nil){
			Last(*L) = Prec;
		} else {
			Prev(Next(*Pdel)) = Prec;
		}
		Next(Prec) = Next(*Pdel);
		Next(*Pdel) = Nil;
		Prev(*Pdel) = Nil;
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
	*Pdel = Prev(Succ);
	if (Prev(Succ) != Nil)
	{
		if (Prev(Prev(Succ)) == Nil){
			First(*L) = Succ;
		} else {
			Next(Prev(*Pdel)) = Succ;
		}
		Prev(Succ) = Prev(*Pdel);
		Next(*Pdel) = Nil;
		Prev(*Pdel) = Nil;
	}
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
	printf("[");
	if (!IsEmpty(L)){
		printf("%d", Info(First(L)));
	}

	address p = Next(First(L)); 
	while (p != Nil){
		printf(",%d", Info(p));
		p = Next(p);		
	}

	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
	printf("[");
	if (!IsEmpty(L)){
		printf("%d", Info(Last(L)));
	}

	address p = Prev(Last(L)); 
	while (p != Nil){
		printf(",%d", Info(p));
		p = Prev(p);
	}

	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
