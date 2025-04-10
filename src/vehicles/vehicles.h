#ifndef VEHICLES_H
#define VEHICLES_H

#define MAX_PLATE 10
#define MAX_MODEL 30

typedef enum {
    CAR = 1,
    MOTORCYCLE,
    TRUCK
} VehicleType;

typedef struct {

    char plate[MAX_PLATE];
    char model[MAX_MODEL];
    int year;
    int mileage;
    VehicleType type;
} Vehicle;

void add_vehicle(Vehicle fleet[], int *total_vehicles, Vehicle new_vehicle);

#endif
