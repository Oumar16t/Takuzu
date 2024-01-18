//
// Created by oumar on 22/04/2022.
//

#include "takuzu.h"

//On crée la fonction qui genere une grille 8x8 entièrement correct (c'est notre grille solution)
int** creation_map_8x8_valide()
{
    int **solution = (int **) malloc(8 * sizeof(int *));

    for (int i = 0; i < 8; i++)
    {
        solution[i] = (int *) malloc(8 * sizeof(int));                         //On alloue notre grille solution 4x4 qui nous servira de repaire pour la suite//
    }
    for (int i = 0; i<8;i++ )
    {
        for (int j = 0; j < 8; j++)
        {
            solution[i][j] = -1;
        }
    }
// Voici les valeur qui converti en binaire pourron formé notre grille 8x8
    int tab[33] =  {43, 45, 51, 53, 54, 75, 77, 83, 85, 86, 89, 90, 101, 102, 105, 106, 108, 147, 149, 150,
                    153, 154, 165, 166, 169, 170, 172, 178, 180, 202, 204, 210, 212};

    int ligne = 0;
    int lets_go = 0; // il nous permet de savoir si la création de la grille est fini ou non

    srand(time(NULL));

    do
    {
        int val = tab[rand()%33];
        solution[ligne] = binary_conversion_8x8(val);

        if (ligne >= 2)
        {
            //si la ligne ajouter n'est pas en harmoni avec les autre elle est regénérer
            while(comparer_ligne_par3_suivi(solution,ligne) == 0)
            {
                val = tab[rand()%33];
                solution[ligne] = binary_conversion_8x8(val);
            }
            ligne ++;
        }
        else if (ligne < 2)
        {
            ligne++;
        }
        if(ligne == 8)
        {
            //il permet de savoir si il y a autant de zero que de un sur la colonne
            int parité = comparer_colone_8x8(solution);
            //il permet coomme sont non l'indique de verifier si il n'y a pas de colonne identique
            int non_identique = comparer_colone_identique(solution);

            if ((parité == 1) && (non_identique == 1))
            {
                lets_go = 1;
            }
            else
            {
                ligne = 0;
            }
        }

    }while((ligne < 8) && (lets_go == 0));

    return solution;
}

//On crée une fonction qui converti un nombre decimal et binaire
int* binary_conversion_8x8(int val)
{
    int * tab = NULL;
    tab =(int*) malloc(8*sizeof(int));

    for(int i=7 ; i >= 0; i--)
    {
        tab[i] = val%2;
        val = val/2;
    }

    return tab;
}

//On crée la fonction qui compare les lignes sont bien agencé (c'ees à dire qu'il n'y a pas plus de deux mêmes valeur qui se suivent)
int comparer_ligne_par3_suivi(int** solution, int ligne)
{
    int verif = 1;

    for(int i = 0; i < 8; i++)
    {
       if((solution[ligne][i] == solution[ligne-1][i])&&(solution[ligne][i] == solution[ligne-2][i]))
       {
           verif = 0;
       }
    }

    return verif;
}

//on crée la fonction qui verifie si les colones ne sont pas identique
int comparer_colone_identique(int** solution)
{
    int verif = 1;

    int cpt =0;
    //on crée une boucle for pour nous permet de verifier tout les colonnes en fonction d'une seule et ainsi de suite
    for (int i=0; i<7 ;i++)
    {
        for (int j=i+1 ;j<8 ;j++)
        {
            for (int k=0; k<8 ;k++)
            {
                if (solution[k][i] == solution[k][j])
                {
                    cpt++;
                }
            }
            if (cpt == 8)
            {
                verif = 0;
            }
            cpt = 0;
        }
    }

    return verif;
}

//on cée la fonction qui verifi si il y a autant de zero que de un sur les colonnes
int comparer_colone_8x8(int** solution)
{
    int verif = 1;

    //on crée une boucle for inversé pour bloque la colonne et naviger en fonction des lignes
    for (int colonne = 0 ; colonne < 8 ; colonne++)
    {
        int cpt_1 = 0;
        int cpt_0 = 0;

        for (int ligne = 0; ligne < 8; ligne++)
        {

            if (solution[ligne][colonne] == 0)
            {
                cpt_0++;

            } else if (solution[ligne][colonne] == 1)
            {
                cpt_1++;
            }
        }

        if ((cpt_0 > 4) || (cpt_1 > 4))
        {
            verif = 0;

            return verif;
        }
    }

    return verif;
}

