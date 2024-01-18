//
// Created by oumar on 22/04/2022.
//

#include "takuzu.h"

//On crée la fonction qui genere une grille 4x4 entièrement correct (c'est notre grille solution)
int** creation_map_4x4_valide()
{
    int** solution = (int**) malloc(4* sizeof(int*));

    for (int i = 0;i<4;i++)
    {                                                             //On alloue notre grille solution 4x4 qui nous servira de repaire pour la suite//
        solution[i]=(int*)malloc(4*sizeof(int));
    }

    srand(time(NULL));
    int val1;
    do
    {
        val1 = rand()%16;

    } while ((val1 != 3)&&(val1 != 5)&&(val1 != 6)&&(val1 != 9)&&(val1 != 10)&&(val1 != 12));

    int* ligne1 = binary_conversion_4x4(val1);                                        //ici un nombre aléatoire est generer et est ensuite converti en binaire//
    int inv_val1 = inverse_ligne_4x4(ligne1);                                       // qu'on stock dans une ligne//
    int* ligne2 = binary_conversion_4x4(inv_val1);

    int val2;
    do
    {
        val2 = rand()%16;

    } while ((val2 != 3)&&(val2 != 5)&&(val2 != 6)&&(val2 != 9)&&(val2 != 10)&&(val2 != 12));

    while ((val2 == val1)||(val2 == inv_val1))
    {
        do
        {
            val2 = rand()%16;
        } while ((val2 != 3)&&(val2 != 5)&&(val2 != 6)&&(val2 != 9)&&(val2 != 10)&&(val2 != 12));
    }

    int* ligne3 = binary_conversion_4x4(val2);
    int inv_val2 = inverse_ligne_4x4(ligne3);
    int* ligne4 = binary_conversion_4x4(inv_val2);

    solution[0] = ligne1;                                                         //4 nombre sont generer et converti en binaire. Il formeront notre grille 4x4 solution
    solution[1] = ligne2;
    solution[2] = ligne3;
    solution[3] = ligne4;

    return solution;
}

//On crée une fonction qui converti un nombre decimal et binaire
int* binary_conversion_4x4(int val)
{
    int * tab = NULL;
    tab =(int*) malloc(4*sizeof(int));

    for(int i=3 ; i >= 0; i--)                        //convertir des nombre en binaire qui rentre sur 4 ligne
    {
        tab[i] = val%2;
        val = val/2;
    }

    return tab;
}

//On crée une fonction qui converti un nombre exprimé en binaire en decimal
int inverse_ligne_4x4(int* ligne)
{

    int ligne_bis[4];
    for(int i=0;i<4;i++)
    {
        ligne_bis[i]=ligne[i];
    }

    int inv = 0,cpt =3;

    for(int i=0;i<4;i++)
    {                                       //On prend la ligne qui contient le nombre binaire generer et on linverse tout simplement
        if(ligne_bis[i]==0)                //pour ce faire on commence par la copié dans une ligne intermediare qu'ont inversera par la suite
        {
            ligne_bis[i]=1;
        }
        else if(ligne_bis[i]==1)
        {
            ligne_bis[i]=0;
        }
    }

    for(int i=0 ;i<4;i++)
    {
        inv += ligne_bis[i] * pow(2,cpt);
        cpt--;                                             //une fois ligne_bis inversé on convertie le code binaire qui y est stocké en decimale que l'on return ensuite
    }

    return inv;
}

//On crée la fonction qui affichera les grilles 4x4
void print_map_4x4(int** map_4x4)
{
    printf("        %c",'A');
    for (int i=0; i<4-1;i++)
    {
        printf("         %c",'B'+i);
    }
    printf("\n");

    printf("   ......................................... \n");
    for(int i=0; i<4;i++)
    {
        printf("%d  :",i+1);
        for(int j=0;j<4;j++)
        {
            //on crée des conditions pour qu'en fonction de la val trouvé un affichage en conséquence s'affiche

            if ((map_4x4[i][j] != -1) && (map_4x4[i][j] != -2) && (map_4x4[i][j] != -3) && (map_4x4[i][j] != -4) && (map_4x4[i][j] != -5))
            {
                printf("    %d    :",map_4x4[i][j]);
            }
            else if (map_4x4[i][j] == -1)
            {
                printf("         :");
            }
            else if (map_4x4[i][j] == -2)
            {
                color(12,0);
                printf("    x");
                color(15,0);
                printf("    :");
            }
            else if (map_4x4[i][j] == -3)
            {
                color(10,0);
                printf("    x");
                color(15,0);
                printf("    :");
            }
            else if (map_4x4[i][j] == -4)
            {
                color(11,0);
                printf("    x");
                color(15,0);
                printf("    :");
            }
            else if (map_4x4[i][j] == -5)
            {
                color(13,0);
                printf("    +");
                color(15,0);
                printf("    :");
            }
        }
        printf("\n");
        printf("   ......................................... \n");
    }
    printf("\n");

    return;
}

