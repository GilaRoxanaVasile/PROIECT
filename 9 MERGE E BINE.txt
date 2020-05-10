#define _CRT_SECURE_NO_WARNINGS
#define NMAX 1000
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
	
	int n, i, q,x[NMAX],y[NMAX];

	fscanf(fr,"%d", &n);  
	fscanf(fr,"%d", &q);   

	//C1  C2  --> ordinea celor 4 cadrane --> ca cel de la trigonometrie 
	//C3  C4

	/*in continuare gandim problema in felul urmator: in functie de "coordonatele" (indicii dati) punctului (numarului) pe care vrem sa il determinam "impartim" tabelul in
	4 tabele, fiecare din cele 4 tabele mai mici e impartita in 4, care la randul lor sunt impartite in 4... si tot asa pana cand nu se mai poate imparti -> adica pana tabelul e de 2x2*/

	for (i = 1; i <= q; i++)
	{
		fscanf(fr,"%d", &x[i]);
		fscanf(fr,"%d", &y[i]);
	}

	fclose(fr);
	int nr_elemente_cadran = 0;  
	nr_elemente_cadran=nr_elemente_cadran | (1 << (n * 2)); //cu ajutorul acestei variabile vom stabili cand ne putem opri din impartit (deci am ajuns la situatia de tabel 2x2)
															//aceasta ne ajuta si sa plecam cu cautarea din punctul de maxim al tabelului
	int nr_col_lin = 0;          
	nr_col_lin= nr_col_lin | (1<<(n));      //cu ajutorului acestei variabile vom putea sarii din tabel in tabel in functie de circumstante: locatia indicilor fata de acesta (el fiind mereu
										//jumatatea\mijlocul nr-lui de linii (respectiv coloane) al tabelului in care ne aflam), scaderea corespunzatoare dimenisunii tabelului pt a trece la
										//un tabel mai mic 

	FILE *fw;
	fw = fopen("out.txt", "wt");

	if (fw == NULL)
	{
		printf("Eroare deschidere fisier out.txt!\n");
		exit(1);
	}

	for (i = 1; i <= q; i++)
	{
		
		int cate = nr_elemente_cadran/4; //cu ajutorul acestei variabile tinem socoteala la cate elemente avem int tabelul curent
											// impartim de la inceput cu 4 pt a imparti deja in 4 tabele
		int unde = nr_col_lin/2;      //salvam nr_col_lin in unde pt a nu trebui sa il calculam de fiecare data si il imaprtimi deja cu doi pt a stabili jumatatea de acm
		int cautat = nr_elemente_cadran;

		if (x[i] % 2 != 0 && y[i] % 2 == 0)   //in functie de paritatea indicilor ne asezam pe elementul din cadranul de dimensiune 2x2 din C1 pt ca cu el ne vom "plimba" in cautarea locului cerut
			cautat = cautat - 1;
		else
			if (x[i] % 2 == 0 && y[i] % 2 != 0)
				cautat = cautat - 2;
			else
				if (x[i] % 2 == 0 && y[i] % 2 == 0)
					cautat = cautat - 3;


		while (unde != 1 && cautat!=1 && x[i]!=0 && y[i]!=0) 
		{
			if (x[i] <= unde && y[i] > unde) //in aceste conditii nr cautat se afla in C2 din tabelul curent, deci ne mutam in acesta prin scaderea nr. corspunzator 
			{
				int s = 0 ;
				s = s | (1 << (unde));
				cautat = cautat - s;
				y[i] = y[i] - unde;

			}
			else
			if (x[i] > unde && y[i] <= unde) //aceeasi situatie ca mai sus, doar ca e vorba de C3
				{
				int s = 0;
				s = s | (1 << (unde + 1));
				cautat = cautat - s;
				x[i] = x[i] - unde;
				}
				else
				if (x[i] > unde && y[i] > unde) //aceeasi situatie ca mai sus, doar ca e vorba de C4
					{
					int s1 = 0, s2=0;
					s1=s1 | (1 << (unde + 1));
					s2=s2 | (1 << (unde));
					cautat = cautat - (s1 + s2);
					x[i] = x[i] - unde;
					y[i] = y[i] - unde;
					}
			unde = unde / 2; //trecand la urm tabel mai mic mijlocul se injumatateste
			cate = cate / 4; //impartim cadranul curent in 4 
		}

		fprintf(fw, "%d\n", cautat);

	}

	fclose(fw);

	system("pause");
	return 0;
}
