#include "utils/utils.h"
#include "vehicles/vehicles.h"
#include "utils/colors.h"

void add_vehicle(Vehicle fleet[], int *total_vehicles, Vehicle new_vehicle) {

    fleet[*total_vehicles] = new_vehicle;
    (*total_vehicles)++;
    println(COLOR_GREEN "\nVehicle added successfully!" COLOR_RESET "\n");

}
