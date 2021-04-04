#include "DataBaseHandler.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

int main() {

	string age, city, institute, district, address, caffe, cinema;
	uint weekdays = 0, weekend = 0, costs = 0;
	
	cout << "Enter the student information" << endl;
	cout << "-------------------------" << endl;
	cout << "Enter age: ";
	cin >> age;
	cout << "--------------------------" << endl;
	cout << "Enter city: ";
	cin >> city;
	cout << "-------------------------" << endl;
	cout << "Enter institute: ";
	cin >> institute;
	cout << "-------------------------" << endl;
	cout << "Enter district: ";
	cin >> district;
	cout << "-------------------------" << endl;
	cout << "Enter adress: ";
	cin >> address;
	cout << "-------------------------" << endl;
	cout << "Enter caffe: ";
	cin >> caffe;
	cout << "-------------------------" << endl;
	cout << "Enter cinema: ";
	cin >> cinema;
	cout << "-------------------------" << endl;
	cout << "Enter weekdays in the month: ";
	cin >> weekdays;
	cout << "-------------------------" << endl;
	cout << "Enter number weekend in the month: ";
	cin >> weekend;
	cout << "-------------------------" << endl;

	Student student(age, city, institute, district, address, caffe, cinema, weekdays, weekend);

	costs = student.CounterMonthCost(weekdays, weekend);

	cout << "Student monthly cost of living: " << costs << endl;
	cout << "-------------------------" << endl;

	return 0;
}