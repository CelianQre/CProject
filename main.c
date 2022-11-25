#include <stdio.h>
#include <stdlib.h>


///////////////////////attention ++j au lieu de j++

    void infoJeu() {
        printf("Les types de navires:\n");
        printf("\tPorte-avion:\n");
        printf("\t\tSymbole: P.\n");
        printf("\t\tQuantité: 1.\n");
        printf("\t\tTaille: 7 cases.\n");

        printf("\tCroiseur:\n");
        printf("\t\tSymbole: C.\n");
        printf("\t\tQuantité: 2.\n");
        printf("\t\tTaille: 5 cases.\n");

        printf("\tDestroyer:\n");
        printf("\t\tSymbole: D.\n");
        printf("\t\tQuantité: 3.\n");
        printf("\t\tTaille: 3 cases.\n");

        printf("\tSous-marin:\n");
        printf("\t\tSymbole: S.\n");
        printf("\t\tQuantité: 4.\n");
        printf("\t\tTaille: 1 cases.\n");

        printf("Les touches a retenir:\n");
        printf("\tV: permet de passer en mode triche et d voir led bateau ennemis.\n");
        //mettre info de comment charger partie
    }
    void
    enregistrement(int grilleBateau1[15][15], int grilleTir1[15][15], int grilleBateau2[15][15], int grilleTir2[15][15],
                   int bateau1[10][6], int bateau2[10][6]) {
        FILE *fichier = NULL;
        fichier = fopen("C:\\Users\\User\\Desktop\\projectC\\save.txt", "w");
        if (fichier == NULL) printf("probleme d'ouverture de fichier\n");
        else {
            fprintf(fichier, "Joueur_1:\n");
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 15; ++j) {
                    if (i < 15) fprintf(fichier, "%d ", grilleBateau1[i][j]);
                    else fprintf(fichier, "%d ", grilleTir1[i][j]);
                }
                fprintf(fichier, "\n");
            }
            fprintf(fichier, "Joueur_2:\n");
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 15; ++j) {
                    if (i < 15) fprintf(fichier, "%d ", grilleBateau2[i][j]);
                    else fprintf(fichier, "%d ", grilleTir2[i][j]);
                }
                fprintf(fichier, "\n");
            }
        }
        fclose(fichier);
    }


    void affichage(int grilleBateau1[15][15], int grilleTir1[15][15]) {
        for (int i = 0; i < 15; ++i) {
            if (i < 10) printf("%d..", i);
            else printf("%d.", i);
        }
        printf("\t");
        for (int i = 0; i < 15; ++i) {
            if (i < 10) printf("%d..", i);
            else printf("%d.", i);
        }
        printf("\n");
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                printf("%d  ", grilleBateau1[i][j]);
            }
            printf("\t");
            for (int j = 0; j < 15; ++j) {
                printf("%d  ", grilleTir1[i][j]);
            }
            printf("\t");
            printf("%d.", i);
            printf("\n");
        }

    }
    void
    tricheOn(int grilleBateau1[15][15], int grilleTir1[15][15], int grilleBateau2[15][15], int grilleTir2[15][15]) {
        printf("Vision Joueur 1:\n");
        for (int i = 0; i < 15; ++i) {
            if (i < 10) printf("%d..", i);
            else printf("%d.", i);
        }
        printf("\t");
        for (int i = 0; i < 15; ++i) {
            if (i < 10) printf("%d..", i);
            else printf("%d.", i);
        }
        printf("\n");
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                printf("%d  ", grilleBateau1[i][j]);
            }
            printf("\t");
            for (int j = 0; j < 15; ++j) {
                printf("%d  ", grilleTir1[i][j]);
            }
            printf("\t");
            printf("%d.", i);
            printf("\n");
        }
        printf("\nVision Joueur 2:\n");
        for (int i = 0; i < 15; ++i) {
            if (i < 10) printf("%d..", i);
            else printf("%d.", i);
        }
        printf("\t");
        for (int i = 0; i < 15; ++i) {
            if (i < 10) printf("%d..", i);
            else printf("%d.", i);
        }
        printf("\n");
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                printf("%d  ", grilleBateau2[i][j]);
            }
            printf("\t");
            for (int j = 0; j < 15; ++j) {
                printf("%d  ", grilleTir2[i][j]);
            }
            printf("\t");
            printf("%d.", i);
            printf("\n");
        }

    }


    int placeDisponnible(int grilleBateau1[15][15], int tab[6]) {
        int verif = 1;
        for (int i = tab[2]; i < tab[4] + 1; i++) {
            for (int j = tab[3]; j < tab[5] + 1; j++) {
                if (grilleBateau1[i][j] != 0)
                    verif = 0;
            }
        }
        return verif;
    }
    void ecriture(int tab[6], int grilleBateau1[15][15]) {
        if (tab[2] == tab[4]) {
            for (int j = tab[3]; j < tab[5]; j++) {
                grilleBateau1[tab[2]][j] = tab[0];
            }
        } else {
            for (int i = tab[2]; i < tab[4]; i++) {
                grilleBateau1[i][tab[3]] = tab[0];
            }
        }
/*
    for (int i = tab[2]; i < tab[4]; i++) {
        for (int j = tab[3]; j < tab[5]; j++) {
            grilleBateau1[i][j]=tab[0];
        }
    }
*/
    }
    void
    resetGrilles(int grilleBateau1[15][15], int grilleTir1[15][15], int grilleBateau2[15][15], int grilleTir2[15][15]) {
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                grilleBateau1[i][j] = 0;
                grilleBateau2[i][j] = 0;
                grilleTir1[i][j] = 0;
                grilleTir2[i][j] = 0;
            }
        }
    }

    void initialisationBatailleNavalleJoueur1(int grilleBateau1[15][15], int bateau1[10][6]) {
        int x, y;
        int validation = 1;
        /*
        int porteAvion=1;
        int croisier1=2,croisier2=3;
        int destroyer1=4;destroyer2=5;destroyer3=6;
        int ss1=7,ss2=8;ss3=9,ss4=10;
         */
        for (int i = 1; i < 11; ++i) {
            bateau1[i - 1][0] = i;
        }
        bateau1[0][1] = 7;
        bateau1[1][1] = 5;
        bateau1[2][1] = 5;
        bateau1[3][1] = 3;
        bateau1[4][1] = 3;
        bateau1[5][1] = 3;
        bateau1[6][1] = 1;
        bateau1[7][1] = 1;
        bateau1[8][1] = 1;
        bateau1[9][1] = 1;
        //porte avion
        for (int i = 0; i < 10; i++) {
            while (validation) {
                if (rand() % 2 == 0) {
                    x = rand() % (15);
                    y = rand() % (15 - bateau1[i][1]);
                    //printf("\n\n\n%d %d\n\n",x,y);
                    bateau1[i][2] = x;
                    bateau1[i][4] = x;
                    bateau1[i][3] = y;
                    bateau1[i][5] = y + bateau1[i][1];
                } else {
                    x = rand() % (15 - bateau1[i][1]);
                    y = rand() % (15);
                    //printf("\n\n\n%d %d\n\n",x,y);
                    bateau1[i][2] = x;
                    bateau1[i][4] = x + bateau1[i][1];
                    bateau1[i][3] = y;
                    bateau1[i][5] = y;
                }
                if (placeDisponnible(grilleBateau1, bateau1[i])) {
                    ecriture(bateau1[i], grilleBateau1);
                    validation = 0;
                }
            }
            validation = 1;
        }
    }
    void initialisationBatailleNavalleJoueur2(int grilleBateau2[15][15], int bateau2[10][6]) {
        int x, y;
        int validation = 1;
        /*
        int porteAvion=1;
        int croisier1=2,croisier2=3;
        int destroyer1=4;destroyer2=5;destroyer3=6;
        int ss1=7,ss2=8;ss3=9,ss4=10;
         */
        for (int i = 1; i < 11; ++i) {
            bateau2[i - 1][0] = i;
        }
        bateau2[0][1] = 7;
        bateau2[1][1] = 5;
        bateau2[2][1] = 5;
        bateau2[3][1] = 3;
        bateau2[4][1] = 3;
        bateau2[5][1] = 3;
        bateau2[6][1] = 1;
        bateau2[7][1] = 1;
        bateau2[8][1] = 1;
        bateau2[9][1] = 1;
        //porte avion
        for (int i = 0; i < 10; i++) {
            while (validation) {
                if (rand() % 2 == 0) {
                    x = rand() % (15);
                    y = rand() % (15 - bateau2[i][1]);
                    //printf("\n\n\n%d %d\n\n",x,y);
                    bateau2[i][2] = x;
                    bateau2[i][4] = x;
                    bateau2[i][3] = y;
                    bateau2[i][5] = y + bateau2[i][1];
                } else {
                    x = rand() % (15 - bateau2[i][1]);
                    y = rand() % (15);
                    //printf("\n\n\n%d %d\n\n",x,y);
                    bateau2[i][2] = x;
                    bateau2[i][4] = x + bateau2[i][1];
                    bateau2[i][3] = y;
                    bateau2[i][5] = y;
                }
                if (placeDisponnible(grilleBateau2, bateau2[i])) {
                    ecriture(bateau2[i], grilleBateau2);
                    validation = 0;
                }
            }
            validation = 1;
        }
    }

    void ordinateur() {}
    int tir(int position[2], int grillebateau[15][15]) {
        if (grillebateau[position[0]][position[1]] == 0)
            return 0;
    }
    void eclairage() {}
    void deplacementBateau() {
        int idBateau;
        printf("Renseignez le code d'identification du bateau.\n");
        scanf("%d", &idBateau);


    }
    void tourBatailleNavale(int grilleBateau1[15][15], int grilleTir1[15][15], int grilleBateau2[15][15],
                            int grilleTir2[15][15], int bateau1[10][6], int bateau2[10][6], int *choixTour) {
        int position[2];
        int selectBateau;
        switch (*choixTour) {
            case 1: //tir
                printf("Indiquez l'endroit de tir.\n");
                printf("largeur: ");
                scanf("%d", &position[0]);
                printf("\nhauteur: ");
                scanf("%d", &position[1]);
                printf("\n");
                tir(position, grilleBateau2);
                break;
            case 2: //eclairage
                printf("Indiquez l'endroit de tir de la fusée éclairante.\n");
                printf("largeur: ");
                scanf("%d", &position[0]);
                printf("\nhauteur: ");
                scanf("%d", &position[1]);
                printf("\n");
                eclairage();
                break;
            case 3: //deplacement
                deplacementBateau();
                break;
            default:
                break;
        }
        //section navires coulés
    }
    void batailleNavale(int grilleBateau1[15][15], int grilleTir1[15][15], int grilleBateau2[15][15],
                        int grilleTir2[15][15]) {
        int choixTour;
        int finBataille = 1;
        int bateau1[10][6];
        int bateau2[10][6];


        initialisationBatailleNavalleJoueur1(grilleBateau1, bateau1);
        initialisationBatailleNavalleJoueur2(grilleBateau2, bateau2);

        while (finBataille) {
            affichage(grilleBateau1, grilleTir1);
            printf("Que voulez vous faire ?\n1: Tirer.\n2: Eclairer.\n3: Deplacer.\n4: Quitter et enregistrer.\n5: Quitter.\n");
            scanf("%d", &choixTour);

            switch (choixTour) {
                case 1:
                    tourBatailleNavale(grilleBateau1, grilleTir1, grilleBateau2, grilleTir2, bateau1, bateau2,
                                       &choixTour);
                    break;
                case 2:
                    tourBatailleNavale(grilleBateau1, grilleTir1, grilleBateau2, grilleTir2, bateau1, bateau2,
                                       &choixTour);
                    break;
                case 3:
                    tourBatailleNavale(grilleBateau1, grilleTir1, grilleBateau2, grilleTir2, bateau1, bateau2,
                                       &choixTour);
                    break;
                case 4:
                    enregistrement(grilleBateau1, grilleTir1, grilleBateau2, grilleTir2, bateau1, bateau2);
                    finBataille = 0;
                    break;
                case 5:
                    finBataille = 0;
                    break;
                default:
                    printf("Valeure incorrect.");
                    break;
            }
            ordinateur();
            //testFinPartie(bateau1, bateau2);
        }
        finBataille = 1;

    }

