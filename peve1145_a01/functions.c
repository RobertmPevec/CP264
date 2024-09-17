/**
 * -------------------------------------
 * @file  functions.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @Robert Pevec, 169081145, peve1145@mylaurier.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */

#include "functions.h"
#include "math.h"
#include "math.h"
double feet_to_acres(int feet) {
    return feet / 43560.0;
}
int mow_lawn(double width, double height, double mowing_rate) {
    return width * height / mowing_rate;
}
int date_convert(int date) {
    int day = date / 1000000;
    int month = (date / 10000) % 100;
    int year = date % 10000;
    int date_format = year * 10000 + month * 100 + day;
    return date_format;
}

int falling_time(int distance) {
    double g = 9.80665;
    double time = sqrt((2 * (double)distance) / g);
    return (int)time;
}

double hypotenuse(double a, double b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}
int sum_even(int a) {
    int starting_int = 2;
    int total = 0;
    while (starting_int <= a) {
        total += starting_int;
        starting_int += 2;
    }
    return total;
}
double sum_partial_harmonic(int a) {
    double total = 0;
    for (int i = 1; i <= a; i++) {
        total += 1.0 / i;
    }
    return total;
}
int population_growth(int current_population, double growth_rate, int target_population) {
    int years = 0;
    while (current_population < target_population) {
        current_population += current_population * (growth_rate / 100);
        years++;
    }
    return years;
}