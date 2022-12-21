#include "Race.h"

void 
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
		break;
	}
	case VehicleTypeCentaur: {
		participants.push_back(new Centaur());
		break;
	}
	default: {
		std::cout << "Wrong vehicle type" << VehicleTypeStr[vt] << std::endl;
	}
	}
}

void 
Race::start() {
	for (auto& participant : participants) {
		auto time = participant->get_race_time(_distance);
		RaceResult result = RaceResult(participant->get_type(), time);
		_results.insert(result);
	}
}