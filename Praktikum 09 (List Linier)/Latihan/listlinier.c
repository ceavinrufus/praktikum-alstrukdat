#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return First(L) == Nil; 
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	address P;
	P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address P = First(L);
	boolean found = false;

	while (P != Nil && !found){
		if (Info(P) == X){
			found = true;
		} else{
			P = Next(P); 
		}
	}
	if (found){
		return P;
	} else {
		return Nil;
	}
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address P = Alokasi(X);

	if (P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address P = Alokasi(X);

	if (P != Nil){
		InsertLast(L, P);
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
	Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	address P;
	
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	Next(P) = First(*L);
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){

	if (IsEmpty(*L)){
		InsertFirst(L, P);
	} else {
		address last = First(*L);
		while (Next(last) != Nil){
			last = Next(last);
		}
		InsertAfter(L, P, last);
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	*P = First(*L);
	First(*L) = Next(*P);
	Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
	address P = Search(*L, X);

	if (P != Nil){
		if (P == First(*L)){
			DelFirst(L, &P);
		}
		else {
			address prec = First(*L);
			while (Next(prec) != P){
				prec = Next(prec);
			}
			DelAfter(L, &P, prec);
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
	address last = First(*L);
	address prec = Nil;

	while (Next(last) != Nil){
		prec = last;
		last = Next(last);
	}

	*P = last;
	if (prec == Nil){
		First(*L) = Nil; 
	} else {
		Next(prec) = Nil;
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	if (Next(Prec) != Nil){
		Next(Prec) = Next(Next(Prec));
		Next(*Pdel) = Nil;
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
	address P = First(L);

	if (IsEmpty(L)){
		printf("[]");
	} else {
		printf("[%d", Info(P));
		while (Next(P) != Nil){
			P = Next(P);
			printf(",%d", Info(P));
		}
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
	int banyak = 0;

	address P = First(L);

	while (P != Nil) {
		P = Next(P);
		banyak++;
	}
	return banyak;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
	address P = First(L);
	infotype max = Info(P);

	while (Next(P) != Nil) {
		P = Next(P);
		if (Info(P) > max){
			max = Info(P);
		}
	}

	return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L){
	address P = First(L);
	address addrMax = First(L);
	infotype max = Info(P);

	while (Next(P) != Nil) {
		P = Next(P);
		if (Info(P) > max){
			max = Info(P);
			addrMax = P;
		}
	}

	return addrMax;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L){
	address P = First(L);
	infotype min = Info(P);

	while (Next(P) != Nil) {
		P = Next(P);
		if (Info(P) < min){
			min = Info(P);
		}
	}

	return min;
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L){
	address P = First(L);
	address addrMin = First(L);
	infotype min = Info(P);

	while (Next(P) != Nil) {
		P = Next(P);
		if (Info(P) < min){
			min = Info(P);
			addrMin = P;
		}
	}

	return addrMin;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
	address P = First(L);
	int banyak = 0;
	float total = 0;

	while (P != Nil) {
		total += Info(P);
		banyak++;
		P = Next(P);
	}

	float avg = total/banyak;
	return (avg);
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
	address P = First(*L);
	address A = P;
	address B = Next(P);
	
	while (B != Nil) {
		A = B;
		B = Next(B);
		InsertFirst(L, A);
		Next(P) = B;
	}
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3){
	CreateEmpty(L3);
	address lastL1 = First(*L1);

	if (IsEmpty(*L1)){
		First(*L3) = First(*L2);
	} else {
		First(*L3) = First(*L1);
		while (Next(lastL1) != Nil){
			lastL1 = Next(lastL1);
		}
		Next(lastL1) = First(*L2);
	}
	CreateEmpty(L1);
	CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan 	L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void setElmt(List *L, int idx, infotype val){
    int ctr = 0;
	address p = First(*L);

    while (ctr < idx){
        p = Next(p);
    	ctr++;
	}
    Info(p) = val;
}

infotype getElmt(List L, int idx){
    int ctr = 0;
    address p = First(L);

    while (ctr < idx){
        p = Next(p);
        ctr++;
    }
    return Info(p);
}

void bubbleSort(List *L){
	// Membesar
	infotype temp;
	for (int i = 0; i < NbElmt(*L)-1; ++i)
    {
        for (int j = 0; j < NbElmt(*L) - i - 1; ++j)
        {
            if (getElmt(*L, j) > getElmt(*L, j+1)){
                temp = getElmt(*L, j);
                setElmt(L, j, getElmt(*L, j+1));
                setElmt(L, j+1, temp);
            }
        }
    }
}

boolean FSearch (List L, address P){
    address now = First(L);
    while (now != Nil){
        if (P == now){
            return true;
        }
        now = Next(now);
    }
    return false;
}

address SearchPrec (List L, infotype X){
    address s = Search(L, X);
    if (s != Nil){
        address P = First(L);
        while (P != Nil){
            if (Next(P) == s){
                return P;
            }
            P = Next(P);
        }
    }
    return Nil;
}

void DelAll (List *L){
    address pembuangan;
    address now = First(*L);
    while (now != Nil){
        DelFirst(L, &pembuangan);
        now = Next(now);
    }
    First(*L) = Nil;

    // Address P;

    // while (IsListEmpty(*L) == false) {
    //     DeleteFirst(L, &P);
    //     Dealokasi(&P);
    // }
}

void CopyList (List *L1, List *L2){
    First(*L2) = First(*L1);
}

List FCopyList (List L){
    List new;
    CreateEmpty(&new);

    boolean fail = false;
    address P = First(L);
    while (!fail && P != Nil){
        address c = Alokasi(Info(P));
        if (c == Nil){
            fail = true;
        } else {
            InsertLast(&new, c);
        }
        P = Next(P);
    }
    if (fail){
        DelAll(&new);
    }
    return new;
}

List FInversList (List L){
    List new = FCopyList(L);
    InversList(&new);
    return new;
}

void CpAlokList (List Lin, List *Lout){
    *Lout = FCopyList(Lin);
}

void PecahList (List *L1, List *L2, List L){
    CreateEmpty(L1);
    CreateEmpty(L2);
    int half = NbElmt(L)/2;
    int count = 0;
    address now = First(L);
    while (now != Nil){
        count++;
        address ins = Alokasi(Info(now));
        if (ins != Nil){
            if (count <= half){
                InsertLast(L1, ins);
            } else {
                InsertLast(L2, ins);
            }
        }
        now = Next(now);
    }
}

int CountX (List L, Infotype X, char sign)
/* Menghasilkan banyaknya elemen list L yang memenuhi persyaratan sbb:
 * -Jika sign adalah '>' maka dihasilkan banyaknya elemen yang lebih besar dari X
 * -JIka sign adalah '=' maka dihasilkan banyaknya bilangan yang sama dengan X
 * -Jika sign adalah '<' maka dihasilkan banyaknya elemen yang bernilai <X 
*/
//caranya pake counter kayak nbelmt, itung 1.1, if info(P) > lakukan dll
{
	int count;
    Address P;

    count = 0;
    P = First(L);
    while (P != Nil) {
		if (sign == '>') {
			if (Info(P) > X) {
				count++;
			}
		} else if (sign == '=') {
			if (Info(P) = X) {
				count++;
			}
		} else if (sign == '<') {
			if (Info(P) < X) {
				count++;
			}
		}
        P = Next(P);
    }
    return count;
}

void FilterList (List *L, Infotype X)
/* IS: L terdefinisi, mungkin kosong. X terdefinisi. */
/* FS: Semua elemen L dengan info bernilai X dihapus dan didealokasi dari list L. L mungkin menjadi kosong. */
// caranya, pake deleteP, cari P dengan search
{
	Address P;
	
	P= First(*L);
	while (P != Nil) {
		if (Info(P) == X) {
			DeleteP (L, X);
		}
		P= Next(P);
	}

}

void AscOrderList (List *L)
/* IS : L terdefinisi, tidak kosong */
/* FS: Elemen-elemen L terurut membesar */
//caranya: searchMin, lalu ganti first(L) = hasil dari searchmin,
//lalu kayakgitu seterusnya next(First(L))
{
	Address P;
	Infotype a;
	
	P= First(*L);
	while (P!= Nil) {
		a= Min(*L);
		DeleteAfter (L, &P, AdrMin(*L));
		Info(P) = a;
		P= Next(P);
	}

}

void SplitList (List L, List *LGenap, List *LGanjil) {
	Address P;
	
	CreateList(LGenap);
	CreateList(LGanjil);
	P = First(L);
	while (P!= Nil) {
		if (Info(P) % 2 == 0) {
			InsertLast(LGenap, P);
		} else if (Info(P) % 2 != 0) {
			InsertLast(LGanjil, P);
		}
		P = Next(P);
	}
}

boolean isSubList (List L1, List L) 
/* Menghasilkan true jika list L1 muncul sebagai sublist dari L. L1 merupakan sublist dari L bila L1 muncul pada L secara sekuensial.
 * Contoh: isSubList ([4,5,6], [3,4,5,6,7]) = true
 * 		   isSubList ([4,5,6], [3,4,1,5,6]) = false
 *         isSubList ([4,5,6], [4,5]) = false
 * 		   isSubList ([], [4,6,8]) = true
 *         isSubList ([], []) = true
*/
//caranya: setiap elemen disearch di L isboolean true, skali false langsung keluar
{
	Address P1, P;
	boolean subset;
	
	P1 = First(L1);
	P = First(L);
	subset= true;
	
	if (IsListEmpty(L1)) {
		subset= true;
	} else if (NbElmt(L1) > NbElmt(L)) {
		subset= false;
	} else {
		if (Search(L, Info(P1)) != Nil) {
			P= Search(L, Info(P1));
			while ((P1 != Nil) && (subset == true)) {
				if (Info(P1) ==  Info(P)) {
					subset= true;
					P= Next(P);
				} else if (Info(P1) !=  Info(P)) {
					subset= false;
				}
			}
		}
	}		
	return subset;
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    CreateEmpty(L3);

	address tempAdr;
	infotype temp;
	address CP;
	boolean stop = false;

    if (!(IsEmpty(L1))){
        CP = First(L1);
        while ((CP != Nil) && (!stop)){
			temp = Info(CP);
			tempAdr = Alokasi(temp);
			if (tempAdr != Nil){
				InsertLast(L3, tempAdr);
				CP = Next(CP);
			}
			else {
				DelAll(L3);
				stop = true;
			}
		}

		CP = First(L2);
        while ((CP != Nil) && (!stop)){
			temp = Info(CP);
			tempAdr = Alokasi(temp);
			if (tempAdr != Nil){
				InsertLast(L3, tempAdr);
				CP = Next(CP);
			}
			else {
				DelAll(L3);
				stop = true;
			}
		}
    }
    else{
		CP = First(L2);
        while ((CP != Nil) && (!stop)){
			temp = Info(CP);
			tempAdr = Alokasi(temp);
			if (tempAdr != Nil){
				InsertLast(L3, tempAdr);
				CP = Next(CP);
			}
			else {
				DelAll(L3);
				stop = true;
			}
		}
    }
}