//On crée la fonction qui affichera les grilles 4x4
void print_map_8x8(int** map_8x8)
{
    printf("          %c",'A');
    for (int i=0; i<8-1;i++)
    {
        printf("         %c",'B'+i);
    }
    printf("\n");

    printf("     ................................................................................. \n");
    for(int i=0; i<8;i++)
    {
        printf(" %d   :",i+1);

        //on crée des conditions pour qu'en fonction de la val trouvé un affichage en conséquence s'affiche
        for(int j=0;j<8;j++)
        {
            if ((map_8x8[i][j] != -1) && (map_8x8[i][j] != -2) && (map_8x8[i][j] != -3) && (map_8x8[i][j] != -4) && (map_8x8[i][j] != -5)) //on affiche ce qu'il y a dans la solution
            {
                printf("    %d    :",map_8x8[i][j]);
            }
            else if (map_8x8[i][j] == -1) // on affiche r
            {
                printf("         :");
            }
            else if (map_8x8[i][j] == -2)   //on affiche une croix rouge
            {
                color(12,0);
                printf("    x");
                color(15,0);
                printf("    :");
            }
            else if (map_8x8[i][j] == -3) // on affiche des croix vert
            {
                color(10,0);
                printf("    x");
                color(15,0);
                printf("    :");
            }
            else if (map_8x8[i][j] == -4) //on affiche une croix bleu
            {
                color(11,0);
                printf("    x");
                color(15,0);
                printf("    :");
            }
            else if (map_8x8[i][j] == -5) //on affiche un plus...
            {
                color(13,0);
                printf("    +");
                color(15,0);
                printf("    :");
            }
        }
        printf("\n");
        printf("     ................................................................................. \n");

    }
    printf("\n");

    return;
}

//On crée un mask aléatoire sur lequel notre grille de jeux se referera pour afficher ou non les cases
int** masque_8x8_aleatoire()
{
    int ** masque = (int**) malloc(8* sizeof(int*));

    for(int i = 0;i<8;i++)
    {
        masque[i]=(int*)malloc(8*sizeof(int));
    }
                                                    //ici un mask4x4 aléatoire est crée,càd alouer puis remplit par des valeur aléatoire,grace au rend()%
    srand(time(NULL));
    for(int i=0;i<8;i++)
    {
        for(int j = 0;j<8;j++)
        {
            int aleatoire = rand() % 2;                //Ici les valeur aléatore sont des 1 ou des 0;
            masque[i][j] = aleatoire;
        }
    }

    return masque;
}

//Pareil que pour la fonction précedent à la différence que se mask est crée par l'utilisateur
int** masque_8x8_manuelle()
{
    int ** masque = (int**) malloc(8* sizeof(int*));

    for(int i = 0;i<8;i++)
    {
        masque[i]=(int*)malloc(8*sizeof(int));
    }

    for(int i=0;i<8;i++)
    {
        for(int j = 0; j < 8; j++)
        {
            masque[i][j] = -3;
        }
    }

    int nbr_masque;
    do {
        printf("Saisir le nombre d'element que vous-voulez masquer (entre 1 et 63): \n");
        scanf("%d",&nbr_masque);
    } while ((nbr_masque < 1) || (nbr_masque > 63));


    int ligne;
    char colonne_char;
    int colonne_int;
    do
    {
        print_map_8x8(masque);
        do
        {
            printf("Saisir la lettre de la colonne que vous souhaitez masquer: \n");
            scanf(" %c",&colonne_char);
        } while ((colonne_char < 'A') || (colonne_char > 'H'));

        do
        {
            printf("Sasir l'indice de la ligne que vous souhaitez masquer: \n");
            scanf("%d",&ligne);
        } while ((ligne < 1) || (ligne > 8));
        ligne--;

        switch (colonne_char)
        {
            case 'A':
                colonne_int = 0;
                break;
            case 'B':
                colonne_int = 1;
                break;
            case 'C':
                colonne_int = 2;
                break;
            case 'D':
                colonne_int = 3;
                break;
            case 'E':
                colonne_int = 4;
                break;
            case 'F':
                colonne_int = 5;
                break;
            case 'G':
                colonne_int = 6;
                break;
            case 'H':
                colonne_int = 7;
                break;
        }

        if (masque[ligne][colonne_int] == -5)
        {
            color(8,0);
            printf("\nLa case est deja masquer\n\n");                       //On verifi si la case que l'utilisateur souhaite masquer est possible ou non
            color(15,0);
            sleep(4);
        }
        else
        {
            masque[ligne][colonne_int] = -5;
            nbr_masque--;
        }
    } while (nbr_masque > 0);

    printf("\nVoici la grille sur laquelle vous aller jouer:\n\n");
    print_map_8x8(masque);
    printf("\n\n");

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if (masque[i][j] == -5)
            {
                masque[i][j] = -1;
            }
        }
    }

    sleep(4);

    return masque;
}

