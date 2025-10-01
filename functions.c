#include "header.h"

info_client clion[1];
produits prd[10]; 

int m_strcasecmp(char s1[], char s2[])
{
    int i = 0;
    int r;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] = s1[i] + 32;
        }
        if (s2[i] >= 'A' && s2[i] <= 'Z')
        {
            s2[i] = s2[i] + 32;
        }

        if (s1[i] == s2[i])
        {
            i++;
        }
        else 
        {               
           return s1[i] - s2[i];
            
        }
    } 
    return s1[i] - s2[i];
}


void selection_produit()
{
    int id_recherche;
    int trouve = 0;

    printf(JUEN"veuillez saisir l id du produit que vous voulez acheter: "RESET);
    scanf("%d", &id_recherche);
    for (int i = 0; i < 10; i++)
    {
        if (prd[i].id == id_recherche)
        {
            trouve = 1;
            printf(viole"\nproduit choisi:\n");
            printf("id : %d\n", prd[i].id);
            printf("nom : %s\n", prd[i].nom_prd);
            printf("categorie: %s\n", prd[i].categorie);
            printf("prix : %.2f\n", prd[i].prix);
            printf("stock : %d\n"RESET, prd[i].stock);
            if (prd[i].stock <= 0)
            {
                printf(ROUGE"produit indisponibl dans stock!\n"RESET);
                return;
            }
            if (clion[0].solde < prd[i].prix)
            {
                printf(ROUGE"operation d achat ruffuse charger votre solde !\n"RESET);
                return;
            }
            clion[0].solde = clion[0].solde - prd[i].prix;
            prd[i].stock = prd[i].stock - 1;
            printf(VERT"operation d achat termine avec un succee => le nouveau solde: %.2f\n"RESET, clion[0].solde);
            return;
        }
    }
    if (trouve != 1)
    {
        printf(ROUGE"produit ne trouve pas!\n"RESET);
    }
}


void details_produit() 
{
    int id_recherche;
    int trouve = 0;

    printf(JUEN"veuillez saisir l id du produit: "RESET);
    scanf("%d", &id_recherche);
    for (int i = 0; i < 10; i++) {
        if (prd[i].id == id_recherche) {
            trouve = 1;
            printf(viole"\n==> %d\n", prd[i].id);
            printf("==> %s\n", prd[i].nom_prd);
            printf("==> %s\n", prd[i].categorie);
            printf("==> %.2f\n", prd[i].prix);
            printf("==> %d\n", prd[i].stock);
            printf("==> %s\n"RESET, prd[i].description);
            printf(JUEN"================================\n"RESET);
            break; 
        }
    }
    if (trouve != 1) {
        printf(ROUGE"produit n exeste pas\n"RESET);
    }
}


void tri_produit()
{
    int chois, i, j;
    produits temp;

    printf(JUEN"\n=========Tri des produits=========\n"RESET);
    printf(BLUE"1_ Par prix croissant.\n");
    printf("2_ Par prix decroissant.\n");
    printf("3_ Par nom alphabetique.\n");
    printf("4_ quitter.\n");
    printf("veuillez saisir votre choix: "RESET);
    scanf("%d", &chois);

    while (chois < 1 || chois > 4)
    {
        printf(ROUGE"le choix est incorect. veuillez saisir un nombre entre 1 et 4 : \n"RESET);
        scanf("%d", &chois);
    }

    if (chois == 4) return;

    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            int swap = 0;

            if (chois == 1 && prd[i].prix > prd[j].prix)
                swap = 1;
            else if (chois == 2 && prd[i].prix < prd[j].prix)
                swap = 1;
            else if (chois == 3 && m_strcasecmp(prd[i].nom_prd, prd[j].nom_prd) > 0) 
                swap = 1;

            if (swap == 1)
            {
                temp = prd[i];
                prd[i] = prd[j];
                prd[j] = temp;
            }
        }
    }
    printf(JUEN"\n=========Produits après tri=========\n"RESET);
}

