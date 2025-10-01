#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

// #include "fonction.c"

#define ROUGE "\033[1;31m"
#define VERT "\033[1;32m"
#define JUEN "\033[1;33m"
#define BLUE "\033[1;34m"
#define viole "\033[1;35m"
#define Bleu_ciel "\033[1;36m"
#define RESET "\033[0m"


typedef struct {
    char nom[100];
    char prenom[100];
    int id;
    char email[500];
    float solde;
} info_client;

extern info_client clion[1];

typedef struct {
    int id;
    char nom_prd[100];
    char categorie[100];
    float prix;
    int stock;
    char description[100];
} produits;

extern produits prd[10];

// Function prototypes
void G_creation_profil();
void G_solde_vr();

void system_dachat_client();

void data_prduit();
void affichage_produit();
void cataloge_prd();
void G_profil_clion();

void recherch_produit();
void consulter();
void modifier_profil();

#endif