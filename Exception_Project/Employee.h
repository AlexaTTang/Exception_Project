#pragma once
#ifndef EMPLOYEE
#define EMPLOYEE
#include<iostream>
class Employee
{
private:
	std::string employee_name;
	int employee_num;
	std::string hire_date;
public:
	//exception class
	class InvalidEmployeeNumber{};

	//base class constructor
	Employee()
	{
		employee_name = "";
		employee_num = 0;
		hire_date = "";
	}
	Employee(std::string name, int num, std::string date)
	{
		employee_name = name;
		employee_num = num;
		hire_date = date;
	}
	
	//Mutator functions
	void setEmployeeName(std::string n)
	{
		employee_name = n;
	}
	void  setEmployeeNum(int eN)
	{
		if (0 > employee_num || employee_num > 9999)
		{
			throw InvalidEmployeeNumber();
		}
		employee_num = eN;
	}
	void setHireDate(std::string hD)
	{
		hire_date = hD;
	}
	//Accessor functions
	std::string getEmployeeName()
	{
		return employee_name;
	}
	int getEmployeeNum()
	{
		return  employee_num;
	}
	std::string getHireDate()
	{
		return hire_date;
	}
};

#endif
