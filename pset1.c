#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int num, int p)
{
	int ans = 1;
	int i;
	for(i=0; i<p; i++)
	{
		ans *= num;
	}
	return ans;
}

char * karatsuba(char * num1, char * num2, int n)
{		
	char a[n/2+1], b[n/2+1], c[n/2+1], d[n/2+1];

	/*pn = power(10,(n));
	pn2 = power(10,(n/2)) ;
	*/

	for(i=0; i<(n/2); i++)
		a[i] = num1[i];
	a[++i] = "\0";

	for(i=(n/2); i<n; i++)
		b[i] = num1[i];
	b[++i] = "\0";

	for(i=0; i<(n/2); i++)
		c[i] = num2[i];
	c[++i] = "\0";

	for(i=(n/2); i<(n); i++)
		d[i] = num2[i];
	d[++i] = "\0";

	
	int length = strlen(num1);
	char * ans = "0";

	if(length < 3)
	{
		int n = atoi(num1), m = atoi(num2);
		sprintf(ans, "%d", n*m);
		return ans;

	}
	else
	{
		char * ac = karatsuba(a,c,n/2);
		char * bd = karatsuba(b,d,n/2);
		char * ad = karatsuba(a,d,n/2);
		char * bc = karatsuba(b,c,n/2);

	return (pn*ac + pn2*adbc + bd);

	}
}

int main(void)
{
	char num1[] = "12345678";
	char num2[] = "12345678";
	int length = strlen(num1);
	char * num3 = karatsuba(num1, num2, length);
	printf("%s\n", num3);

	return 0;
}





























