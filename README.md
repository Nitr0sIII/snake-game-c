# Snake Game (C - Terminal)

## Overview (EN)

- Terminal-playable Snake with colored ASCII rendering.
- Non-blocking input via `termios` raw mode for smooth controls.
- Current score, persistent best score, automatic save at game end.

## Requirements (EN)

- GCC or Clang with C11 support.
- POSIX environment (Linux, macOS) for `termios`, `unistd.h`, `fcntl.h`.

## Build & Run (EN)

```bash
make          # build ./snake
./snake       # run the game
make clean    # remove objects and binary
```

## Controls (EN)

- On start, you define keys for `up`, `down`, `left`, `right` (letters A–Z or a–z).
- Quit: `p` (`EXIT_KEY`).
- If no key is pressed, the snake keeps the last valid direction.

## Game Rules (EN)

- Square grid of size 15 (modifiable in `src/snake.c`).
- An apple spawns every 8 loop ticks; eating gives +5 points and grows the body up to `BODY_MAX` (100).
- Collision with body or borders -> game over (`HIT`).

## Persistence (EN)

- Binary save `save.bin` (`SAVE_PATH`) written at game end, storing notably the best score.
- On startup, best score reloads if the file exists.

## Project Structure (EN)

- `Makefile`: simple build rules (separate compilation, links `snake`).
- `src/`:
  - `snake.c`: main loop, grid/snake init, refresh, lose screen.
  - `keyManagement.c`: terminal raw mode, non-blocking input, user key prompts.
  - `gridManagement.c`: grid create/free, ASCII render, apple spawn.
  - `movementManagement.c`: movement logic, collision, growth, scoring.
  - `snakeManagement.c`: snake data model, stats display, best score handling.
  - `saveLoadSystem.c`: binary save of relevant state.
  - `loseMenu.c`: end-of-game display.
- `include/`: headers and ANSI color helpers.

## Tunable Parameters (EN)

- Grid size and refresh time: `sizeGrid`, `refreshTime` in `src/snake.c`.
- Exit key: `EXIT_KEY` in `include/keyManagement.h`.
- Max body capacity: `BODY_MAX` in `include/snakeManagement.h`.

---

## Aperçu (FR)

- Jeu Snake jouable dans le terminal, rendu ASCII coloré.
- Entrées non bloquantes via `termios` (mode raw) pour des contrôles fluides.
- Score courant, meilleur score persistant, sauvegarde automatique en fin de partie.

## Prérequis (FR)

- GCC ou Clang compatible C11.
- Environnement POSIX (Linux, macOS) pour `termios`, `unistd.h`, `fcntl.h`.

## Compilation et exécution (FR)

```bash
make          # compile l'exécutable ./snake
./snake       # lance le jeu
make clean    # supprime les objets et le binaire
```

## Contrôles (FR)

- Au démarrage, vous définissez les touches `haut`, `bas`, `gauche`, `droite` (lettres A–Z ou a–z).
- Quitter : `p` (`EXIT_KEY`).
- Sans touche pressée, le serpent continue dans la dernière direction valide.

## Règles du jeu (FR)

- Grille carrée de taille 15 (modifiable dans `src/snake.c`).
- Une pomme apparaît toutes les 8 itérations; la manger ajoute 5 points et allonge le corps jusqu'à `BODY_MAX` (100).
- Collision avec le corps ou les bordures -> fin de partie (`HIT`).

## Persistance (FR)

- Sauvegarde binaire `save.bin` (`SAVE_PATH`) écrite à la fin de la partie, incluant le meilleur score.
- Au démarrage, le meilleur score est rechargé si le fichier existe.

## Structure du projet (FR)

- `Makefile` : règles de build simples (compilation séparée, lien de l'exécutable `snake`).
- `src/` :
  - `snake.c` : boucle principale, init grille/serpent, rafraîchissement, écran de défaite.
  - `keyManagement.c` : mode raw du terminal, lecture non bloquante, saisie des touches.
  - `gridManagement.c` : création/libération de la grille, rendu ASCII, génération des pommes.
  - `movementManagement.c` : déplacement, collisions, croissance, score.
  - `snakeManagement.c` : modèle du serpent, affichage stats, meilleur score.
  - `saveLoadSystem.c` : sauvegarde binaire de l'état.
  - `loseMenu.c` : affichage de fin de partie.
- `include/` : en-têtes associés et utilitaires de couleurs ANSI.

## Paramètres utiles (FR)

- Taille de grille et temps de rafraîchissement : `sizeGrid`, `refreshTime` dans `src/snake.c`.
- Touche de sortie : `EXIT_KEY` dans `include/keyManagement.h`.
- Capacité maximale du corps : `BODY_MAX` dans `include/snakeManagement.h`.
