/**
 * -------------------------------------
 * @file  movie_utilities.c
 * Assignment 2 movie_utilities Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-09-13
 *
 * -------------------------------------
 */
#include "movie_utilities.h"

void get_movie(movie_struct *source) {
    char movie_line[81];
    printf("Enter a movie object (e.g. Star Wars: Episode IV - A New Hope|1977|George Lucas|8.7|0,6):\n");
    fgets(movie_line, sizeof(movie_line), stdin);
    char *value = strtok(movie_line, "|");
    strcpy(source->title, value); 
    value = strtok(NULL, "|");
    char *pointer;
    source->year = strtol(value, &pointer, 10);
}

void read_movie(movie_struct *source, const char *line) {
    
}
