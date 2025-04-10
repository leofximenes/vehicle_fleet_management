#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "vehicles/vehicles.h"
#include "menu/menu.h"

void add_vehicle(Vehicle fleet[], int *total_vehicles, Vehicle new_vehicle) {

    fleet[*total_vehicles] = new_vehicle;
    (*total_vehicles)++;
    println("Vehicle added successfully!");
}