//on crée notre grille de jeux 4x4 sur laquelle l'utilisateur va jouer
int** grille_de_jeu_8x8(int** solution,int** masque)
{
    int ** grille = (int**) malloc(8* sizeof(int*));

    for(int i= 0;i<8;i++)
    {
        grille[i]=(int*)malloc(8*sizeof(int));
    }

    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if ((masque[i][j] == 0) || (masque[i][j] == -1))            //On crée notre grille de jeu 4x4 sur laqu'elle l'utilisateur jouera
            {                                                           //Elle est crée en fonction du mak et de la grille solution
                grille[i][j] = -1;
            }
            else
            {
                grille[i][j] = solution[i][j];
            }
        }
    }

    return grille;
}





//On crée la fonction de jeux pour l'utilisateur
void play_8x8(int** masque)
{
    int ** solution = NULL;
    int** grille = NULL;

    solution = creation_map_8x8_valide();
    grille = grille_de_jeu_8x8(solution,masque);

    int play_on = 1;                         //c'est notre bouton on/off si il est sur 1 alors on peut jouer si il est sur 0 la partie s'arret
    int life = 3;
    printf("\n");
    do
    {
        if (life == 3)
        {
            printf("Life: ");
            color(12,0);
            printf("%c %c %c \n",3,3,3);
            color(15,0);
        }
        else if (life == 2)
        {
            printf("Life: ");
            color(12,0);
            printf("%c %c \n",3,3);
            color(15,0);
        }
        else if (life == 1)
        {
            printf("Life: ");
            color(12,0);
            printf("%c \n",3);
            color(15,0);
        }
        //On affiche la grille de jeux
        print_map_8x8(grille);
        int possible = 0;                  //C'est lui qui nous permet de savoir si la case est vide ou non (ici il est à zero donc on part du principe que la case est vide)

        int ligne;
        char colonne_char;     //Comme il sera demander à l'utilisateur de rentrer des lettre pour les colonne alors on initialise un carratè qui stckera les lettre
        int colonne_int;            //en fonction de la lettre rentre il prendra une certaine valeur
        do
        {
            do
            {
                printf("Saisir la lettre de la colonne dans laquelle vous souhaitez jouer: \n");
                scanf(" %c",&colonne_char);
            } while ((colonne_char < 'A') || (colonne_char > 'H'));

            do
            {
                printf("Sasir l'indice de la ligne dans laquelle vous shouaitez jouer: \n");
                scanf("%d",&ligne);
            } while ((ligne < 1) || (ligne > 8));
            ligne--;

            switch (colonne_char)
            {
                case 'A':
                    colonne_int = 0;
                    break;
                case 'B':
                    colonne_int = 1;
                    break;
                case 'C':
                    colonne_int = 2;
                    break;
                case 'D':
                    colonne_int = 3;
                    break;
                case 'E':                             //on converti la letre renter en chiffre pour traiter l'information
                    colonne_int = 4;
                    break;
                case 'F':
                    colonne_int = 5;
                    break;
                case 'G':
                    colonne_int = 6;
                    break;
                case 'H':
                    colonne_int = 7;
                    break;
            }

            if (grille[ligne][colonne_int] != -1)
            {
                color(8,0);
                printf("\nLa case est deja remplit\n\n");
                color(15,0);
                sleep(3);
                possible = 0;
            }
            else
            {
                possible = 1;
            }
        }while(possible == 0);

        int val;
        do
        {
            printf("Saisir une valeur entre 0 et 1 en [%c ; %d] ou 2 -> pour quitter la partie: \n",colonne_char,ligne+1);
            scanf("%d",&val);
        }while ((val<0) || (val>2));
        if (val == 2)
        {
            printf("(R2D2: ");
            color(11,0);
            printf("Poule mouiller... %c\n\n",2);
            color(15,0);

            sleep(3);
            menu_Resoudre_grille();
        }

        int type_coup;                      //Aprèes que l'utilisateur est rentrer sa veleur. Elle sera analyser puis une certaine
        type_coup = type_de_coup_8x8(val,grille,ligne,colonne_int);               //valeur sera renvoyer. cette valeur definira notre type de coup

        // Selon la valeur de type_coup un message est renvoyer
        switch (type_coup)
        {
            case -6:
                grille[ligne][colonne_int] = -2;
                print_map_8x8(grille);
                color(12,0);
                printf("Vous vous etes malheureusement bloque !\n");
                color(15,0);
                life = 0;
                break;
            case -5:
                grille[ligne][colonne_int] = -2;
                print_map_8x8(grille);
                color(12,0);
                printf("Vous vous etes malheureusement bloque !\n");
                color(15,0);
                life = 0;
                break;
            case -4:
                grille[ligne][colonne_int] = -2;
                print_map_8x8(grille);
                color(12,0);
                printf("Vous vous etes malheureusement bloque !\n");
                color(15,0);
                life = 0;
                break;
            case -3:
                color(12,0);
                printf("\nCoup incrorect !\n\n");
                color(15,0);
                life--;
                break;
            case -2:
                color(12,0);
                printf("\nCoup incrorect !\n\n");
                color(15,0);
                life--;
                break;
            case -1:
                color(12,0);
                printf("\nCoup incrorect !\n\n");
                color(15,0);
                life--;
                break;
            case 0:
                color(14,0);
                printf("\nCoup valide !\n\n");
                color(15,0);
                grille[ligne][colonne_int] = val;
                break;
            case 1:
                color(10,0);
                printf("\nCoup correct !\n\n");
                color(15,0);
                grille[ligne][colonne_int] = val;
                break;
            case 2:
                color(10,0);
                printf("\nCoup correct !\n\n");
                color(15,0);
                grille[ligne][colonne_int] = val;
                break;
            case 3:
                color(10,0);
                printf("\nCoup correct !\n\n");
                color(15,0);
                grille[ligne][colonne_int] = val;
                break;
        }

        int cpt_moin_1;                  //a chaque etape un conteur va conter le nombre de -1(=casevide)
        cpt_moin_1 = compteur_grille_8x8(grille);       //pour savoir si la grille de jeux est totalement remplit

        if(cpt_moin_1 == 0)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Felicitation !\n");
            printf("        Vous avez fini la grille\n");
            printf("        Je peux enfin aller me coucher %c\n\n",2);
            color(15,0);
            play_on = 0;
        }
        else if(life < 1)
        {

            printf("\n(R2D2): ");
            color(11,0);
            printf("Vous avez perdu tout vos vies !\n");
            printf("        Faites plus attention la prochaine fois %c\n\n",2);
            color(15,0);
            play_on = 0;
        }

    } while (play_on == 1);

    sleep (4);

    free_8x8(grille);
    free_8x8(solution);
    free_8x8(masque);

    menu_Resoudre_grille();
}

