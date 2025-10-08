#include "../lib/utils.h"
#include "../lib/operations.h"

void adjust_dominant_color(Image *img, char dominant_color, int value){ // <-- RAISSA
    // 1. Parcourir tous les pixels dans le tableau img->pixels.
    // 2. Pour chaque pixel, déterminer sa couleur dominante (la plus grande valeur parmi R, G, B)[cite: 38].
    // 3. Vérifier si la dominante du pixel correspond à l'argument 'dominant_color'.
    // 4. Si elles correspondent :
    //    a. Calculer les nouvelles valeurs R, G, B en ajoutant 'value' à chacune.
    //    b. Utiliser la fonction d'écrêtage (CLAMP) pour garantir que les nouvelles valeurs restent dans l'intervalle [0, 255].
    //    c. Mettre à jour les composantes R, G, B du pixel avec les valeurs écrêtées.

    //code here
}

/**
 * @brief Convertit l'image en noir et blanc en utilisant les niveaux de gris.
 *
 * L'opération est effectuée sur place.
 * [cite_start]Le niveau de gris est obtenu en donnant aux trois composantes la valeur moyenne des trois valeurs d'origine[cite: 43].
 *
 * @param img Pointeur vers la structure Image à modifier.
 */
void convert_to_grayscale(Image *images){ //Responsable<-- FATIMATOU Njapndounke 
    // 1. Parcourir tous les pixels dans le tableau img->pixels.
    // 2. Pour chaque pixel (r, g, b):
    //    a. Calculer la valeur moyenne : moyenne = (r + g + b) / 3.
    //    b. Affecter cette moyenne aux trois composantes R, G, et B du pixel (r = moyenne, g = moyenne, et b = moyenne).

   

    // Vérification de sécurité
    if (images == NULL || images->pixels == NULL) {
        return;
    }

    unsigned width = images->width;
    unsigned height = images->height;

    
    for (unsigned i = 0; i < height; i++) {      
        for (unsigned j = 0; j < width; j++) {    
            Pixel *pixy = &images->pixels[i][j];
            
            int sum = pixy->r + pixy->g + pixy->b;
            unsigned char moy = (unsigned char)(sum / 3);
            pixy->r = moy;
            pixy->g = moy;
            pixy->b = moy;
        }
    }
}



/**
 * @brief Crée le négatif de l'image en changeant chaque couleur par son complémentaire.
 *
 * L'opération est effectuée sur place.
 * [cite_start]La couleur complémentaire est calculée comme : nouvelle_valeur = max_color_val - valeur_actuelle[cite: 44].
 *
 * @param img Pointeur vers la structure Image à modifier.
 */
void create_negative(Image *img){ // <-- CALEB
    // 1. Parcourir tous les pixels dans le tableau img->pixels.
    // 2. Pour chaque pixel :
    //    a. Calculer nouveau_R = img->max_color_val - R.
    //    b. Calculer nouveau_G = img->max_color_val - G.
    //    c. Calculer nouveau_B = img->max_color_val - B.
    // 3. Mettre à jour les composantes R, G, B du pixel avec les nouvelles valeurs.

    //code here
}


/**
 * [cite_start]@brief Affiche la taille de l'image (largeur x hauteur) en nombre de pixels[cite: 46].
 *
 * La fonction lit la largeur et la hauteur depuis l'en-tête de l'image.
 *
 * @param img Pointeur constant vers la structure Image (aucune modification).
 */
void display_size(const Image *img){
    // 1. Accéder aux champs img->width (largeur) et img->height (hauteur) de la structure.
    // 2. Afficher les dimensions sur la sortie standard au format "largeur x hauteur" (ex: "100x205").

    printf("%u x %u", img->width, img->height);

}


/**
 * @brief Découpe une section de l'image et retourne une NOUVELLE structure Image.
 *
 * [cite_start]La fonction valide les coordonnées de découpe (l1 < l2 <= hauteur et c1 < c2 <= largeur)[cite: 61].
 *
 * @param img Pointeur constant vers la structure Image originale.
 * @param l1 Ligne de début (inclusive, index 1-basé).
 * @param l2 Ligne de fin (exclusive, index 1-basé).
 * @param c1 Colonne de début (inclusive, index 1-basé).
 * @param c2 Colonne de fin (exclusive, index 1-basé).
 * @return Pointeur vers la NOUVELLE structure Image contenant la partie découpée, ou NULL si les coordonnées sont invalides.
 */

Image* crop_image(const Image *img, int l1, int l2, int c1, int c2){ // <-- MAR'RYAM
    // 1. Valider les coordonnées : Vérifier si l1 < l2 <= img->height ET c1 < c2 <= img->width[cite: 61].
    // 2. Si les coordonnées sont invalides, retourner NULL (ou gérer l'erreur).
    // 3. Calculer la nouvelle largeur (new_w = c2 - c1) et la nouvelle hauteur (new_h = l2 - l1).
    // 4. Allouer dynamiquement la mémoire pour la nouvelle structure Image et son nouveau tableau de pixels (taille : new_w * new_h).
    // 5. Copier les informations d'en-tête (version, max_color_val) de l'image originale.
    // 6. Définir la largeur et la hauteur de la nouvelle image à new_w et new_h.
    // 7. Parcourir les pixels *originaux* qui correspondent à la région de découpe (en utilisant les indices 0-basés : l1-1 à l2-1 et c1-1 à c2-1).
    // 8. Copier les données des pixels de l'image originale vers le nouveau tableau de pixels, en s'assurant de la bonne séquence ligne par ligne.
    // 9. Retourner le pointeur vers la nouvelle structure Image.

    //code here
}


/**
 * @brief Applique le filtre médian à l'image et retourne une NOUVELLE structure Image.
 *
 * Le filtre remplace chaque composante de couleur d'un pixel par la valeur médiane [cite: 47] de
 * l'ensemble de la même composante des pixels de son voisinage (8 voisins, soit 9 valeurs au total).
 * L'opération doit être effectuée sur une NOUVELLE image pour éviter que le filtre ne se propage.
 *
 * @param img Pointeur constant vers la structure Image originale.
 * @return Pointeur vers la NOUVELLE structure Image avec le filtre appliqué.
*/

Image* apply_median_filter(const Image *img){ //<--Cedric
    // 1. Allouer dynamiquement la mémoire pour une NOUVELLE structure Image (resultat) de même taille que l'originale.
    // 2. Copier les informations d'en-tête (version, largeur, hauteur, max_color_val).
    // 3. Parcourir chaque pixel (i, j) de l'image. Gérer les pixels de bordure (qui n'ont pas 8 voisins).
    // 4. Pour chaque pixel (i, j) :
    //    a. Collecter les 9 valeurs Rouges (R) du pixel (i, j) et de ses 8 voisins.
    //    b. Trier ces 9 valeurs R.
    //    c. [cite_start]La **médiane** (la 5ème valeur) devient la nouvelle valeur R du pixel (i, j) dans l'image 'resultat'[cite: 47].
    //    d. Répéter les étapes 4a-4c séparément pour les composantes Vertes (G) et Bleues (B).
    // 5. Stocker les trois nouvelles valeurs R, G, B médianes dans le tableau de pixels de l'image 'resultat' à l'index (i, j).
    // 6. Retourner le pointeur vers la NOUVELLE structure Image.


    //code here

}