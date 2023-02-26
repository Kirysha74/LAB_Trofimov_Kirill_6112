#include <vehicle/vehicle.h>

#include <stdexcept>

using namespace vehicle;
using namespace std;

Vehicle Vehicle::create_car(char model_name, int engine_capacity) {
	return Vehicle(Type::Car, model_name, engine_capacity, 0);
}

Vehicle Vehicle::create_moto(char model_name, int engine_capacity) {
	return Vehicle(Type::Moto, model_name, engine_capacity, 0);
}

Vehicle Vehicle::create_truck(char model_name, int engine_capacity, tonnage) {
	return Vehicle(Type::Truck, model_name, engine_capacity, tonnage);
}

Vehicle::Vehicle(): _type(Type::Car), _model_name("Audi R8"), _engine_capacity(4163) {}

Vehicle::Vehicle(const Type type, const char model_name, int engine_capacity, int tonnage): _type(Type::type), _model_name(model_name), _engine_capacity(engine_capacity), _tonnage(tonnage) {}

Type Vehicle::get_type() {
	return _type;
}

char Vehicle::get_model_name() const {
	return _model_name;
}

int Vehicle::get_engine_capacity() const {
	return _engine_capacity;
}

int Vehicle::get_tonnage() const {
	if (_type == Car || _type == Moto) {
		printf("No tonnage!\n");
		return 0;
	}
	return tonnage;
}
int Vehicle::compute_vehicle_tax(int S) const {
	switch(_type) {
		case Type::Car:
			return S * _engine_capacity;
		case Type::Moto:
			return S * _engine_capacity;
		case Type::Truck:
			return S * _engine_capacity;
	}
}
