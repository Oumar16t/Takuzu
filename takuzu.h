//
// Created by oumar on 31/03/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <windows.h>

#ifndef CODE_TAKUZU_H
#define CODE_TAKUZU_H

#endif //CODE_TAKUZU_H

/*Partie Menu*/
void menu_Principale();

void menu_Resoudre_grille();
void menu_Resoudre_grille_avc_masque_aleatoire();
void menu_Resoudre_grille_avec_masque_manuelle();

void menu_Resoudre_Automatiquement_grille();
void menu_Resoudre_Automatiquement_grille_avc_masque_manuelle();
void menu_Resoudre_Automatiquement_grille_avc_masque_aleatoire();

void menu_Generer_grille();
void generer_grille_4x4();
void generer_grille_8x8();
//-------------------------------------------------------------------------------------------------//

/*Partie 4x4*/
int** creation_map_4x4_valide();
int* binary_conversion_4x4(int val);
int inverse_ligne_4x4(int* ligne);

void print_map_4x4(int** map_4x4);

int** masque_4x4_aleatoire();
int** masque_4x4_manuelle();
int** grille_de_jeu_4x4(int** solution,int** masque);

void play_4x4(int** masque);

int coup_correct_remplit_4x4(int val,int** grille,int ligne,int colonne);
int coup_incorect_remplit_4x4(int val,int** grille,int ligne,int colonne);
int coup_bloque_remplit_4x4(int** grille, int ligne, int colonne);

int type_de_coup_4x4(int val,int** grille,int ligne,int colonne);

int compteur_grille_4x4(int** grille);

void play_4x4_auto(int** masque);
void phrase_coup_bot_remplit_4x4(int** grille,int ligne,int colonne,int val,char colonne_char);

void generer_grille_4x4();

//-------------------------------------------------------------------------------------------------//

/*Partie 8x8*/
int** creation_map_8x8_valide();
int* binary_conversion_8x8(int val);
int comparer_ligne_par3_suivi(int** solution, int ligne);
int comparer_colone_identique(int** matrice);
int comparer_colone_8x8(int** matrice);

void print_map_8x8(int** map_8x8);

int** masque_8x8_aleatoire();
int** masque_8x8_manuelle();
int** grille_de_jeu_8x8(int** solution,int** masque);

void play_8x8(int** masque);

int coup_correct_middle(int** grille,int val,int ligne,int colonne);
int coup_correct_haut_bas_gauche_droite(int val,int** grille,int ligne,int colonne);
int coup_correct_remplit_8x8(int val,int** grille,int ligne,int colonne);

int coup_incorrect_remplit_8x8(int val,int** grille,int ligne,int colonne);
int coup_incorrect_haut_bas_gauche_droite(int** grille,int val,int ligne,int colonne);
int coup_incorrect_middle(int** grille,int val,int ligne,int colonne);

int coup_bloque_remplit_8x8(int** grille, int ligne, int colonne);
int coup_bloque_encercler_8x8(int** grille, int ligne, int colonne);
int coup_bloque_deux_dafiler_de_chaque_8x8(int** grille, int ligne, int colonne);

int type_de_coup_8x8(int val,int** grille,int ligne,int colonne);

int compteur_grille_8x8(int** grille);

void play_8x8_auto(int** masque);
void phrase_coup_bot_remplit_8x8(int** grille,int ligne,int colonne,int val,char colonne_char);

void generer_grille_8x8();

//-------------------------------------------------------------------------------------------------//

/*Fonctions à ne pas oublier !*/
void color(int couleurDuTexte,int couleurDeFond);
void free_4x4(int** map);
void free_8x8(int** map);

