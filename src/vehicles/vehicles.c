#include "vehicles/vehicles.h"
#include "utils/colors.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


bool valid_plate(char *plate) {
    if (strlen(plate) != 7) {
        return false;
    }

    for (int i = 0; plate[i] != '\0'; i++) {
        plate[i] = toupper(plate[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (!isalpha(plate[i])) {
            return false;
        }
    }
    for (int i = 3; i < 7; i++) {
        if (!isdigit(plate[i])) {
            return false;
        }
    }
    return true;
}

bool valid_model(char *model) {
    if (strlen(model) >= MAX_MODEL - 1) {
        return false;
    }
    for (int i = 0; model[i] != '\0'; i++) {
        model[i] = toupper(model[i]);
    }
    return true;
}

void add_vehicle(Vehicle fleet[], int *total_vehicles, Vehicle new_vehicle) {
    if (*total_vehicles < MAX_VEHICLES) {
        fleet[*total_vehicles] = new_vehicle;
        (*total_vehicles)++;
    } else {
        printf(COLOR_RED"Fleet is full!"COLOR_RESET);
    }
}

void initialize_fleet(Vehicle fleet[], int *total_vehicles) {
    Vehicle vehicle1 = {.type = CAR, .plate = "ABZ1234", .model = "CELTA", .year = 2004, .mileage = 4000};
    Vehicle vehicle2 = {.type = CAR, .plate = "XYZ5678", .model = "PALIO", .year = 2015, .mileage = 15000};
    Vehicle vehicle3 = {.type = MOTORCYCLE, .plate = "DEF5678", .model = "HONDA BIZ", .year = 2019, .mileage = 10000};
    Vehicle vehicle4 = {.type = MOTORCYCLE, .plate = "GHI8765", .model = "HONDA POP 100", .year = 2020, .mileage = 5000};
    Vehicle vehicle5 = {.type = TRUCK, .plate = "JKL4321", .model = "FORD F4000", .year = 2018, .mileage = 30000};
    Vehicle vehicle6 = {.type = TRUCK, .plate = "MNO6543", .model = "VOLVO FH", .year = 2020, .mileage = 10000};

    fleet[0] = vehicle1;
    fleet[1] = vehicle2;
    fleet[2] = vehicle3;
    fleet[3] = vehicle4;
    fleet[4] = vehicle5;
    fleet[5] = vehicle6;

    *total_vehicles = 6;
}