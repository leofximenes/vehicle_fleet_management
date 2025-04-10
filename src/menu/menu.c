#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "utils/utils.h"
#include "vehicles/vehicles.h"

void show_menu(Vehicle fleet[], int *total_vehicles) {

    int option;
    while (1) {

        println("\n=== Vehicle Fleet Management ===");
        println("\n1. Register Vehicle");
        println("\n2. Check Vehicle");
        println("\n3. Generate Fleet Report");
        println("\n4. Update Mileage");
        println("\n5. Exit");
        print("\nChoose an Option: ");

        scanf("%d", &option);

        switch (option) {

            case 1:
                register_vehicle(fleet, total_vehicles);
                break;
            case 2:
                check_vehicle(fleet, *total_vehicles);
                //to do//
                break;
            case 3:
                //to do//
                break;
            case 4:
                //to do//
                break;
            case 5:
                println("Exiting...");
                return;
            default:
                println("Invalid Option !");
        }
    }
}

void register_vehicle(Vehicle fleet[], int *total_vehicles) {
    Vehicle new_vehicle;

    println("\n1. Car\n2. Motorcycle\n3. Truck\nSelect type:\n");
    new_vehicle.type = read_int();
    clear_input_buffer();

    println("Enter plate:");
    read_string(new_vehicle.plate, MAX_PLATE);

    println("Enter model:");
    read_string(new_vehicle.model, MAX_MODEL);

    println("Enter year:");
    new_vehicle.year = read_int();

    println("Enter mileage:");
    new_vehicle.mileage = read_int();

    add_vehicle(fleet, total_vehicles, new_vehicle);
}

void check_vehicle(Vehicle fleet[], int total_vehicles) {
    //TO DO//
}