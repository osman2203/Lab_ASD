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
				UWE(&L, &W);
				break;
			case '8':
				char nazwaPliku[100];
				printf("\nPodaj nazwe pliku do wczytania: ");
				if (scanf_s("%s", nazwaPliku, (unsigned)_countof(nazwaPliku)) == 0)
					exit(1);
				WczytajZPliku(&L, nazwaPliku);
				break;
			case '9':
				char nazwaPliku2[100];
				printf("\nPodaj nazwe pliku do zapisania: ");
				if (scanf_s("%s", nazwaPliku2, (unsigned)_countof(nazwaPliku2)) == 0)
					exit(1);
				ZapiszDoPliku(L, nazwaPliku2);
				break;
			case 'a':
				printf("\n 1 - wyswietl normalnie\n");
				printf("\n 2 - wyswietl odwrotnie\n");
				if (scanf_s(" %c", &input, 1) == 0)
					exit(1);
				printf("\n");
				if (input == '1')
					WyswietlListe(L);
				if (input == '2')
					WyswietlListeOdwrotnie(L);
				printf("\n\n");
				break;
			case 'b': //Zadanie 2 - usuwanie kazdego wystapienia podanego elementu
				printf("\n Podaj element do usuniecia: ");
				if (scanf_s(" %d", &x) == 0)
					exit(1);
				printf("\n 1 - usun normalnie\n");
				printf("\n 2 - usun rekursywnie\n");
				if (scanf_s(" %c", &input, 1) == 0)
					exit(1);
				printf("\n\n");
				if (input == '1')
					UKWE(&L, x);
				if (input == '2')
					UKWE_Rekurencyjnie(&L, x);
				printf("\n\n");
				break;
			case 'c': //Zadanie 5 - odwracanie listy iteracyjnie i rekurencyjnie
				printf("\n 1 - odwroc normalnie\n");
				printf("\n 2 - odwroc rekursywnie\n");
				if (scanf_s(" %c", &input, 1) == 0)
					exit(1);
				printf("\n\n");
				if (input == '1')
					OdwrocListe(&L);
				if (input == '2')
					OdwrocListeRekurencyjnie(&L, &L);
				printf("\n\n");
				break;
			case '0':
				return 0;
			default:
				return 1;
		}

	} while (1);
	return 0;
}