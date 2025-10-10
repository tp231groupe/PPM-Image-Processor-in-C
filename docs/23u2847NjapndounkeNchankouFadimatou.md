## **23U2847 – Njapndounke Nchankou Fadimatou**

> Rapport d'Avancement Individuel (Cours/Module - TP/TD 3) – Projet de Manipulation d’Images PPM (CLI)

---

### **Séance 1 : Vendredi 03/10/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 30 min |
| **Objectif Principal** | Présentation du projet et introduction au format de fichier **PPM** (Portable Pixmap). Expliquer le standard, les objectifs du TP et les attentes globales. |
| **Avancement** | **[Initialisation réussie]** La séance a permis de comprendre la structure du format PPM et de poser les bases du projet. |
| **Tâches Accomplies** | * Présentation du **format PPM** et de ses variantes (P3, P6).<br>* Discussion sur la structure d’un projet modulaire en C (fichiers `.h` et `.c`).<br>* Introduction aux fonctions à implémenter pour la **lecture et l’écriture** d’images. |
| **Difficultés** | Aucune difficulté majeure, séance surtout conceptuelle et introductive. |
| **À Faire (Prochaine Séance)** | Approfondir la lecture/écriture de fichiers PPM et définir la structure des données `Image` et `Pixel`. |

---

### **Séance 2 : Dimanche 05/10/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 3 heures |
| **Objectif Principal** | Détailler le fonctionnement global du projet, notamment l’aspect **CLI (Command Line Interface)** et la gestion des fichiers PPM. |
| **Avancement** | **[Planification complète]** Répartition des tâches et attribution des premières implémentations : CLI et lecture de fichiers PPM. |
| **Tâches Accomplies** | * Explication détaillée du **fonctionnement du projet CLI** (commandes prévues : `cut`, `size`, `neg`, `gris`, etc.).<br>* Étude du **format de fichier PPM** pour comprendre la lecture et l’écriture.<br>* Attribution des tâches à chaque membre : lecture/écriture de fichiers, structure principale du CLI, implémentation de commandes de base. |
| **Difficultés** | Quelques incompréhensions sur la structure du fichier PPM, clarifiées avec des exemples concrets. |
| **À Faire (Prochaine Séance)** | Finaliser la lecture/écriture PPM et préparer la correction collective du code. |

---

### **Séance 5 : Mercredi 08/10/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | -- |
| **Objectif Principal** | Intégration et test des fonctionnalités implémentées sur les branches. |
| **Avancement** | **[Projet finalisé]** Intégration réussie des principales commandes (`cut`, `size`, `neg`, `gris`, `dom`, `fil`). Le programme principal (`main.c`) est complet, stable et fonctionnel. |                                                
| **Tâches Accomplies** | * Étude du fonctionnement global du projet CLI (cut, size, neg, gris, dom, fil).
* Découverte des fichiers PPM (en-têtes, données brutes, composantes RGB).
* Affectation de la commande gris (conversion en niveaux de gris). |
| **Difficultés** | Quelques difficultés à comprendre la structure du format binaire PPM (P6), résolues par des exemples pratiques.|
| **À Faire (Prochaine Étape)** | Implémenter la fonction de conversion en niveaux de gris (convert_to_grayscale). |                                                                                                                   
### **Synthèse de la Période**

* **Travail Réalisé :** réalisation de la fonction `convert_to_grayscale`, permettant de générer une image en niveaux de gris à partir d’un fichier PPM, participation active à l’intégration sur GitHub et tests des fonctionnalités CLI.
* **Outils et Compétences Acquises :** gestion de versions avec **Git/GitHub**, manipulation du format **PPM**, compréhension du traitement d’images par canal RGB, et travail collaboratif en équipe.
* **Temps Total Estimé :** **≈ 32 heures**
