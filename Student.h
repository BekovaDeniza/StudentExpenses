#pragma once
#include <iostream>
#include <string>
#include "DataBaseHandler.h"

using namespace std;
typedef unsigned int uint;

class Student {
private:
	string _city;
	string _institute;
	string _district;
	string _address;
	string _caffe;
	string _cinema;
	string _age;
	uint _weekdays;
	uint _weekend;

public:
	Student (const string& age, const string& city, const string& institute,
			const string& district, const string& address, const string& caffe, 
			const string& cinema, uint weekdays, uint weekend);
	Student();
	~Student();

	uint CounterMonthCost (uint weekdays, uint weekend);
};