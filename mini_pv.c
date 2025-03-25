/*
** EPITECH PROJECT, 2025
** my_pv
** File description:
** mini_pv.c
*/

#include "include.h"

static int display_time(pv_t *my_pv)
{
    time_t clock = time(NULL);
    struct tm *current_time = localtime(&clock);
    struct timeval tv = {0};

    if (gettimeofday(&tv, NULL) == -1 || current_time == NULL)
        return 84;
    my_pv->time_elaps = tv.tv_sec;
    printf("%d-%02d-%02d %02d:%02d:%02d.%.2ld: ", 1900 + current_time->tm_year,
    current_time->tm_mon, current_time->tm_mday, current_time->tm_hour,
    current_time->tm_min, current_time->tm_sec, tv.tv_sec + tv.tv_usec);
    return 0;
}

static int display(pv_t *my_pv)
{
    float percentage = 0;

    if (my_pv->total == 0 || display_time(my_pv) == 84)
        return 84;
    percentage = ((float)my_pv->bytes_read / (float)my_pv->total) * 100;
    printf("Progress: %lld b / %lld b (%.2f %%). Bitrate: %lld bytes/sec.\n",
    my_pv->bytes_read, my_pv->total, percentage, my_pv->time_elaps / my_pv->
    bytes_read);
    return 0;
}

static int get_file_size(char *pathname, pv_t *my_pv)
{
    struct stat stat_file = {0};

    if (stat(pathname, &stat_file) == -1)
        return 84;
    my_pv->total = stat_file.st_size;
    return 0;
}

/**
 * @brief Lit les données de stdin et les écrit vers stdout.
 *
 * Cette fonction lit les données en utilisant un buffer
 * et affiche périodiquement les statistiques de progression.
 *
 * @param buffer_size Taille du buffer en octets.
 * @return int Retourne 0 si succès, -1 en cas d'erreur.
 */
int mini_pv(char *pathname, pv_t *my_pv)
{
    FILE *stream = fopen(pathname, "r");
    ssize_t bytes_read = 0;
    char buffer[2048] = {0};

    if (!stream)
        return 84;
    if (get_file_size(pathname, my_pv) == 84){
        fclose(stream);
        return 84;
    }
    do {
        bytes_read = fread(buffer, 1, 2048, stream);
        my_pv->bytes_read += bytes_read;
        if (display(my_pv) == 84){
            fclose(stream);
            return 84;
        }
    } while (bytes_read > 0);
    fclose(stream);
    printf("Done.\n");
    return 0;
}

int main(int ac, char **av)
{
    pv_t my_pv = {0};

    if (ac != 2){
        dprintf(2, "\033[0;31mToo many arguments!\033[0m\n");
        return 84;
    }
    return mini_pv(av[1], &my_pv);
}
