#include <stdio.h>

int shipping_costs(int arr[], int size) {
    int cost = 15;
    int additional_charge = 1;
    int total_cost = 0;
    // weight in grams
    int max_weight = 1000;
    int weightper = 100;
    for (int i = 0; i < size; i += 1) {
        int package = arr[i];
        if (package < 0) {
            printf("Error: package weight cannot be less than 0");
        } else if (package <= max_weight) {
            total_cost += cost;
        } else {
            int newcost = ((package - max_weight) / weightper * additional_charge) + cost;
            total_cost += newcost;
        }
    }
    return total_cost;
}