#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    size_t bytes_read;
    // хранятся данный между выховами 
    // то что прочиталось из файла но после конца строки
    static char *remainder;
    static size_t remainder_size;
    char* line;
    char* new_line;
    char* new_remainder;
    char* temp;
    size_t line_size;
    size_t i;
    size_t j;
    size_t k;

    i = 0;
    j = 0;
    k = 0;
    line_size = 0;
    line = NULL;

    while (1)
    {
        if (remainder_size) {
            i = 0;
            while(i < remainder_size && remainder[i] != '\n')
            {
                i++;
            }
            if (i < remainder_size)
            {
                // если нашли конец строки в buffer
                // i - индекс символа '\n' в buffer (или длина строки включая '\n')
                new_line = malloc(sizeof(char) * (i + 1));
                j = 0;
                // перкладываем в новую строку остаток с прошлого вызова функции get_next_line
                while(j < i + 1)
                {
                    new_line[j] = remainder[j];
                    j++;
                }
                new_remainder = malloc(sizeof(char) * (remainder_size - i - 1));
                while (j < remainder_size)
                {
                    new_remainder[j-i-1] = remainder[j];
                    j++;
                }
                
                line_size += i;
                temp = line;
                line = new_line;
                if (temp)
                {
                    free(temp);
                }
                temp = remainder;
                remainder = new_remainder;
                remainder_size = remainder_size - i - 1;
                if (temp)
                {
                    free(temp);
                }
                // нашли конце строки - выходим
                break;
            }
        }
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        if (!bytes_read)
        {
            if (!remainder_size)
            {
                break;
            }
            new_line = malloc(sizeof(char) * (remainder_size + line_size));
            j = 0;
            // перкладываем в новую строку остаток с прошлого вызова функции get_next_line
            while(j < remainder_size)
            {
                new_line[j] = remainder[j];
                j++;
            }
            if (remainder)
            {
                remainder_size = 0;
                free (remainder);
                remainder = NULL;
            }
            // перекладываем в новую строку то что было прочитано за
            // текущий вызов функции get_next_line
            while(j < line_size)
            {
                new_line[j] = line[j];
                j++;
            }

            line_size += i;
            temp = line;
            line = new_line;
            if (temp){
                free(temp);
            }

            // выходим выдаем то что осталось
            break;
        }
        buffer[bytes_read] = '\0';
        i = 0;
        while(i < bytes_read && buffer[i] != '\n')
        {
            i++;
        }
        if (i < bytes_read)
        {
            // если нашли конец строки в buffer
            // i - индекс символа '\n' в buffer
            new_line = malloc(sizeof(char) * (remainder_size + line_size + i + 1));
            j = 0;
            // перкладываем в новую строку остаток с прошлого вызова функции get_next_line
            while(j < remainder_size)
            {
                new_line[j] = remainder[j];
                j++;
            }
            if (remainder)
            {
                remainder_size = 0;
                free (remainder);
                remainder = NULL;
            }
            // перекладываем в новую строку то что было прочитано за
            // текущий вызов функции get_next_line
            while(j < line_size)
            {
                new_line[j] = line[j];
                j++;
            }
            k = 0;
            // перекладываем то что прочитали последний раз в read
            while(k < i + 1)
            {
                new_line[j+k] = buffer[k];
                k++;
            }
            line_size += i;
            temp = line;
            line = new_line;
            if (temp)
            {
                free(temp);
            }
            // сохраняем то что осталось после символа \n для следующего вызова get_next_line
            remainder_size = bytes_read - i - 1;
            if (remainder_size)
            {
                remainder = malloc(sizeof(char) * remainder_size);
                j = 0;
                while (j < remainder_size)
                {
                    remainder[j] = buffer[i + j + 1];
                    j++;
                }
            }
            // нашли конце строки - выходим
            break;
        }
        else
        {
            // если НЕ нашли конец строки в buffer
            new_line = malloc(sizeof(char) * (remainder_size + line_size + bytes_read));
            j = 0;
            // перкладываем в новую строку остаток с прошлого вызова функции get_next_line
            while(j < remainder_size)
            {
                new_line[j] = remainder[j];
                j++;
            }
            if (remainder)
            {
                remainder_size = 0;
                free (remainder);
                remainder = NULL;
            }
            // перекладываем в новую строку то что было прочитано за
            // текущий вызов функции get_next_line
            while(j < line_size)
            {
                new_line[j] = line[j - remainder_size];
                j++;
            }
            k = 0;
            // перекладываем то что прочитали последний раз в read
            while(k < bytes_read)
            {
                new_line[j+k] = buffer[k];
                k++;
            }
            line_size += bytes_read;
            temp = line;
            line = new_line;
            if (temp)
            {
                free(temp);
            }
            if (bytes_read < BUFFER_SIZE) 
            {
                // конец строки не нашли и файл закончился - выходим
                break;
            }
        }   
    }
    return(line);
}

int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    fd = open("test2.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    close(fd);
}