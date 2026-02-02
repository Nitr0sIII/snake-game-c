# 🐍 Snake Game en C

> 📌 **This documentation is available in two versions / Cette documentation est disponible en deux versions**
> - **English**: See section [## English Version](#english-version) below
> - **Français**: Voir la section [## Version Française](#version-française) ci-dessous

---

# English Version

## 📝 Description

- 🎨 **Terminal-based Snake game** with colored ASCII rendering and real-time display.
- ⚡ **Non-blocking input** via `termios` raw mode for smooth, responsive controls.
- 🏆 **Score system** with current score, persistent best score, and automatic save at game end.
- 🎮 **Customizable gameplay** with adjustable grid size, refresh rate, and key bindings.

---

## 🔧 Requirements

- **GCC** or Clang with C11 support
- **POSIX environment** (Linux, macOS) for `termios`, `unistd.h`, `fcntl.h`
- **Make** for build automation

---

## 💾 Build & Run

```bash
make          # Compile the executable ./snake
./snake       # Run the game
make clean    # Remove object files and binary
```

---

## 🎮 Usage

### Game Controls
- **Define keys on startup**: Set keys for `up`, `down`, `left`, `right` (use letters A–Z or a–z)
- **Quit**: Press `p` (`EXIT_KEY`)
- **Direction persistence**: If no key is pressed, the snake continues in the last valid direction

### Game Rules
- **Grid**: Square grid of size 15 (customizable in `src/snake.c`)
- **Apples**: Appear every 8 game ticks; eating an apple gives +5 points and grows the snake body (max `BODY_MAX` = 100)
- **Collision**: Hitting the body or borders results in game over

### Score & Save
- **Binary save**: `save.bin` is written at game end, storing the best score
- **Automatic reload**: Best score is restored on startup if the save file exists

---

## 📂 Project Structure

```
snake-game-c/
├── Makefile                    # Build configuration
├── README.md                   # Documentation (this file)
├── include/
│   ├── colorConsole.h          # ANSI color macros
│   ├── gridManagement.h        # Grid management declarations
│   ├── keyManagement.h         # Key input declarations
│   ├── loseMenu.h              # End-of-game display declarations
│   ├── movementManagement.h    # Movement logic declarations
│   ├── saveLoadSystem.h        # Save/load system declarations
│   └── snakeManagement.h       # Snake data model declarations
├── src/
│   ├── snake.c                 # Main game loop, initialization
│   ├── keyManagement.c         # Terminal raw mode, non-blocking input
│   ├── gridManagement.c        # Grid creation, rendering, apple spawning
│   ├── movementManagement.c    # Movement logic, collision detection, scoring
│   ├── snakeManagement.c       # Snake data model, stats display
│   ├── saveLoadSystem.c        # Binary save/load functionality
│   └── loseMenu.c              # End-of-game screen
└── save.bin                    # Best score save file (auto-generated)
```

- **`Makefile`**: Build rules with separate compilation and linking
- **`src/`**: Core implementation files
  - `snake.c`: Main game loop, grid/snake initialization, rendering, lose screen
  - `keyManagement.c`: Terminal raw mode setup, non-blocking input handling, key prompts
  - `gridManagement.c`: Grid creation/cleanup, ASCII rendering, apple spawning
  - `movementManagement.c`: Snake movement, collision detection, growth, scoring
  - `snakeManagement.c`: Snake data structure, stats display, best score management
  - `saveLoadSystem.c`: Binary persistence of game state
  - `loseMenu.c`: End-of-game display and menu
- **`include/`**: Header files and ANSI color utilities

---

## ⚙️ Tunable Parameters

- **Grid size & refresh rate**: `sizeGrid` and `refreshTime` in [src/snake.c](src/snake.c)
- **Exit key**: `EXIT_KEY` in [include/keyManagement.h](include/keyManagement.h)
- **Max body capacity**: `BODY_MAX` in [include/snakeManagement.h](include/snakeManagement.h)
- **Apple spawn rate**: Change the divisor in game loop for different spawn frequencies
- **Score increment**: Modify the point value per apple in [src/movementManagement.c](src/movementManagement.c)

---

## 💡 Usage Examples

```bash
$ make
gcc -c src/snake.c -o obj/snake.o ...
gcc -c src/keyManagement.c -o obj/keyManagement.o ...
# ... (other compilations)
gcc obj/*.o -o snake

$ ./snake
=== KEY SETUP ===
Enter UP key (a-z, A-Z): w
Enter DOWN key (a-z, A-Z): s
Enter LEFT key (a-z, A-Z): a
Enter RIGHT key (a-z, A-Z): d

# Game starts with the configured keys
# Press 'p' to quit
# Game saves best score on exit
```

---

## 📄 License

This project is provided for educational purposes.

---

**Author**: Nitros  
**Date**: February 2026  
**Language**: C

---

# Version Française

## 📝 Description

- 🎨 **Jeu Snake dans le terminal** avec rendu ASCII coloré et affichage temps réel.
- ⚡ **Entrées non-bloquantes** via `termios` (mode raw) pour des contrôles fluides et réactifs.
- 🏆 **Système de score** avec score courant, meilleur score persistant et sauvegarde automatique.
- 🎮 **Gameplay personnalisable** avec grille ajustable, fréquence de rafraîchissement et touches configurables.

---

## 🔧 Prérequis

- **GCC** ou Clang compatible C11
- **Environnement POSIX** (Linux, macOS) pour `termios`, `unistd.h`, `fcntl.h`
- **Make** pour l'automatisation du build

---

## 💾 Compilation et Exécution

```bash
make          # Compile l'exécutable ./snake
./snake       # Lance le jeu
make clean    # Supprime les fichiers objets et le binaire
```

---

## 🎮 Utilisation

### Contrôles du jeu
- **Définir les touches au démarrage** : Configurez les touches pour `haut`, `bas`, `gauche`, `droite` (utilisez les lettres A–Z ou a–z)
- **Quitter** : Appuyez sur `p` (`EXIT_KEY`)
- **Persistance de direction** : Sans entrée, le serpent continue dans la dernière direction valide

### Règles du jeu
- **Grille** : Grille carrée de taille 15 (personnalisable dans `src/snake.c`)
- **Pommes** : Apparaissent toutes les 8 itérations; manger une pomme ajoute 5 points et allonge le corps (max `BODY_MAX` = 100)
- **Collision** : Heurter le corps ou les bordures = fin de partie

### Score et Sauvegarde
- **Sauvegarde binaire** : `save.bin` est écrit à la fin de la partie, stockant le meilleur score
- **Rechargement automatique** : Le meilleur score est restauré au démarrage si le fichier existe

---

## 📂 Structure du Projet

```
snake-game-c/
├── Makefile                    # Configuration de build
├── README.md                   # Documentation (ce fichier)
├── include/
│   ├── colorConsole.h          # Macros de couleurs ANSI
│   ├── gridManagement.h        # Déclarations gestion grille
│   ├── keyManagement.h         # Déclarations gestion touches
│   ├── loseMenu.h              # Déclarations écran de fin
│   ├── movementManagement.h    # Déclarations logique mouvement
│   ├── saveLoadSystem.h        # Déclarations système sauvegarde
│   └── snakeManagement.h       # Déclarations modèle serpent
├── src/
│   ├── snake.c                 # Boucle principale du jeu
│   ├── keyManagement.c         # Mode raw, entrées non-bloquantes
│   ├── gridManagement.c        # Création grille, rendu ASCII
│   ├── movementManagement.c    # Logique mouvement, collision
│   ├── snakeManagement.c       # Modèle serpent, affichage stats
│   ├── saveLoadSystem.c        # Persistance binaire
│   └── loseMenu.c              # Écran de fin de partie
└── save.bin                    # Fichier sauvegarde (auto-généré)
```

- **`Makefile`** : Règles de build avec compilation séparée et édition de liens
- **`src/`** : Fichiers d'implémentation principaux
  - `snake.c` : Boucle principale du jeu, initialisation grille/serpent, rendu, écran de défaite
  - `keyManagement.c` : Configuration du mode raw, gestion des entrées non-bloquantes, prompts
  - `gridManagement.c` : Création/nettoyage de grille, rendu ASCII, spawn des pommes
  - `movementManagement.c` : Mouvement du serpent, détection de collision, croissance, scoring
  - `snakeManagement.c` : Structure de données du serpent, affichage des stats, gestion du meilleur score
  - `saveLoadSystem.c` : Persistance binaire de l'état du jeu
  - `loseMenu.c` : Écran de fin de partie et menu
- **`include/`** : Fichiers d'en-tête et utilitaires de couleurs ANSI

---

## ⚙️ Paramètres Configurables

- **Taille de grille et fréquence de rafraîchissement** : `sizeGrid` et `refreshTime` dans [src/snake.c](src/snake.c)
- **Touche de quitter** : `EXIT_KEY` dans [include/keyManagement.h](include/keyManagement.h)
- **Capacité max du corps** : `BODY_MAX` dans [include/snakeManagement.h](include/snakeManagement.h)
- **Fréquence d'apparition des pommes** : Modifiez le diviseur dans la boucle principale
- **Incrément de score** : Adaptez la valeur des points par pomme dans [src/movementManagement.c](src/movementManagement.c)

---

## 💡 Exemples d'Utilisation

```bash
$ make
gcc -c src/snake.c -o obj/snake.o ...
gcc -c src/keyManagement.c -o obj/keyManagement.o ...
# ... (autres compilations)
gcc obj/*.o -o snake

$ ./snake
=== CONFIGURATION DES TOUCHES ===
Entrez la touche HAUT (a-z, A-Z): z
Entrez la touche BAS (a-z, A-Z): s
Entrez la touche GAUCHE (a-z, A-Z): q
Entrez la touche DROITE (a-z, A-Z): d

# Le jeu démarre avec les touches configurées
# Appuyez sur 'p' pour quitter
# Le jeu sauvegarde le meilleur score à la sortie
```

---

## 📄 Licence

Ce projet est mis à disposition à titre éducatif.

---

**Auteur** : Nitros  
**Date** : Février 2026  
**Langage** : C

