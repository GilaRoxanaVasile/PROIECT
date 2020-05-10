#define _CRT_SECURE_NO_WARNINGS
#define NMAX 1000
#include <stdio.h>
#include <stdlib.h>

int puterile_lui_2(int x) //functie care calculeaza 2^x
{
	int p = 1;
	while (x != 0)
	{
		p = p * 2;
		x--;
	}
	return p;
}

int aproape(int x) //functie care gaseste cea mai apropiata puetre a lui doi mai mica decat x
{
	int nr = 1;
	do {
		if (nr > x) return nr / 2;
			else  nr * 2;
	} while (nr != x);
	return x;
}

int numar(int x, int y, int n, int nivelx,int nively)
{
	if (nivelx != 0 && nively != 0)
	{
		
	}
	return n;
}

int main()
{

	int n, i, q, x[NMAX], y[NMAX];

	scanf("%d", &n);
	scanf("%d", &q);

	for (i = 1; i <= q; i++)
	{
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
	}

	for (i = 1; i <= q; i++)
	{

		int nivelx = n - x[i];
		if (nivelx % 2 != 0) nivelx--;
		int lx = 0;
		while (nivelx != 0)
		{
			int nr = aproape(nivelx);
			lx = lx + puterile_lui_2(nr+1);
			nivelx = nivelx - nr;
		}
		
		int nively = n - y[i];
		if (nively % 2 != 0) nively--;
		int ly = 0;
		while (nively != 0)
		{
			int nr = aproape(nivelx);
			ly = ly + puterile_lui_2(nr);
			nively = nively - nr;
		}

		int FINAL = lx + ly;
		if (x[i] % 2 == 0 && y[i] % 2 != 0)  FINAL = FINAL + 1;
		else
			if (x[i] % 2 != 0 && y[i] % 2 == 0)  FINAL = FINAL + 2;
				else
				if (x[i] % 2 != 0 && y[i] % 2 != 0)  FINAL = FINAL + 3;

		printf("%d\n", FINAL);

	}

	system("pause");
	return 0;

}