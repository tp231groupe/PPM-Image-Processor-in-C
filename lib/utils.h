#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definition de la structure pixel
typedef struct {
    unsigned char r, g, b; // Couleur RGB (0 à 255)
} Pixel;

typedef struct {
    char magic_number[3];    // Ex: "P3"
    unsigned width, height;  // Largeur et hauteur en pixels
    unsigned max_val;  // Valeur maximale (Ex: 255)
    Pixel **pixels;      // Tableau dynamique des pixels
} Image;

unsigned find_max_rgb(unsigned r, unsigned g, unsigned b);
unsigned clamp(int value); // Fonction utilitaire qui s'assurer que les valeurs restent entre 0 et 255 (Clamping).
bool fileExist(const char *chemin_fichier);
char *generate_file_name(char *input_file, char *operation);
#endif