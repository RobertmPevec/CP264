/**
 * -------------------------------------
 * @file  movie.c
 * movie Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "movie.h"

// Array of strings for movie genres.
const char *const GENRES[] = {"science fiction", "fantasy", "drama", "romance", "comedy", "zombie", "action",
        "historical", "horror", "war", "mystery"};

// Calculates size of GENRES array.
const int GENRES_COUNT = sizeof GENRES / sizeof *GENRES;

void movie_init(movie_struct *source, const char *title, int year, const char *director, int genre, float rating) {
    assert(year >= FIRST_YEAR);
    assert(rating >= MIN_RATING && rating <= MAX_RATING);
    strncpy(source->title, title, MAX_STRING - 1);
    source->title[MAX_STRING - 1] = '\0';
    strncpy(source->director, director, MAX_STRING - 1);
    source->director[MAX_STRING - 1] = '\0'; 
    if (year >= 1888 && year <= 2050) {
        source->year = year;
    } else {
        source->year = -1;
    }
    if (genre >= 0 && genre < GENRES_COUNT) {
        source->genre = genre;
    } else {
        source->genre = -1;
    }
    if (rating < 0 || rating > 10) {
        source->rating = -1.0;
    } else if ((int)rating == rating) {  
        source->rating = (float)((int)rating);
    } else {
        source->rating = rating;
    }
}

void movie_copy(const movie_struct *source, movie_struct *target) {
    strncpy(target->title, source->title, MAX_STRING - 1);
    target->title[MAX_STRING - 1] = '\0';
    strncpy(target->director, source->director, MAX_STRING - 1);
    target->director[MAX_STRING - 1] = '\0';
    target->year = source->year;
    target->genre = source->genre;
    target->rating = source->rating;
}

int movie_compare(const movie_struct *source, const movie_struct *target) {
    int compare;
    int result = strcmp(source->title, target->title);
    if (result == 0) {
        if (source->year < target->year) {
            compare = -1;
        } else if (source->year > target->year) {
            compare = 1;
        } else {
            compare = 0;
        }
    } else {
        if (result > 0) {
            compare = 1;
        } else {
            compare = -1;
        }
    }
    return compare;
}

void movie_print(const movie_struct *source) {
    if (source == NULL) {
        printf("No Movie");
    } else {
        printf("%-10s %s\n", "Title:", source->title);
        printf("%-10s %d\n", "Year:", source->year);
        printf("%-10s %s\n", "Director:", source->director);
        printf("%-10s %s\n", "Genres:", GENRES[source->genre]);
        printf("%-10z %f\n", "Rating:", source->rating);
    }
}

char* movie_key(char *str, size_t max_length, movie_struct *source) {
    int title_length = max_length - 7;
    strncpy(str, source->title, title_length);
    str[title_length] = '\0';
    snprintf(str + strlen(str), max_length - strlen(str), ", %d", source->year);
    return str;
}

void genres_menu() {
    int i = 0;
    while (GENRES_COUNT > i) {
        printf("%d: %s\n", i, GENRES[i]);
        i += 1;
    }
}