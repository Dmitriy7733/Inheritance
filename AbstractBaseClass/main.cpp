#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
	const int MAX_SPEED;
public:
	Vehicle(int speed = 0, int max_speed = 250) :speed(speed),MAX_SPEED(max_speed) {}
	virtual void move() = 0;
};

class GroundVehicle :public Vehicle{};

class Buldozer :public GroundVehicle
{
public:
	void move()
	{
		cout << "Бульдозер ездит на гусеницах" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина ездит на колесах" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//GroundVehicle gv;
	Car car;
	car.move();
	Buldozer amd;
	amd.move();
}