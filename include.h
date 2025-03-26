/*
** EPITECH PROJECT, 2025
** my_pv
** File description:
** structure.h
*/

#ifndef INCLUDE_H
    #define INCLUDE_H
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <sys/time.h>
    #include <time.h>
    #include <stdint.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <signal.h>
    #include <termios.h>
    #include <fcntl.h>

typedef struct pv_s {
    // Total number of bytes already read
    unsigned long long bytes_read;
    // Total number of bytes to read
    unsigned long long total;
    // Elapsed time in seconds
    unsigned long time_elapsed;
    // Time when start in seconds
    unsigned long time_start;
} pv_t;
#endif
