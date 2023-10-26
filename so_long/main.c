#include "so_long.h"
#include <stdio.h>

void reterr(char *message, int len)
{
    write(2, message, len);
    exit(1);
}

int check_map_name(char *file, char *format)
{
    int file_name_index;
    int file_len;
    int format_len;

    file_len = ft_strlen(file);
    format_len = ft_strlen(format);
    file_name_index = file_len - format_len;

    if (ft_strncmp(file + file_name_index, format, format_len + 1) != 0)
        return (1);
    return(0);
}

int main(int argc, char **argv)
{
    t_map *game;

    int fd;
    if (argc != 2)
        reterr("There are not 2 args\n", 22);
    fd = open(argv[1], O_RDONLY);
    if(!fd)
        reterr("File cannot be opened\n", 23);
    if (!check_map_name(argv[1], ".ber"))
        game = init_game();
    else
        reterr("This file has invalid format, use .ber\n", 40);
    return (0);
}