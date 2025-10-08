#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "utils.h"

void adjust_dominant_color(Image *img, char dominant_color, int value); //fonction qui permets de Foncer/éclaircir les pixels avec une dominante
void convert_to_grayscale(Image *img); //Passer en noir et blanc en utilisant la moyenne des couleurs (niveaux de gris)
void create_negative(Image *img); //Créer le négatif de l'image (couleur complémentaire)
void display_size(const Image *img); //Afficher la taille (largeur x hauteur)
Image* crop_image(const Image *img, int l1, int l2, int c1, int c2); //Découper une partie de l'image entre les lignes l1, l2 et les colonnes c1 et c2
Image* apply_median_filter(const Image *img); //Appliquer le filtre médian sur l'image

#endif