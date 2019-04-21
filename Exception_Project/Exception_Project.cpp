// Exception_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Employee.h"
#include "ProductionWorker.h"
#include <iostream>
#include <iomanip>
#include <string>
void displayInfo(ProductionWorker &w)
{
	std::cout << "Name: " << w.getEmployeeName() << "\n" << std::endl;
	std::cout << "ID Number: " << w.getEmployeeNum() << "\n" << std::endl;
	std::cout << "Hire date: " << w.getHireDate() << "\n" << std::endl;
	//shift
	/*std::cout << "shift: " << w.getShift() << "\n" << std::endl;*/
	std::cout << "Hourly Rate: " << w.getHourlyRate() << "\n" << std::endl;
}
int main()
{
	ProductionWorker worker1("bob", 123456, "02/31/2018", 2, 26);
	displayInfo(worker1);

	std::cout << "Shift exception" << std::endl;
	try 
	{
	ProductionWorker worker2("bob", 0,"02/31/2018", 0, 13);
	displayInfo(worker2);
	}
	catch (ProductionWorker::InvalidShift)
	{
		std::cout << "invalid shift" << std::endl;
	}

	std::cout << "Rate exception" << std::endl;
	try
	{
		ProductionWorker worker3("bob", 2, "02/31/2018", 1, -13);
		displayInfo(worker3);
	}
	catch (ProductionWorker::InvalidPayRate)
	{
		std::cout << "invald pay rate"<< std::endl;
	}

	std::cout << "Employee Number exception" << std::endl;
	try
	{
		ProductionWorker worker3("bob", 2, "02/31/2018", 0, 13);
		displayInfo(worker3);
	}
	catch (Employee::InvalidEmployeeNumber)
	{
		std::cout << "invalid employee number" << std::endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
