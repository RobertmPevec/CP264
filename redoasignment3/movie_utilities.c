/**
 * -------------------------------------
 * @file  movie_utilities.c
 * Assignment 2 movie_utilities Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "movie_utilities.h"

void get_movie(movie_struct *source) {
        char title[81];
    int year, genre;
    char director[81];
    float rating;
    printf("Title: ");
    scanf(" %80[^\n]", title);
    printf("Year: ");
    scanf("%d", &year);
    printf("Director: ");
    scanf(" %80[^\n]", director);
    printf("Genres\n"
    "0: science fiction\n"
    "1: fantasy\n"
    "2: drama\n"
    "3: romance\n"
    "4: comedy\n"
    "5: zombie\n"
    "6: action\n"
    "7: historical\n"
    "8: horror\n"
    "9: war\n"
    "10: mystery\n"
    "Genre: ");
    scanf("%d", &genre);
    if (genre < 0 || genre >= GENRES_COUNT - 1) {
        genre = -1;
    }
    printf("Rating: ");
    scanf("%f", &rating);
    if (rating < 0.0 || rating > 10.0) {
        rating = -1;
    }
    strcpy(source->title, title);
    source->year = year;
    strcpy(source->director, director);
    source->genre = genre;
    source->rating = rating;
}

void read_movie(movie_struct *source, const char *line) {
        char movie_line[256];
    strncpy(movie_line, line, sizeof(movie_line) - 1);
    movie_line[sizeof(movie_line) - 1] = '\0';
    char *value = strtok(movie_line, "|");
    strcpy(source->title, value); 
    value = strtok(NULL, "|");
    char *pointer;
    source->year = strtol(value, &pointer, 10);
    value = strtok(NULL, "|");
    strcpy(source->director, value); 
    value = strtok(NULL, "|");
    source->rating = strtof(value, &pointer);
    value = strtok(NULL, "|");
    source->genre = strtol(value, &pointer, 10);
}

void read_movies(movie_array_struct *movies, FILE *fp) {
    char buffer[256];
    int n = movies->count;
    movies->capacity = MOVIES_INIT;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && n < movies->capacity) {
        read_movie(&movies->items[n], buffer);
        n++;
    }
    movies->count = n;
}