//On crée la fonction qui verifi si la ligne est complet selon la valeur selctionner par l'utilisateur
int coup_correct_remplit_8x8(int val,int** grille,int ligne,int colonne)
{
    int verif = 0;

    int cpt0_lig = 0;
    int cpt1_lig = 0 ;
    int cpt0_col = 0;
    int cpt1_col = 0;

    for(int i = 0;i<8;i++)
    {
        if(grille[ligne][i]==0)
        {
            cpt0_lig++;
        }
        else if (grille[ligne][i] == 1)
        {
            cpt1_lig++;
        }
    }

    for(int i = 0;i<8;i++)
    {
        if(grille[i][colonne]==0)
        {
            cpt0_col++;
        }
        else if (grille[i][colonne] == 1)
        {
            cpt1_col++;
        }
    }


    if (val == 1)
    {
        if((cpt1_lig <= 3) && (cpt0_lig == 4))
        {
            verif = 1;
        }
        else if(cpt1_col <= 3 && cpt0_col == 4)
        {
            verif = 1;
        }
    }

    if (val == 0)
    {
        if((cpt0_lig <= 3) && (cpt1_lig == 4))
        {
            verif = 1;
        }
        else if((cpt0_col <= 3) && (cpt1_col == 4))
        {
            verif = 1;
        }
    }

    return verif;
}