/*
void test(int grilleBateau1[15][15], int grilleTir1[15][15])
{
    initialisationBatailleNavalleJoueur1(grilleBateau1, grilleTir1);
    printf("\n");

    printf("\n");
    affichage(grilleBateau1, grilleTir1);
}*/
    void chargerPartie() {
        FILE *fichier = NULL;
        int compteurLigneFicher = 0;     //probleme de  depassement si la sauvegarde n'est pas conforme
        int grilleBateau1[15][15], grilleTir1[15][15];
        int grilleBateau2[15][15], grilleTir2[15][15];

        fichier = fopen("C:\\Users\\User\\Desktop\\projectC\\test.txt", "r");
        if (fichier == NULL) printf("Mauvaise ouverture du fichier.\n");
        else {
            printf("Bonne ouverture du fichier");
            //lecture du fichier en entier
            for (compteurLigneFicher = 0; compteurLigneFicher < 62; compteurLigneFicher++) {
                if (compteurLigneFicher >= 1 && compteurLigneFicher <= 15) {
                    for (int i = 0; i < 15; ++i) {
                        for (int j = 0; j < 15; ++j) {
                            fscanf(fichier, "%d", &grilleBateau1[i][j]);
                        }
                    }
                } else if (compteurLigneFicher >= 16 && compteurLigneFicher <= 30) {
                    for (int i = 0; i < 15; ++i) {
                        for (int j = 0; j < 15; ++j) {
                            fscanf(fichier, "%d", &grilleTir1[i][j]);
                        }
                    }
                } else if (compteurLigneFicher >= 32 && compteurLigneFicher <= 46) {
                    for (int i = 0; i < 15; ++i) {
                        for (int j = 0; j < 15; ++j) {
                            fscanf(fichier, "%d", &grilleBateau2[i][j]);
                        }
                    }
                } else if (compteurLigneFicher >= 47) {
                    for (int i = 0; i < 15; ++i) {
                        for (int j = 0; j < 15; ++j) {
                            fscanf(fichier, "%d", &grilleTir2[i][j]);
                        }
                    }
                }
                compteurLigneFicher++;
            }
            fclose(fichier);
        }
        batailleNavale(grilleBateau1, grilleTir1, grilleBateau2, grilleTir2);
    }

    int main() {

        int grilleBateau1[15][15], grilleTir1[15][15];
        int grilleBateau2[15][15], grilleTir2[15][15];

        int menuAcceuil;
        int finPartie = 1;

        while (finPartie) {
            printf("\nBonjour, bienvenu dans ce jeu de bataille Navale.\nQue voulez faire ?\n1: Jouer contre l'ordianteur.\n2: Charger une partie.\n3: Aide.\n4: Quitter.\n");
            scanf("%d", &menuAcceuil);

            switch (menuAcceuil) {
                case 1:
                    printf("\ninitialisation d'une nouvelle partie.\n\n");
                    resetGrilles(grilleBateau1, grilleTir1, grilleBateau2, grilleTir2);
                    //tricheOn(grilleBateau1,grilleTir1,grilleBateau2,grilleTir2);
                    batailleNavale(grilleBateau1, grilleTir1, grilleBateau2, grilleTir2);
                    //test(grilleBateau1, grilleTir1);
                    break;
                case 2:
                    chargerPartie();
                    break;
                case 3:
                    infoJeu();
                    break;
                case 4:
                    finPartie = 0;
                    break;
                default:
                    printf("Valeure incorrect.");
                    break;
            }
        }
        return 0;
    }
