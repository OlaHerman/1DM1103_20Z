#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student 
{
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *poprz;
    struct _Student *nast;
} Student;

typedef struct _Przedmiot 
{
    char * kod_przed;
    char * nazwa_przed;
    char * sem;

    struct _Przedmiot *poprz;
    struct _Przedmiot *nast;
} Przedmiot;

typedef struct _Ocena 
{
    char * kod_przedmiotu;
    char * nr_albumu;

    char * ocena;
    char * komentarz;

    struct _Ocena *poprz;
    struct _Ocena *nast;
} Ocena;

typedef struct _SBaza 
{
    Student *lista_studentow;
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);
void listuj_studentow(SBaza *baza);
void listuj_przedmioty(SBaza *baza);
void listuj_oceny(SBaza *baza);
void listuj_studentow_od_konca(SBaza *baza);
void listuj_przedmioty_od_konca(SBaza *b);
void wypisz_rekurencyjnie_od_konca(Student *el);
SBaza *dodaj_studenta(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email);
void dodaj_przedmiot(SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem);
SBaza * dodaj_stud_do_przed(SBaza *baza, char *kod_przedmiotu, char *nr_albumu, char *ocena, char *komentarz);
Student * sortuj_stud_przez_wybieranie(Student *glowa);
Przedmiot * sortuj_przed_przez_wybrany_kod(Przedmiot *glowa);
Ocena * filtruj_przedmioty(Ocena * glowa, char *kodzik, SBaza * baza);
Ocena * filtruj_przedmioty2(Ocena * glowa, char *albumik, SBaza *baza);
void zwolnij_student(Student *s);
void zwolnij_przedmioty(Przedmiot *s);
void zwolnij_ocena(Ocena *s);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);

#endif