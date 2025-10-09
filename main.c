#include "lib/utils.h"
#include "lib/ppm_io.h"
#include "lib/operations.h"
#include <ctype.h>

#ifdef _WIN32
    #define STRCMP_CASE_INSENSITIVE _stricmp
#else
    #define STRCMP_CASE_INSENSITIVE strcasecmp
#endif


int main(){

    while (true){
        printf(ANSI_COLOR_GREEN "ppviewer>" ANSI_COLOR_RESET);
        char input[MAX_INPUT_SIZE];

        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }
       
        input[strcspn(input, "\n")] = 0;
        char* command = strtok(input, " ");

        if(command == NULL)
            continue;
        
        if(STRCMP_CASE_INSENSITIVE(command, "quit") == 0)
            exit(EXIT_SUCCESS);
        
        else if(STRCMP_CASE_INSENSITIVE(command, "gris") == 0 || STRCMP_CASE_INSENSITIVE(command, "neg") == 0 || STRCMP_CASE_INSENSITIVE(command, "fil") == 0){
            char *inputFile = strtok(NULL," ");
            char *outputFile = strtok(NULL," ");

            if(inputFile == NULL){
                printf(ANSI_COLOR_RED "Erreur: la commande %s necessite un fichier en entree\n" ANSI_COLOR_RESET, command);
                continue;
            }

            if(!outputFile)
                outputFile = generate_file_name(inputFile, command);
            
            if(!fileExist(inputFile)){
                printf(ANSI_COLOR_RED "Erreur: fichier introuvable\n" ANSI_COLOR_RESET);
                continue;
            }

            Image *img = read_ppm(inputFile);
            if (img != NULL) {
                // if 'gris' : convert_to_grayscale(img); // Opération sur place       
                if(STRCMP_CASE_INSENSITIVE(command, "gris") == 0){
                    convert_to_grayscale(img);

                    generate_ppm(outputFile, img);
                    const char *basename = strrchr(outputFile, '/');

                    if (!basename) 
                        basename = strrchr(outputFile, '\\');
                    if (basename) 
                        basename++;  // sauter le slash

                    printf(ANSI_COLOR_BLUE "🎉 Voilà votre fichier : %s !\n" ANSI_COLOR_RESET , basename ? basename : outputFile);
                }

                // if 'fil' : img = apply_median_filter(img); // Opération retournant une nouvelle image
                if(STRCMP_CASE_INSENSITIVE(command, "fil") == 0){
                    Image *fil_img = apply_median_filter(img);
                    if (fil_img != NULL) {
                        generate_ppm(outputFile, fil_img);
                        const char *basename = strrchr(outputFile, '/');
                        if (!basename) basename = strrchr(outputFile, '\\');
                        if (basename) basename++;  // sauter le slash

                        printf(ANSI_COLOR_BLUE "🎉 Voilà votre fichier : %s !\n" ANSI_COLOR_RESET , basename ? basename : outputFile);
                        //printf(ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, outputFile);
                        free_image(fil_img);
                    } else {
                        printf(ANSI_COLOR_RED "Erreur: Filtrage de l'image échoué.\n" ANSI_COLOR_RESET);
                    }
                }
                // if 'neg' : create_negative(Image *img);
                if(STRCMP_CASE_INSENSITIVE(command, "neg") == 0){
                    create_negative(img);
                    generate_ppm(outputFile, img);
                    const char *basename = strrchr(outputFile, '/');

                    if (!basename) 
                        basename = strrchr(outputFile, '\\');
                    if (basename) 
                        basename++;  // sauter le slash

                    printf(ANSI_COLOR_BLUE "🎉 Voilà votre fichier : %s !\n" ANSI_COLOR_RESET , basename ? basename : outputFile);
                }
                // write_ppm(outputFile, img, text);
                free_image(img);
            }
        }
        
        else if (STRCMP_CASE_INSENSITIVE(command, "size") == 0) {
            char* inputFile = strtok(NULL, " ");

            if (inputFile == NULL) {
                printf(ANSI_COLOR_RED "Erreur: La commande size necessite un nom de fichier.\n" ANSI_COLOR_RESET);
                continue;
            }

            // ... Validation fileExist(inputFile) ...
            if(!fileExist(inputFile)){
                printf( ANSI_COLOR_RED "Erreur: fichier introuvable %s \n" ANSI_COLOR_RESET, inputFile);
                continue;
            }

            Image *img = read_ppm(inputFile);

            if (img != NULL) {
                display_size(img);
                free_image(img);
            }
        }
        // --- COMMANDE COMPLEXE 'DOM' (avec 4 arguments) ---
        else if (STRCMP_CASE_INSENSITIVE(command, "dom") == 0) {
            char* domColor = strtok(NULL, " ");   // Ex: 'R'
            char* strValue = strtok(NULL, " ");   // Ex: '4'
            char* inputFile = strtok(NULL, " ");  // Ex: 'image1.ppm'
            char* outputFile = strtok(NULL, " "); // Ex: 'resultat.ppm'

            if (domColor == NULL || strValue == NULL || inputFile == NULL) {
                printf(ANSI_COLOR_RED "Erreur: Usage dom <couleur> <valeur> <input_file>.\n" ANSI_COLOR_RESET);
                continue;
            }
            
            if(outputFile == NULL)
                outputFile = generate_file_name(inputFile, command);
            
            // ... Conversion de strValue en int (utiliser atoi) ...
            int value = atoi(strValue);

            // ... Validation de domColor (doit être 'R', 'G', ou 'B') ...
            char color = toupper((unsigned char)domColor[0]);
            if (color != 'R' && color != 'G' && color != 'B') {
                printf(ANSI_COLOR_RED "Erreur: couleur dominante invalide (R, G ou B attendus).\n" ANSI_COLOR_RESET);
                continue;
            }

            // ... Appeler read_ppm, adjust_dominant_color, write_ppm ...
            Image *img = read_ppm(inputFile);
            if (img == NULL) {
                printf(ANSI_COLOR_RED "Erreur: impossible de lire le fichier %s\n" ANSI_COLOR_RESET, inputFile);
                continue;
            }

            // Appliquer l'ajustement de couleur dominante
            adjust_dominant_color(img, color, value);

            // Sauvegarder l'image
            generate_ppm(outputFile, img);

            // Extraire seulement le nom du fichier sans chemin pour l'affichage
            const char *basename = strrchr(outputFile, '/');
            if (!basename) 
                basename = strrchr(outputFile, '\\');
            if (basename) 
                basename++;  // sauter le slash

            printf(ANSI_COLOR_BLUE "🎉 Voilà votre fichier : %s !\n" ANSI_COLOR_RESET, basename ? basename : outputFile);

            free_image(img);
        }

        // --- COMMANDE TRÈS COMPLEXE 'CUT' (avec 6 arguments) ---
        else if (STRCMP_CASE_INSENSITIVE(command, "cut") == 0) {

            // Récupérer les 6 jetons nécessaires l1 l2 c1 c2 fichier_entree fichier_resultat
            char *inputFile = strtok(NULL, " ");
            char *strL1 = strtok(NULL, " ");
            char *strL2 = strtok(NULL, " ");
            char *strC1 = strtok(NULL, " ");
            char *strC2 = strtok(NULL, " ");
            char *outputFile= strtok(NULL, " ");

            // ... récupérer strL2, strC1, strC2, inputFile, outputFile ...

            if (inputFile == NULL || strL1 == NULL || strL2 == NULL || strC1 == NULL || strC2 == NULL) {
                printf(ANSI_COLOR_RED "Erreur: Usage cut <l1> <l2> <c1> <c2> <input_file>.\n" ANSI_COLOR_RESET);
                continue;
            }

            if(!fileExist(inputFile)){
                printf(ANSI_COLOR_RED"Erreur: fichier %s introuvable"ANSI_COLOR_RESET, inputFile);
                continue;
            }

            if (outputFile == NULL){
                outputFile = generate_file_name(inputFile, command);
            }

            // ... Conversion des coordonnées strL1, strL2, strC1, strC2 en int ...
            int l1 = atoi(strL1);
            int l2 = atoi(strL2);
            int c1 = atoi(strC1);
            int c2 = atoi(strC2);

            // ... Appeler read_ppm, crop_image, write_ppm ...
            Image *img = read_ppm(inputFile);
            if (img == NULL) {
                continue;
            }
            
            if (l1 < 0 || l2 >= img->height || c1 < 0 || c2 >= img->width || l1 > l2 || c1 > c2) {
                printf(ANSI_COLOR_RED "Erreur: coordonnées de découpe invalides.\n" ANSI_COLOR_RESET);
                free_image(img);
                continue;
            }
            Image *cropped_img = crop_image(img, l1, l2, c1, c2);

            if (cropped_img != NULL) {
                generate_ppm(outputFile, cropped_img);
                const char *basename = strrchr(outputFile, '/');
                if (!basename) basename = strrchr(outputFile, '\\');
                if (basename) basename++;  // sauter le slash

                printf(ANSI_COLOR_BLUE "🎉 Voilà votre fichier : %s !\n" ANSI_COLOR_RESET , basename ? basename : outputFile);
                //printf(ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, outputFile);
                free_image(cropped_img);
            } else {
                printf(ANSI_COLOR_RED "Erreur: Découpage de l'image échoué.\n" ANSI_COLOR_RESET);
            }

        }
        
        // --- COMMANDE INCONNUE ---
        else {
            printf(ANSI_COLOR_RED "Erreur: Commande '%s' introuvable.\n" ANSI_COLOR_RESET, command);
        }
    }
    return 0;
}