/*
** EPITECH PROJECT, 2025
** my_pv
** File description:
** mini_pv.c
*/

#include "include.h"

/**
 * @brief Displays the current time for my program.
 *
 * This function displays the current time in the format (yy:mm:dd hh:mm:ss).
 *
 * @param my_pv Structure containing: bytes read, total bytes to read,
 * and the current time in seconds.
 * @return int Returns 0 on success, 84 on error.
*/
static int display_time(pv_t *my_pv)
{
    time_t clock = time(NULL);
    struct tm *current_time = localtime(&clock);
    struct timeval tv = {0};

    if (gettimeofday(&tv, NULL) == -1 || current_time == NULL){
        perror("An error occurred");
        return 84;
    }
    my_pv->time_elapsed = tv.tv_sec - my_pv->time_start;
    if (my_pv->time_elapsed == 0)
        return -1;
    dprintf(2, "%d-%02d-%02d %02d:%02d:%02d.%.2ld: ",
    1900 + current_time->tm_year, current_time->tm_mon,
    current_time->tm_mday, current_time->tm_hour, current_time->tm_min,
    current_time->tm_sec, tv.tv_usec);
    return 0;
}

/**
 * @brief Global display of my program.
 *
 * This function displays all useful information: current time
 * (yy:mm:dd hh:mm:ss), progress (bytes read / total bytes), and the bitrate.
 *
 * @param my_pv Structure containing: bytes read, total bytes to read,
 * and the current time in seconds.
 * @return int Returns 0 on success, 84 on error.
*/
int display(pv_t *my_pv)
{
    float percentage = 0;
    int time = display_time(my_pv);

    if (time == -1)
        return 0;
    if (time == 84 || my_pv->time_elapsed == 0)
        return 84;
    percentage = ((float)my_pv->bytes_read / (float)my_pv->total) * 100;
    dprintf(2, "Progress %lld b / %lld b (%.2f %%). Bitrate: %lld bytes/sec.\n"
    , my_pv->bytes_read, my_pv->total, percentage, my_pv->bytes_read /
    my_pv->time_elapsed);
    return 0;
}

/**
 * @brief Gets the total size of a file.
 *
 * This function retrieves the total size of the file passed
 * as a parameter.
 *
 * @param pathname Name of the file to handle.
 * @param my_pv Structure containing: bytes read, total bytes to read,
 * and the current time in microseconds.
 * @return int Returns 0 on success, 84 on error.
*/
static int get_file_size(const char *const pathname, pv_t *my_pv)
{
    struct stat stat_file = {0};

    if (pathname == NULL){
        perror("An error occurred");
        return 84;
    }
    if (stat(pathname, &stat_file) == -1){
        perror("An error occurred");
        return 84;
    }
    my_pv->total = stat_file.st_size;
    return 0;
}

/**
 * @brief Reads data from stdin and writes it to stdout.
 *
 * This function reads data using a buffer
 * and displays progress statistics.
 *
 * @param pathname Name of the file to handle.
 * @param my_pv Structure containing: bytes read, total bytes to read,
 * and the current time in seconds.
 * @return int Returns 0 on success, 84 on error.
*/
int mini_pv(const char *const pathname, pv_t *my_pv)
{
    int fd = open(pathname, O_RDONLY);
    ssize_t bytes_read = 0;
    char buffer[4096] = {0};

    if (fd == -1){
        perror("An error occurred");
        return 84;
    }
    bytes_read = read(fd, buffer, 4096);
    for (; bytes_read > 0; bytes_read = read(fd, buffer, 4096)){
        my_pv->bytes_read += bytes_read;
        write(STDOUT_FILENO, buffer, 4096);
        if (display(my_pv) == 84){
            close(fd);
            return 84;
        }
    }
    close(fd);
    dprintf(2, "Done !\n");
    return 0;
}

/**
 * @brief Handles program termination on signal.
 *
 * This function stops the program when Ctrl+C
 * (SIGINT) is detected.
 *
 * @param sig The signal number that triggered the handler.
 * @return void
 */
static void sigint_hand(int sig)
{
    (void)sig;
    dprintf(2, "Done !\n");
    exit(0);
}

int main(int ac, char **av)
{
    pv_t my_pv = {0};
    struct timeval tv = {0};

    if (ac != 2){
        dprintf(2, "\033[0;31mInvalid number of arguments!\033[0m\n");
        return 84;
    }
    if (gettimeofday(&tv, NULL) == -1){
        perror("An error occurred");
        return 84;
    }
    my_pv.time_start = tv.tv_sec;
    signal(SIGINT, sigint_hand);
    if (get_file_size(av[1], &my_pv) == 84)
        return 84;
    return mini_pv(av[1], &my_pv);
}
