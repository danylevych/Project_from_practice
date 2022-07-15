#include <deque>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Function.h"
#include "Data.h"
#include "Constant_And_Macross.h"


void MainMenue()
{
	GET_CONSOLE
	std::cout << R"(			
					МЕНЮ: 
		1) Додати учня
		2) Вивести інформацію про певний клас
		3) Пошук учня
		4) Сортування інформації
		5) Форматування інформації
		6) Видалення учня
		7) Очистити базу даних
		8) Вибрати формат збереження інформації
		9) Ковертація файлу
		10) Вивести формат збереження з яким зараз працює програма
		0) Вихід
		Ваш вибір: )";
	U_COLOR std::cin >> _stateMenu; A_COLOR
}

int main()
{
	GET_CONSOLE
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Loading(5, "Завантаження");

	bool check = true;
	std::string name, shurname;
	std::string path, number;
	std::deque<Data> data;
	_choose_format_file = Read_Format_File();

	while (_stateMenu)
	{
		system("cls");
		MainMenue();
		switch (_stateMenu)
		{
		case 1:
			system("cls");
			std::cout << "Введіть клас до якого хочете добавити учнів: "; U_COLOR std::cin >> number; A_COLOR
			SwapPath(path, number);
			system("cls");
			AddStudent(path);
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "Введіть клас дані якого бажаєте побачити: "; U_COLOR std::cin >> number; A_COLOR
			SwapPath(path, number);
			system("cls");
			if (!ReadInfo(data, path))
				PrintInfo(data);
			system("pause");
			break;

		case 3:
			system("cls");
			std::cout << "Введіть клас, у якому навчається учень: "; U_COLOR std::cin >> number; A_COLOR
			std::cout << "Введіть Ім’я учня: "; U_COLOR std::cin >> name; A_COLOR
			std::cout << "Введіть Прізвище учня: "; U_COLOR std::cin >> shurname; A_COLOR
			SwapPath(path, number);
			system("cls");
			if (!ReadInfo(data, path))
			{
				SearchInfo(data, name, shurname);
				system("pause");
			}
			break;

		case 4:
			system("cls");
			std::cout << "Введіть клас, у якому потрібно відсортувати інформацію: "; U_COLOR std::cin >> number; A_COLOR
			SwapPath(path, number);
			system("cls");
			if (!ReadInfo(data, path))
			{
				std::cout << "1) Сортувати від А до Я" << std::endl;
				std::cout << "2) Сортувати від Я до А" << std::endl;
				std::cout << "Ваш вибір: "; U_COLOR std::cin >> _stateMenu; A_COLOR
					if (_stateMenu == 1)
						SortingAlpavit(data, Sort_for_A_to_Z); check = false;
				if (_stateMenu == 2)
					SortingAlpavit(data, Sort_for_Z_to_A); check = false;
				system("cls");
				if (check)
				{
					E_COLOR std::cout << "Дані НЕ відсортовані!!!" << std::endl; A_COLOR
				}
				else
				{
					S_COLOR std::cout << "Дані успішно відсортовані!!!" << std::endl; A_COLOR
				}
				std::cout << "Зберегти назад у файл? (1 - так, 0 - ні): "; U_COLOR std::cin >> check; A_COLOR
					if (check)
					{
						Student st;
						Delete_Oll_Info(path);
						for (size_t i = 0, n = data.size(); i < n; i++)
						{
							st = data[i].GetStudentInfo();
							SaveInFile(st, path);
						}
					}
				system("pause");
			}
			break;

		case 5:
			system("cls");
			std::cout << "Введіть клас, у якому потрібно відформатувати інформацію: "; U_COLOR std::cin >> number; A_COLOR
			std::cout << "Введіть Ім’я учня: "; U_COLOR std::cin >> name; A_COLOR
			std::cout << "Введіть Прізвище учня: "; U_COLOR std::cin >> shurname; A_COLOR
			SwapPath(path, number);
			if (!ReadInfo(data, path))
			{
				system("cls");
				FormatInfo(data, path, name, shurname);
				system("pause");
			}
			break;

		case 6:
			system("cls");
			std::cout << "Введіть клас, у якому потрібно видалити інформацію: "; U_COLOR std::cin >> number; A_COLOR
			std::cout << "Введіть Ім’я учня: "; U_COLOR std::cin >> name; A_COLOR
			std::cout << "Введіть Прізвище учня: "; U_COLOR std::cin >> shurname; A_COLOR
			SwapPath(path, number);
			system("cls");
			if(!ReadInfo(data, path))
				DeleteInfo(data, path, name, shurname);
			system("pause");
			break;

		case 7:
			system("cls");
			std::cout << "Ви впевнені, Що бажаєте очисти дані? (1 - так, 0 - ні): "; U_COLOR std::cin >> check; A_COLOR
			if (check)
			{
				std::cout << "Введіть клас, інформацію про який потрібно видалити: "; U_COLOR std::cin >> number; A_COLOR
				SwapPath(path, number);
				system("cls");
				Delete_Oll_Info(path);
				system("pause");
			}
			break;

		case 8:
			system("cls");
			Choose_File_Format();
			system("pause");
			system("cls");
			break;

		case 9:
			system("cls");
			std::cout << "Введіть клас, файл якого потрібно конвертувати: "; U_COLOR std::cin >> number; A_COLOR
			Convert(data, path, number);
			break;

		case 10:
			system("cls");
			std::cout << "Формат файлу з яким зараз працює програма - " << _choose_format_file << std::endl;
			system("pause");
			break;
		}
	}
}