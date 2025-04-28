#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "utils/utils.h"
#include "vehicles/vehicles.h"
#include <utils/colors.h>


void show_menu(Vehicle fleet[], int *total_vehicles) {
    int option;
    while (1) {
        println(COLOR_YELLOW"\n==="COLOR_RESET" Vehicle Fleet Management"COLOR_YELLOW"==="COLOR_RESET);
        println(COLOR_YELLOW"\n1."COLOR_RESET" Register Vehicle");
        println(COLOR_YELLOW"\n2."COLOR_RESET" Check Vehicle");
        println(COLOR_YELLOW"\n3."COLOR_RESET" Generate Fleet Report");
        println(COLOR_YELLOW"\n4."COLOR_RESET" Update Mileage");
        println(COLOR_YELLOW"\n5."COLOR_RESET COLOR_RED" Exit"COLOR_RESET);
        printf("\nChoose an "COLOR_YELLOW"Option:"COLOR_RESET" ");
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
                println(COLOR_RED"Invalid Option !"COLOR_RESET);
        }
    }
}

void register_vehicle(Vehicle fleet[], int *total_vehicles) {
    Vehicle new_vehicle;

    clear_input_buffer();
    int option_type;

    while (1) {
        println("\n"COLOR_YELLOW"1."COLOR_RESET" Car\n"
        COLOR_YELLOW"2."COLOR_RESET" Motorcycle\n"
        COLOR_YELLOW"3."COLOR_RESET" Truck\n"
        COLOR_YELLOW"4."COLOR_RESET" Exit\n\n"
        "Select "COLOR_YELLOW"type:"COLOR_RESET"\n");
        scanf("%d", &option_type);

        if (option_type == 4) {
            println(COLOR_YELLOW"Exiting vehicle registration."COLOR_RESET);
            return;
        }

        if (option_type >= 1 && option_type <= 3) {
            new_vehicle.type = option_type;
            break;
        }

        println(COLOR_RED"Invalid option! Please choose a valid vehicle type."COLOR_RESET);
    }

    clear_input_buffer();

    while (1) {
        println("\nEnter"COLOR_YELLOW" plate"COLOR_RESET" (or type "COLOR_YELLOW"'exit'"COLOR_RESET" to exit):\n");
        read_string(new_vehicle.plate, MAX_PLATE);

        if (strcmp(new_vehicle.plate, "exit") == 0) {
            println(COLOR_YELLOW"Exiting vehicle registration."COLOR_RESET);
            return;
        }

        if (valid_plate(new_vehicle.plate)) {
            break;
        }
        println(COLOR_RED"Invalid plate format! It must contain 7 digits! (Example: ABC1234)"COLOR_RESET);
    }

    while (1) {
        println("\nEnter "COLOR_YELLOW"model"COLOR_RESET"(or type"COLOR_YELLOW"'exit'"COLOR_RESET" to exit):\n");
        read_string(new_vehicle.model, MAX_MODEL);

        if (strcmp(new_vehicle.model, "exit") == 0) {
            println(COLOR_YELLOW"Exiting vehicle registration."COLOR_RESET);
            return;
        }

        if (strlen(new_vehicle.model) == 0) {
            println(COLOR_RED"Model cannot be empty!"COLOR_RESET);
            continue;
        }
        if (valid_model(new_vehicle.model)) {
            break;
        }
        println(COLOR_RED"Invalid model! It must be up to 29 characters!"COLOR_RESET);
    }

    while (1) {
        println("\nEnter "COLOR_YELLOW"year"COLOR_RESET"(or type "COLOR_YELLOW"'exit'"COLOR_RESET" to exit):\n");
        int year = read_int();

        if (year == -1) {
            println(COLOR_YELLOW"Exiting vehicle registration."COLOR_RESET);
            return;
        }

        new_vehicle.year = year;
        break;
    }

    while (1) {
        println("\nEnter"COLOR_YELLOW" mileage"COLOR_RESET" (or type "COLOR_YELLOW"'exit'"COLOR_RESET" to exit):\n");
        int mileage = read_int();

        if (mileage == -1) {
            println(COLOR_YELLOW"Exiting vehicle registration."COLOR_RESET);
            return;
        }

        new_vehicle.mileage = mileage;
        break;
    }

    add_vehicle(fleet, total_vehicles, new_vehicle);
}

