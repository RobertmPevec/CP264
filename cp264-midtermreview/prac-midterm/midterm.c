/* CP264 Fall 2021 Midterm */

/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 * I certify that i completed this midterm according to academic honesty guidelines.
 * I attest that i did not use any external help, neither in person nor virtually. I
 * understand that plagiarizing will lead to my failure in the course, in addition to
 *other penalties according to the University policies.
 * ---------------------------------
 */

/**
 * ---------------------------------
 *	I was getting warnings from the midterm_test.c file but my midterm.c file still
 *	gives the correct output.
 * ---------------------------------
 */

//---- Do not change imports -----------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "midterm.h"
//---------------------------------------------

//----------------- Task 1 ---------------------
void replace_most_freq(const char *filename, char c, FILE* destination) {
	char buffer[256];
	char letters[26] = {0};
	char most_frequent_char;
	int largest_index = -1;
	FILE *file = fopen(filename, "r");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
		for (int i = 0; buffer[i] != '\0'; i += 1) {
			if (isalpha(buffer[i])) {
				int index = tolower(buffer[i]) - 'a';
				    if (index >= 0 && index < 26) {
                    	letters[index]++;  // Increment the letter count
                	}
				}

			}
		}
		int max_frequency = 0;
		for (int n = 0; n < 26; n += 1) {
			if (letters[n] > max_frequency) {
				max_frequency = letters[n];
				largest_index = n;
			}
		}
		most_frequent_char = 'a' + largest_index;
		FILE *file = fopen(filename, "r");
		while (fgets(buffer, sizeof(buffer), filename != NULL)) {
			for (int i = 0; buffer[i] != '\0'; i += 1) {
				if (buffer[i] == most_frequent_char) {
					buffer[i] = c;
				}
			}
			fputs(buffer, c);
		}
	}

//----------------- Task 2 ---------------------


//----------------- Task 3 ---------------------