//On crée un mask aléatoire sur lequel notre grille de jeux se referera pour afficher ou non les cases
int** masque_4x4_aleatoire()
{
    int ** masque = (int**) malloc(4* sizeof(int*));

    for(int i = 0;i<4;i++)
    {
        masque[i]=(int*)malloc(4*sizeof(int));
    }

    srand(time(NULL));                            //ici un mask4x4 aléatoire est crée,càd alouer puis remplit par des valeur aléatoire,grace au rend()%
    for(int i=0;i<4;i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int aleatoire = rand() % 2;          //les valeur aléatoire sont 1 et 0
            masque[i][j] = aleatoire;
        }
    }

    return masque;
}

//Pareil que pour la fonction précedent à la différence que se mask est crée par l'utilisateur
int** masque_4x4_manuelle()
{
    int ** masque = (int**) malloc(4* sizeof(int*));

    for(int i = 0;i<4;i++)
    {
        masque[i]=(int*)malloc(4*sizeof(int));
    }

    for(int i=0;i<4;i++)
    {
        for(int j = 0; j < 4; j++)
        {
            masque[i][j] = -3;
        }
    }

    int nbr_masque;
    do {
        printf("Saisir le nombre d'element que vous-voulez masquer (entre 1 et 15): \n");
        scanf("%d",&nbr_masque);
    } while ((nbr_masque < 1) || (nbr_masque > 15));


    int ligne;
    char colonne_char;
    int colonne_int;
    do
    {
        print_map_4x4(masque);
        do
        {
            printf("Saisir la lettre de la colonne que vous souhaitez masquer: \n");
            scanf(" %c",&colonne_char);
        } while ((colonne_char < 'A') || (colonne_char > 'D'));

        do
        {
            printf("Sasir l'indice de la ligne que vous souhaitez masquer: \n");
            scanf("%d",&ligne);
        } while ((ligne < 1) || (ligne > 4));
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
        }

        if(masque[ligne][colonne_int] == -5)
        {
            color(8,0);                       //On verifi si la case que l'utilisateur souhaite masquer est possible ou non
            printf("\nLa case est deja masquer\n\n");
            color(15,0);
            sleep(3);
        }
        else
        {
            masque[ligne][colonne_int] = -5;
            nbr_masque--;
        }
    } while (nbr_masque > 0);

    printf("\nVoici la grille sur laquelle vous aller jouer:\n\n");
    print_map_4x4(masque);
    printf("\n\n");

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
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
int** grille_de_jeu_4x4(int** solution,int** masque)
{
    int** grille = (int**) malloc(4* sizeof(int*));

    for(int i= 0;i<4;i++)
    {
        grille[i]=(int*)malloc(4*sizeof(int));
    }

    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if ((masque[i][j] == 0) || (masque[i][j] == -1))
            {
                grille[i][j] = -1;                                 //On crée notre grille de jeu 4x4 sur laqu'elle l'utilisateur jouera
            }                                                      //Elle est crée en fonction du mak et de la grille solution
            else
            {
                grille[i][j] = solution[i][j];
            }
        }
    }

    return grille;
}




