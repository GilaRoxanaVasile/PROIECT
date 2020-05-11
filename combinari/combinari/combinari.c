#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, st[101], a[101], ok, k, suma, S;

int valid(int k)
{
	S = 0;
	for (int i = 1; i < k; i++)
	{
		S = S + a[st[i]];
		if (st[i] > st[k]) return 0;
	}
	if (S <= suma)
		return 1;
	return 0;
}

int solutie(int k)
{
	if (suma == S)
		return 1;
	return 0;
}

int afisare(int k)
{

	for (int j = 1; j < k; j++)
		printf("%d ", a[st[j]]);
	printf("\n");

}

void bkt(int k)
{

	for (int i = 1; i <= n; i++)
	{
		st[k] = i;
		if (valid(k) == 1)
			if (solutie(k))
			{
				afisare(k);
			}
			else bkt(k + 1);
	}
}
int main()
{
	printf("Dati suma: \n");
	scanf("%d", &suma);
	printf("Dati n: \n");
	scanf("%d", &n);
	printf("Dati cele n nr: \n");

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("\n");

	do {
		ok = 1;
		for (int i = 1; i < n; i++)
			if (a[i] > a[i + 1])
			{
				int aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				ok = 0;
			}
	} while (ok == 0);

	bkt(1);
	system("pause");
	return 0;
}