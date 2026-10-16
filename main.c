#include <stdio.h>
#include <stdlib.h>
#include "Lista_jed.h"

int main(){
	char input;
	int x;
	Lista L = NULL, W = NULL;

	do{
		Menu();

		if (scanf_s(" %c", &input, 1) == 0)
			exit(1);

		switch (input) {
			case '1':
				printf("\nPodaj wartosc elementu: ");
				if (scanf_s(" %d", &x) == 0)
					exit(1);
				DNPL(&L, x);
				break;
			case '2':
				printf("\nPodaj wartosc elementu: ");
				if (scanf_s(" %d", &x) == 0)
					exit(1);
				DNKL(&L, x);
				break;
			case '3':
				UPeL(&L);
				break;
			case '4':
				UOeL(&L);
				break;
			case '5':
				printf("\nPodaj element do wyszukania: ");
				if (scanf_s(" %d", &x) == 0)
					exit(1);
				W = SzukajElementu(L, x);
				break;
			case '6':
				printf("\nPodaj wartosc elementu: ");
				if (scanf_s(" %d", &x) == 0)
					exit(1);
				printf("\n 1 - dodaj przed wskazanym elementem\n");
				printf("\n 2 - dodaj po wskazanym elemencie\n");
				if (scanf_s(" %c", &input, 1) == 0)
					exit(1);
				printf("\n\n");
				if (input == '1')
					DodajPrzed(&L, W, x);
				if(input == '2')
					DodajZa(W, x);
				printf("\n\n");
				break;
			case '7':
				
				break;
			case '8':
				
				break;
			case '9':
				
				break;
			case '+':
				printf("\n 1 - wyswietl normalnie\n");
				printf("\n 2 - wyswietl odwrotnie\n");
				if (scanf_s(" %c", &input, 1) == 0)
					exit(1);
				if (input == '1')
					WyswietlListe(L);
				if (input == '2')
					WyswietlListeOdwrotnie(L);
				break;
			case '0':
				return 0;
			default:
				return 1;
		}

	} while (1);
	return 0;
}