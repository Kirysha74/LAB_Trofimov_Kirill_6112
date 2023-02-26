#include <gtest/gtest.h>

#include <vehicle/vehicle.h>

using namespace vehicle;

TEST(VehicleTest, CarTest) {
	const auto car1 = Vehicle::create_car("Audi R8", 5000);
	const auto car2 = Vehicle::create_car("Lada Granta", 3500);
	const auto car3 = Vehicle::create_car("Ford Focus", 1500);
	
	EXPECT_EQ(car1.get_engine_capacity(), 5000);
	EXPECT_EQ(car2.get_tonnage(), 0);
	EXPECT_EQ(car3.get_model_name(), "Ford Focus");
}

TEST(VehicleTest, TruckTest) {
	const auto car1 = Vehicle::create_truck("KAMAZ", 5000, 10);
	const auto car2 = Vehicle::create_truck("MAN", 3500, 12);
	const auto car3 = Vehicle::create_truck("GAZ", 1500, 5);

	EXPECT_EQ(car1.get_engine_capacity(), 5000);
	EXPECT_EQ(car2.get_tonnage(), 12);
	EXPECT_EQ(car3.get_model_name(), "GAZ");
}

TEST(VehicleTest, MotoTest) {
	const auto car1 = Vehicle::create_car("Yamaha R6", 600);
	const auto car2 = Vehicle::create_car("KTM 450", 450);
	const auto car3 = Vehicle::create_car("Minsk RX 450", 450);

	EXPECT_EQ(car1.get_engine_capacity(), 600);
	EXPECT_EQ(car2.get_tonnage(), 0);
	EXPECT_EQ(car3.get_model_name(), "Minsk RX 450");
}

TEST(VehicleTest, TaxTest) {
	const auto car = Vehicle::create_car("Audi R8", 5000);
	const auto truck = Vehicle::create_truck("KAMAZ", 5000, 10);
	const auto moto = Vehicle::create_moto("Yamaha R6", 600);

	EXPECT_EQ(car.compute_vehicle_tax(1), 5000);
	EXPECT_EQ(truck.compute_vehicle_tax(1), 30000);
	EXPECT_EQ(moto.compute_vehicle_tax(1), 180);
}
