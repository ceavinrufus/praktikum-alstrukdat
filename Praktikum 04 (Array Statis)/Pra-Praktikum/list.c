#include "list.h"
#include <stdio.h>
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
List MakeList(){
    List L;
    for (int i=0; i<MaxEl;i++){
        L.A[i] = Mark;
    }
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
boolean IsEmpty(List L){
    return L.A[0] == Mark; 
}

/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
ElType Get(List L, IdxType i){
    return L.A[i];
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
void Set(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
int Length(List L){
    int i = 0;
    while (L.A[i] != Mark){
        i++;
    }
    return i;
}

/* *** Selektor INDEKS *** */
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType FirstIdx(List L){
    return 0;
}

/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
IdxType LastIdx(List L){
    return Length(L) - 1;
}

/* ********** Test Indeks yang valid ********** */
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
boolean IsIdxValid (List L, IdxType i){
    return i < MaxEl && i >= FirstIdx(L);
}

/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
boolean IsIdxEff (List L, IdxType i){
    return i <= LastIdx(L) && i >= FirstIdx(L); 
}

/* ********** Operasi-operasi ********** */
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
boolean Search(List L, ElType X){
    IdxType i;
    boolean found;

    i = 0;
    found = false;

    do{
        if (L.A[i] == X){
            found = true;
        }
        else{
            i++;
        }

    } while ((found == 0) && (i<=LastIdx(L)));
    return found;
}

/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
void InsertFirst(List *L, ElType X){
    if (IsEmpty(*L)) {
        (*L).A[0] = X;
    } else {
        InsertAt(L, X, 0);
    }
}

/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertAt(List *L, ElType X, IdxType i){
    for (int j = Length(*L); j > i; j--){
        (*L).A[j] = (*L).A[j-1];
    }
    (*L).A[i] = X;
}

/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
void InsertLast(List *L, ElType X){
    if (IsEmpty(*L)){
        (*L).A[0] = X;
    } else {
        (*L).A[LastIdx(*L)+1] = X;
    }
}

/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
void DeleteFirst(List *L) {
    DeleteAt(L, 0);
}

/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
void DeleteAt(List *L, IdxType i){
    for (int idx=i; idx<LastIdx(*L);idx++){
        (*L).A[idx] = (*L).A[idx+1]; 
    }
    (*L).A[LastIdx(*L)] = Mark;
}

/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
void DeleteLast(List *L){
    (*L).A[LastIdx(*L)] = Mark;
}

/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
List Concat(List L1, List L2){
    List L3 = MakeList();

    for (int i = 0; i < Length(L1); i++){
        InsertLast(&L3, L1.A[i]);
    }
    for (int j=0; j < Length(L2); j++){
        InsertLast(&L3, L2.A[j]);
    }

    return L3;
}

