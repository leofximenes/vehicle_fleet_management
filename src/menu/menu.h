#ifndef MENU_H
#define MENU_H

#include "vehicles/vehicles.h"

void register_vehicle(Vehicle fleet[], int *total_vehicles);
void check_vehicle(Vehicle fleet[], int total_vehicles);
void show_menu(Vehicle fleet[], int *total_vehicles);
void generate_report(Vehicle fleet[], int total_vehicles);
void update_mileage(Vehicle fleet[], int total_vehicles);

#endif
