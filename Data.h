#pragma once
//#ifndef _DATA_H_
//#define _DATA_H_

#include <iostream>
#include <fstream>
#include <string>
#include <deque>


class Data;
struct Payment
{
	bool PaySeptember = 0;
	bool PayOctober = 0;
	bool PayNovember = 0;
	bool PayDecember = 0;
	bool PayJanury = 0;
	bool PayFebruary = 0;
	bool PayMarch = 0;
	bool PayApril = 0;
	bool PayMay = 0;
};

struct Student
{
	std::string name = "NoName";
	std::string shurname;
	std::string patronimic;
	std::string number;
	Payment pay;
};

class Data
{
public:
	Data();
	Data(Student st);

	void Print();
	std::string CheckPay(const bool &pay){ return (pay) ? "CÏËÀÒÈÂ" : "ÍÅ ÑÏËÀÒÈÂ"; }
	void Initiality(Student st);
	Student GetStudentInfo() const { return st; }
private:
	Student st;
};

//#endif // !_DATA_H_