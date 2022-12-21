#include <iostream>
#include "Race.h"
#include "Vehicle.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdio>
#include <conio.h>

int main()
{
	while (true) {
		std::cout << "Welcome to Fantasy race" << std::endl;

		std::cout << "Choose type of race" << std::endl;
		for (int i = 0; i < RaceTypeLast; ++i) {
			std::cout << i + 1 << ". " << RaceTypeStr[i] << std::endl;
		}

		std::cout << "New race is? ";
		int type_of_race;
		std::cin >> type_of_race;

		std::cout << "What's the race distance? ";
		unsigned distance = 0;
		std::cin >> distance;

		Race race(distance);

		bool VehicleIsChosen[VehicleTypeLast] = { false };
		do {
			std::cout << "Choose transport" << std::endl;
			for (int i = 0; i < VehicleTypeLast; ++i) {
				if (!VehicleIsChosen[i]) {
					std::cout << i + 1 << ". " << VehicleTypeStr[i] << std::endl;
				}
			}
			if (race.count_participant() >= 2) {
				std::cout << "0. Finish registration" << std::endl;
			}
			std::cout << "New vehicle is? ";
			int chosenVehicle;
			std::cin >> chosenVehicle;
			if (chosenVehicle == 0) break;

			if (VehicleIsChosen[chosenVehicle - 1]) {
				std::cout << "You can't register the same vehicle twice" << std::endl;
				continue;
			}

			VehicleIsChosen[chosenVehicle - 1] = true;
			race.add_participant(static_cast<VehicleType> (chosenVehicle - 1));

		} while (true);

		std::cout << "Press any key to start race" << std::endl;
		getch();

		for (int i = 3; i > 0; --i) {
			printf("\r****** %i *******", i);
			Sleep(1000);
		}
		printf("\r****** Go *******\n");
		race.start();
		for (int i = 0; i < 17; ++i) {
			printf("*");
			Sleep(10);
		}
		std::cout << std::endl;
		printf("\r****** Standings *******\n");
		auto standings = race.get_standing();
		int rank = 1;
		for (auto result : standings) {
			std::cout << rank << ". " << result.print() << std::endl;
			++rank;
		}

		std::string choice;
		std::cout << "New game(yes/no) ? ";
		std::cin >> choice;

		if (choice == "no") break;
	}

	return 0;
}