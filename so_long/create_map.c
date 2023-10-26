#include "so_long.h"

typedef struct s_data
{
    void    *img;
    void    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
	void *mlx;
    void *mlx_win;
}  t_data;

int destroy_window(void *mlx, void *mlx_win)
{
    free(mlx);
    mlx_destroy_window(mlx, mlx_win);
	return (0);
}


void convert_image(t_map img)
{
	void *image;

	image = mlx_xpm_file_to_image(img.mlx, path, TEXTURE_W, TEXTURE_H);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	create_map(t_map game)
{
    t_data img;

	img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, TEXTURE_W * game.width, TEXTURE_H * game.height, "./so_long");
    mlx_hook(img.mlx, 17, 0L, mlx_destroy_window, &img); // close the window by crest keypress
    mlx_hook(img.mlx, 2, 1L<<0, move_player, &img); // 2 - press key
    mlx_loop(img.mlx);
}