#include "../lib/utils.h"
#include "../lib/ppm_io.h"
#include "../lib/operations.h"


#define MAX_INPUT_SIZE 256

#define ANSI_COLOR_GREEN   "\x1b[32m"

#define ANSI_COLOR_RESET   "\x1b[0m"


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
        
        if(strcmp(command, "quit") == 0)
            exit(EXIT_SUCCESS);
        
        else if(strcmp(command, "gris") == 0 || strcmp(command, "neg") == 0 || strcmp(command, "gris") == 0){
            char *inputFile = strtok(input," ");
            char *outputFile = strtok(input," "), *text;

            if(inputFile == NULL){
                printf("Erreur: la commande %s necessite un fichier en entree", command);
                continue;
            }

            if(outputFile == NULL)
                strcpy(text,command);
            
            if(!fileExist(inputFile)){
                printf("Erreur: fichier introuvable");
                continue;
            }

            Image *img = read_ppm(inputFile);
            if (img != NULL) {
                // if 'gris' : convert_to_grayscale(img); // Opération sur place
                // if 'fil' : img = apply_median_filter(img); // Opération retournant une nouvelle image
                // ...
                // write_ppm(outputFile, img, text);
                // free_image(img);
            }

            else if (strcmp(command, "size") == 0) {
                char* inputFile = strtok(NULL, " ");
                if (inputFile == NULL) {
                    printf("Erreur: La commande size nécessite un nom de fichier.\n");
                    continue;
                }
                // ... Validation fileExist(inputFile) ...
                if(!fileExist(inputFile)){
                    printf("Erreur: fichier introuvable");
                    continue;
                }

                Image *img = read_ppm(inputFile);
                if (img != NULL) {
                    display_size(img);
                    free_image(img);
                }
            }
        }

        // --- COMMANDE COMPLEXE 'DOM' (avec 4 arguments) ---
        else if (strcmp(command, "dom") == 0) {
            char* domColor = strtok(NULL, " ");   // Ex: 'R'
            char* strValue = strtok(NULL, " ");   // Ex: '4'
            char* inputFile = strtok(NULL, " ");  // Ex: 'image1.ppm'
            char* outputFile = strtok(NULL, " "); // Ex: 'resultat.ppm'

            if (domColor == NULL || strValue == NULL || inputFile == NULL) {
                printf("Erreur: Usage dom <couleur> <valeur> <input_file>.\n");
                continue;
            }
            
            if(outputFile == NULL)
                outputFile = generate_file_name(inputFile, "dom");
            
            // ... Conversion de strValue en int (utiliser atoi ou sscanf) ...
            // ... Validation de domColor (doit être 'R', 'G', ou 'B') ...
            
            // ... Appeler read_ppm, adjust_dominant_color, write_ppm ...
        }

        // --- COMMANDE TRÈS COMPLEXE 'CUT' (avec 6 arguments) ---
        else if (strcmp(command, "cut") == 0) {
            char *inputFile = strtok(NULL, " ");
            char *l1 = strtok(NULL, " ");
            char *l2 = strtok(NULL, " ");
            char *c1 = strtok(NULL, " ");
            char *c2 = strtok(NULL, " ");
            char *outputFile= strtok(NULL, " ");
            // Récupérer les 6 jetons nécessaires l1 l2 c1 c2 fichier_entree fichier_resultat
            char* strL1 = strtok(NULL, " ");
            // ... récupérer strL2, strC1, strC2, inputFile, outputFile ...

            if (inputFile == NULL || l1 == NULL || l2 == NULL || c1 == NULL || c2 == NULL) {
                printf("Erreur: Usage cut <l1> <l2> <c1> <c2> <input_file>.\n");
                continue;
            }

            if (outputFile == NULL)
                outputFile = generate_file_name(inputFile, "cut");

            

            // ... Conversion des coordonnées strL1, strL2, strC1, strC2 en int ...
            // ... Appeler read_ppm, crop_image, write_ppm ...
        }
        
        // --- COMMANDE INCONNUE ---
        else {
            printf("Erreur: Commande '%s' introuvable.\n", command);
        }
    }
    return 0;
}