//On crée la fonction de jeux pour l'utilisateur
void play_4x4(int** masque)
{
    int ** solution = NULL;
    int** grille = NULL;

    solution = creation_map_4x4_valide();
    grille = grille_de_jeu_4x4(solution,masque);

    int play_on = 1;                 //c'est notre bouton on/off si il est sur 1 alors on peut jouer si il est sur 0 la partie s'arret
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
        print_map_4x4(grille);
        int possible = 0; //C'est lui qui nous permet de savoir si la case est vide ou non (ici il est à zero donc on part du principe que la case est vide)

        int ligne;
        char colonne_char;    //Comme il sera demander à l'utilisateur de rentrer des lettre pour les colonne alors on initialise un carratè qui stckera les lettre
        int colonne_int;     //en fonction de la lettre rentre il prendra une certaine valeur
        do
        {
            do
            {
                printf("Saisir la lettre de la colonne dans laquelle vous souhaitez jouer: \n");
                scanf(" %c",&colonne_char);
            } while ((colonne_char < 'A') || (colonne_char > 'D'));

            do
            {
                printf("Sasir l'indice de la ligne dans laquelle vous shouaitez jouer: \n");
                scanf("%d",&ligne);
            } while ((ligne < 1) || (ligne > 4));
            ligne--;

            switch (colonne_char)
            {
                case 'A':
                    colonne_int = 0;
                    break;
                case 'B':
                    colonne_int = 1;             //on converti la letre renter en chiffre pour traiter l'information
                    break;
                case 'C':
                    colonne_int = 2;
                    break;
                case 'D':
                    colonne_int = 3;
                    break;
            }

            if(grille[ligne][colonne_int] != -1)
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

        int type_coup;
        type_coup = type_de_coup_4x4(val,grille,ligne,colonne_int);             //Aprèes que l'utilisateur est rentrer sa veleur. Elle sera analyser puis une certaine
                                                                            //valeur sera renvoyer. cette valeur definira notre type de coup
        // Selon la valeur de type_coup un message est renvoyer
        switch (type_coup)
        {
            case -2:
                grille[ligne][colonne_int] = -2;
                print_map_4x4(grille);
                color(12,0);
                printf("Vous vous etes malheureusement bloque !\n");
                color(15,0);
                life = 0;
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
        }

        int cpt_moin_1;
        cpt_moin_1 = compteur_grille_4x4(grille);  //a chaque etape un conteur va conter le nombre de -1(=casevide)
                                                  //pour savoir si la grille de jeux est totalement remplit
        if(cpt_moin_1 == 0)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Felicitation !\n");
            printf("        Vous avez fini la grille\n");
            printf("        Tenter une 8 x 8 %c\n\n",2);
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

    free_4x4(grille);
    free_4x4(solution);
    free_4x4(masque);

    menu_Resoudre_grille();
}

//On crée la fonction qui verifi si la ligne est complet selon la valeur selctionner par l'utilisateur
int coup_correct_remplit_4x4(int val,int** grille,int ligne,int colonne)
{
    int cpt0_lig = 0;
    int cpt1_lig = 0 ;
    int cpt0_col = 0;
    int cpt1_col = 0;
    int verif = -1;

    for(int i = 0;i<4;i++)
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

    for(int i = 0;i<4;i++)
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
        if((cpt1_lig <= 1) && (cpt0_lig == 2))
        {
            verif = 1;
        }
        else if(cpt1_col <= 1 && cpt0_col == 2)
        {
            verif = 1;
        }
    }

    if (val == 0)
    {
        if((cpt0_lig <= 1) && (cpt1_lig == 2))
        {
            verif = 1;
        }
        else if((cpt0_col <= 1) && (cpt1_col == 2))
        {
            verif = 1;
        }
    }

    return verif;
}

//On crée une fonction qui determine si le coup souhaiter par l'utilisateur est incorrect
int coup_incorect_remplit_4x4(int val,int** grille,int ligne,int colonne)
{
    int cpt0_lig = 0;
    int cpt1_lig = 0 ;
    int cpt0_col = 0;
    int cpt1_col = 0;
    int verif = -1;

    for(int i = 0;i<4;i++)
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

    for(int i = 0;i<4;i++)
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
        if((cpt1_lig >= 2) || (cpt1_col >= 2))
        {
            verif = 1;
        }
    }
    else if (val == 0)
    {
        if ((cpt0_lig >= 2) || (cpt0_col >= 2)) {
            verif = 1;
        }
    }
    return verif;
}

//On crée une fonction qui determine si le coup souhaiter par l'utilisateur ne va pa le bloquer
int coup_bloque_remplit_4x4(int** grille, int ligne, int colonne)
{
    int cpt0_lig = 0;
    int cpt1_lig = 0 ;
    int cpt0_col = 0;
    int cpt1_col = 0;
    int verif = -1;

    for(int i = 0;i<4;i++)
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

    for(int i = 0;i<4;i++)
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

    if(((cpt1_col >= 2)&&(cpt0_lig >= 2))||((cpt0_col >= 2)&&(cpt1_lig >= 2)))
    {
        verif = 1;
    }
    return verif;
}

//On crée une fonction qui recroupe tout les types de coups sur une grille de takuzu 4x4
int type_de_coup_4x4(int val,int** grille,int ligne,int colonne)
{
    int type_coup = -3;

    int coup_correc = coup_correct_remplit_4x4(val,grille,ligne, colonne);
    int coup_incorrec = coup_incorect_remplit_4x4(val,grille,ligne, colonne);
    int coup_bloque = coup_bloque_remplit_4x4(grille,ligne,colonne);

    if(coup_bloque == 1)
    {
        type_coup = -2;
    }
    else if (coup_incorrec == 1)
    {
        type_coup = -1;
    }
    else if (coup_correc == 1 )
    {
        type_coup = 1;
    }
    else
        type_coup = 0;

    return type_coup;
}

