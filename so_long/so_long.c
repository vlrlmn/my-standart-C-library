#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

typedef struct s_data
{
    void    *img;
    void    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int width;
    int height;
}  t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < data->width && y >= 0 && y < data->height)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

void draw_circle(t_data *data, int xc, int yc, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;


    while(x >= y)
    {
        my_mlx_pixel_put(data, xc + x, yc + y, color);
        my_mlx_pixel_put(data, xc + y, yc + x, color);
        my_mlx_pixel_put(data, xc - y, yc + x, color);
        my_mlx_pixel_put(data, xc - x, yc + y, color);
        my_mlx_pixel_put(data, xc - x, yc - y, color);
        my_mlx_pixel_put(data, xc - y, yc - x, color);
        my_mlx_pixel_put(data, xc + y, yc - x, color);
        my_mlx_pixel_put(data, xc + x, yc - y, color);

        if(err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}
int main(void)
{
    void *mlx;
    void *mlx_win;
    t_data img;

    img.width = 500;
    img.height = 500;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Hello world");

    img.img = mlx_new_image(mlx, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, 
                                &img.endian);
    draw_circle(&img, 100, 100, 50, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}