#include <stdio.h>
#include "utils/utils.h"
#include "vehicles/vehicles.h"
#include "menu/menu.h"

int main(void) {
    Vehicle fleet[100];
    int total_vehicles = 0;

    show_menu(fleet, &total_vehicles);
    return 0;
}