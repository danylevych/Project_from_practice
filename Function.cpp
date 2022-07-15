#include "Function.h"
#include "Constant_And_Macross.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <deque>


void AddStudent(std::string path)
{
	GET_CONSOLE
		int n = 1;
	Student st;
	while (n)
	{
		std::cout << "Ведіть ПІБ: "; U_COLOR std::cin >> st.shurname >> st.name >> st.patronimic; A_COLOR
			do
			{
				std::cout << "Введіть номер телефону:"; U_COLOR std::cout << " +38";
				std::cin >> st.number; A_COLOR
			} while (!Check_Number(st.number));
				std::cout << "Сплата за їдальню (1 - так, 0 - ні):\n";
				std::cout << "За вересень: "; U_COLOR std::cin >> st.pay.PaySeptember; A_COLOR
					std::cout << "За жовтень: "; U_COLOR  std::cin >> st.pay.PayOctober; A_COLOR
					std::cout << "За листопад: "; U_COLOR std::cin >> st.pay.PayNovember; A_COLOR
					std::cout << "За грудень: "; U_COLOR std::cin >> st.pay.PayDecember; A_COLOR
					std::cout << "За січень: "; U_COLOR std::cin >> st.pay.PayJanury; A_COLOR
					std::cout << "За лютий: "; U_COLOR std::cin >> st.pay.PayFebruary; A_COLOR
					std::cout << "За березень: "; U_COLOR std::cin >> st.pay.PayMarch; A_COLOR
					std::cout << "За квітень: "; U_COLOR std::cin >> st.pay.PayApril; A_COLOR
					std::cout << "За травень: "; U_COLOR std::cin >> st.pay.PayMay; A_COLOR
					std::cout << "_______________________________________________________________________\n";
				SaveInFile(st, path);
				std::cout << "Бажаєте додати іще одного учня? (0 - ні, 1 - так): "; U_COLOR std::cin >> n; A_COLOR
					system("cls");
	}

}

void SwapPath(std::string& path, std::string number)
{
	path = "PayInfoClass" + number + _choose_format_file;
}
void Choose_File_Format()
{
	int chose;
	std::cout << "Виберіть формат збереження файла:" << std::endl;
	std::cout << "1) .txt \n" << "2) .bin\n" << "3) .svg\n" << "4) Повернутися в головне меню" << std::endl;
	std::cout << "Ваш вибір: "; U_COLOR std::cin >> chose; A_COLOR
		switch (chose)
		{
		case 1:
			_choose_format_file = ".txt";
			Save_Format_File(_choose_format_file);
			S_COLOR std::cout << "Формат успішно змінений!!!" << std::endl; A_COLOR
				break;
		case 2:
			_choose_format_file = ".bin";
			Save_Format_File(_choose_format_file);
			S_COLOR std::cout << "Формат успішно змінений!!!" << std::endl; A_COLOR
				break;
		case 3:
			_choose_format_file = ".svg";
			Save_Format_File(_choose_format_file);
			S_COLOR std::cout << "Формат успішно змінений!!!" << std::endl; A_COLOR
				break;
		case 4:
			return;
			break;
		default:
			_choose_format_file = Read_Format_File();
			E_COLOR std::cout << "Формат НЕ змінений, встановлено попередній формат!!!" << std::endl; A_COLOR
				break;
		}
}
static void Save_Format_File(const std::string& format)
{
	std::ofstream out("Format_File.svg");
	out << format;
	out.close();
}
const std::string Read_Format_File()
{
	std::string format;
	std::ifstream in("Format_File.svg");
	if (!in.is_open())
	{
		return ".txt";
	}
	else
	{
		in >> format;
		in.close();
		return format;
	}
}

void SaveInFile(Student& st, const std::string& path)
{
	std::ofstream out;
	out.open(path, std::fstream::app);
	if (!out.is_open())
	{
		E_COLOR std::cout << "Error opening file" << std::endl; A_COLOR
	}
	else
	{
		out << st.shurname << " " << st.name << " " << st.patronimic << " " << st.number << " ";
		out << st.pay.PaySeptember << " " << st.pay.PayOctober << " " << st.pay.PayNovember << " "
			<< st.pay.PayDecember << " " << st.pay.PayJanury << " " << st.pay.PayFebruary << " "
			<< st.pay.PayMarch << " " << st.pay.PayApril << " " << st.pay.PayMay << "\n";
	}
	out.close();
}

