#pragma once
#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "Data.h"
#include <iostream>
#include <string>
#include <deque>

void AddStudent(const std::string path);						// Add a new Student
void SwapPath(std::string &path, std::string number);			// Change path
static bool ChechClass(const std::string& number);
void Choose_File_Format();
static void Save_Format_File(const std::string& format);
const std::string Read_Format_File();
void SaveInFile(Student& st, const std::string& path);			// Save information about class
int ReadInfo(std::deque<Data>& data, const std::string path);	// Read information from fail
void DeleteDeque(std::deque<Data>& data);						// Delete information in deque 
void PrintInfo(std::deque<Data>& data);							// Print information about class
void SearchInfo(std::deque<Data>& data, const std::string& name, const std::string& shurname); // Search information about Student
void SortingAlpavit(std::deque<Data>& data, void (*func)(Data&, Data&)); // Sort information in alphabetical order
void Sort_for_A_to_Z(Data& data1, Data& data2);
void Sort_for_Z_to_A(Data& data1, Data& data2);
void Delete_Oll_Info(const std::string path);					// Delete information in file
// Delete information about Student
void DeleteInfo(std::deque<Data>& data, const std::string path, const std::string& name, const std::string& shurname);
// Formating information about Student
void FormatInfo(std::deque<Data>& data, const std::string path, const std::string& name, const std::string& shurname);
static void FormatSNP_and_number(Student& st);
static void FormatPayment(Student& st);
static bool Check_Number(const std::string& number);			// Check the correct spelling of the number
void Convert(std::deque<Data>& data, std::string& path, std::string& number);
int Loading(time_t t, std::string Text);
#endif // !_FUNCTION_H_