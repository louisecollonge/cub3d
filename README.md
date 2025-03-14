# Cub3D

## Description
The Cub3D project aims to create a 3D graphical representation of a maze using a first-person perspective view. This representation is built using raycasting principles, which simulate the 3D environment by casting rays to determine what objects or walls are in the player's line of sight.

The program will use the MiniLibX library for graphics rendering, and the player will be able to move around the maze with basic controls and interact with the environment. The goal is to accurately implement raycasting and proper window management while rendering textures based on wall orientations (North, South, East, West).

## Features
- Raycasting: Uses raycasting to create a first-person perspective view inside a maze.
- MiniLibX: Utilizes MiniLibX for graphics rendering, window management, and event handling.
- Textures: Walls have different textures depending on their direction (North, South, East, West).
- Floor and Ceiling Colors: Custom colors for the floor and ceiling are supported.
- Camera Movement:
  - Arrow keys for rotating the camera left and right.
  - WASD keys for moving the camera (forward, left, backward, right).
- Window Management: Proper handling of window minimization, focus changes, and program exit.
- Clean Exit: Close the window with the ESC key or the window's close button to exit the program cleanly.
- Map Parsing: The program loads a map from a .cub file and parses its contents.
- Error Handling: Displays errors for invalid maps or incorrect file formatting.

## Prerequisites
- MiniLibX: The project uses MiniLibX for graphical operations, window management, and handling user inputs.
- C Compiler: The project must be compiled using gcc with the default flags (-Wall -Wextra -Werror).

## Installation
Clone the repository:
```bash
git clone https://github.com/your-username/cub3d.git
```
Navigate to the project directory:
```bash
cd cub3d
```
Compile the project:
```bash
make
```

## Usage
To run the project, provide a .cub map file as the first argument:

```bash
./cub3d map.cub
```

## Controls
- Arrow Keys: Rotate the camera left and right.
- `W`, `A`, `S`, `D`: Move the player forward, left, backward, and right.
- `ESC`: Close the window and exit the program.
- Window Close Button: Click the window's close button (red cross) to exit the program.

## Map File Structure
The program expects a `.cub` file with the following elements:

1) Textures:

- `NO` (North texture): `NO ./path_to_the_north_texture`
- `SO` (South texture): `SO ./path_to_the_south_texture`
- `WE` (West texture): `WE ./path_to_the_west_texture`
- `EA` (East texture): `EA ./path_to_the_east_texture`

2) Colors:

- Floor color: `F 220,100,0` (RGB format).
- Ceiling color: `C 225,30,0` (RGB format).

3) Map:

- The map is represented by a grid of the following characters:
  - `0` for empty spaces.
  - `1` for walls.
  - `N`, `S`, `E`, `W` for the player's starting position and orientation.
- The map must be enclosed by walls (i.e., the outer border must be 1s), or the program will return an error.

## Example `.cub` File
```bash
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
1011101111
1000100001
1011101111
1111111111
```

## File Parsing
- The file should contain the textures, colors, and map in a specific order.
- Textures and colors are followed by the map definition, which must be closed (i.e., surrounded by walls).
- Empty lines can be used to separate sections.
- The map section must contain only valid characters (`0`, `1`, `N`, `S`, `E`, `W`), and all other elements must be defined according to the required format.

## Error Handling
- If the map is not properly enclosed by walls, the program will display an error message and quit.
- Invalid file formats or missing elements in the `.cub` file will result in an error message.
