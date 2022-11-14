#include <stdio.h>
#include "roman.h"

boolean IsRomanDigit(infotype X)
/* Mengirim true jika X adalah digit romawi I, V, X, L, C, D, atau M (case sensitive) */
{
	return ((X == 'I') || (X == 'V')|| (X == 'X') || (X == 'L') || (X == 'C') || (X == 'D') || (X == 'M'));
}
int RomanToDec(infotype X)
/* I.S. X adalah digit romawi yang dikenali */
/* F.S. Mengembalikan nilai desimal dari X */
{
	if (IsRomanDigit(X))
	{
		if (X == 'I')
		{
			return 1;
		}
		else if (X == 'V')
		{
			return 5;
		}else if (X == 'X')
		{
			return 10;
		}
		else if (X == 'D'){
			return 500;
		}else if (X == 'L')
		{
			return 50;
		}else if (X == 'C')
		{
			return 100;
		}
		else if (X == 'M')
		{
			return 1000;
		}else{
			return 0;
		}

	}else {return 0;}
}
int Decimal(Stack S)
/* Mengembalikan nilai desimal dari bilangan romawi R */
/* I.S. R berisi digit-digit romawi yang dikenali dengan susunan yang benar,
        digit paling atas adalah digit terakhir */
/* F.S. Mengembalikan nilai desimal dari bilangan romawi R */
{
	int Sum,bek;
	Sum = RomanToDec((S).T[S.TOP]);
	for (int i = S.TOP-1 ; i >= 1; i--)
	{
		if (RomanToDec((S).T[i]) >= RomanToDec((S).T[i+1])){
			Sum = Sum + RomanToDec(S.T[i]);
		} else if (RomanToDec((S).T[i]) < RomanToDec((S).T[i+1]))
		{
			Sum = Sum - RomanToDec(S.T[i]);
		}
	}
	return Sum;
}