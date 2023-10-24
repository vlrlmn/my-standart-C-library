#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
    int x;
    int y;// поля структуры t_map
} t_map;

typedef struct s_data
{
    void   *mlx_ptr;
    void    *win_ptr;
    void    *textures[5];
    t_map   *map; 
}   t_data;

void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

#endif