void G_solde_vr()
{
    int chois;
    float charge;
    printf(JUEN"=============solde virtuel===========\n"RESET);
    printf(BLUE"1_ consultation du solde.\n");
    printf("2_depot d argent.\n");
    printf("3_verification automatique.\n");
    printf("4_ retour .");
    printf("veuillez saisir votre chois : ");
    scanf("%d", &chois);
    while (chois < 1 || chois > 4)
    {
        printf(ROUGE"Attention! le nomber in correct veuillez saisir votre choix: "RESET);
        scanf("%d", &chois);

    }
    switch (chois)
    {
    case 1:
        printf(viole"votre solde : %.2f\n"RESET,clion[0].solde);
        system_dachat_client();
        break;
    case 2:
        printf("charger votre solde : ");
        scanf("%f", &charge);
        clion[0].solde = clion[0].solde + charge;
        printf(VERT"l operation du recharge a ete termini avec sucsee.\n"RESET);
        printf(viole"votre dolde maintenet est : %.2f\n"RESET, clion[0].solde);
        system_dachat_client();
        break;
    case 3:
        printf(viole"votre dolde maintenet est : %.2f\n"RESET, clion[0].solde);
        system_dachat_client();
    case 4:
        system_dachat_client();
    }
}

void data_prduit()
{
    prd[0].id = 1;
    strcpy(prd[0].nom_prd, "BMW");
    strcpy(prd[0].categorie, "voitur");
    prd[0].prix = 850000.00;
    prd[0].stock = 3;
    strcpy(prd[0].description, "bmw x6, mode 2023, essense, couleur noir, tout option");
    
    prd[1].id = 2;
    strcpy(prd[1].nom_prd, "iPhone");
    strcpy(prd[1].categorie, "electronique");
    prd[1].prix = 15000.00;
    prd[1].stock = 10;
    strcpy(prd[1].description, "iPhone 15 Pro Max, 256Go, couleur argent.");
    
    prd[2].id = 3;
    strcpy(prd[2].nom_prd, "MacBook");
    strcpy(prd[2].categorie, "Informatique");
    prd[2].prix = 22000.00;
    prd[2].stock = 5;
    strcpy(prd[2].description, "MacBook Pro 14 pouces, M2 Pro, 16Go RAM, 512Go SSD.");

    prd[3].id = 4;
    strcpy(prd[3].nom_prd, "PlayStation");
    strcpy(prd[3].categorie, "Jeux");
    prd[3].prix = 8500.00;
    prd[3].stock = 7;
    strcpy(prd[3].description, "Console Sony PlayStation 5 avec manette DualSense.");

    prd[4].id = 5;
    strcpy(prd[4].nom_prd, "Samsung");
    strcpy(prd[4].categorie, "electronique");
    prd[4].prix = 6000.00;
    prd[4].stock = 4;
    strcpy(prd[4].description, "Téléviseur Samsung 55 pouces 4K UHD Smart TV.");

    prd[5].id = 6;
    strcpy(prd[5].nom_prd, "Casque Sony");
    strcpy(prd[5].categorie, "Audio");
    prd[5].prix = 1200.00;
    prd[5].stock = 15;
    strcpy(prd[5].description, "Casque sans fil Sony WH-1000XM5, reduction de bruit.");

    prd[6].id = 7;
    strcpy(prd[6].nom_prd, "Clavier");
    strcpy(prd[6].categorie, "informatique");
    prd[6].prix = 450.00;
    prd[6].stock = 20;
    strcpy(prd[6].description, "Clavier mécanique Logitech RGB retroeclaire.");

    prd[7].id = 8;
    strcpy(prd[7].nom_prd, "nike_air_aax");
    strcpy(prd[7].categorie, "chaussures");
    prd[7].prix = 1200.00;
    prd[7].stock = 25;
    strcpy(prd[7].description, "chaussures nike air Max 270, couleur blanche et rouge.");

    prd[8].id = 9;
    strcpy(prd[8].nom_prd, "Sac_Gucci");
    strcpy(prd[8].categorie, "Mode");
    prd[8].prix = 9500.00;
    prd[8].stock = 6;
    strcpy(prd[8].description, "Sac a main Gucci original cuir marron.");

    prd[9].id = 10;
    strcpy(prd[9].nom_prd, "refrigerateur_LG");
    strcpy(prd[9].categorie, "electromenager");
    prd[9].prix = 7800.00;
    prd[9].stock = 8;
    strcpy(prd[9].description, "Refrigerateur LG 400L, inox, systeme No Frost.");
}



