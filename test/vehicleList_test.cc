#include <gtest/gtest.h>

#include <vehicle/vehicle.h>

using namespace vehicle;

TEST(VehicleListTest, CapacityCheck) {
	const auto veh = Vehicle::create_car("Audi R8", 5000);
	VehicleList vehicles;
	for (int i = 0; i < VehicleList::CAPACITY; i++) {
		vehicles.insert(i, veh);
	}
	ASSERT_ANY_THROW(vehicles.insert(10, veh));
}

TEST(VehicleListTest, TaxCheck) {
	VehicleList vehicles1;
	vehicles1.insert(0, Vehicle::create_car("Audi R8", 5000));
	vehicles1.insert(1, Vehicle::create_truck("MAN", 3500, 12));
	vehicles1.insert(2, Vehicle::create_moto("Yamaha R6", 600));
	EXPECT_EQ(index_of_max_veh_tax(vehicles1, 0.5), 1);
}

TEST(VehicleListTest, NoResult) {
	VehicleList vehicles1;
	EXPECT_EQ(index_of_max_veh_tax(vehicles1, 0.5), -1);
}