void check_vehicle(Vehicle fleet[], int total_vehicles) {

    char search_plate[9];
    int found = 0;
    clear_input_buffer();
    printf("\nWrite the "COLOR_YELLOW"plate number (In Uppercase)"COLOR_RESET" from desired vehicle"COLOR_YELLOW" (Example: ABC1234):"COLOR_RESET"\n");
    read_string(search_plate, sizeof(search_plate));

    for(int i = 0; i < total_vehicles; i++) {
        if (strcmp(fleet[i].plate, search_plate) == 0) {
            printf(COLOR_GREEN "\nVehicle from plate" COLOR_RESET " === %s === " COLOR_GREEN "found" COLOR_RESET"\n", search_plate);
            printf("\n"
                COLOR_YELLOW" | TYPE:"COLOR_RESET" %s\n"
                COLOR_YELLOW" | PLATE:"COLOR_RESET" %s\n"
                COLOR_YELLOW" | MODEL:"COLOR_RESET" %s\n"
                COLOR_YELLOW" | YEAR:"COLOR_RESET" %d\n"
                COLOR_YELLOW" | MILEAGE: "COLOR_RESET"%d km\n",
                    get_vehicle_type(fleet[i].type), fleet[i].plate, fleet[i].model, fleet[i].year, fleet[i].mileage);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf(COLOR_RED "Vehicle from plate "COLOR_RESET"=== %s === "COLOR_RED" not found !\n"COLOR_RESET, search_plate);
    }
}

void generate_report(Vehicle fleet[], int total_vehicles) {

    if (total_vehicles == 0) {
        printf(COLOR_RED"No vehicles found !"COLOR_RESET);
        return;
    }

    printf("\n"COLOR_YELLOW"==="COLOR_RESET" List of Vehicles "COLOR_YELLOW"==="COLOR_RESET"\n");
    printf(COLOR_YELLOW "\n%d/100\n" COLOR_RESET,total_vehicles);

    for (int i = 0; i < total_vehicles; i++) {

        printf(COLOR_YELLOW"\n#%d"COLOR_RESET" Vehicle:\n", i + 1);
        printf(COLOR_YELLOW"\n | TYPE:"COLOR_RESET" %s\n"
        COLOR_YELLOW" | PLATE:"COLOR_RESET" %s\n"
        COLOR_YELLOW" | MODEL:"COLOR_RESET" %s\n"
        COLOR_YELLOW" | YEAR:"COLOR_RESET" %d\n"
        COLOR_YELLOW" | MILEAGE:"COLOR_RESET" %d km\n",
            get_vehicle_type(fleet[i].type), fleet[i].plate, fleet[i].model, fleet[i].year, fleet[i].mileage);
    }
}

void update_mileage(Vehicle fleet[], int total_vehicles) {

        char search_plate[9];
        int found = 0;
        int new_mileage = 0;
        clear_input_buffer();

        printf("\nWrite the "COLOR_YELLOW"plate number"COLOR_RESET" from desired vehicle:\n");
        read_string(search_plate, sizeof(search_plate));

        for(int i = 0; i < total_vehicles; i++) {
            if (strcmp(fleet[i].plate, search_plate) == 0) {
                printf(COLOR_GREEN"\nVehicle from plate" COLOR_RESET " === %s === " COLOR_GREEN "found:\n"COLOR_RESET, search_plate);
                printf("\nVehicle current "COLOR_YELLOW"mileage:"COLOR_RESET" %d km\n", fleet[i].mileage);
                printf("\nType the new "COLOR_YELLOW"mileage"COLOR_RESET"\n");
                scanf("%d", &new_mileage);
                fleet[i].mileage = new_mileage;
                printf(COLOR_GREEN"\nMileage updated !\n"COLOR_RESET);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf(COLOR_RED"Vehicle from plate"COLOR_RESET" '%s'"COLOR_RED" not found !\n"COLOR_RESET, search_plate);
        }
    }

