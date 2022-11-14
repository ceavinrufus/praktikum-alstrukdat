#include<stdio.h>
#include<stdlib.h>
#include"RR.h"
/* Prototype manajemen memori */
void Alokasi (address *P, infotype X,Priority Y){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
    *P=(address)malloc(sizeof(ElmtQueue));
    if(*P!=Nil){
        Info(*P)=X;
        Prio(*P)=Y;
        Next(*P)=Nil;
    }
}
void Dealokasi (address  P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
    free(P);
}
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
    return Head(Q)==Nil;
}
int NbElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
    int count=0;
    if(!IsEmpty(Q)){
        address P=Head(Q);
        while (P!=Nil){
            count+=1;
            P=Next(P);
        }
    }
    return count;
}
/*** Kreator ***/
void CreateEmpty(Queue * Q){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
    Head(*Q)=Nil;
}
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X, Priority Y){
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
    address P;
    Alokasi(&P,X,Y);
    if(P!=Nil){
        if (IsEmpty(*Q)){
            Head(*Q)=P;
        }
        else{
            address now=Head(*Q),prec=Nil;
            while((now!=Nil)&&(Prio(now)<Prio(P))){
                prec=now;
                now=Next(now);
            }
            if(prec==Nil){
                Next(P)=Head(*Q);
                Head(*Q)=P;
            }
            else{
                Next(P)=Next(prec);
                Next(prec)=P;
            }
            
        }
    }
}
void Del(Queue * Q, infotype * X){
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
    address P=Head(*Q);
    *X=Info(P);
    Head(*Q)=Next(Head(*Q));
    Next(P)=Nil;
    Dealokasi(P);
}
void PrintInfo(Queue Q){
    printf("[");
    if (!IsEmpty(Q)){
        address P=Head(Q);
        while (P!=Nil){
            if (Next(P)==Nil){
                printf("%d",Info(P));
            }
            else{
                printf("%d,",Info(P));
            } 
            P=Next(P);  
        }
    }
    printf("]");
}
void CheckPrio(Queue Q){
    printf("[");
    if (!IsEmpty(Q)){
        address P=Head(Q);
        while (P!=Nil){
            if (Next(P)==Nil){
                printf("%d",Prio(P));
            }
            else{
                printf("%d,",Prio(P));
            } 
            P=Next(P);  
        }
    }
    printf("]");
}

boolean Search(Queue Q, infotype X){
    boolean check=false;
    if (!IsEmpty(Q)){
        address P=Head(Q);
        boolean stop=false;
        while(P!=Nil){
            if ((Info(P)==X)&&(!stop)){
                check=true;
                stop=true;
            }
            P=Next(P);
        }
    }
    return check;
}
int Urutan (Queue Q, infotype X){
    int count=1;
    if (Search(Q,X)){
        address P=Head(Q);
        while(Info(P)!=X){
            count+=1;
            P=Next(P);
        }
    }
    else{
        count=-999;
    }
    return count;
}