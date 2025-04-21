#include <stdio.h>
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
                break;
            case 3:
                generate_report(fleet, *total_vehicles);
                break;
            case 4:
                update_mileage(fleet, *total_vehicles);
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
    clear_input_buffer();

    int option_type;

    println("\n1. Car\n2. Motorcycle\n3. Truck\nSelect type:");
    scanf("%d", &option_type);
    new_vehicle.type = option_type;
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

    char search_plate[9];
    int found = 0;

    clear_input_buffer();

    printf("Write the plate number from desired vehicle:\n");
    read_string(search_plate, sizeof(search_plate));

    for(int i = 0; i < total_vehicles; i++) {
        if (strcmp(fleet[i].plate, search_plate) == 0) {
            printf("\n Vehicle from plate === %s === found:\n", search_plate);
            printf("\n | TYPE: %s\n | PLATE: %s\n | MODEL: %s\n | YEAR: %d\n | MILEAGE: %d km\n",
                    get_vehicle_type(fleet[i].type), fleet[i].plate, fleet[i].model, fleet[i].year, fleet[i].mileage);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Vehicle from plate '%s' not found !", search_plate);
    }

}

void generate_report(Vehicle fleet[], int total_vehicles) {

    if (total_vehicles == 0) {
        printf("No vehicles found !");
        return;
}
    printf("\n=== List of Vehicles ===\n");

    for (int i = 0; i < total_vehicles; i++) {
        printf("\n#%d Vehicle:\n", i + 1);
        printf("\n | TYPE: %s\n | PLATE: %s\n | MODEL: %s\n | YEAR: %d\n | MILEAGE: %d km\n",
            get_vehicle_type(fleet[i].type), fleet[i].plate, fleet[i].model, fleet[i].year, fleet[i].mileage);
    }

}

void update_mileage(Vehicle fleet[], int total_vehicles) {

    char search_plate[9];
    int found = 0;
    int new_mileage = 0;

    clear_input_buffer();

    printf("Write the plate number from desired vehicle:\n");
    read_string(search_plate, sizeof(search_plate));

    clear_input_buffer();

    for(int i = 0; i < total_vehicles; i++) {
        if (strcmp(fleet[i].plate, search_plate) == 0) {
            printf("\n Vehicle from plate === %s === found:\n", search_plate);
            printf("\n Vehicle current mileage: %d km\n", fleet[i].mileage);

            printf("\nType the new mileage\n");
            scanf("%d", &new_mileage);

            fleet[i].mileage = new_mileage;
            printf("\n Mileage updated !\n");

            found = 1;
            break;
        }
    }
        if (!found) {
            printf("Vehicle from plate '%s' not found !", search_plate);
        }
    }
