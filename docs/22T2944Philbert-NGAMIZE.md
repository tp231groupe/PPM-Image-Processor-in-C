## **22T2944 - PHILBERT NGAMIZE**

> Rapport d'Avancement Individuel (Cours/Module - TP/TD 3) - Projet de Manipulation d’Images PPM (CLI)

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

### **Séance 3 : Lundi 06/10/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 1h30 |
| **Objectif Principal** | Correction des tâches attribuées et approfondissement des commandes principales (`cut`, `size`, `neg`, `gris`). |
| **Avancement** | **[Progression significative]** Les fonctions de lecture et d’écriture PPM ont été corrigées et validées. |
| **Tâches Accomplies** | * Relecture et correction des fonctions de lecture/écriture PPM.<br>* Explication du fonctionnement de chaque commande à implémenter.<br>* Discussion sur la gestion de la mémoire et la structure des pixels. |
| **Difficultés** | Quelques erreurs de gestion de fichiers corrigées (mauvaises ouvertures ou formats incorrects). |
| **À Faire (Prochaine Séance)** | Démarrer la mise en place du dépôt GitHub et organiser la collaboration en branches. |

---

### **Séance 4 : Mardi 07/10/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 2h |
| **Objectif Principal** | Introduction à **Git et GitHub** et mise en place de la structure du projet. |
| **Avancement** | **[Structure collaborative opérationnelle]** Mise en place du dépôt distant et définition claire des branches de travail. |
| **Tâches Accomplies** | * Tuto sur **Git/GitHub** (commit, push, pull, branches, merge).<br>* Création du **dépôt principal GitHub**.<br>* Définition de l’**architecture du projet** : séparation en modules (`ppm_io`, `operations`, `utils`, etc.).<br>* Répartition des fonctionnalités par développeur. |
| **Difficultés** | Aucune majeure, adaptation rapide à l’outil Git. |
| **À Faire (Prochaine Séance)** | Intégration et test des différentes fonctionnalités sur leurs branches respectives. |

---

### **Séance 5 : Mercredi 08/10/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | -- |
| **Objectif Principal** | Intégration et test des fonctionnalités implémentées sur les branches. |
| **Avancement** | **[Projet finalisé]** Intégration réussie des principales commandes (`cut`, `size`, `neg`, `gris`, `dom`, `fil`). Le programme principal (`main.c`) est complet, stable et fonctionnel. |
| **Tâches Accomplies** | * Réception et test des fonctionnalités développées par chaque membre.<br>* Fusion et débogage des branches.<br>* Validation des opérations principales sur plusieurs fichiers PPM.<br>* Amélioration de l’affichage et des messages CLI. |
| **Difficultés** | Quelques conflits Git lors des merges, rapidement résolus. |
| **À Faire (Prochaine Étape)** | Rédiger la documentation technique et finaliser la version à livrer. |

### **Synthèse de la Période**

* **Travail Réalisé :** réalisation d'un **CLI**, fonction d'affichage de la taille d'une image ppm `display_size`, fonction negatif `create_negatif`(donner le negatif d'une image ppm), la fonction ``apply_median_filter`, integration des différents features depuis des branches **Git/Github**
* **Temps Total :** ≈ 42 heures

---