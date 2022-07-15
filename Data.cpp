#include "Data.h"
#include "Constant_And_Macross.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>

//HANDLE hConsole;
Data::Data()
{
	st.name = "NoName";
	st.shurname = "";
	st.patronimic = "";
	st.name = "";
}
Data::Data(Student st)
{
	Data::Initiality(st);
}

void Data::Print()
{
	GET_CONSOLE
	std::cout << "Прізвище Ім’я Побатькові: "; U_COLOR  std::cout << st.shurname << " "
		<< st.name << " " << st.patronimic << std::endl; A_COLOR
	std::cout << "Номер телефону: "; U_COLOR std::cout << "+38" << st.number; A_COLOR
	std::cout << "\nСплата за їдальню:\n";
	std::cout << "За вересень: "; U_COLOR std::cout << CheckPay(st.pay.PaySeptember) << std::endl; A_COLOR
	std::cout << "За жовтень: "; U_COLOR std::cout << CheckPay(st.pay.PayOctober) << std::endl; A_COLOR
	std::cout << "За листопад: "; U_COLOR std::cout << CheckPay(st.pay.PayNovember) << std::endl; A_COLOR
	std::cout << "За грудень: "; U_COLOR std::cout << CheckPay(st.pay.PayDecember) << std::endl; A_COLOR
	std::cout << "За січень: "; U_COLOR std::cout << CheckPay(st.pay.PayJanury) << std::endl; A_COLOR
	std::cout << "За лютий: "; U_COLOR std::cout << CheckPay(st.pay.PayFebruary) << std::endl; A_COLOR
	std::cout << "За березень: "; U_COLOR std::cout << CheckPay(st.pay.PayMarch) << std::endl; A_COLOR
	std::cout << "За квітень: "; U_COLOR std::cout << CheckPay(st.pay.PayApril) << std::endl; A_COLOR
	std::cout << "За травень: "; U_COLOR std::cout << CheckPay(st.pay.PayMay) << std::endl; A_COLOR
}

void Data::Initiality(Student st)
{
	this->st.name = st.name;
	this->st.shurname = st.shurname;
	this->st.patronimic = st.patronimic;
	this->st.number = st.number;

	this->st.pay.PaySeptember = st.pay.PaySeptember;
	this->st.pay.PayOctober = st.pay.PayOctober;
	this->st.pay.PayNovember = st.pay.PayNovember;
	this->st.pay.PayDecember = st.pay.PayDecember;
	this->st.pay.PayJanury = st.pay.PayJanury;
	this->st.pay.PayFebruary = st.pay.PayFebruary;
	this->st.pay.PayMarch = st.pay.PayMarch;
	this->st.pay.PayApril = st.pay.PayApril;
	this->st.pay.PayMay = st.pay.PayMay;
}