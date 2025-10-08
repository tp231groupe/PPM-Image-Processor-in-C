# **PPM Image Processor in C (INF231 - TP/TD 1)**

## **Description du Projet**

Ce projet, réalisé dans le cadre du cours INF231 (Technique de Conception d'Algorithmes et Structures de Données) à l'Université de Yaoundé 1, consiste à développer un programme en **langage C** pour manipuler et traiter des images au format **PPM (Portable PixMap)**.

L'application `ppmviewer` implémente plusieurs opérations de base sur les images, accessibles via une interface de ligne de commande interactive.

### **Format PPM Utilisé**

Le projet se concentre sur la version **P3** du format PPM, où les valeurs de coordonnées RGB (Rouge, Vert, Bleu) sont stockées en texte brut. Chaque coordonnée est un entier compris entre 0 et 255.

-----

## **Fonctionnalités Implémentées**

L'application prend en charge les opérations suivantes, comme spécifié dans la fiche de TP :

| Catégorie | Commande | Description |
| :--- | :--- | :--- |
| **Modification Couleurs** | `dom c val fichier.ppm` | Fonce ou éclaircit les pixels dont la couleur dominante est `c` (R, G, ou B) avec une valeur `val`. |
| **Effet** | `gris fichier.ppm` | Convertit l'image en niveaux de gris en utilisant la valeur moyenne des composantes RGB de chaque pixel. |
| **Effet** | `neg fichier.ppm fichier_resultat.ppm` | Crée le négatif de l'image en utilisant le complémentaire de chaque couleur. |
| **Filtre** | `fil fichier.ppm fichier_resultat.ppm` | Applique le filtre médian sur chaque couleur d'un pixel en utilisant les 8 pixels voisins. |
| **Extraction** | `cut f.ppm l1 l2 c1 c2 f_res.ppm` | Découpe une partie de l'image entre les lignes $l_1$ et $l_2$ et les colonnes $c_1$ et $c_2$ et l'enregistre. |
| **Information** | `size fichier.ppm` | Affiche la taille (largeur x hauteur) de l'image en pixels. |
| **Quitter** | `quit` | Quitte l'application `ppmviewer`. |

-----

## **Structure du Projet et Organisation du Travail**

Le projet utilise une architecture standard en C pour séparer l'interface (en-têtes) de l'implémentation (sources).

```
PPM-Image-Processor-in-C/
├── assets/                 # Images PPM de test
├── docs/                   # Documentation du projet (Guide, Rapports...)
├── lib/                    # Fichiers d'en-tête (.h)
│   ├── operations.h        # Déclarations des fonctions de traitement
│   ├── ppm_io.h            # Déclarations des fonctions I/O (lecture/écriture)
│   └── utils.h             # Déclarations des fonctions utilitaires (clamp, max, etc.)
├── src/                    # Fichiers sources (.c)
│   ├── operations.c        # Implémentation du traitement des images
│   ├── ppm_io.c            # Implémentation I/O
│   └── utils.c             # Implémentation des utilitaires
├── main.c                  # Point d'entrée de l'application (interface ppmviewer>)
└── README.md               # Ce fichier
```

### **Répartition des Tâches et Contribution**

Pour assurer l'efficacité et éviter les conflits de fusion, le travail a été strictement assigné et suivi :

  * **Implémentation :** Les tâches ont été réparties dans le fichier `src/operations.c`. Chaque fonction porte un commentaire indiquant le responsable : `// <-- Responsable: [nom]`.
  * **Conventions :** Le document **`docs/GUIDE_DE_DEVELOPPEMENT.md`** détaille la syntaxe de création des branches, les conventions de commit, et les règles de travail strictes.

| Membre de l'Équipe | Rôle Principal | Fonction(s) Attribuée(s) |
| :--- | :--- | :--- |
| **[LEADS]** | Chef de Projet / Architecture | `ppm_io.c` (Lecture/Écriture), `main.c` (Parsing), **[...]** |
| **[Membre 2]** | Développeur C | **[...]** |
| **[Membre 3]** | Développeur C | **[...]** |
| **[Membre 4]** | Développeur C | **[...]** |

-----

## **Compilation et Exécution**

### **Compilation (Linux/macOS)**

Si vous utilisez un compilateur GCC standard :

```bash
# Compiler tous les fichiers sources
gcc -o ppmviewer src/*.c lib/*.c main.c -Wall

# OU, si utilisation d'un Makefile:
make
```

### **Exécution**

Le programme s'exécute en mode interactif :

```bash
./ppmviewer
```

L'invite de commande **`ppmviewer >`** s'affichera.

### **Exemples d'Utilisation**

```bash
ppmviewer > size assets/image1.ppm
100 x 205

ppmviewer > cut assets/image1.ppm 1 50 1 100 mesimages/image2.ppm 
opération effectuée

ppmviewer > dom R 4 mesimages/image2.ppm
opération effectuée mesimages/image2_dom.ppm créé

ppmviewer > quit
```

-----