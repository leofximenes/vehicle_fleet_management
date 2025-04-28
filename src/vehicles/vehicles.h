#ifndef VEHICLES_H
#define VEHICLES_H

#include <stdbool.h>

#define MAX_PLATE 8
#define MAX_MODEL 30
#define MAX_VEHICLES 100

typedef enum {
    CAR = 1,
    MOTORCYCLE,
    TRUCK
} VehicleType;

typedef struct {

    char plate[MAX_PLATE];
    char model[MAX_MODEL];
    char plate_copy[8];
    int year;
    int mileage;
    VehicleType type;
} Vehicle;

bool valid_plate(char *plate);
bool valid_model(char *model);

void initialize_fleet(Vehicle fleet[], int *total_vehicles);
void add_vehicle(Vehicle fleet[], int *total_vehicles, Vehicle new_vehicle);

#endif