//On crée une finction qui compte le nombre de case vide sur la grille de jeux
int compteur_grille_4x4(int** grille)
{
    int cpt_moin_1 = 0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
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
void play_4x4_auto(int** masque)
{
    int ** solution = NULL;
    int** grille = NULL;
    srand(time(NULL));

    solution = creation_map_4x4_valide();
    grille = grille_de_jeu_4x4(solution,masque);

    printf("\n(R2D2): ");
    color(11,0);
    printf("Salut je m'appel ");
    color(15,0);
    printf("R2D2 ");
    color(11,0);
    printf("et je vais t'aider a resoudre cette grille !\n\n");
    color(15,0);

    print_map_4x4(grille);

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
            ligne = rand()%4;
            colonne = rand()%4;
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
        }

        printf("\n(R2D2): ");
        color(11,0);
        printf("Dirigeons-nous en [%c ; %d]\n\n",colonne_char,ligne + 1);
        color(15,0);

        grille[ligne][colonne] = -4;
        print_map_4x4(grille);

        int choix_2;
        do
        {
            color(15,0);
            printf("Selectionner 1 pour acceder a la solution: \n");
            scanf("%d",&choix_2);
        }while(choix_2 != 1);

        int type_coup;
        type_coup = type_de_coup_4x4(val,grille,ligne,colonne);

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
                phrase_coup_bot_remplit_4x4(grille,ligne,colonne,val,colonne_char);
                break;
        }

        print_map_4x4(grille);

        int cpt_moin_1;
        cpt_moin_1 = compteur_grille_4x4(grille);

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
                printf("On se reverra...\n\n");
                color(15,0);

                sleep(3);

                free_4x4(grille);
                free_4x4(solution);
                free_4x4(masque);

                menu_Resoudre_Automatiquement_grille();
            }
        }

        else if (cpt_moin_1 == 0)
        {
            printf("\n(R2D2): ");
            color(11,0);
            printf("Et voila\n");
            printf("        Trop facile la 4x4 !\n");
            printf("        Teste moi sur 8x8 la prochaine fois %c\n\n",2);
            color(15,0);

            play_on = 0;
        }

    } while (play_on == 1);

    sleep(4);

    free_4x4(grille);
    free_4x4(solution);
    free_4x4(masque);

    menu_Resoudre_Automatiquement_grille();
}

//on crée une finction qui selon la valeur renvoi les phrase dites par R2D2 lors de la résolution
void phrase_coup_bot_remplit_4x4(int** grille,int ligne,int colonne,int val,char colonne_char)
{
        int cpt0_lig = 0;
        int cpt1_lig = 0;
        int cpt0_col = 0;
        int cpt1_col = 0;

        for (int i = 0; i < 4; i++)
        {
            if (grille[ligne][i] == 0) {
                cpt0_lig++;
            } else if (grille[ligne][i] == 1) {
                cpt1_lig++;
            }
        }

        for (int i = 0; i < 4; i++)
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
            if (cpt0_lig == 2)
            {
                printf("\n(R2D2): ");
                color(11,0);
                printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
                printf("        il y a deux 0 sur la ligne %d\n\n",ligne + 1);
                color(15,0);
                grille[ligne][colonne] = val;
            }
            else if (cpt0_col == 2)
            {
                printf("\n(R2D2): ");
                color(11,0);
                printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val, colonne_char,ligne + 1);
                printf("        il y a deux 0 sur la colonne %c\n\n",colonne_char);
                color(15,0);
                grille[ligne][colonne] = val;
            }
        }

        if (val == 0)
        {
            if (cpt1_lig == 2)
            {
                printf("\n(R2D2): ");
                color(11,0);
                printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
                printf("        il y a deux 1 sur la ligne %d\n\n",ligne + 1);
                color(15,0);
                grille[ligne][colonne] = val;
            }
            else if (cpt1_col == 2)
            {
                printf("\n(R2D2): ");
                color(11,0);
                printf("Je suis obliger de mettre un %d en [%c ; %d] car:\n",val,colonne_char,ligne + 1);
                printf("        il y a deux 1 sur la colonne %c\n\n",colonne_char);
                color(15,0);
                grille[ligne][colonne] = val;
            }
        }
}

//------------------------------------------------------------------------------------------------------------------------------------//

//on crée la fonction qui génère une grille de jeux correct 4x4
void generer_grille_4x4()
{

    int** solution = NULL;
    solution = creation_map_4x4_valide();

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

    print_map_4x4(solution);

    printf("(R2D2): ");
    color(11,0);
    printf("Voici la grille de takuzu 4x4 que vous avez commander\n\n");
    color(15,0);
    sleep(3);

    free_4x4(solution);

    int choix;
    do
    {
        printf("Selectionner: \n\n");
        printf("1 - pour generer une nouvelle grille de takuzu 4x4\n");
        printf("2 - retour au menu\n\n");
        printf("Saisissez le numero correspondant a votre choix:\n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 2));

    switch(choix)
    {
        case 1:
            generer_grille_4x4();
            break;
        case 2:
            menu_Generer_grille();
            break;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------//

//On crée une fonction qui libère l'espace de la mémoire de notre ordinateur
void free_4x4(int ** map)
{
    for(int i = 0; i < 4; i++)
    {
        free(map[i]);
    }
    free(map);
    map = NULL;
}

