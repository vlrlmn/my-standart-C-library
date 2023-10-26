#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx/mlx.h"

# define W_KEY 87
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define ESC_KEY 53
# define P_KEY 35
# define E_KEY 14
# define C_KEY 8
# define WALL 1
# define SPACE 0
# define TEXTURE_H 64
# define TEXTURE_W 64 

# define WALL_IMG
# define PLAYER_IMG
# define EXIT_IMG
# define ENEMY_IMG
# define ITEM_IMG

typedef struct s_map
{
    int height;
    int width;
    int player_position;
    int score;
    int current_score;
    char    **mapdata;
    void    *wall;
    void    *exit;
    void    *items;
    void    *player;
    int enemy_position;
    int gameover;
    int show_steps;
} t_map;

int move_player();

#endif