void recherch_produit()
{
    int chois;
    char p_recherche[20];
    int i = 0;
    int trouve = 0;
    printf(JUEN"=========rechercher dans le cataloge du produit===============\n"RESET);
    printf(BLUE"1_ recherche par nom.\n");
    printf("2_ recherche par categorie.\n");
    printf("3_ retour.\n");
    printf("4_ Quiter le progreme.\n");
    printf("veuillez siasir votre chois: "RESET);
    scanf("%d", &chois);
    while (chois < 1 || chois > 3)
    {
        printf(ROUGE"le nomber que vous entrez inccorect veuillez saisir un nomber entre 1 et 3 : \n"RESET);
        scanf("%d", &chois);
    }
    switch (chois)
    {
        case 1:
            printf(viole"veuillez sisir le nom de produit que vous recherche : "RESET);
            scanf("%s", p_recherche);
            while (i < 10)
            {
                if (m_strcasecmp(prd[i].nom_prd, p_recherche) == 0)
                {
                    trouve = 1;
                    printf(viole"==> %d\n", prd[i].id);
                    printf("==> %s\n", prd[i].nom_prd);
                    printf("==> %s\n", prd[i].categorie);
                    printf("==> %.2f\n", prd[i].prix);
                    printf("==> %d\n", prd[i].stock);
                    printf("==> %s\n"RESET, prd[i].description);
                    printf(JUEN"================================"RESET);
                }
                i++;   
            }
            if (trouve == 0)
            printf(ROUGE"le produit que vous rechrche n pas dispobilbe!\n"RESET);
            break;
        case 2:
            printf(viole"veuillez sisir la categorie de produit que vous recherche : "RESET);
            scanf("%s", p_recherche);
            while (i < 10)
            {
                if (m_strcasecmp(prd[i].categorie, p_recherche) == 0)
                {
                    trouve = 1;
                    printf(viole"==> %d\n", prd[i].id);
                    printf("==> %s\n", prd[i].nom_prd);
                    printf("==> %s\n", prd[i].categorie);
                    printf("==> %.2f\n", prd[i].prix);
                    printf("==> %d\n", prd[i].stock);
                    printf("==> %s\n"RESET, prd[i].description);
                    printf(JUEN"================================"RESET);
                }
                i++;   
            }
            if (trouve == 0)
                printf(ROUGE"le produit que vous rechrche n pas dispobilbe!\n"RESET);
            break;
        case 3:
            system_dachat_client();
            break;
        case 4:
           break;        
    }
}

void affichage_produit()
{
    printf(JUEN"\n=========produits==========\n"RESET);
    for (int i = 0; i < 10; i++)
    {
        printf(viole"==> %d\n", prd[i].id);
        printf("==> %s\n", prd[i].nom_prd);
        printf("==> %s\n", prd[i].categorie);
        printf("==> %.2f\n", prd[i].prix);
        printf("==> %d\n", prd[i].stock);
        printf("==> %s\n"RESET, prd[i].description);
        printf(JUEN"================================\n"RESET);
    }
}

