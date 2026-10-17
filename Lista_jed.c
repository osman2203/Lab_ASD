#include <stdio.h>
#include <stdlib.h>
#include "Lista_jed.h"

typedef struct ElementListy {
	int klucz;
	struct ElementListy* nast;
}ElL;

void Menu() {
	printf("\n1 - dodaj element na poczatku listy\n");
	printf("2 - dodaj element na koncu listy\n");
	printf("3 - usun pierwszy element listy\n");
	printf("4 - usun ostatni element listy\n");
	printf("5 - odszukaj zadany element\n");
	printf("6 - dodaj nowy element przed lub za wskazanym\n");
	printf("7 - usun wskazany element\n");
	printf("8 - wczytaj zawartosc listy z pliku\n");
	printf("9 - zapisz zawartosc listy do pliku\n");
	printf("+ - wyswietl zawartosc listy\n");
	printf("0 - zakoncz dzialanie programu\n");
	printf("Nastepna operacja: ");
}

void WyswietlListe(Lista L) {
	Lista p = L;
	while(p != NULL) {
		printf("%d ", p->klucz);
		p = p->nast;
	}
}

void WyswietlListeOdwrotnie(Lista L) {
	if(L != NULL) {
		WyswietlListeOdwrotnie(L->nast);
		printf("%d ", L->klucz);
	}
}

void DNPL(Lista* L, int x) {
	Lista p = (Lista)malloc(sizeof(ElL));
	if(p == NULL) {
		printf("Blad alokacji pamieci!\n");
		exit(1);
	}
	p->klucz = x;
	p->nast = *L;
	*L = p;
}

void DNKL(Lista* L, int x) {
	while (*L) {
		L = &(*L)->nast;
	}
	DNPL(L, x);
}

void UPeL(Lista* L) {
	if(*L == NULL) {
		printf("Lista jest pusta!\n");
		return;
	}
	Lista p = *L;
	*L = p->nast;
	free(p);
}

void UOeL(Lista* L) {
	if (*L == NULL) {
		printf("Lista jest pusta!\n");
		return;
	}
	while ((*L)->nast) {
		L = &(*L)->nast;
	}
	free(*L);
	*L = NULL;
}

Lista SzukajElementu(Lista L, int x) {
	while (L) {
		if (L->klucz == x)
			return L;
		L = L->nast;
	}
	printf("Nie znaleziono elementu o wartosci %d\n", x);
	return NULL;
}

void DodajZa(Lista W, int x) {
	if(W == NULL) {
		printf("Nie mozna dodac elementu za NULL!\n");
		return;
	}
	Lista p = (Lista)malloc(sizeof(ElL));
	if(p == NULL) {
		printf("Blad alokacji pamieci!\n");
		exit(1);
	}
	p->klucz = x;
	p->nast = W->nast;
	W->nast = p;
}

void DodajPrzed(Lista* L, Lista W, int x) {
	if (W == NULL) {
		printf("Nie mozna dodac elementu za NULL!\n");
		return;
	}
	Lista p = (Lista)malloc(sizeof(ElL));
	if(p == NULL) {
		printf("Blad alokacji pamieci!\n");
		exit(1);
	}
	p->klucz = x;
	p->nast = W;
	while (*L != W) {
		L = &(*L)->nast;
	}
	*L = p;
}


void UKWE(Lista* L, int x) {
	Lista p;
	p = *L;
	while (*L) {
		if ((*L)->klucz == x) {
			p = *L;
			*L = (*L)->nast;
			free(p);
		} else {
			L = &(*L)->nast;
		}
	}
}

void UKWE_Rekurencyjnie(Lista* L, int x) {
	Lista p;
	if (*L) {
		if ((*L)->klucz == x) {
			p = *L;
			*L = (*L)->nast;
			free(p);
			UKWE_Rekurencyjnie(L, x);
		} else {
			UKWE_Rekurencyjnie(&(*L)->nast, x);
		}
	}
}