//on crée la onction qui verifi si val n'est pas entourer de deux valeur qui se suivent
int coup_correct_haut_bas_gauche_droite(int val,int** grille,int ligne,int colonne)
{
    int verif = 0;

    if (val == 1)
    {
        if (coup_incorrect_haut_bas_gauche_droite(grille,0, ligne, colonne) == 1)
        {
            verif = 1;
        }
    }
    else if (val == 0)
    {
        if (coup_incorrect_haut_bas_gauche_droite(grille,1, ligne, colonne) == 1)
        {
            verif = 1;
        }
    }
}

//on cée la fonction qui verifie si verifie si val n'est pas encercler de valeur egale
int coup_correct_middle(int** grille,int val,int ligne,int colonne)
{
    int verif = 0;

    if (val == 1)
    {
        if(coup_incorrect_middle(grille,0,ligne,colonne) == 1)
        {
            verif = 1;
        }
    }
    else if (val == 0)
    {
        if(coup_incorrect_middle(grille,1,ligne,colonne) == 1)
        {
            verif = 1;
        }
    }
}

//On crée la fonction qui verifie si val est encercler par des valeur egale
int coup_incorrect_middle(int** grille,int val,int ligne,int colonne)
{
    int** mat_12 = (int**)malloc(12*sizeof(int*));
    for(int i = 0; i< 12; i++)
    {
        mat_12[i] = (int*) malloc(12*sizeof(int));
    }
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            if (((i < 2)||(j < 2))||((i > 9 )||(j>9)))
            {
                mat_12[i][j] = 0;
            }
            else
            if(grille[i-2][j-2] == 0)
            {
                mat_12[i][j] = 3;
            }
            else if(grille[i-2][j-2] == 1)
            {
                mat_12[i][j] =grille[i-2][j-2] ;
            }
        }
    }

    int verif = 0;

    int i = ligne + 2;
    int j = colonne + 2;
    int somme_gauche_droite = 0;
    int somme_haut_bas = 0;

    somme_gauche_droite = mat_12[i][j-1] + mat_12[i][j+1];
    somme_haut_bas = mat_12[i+1][j] + mat_12[i-1][j];

    if (val == 1)
    {
        if ((somme_gauche_droite == 2) || (somme_haut_bas == 2))
        {
            verif = 1;
        }
    }
    else if (val ==0)
    {
        if ((somme_gauche_droite == 6) || (somme_haut_bas == 6))
        {
            verif = 1;
        }
    }

    return verif;
}

//on crée la onction qui verifi si val est entourer de deux valeur qui se suivent
int coup_incorrect_haut_bas_gauche_droite(int** grille,int val,int ligne,int colonne)
{
    int** mat_12 = (int**)malloc(12*sizeof(int*));
    for(int i = 0; i< 12; i++)
    {
        mat_12[i] = (int*) malloc(12*sizeof(int));
    }
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            if (((i < 2)||(j < 2))||((i > 9 )||(j>9)))
            {
                mat_12[i][j] = 0;
            }
            else
            if(grille[i-2][j-2] == 0)
            {
                mat_12[i][j] = 3;
            }
            else if(grille[i-2][j-2] == 1)
            {
                mat_12[i][j] =grille[i-2][j-2] ;
            }
        }
    }

    int verif = 0;

    int i = ligne + 2;
    int j = colonne + 2;
    int somme_gauche = 0;
    int somme_droite = 0;
    int somme_bas = 0;
    int somme_haut = 0;

    somme_droite = mat_12[i][j+1] + mat_12[i][j+2];
    somme_gauche = mat_12[i][j-1] + mat_12[i][j-2];
    somme_haut = mat_12[i-1][j] + mat_12[i-2][j];
    somme_bas = mat_12[i+1][j] + mat_12[i+2][j];

    if (val == 1)
    {
        if ((somme_gauche == 2) || (somme_droite == 2) || (somme_haut == 2) || (somme_bas == 2))
        {
            verif = 1;
        }
    }

    else if(val == 0 )
    {
        if ((somme_gauche == 6)||(somme_droite == 6)||(somme_haut == 6)||(somme_bas == 6))
        {
            verif = 1;
        }
    }
    return verif;
}

