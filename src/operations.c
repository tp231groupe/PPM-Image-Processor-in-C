#include "../lib/utils.h"
#include "../lib/operations.h"


/**
 * @brief Fonce ou éclaircit les pixels d'une image dont la couleur dominante correspond à la couleur spécifiée.
 *
 * L'opération est effectuée sur place.
 * Le pixel est fonçé si 'value' est positive (ajout de 'value'), et éclairci si 'value' est négative (soustraction de 'value)[cite: 39, 41, 54].
 * Seuls les pixels dont la couleur dominante (la composante ayant l'entier le plus grand) correspond à 'dominant_color' sont modifiés[cite: 37, 38].
 * Les nouvelles composantes de couleur doivent être bornées (écrêtées) entre 0 et la valeur maximale de couleur (255 dans l'exemple)[cite: 6].
 *
 * @param img Pointeur vers la structure Image à modifier.
 * @param dominant_color Caractère représentant la couleur dominante à cibler ('R', 'G', ou 'B').
 * @param value Entier à ajouter (foncer, value > 0) ou à soustraire (éclaircir, value < 0) à chacune des composantes R, G, et B du pixel[cite: 53, 54].
 */
void adjust_dominant_color(Image *img, char dominant_color, int value){ // <-- RAISSA
    // 1. Parcourir tous les pixels dans le tableau img->pixels.
    // 2. Pour chaque pixel, déterminer sa couleur dominante (la plus grande valeur parmi R, G, B)[cite: 38].
    // 3. Vérifier si la dominante du pixel correspond à l'argument 'dominant_color'.
    // 4. Si elles correspondent :
    //    a. Calculer les nouvelles valeurs R, G, B en ajoutant 'value' à chacune.
    //    b. Utiliser la fonction d'écrêtage (CLAMP) pour garantir que les nouvelles valeurs restent dans l'intervalle [0, 255].
    //    c. Mettre à jour les composantes R, G, B du pixel avec les valeurs écrêtées.

    if (!img || !img->pixels) return;

    for (unsigned i = 0; i < img->height; i++) {
        for (unsigned j = 0; j < img->width; j++) {
            Pixel *p = &img->pixels[i][j];

            // Utilise ton utilitaire pour déterminer la couleur dominante
            char max_color = find_max_rgb(p->r, p->g, p->b);

            if (max_color == dominant_color) {
                p->r = clamp(p->r + value);
                p->g = clamp(p->g + value);
                p->b = clamp(p->b + value);
            }
        }
    }
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
            
            int sum = (int)pixy->r + (int)pixy->g + (int)pixy->b;
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

    if (!img || !img->pixels) return;

    for (unsigned i = 0; i < img->height; i++) {
        for (unsigned j = 0; j < img->width; j++) {
            Pixel *p = &img->pixels[i][j];

            p->r = img->max_val - p->r;
            p->g = img->max_val - p->g;
            p->b = img->max_val - p->b;

            // Si tu veux assurer l'écrêtage (au cas où max_val != 255)
            p->r = clamp(p->r);
            p->g = clamp(p->g);
            p->b = clamp(p->b);
        }
    }
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

    printf(ANSI_COLOR_BLUE "%u x %u\n" ANSI_COLOR_RESET, img->width, img->height);

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

    if (l1 >= l2 || l2 > img->height || c1 >= c2 || c2 > img->width || l1 < 1 || c1 < 1) {
        return NULL;
    }
    int new_h = l2 - l1;
    int new_w = c2 - c1;
    Image *new_img = malloc(sizeof(Image));
    if (new_img == NULL) return NULL;
    strcpy(new_img->magic_number, img->magic_number);
    new_img->width = new_w;
    new_img->height = new_h;
    new_img->max_val = img->max_val;
    new_img->pixels = malloc(new_h * sizeof(Pixel*));
    if (new_img->pixels == NULL) {
        free(new_img);
        return NULL;
    }
    for(int i = 0; i < new_h; i++){
        new_img->pixels[i] = malloc(new_w * sizeof(Pixel));
        if (new_img->pixels[i] == NULL) {
            for(int k=0; k<i; k++) free(new_img->pixels[k]);
            free(new_img->pixels);
            free(new_img);
            return NULL;
        }
        for(int j=0; j<new_w; j++){
            new_img->pixels[i][j] = img->pixels[l1-1 + i][c1-1 + j];
        }
    }
    return new_img;
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

int compare_uint(const void *a, const void *b) {
    return (*(unsigned char*)a) - (*(unsigned char*)b);
}

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


    if (!img || !img->pixels) return NULL;

    int h = img->height;
    int w = img->width;

    // 1. Allouer la nouvelle image
    Image *result = malloc(sizeof(Image));
    if (!result) return NULL;

    strcpy(result->magic_number, img->magic_number);
    result->width = w;
    result->height = h;
    result->max_val = img->max_val;

    result->pixels = malloc(h * sizeof(Pixel*));
    if (!result->pixels) {
        free(result);
        return NULL;
    }

    for (int i = 0; i < h; i++) {
        result->pixels[i] = malloc(w * sizeof(Pixel));
        if (!result->pixels[i]) {
            for (int k = 0; k < i; k++) free(result->pixels[k]);
            free(result->pixels);
            free(result);
            return NULL;
        }
    }

    // 2. Parcourir chaque pixel
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            unsigned char neighbors_r[9], neighbors_g[9], neighbors_b[9];
            int count = 0;

            // Collecte des voisins (3x3)
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                        neighbors_r[count] = img->pixels[ni][nj].r;
                        neighbors_g[count] = img->pixels[ni][nj].g;
                        neighbors_b[count] = img->pixels[ni][nj].b;
                        count++;
                    }
                }
            }

            // Trier les voisins et prendre la médiane
            qsort(neighbors_r, count, sizeof(unsigned char), compare_uint);
            qsort(neighbors_g, count, sizeof(unsigned char), compare_uint);
            qsort(neighbors_b, count, sizeof(unsigned char), compare_uint);

            int median_index = count / 2;
            result->pixels[i][j].r = neighbors_r[median_index];
            result->pixels[i][j].g = neighbors_g[median_index];
            result->pixels[i][j].b = neighbors_b[median_index];
        }
    }

    return result;

}