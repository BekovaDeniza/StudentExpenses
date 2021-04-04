#pragma once

#include "Student.h"
#include <string>
#include <fstream>
#include <sstream>


using namespace std;
typedef unsigned int uint;

class DataBaseHandler {
public:

	static unsigned int getDinnerCost(const string& city, const string& institute);
	static unsigned int getFoodOtherCost(const string& city, const string& age);
	static unsigned int getTransportCost(const string& city, const string& district, const string& institute);
	static unsigned int getEntertainmentCost(const string& city, const string& adress, const string& caffe, const string& cinema);
};