//On crée une fonction qui determine si le coup souhaiter par l'utilisateur est incorrect
int coup_incorrect_remplit_8x8(int val,int** grille,int ligne,int colonne)
{
    int verif = 0;

    int cpt0_lig = 0;
    int cpt1_lig = 0 ;
    int cpt0_col = 0;
    int cpt1_col = 0;

    for(int i = 0;i<8;i++)
    {
        if(grille[ligne][i]==0)
        {
            cpt0_lig++;
        }
        else if (grille[ligne][i] == 1)
        {
            cpt1_lig++;
        }
    }

    for(int i = 0;i<8;i++)
    {
        if(grille[i][colonne]==0)
        {
            cpt0_col++;
        }
        else if (grille[i][colonne] == 1)
        {
            cpt1_col++;
        }
    }

    if( val == 1)
    {
        if((cpt1_lig >= 4) || (cpt1_col >= 4))
        {
            verif = 1;
        }
    }
    else if (val == 0)
    {
        if ((cpt0_lig >= 4) || (cpt0_col >= 4)) {
            verif = 1;
        }
    }

    return verif;
}

//On cée la fonction qui verifi si la case est boqué car les ligne est colonne sont presque remplit
int coup_bloque_remplit_8x8(int** grille, int ligne, int colonne)
{
    int verif = 0;

    int cpt0_lig = 0;
    int cpt1_lig = 0 ;
    int cpt0_col = 0;
    int cpt1_col = 0;

    for(int i = 0;i<8;i++)
    {
        if(grille[ligne][i]==0)
        {
            cpt0_lig++;
        }
        else if (grille[ligne][i] == 1)
        {
            cpt1_lig++;
        }
    }

    for(int i = 0;i<8;i++)
    {
        if(grille[i][colonne]==0)
        {
            cpt0_col++;
        }
        else if (grille[i][colonne] == 1)
        {
            cpt1_col++;
        }
    }

    if(((cpt1_col >= 4)&&(cpt0_lig >= 4))||((cpt0_col >= 4)&&(cpt1_lig >= 4)))
    {
        verif = 1;
    }
    return verif;
}

//On cée la fonction qui verifi si la case est boqué car elle est encercler de valeur egale de 1 et de 0
int coup_bloque_encercler_8x8(int** grille, int ligne, int colonne)
{
    int verif = 0;
    int coup_incorrect_1 = coup_incorrect_middle(grille,1,ligne,colonne);
    int coup_incorrect_2 = coup_incorrect_middle(grille,0,ligne,colonne);

    if (( coup_incorrect_1 == 1)&&( coup_incorrect_2 == 1))
    {
        verif = 1;
    }

    return  verif;
}

//On cée la fonction qui verifi si la case est boqué car la case est entourer de deux valeur qui se suivent pour 1 et pour 0
int coup_bloque_deux_dafiler_de_chaque_8x8(int** grille, int ligne, int colonne)
{
    int verif = 0;
    int coup_incorrect_1 = coup_incorrect_haut_bas_gauche_droite(grille,1,ligne,colonne);
    int coup_incorrect_2 = coup_incorrect_haut_bas_gauche_droite(grille,0,ligne,colonne);

    if (( coup_incorrect_1 == 1)&&( coup_incorrect_2 == 1))
    {
        verif = 1;
    }

    return  verif;
}