int ReadInfo(std::deque<Data>& data, const std::string path)
{
	Student st;
	std::ifstream in;
	in.open(path);
	if (!in.is_open())
	{
		E_COLOR std::cout << "Error opeening file\n"<<"Схоже токого файлу немає, або теперішній формат є неправильним\n"
			<< "Переконайтеся, що формат файлу відповідає формату збереження інформації з якою працює база" << std::endl; A_COLOR
		return 1;
	}
	else
	{
		DeleteDeque(data);
		while (!in.eof())
		{
			st = {};
			in >> st.shurname >> st.name >> st.patronimic >> st.number >> st.pay.PaySeptember >> st.pay.PayOctober
				>> st.pay.PayNovember >> st.pay.PayDecember >> st.pay.PayJanury >> st.pay.PayFebruary >> st.pay.PayMarch
				>> st.pay.PayApril >> st.pay.PayMay;
			if (st.name != "NoName")
				data.push_back(st);
		}
	}
	in.close();
	return 0;
}
void DeleteDeque(std::deque<Data>& data)
{
	while (!data.empty())
		data.pop_back();
}

void PrintInfo(std::deque<Data>& data)
{
	for (auto& element : data)
	{
		std::cout << "---------------------------------------------------------------------------\n";
		element.Print();
		std::cout << "---------------------------------------------------------------------------\n";
	}
}

void SearchInfo(std::deque<Data>& data, const std::string& name, const std::string& shurname)
{
	bool check = false;
	for (size_t i = 0, n = data.size(); i < n; i++)
	{
		if (data[i].GetStudentInfo().name == name && data[i].GetStudentInfo().shurname == shurname)
		{
			check = true;
			data[i].Print();
			break;
		}
	}
	if (!check)
	{
		E_COLOR std::cout << "Студента НЕ ЗНАЙДЕНО!!!" << std::endl; A_COLOR
	}
}

void SortingAlpavit(std::deque<Data>& data, void (*func)(Data&, Data&))
{
	for (size_t i = 0, n = data.size(); i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			func(data[i], data[j]);
		}
	}
}
void Sort_for_A_to_Z(Data& data1, Data& data2)
{
	if (data1.GetStudentInfo().shurname > data2.GetStudentInfo().shurname)
	{
		std::swap<Data>(data1, data2);
	}
}
void Sort_for_Z_to_A(Data& data1, Data& data2)
{
	if (data1.GetStudentInfo().shurname < data2.GetStudentInfo().shurname)
	{
		std::swap<Data>(data1, data2);
	}
}

void Delete_Oll_Info(const std::string path)
{
	std::ofstream out(path);
	out.close();
}
void DeleteInfo(std::deque<Data>& data, const std::string path, const std::string& name, const std::string& shurname)
{
	bool check_del = false;
	size_t number = -3;
	for (size_t i = 0, n = data.size(); i < n; i++)
	{
		if (data[i].GetStudentInfo().name == name && data[i].GetStudentInfo().shurname == shurname)
		{
			Delete_Oll_Info(path);
			check_del = true;
			number = i;
			break;
		}
	}

	if (check_del)
	{
		Student st;
		for (size_t i = 0, n = data.size(); i < n; i++)
		{
			if (i == number)
				continue;
			st = data[i].GetStudentInfo();
			SaveInFile(st, path);
		}
		DeleteDeque(data);
		ReadInfo(data, path);
		S_COLOR std::cout << "Дані успішно видалено" << std::endl; A_COLOR
	}
	else
	{
		E_COLOR std::cout << "Дані НЕ видалено, учня не знайдено!!!" << std::endl; A_COLOR
	}
}

void FormatInfo(std::deque<Data>& data, const std::string path, const std::string& name, const std::string& shurname)
{
	GET_CONSOLE
		bool check_formar = false;
	size_t number = -3;
	for (size_t i = 0, n = data.size(); i < n; i++)
	{
		if (data[i].GetStudentInfo().name == name && data[i].GetStudentInfo().shurname == shurname)
		{
			Delete_Oll_Info(path);
			check_formar = true;
			number = i;
			break;
		}
	}

	if (check_formar)
	{
		int what;
		Student st;
		for (size_t i = 0, n = data.size(); i < n; i++)
		{
			if (i == number)
			{
				st = data[i].GetStudentInfo();
				std::cout << "Що бажаєте змінити? (1 - ПІБ та номер, 0 - Стан оплати) "; U_COLOR std::cin >> what; A_COLOR
				(what) ? FormatSNP_and_number(st) : FormatPayment(st);
				SaveInFile(st, path);
				continue;
			}
			st = data[i].GetStudentInfo();
			SaveInFile(st, path);
		}
		DeleteDeque(data);
		ReadInfo(data, path);
		S_COLOR std::cout << "Дані успішно форматовано!!!" << std::endl; A_COLOR
	}
	else
	{
		E_COLOR std::cout << "Дані НЕ форматовано, учня не знайдено!!!" << std::endl; A_COLOR
	}
}

