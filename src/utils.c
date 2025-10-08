#include "../lib/utils.h"

/**
 * @brief Détermine la valeur maximale parmi les trois composantes de couleur d'un pixel.
 *
 * Cette fonction sert à identifier la couleur dominante d'un pixel, qui est celle
 * ayant la plus grande valeur entière.
 *
 * @param r La composante Rouge (entre 0 et 255).
 * @param g La composante Verte (entre 0 et 255).
 * @param b La composante Bleue (entre 0 et 255).
 * @return La valeur maximale (R, G, ou B), au format unsigned char.
*/

unsigned find_max_rgb(unsigned r, unsigned g, unsigned b){
    // 1. Initialiser une variable 'max' avec la valeur de r.
    // 2. Comparer 'max' avec g et mettre à jour si g > max.
    // 3. Comparer 'max' avec b et mettre à jour si b > max.
    // 4. Retourner 'max'.
    // Puisque les valeurs sont déjà garanties dans [0, 255] par la structure Pixel,
    // l'utilisation de 'unsigned char' en entrée et en sortie est la plus appropriée.

    unsigned max = r; 

    if (g > max) {
        max = g;
    }

    if (b > max) {
        max = b;
    }

    return max;
}


/**
 * @brief Limite une valeur entière dans la plage valide des couleurs [0, 255].
 *
 * Cette fonction est cruciale pour les opérations de modification de couleur
 * (foncer/éclaircir, négatif) afin de s'assurer que les valeurs restent dans
 * la plage 8-bit.
 *
 * @param value La valeur entière potentiellement hors de la plage [0, 255].
 * @return La valeur limitée (0, 255, ou la valeur d'origine) au format unsigned char.
 */
unsigned clamp(int value){
    // 1. Si value < 0, retourner 0.
    // 2. Si value > 255, retourner 255.
    // 3. Sinon, retourner la valeur d'origine.
    // (Note : le retour doit être casté en unsigned char si la valeur d'origine est un int.)

    if (value < 0) {
        return 0;
    } 
    
    else if (value > 255) {
        return 255;
    } 
    
    else {
        return (unsigned char)value;
    }
}

bool fileExist(const char *chemin_fichier) {
    FILE *fp;
    
    fp = fopen(chemin_fichier, "rb");

    if (fp != NULL) {
        fclose(fp); 
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Génère un nom de fichier de sortie basé sur le fichier d'entrée et l'opération.
 *
 * Ex: generate_file_name("image1.ppm", "gris") retourne "image1gris.ppm".
 *
 * @note ATTENTION : L'implémentation doit allouer dynamiquement la mémoire
 * pour éviter de retourner un pointeur vers la pile (variable locale).
 *
 * @param input_file La chaîne de caractères représentant le nom du fichier d'entrée.
 * @param operation La chaîne de caractères décrivant l'opération effectuée (ex: "gris", "neg", "cut").
 * @return Un pointeur vers une chaîne de caractères allouée dynamiquement 
 * contenant le nouveau nom de fichier de sortie.
 */
char *generate_file_name(char *input_file, char *operation){


    char output_file_name[512]; 
    char *dot = strrchr(input_file, '.');
    size_t len = dot - input_file;
    strncpy(output_file_name, input_file, len);
    output_file_name[len] = '\0';

    strcat(output_file_name, operation);
    strcat(output_file_name, dot);  // ajoute ".ppm"

    return output_file_name;

}