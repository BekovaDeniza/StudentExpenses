#include "Student.h"

using namespace std;
typedef unsigned int uint;

Student::Student (const string& age, const string& city, const string& institute, 
					const string& district, const string& address, const string& caffe, 
					const string& cinema, uint weekdays, uint weekend) {

	_age = age;
	_city = city;
	_institute = institute;
	_district = district;
	_address = address;
	_cinema = cinema;
	_caffe = caffe;
	_weekdays = weekdays;
	_weekend = weekend;
}

Student::Student() {
	_age = string();
	_city = string();
	_institute = string();
	_district = string();
	_address = string();
	_cinema = string();
	_caffe = string();
	_weekdays = 0;
	_weekend = 0;
}

uint Student::CounterMonthCost (uint weekdays, uint weekend) {
	/* Расходы:
     - по рабочим дням (дорога до института и обратно + обед в институтской столовой)
     - по выходным дням (поход в кино (пешком) + поход  в кафе (пешком))
     - расходы на еду в течении месяца
     - прочие расходы */
	uint entertainment_cost = 0;
	uint transport_cost = 0;
	uint dinner_cost = 0;
	uint food_other_cost = 0;
	uint costs = 0;
	
	DataBaseHandler db;

	entertainment_cost = db.getEntertainmentCost(_city, _address, _caffe, _cinema);
	transport_cost = db.getTransportCost(_city, _district, _institute);
	dinner_cost = db.getDinnerCost(_city, _institute);
	food_other_cost = db.getFoodOtherCost(_city, _age);

	if (transport_cost != 0 && dinner_cost != 0 && food_other_cost != 0 && entertainment_cost != 0) {
		costs = ((transport_cost * 2 + dinner_cost) * weekdays + (entertainment_cost) * weekend) + food_other_cost;
	}
	return costs;
}

Student::~Student() {
	cout << "Have a good month!" << endl;
	cout << "------------------------------" << endl;
}