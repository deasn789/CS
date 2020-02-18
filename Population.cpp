// Population.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class Population
{
public:
	void print();
	Population();
	Population(int pop, int births, int deaths, std::string area);
	int getPop();
	int getBirth();
	int getDeath();
	std::string getArea();

	void setPop(int pop);
	void setBirths(int births);
	void setDeaths(int deaths);
	void setArea(std::string area);

	float birthRate();
	float deathRate();

private:
	int population_;
	int annualBirths_;
	int annualDeaths_;
	std::string geographicalArea_;
};

Population* popDiArray(int size);
void printPopArray(Population* ary, int sz);

int main()
{
	std::string area01, area02;
	int births01, births02;
	int deaths01, deaths02;
	int p01, p02;

	Population kuzkoz(5, 1, 0, "Kuzkoz");
	Population pop01;

	std::cout << "Enter name of area one" << std:: endl;
	std::cin >> area01;
	pop01.setArea(area01);

	std::cout << "The default values of " << pop01.getArea() << " are the following:" << std::endl;
	pop01.print();

	std::cout << "Let's change them now..." << std::endl << "Enter the population number" << std::endl;
	std::cin >> p01;
	if (p01 < 2) { p01 = 2;}
	pop01.setPop(p01);

	std::cout << "Enter the Annual Births" << std::endl;
	std::cin >> births01;
	if (births01 < 0) { births01 = 0;}
	pop01.setBirths(births01);

	std::cout << "Enter the Annual Deaths" << std::endl;
	std::cin >> deaths01;
	if (deaths01 < 0) { deaths01 = 0;}
	pop01.setDeaths(deaths01);

	std::cout << "Now lets enter the values for area two" << std::endl;
	std::cout << "Enter name of area two" << std::endl;
	std::cin >> area02;

	std::cout << "Enter the population number of " << area02 << std::endl;
	std::cin >> p02;
	if (p02 < 2) { p02 = 2; }

	std::cout << "Enter the Annual Births for " << area02 << std::endl;
	std::cin >> births02;
	if (births02 < 0) { births02 = 0; }

	std::cout << "Enter the Annual Deaths for " << area02 << std::endl;
	std::cin >> deaths02;
	if (deaths02 < 0) { deaths02 = 0; }

	Population pop02(p02, births02, deaths02, area02);

	std::cout << std::endl << "Below is the information on " << pop01.getArea() << std::endl << std::endl;
	pop01.print();

	std::cout << std::endl << "Below is the information on " << pop02.getArea() << std::endl << std::endl;
	pop02.print();

	std::cout << std::endl << "Below is the information on Kuzkoz" << std::endl << std::endl;
	kuzkoz.print();

	int size;
	std::cout << "How many more areas would you like to enter?" << std::endl;
	std::cin >> size;
	if (size > 0)
	{
		Population* populationArray = popDiArray(size);
		printPopArray(populationArray, size);
		delete[] populationArray;
	}
	else
	{
		std::cout << "Ok, you have selected not to enter anymore areas." << std::endl << "Goodbye" << std::endl;
	}

	

}

void printPopArray(Population* ary, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		std::cout << "Printing out area #" << (i+1) << std::endl << std::endl;
		(ary + i)->print();
		std::cout << std::endl;
	}
}
Population* popDiArray(int size)
{
	std::string area;
	int input;
	Population* array = new Population[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter name of area " << (i+1) << std::endl;
		std::cin >> area;
		(array+i)->setArea(area);
		
		std::cout << "Enter the population number for area " << (i + 1) << std::endl;
		std::cin >> input;
		(array+i)->setPop(input);
		if ((array+i)->getPop() < 2) { (array+i)->setPop(2); }

		std::cout << "Enter the Annual Births for area " << (i + 1) << std::endl;
		std::cin >> input;
		(array + i)->setBirths(input);
		if ((array+i)->getBirth() < 0) { (array+i)->setBirths(0); }
		
		std::cout << "Enter the Annual Deaths for area " << (i + 1) << std::endl;
		std::cin >> input;
		(array + i)->setDeaths(input);
		if ((array+i)->getDeath() < 0) { (array+i)->setDeaths(0); }
		
	}
	return array;
}
void Population::print()
{
	std::cout << "Name of Area: " << getArea() << std::endl;
	std::cout << "Population: " << getPop() << std::endl;
	std::cout << "Annual Births: " << getBirth() << std::endl;
	std::cout << "Annual Deaths: " << getDeath() << std::endl;
	std::cout << "Birth Rate: " << birthRate() << std::endl;
	std::cout << "Death Rate: " << deathRate() << std::endl;
}
Population::Population()
{
	population_ = 2;
	annualBirths_ = 0;
	annualDeaths_ = 0;
	geographicalArea_ = "";
}
Population::Population(int pop, int births, int deaths, std::string area): population_(pop), annualBirths_(births),
annualDeaths_(deaths), geographicalArea_(area)
{
}
int Population::getPop()
{
	return population_;
}
int Population::getBirth()
{
	return annualBirths_;
}
int Population::getDeath()
{
	return annualDeaths_;
}
std::string Population::getArea()
{
	return geographicalArea_;
}
void Population::setPop(int pop)
{
	population_ = pop;
}
void Population::setBirths(int births)
{
	 annualBirths_ = births;
}
void Population::setDeaths(int deaths)
{
	 annualDeaths_ = deaths;
}
void Population::setArea(std::string area)
{
	geographicalArea_ = area;
}
float Population::birthRate()
{
	float myFloat = 0.0f;
	myFloat = (float)annualBirths_ / (float)population_;
	return myFloat;
}
float Population::deathRate()
{
	float myFloat = 0.0f;
	myFloat = (float)annualDeaths_ / (float)population_;
	return myFloat;
}