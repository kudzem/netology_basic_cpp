#include "Race.h"
#include <sstream>
#include <iomanip>


Race::~Race() {
	for (Vehicle* participant : participants) {
		delete participant;
	}
}

std::string 
RaceResult::print() 
{ 
	std::ostringstream s;
	s << std::fixed << std::setprecision(2) << _time;
	return std::string(VehicleTypeStr[_vt]) + "\t Time: " + s.str();
}

void 
Race::start() {
	for (auto& participant : participants) {
		auto time = participant->get_race_time(_distance);
		RaceResult result = RaceResult(participant->get_type(), time);
		_results.insert(result);
	}
}

bool
Race::add_participant(VehicleType vt)
{
	switch (vt) {
	case VehicleTypeBroomstick: {
		participants.push_back(new BroomStick());
		break;
	}
	case VehicleTypeEagle: {
		participants.push_back(new Eagle());
		break;
	}
	case VehicleTypeCarpetPlane: {
		participants.push_back(new CarpetPlane());
		break;
	}
	case VehicleTypeCamel: {
		participants.push_back(new Camel());
		break;
	}
	case VehicleTypeFastCamel: {
		participants.push_back(new FastCamel());
		break;
	}
	case VehicleTypeBoots: {
		participants.push_back(new Boots());
		return true;
	}
	case VehicleTypeCentaur: {
		participants.push_back(new Centaur());
		break;
	}
	default: {
		return false;
	}
	}
	VehicleIsChosen[vt] = true;
	return true;
}

bool
AirRace::add_participant(VehicleType vt)
{
		switch (vt) {
		case VehicleTypeBroomstick: {
			participants.push_back(new BroomStick());
			break;
		}
		case VehicleTypeEagle: {
			participants.push_back(new Eagle());
			break;
		}
		case VehicleTypeCarpetPlane: {
			participants.push_back(new CarpetPlane());
			break;
		}
		default: {
			return false;
		}
		}
		VehicleIsChosen[vt] = true;
		return true;
}


bool
GroundRace::add_participant(VehicleType vt)
{
	switch (vt) {
		case VehicleTypeCamel: {
			participants.push_back(new Camel());
			break;
		}
		case VehicleTypeFastCamel: {
			participants.push_back(new FastCamel());
			break;
		}
		case VehicleTypeBoots: {
			participants.push_back(new Boots());
			break;
		}
		case VehicleTypeCentaur: {
			participants.push_back(new Centaur());
			break;
		}
		default: {
			return false;
		}
	}
	VehicleIsChosen[vt] = true;
	return true;
}