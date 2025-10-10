
# **PPM Image Processor in C (INF231 - TP/TD 3)**

## **Description du Projet**

Ce projet, réalisé dans le cadre du cours **INF231 (Technique de Conception d'Algorithmes et Structures de Données)** à l'Université de Yaoundé I, consiste à développer un programme en **langage C** permettant de manipuler et de traiter des images au format **PPM (Portable PixMap)**.

L'application `ppmviewer` implémente plusieurs opérations de base sur les images, accessibles via une interface **CLI (Command Line Interface)** interactive.

---

## **Format PPM Utilisé**

Le projet se concentre sur la version **P3** du format PPM, où les valeurs de coordonnées RGB (Rouge, Vert, Bleu) sont stockées en **texte brut**.
Chaque coordonnée est un entier compris entre 0 et 255.

Exemple de fichier `.ppm` :

```
P3
# Exemple simple
4 4
255
255 0 0   0 255 0   0 0 255   255 255 0
...
```

---

## **Fonctionnalités Implémentées**

L'application prend en charge les opérations suivantes, comme spécifié dans la fiche de TP :

| Catégorie                 | Commande                               | Description                                                                                              |
| :------------------------ | :------------------------------------- | :------------------------------------------------------------------------------------------------------- |
| **Modification Couleurs** | `dom c val fichier.ppm`                | Fonce ou éclaircit les pixels dont la couleur dominante est `c` (R, G, ou B) avec une valeur `val`.      |
| **Effet**                 | `gris fichier.ppm`                     | Convertit l'image en niveaux de gris en utilisant la valeur moyenne des composantes RGB de chaque pixel. |
| **Effet**                 | `neg fichier.ppm fichier_resultat.ppm` | Crée le négatif de l'image en utilisant le complémentaire de chaque couleur.                             |
| **Filtre**                | `fil fichier.ppm fichier_resultat.ppm` | Applique un **filtre médian** sur chaque canal de couleur à partir des 8 pixels voisins.                 |
| **Extraction**            | `cut f.ppm l1 l2 c1 c2 f_res.ppm`      | Découpe une partie de l'image entre les lignes `l1` et `l2` et les colonnes `c1` et `c2`.                |
| **Information**           | `size fichier.ppm`                     | Affiche la taille (largeur x hauteur) de l'image en pixels.                                              |
| **Quitter**               | `quit`                                 | Quitte l'application `ppmviewer`.                                                                        |

---

## **Structure du Projet**

```
PPM-Image-Processor-in-C/
├── assets/                 # Images PPM de test
├── docs/                   # Documentation (Guide, Rapports...)
├── lib/                    # Fichiers d'en-tête (.h)
│   ├── operations.h        # Fonctions de traitement d'image
│   ├── ppm_io.h            # Fonctions d'entrée/sortie PPM
│   └── utils.h             # Fonctions utilitaires
├── src/                    # Code source (.c)
│   ├── operations.c
│   ├── ppm_io.c
│   └── utils.c
├── main.c                  # Interface CLI (ppmviewer>)
└── README.md               # Documentation principale
```

---

## **Détail des Fonctions Implémentées**

### 🔹 `convert_to_grayscale(Image *img)`

**Auteur :** Njapndounke Nchankou Fadimatou
**But :** convertir une image couleur en niveaux de gris.

**Pseudo-code :**

```c
Pour chaque pixel p :
    gris = (p.r + p.g + p.b) / 3;
    p.r = p.g = p.b = gris;
```

---

### 🔹 `create_negatif(Image *img)`

**Auteur :** Philbert Ngamize
**But :** créer le négatif d’une image.

**Pseudo-code :**

```c
Pour chaque pixel p :
    p.r = 255 - p.r;
    p.g = 255 - p.g;
    p.b = 255 - p.b;
```

---

### 🔹 `adjust_dominant_color(Image *img, char c, int val)`

**Auteur :** Philbert Ngamize
**But :** foncer ou éclaircir les pixels ayant une dominante `c`.

**Pseudo-code :**

```c
Pour chaque pixel p :
    dominant = couleur_dominante(p);
    Si dominant == c :
        p.r = clamp(p.r - val);
        p.g = clamp(p.g - val);
        p.b = clamp(p.b - val);
```

---

### 🔹 `crop_image(Image *img, int l1, int l2, int c1, int c2)`

**Auteur :** MFOPIT Mar’yam
**But :** extraire une sous-image.

**Pseudo-code :**

```c
Créer une nouvelle image (hauteur = l2 - l1 + 1, largeur = c2 - c1 + 1)
Pour i de l1 à l2 :
    Pour j de c1 à c2 :
        nouvelle_image[i-l1][j-c1] = img[i][j];
```

---

### 🔹 `apply_median_filter(Image *img)`

**Auteur :** Philbert Ngamize
**But :** réduire le bruit avec un filtre médian.

**Pseudo-code :**

```c
Pour chaque pixel (hors bordure) :
    voisins = 8 pixels autour
    Pour chaque canal (R, G, B) :
        trier(voisins.canal)
        p.canal = voisins.canal[4];
```

---

### 🔹 `display_size(Image *img)`

**Auteur :** Philbert Ngamize
**But :** afficher les dimensions d’une image.
**Sortie :** texte “largeur x hauteur”.

---

## **Fonctions Utilitaires (`utils.c`)**

### 🔸 `find_max_rgb(unsigned r, unsigned g, unsigned b)`

Retourne la couleur dominante (`'R'`, `'G'` ou `'B'`) selon la composante la plus forte.

```c
if (r >= g && r >= b) return 'R';
else if (g >= r && g >= b) return 'G';
else return 'B';
```

---

### 🔸 `clamp(int value)`

Limite une valeur entre `0` et `255`.

```c
if (value < 0) return 0;
else if (value > 255) return 255;
else return (unsigned char)value;
```

---

### 🔸 `fileExist(const char *path)`

Vérifie si un fichier existe.

```c
FILE *fp = fopen(path, "r");
if (fp != NULL) { fclose(fp); return true; }
return false;
```

---

### 🔸 `generate_file_name(char *inputFile, char *operation)`

Génère un nom de fichier basé sur le nom d’entrée et l’opération.

Exemple :
`generate_file_name("image1.ppm", "gris") → "image1-generate-gris.ppm"`

```c
static char new_filename[514];
char *dot = strrchr(inputFile, '.');
size_t len = dot - inputFile;
strncpy(new_filename, inputFile, len);
new_filename[len] = '\0';
strcat(new_filename, "-generate-");
strcat(new_filename, operation);
strcat(new_filename, dot);
return new_filename;
```

---

## **Structures de Données**

### 📦 `Pixel`

```c
typedef struct {
    unsigned int r, g, b;
} Pixel;
```

### 🖼️ `Image`

```c
typedef struct {
    unsigned int width;
    unsigned int height;
    Pixel **pixels;
} Image;
```

---

## **Répartition des Tâches**

| Membre                            | Rôle                        | Fonction(s)                                                                     |
| :-------------------------------- | :-------------------------- | :------------------------------------------------------------------------------ |
| **Philbert NGAMIZE**              | Chef de Projet / Architecte | `ppm_io.c`, `main.c`, `create_negatif`,  `apply_median_filter`, `display_size` |
| **MFOPIT Mar’yam**                | Développeur C               | `crop_image`                                                                    |
| **Njapndounke Nchankou Fadimatou** | Développeur C               | `convert_to_grayscale`                                                          |
| **Raissa MESSINA**                    | Développeur C               |    `adjust_dominant_color`                                                       |

---

## **Compilation et Exécution**

### 🔧 Compilation (Linux/macOS)

```bash
gcc -o ppmviewer src/*.c  main.c -Wall
```

### ▶️ Exécution

```bash
./ppmviewer
```

### Exemple d’utilisation

```bash
ppmviewer > size assets/image1.ppm
100 x 205

ppmviewer > gris assets/image1.ppm
🎨 Conversion en niveaux de gris terminée : image1-generate-gris.ppm

ppmviewer > dom R 4 mesimages/image2.ppm
🎉 Voilà votre fichier : image2-generate-dom.ppm créé

ppmviewer > quit
```

---