#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include "Vehicle.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Boots.h"
#include "Centaur.h"
#include "CarpetPlane.h"
#include "Eagle.h"
#include "Broomstick.h"

enum RaceType {
	RaceTypeUnknown,
	RaceTypeGround,
	RaceTypeAir,
	RaceTypeMixed,
	RaceTypeLast // should be last and do not use it
};

const char* RaceTypeStr[] = { "Unknown",
                              "Ground",
							  "Air",
							  "Mixed"
};

class RaceResult {
	VehicleType _vt;
	double _time;
public:
	RaceResult(VehicleType vt, double time) : _vt(vt), _time(time) {}
	bool operator< (const RaceResult& other) const { return this->_time < other._time; }
	std::string print();
};

class Race {
public:
	Race(unsigned distance, RaceType raceType) : _distance(distance), _raceType(raceType) {
		std::fill(VehicleIsChosen, VehicleIsChosen + VehicleTypeLast, false);
	}
	virtual ~Race() {}

	size_t count_participant() const { return participants.size(); }
	virtual bool add_participant(VehicleType vt);
	bool is_registered(VehicleType vt) { return VehicleIsChosen[vt]; }
	virtual bool is_allowed(VehicleType vt) { return (vt >= VehicleTypeBroomstick && vt < VehicleTypeLast); }
	void start();
	std::set<RaceResult> get_standing() { return _results; }
protected:
	std::vector<Vehicle*> participants;
	bool VehicleIsChosen[VehicleTypeLast];
private:
	unsigned _distance;
	std::set<RaceResult> _results;
	RaceType _raceType;
};

class AirRace : public Race {
public:
	AirRace(unsigned distance) : Race(distance, RaceTypeAir) { }
	bool add_participant(VehicleType vt) override;
	bool is_allowed(VehicleType vt) override { 
		return (vt >= VehicleTypeBroomstick && vt <= VehicleTypeCarpetPlane); }
};

class GroundRace : public Race {
public:
	GroundRace(unsigned distance) : Race(distance, RaceTypeGround) {  }
	bool add_participant(VehicleType vt) override;
	bool is_allowed(VehicleType vt) override { return (vt >= VehicleTypeCentaur && vt <= VehicleTypeBoots); }
};