static void FormatSNP_and_number(Student& st)
{
	GET_CONSOLE
		int select;
	std::cout << "Відформатувати прізвище? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "Вводьте прізвище: "; U_COLOR std::cin >> st.shurname; A_COLOR
		}

	std::cout << "Відформатувати ім’я? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "Вводьте ім’я: "; U_COLOR std::cin >> st.name; A_COLOR
		}

	std::cout << "Відформатувати по батькові? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "Вводьте по батькові: "; U_COLOR std::cin >> st.patronimic; A_COLOR
		}

	std::cout << "Відформатувати номер? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			do
			{
				std::cout << "Введіть номер телефону:"; U_COLOR std::cout << " +38";
				std::cin >> st.number; A_COLOR
			} while (!Check_Number(st.number));
		}
}

static void FormatPayment(Student& st)
{
	GET_CONSOLE
		int select;
	std::cout << "Відформатувати оплату за вересень? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За вересень: "; U_COLOR std::cin >> st.pay.PaySeptember; A_COLOR
		}

	std::cout << "Відформатувати оплату за жовтень? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За жовтень: "; U_COLOR std::cin >> st.pay.PayOctober; A_COLOR
		}

	std::cout << "Відформатувати оплату за листопад? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За листопад: "; U_COLOR std::cin >> st.pay.PayNovember; A_COLOR
		}

	std::cout << "Відформатувати оплату за грудень? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За грудень: "; U_COLOR std::cin >> st.pay.PayDecember; A_COLOR
		}

	std::cout << "Відформатувати оплату за січень? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За січень: "; U_COLOR std::cin >> st.pay.PayJanury; A_COLOR
		}


	std::cout << "Відформатувати оплату за лютий? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За лютий: "; U_COLOR std::cin >> st.pay.PayFebruary; A_COLOR
		}

	std::cout << "Відформатувати оплату за березень? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За березень: "; U_COLOR std::cin >> st.pay.PayMarch; A_COLOR
		}

	std::cout << "Відформатувати оплату за квітень? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За квітень: "; U_COLOR std::cin >> st.pay.PayApril; A_COLOR
		}

	std::cout << "Відформатувати оплату за травень? (1/0): "; U_COLOR std::cin >> select; A_COLOR
		if (select)
		{
			std::cout << "За травень: "; U_COLOR std::cin >> st.pay.PayMay; A_COLOR
		}
}

static bool Check_Number(const std::string& number)
{
	if (number.size() > 10 || number.size() < 10)
		return false;

	for (int i = 0, x = number.size(); i < x; i++)
		if (!isdigit(number[i]))
			return false;
	return true;
}

void Convert(std::deque<Data>&data, std::string &path, std::string& number)
{
	SwapPath(path, number);
	if (!ReadInfo(data, path))
		return;
	Choose_File_Format();
	SwapPath(path, number);
	system("cls");
	std::thread th(Loading, 10, "Конвертація");
	Delete_Oll_Info(path);

	Student st;
	Delete_Oll_Info(path);
	for (size_t i = 0, n = data.size(); i < n; i++)
	{
		st = data[i].GetStudentInfo();
		SaveInFile(st, path);
	}
	th.join();

}

int Loading(time_t t, std::string Text)
{
	int proces = 100, n = 0;
	for (int i = 0; i <= proces; i++)
	{
		std::cout << "\n\n\n\n\n\n\n\n\t\t\t";
		std::cout << Text << "...[";

		if (i % 10 == 0)
		{
			n = i / 10;
		}

		for (int j = 0; j <= n; j++)
		{
			std::cout << "#";
		}
		for (int x = 0; x < (10 - n); x++)
		{
			std::cout << " ";
		}
		std::cout << "]";
		std::cout << i << "%" << std::endl;
		Sleep(t);
		system("cls");
	}
	return 0;
}