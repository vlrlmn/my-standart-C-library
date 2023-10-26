#include <fcntl.h>
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

main(int argc, char **argv)
{
    t_data *game;
    int fd;

    if (!init_struct(&game))
        exit(1);
    if (argc != 2)
        err("Invalid number of arguments");
    fd = open (argv[1], O_RDONLY);
    if (fd < 0)
        err("File not fould");
    if (check_map_name(argv[1], ".ber"))
        err("Invalid filename, use .ber"); //err needs to free *game, write(with fd 2 message and exit);
}