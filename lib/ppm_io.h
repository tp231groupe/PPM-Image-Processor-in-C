#ifndef PPM_IO_H
#define PPM_IO_H
#include "utils.h"

Image* read_ppm(const char *filename); //Lire un fichier PPM et le charge une structure Image.
void generate_ppm(const char *filename, const Image *img, char *text); //Sauvegardes an Image structure back to a PPM file.
void free_image(Image *img); //Liberer les memoires alloues pour les pixels de la structure Image et la structure elle-meme.
#endif