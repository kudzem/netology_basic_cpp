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
#include <cstdlib>

bool organize_race(Race** race);
void open_registration(Race* race);
void start_race(Race* race);
void print_standings(Race* race);

int main()
{
	while (true) {
		Race* race = nullptr;
		if (false == organize_race(&race)) continue;

		open_registration(race);

		std::cout << "Press any key to start race";
		_getch();

		start_race(race);
		print_standings(race);

		delete race;

		std::string choice;
		std::cout << "New game(yes/no) ? ";
		std::cin >> choice;

		if (choice == "no") break;
	}

	return 0;
}

bool organize_race(Race** race)
{
	system("CLS");
	std::cout << "Welcome to Fantasy race" << std::endl;

	std::cout << "Choose type of race" << std::endl;
	for (int i = RaceTypeGround; i < RaceTypeLast; ++i) {
		std::cout << i << ". " << RaceTypeStr[i] << std::endl;
	}

	std::cout << "New race is? ";
	unsigned type_of_race;
	std::cin >> type_of_race;

	if (type_of_race == RaceTypeUnknown || type_of_race >= RaceTypeLast) {
		std::cout << "You have to choose correct race type" << std::endl;
		return false;
	}

	std::cout << "What's the race distance? ";
	unsigned distance = 0;
	std::cin >> distance;

	switch (type_of_race) {
	case RaceTypeGround: {
		*race = new GroundRace(distance);
		break;
	}
	case RaceTypeAir: {
		*race = new AirRace(distance);
		break;
	}
	default: {
		*race = new Race(distance, RaceTypeMixed);
		break;
	}
	}

	return true;
}

void open_registration(Race* race) {
	system("CLS");
	std::cout << "Welcome to race registration" << std::endl;
	while (true) {
		std::cout << "Choose transport" << std::endl;
		for (int i = 0; i < VehicleTypeLast; ++i) {
			if (!race->is_registered(static_cast<VehicleType>(i)) &&
				race->is_allowed(static_cast<VehicleType>(i))) {
				std::cout << i + 1 << ". " << VehicleTypeStr[i] << std::endl;
			}
		}
		if (race->count_participant() >= 2) {
			std::cout << "0. Finish registration" << std::endl;
		}
		std::cout << "New vehicle is? ";
		int chosenVehicle;
		std::cin >> chosenVehicle;
		if (chosenVehicle == 0) break;

		if (race->is_registered(static_cast<VehicleType>(chosenVehicle - 1))) {
			std::cout << "You can't register the same vehicle twice" << std::endl;
			continue;
		}

		if (!race->add_participant(static_cast<VehicleType> (chosenVehicle - 1))) {
			std::cout << "You can't register this vehicle to this race" << std::endl;
		}

	};
}

void start_race(Race* race) {
	system("CLS");
	for (int i = 3; i > 0; --i) {
		printf("\r************** %i ************", i);
		Sleep(1000);
	}
	printf("\r************** Go ************\n");
	race->start();
	for (int i = 0; i < 30; ++i) {
		printf("*");
		Sleep(10);
	}
	std::cout << std::endl;
}

void print_standings(Race* race) {
	printf("\r********* Standings **********\n");
	auto standings = race->get_standing();
	int rank = 1;
	for (auto result : standings) {
		std::cout << rank << ". " << result.print() << std::endl;
		++rank;
	}
}