# Cub3D

Cub3D is a 3D game engine project inspired by Wolfenstein 3D. It aims to introduce to raycasting, a fundamental technique in early 3D rendering.

## Features
- **Raycasting rendering**: Simulates a 3D environment from a 2D map.
- **Player movement**: Allows movement and rotation within the game world.
- **Wall collisions**: Ensures realistic interactions with the environment.
- **MLX42 graphics**: Uses the MLX42 library for rendering.
- **Configurable maps**: Reads and interprets maps from `.cub` files.

## Setup
1. Clone the repository:
   ```sh
   git clone https://github.com/louisecollonge/cub3d.git && cd cub3d
   ```
2. Install dependencies:
   ```sh
   make
   ```

## Usage
Run the executable with a valid map file:
```sh
./cub3D maps/sample.cub
```

## Controls
- `W` / `S` - Move forward/backward
- `A` / `D` - Move left/right
- Left / Right arrow - Rotate the view
- `ESC` - Quit the game

## Map Format
The game uses `.cub` files for maps. A valid map contains:
- Walls represented by `1`
- Empty space by `0`
- Player start position (`N`, `S`, `E`, `W`)
- Textures and colors defined in the file, before the map itself

Example:
```
NO texture/north.png
SO texture/south.png
WE texture/west.png
EA texture/east.png

F 200,100,0
C 200,100,0

111111
100001
10N001
100001
111111
```