void cataloge_prd()
{
    int chois;
    printf(JUEN"\n===========Consultation des produits==============\n"RESET);
    printf(Bleu_ciel"1_Affichage catalogue.\n");
    printf("2_Recherche produits.\n");
    printf("3_Tri des produits.\n");
    printf("4_Details produit\n");
    printf("5_Produits predefinis\n");
    printf("6_Quiter le programe\n");
    printf("veuillez siasir votre chois : "RESET);
    scanf("%d", &chois);
    while (chois < 1 || chois > 6)
    {
        printf(ROUGE"le nomber que vous entrez inccorect veuillez saisir un nomber entre 1 et 6 : \n"RESET);
        scanf("%d", &chois);
    }

    switch (chois)
    {
        case 1:
            affichage_produit();
            system_dachat_client();
            break;
        case 2:
            recherch_produit();
            system_dachat_client();
            break;
        case 3:
            tri_produit();
            affichage_produit();
            system_dachat_client();
        case 4:
            details_produit();
            break;

    }
}


void consulter()
{
    printf(viole"le nom        : %s\n", clion[0].nom);
    printf("le prenom     : %s\n", clion[0].prenom);
    printf("email         : %s\n", clion[0].email);
    printf("solde actuele : %.2f\n"RESET, clion[0].solde);
    printf(JUEN"==================================\n"RESET);
}

void modifier_profil()
{
    char m_prenom[30];
    char m_nom[30];

    printf(JUEN"\n=================la modification============\n"RESET);
    printf(viole"veuillez saisir la modification sur votre profil : \n"RESET);
    printf(BLUE"veuillez saisir le nouveau nom : "RESET);
    scanf("%s", m_nom);

    printf(BLUE"veuillez saisir le nouveau prenom : "RESET);
    scanf("%s",m_prenom);

    strcpy(clion[0].nom, m_nom);
    strcpy(clion[0].prenom, m_prenom);

    printf("%s",clion[0].nom);
    sprintf(clion[0].email,"%s.%s@gmail.com",clion[0].nom,clion[0].prenom);
    printf(VERT"\nla modification a ete terminee avec un succes\n"RESET);

}

void G_creation_profil()
{
    printf(viole"Saisie nom :");
    scanf("%s", clion[0].nom);
    printf("saisir prenom :");
    scanf(" %s", clion[0].prenom);
    sprintf(clion[0].email,"%s.%s@gmail.com",clion[0].nom,clion[0].prenom);
    clion[0].id = 1; 
    printf("veuillez saisir votre solde virtuel : ");
    scanf("%f", &clion[0].solde);
    printf(VERT"\nprofil vree avec succes.\n"RESET);
}

void G_profil_clion()
{
    int chois;
    printf(JUEN"==========Profil============\n"RESET);
    printf(viole"1_ Creation de profil.\n");
    printf("2_ Modification du profil.\n");
    printf("3_ Consultation du profil.\n");
    printf("veuillez sisi: ");
    scanf("%d", &chois);
    while (chois < 1 || chois > 3)
    {
        printf(ROUGE"Attention! le nomber in correct veuillez saisir votre choix: "RESET);
        scanf("%d",&chois);
    }
    switch (chois)
    {
    case 1:
        G_creation_profil(); 
        system_dachat_client();
        break;
    case 2:
        modifier_profil();
        system_dachat_client();
        break;
    case 3:
        consulter();
        system_dachat_client();
        break;
    default:
        break;
    }

}

void system_dachat_client()
{
    int chois;
    printf(JUEN"=================SYSTEM D ACHAT CLIEN=================\n"RESET);
    printf(BLUE"1_ Gestion du profil client.\n"RESET);
    printf(BLUE"2_ Gestion du solde virtuel.\n"RESET);
    printf(BLUE"3_ Consultation des produits.\n"RESET);
    printf(BLUE"4_ Effectuer un achat.\n"RESET);
    printf(BLUE"5_ Mes statistiques.\n"RESET);
    printf(BLUE"0_ Quitter l application\n"RESET);
    printf(JUEN"Votre choix: ");
    scanf("%d", &chois);
    while (chois < 0 || chois > 6)
    {
        printf(ROUGE"Attention! le nomber in correct veuillez saisir votre choix: "RESET);
        scanf("%d", &chois);
    } 
    switch (chois)
    {
        case 1: 
            G_profil_clion();
            break;
        case 2: 
            G_solde_vr();
            break;
        case 3:
            cataloge_prd();
            break;

    }
}
