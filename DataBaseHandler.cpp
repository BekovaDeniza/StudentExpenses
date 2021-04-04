#include "DataBaseHandler.h"
#include <iostream>

typedef unsigned int uint;


uint DataBaseHandler::getDinnerCost(const string& city, const string& institute) {
	//Функция читает и возвращает из файла расходы на обед в институте
	fstream fs;
	fs.open("Institute.csv");

	if (!fs.is_open()) {
		cout << "FILE OPENING ERROR Institute.csv" << endl;
		exit(0);
	}

	string line, cur_city, cur_institute, dinner_cost;

	while (getline(fs, line)) {
		stringstream lineStream(line);

		getline(lineStream, cur_city, ',');
		getline(lineStream, cur_institute, ',');
		getline(lineStream, dinner_cost, ',');

		if (cur_city == city && cur_institute == institute) {
			fs.close();
			return stoi(dinner_cost);
		}
	}
	fs.close();
	cout << "Data is not in our database! Sorry, try again!" << endl;
	cout << "--------------------------------------------------" << endl;
	exit(0);
}

uint DataBaseHandler::getTransportCost(const string& city, const string& district, const string& institute) {
	//Функция читает и возвращает из файла "Transport.csv" расходы на транспорт до университета
	fstream fs;
	fs.open("Transport.csv");
	if (!fs.is_open()) {
		cout << "FILE OPENING ERROR Transport.csv" << endl;
		exit(0);
	}

	string line, transport_cost;

	while (getline(fs, line)) {
		string cur_city, cur_district, cur_institute;
		stringstream lineStream(line);

		getline(lineStream, cur_city, ',');
		getline(lineStream, cur_district, ',');
		getline(lineStream, cur_institute, ',');
		getline(lineStream, transport_cost, ',');

		if (cur_city == city && cur_institute == institute && cur_district == district) {
			fs.close();
			return stoi(transport_cost);
		}
	}
	fs.close();
	cout << "Data is not in our database! Sorry, try again!" << endl;
	cout << "--------------------------------------------------" << endl;
	exit(0);
}

uint DataBaseHandler::getFoodOtherCost(const string& city, const string& age) {
	//Функция читает и возвращает из файла "Costs.csv" расходы на продукты и остальные расходы за месяц
	fstream fs;
	fs.open("Costs.csv");

	if (!fs.is_open()) {
		cout << "FILE OPENING ERROR Costs.csv" << endl;
		exit(0);
	}

	string line;
	string food_cost, other_cost;
	
	while (getline(fs, line)) {
		string cur_city, cur_age;
		stringstream lineStream(line);

		getline(lineStream, cur_city, ',');
		getline(lineStream, cur_age, ',');
		getline(lineStream, food_cost, ',');
		getline(lineStream, other_cost, ',');

		if (cur_city == city && cur_age == age) {
			fs.close();
			return stoi(food_cost) + stoi(other_cost);
		}
	}
	fs.close();
	cout << "Data is not in our database! Sorry, try again!" << endl;
	cout << "--------------------------------------------------" << endl;
	exit(0);
}

uint DataBaseHandler::getEntertainmentCost(const string& city, const string& adress, 
											const string& caffe, const string& cinema) {
	//Функция читает и возвращает из файла "Caffe-and-cinema.csv" расходы на развлечения
	fstream fs;
	fs.open("Caffe-and-cinema.csv");

	if (!fs.is_open()) {
		cout << "FILE OPENING ERROR Caffe-and-cinema.csv" << endl;
		exit(0);
	}

	string line, cur_city, cur_address, cur_caffe, cur_cinema;
	string caffe_cost, cinema_cost;
	while (getline(fs, line)) {

		stringstream lineStream(line);

		getline(lineStream, cur_city, ',');
		getline(lineStream, cur_address, ',');
		getline(lineStream, cur_caffe, ',');
		getline(lineStream, caffe_cost, ',');
		getline(lineStream, cur_cinema, ',');
		getline(lineStream, cinema_cost, ',');

		if (cur_city == city && cur_address == adress && cur_caffe == caffe && cur_cinema == cinema) {
			fs.close();
			return stoi(caffe_cost) + stoi(cinema_cost);
		}
	}
	fs.close();
	cout << "Data is not in our database! Sorry, try again!" << endl;
	cout << "--------------------------------------------------" << endl;
	exit(0);
}