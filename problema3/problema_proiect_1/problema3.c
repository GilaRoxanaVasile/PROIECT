#define _CRT_SECURE_NO_WARNINGS
#define NMAX 100
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fr;
	fr = fopen("in.txt", "rt"); 

	if (fr == NULL)
	{
		printf("Eroare deschidere fisier in.txt!\n");
		exit(1);
	}

	int i, n, maxim, minim, a, distmax=0;

	struct {
		int c, b; // c= case, b=birouri, l=locuitorul (proprietarul) celor doua
	}l[NMAX];

	fscanf(fr, "%d", &n); //citim numarul de locuitori
	for (i = 1; i <= n; i++)
	{
		fscanf(fr, "%d", &l[i].c);
		fscanf(fr, "%d", &l[i].b);
	}

	fclose(fr);

	for (i = 1; i <= n; i++)
	{
	
		if (l[i].c > l[i].b)
		{
			maxim = l[i].c;
			minim = l[i].b;
		}
		else
		{
			 maxim = l[i].b;
			 minim = l[i].c;
		}
		int x1 = maxim-minim; //distanta dintre casa si birou cand mergi in sensul acelor de ceasornic pe cerc
		int x2 = (2*n - maxim + minim); //distanta dintre casa si birou cand mergi invers acelor de ceasornic pe cerc
		if (x1 > x2)
			 a = x2; //a=minimul dintre cele doua distante pt a afla pe ce cale e drumul cel mai scurt catre birou
		else
			a = x1;
		if (a > distmax) //distmax=distanta cea mai lunga pe care o parcurge un locuitor al orasului
			distmax = a;
	}

	FILE *fw;
	fw = fopen("out.txt", "wt");
	if (fw == NULL)
	{
		printf("Eroare deschidere fisier out.txt!\n");
		exit(1);
	}
	fprintf(fw, "%d", distmax);
	fclose(fw);

	system("pause");
	return 0;
}