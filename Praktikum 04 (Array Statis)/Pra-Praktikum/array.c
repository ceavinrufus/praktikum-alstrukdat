#include <stdlib.h>
#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
#define BUFFER(arr) (arr).TI
#define NEFF(arr) (arr).Neff

/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
void MakeEmpty (TabInt *T){
    NEFF(*T) = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int NbElmt (TabInt T){ 
    return NEFF(T);
}

/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
int MaxNbEl (TabInt T){
    return IdxMax-IdxMin+1;
}


/* *** Selektor INDEKS *** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetFirstIdx (TabInt T){
    return IdxMin;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
IdxType GetLastIdx (TabInt T){
    return NEFF(T);
}

/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
ElType GetElmt (TabInt T, IdxType i){
    return BUFFER(T)[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetTab (TabInt Tin, TabInt *Tout){
    MakeEmpty(Tout);
    for (int i = IdxMin; i <= GetLastIdx(Tin); i++){
        BUFFER(*Tout)[i] = BUFFER(Tin)[i];
    }
    NEFF(*Tout) = NEFF(Tin);
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetEl (TabInt *T, IdxType i, ElType v){
    BUFFER(*T)[i] = v;
    if (i > GetLastIdx(*T)){
        NEFF(*T)++;
    }
}


/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
void SetNeff (TabInt *T, IdxType N){
    NEFF(*T) = N;
}

/* ********** Test Indeks yang valid ********** */
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxValid (TabInt T, IdxType i){
    return IdxMax >= i && IdxMin <= i;
}

/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
boolean IsIdxEff (TabInt T, IdxType i){
    return NEFF(T) >= i && IdxMin <= i;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
boolean IsEmpty (TabInt T){
    return NEFF(T) == 0;
}

/* *** Test tabel penuh *** */
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
boolean IsFull (TabInt T){
    return NEFF(T) == IdxMax;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
void TulisIsi (TabInt T){
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    }
    for (int i=IdxMin; i <= NbElmt(T); i++){
        printf("%d:%d\n", i, BUFFER(T)[i]);
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
TabInt PlusTab (TabInt T1, TabInt T2){
    TabInt T3;
    MakeEmpty(&T3);
    for (int i=IdxMin; i<=NEFF(T1); i++){
        BUFFER(T3)[i] = BUFFER(T1)[i] + BUFFER(T2)[i];
    }
    NEFF(T3) = NEFF(T1);
    return T3;
}

/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
TabInt MinusTab (TabInt T1, TabInt T2){
    TabInt T3;
    MakeEmpty(&T3);
    for (int i=IdxMin; i<=NEFF(T1); i++){
        BUFFER(T3)[i] = BUFFER(T1)[i] - BUFFER(T2)[i];
    }
    NEFF(T3) = NEFF(T1);
    return T3;
}

/* ********** NILAI EKSTREM ********** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMax (TabInt T){
    ElType max = BUFFER(T)[IdxMin];
    for (int i=IdxMin+1; i<=NbElmt(T); i++){
        if (BUFFER(T)[i] > max){
            max = BUFFER(T)[i];
        }
    }
    return max;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
ElType ValMin (TabInt T){
    ElType min = BUFFER(T)[IdxMin];
    for (int i=IdxMin+1; i<=NbElmt(T); i++){
        if (BUFFER(T)[i] < min){
            min = BUFFER(T)[i];
        }
    }
    return min;
}


/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
IdxType IdxMaxTab (TabInt T){
    ElType max = BUFFER(T)[IdxMin];
    IdxType idx = IdxMin;

    for (int i=IdxMin+1; i<=NbElmt(T); i++){
        if (BUFFER(T)[i] > max){
            max = BUFFER(T)[i];
            idx = i;
        }
    }
    return idx;
}

/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
IdxType IdxMinTab (TabInt T){
    ElType min = BUFFER(T)[IdxMin];
    IdxType idx = IdxMin;

    for (int i=IdxMin+1; i<=NbElmt(T); i++){
        if (BUFFER(T)[i] < min){
            min = BUFFER(T)[i];
            idx = i;
        }
    }
    return idx;
}