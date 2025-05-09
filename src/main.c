#include <stdio.h>
#include "vehicles/vehicles.h"
#include "menu/menu.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main(void) {

#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    SetConsoleOutputCP(CP_UTF8);
#endif

    Vehicle fleet[100];
    int total_vehicles = 0;

    initialize_fleet(fleet, &total_vehicles);

    show_menu(fleet, &total_vehicles);
    return 0;
}