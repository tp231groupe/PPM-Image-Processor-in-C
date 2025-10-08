#include "../lib/utils.h"
#include "../lib/ppm_io.h"


/**
 * @brief Lit un fichier image PPM (format P3) et le charge en mémoire.
 *
 * Cette fonction lit l'en-tête (version, largeur, hauteur, max_color_val), alloue
 * dynamiquement la mémoire pour la structure Image et son tableau de pixels, puis
 * lit toutes les données de couleur.
 *
 * @param filename Le nom du fichier PPM à lire.
 * @return Un pointeur vers la NOUVELLE structure Image remplie, ou NULL en cas d'erreur
 * (fichier non trouvé, format invalide, allocation mémoire échouée, etc.).
 */
Image* read_ppm(const char *filename) {

    Image *img;
    img = malloc(sizeof(Image));
    char maggic_number[3];
    FILE *file = fopen(filename, "r");
    

    fscanf(file, "%2s", &img->magic_number);
    //skip_comments(file);
    fscanf(file, "%u %u", &img->width, &img->height);
    //skip_comments(file);
    fscanf(file, "%u", &img->max_val);

    img->pixels = malloc(img->height * sizeof(Pixel*));
    for(int i = 0; i < img->height; i++)
        img->pixels[i] = malloc(img->width * sizeof(Pixel));
    for(int i = 0; i< img->height; i++){
        for(int j = 0; j < img->width; j++){
            unsigned r, g, b;
            fscanf(file, "%u %u %u", &r,&g,&b);
            img->pixels[i][j].r = r;
            img->pixels[i][j].g = g;
            img->pixels[i][j].b = b;
        }
    }

    fclose(file);
    return img;
}

/**
 * @brief Sauvegarde la structure Image en mémoire dans un nouveau fichier PPM (format P3).
 *
 * Écrit l'en-tête de l'image, puis les données de pixels, en format texte.
 *
 * @param filename Le nom du fichier PPM de destination (fichier_resultat.ppm).
 * @param img Pointeur constant vers la structure Image à sauvegarder.
 * @param text Le nom a ajouter au fichier generer en fonction des operations effectues sur une autre image pour l'obtenir
 * @return 0 en cas de succès, -1 en cas d'erreur (échec de l'ouverture du fichier).
 */
void generate_ppm(const char *filename, const Image *img, char *text){
    // 1. Ouvrir le fichier en mode écriture (utiliser fopen) ; vérifier le succès.
    // 2. Écrire l'en-tête du fichier PPM en utilisant fprintf :
    //    a. Version (P3).
    //    b. Largeur et Hauteur.
    //    c. Valeur Maximale de Couleur (Ex: 255).
    // 3. Boucler à travers le tableau de pixels (img->pixels).
    // 4. Pour chaque pixel, écrire ses trois composantes de couleur (R, G, B) en tant qu'entiers séparés par des espaces ou des sauts de ligne.
    // 5. Fermer le fichier.
    // 6. Retourner 0.

    char new_filename[512]; 
    char *dot = strrchr(filename, '.');
    size_t len = dot - filename;
    strncpy(new_filename, filename, len);
    new_filename[len] = '\0';

    strcat(new_filename, "-generate");
    strcat(new_filename, dot);  // ajoute ".ppm"
    
    FILE *file = fopen(new_filename,"w");
    
    fprintf(file, "%s\n", img->magic_number);
    fprintf(file, "%u %u\n", img->width, img->height);
    fprintf(file, "%u\n", img->max_val);

    for(int i = 0; i< img->height; i++){
        for(int j = 0; j < img->width; j++){
            fprintf(file, "%u %u %u", img->pixels[i][j].r ,img->pixels[i][j].g,img->pixels[i][j].b);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}


/**
 * @brief Libère toute la mémoire allouée dynamiquement pour la structure Image.
 *
 * Cette fonction doit libérer d'abord le tableau de pixels, puis la structure Image elle-même.
 *
 * @param img Pointeur vers la structure Image à libérer.
 */
void free_image(Image *img) {
    // 1. Vérifier si le pointeur img n'est pas NULL.
    // 2. Si img->pixels n'est pas NULL, libérer la mémoire du tableau de pixels (free(img->pixels)).
    // 3. Libérer la mémoire de la structure Image elle-même (free(img)).
    // 4. (Optionnel mais recommandé) Mettre le pointeur 'img' à NULL après l'avoir libéré pour éviter les "dangling pointers".

    if (img == NULL) {
        return; // Rien à libérer
    }

    if (img->pixels != NULL) {
        free(img->pixels);
        img->pixels = NULL;
    }

    free(img);
}