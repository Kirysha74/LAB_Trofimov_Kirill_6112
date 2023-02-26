#pragma once

namespace vehicle{
	
	enum class Type
	{
		Car,
		Truck,
		Moto,
	};

	class Vehicle
	{
	private:
		Type _type;
		char _model_name[256];
		int _engine_capacity;
		int _tonnage;
		Vehicle(Type type, char model_name, int engine_capacity, int _tonnage);
	public:
		static Vehicle create_car(char model_name, int engine_capacity);
		static Vehicle create_truck(char model_name, int engine_capacity, int tonnage);
		static Vehicle create_moto(char model_name, int engine_capacity);
		Type get_type() const;
		char get_model_name() const;
		int get_engine_capacity() const;
		int get_tonnage() const;
		int compute_vehicle_tax(int S) const;
	};

	class VehicleList
	{
	public:
		static const int CAPACITY = 10;
	private:
		Vehicle _vehicles[CAPACITY];
		int _size;
	public:
		VehicleList();

		int size() const;

		Vehicle operator[](const int index) const;

		void insert(int index, Vehicle veh);

		void remove(int index);
	};

	int index_of_max_veh_tax(const VehicleList& vehicles, int S);
}