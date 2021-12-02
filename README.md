# WOLFENSTEIN-RAYCASTING-ENGINE
## Introduction
Raycasting engine inspired by engine used in the "Wolfenstein 3D" game. It can therefore only run in MacOSX. The project runs using the MiniLibX, a simplified version of the Xlib.

## Launch and setup

```
git clone git@github.com:RectangularArch/WOLFENSTEIN-RAYCASTING-ENGINE.git
```

Using `make` in project directory will build the executable `cub3D` file. Use `make start` or `./cub3D map.cub` to run the programm.

Using `make save` will save `screenshot.bmp` file from the starting player position. You can adjust the image resolution using `map.cub` configuration file.

## About configuration file
Сonfiguration file should be called `map.cub` and contain a dataset for building a map and an image.

Valid map can't be splitted by empty lines, must be surrounded by walls (1) and should contain characters:

```
1                                             |-> wall
0                                             |-> empty area with floor
2                                             |-> sprite
N S E W                                       |-> player position with view direction
```
```
R 640 480                                     |-> resolution
NO textures/path_to_the_north_texture.xpm     |-> path to NO texture
SO textures/path_to_the_south_texture.xpm     |-> path to SO texture
WE textures/path_to_the_west_texture.xpm      |-> path to WE texture
EA textures/path_to_the_east_texture.xpm      |-> path to EA texture
S textures/sprite.xpm                         |-> path to sprite

C 62, 150, 230                                |-> ceiling rgb
F 62, 62, 62                                  |-> floor rgb

111111111111
100000000001
100020020001
10000E000001
100020020001
100000000001
100000000001
111111111111
```
The parser will indicate invalid cases and return error message with description.
## Controls

Move around the with `W` `A` `S` `D`.

View rotation with `←` and `→`.

Press `ESC` to exit or click the red cross.