//On crée une fonction qui recroupe tout les types de coups sur une grille de takuzu 8x8
int type_de_coup_8x8(int val,int** grille,int ligne,int colonne)
{
    int type_coup = -7;

    int coup_correct_1 = coup_correct_remplit_8x8(val,grille,ligne, colonne);
    int coup_correct_2 = coup_correct_haut_bas_gauche_droite(val,grille,ligne,colonne);
    int coup_correct_3 = coup_correct_middle(grille,val,ligne,colonne);


    int coup_incorrect_1 = coup_incorrect_middle(grille,val,ligne,colonne);
    int coup_incorrect_2 = coup_incorrect_haut_bas_gauche_droite(grille,val,ligne,colonne);
    int coup_incorrect_3 = coup_incorrect_remplit_8x8(val,grille,ligne, colonne);

    int coup_bloque_1 = coup_bloque_remplit_8x8(grille,ligne,colonne);
    int coup_bloque_2 = coup_bloque_encercler_8x8(grille,ligne,colonne);
    int coup_bloque_3 = coup_bloque_deux_dafiler_de_chaque_8x8(grille,ligne,colonne);

    if (coup_bloque_3 == 1)
    {
        type_coup = -6;
    }
    else if (coup_bloque_2 == 1)
    {
        type_coup = -5;
    }
    else if(coup_bloque_1 == 1)
    {
        type_coup = -4;
    }
    else if (coup_incorrect_3 == 1)
    {
        type_coup = -3;
    }
    else if (coup_incorrect_2 == 1)
    {
        type_coup = -2;
    }
    else if (coup_incorrect_1 == 1)
    {
        type_coup = -1;
    }
    else if (coup_correct_1 == 1 )
    {
        type_coup = 1;
    }
    else if (coup_correct_2 == 1)
    {
        type_coup = 2;
    }
    else if (coup_correct_3 == 1)
    {
        type_coup = 3;
    }
    else
        type_coup = 0;

    return type_coup;
}

//On crée une finction qui compte le nombre de case vide sur la grille de jeux
int compteur_grille_8x8(int** grille)
{
    int cpt_moin_1 = 0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(grille[i][j] == -1)
            {
                cpt_moin_1++;
            }
        }
    }

    return cpt_moin_1;
}

//------------------------------------------------------------------------------------------------------------------------------------//

//On crée la fonction de jeux pour R2D2 qui résolvra une grille de takuzu
void play_8x8_auto(int** masque)
{
    int ** solution = NULL;
    int** grille = NULL;
    srand(time(NULL));

    solution = creation_map_8x8_valide();
    grille = grille_de_jeu_8x8(solution,masque);

    printf("\n(R2D2): ");
    color(11,0);
    printf("Salut je m'appel ");
    color(15,0);
    printf("R2D2 ");
    color(11,0);
    printf("et je vais t'aider a resoudre cette grille !\n\n");
    color(15,0);

    print_map_8x8(grille);

    int choix_1;
    do
    {
        color(15,0);
        printf("Selectionner 1 pour acceder a la prochaine etape: \n");
        scanf("%d",&choix_1);
    }while(choix_1 != 1);


    int play_on = 1;
    do
    {
        int ligne;
        int colonne;

        do
        {
            ligne = rand()%8;
            colonne = rand()%8;
        } while (grille[ligne][colonne] != -1);

        int val;
        val = solution[ligne][colonne];

        char colonne_char;
        switch (colonne)
        {
            case 0:
                colonne_char = 'A';
                break;
            case 1:
                colonne_char = 'B';
                break;
            case 2:
                colonne_char = 'C';
                break;
            case 3:
                colonne_char = 'D';
                break;
            case 4:
                colonne_char = 'E';
                break;
            case 5:
                colonne_char = 'F';
                break;
            case 6:
                colonne_char = 'G';
                break;
            case 7:
                colonne_char = 'H';
                break;
        }

        printf("\n(R2D2): ");
        color(11,0);
        printf("Dirigeons-nous en [%c ; %d]\n\n",colonne_char,ligne + 1);
        color(15,0);

        grille[ligne][colonne] = -4;
        print_map_8x8(grille);

        int choix_2;
        do
        {
            color(15,0);
            printf("Selectionner 1 pour acceder a la solution: \n");
            scanf("%d",&choix_2);
        }while(choix_2 != 1);

        int type_coup;
        type_coup = type_de_coup_8x8(val,grille,ligne,colonne);

        int inverse = -1;
        if (val == 1)
        {
            inverse = 0;
        }
        else if (val == 0)
        {
            inverse = 1;
        }

                                   //Si la case est masker le robot explique comment la remplir en fonction du type de coup
        switch (type_coup)
        {
            case 0:
                printf("\n(R2D2): ");
                color(11,0);
                printf("Je suis libre de mettre un %d en [%c ; %d]\n\n",val,colonne_char,ligne + 1);
                color(15,0);
                grille[ligne][colonne] = val;
                break;
            case 1:
                phrase_coup_bot_remplit_8x8(grille,ligne,colonne,val,colonne_char);
                break;
            case 2:
                printf("\n(R2D2): ");
                color(11,0);
                printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
                printf("        il y a deux %d qui se suivent\n\n",inverse);
                color(15,0);
                grille[ligne][colonne] = val;
                break;
            case 3:
                printf("\n(R2D2): ");
                color(11,0);
                printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
                printf("        je suis encercler de %d\n\n",inverse);
                color(15,0);
                grille[ligne][colonne] = val;
                break;
        }

        print_map_8x8(grille);

        int cpt_moin_1;
        cpt_moin_1 = compteur_grille_8x8(grille);

        if (cpt_moin_1 != 0)
        {
            int choix_3;
            do
            {
                printf("Selectionner 1 pour acceder a la prochaine etape ou 2 -> pour quitter la partie: \n");
                scanf("%d",&choix_3);
            }while ((choix_3 != 1) && (choix_3 != 2));

            if (choix_3 == 2)
            {
                printf("(R2D2: ");
                color(11,0);
                printf("Dommage vous me quitter deja...\n\n");
                color(15,0);

                sleep(3);

                free_8x8(grille);
                free_8x8(solution);
                free_8x8(masque);

                menu_Resoudre_Automatiquement_grille();
            }
        }

        else if (cpt_moin_1 == 0)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Et voila\n");
            printf("        Trop facile la 8x8 %c\n",2);
            color(15,0);

            play_on = 0;
        }

    } while (play_on == 1);

    sleep(4);

    free_8x8(grille);
    free_8x8(solution);
    free_8x8(masque);

    menu_Resoudre_Automatiquement_grille();
}

