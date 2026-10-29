#pragma once

typedef struct ElementListy {
	int klucz;
	struct ElementListy* nast;
}ElL;

typedef ElL* Lista;

void Menu();

void WyswietlListe(Lista L);

void WyswietlListeOdwrotnie(Lista L);

void DNPL(Lista* L, int x);

void DNKL(Lista* L, int x);

void UPeL(Lista* L);

void UOeL(Lista* L);

int WczytajZPliku(Lista* L, const char* NazwaPliku);

int ZapiszDoPliku(Lista L, const char* NazwaPliku);

Lista SzukajElementu(Lista L, int x);

void DodajZa(Lista W, int x);

void DodajPrzed(Lista* L, Lista W, int x);

//Usun wskazany element z listy L (wskazany przez W)
void UWE(Lista *L, Lista *W);

//Usun kazde wystapienie elementu o wartosci x z listy L
void UKWE(Lista* L, int x);

void UKWE_Rekurencyjnie(Lista* L, int x);

void OdwrocListe(Lista* L);

void OdwrocListeRekurencyjnie(Lista* L);