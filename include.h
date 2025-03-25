/*
** EPITECH PROJECT, 2025
** my_pv
** File description:
** structure.h
*/

#ifndef INCLUDE_H
    #define INCLUDE_H
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/time.h>
    #include <time.h>
    #include <stdint.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
typedef struct pv_s {
    // Taille du buffer pour lire les données (4 Ko)
    unsigned long long bytes_read;
    unsigned long long total;
    unsigned long long bitrate;
    unsigned long time_elaps;
} pv_t;
#endif
