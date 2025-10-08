# **PPM Image Processor in C (INF231 - TP/TD 1)**

## **Description du Projet**

Ce projet, réalisé dans le cadre du cours INF231 (Technique de Conception d'Algorithmes et Structures de Données) à l'Université de Yaoundé 1, consiste à développer un programme en **langage C** pour manipuler et traiter des images au format **PPM (Portable PixMap)**[cite: 4, 5].

L'application `ppmviewer` implémente plusieurs opérations de base sur les images, accessibles via une interface de ligne de commande interactive[cite: 48, 50].

### **Format PPM Utilisé**

Le projet se concentre sur la version **P3** du format PPM, où les valeurs de coordonnées RGB (Rouge, Vert, Bleu) sont stockées en texte brut[cite: 11, 17]. [cite\_start]Chaque coordonnée est un entier compris entre 0 et 255[cite: 6].

-----

## **Fonctionnalités Implémentées**

L'application prend en charge les opérations suivantes, comme spécifié dans la fiche de TP :

| Catégorie | Commande | Description |
| :--- | :--- | :--- |
| **Modification Couleurs** | `dom c val fichier.ppm` | [cite\_start]Fonce ou éclaircit les pixels dont la couleur dominante est `c` (R, G, ou B) avec une valeur `val`[cite: 51, 52, 53, 54]. |
| **Effet** | `gris fichier.ppm` | [cite\_start]Convertit l'image en niveaux de gris en utilisant la valeur moyenne des composantes RGB de chaque pixel[cite: 42, 43, 56]. |
| **Effet** | `neg fichier.ppm fichier_resultat.ppm` | [cite\_start]Crée le négatif de l'image en utilisant le complémentaire de chaque couleur[cite: 44, 62]. |
| **Filtre** | `fil fichier.ppm fichier_resultat.ppm` | [cite\_start]Applique le filtre médian sur chaque couleur d'un pixel en utilisant les 8 pixels voisins[cite: 47, 63]. |
| **Extraction** | `cut f.ppm l1 l2 c1 c2 f_res.ppm` | [cite\_start]Découpe une partie de l'image entre les lignes $l_1$ et $l_2$ et les colonnes $c_1$ et $c_2$ et l'enregistre[cite: 46, 59]. |
| **Information** | `size fichier.ppm` | [cite\_start]Affiche la taille (largeur x hauteur) de l'image en pixels[cite: 45, 57]. |
| **Quitter** | `quit` | [cite\_start]Quitte l'application `ppmviewer`[cite: 64]. |

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

  * **Implémentation :** Les tâches ont été réparties dans le fichier `src/operations.c`. Chaque fonction porte un commentaire indiquant le responsable : `// <-- Responsable: [Initiales] -->`.
  * [cite\_start]**Conventions :** Le document **`docs/GUIDE_DE_DEVELOPPEMENT.md`** détaille la syntaxe de création des branches, les conventions de commit, et les règles de travail strictes[cite: 70].

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

[cite\_start]L'invite de commande **`ppmviewer >`** s'affichera[cite: 49].

### **Exemples d'Utilisation**

```bash
ppmviewer > size assets/image1.ppm
[cite_start]100x205 [cite: 76]

[cite_start]ppmviewer > cut assets/image1.ppm 1 50 1 100 mesimages/image2.ppm [cite: 77]
[cite_start]opération effectuée [cite: 78]

ppmviewer > dom R 4 mesimages/image2.ppm
[cite_start]opération effectuée mesimages/image2_dom.ppm créé [cite: 82]

[cite_start]ppmviewer > quit [cite: 89]
```

-----