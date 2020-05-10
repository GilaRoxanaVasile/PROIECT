#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>
#include <stdlib.h>


int bk(int rest)
{
	int sol[10] = { 0 };
	int nr = 0;
	int s = 0;
	while (s < rest)
	{
		s+=v[]
	}
}

int main()
{
	int n, l, v[MAX], ok, suma=0, rest;

	FILE *fr;
	fr = fopen("in.txt", "rt");

	if (fr == NULL)
	{
		printf("Eroare deschidere fisier in.txt!\n");
		exit(1);
	}

	fscanf(fr, "%d %d", &l, &n);

	for (int i = 1; i <= n; i++)
	{
		fscanf(fr, "%d", &v[i]);
		suma = suma + v[i]; 
	}

	fclose(fr);

	rest = l - suma; //cum fiecare reper trebuie folosit macar o data, rezulta ca trebuie sa gasim combinatiile de repere care 'completeaza' restul barei

	do {
		ok = 1;
		for (int i = 1; i < n; i++)
			if (v[i] > v[i + 1])
			{
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ok = 0;
			}
	} while (ok == 0);

	if (rest == 0)
		afisare();
	for (int i = 1; i <= n; i++)
	{
		int s = v[i];
		while (s < suma);

	}

	FILE *fw;
	fw = fopen("out.txt", "wt");
	if (fw == NULL)
	{
		printf("Eroare deschidere fisier out.txt!\n");
		exit(1);
	}

	fclose(fw);

	system("pause");
	return 0;
}