//on crée une finction qui selon la valeur renvoi les phrase dites par R2D2 lors de la résolution
void phrase_coup_bot_remplit_8x8(int** grille,int ligne,int colonne,int val,char colonne_char)
{
    int cpt0_lig = 0;
    int cpt1_lig = 0;
    int cpt0_col = 0;
    int cpt1_col = 0;

    for (int i = 0; i < 8; i++)
    {
        if (grille[ligne][i] == 0) {
            cpt0_lig++;
        } else if (grille[ligne][i] == 1) {
            cpt1_lig++;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (grille[i][colonne] == 0)
        {
            cpt0_col++;
        } else if (grille[i][colonne] == 1)
        {
            cpt1_col++;
        }
    }

    if (val == 1)
    {
        if (cpt0_lig == 4)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
            printf("        il y a quatre 0 sur la ligne %d\n\n",ligne + 1);
            color(15,0);
            grille[ligne][colonne] = val;
        }
        else if (cpt0_col == 4)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val, colonne_char,ligne + 1);
            printf("        il y a quatre 0 sur la colonne %c\n\n",colonne_char);
            color(15,0);
            grille[ligne][colonne] = val;
        }
    }

    if (val == 0)
    {
        if (cpt1_lig == 4)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
            printf("        il y a quatre 1 sur la ligne %d\n\n",ligne + 1);
            color(15,0);
            grille[ligne][colonne] = val;
        }
        else if (cpt1_col == 4)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
            printf("        il y a quatre 1 sur la colonne %c\n\n",colonne_char);
            color(15,0);
            grille[ligne][colonne] = val;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------------------//

//on crée la fonction qui génère une grille de jeux correct 8x8

void generer_grille_8x8()
{
    int** solution = NULL;
    solution = creation_map_8x8_valide();

    printf("\n(R2D2): ");
    color(11,0);
    printf("Generation en cours ");
    color(15,0);
    sleep(1);
    printf(" .");
    sleep(1);
    printf(" .");
    sleep(1);
    printf(" .\n\n");
    sleep(1);

    print_map_8x8(solution);

    printf("(R2D2): ");
    color(11,0);
    printf("Voici la grille de takuzu 8x8 que vous avez commander\n\n");
    color(15,0);
    sleep(3);

    free_8x8(solution);

    int choix;
    do
    {
        printf("Selectionner: \n\n");
        printf("1 - pour generer une nouvelle grille de takuzu 8x8\n");
        printf("2 - retour au menu\n\n");
        printf("Saisissez le numero correspondant a votre choix:\n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 2));

    switch(choix)
    {
        case 1:
            generer_grille_8x8();
            break;
        case 2:
            menu_Generer_grille();
            break;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------//

//On crée une fonction qui libère l'espace de la mémoire de notre ordinateur
void free_8x8(int ** map)
{
    for(int i = 0;i<8; i++)
    {
        free(map[i]);
    }
    free(map);
    map = NULL;
}