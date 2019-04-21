#pragma once
#ifndef PRODUCTIONWORKER
#define PRODUCTIONWORKER
#include "Employee.h"
//the class ProductionWorker 
//derives from the base class
//Employee
class ProductionWorker : public Employee
{
private:
	// 1 is day shift, 2 is night
	int shift;
	double hourly_rate;
public:
	class InvalidShift	{};
	class InvalidPayRate {};
	ProductionWorker() :Employee()
	{
		shift = 0;
		hourly_rate = 0;
	}
	ProductionWorker(std::string n, int num, std::string dat, int wShift, double rate) :Employee( n, num, dat)
	{
		if ((wShift != 1) || (wShift != 2))
		{
			throw InvalidShift();
		}
		if (rate < 0)
		{
			throw InvalidPayRate();
		}
		shift = wShift;
		hourly_rate = rate;
	}
	void setRate(int r)
	{
		if (r < 0)
		{
			throw InvalidPayRate();
		}
		hourly_rate = r;
	}
	void setShift(int s)
	{
		if ((s != 1) || (s != 2))
		{
			throw InvalidShift();
		}
		shift = s;
	}
	void getShift()
	{ 
		if (shift == 1)
		{
			std::cout << "Day shift" << std::endl;
		}
		if (shift == 2)
		{
			std::cout << "Night shift" << std::endl;
		}
	}
	int getHourlyRate()
	{
		return hourly_rate;
	}
	

};

#endif 

