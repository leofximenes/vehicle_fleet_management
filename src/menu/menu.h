#ifndef MENU_H
#define MENU_H

#include "vehicles/vehicles.h"
#include "utils/utils.h"

void register_vehicle(Vehicle fleet[], int *total_vehicles);
void check_vehicle(Vehicle fleet[], int total_vehicles);
void show_menu(Vehicle fleet[], int *total_vehicles);

#endif
