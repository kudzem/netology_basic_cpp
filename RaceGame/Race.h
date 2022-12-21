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
	RaceTypeGround,
	RaceTypeAir,
	RaceTypeMixed,
	RaceTypeLast // should be last and do not use it
};

const char* RaceTypeStr[] = { "Ground",
							  "Air",
							  "Mixed"
};

class RaceResult {
	VehicleType _vt;
	double _time;
public:
	RaceResult(VehicleType vt, double time) : _vt(vt), _time(time) {}
	bool operator< (const RaceResult& other) const { return this->_time < other._time; }
	std::string print() { return std::string(VehicleTypeStr[_vt]) + "\t Time: " + std::to_string(_time); }
};

class Race {
public:
	Race(unsigned distance) : _distance(distance) {}
	size_t count_participant() const { return participants.size(); }
	void add_participant(VehicleType vt);
	void start();
	std::set<RaceResult> get_standing() { return _results; }
private:
	unsigned _distance;
	std::vector<Vehicle*> participants;
	std::set<RaceResult> _results;
};