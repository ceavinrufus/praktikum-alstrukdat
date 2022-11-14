#include <stdio.h>
#include "stack.h"

int main ()
{
	int X, c1, c2, c3, co, i = 1;
	Stack S;
	
	CreateEmpty (&S);
	scanf ("%dn", &X);
	while (i <= X)
	{
		if (i == 1)
		{
			Push (&S, 0);
		}
		else if (i == 2)
		{
			Push (&S, 1);
		}
		else
		{
			Pop (&S, &c1);
			Pop (&S, &c2);
			c3 = c1 + c2;
			Push (&S, c1);
			Push (&S, c3);
		}
		i++;
	}
	Pop (&S, &co);
	printf("%d\n", co);
}