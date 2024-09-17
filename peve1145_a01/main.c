/**
 * -------------------------------------
 * @file  main.c
 * Assignment 1 Main Source Code File
 * -------------------------------------
 * @Robert Pevec, 169081145, peve1145@mylaurier.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    double square_feet = 100000;
    double acres = feet_to_acres(square_feet);
    printf("feet_to_acres(%.2f) -> %.2f\n", square_feet, acres);

    double width = 10.0;
    double height = 10.0;
    double mowing_rate = 5.0;
    int mow_time = mow_lawn(width, height, mowing_rate);
    printf("mow_lawn(%.2f, %.2f, %.2f) -> %d\n", width, height, mowing_rate, mow_time);

    int date = 25101962;
    int converted_date = date_convert(date);
    printf("date_convert(%d) -> %d\n", date, converted_date);

    double distance_fallen = 50.0;
    int time_falling = falling_time(distance_fallen);
    printf("falling_time(%.2f) -> %d\n", distance_fallen, time_falling);

    double side_a = 3.0;
    double side_b = 4.0;
    double hypo = hypotenuse(side_a, side_b);
    printf("hypotenuse(%.2f, %.2f) -> %.2f\n", side_a, side_b, hypo);

    int max_num = 100;
    int sum_of_evens = sum_even(max_num);
    printf("sum_even(%d) -> %d\n", max_num, sum_of_evens);

    int n = 4;
    double harmonic_sum = sum_partial_harmonic(n);
    printf("sum_partial_harmonic(%d) -> %f\n", n, harmonic_sum);

int initial_population = 10;
double growth_rate = 10.0;
int target_population = 100;
int years_to_target = population_growth(initial_population, growth_rate, target_population);
printf("population_growth(%d, %.2f, %d) -> %d\n", initial_population, growth_rate, target_population, years_to_target);
    return 0;
}