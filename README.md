# So_long - A 2D Pokémon-Themed Game 🎮

---<img width="1602" height="988" alt="Screenshot from 2025-12-20 14-03-40" src="https://github.com/user-attachments/assets/5d54a294-6e10-4a7b-b585-dda87d4a6f7a<img width="348" height="272" alt="Screenshot from 2025-12-20 14-29-39" src="https://github.com/user-attachments/assets/66cdb3d2-6d67-41b4-88fc-3bd0232486f9" />
" />


## 🌍 Language / Langue

- [English Version](#english-version)
- [Version Française](#version-française)

---

<a name="english-version"></a>
# 🇬🇧 ENGLISH VERSION

## 📋 Table of Contents
- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Game Controls](#game-controls)
- [Map Format](#map-format)
- [Project Structure](#project-structure)
- [Bonus Features](#bonus-features)
- [Error Handling](#error-handling)
- [Testing](#testing)
- [Algorithm Details](#algorithm-details)
- [Technical Details](#technical-details)
- [Learning Outcomes](#learning-outcomes)
- [Author](#author)

## 🎯 About

**So_long** is a small 2D game project developed as part of the 42 School curriculum. The player controls a Pokémon trainer who must collect all Pokéballs scattered across the map before escaping through the exit.

This project was built using the **MiniLibX** graphics library and implements core game mechanics including:
- Window management
- Event handling (keyboard inputs)
- Texture rendering
- Map validation
- Pathfinding algorithms

## ✨ Features

### Mandatory Part
- ✅ Player movement in 4 directions (W/A/S/D or Arrow keys)
- ✅ Collectible items (Pokéballs)
- ✅ Exit system (requires all collectibles before leaving)
- ✅ Movement counter displayed in terminal
- ✅ Comprehensive map validation:
  - Rectangular shape check
  - Wall border verification
  - Valid path validation (flood fill algorithm)
  - Component validation (1 player, 1 exit, ≥1 collectible)
- ✅ Smooth window management
- ✅ ESC key to quit
- ✅ Proper memory management (no leaks)

### Bonus Part
- 🎮 **Enemy Patrol System**: Charizard enemies that move in predefined patterns
- ⚔️ **Attack Mechanism**: Press SPACE to throw Pokéballs at enemies
- 💖 **Health System**: 3 HP displayed with visual indicators
- 🎨 **Sprite Animations**: Smooth character animations for all 4 directions
- 📊 **On-Screen HUD**: Movement counter and HP displayed on screen
- 🎬 **Game States**: Menu, gameplay, and game over screens
- 💀 **Game Over**: Triggered when HP reaches 0

## 🔧 Requirements

- **OS**: Linux (Ubuntu 24 recommended)
- **Compiler**: gcc
- **Libraries**: 
  - MiniLibX (included in `minilibx-linux/`)
  - X11 development libraries
  - libm (math library)

### Installing Dependencies

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Fedora
sudo dnf install gcc make libX11-devel libXext-devel
```

## 📥 Installation

1. **Clone the repository**
```bash
git clone https://github.com/yourusername/so_long.git
cd so_long
```

2. **Compile the project**

For the mandatory part:
```bash
make
```

For the bonus part:
```bash
make bonus
```

3. **Clean object files (optional)**
```bash
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Recompile everything
make help     # Display help in English and French
```

## 🎮 Usage

### Mandatory Version
```bash
./so_long map/validmap/[map_name].ber
```

### Bonus Version
```bash
./so_long_bonus map/map_bonus/[map_name].ber
```

### Example Maps

**Valid maps:**
```bash
./so_long map/validmap/minimal.ber
./so_long map/validmap/maze.ber
./so_long_bonus map/map_bonus/42.ber
```

**Testing invalid maps:**
```bash
./so_long map/invalidmap/no_exit.ber        # Error: Need only one exit
./so_long map/invalidmap/hole_top.ber       # Error: Map must be surrounded by walls
./so_long map/invalidmap/exit_unreachable.ber  # Error: Unable to reach exit
```

## 🎮 Game Controls

### Mandatory Version
| Key | Action |
|-----|--------|
| W / ↑ | Move Up |
| A / ← | Move Left |
| S / ↓ | Move Down |
| D / → | Move Right |
| ESC | Quit Game |

### Bonus Version
| Key | Action |
|-----|--------|
| W / ↑ | Move Up |
| A / ← | Move Left |
| S / ↓ | Move Down |
| D / → | Move Right |
| SPACE | Attack (throw Pokéball) |
| ESC | Quit Game |
| ENTER | Start Game (from menu) |

## 🗺️ Map Format

Maps use `.ber` extension and must follow these rules:

### Map Components
- `0` - Empty space (grass)
- `1` - Wall (tree)
- `C` - Collectible (Pokéball)
- `E` - Exit (Pokémon Center)
- `P` - Player starting position
- `M` - Enemy (Charizard) - **Bonus only**

### Map Requirements
1. **Rectangular shape** - All rows must have the same length
2. **Surrounded by walls** - Border must be all `1`s
3. **Valid path** - Player must be able to reach all collectibles and the exit
4. **Exactly 1 player** (`P`)
5. **Exactly 1 exit** (`E`)
6. **At least 1 collectible** (`C`)

### Example Map
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## 📁 Project Structure

```
so_long/
├── Makefile                    # Build configuration
├── README.md                   # This file
├── bonus/
│   ├── include_bonus/          # Bonus header files
│   └── src_bonus/              # Bonus source files
├── include/                    # Mandatory header files
├── libft/                      # Custom C library
├── map/                        # Game maps
│   ├── invalidmap/             # Invalid map examples
│   ├── map_bonus/              # Bonus maps (with enemies)
│   └── validmap/               # Valid map examples
├── minilibx-linux/             # MiniLibX graphics library
├── src/                        # Mandatory source files
└── texture/                    # Game textures
```

## 🎨 Bonus Features

### Enemy System
- **Patrol AI**: Enemies follow predefined patterns with configurable range
- **Collision Detection**: Touching an enemy deals 1 HP damage
- **Dynamic Movement**: Enemies move in 4 directions with sprite changes

### Combat System
- **Directional Attacks**: Attacks target the tile in front of the player
- **Enemy Elimination**: Successfully hit enemies are removed from the map
- **Visual Feedback**: Attack confirmations displayed in terminal

### Animation System
- **4-Direction Sprites**: Separate animations for up, down, left, right
- **Frame Cycling**: Smooth 3-frame animation loop
- **Movement Detection**: Animations play only when moving

### HUD Elements
- **HP Display**: Visual hearts showing current health (3/3, 2/3, 1/3)
- **On-Screen Counter**: Movement count displayed in window

### Game States
- **Menu Screen**: Welcome screen with controls explanation
- **Active Gameplay**: Full game with all mechanics
- **Game Over Screen**: Displayed when HP reaches 0

## 🐛 Error Handling

The program validates maps thoroughly and provides clear error messages:

```bash
Error: The map must be rectangular.
Error: The map must be surrounded by a border.
Error: Need only one exit.
Error: Need at least one food item.
Error: Unable to reach all food.
Error: Unable to reach exit.
Error: File map has to be .ber
Error: Unable to open map file
```

## 🧪 Testing

The project includes comprehensive test maps in `map/validmap/` and `map/invalidmap/`.

## 🔍 Algorithm Details

### Flood Fill Pathfinding
Recursive algorithm to validate map accessibility and ensure all collectibles and the exit are reachable.

## 🛠️ Technical Details

### Memory Management
- All heap-allocated memory is properly freed
- No memory leaks (tested with Valgrind)
- Proper cleanup on error and normal exit

### Graphics
- Uses MiniLibX for rendering
- XPM format for textures (64x64 pixels)
- Event-driven architecture

### Compilation Flags
```
-Wall -Wextra -Werror -g3
```

## 📚 Learning Outcomes

- Graphics programming fundamentals
- Event handling and game loops
- Algorithm implementation (pathfinding)
- Memory management in C
- Map parsing and validation
- Animation systems
- Game state management

---

<a name="version-française"></a>
# 🇫🇷 VERSION FRANÇAISE

## 📋 Table des Matières
- [À Propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Prérequis](#prérequis)
- [Installation](#installation-fr)
- [Utilisation](#utilisation)
- [Contrôles du Jeu](#contrôles-du-jeu)
- [Format de Carte](#format-de-carte)
- [Structure du Projet](#structure-du-projet-fr)
- [Fonctionnalités Bonus](#fonctionnalités-bonus)
- [Gestion des Erreurs](#gestion-des-erreurs)
- [Tests](#tests)
- [Détails des Algorithmes](#détails-des-algorithmes)
- [Détails Techniques](#détails-techniques-fr)
- [Acquis Pédagogiques](#acquis-pédagogiques)
- [Auteur](#auteur-fr)

## 🎯 À Propos

**So_long** est un petit projet de jeu 2D développé dans le cadre du cursus de l'École 42. Le joueur contrôle un dresseur Pokémon qui doit collecter toutes les Pokéballs dispersées sur la carte avant de s'échapper par la sortie.

Ce projet a été construit en utilisant la bibliothèque graphique **MiniLibX** et implémente les mécaniques de jeu essentielles :
- Gestion des fenêtres
- Gestion des événements (entrées clavier)
- Rendu des textures
- Validation de carte
- Algorithmes de recherche de chemin

## ✨ Fonctionnalités

### Partie Obligatoire
- ✅ Déplacement du joueur en 4 directions (W/A/S/D ou flèches)
- ✅ Objets à collecter (Pokéballs)
- ✅ Système de sortie (nécessite tous les objets avant de partir)
- ✅ Compteur de mouvements affiché dans le terminal
- ✅ Validation complète de la carte :
  - Vérification de la forme rectangulaire
  - Vérification des bordures de murs
  - Validation du chemin valide (algorithme de remplissage)
  - Validation des composants (1 joueur, 1 sortie, ≥1 objet)
- ✅ Gestion fluide des fenêtres
- ✅ Touche ESC pour quitter
- ✅ Gestion appropriée de la mémoire (pas de fuites)

### Partie Bonus
- 🎮 **Système de Patrouille d'Ennemis** : Ennemis Charizard qui se déplacent selon des motifs prédéfinis
- ⚔️ **Mécanisme d'Attaque** : Appuyez sur ESPACE pour lancer des Pokéballs sur les ennemis
- 💖 **Système de Vie** : 3 PV affichés avec des indicateurs visuels
- 🎨 **Animations de Sprites** : Animations fluides du personnage dans les 4 directions
- 📊 **HUD à l'Écran** : Compteur de mouvements et PV affichés à l'écran
- 🎬 **États du Jeu** : Menu, gameplay et écrans de game over
- 💀 **Game Over** : Déclenché quand les PV atteignent 0

## 🔧 Prérequis

- **OS** : Linux (Ubuntu 24 recommandé)
- **Compilateur** : gcc
- **Bibliothèques** : 
  - MiniLibX (incluse dans `minilibx-linux/`)
  - Bibliothèques de développement X11
  - libm (bibliothèque mathématique)

### Installation des Dépendances

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Fedora
sudo dnf install gcc make libX11-devel libXext-devel
```

## 📥 Installation {#installation-fr}

1. **Cloner le dépôt**
```bash
git clone https://github.com/votreusername/so_long.git
cd so_long
```

2. **Compiler le projet**

Pour la partie obligatoire :
```bash
make
```

Pour la partie bonus :
```bash
make bonus
```

3. **Nettoyer les fichiers objets (optionnel)**
```bash
make clean    # Supprimer les fichiers objets
make fclean   # Supprimer les fichiers objets et exécutables
make re       # Tout recompiler
make help     # Afficher l'aide en anglais et français
```

## 🎮 Utilisation

### Version Obligatoire
```bash
./so_long map/validmap/[nom_carte].ber
```

### Version Bonus
```bash
./so_long_bonus map/map_bonus/[nom_carte].ber
```

### Exemples de Cartes

**Cartes valides :**
```bash
./so_long map/validmap/minimal.ber
./so_long map/validmap/maze.ber
./so_long_bonus map/map_bonus/42.ber
```

**Test de cartes invalides :**
```bash
./so_long map/invalidmap/no_exit.ber        # Erreur : Besoin d'une seule sortie
./so_long map/invalidmap/hole_top.ber       # Erreur : La carte doit être entourée de murs
./so_long map/invalidmap/exit_unreachable.ber  # Erreur : Impossible d'atteindre la sortie
```

## 🎮 Contrôles du Jeu

### Version Obligatoire
| Touche | Action |
|--------|--------|
| W / ↑ | Monter |
| A / ← | Gauche |
| S / ↓ | Descendre |
| D / → | Droite |
| ESC | Quitter |

### Version Bonus
| Touche | Action |
|--------|--------|
| W / ↑ | Monter |
| A / ← | Gauche |
| S / ↓ | Descendre |
| D / → | Droite |
| ESPACE | Attaquer (lancer une Pokéball) |
| ESC | Quitter |
| ENTRÉE | Démarrer (depuis le menu) |

## 🗺️ Format de Carte

Les cartes utilisent l'extension `.ber` et doivent respecter ces règles :

### Composants de Carte
- `0` - Espace vide (herbe)
- `1` - Mur (arbre)
- `C` - Objet à collecter (Pokéball)
- `E` - Sortie (Centre Pokémon)
- `P` - Position de départ du joueur
- `M` - Ennemi (Charizard) - **Bonus uniquement**

### Exigences de Carte
1. **Forme rectangulaire** - Toutes les lignes doivent avoir la même longueur
2. **Entourée de murs** - La bordure doit être composée uniquement de `1`
3. **Chemin valide** - Le joueur doit pouvoir atteindre tous les objets et la sortie
4. **Exactement 1 joueur** (`P`)
5. **Exactement 1 sortie** (`E`)
6. **Au moins 1 objet** (`C`)

### Exemple de Carte
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## 📁 Structure du Projet {#structure-du-projet-fr}

```
so_long/
├── Makefile                    # Configuration de compilation
├── README.md                   # Ce fichier
├── bonus/
│   ├── include_bonus/          # Fichiers d'en-tête bonus
│   └── src_bonus/              # Fichiers source bonus
├── include/                    # Fichiers d'en-tête obligatoires
├── libft/                      # Bibliothèque C personnalisée
├── map/                        # Cartes de jeu
│   ├── invalidmap/             # Exemples de cartes invalides
│   ├── map_bonus/              # Cartes bonus (avec ennemis)
│   └── validmap/               # Exemples de cartes valides
├── minilibx-linux/             # Bibliothèque graphique MiniLibX
├── src/                        # Fichiers source obligatoires
└── texture/                    # Textures du jeu
```

## 🎨 Fonctionnalités Bonus

### Système d'Ennemis
- **IA de Patrouille** : Les ennemis suivent des schémas prédéfinis avec une portée configurable
- **Détection de Collision** : Toucher un ennemi inflige 1 PV de dégâts
- **Mouvement Dynamique** : Les ennemis se déplacent dans 4 directions avec changement de sprites

### Système de Combat
- **Attaques Directionnelles** : Les attaques ciblent la case devant le joueur
- **Élimination d'Ennemis** : Les ennemis touchés sont retirés de la carte
- **Retour Visuel** : Confirmations d'attaque affichées dans le terminal

### Système d'Animation
- **Sprites à 4 Directions** : Animations séparées pour haut, bas, gauche, droite
- **Cycle d'Images** : Boucle d'animation fluide à 3 images
- **Détection de Mouvement** : Les animations ne jouent que pendant le mouvement

### Éléments HUD
- **Affichage PV** : Cœurs visuels montrant la santé actuelle (3/3, 2/3, 1/3)
- **Compteur à l'Écran** : Nombre de mouvements affiché dans la fenêtre

### États du Jeu
- **Écran de Menu** : Écran d'accueil avec explication des contrôles
- **Gameplay Actif** : Jeu complet avec toutes les mécaniques
- **Écran Game Over** : Affiché quand les PV atteignent 0

## 🐛 Gestion des Erreurs

Le programme valide les cartes en profondeur et fournit des messages d'erreur clairs :

```bash
Erreur : La carte doit être rectangulaire.
Erreur : La carte doit être entourée d'une bordure.
Erreur : Besoin d'une seule sortie.
Erreur : Besoin d'au moins un objet à collecter.
Erreur : Impossible d'atteindre tous les objets.
Erreur : Impossible d'atteindre la sortie.
Erreur : Le fichier de carte doit être .ber
Erreur : Impossible d'ouvrir le fichier de carte
```

## 🧪 Tests

Le projet inclut des cartes de test complètes dans `map/validmap/` et `map/invalidmap/`.

## 🔍 Détails des Algorithmes

### Recherche de Chemin par Remplissage (Flood Fill)
Algorithme récursif pour valider l'accessibilité de la carte et s'assurer que tous les objets et la sortie sont atteignables.

## 🛠️ Détails Techniques {#détails-techniques-fr}

### Gestion de la Mémoire
- Toute la mémoire allouée sur le tas est correctement libérée
- Pas de fuites mémoire (testé avec Valgrind)
- Nettoyage approprié en cas d'erreur et de sortie normale

### Graphismes
- Utilise MiniLibX pour le rendu
- Format XPM pour les textures (64x64 pixels)
- Architecture pilotée par les événements

### Options de Compilation
```
-Wall -Wextra -Werror -g3
```

## 📚 Acquis Pédagogiques

- Fondamentaux de la programmation graphique
- Gestion des événements et boucles de jeu
- Implémentation d'algorithmes (recherche de chemin)
- Gestion de la mémoire en C
- Analyse et validation de cartes
- Systèmes d'animation
- Gestion des états du jeu

---

## 👤 Author / Auteur

**fducrot** - 42 Lausanne Student / Étudiant 42 Lausanne

[![GitHub](https://img.shields.io/badge/GitHub-fducrot-181717?style=flat-square&logo=github)](https://github.com/fducrot)

---

## 📄 License

This project is part of the 42 school curriculum. Feel free to use it as a reference, but please don't copy it directly for your own 42 projects.

---

<p align="center">
  <i>🇬🇧 "Catch 'em all, one pixel at a time."</i>
  <br><br>
  <i>🇫🇷 "Attrapez-les tous, un pixel à la fois."</i>
</p>

---

<p align="center">
  Made with ❤️ at 42 Lausanne
</p>
