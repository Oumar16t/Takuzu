#include "takuzu.h"

//On cree notre menu principale qui sera notre point de depart
void menu_Principale()
{
    printf("\n\n %c ",4);
    color(13,0);
    printf("BIENVENU DANS LE MENU PRINCIPALE ");     // Comme il y est ecrit nous sommes dans le menu pricipale//
    color(15,0);                   // A travers lui on pourra accéder à tous les sous meneu de notre projet (c'est notre point de départ)//
    printf("%c \n\n\n",4);

    int choix = 0;
    do {
        printf("Ou souhaitez-vous aller ? \n\n");
        printf("1 - Resoudre une grille de Takuzu\n");
        printf("2 - Solution d'une grille de Takuzu\n");
        printf("3 - Generer une grille de Takuzu\n\n");
        printf("Saisissez le numero correspondant a votre choix:\n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    switch(choix)
    {
        case 1:
            menu_Resoudre_grille();
            break;                                           //Cette etape dépend du choix de l'utilisateur. En effet selon ce dernier il aura plus ou moin accée aux
        case 2:                                              //trois cas qui vous voyez. Qui ne sont qu'autre que les 3 parties du projet//
            menu_Resoudre_Automatiquement_grille();
            break;
        case 3:
            menu_Generer_grille();
            break;
    }
}

//-----------------------------------------------------------------------------------//

//On cree le menu de la pertie 1 du projet ou l'utilisateur pourra resoudre une grille de takuzu
void menu_Resoudre_grille()
{
    printf("\n\n %c ",4);
    color(13,0);
    printf("MENU RESOUDRE UNE GRILLE ");                                        //Ce menu correspond à la partie 1 du projet dans laqu'elle l'utilisateur
    color(15,0);                                             //resoudre grille de takuzu d'une certaine taille//
    printf("%c \n\n\n",4);

    int choix = 0;
    do {
        printf("Comment voulez-vouz resoudre la grille de takuzu ? \n\n");
        printf("1 - Avec saisi manuelle d'un masque \n");
        printf("2 - Avec saisi aleatoire d'un masque \n");
        printf("3 - Jouer \n");
        printf("4 - Revenir au menu principale \n\n");
        printf("Choisir le numero correspondant a votre choix: \n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 4));

    switch (choix) {
        case 1:
            menu_Resoudre_grille_avec_masque_manuelle();
            break;
        case 2:                                                    //Ici sont regroupé les trois action que l'utilisateur pourra effectué dans la partie 1 du projet//
            menu_Resoudre_grille_avc_masque_aleatoire();
            break;
        case 3:
            menu_Resoudre_grille_avc_masque_aleatoire();
            break;
        case 4:
            menu_Principale();                    //Presente dans tout les menu sauf dans le principale, ce cas permet à l'utilisateur s'il le souhaite de revenir en arrière//
            break;
    }
}

//on crée le menu dans lequel l'utilisateur pourra résoudre une grille generer de manière aléatoire
void menu_Resoudre_grille_avc_masque_aleatoire()
{
    int choix = 0;
    do {
        printf("Sur quelle taille de grille voulez vous jouer ? \n\n");
        printf("1 - 4x4  \n");
        printf("2 - 8x8 \n");                                               //Ici l'utilisateur pourra jouer sur une grille de takuzu de la taille de sont choix
        printf("3 - revenir au menu \n\n");                      // mais avec un mask prédefini//
        printf("Choisir le numero correspondant a votre choix: \n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    int **masque_4x4 = NULL;                // On initialise un mask pour chaque taille de grille qui seront remplit ensuite//
    int **masque_8x8 = NULL;

    switch (choix)
    {
        case 1:
            masque_4x4 = masque_4x4_aleatoire();
            play_4x4(masque_4x4);
            break;
        case 2:
            masque_8x8 = masque_8x8_aleatoire();                 //Après avoir initialiser les mask et que l'utilisateur et donner la taille de grille sur laqu'elle il
            play_8x8(masque_8x8);                        //souhaiter jouer. le mask4x4 ou 8x8 est remplit et est ensuite envoyer vers la fonction qui lancera
            break;                                              //la partie.
        case 3:
            menu_Resoudre_grille();
            break;
    }
}

//on crée le menu dans lequel l'utilisateur pourra résoudre une grille generer par l'utilisateur
void menu_Resoudre_grille_avec_masque_manuelle()
{
    int choix = 0;
    do {
        printf("Sur quelle taille de grille voulez vous jouer ? \n\n");
        printf("1 - 4x4  \n");
        printf("2 - 8x8 \n");                                               //Ici l'utilisateur pourra jouer mais cette fois-ci avec une grille qu'il aura//
        printf("3 - revenir au menu principale \n\n");                     //lui-meme crée//
        printf("Choisir le numero correspondant a votre choix: \n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    int **masque_4x4 = NULL;
    int **masque_8x8 = NULL;

    switch (choix) {
        case 1:
            masque_4x4 = masque_4x4_manuelle();
            play_4x4(masque_4x4);                                //Après avoir initialiser les mask et que l'utilisateur est donner la taille de grille sur laqu'elle il
            break;                                                      //souhaite jouer. Il pourra ensuite crée lui-meme la grille de takuzu//
        case 2:
            masque_8x8 = masque_8x8_manuelle();
            play_8x8(masque_8x8);
            break;
        case 3:
            menu_Resoudre_grille();
            break;
    }
}

//-----------------------------------------------------------------------------------//

//On cree le menu dans lequel l'utilisateur pourra observer un robot resoudre une grille de takuzu
void menu_Resoudre_Automatiquement_grille()
{
    printf("\n\n %c ",4);
    color(13,0);
    printf("RESOLUTION D'UNE GRILLE AVEC LE BOT ");                   //Ce menu correspond à la partie de 2 du projet dans laquel un bot lui expliquerra comment//
    color(15,0);                                   //resoudre une grille de takuzu//
    printf("-> ");
    color(13,0);
    printf("R2D2 ");
    color(15,0);
    printf("%c \n\n\n",4);

    int choix = 0;

    do {
        printf("Comment voulez-vous que la grille de takuzu soit resolue ? \n\n");
        printf("1 - Avec saisi manuelle d'un masque \n");
        printf("2 - Avec saisi aleatoire d'un masque \n");
        printf("3 - Revenir au menu principale \n\n");
        printf("Choisir le numero correspondant a votre choix: \n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    switch (choix)
    {
        case 1:
            menu_Resoudre_Automatiquement_grille_avc_masque_manuelle();
            break;
        case 2:                                                              //l'utilisateur à le choix entre observer R2D2 resoudre une grille aléatoire
            menu_Resoudre_Automatiquement_grille_avc_masque_aleatoire();     // ou l'observer resoudre une grille qu'il aura lui meme crée//
            break;
        case 3:
            menu_Principale();
            break;
    }
}

//On cree le menu dans lequel l'utilisateur pourra observer un robot resoudre une grille generer de manière aléatoire
void menu_Resoudre_Automatiquement_grille_avc_masque_aleatoire()
{
    int choix = 0;
    do {
        printf("Sur quelle taille de grille voulez-vous qu'elle soit resolue ? \n\n");
        printf("1 - 4x4  \n");
        printf("2 - 8x8 \n");
        printf("3 - revenir au menu principale \n\n");
        printf("Choisir le numero correspondant a votre choix: \n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    int **masque_4x4 = NULL;
    int **masque_8x8 = NULL;

    switch (choix)
    {
        case 1:
            masque_4x4 = masque_4x4_aleatoire();
            play_4x4_auto(masque_4x4);
            break;
        case 2:
            masque_8x8 = masque_8x8_aleatoire();
            play_8x8_auto(masque_8x8);
            break;
        case 3:
            menu_Resoudre_Automatiquement_grille();
            break;
    }
}

//On cree le menu dans lequel l'utilisateur pourra observer un robot resoudr eune grille generer par l'utilisateur
void  menu_Resoudre_Automatiquement_grille_avc_masque_manuelle()
{

    int choix = 0;
    do {
        printf("Sur quelle taille de grille voulez-vous qu'elle soit resolue ? \n\n");
        printf("1 - 4x4  \n");
        printf("2 - 8x8 \n");
        printf("3 - revenir au menu principale \n\n");
        printf("Choisir le numero correspondant a votre choix: \n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    int **masque_4x4 = NULL;
    int **masque_8x8 = NULL;

    switch (choix)
    {
        case 1:
            masque_4x4 = masque_4x4_manuelle();
            play_4x4_auto(masque_4x4);
            break;
        case 2:
            masque_8x8 = masque_8x8_manuelle();
            play_8x8_auto(masque_8x8);
            break;
        case 3:
            menu_Resoudre_Automatiquement_grille();
            break;
    }
}

//-----------------------------------------------------------------------------------//

//on cree le menu dans lequel l'utilisateur pourra generer une grille de la taille souhaité
void menu_Generer_grille()
{
    printf("\n\n %c ",4);
    color(13,0);
    printf("MENU GENERER UNE GRILLE ");                   //Ce dernier sous menu correspond à la pertie 3 du prjet ou l'utilisateur pourra
    color(15,0);                       //générer autant de grille qu'il souhaite//
    printf("%c \n\n\n",4);

    int choix = 0;

    do {
        printf("Quelle est la taille de la grille que vous-voulez generer ? \n\n");
        printf("1 - 4x4  \n");
        printf("2 - 8x8 \n");
        printf("3 - revenir au menu principale \n\n");
        printf("Choisir le numero correspondant a votre choix: \n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    switch (choix) {
        case 1:
            generer_grille_4x4();
            break;
        case 2:
            generer_grille_8x8();
            break;
        case 3:
            menu_Principale();
            break;

    }
}

//-----------------------------------------------------------------------------------//

//cette fonction permet de mettre des couleur sur tout le projet mors de l'affichage//
void color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
};