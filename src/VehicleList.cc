#include <vehicle/vehicle.h>

#include <stdexcept>

using namespace vehicle;
using namespace std;

VehicleList::VehicleList(): _size(0) {}

VehicleList::size() const {
	return _size;
}

Vehicle VehicleList::operator[](const int index) const {
	if (index < 0 || _size <= index) {
		throw out_of_range("[FunctionList::operator[]] Index is out of range.");
	}
	return _vehicles[index];
}

void VehicleList::insert(int index, Vehicle veh) {
	if (index < 0 || _size == CAPACITY || index > CAPACITY) {
		throw out_of_range("[FunctionList::operator[]] Index is out of range.");
	}
	else {
		if (index <= _size) {
			for (i = CAPACITY - 1; i != _size; i--) {
				_vehicles[i] = _vehicles[i - 1];
			}
			_vehicles[index] = veh;
			_size++;
		}
		else {
			_size++;
			vehicles[_size] = veh;
		}
	}
}

void VehicleList::remove(int index) {
		if (index < 0 || index > _size) {
			throw out_of_range("[FunctionList::operator[]] Index is out of range.");
		}
		for (int i = index; i <= _size - 1; i++) {
			_vehicles[i] = _vehicles[i + 1];
		vehicles[_size] = Vehicle[_size + 1];
	}
}

int vehicle::int index_of_max_veh_tax(const VehicleList& vehicles, int S) {
	max_index = -1;
	max_tax = 0;
	
	const auto n = vehicles.size();
	
	for (int i = 0; i <= n; i++) {
		if (vehicles[i].compute_vehicle_tax(S) > max_tax)
		{
			max_index = i;
			max_tax = vehicles[i].compute_vehicle_tax(S);
		}
	}
	
	return max_index;
}
	