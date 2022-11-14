#include <stdlib.h>
#include "boolean.h"
#include "node.h"
#include "list_linked.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    Address p;
    int ctr;
    p = l;
    ctr = 0;
    while (ctr < idx){
        ctr++;
        p = NEXT(p);
    }

    return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address p;
    int ctr;
    p = *l;
    ctr = 0;
    while (ctr < idx){
        ctr++;
        p = NEXT(p);
    }
   INFO(p) = val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address p;
    int ctr;
    boolean flag;

    p = l;
    ctr = 0;    
    flag = false;
    while (p != NULL && !flag){
        if (INFO(p) == val){
            flag = true;
        } else {
            ctr++;
            p = NEXT(p);
        }
    }

    if (flag){
        return ctr;
    } else {
        return IDX_UNDEF;
    }

}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address p;
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address p;
        p = newNode(val);
        if (p != NULL) {
            Address last;
            last = *l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address p;
        p = newNode(val);
        if (p != NULL) {
            int ctr; Address loc;
            loc = *l;
            ctr = 0;
            while (ctr < idx-1){
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address p;
    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address p, loc;
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        *l = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    if (idx == 0){
        deleteFirst(l, val);
    } else {
        int ctr; Address loc;
        ctr = 0;
        loc = *l;
        while (ctr < idx-1){
            ctr++;
            loc = NEXT(loc);
        }
        Address p;
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (isEmpty(l)){
        printf("[]");
    } else {
        Address p = l;
        printf("[%d", INFO(p));
        p = NEXT(p);
        while (p != NULL){
            printf(",%d", INFO(p));
            p = NEXT(p);
        }
        printf("]");
    }
}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int len; Address p;
    len = 0;
    p = l;
    while (p != NULL){
        len++;
        p = NEXT(p);
    }
    return len;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    Address p; List l3;
    CreateList(&l3);

    p = l1;
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = l2;
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}