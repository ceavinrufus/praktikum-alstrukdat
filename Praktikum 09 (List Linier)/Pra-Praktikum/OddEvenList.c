#include "OddEvenList.h"
#include <stdio.h>

void OddEvenList(List L, List *Odd, List *Even){
    CreateEmpty(Odd);
    CreateEmpty(Even);

    address p = First(L);

    while (p != Nil){

        if (Info(p) % 2 == 0){
            InsVLast(Even, Info(p));  
        } else{ 
            InsVLast(Odd, Info(p));
        }
        p = Next(p);
    } 

    infotype temp;
    address loc = First(*Odd), loc1;
          
    if (First(*Odd) != Nil) {  
        while(loc != Nil) {  
            loc1 = Next(loc);  
                  
            while(loc1 != Nil) {  
                if(Info(loc) > Info(loc1)) {  
                    temp = Info(loc);  
                    Info(loc) = Info(loc1);  
                    Info(loc1) = temp;  
                }  
                loc1 = Next(loc1);
            }  
            loc = Next(loc);  
        }      
    }

    loc = First(*Even);
    if (First(*Even) != Nil) {  
        while(loc != Nil) {  
            loc1 = Next(loc);  
                  
            while(loc1 != Nil) {  
                if(Info(loc) > Info(loc1)) {  
                    temp = Info(loc);  
                    Info(loc) = Info(loc1);  
                    Info(loc1) = temp;  
                }  
                loc1 = Next(loc1);
            }  
            loc = Next(loc);  
        }      
    }

    // PrintInfo(*Odd);
    // PrintInfo(*Even);
    // PrintInfo(L);
}

