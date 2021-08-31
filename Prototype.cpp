#include <iostream>
#include <map>
#include <string>
using namespace std;
using std::cout;

// Abstract Prototyoe
class BMW
{
protected:
	const unsigned int max_speed;
	const unsigned int Doors;
public:
	BMW(const unsigned int max_speed, const unsigned int Doors):max_speed(max_speed), Doors(Doors){}
	virtual ~BMW(){}
	void info()const
	{
		cout << this << ":" << typeid(*this).name() << "\t";
		cout << "Max speed: " << max_speed << ", \tDoors: " << Doors << endl;
	}
	virtual BMW* clone()const = 0;
};

// Concrete prototype
class BMW_3 : public BMW
{
public:
	BMW_3() :BMW(220, 3){}
	~BMW_3(){}
	BMW* clone()const
	{
		return new BMW_3(*this);
	}
};

class BMW_5 : public BMW
{
public:
	BMW_5() :BMW(250, 4) {}
	~BMW_5() {}
	BMW* clone()const
	{
		return new BMW_5(*this);
	}
};

class BMW_7 : public BMW
{
public:
	BMW_7() :BMW(280, 5) {}
	~BMW_7() {}
	BMW* clone()const
	{
		return new BMW_7(*this);
	}
};


class Wheel
{
protected:
	const string SeasonWheel;
public:
	Wheel(const string SeasonWheel):SeasonWheel(SeasonWheel){}
	virtual ~Wheel(){}

	void info()const
	{
		cout << this << ":" << typeid(*this).name() << "\t";
		cout << "Season: " << SeasonWheel << endl;
	}
	virtual Wheel* clone()const = 0;
};

class WheelSummer : public Wheel
{
public:
	WheelSummer() :Wheel("Summer") {}
	~WheelSummer() {}
	Wheel* clone()const
	{
		return new WheelSummer(*this);
	}
};

class WheelAutumn : public Wheel
{
public:
	WheelAutumn() :Wheel("Autumn") {}
	~WheelAutumn() {}
	Wheel* clone()const
	{
		return new WheelAutumn(*this);
	}
};

class WheelWinter : public Wheel
{
public:
	WheelWinter() :Wheel("Winter") {}
	~WheelWinter() {}
	Wheel* clone()const
	{
		return new WheelWinter(*this);
	}
};

class WheelSpring : public Wheel
{
public:
	WheelSpring() :Wheel("Spring") {}
	~WheelSpring() {}
	Wheel* clone()const
	{
		return new WheelSpring(*this);
	}
};

class WheelFactory
{
	static map<int, Wheel*> prototype;
public:
	static Wheel* create_model(int model)
	{
		return prototype[model]->clone();
	}
};

map<int, Wheel*> WheelFactory::prototype =
{
	pair<int, Wheel*>(1, new WheelSummer),
	pair<int, Wheel*>(2, new WheelAutumn),
	pair<int, Wheel*>(3, new WheelWinter),
	pair<int, Wheel*>(4, new WheelSpring),
};

class SUV
{
protected:
	const unsigned int max_speed;
	const unsigned int Doors;
	const unsigned int Wheels;
public:
	SUV(const unsigned int max_speed, const unsigned int Doors, const unsigned int Wheels) :max_speed(max_speed), Doors(Doors), Wheels(Wheels){}
	virtual ~SUV() {}

	void info()const
	{
		cout << this << ":" << typeid(*this).name() << "\t";
		cout << "Max speed: " << max_speed << ", \tDoors: " << Doors << ", \tWheels: " << Wheels << endl;
	}
	virtual SUV* clone()const = 0;
};


class SUV_1 : public SUV
{
public:
	SUV_1() :SUV(190, 2, 4) {}
	~SUV_1() {}
	SUV* clone()const
	{
		return new SUV_1(*this);
	}
};

class SUV_2 : public SUV
{
public:
	SUV_2() :SUV(200, 4, 6) {}
	~SUV_2() {}
	SUV* clone()const
	{
		return new SUV_2(*this);
	}
};

class SUV_3 : public SUV
{
public:
	SUV_3() :SUV(210, 4, 8) {}
	~SUV_3() {}
	SUV* clone()const
	{
		return new SUV_3(*this);
	}
};

class TruckFactory
{
	static map<int, SUV*> prototype;
public:
	static SUV* create_model(int model)
	{
		return prototype[model]->clone();
	}
};

map<int, SUV*> TruckFactory::prototype =
{
	pair<int, SUV*>(1, new SUV_1),
	pair<int, SUV*>(2, new SUV_2),
	pair<int, SUV*>(3, new SUV_3),
};


class BMWFactory
{
	static map<int, BMW*> prototype;
public:
	static BMW* create_model(int model)
	{
		return prototype[model]->clone();
	}
};

map<int, BMW*> BMWFactory::prototype =
{
	pair<int, BMW*>(3, new BMW_3),
	pair<int, BMW*>(5, new BMW_5),
	pair<int, BMW*>(7, new BMW_7),
};

//#define BMWs
//#define Wheels
#define Trucks

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

#ifdef BMWs
	BMW* bmw = BMWFactory::create_model(3); bmw->info();
	BMW* bmw3 = BMWFactory::create_model(3); bmw3->info();
	BMW_3 bmw_3;
	bmw_3.info();
#endif // BMWs

#ifdef Wheels

	Wheel* wheel = WheelFactory::create_model(1); wheel->info();
	Wheel* wheel2 = WheelFactory::create_model(2); wheel2->info();
	Wheel* wheel3 = WheelFactory::create_model(3); wheel3->info();
	Wheel* wheel4 = WheelFactory::create_model(4); wheel4->info();
#endif // Wheels

	SUV* suv = TruckFactory::create_model(1); suv->info();
	SUV* suv2 = TruckFactory::create_model(2); suv2->info();
	SUV* suv3 = TruckFactory::create_model(3); suv3->info();
}