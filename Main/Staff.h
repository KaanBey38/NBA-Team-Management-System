#ifndef _Staff_
#define _Staff_
#include <iostream>
#include <string>
//#include "player.h"
using namespace std;
int randomNumber2(int percentage);///creates a random number between 0 and percentage
string name_surnameF();/// picks a  random name and surname from our litte name and surmane pool
string nationaltyF();///picks a random nation
int ageF();/// creates a random age between 18 and 37
double wageF();//creates a random wage
string roleF();//creates a random role
string trainingDaysF();
//int trainingNumberF();
string fitnessDaysF();
//int fitnessNumberF();


//start of the header part
class Staff
{
	
protected:
	double wage;
public:
	string name;
	int age;
	string nationality;
	string role;
	//no args
	Staff();
	//5 args
	Staff(double wage, string name, int age, string nationality, string role);
	//copy cons
	Staff(const Staff& obj);
	//destrcutor
	~Staff();
	//getters and setters
	double getWage(void);
	string getName(void);
	int getAge(void);
	string getNationality(void);
	string getRole(void);
	void setWage(int wage);
	void setName(string name);
	void setAge(int age);
	void setNationality(string nationality);
	void setRole(string role);
	//friend int trainingNumberF();
	friend ostream& operator<<(ostream& os, Staff& source);/////overloaded output operator
	
	Staff& operator=(const Staff& source);//overloaded copy operator
};

class CoachStaff :public Staff
{
protected:
	string trainingDays;
	int trainingNumber;
public:
	//no args
	CoachStaff();
	//2 args
	CoachStaff(string trainingDays, int trainingNumber);
	//getter and setters
	string getTrainingDays(void);
	int getTrainingNumbers(void);
	void setTrainingDays(string trainingDays);
	void setTrainingNumber(int trainingNumber);
     int trainingNumberF();
	 friend ostream& operator<<(ostream& os, CoachStaff& source);/////overloaded output operator

	 CoachStaff& operator=(const CoachStaff& source);

	 
	 CoachStaff& operator=(const Staff& source);//this is for convert staff object to coachstaff
};
class MedicalStaff :public Staff
{
public:
	MedicalStaff();
	friend ostream& operator<<(ostream& os, MedicalStaff& source);/////overloaded output operator
	MedicalStaff& operator=(const MedicalStaff& source);
};
class FitnessStaff :public Staff
{
protected:
	string fitnessDays;
	int fitnessNumber;
	
public:
	//no args
	FitnessStaff();
	//2 args
	FitnessStaff(string fitnessDays, int fitnessNumber);
	string getFitnessDays(void);
	int getFitnessNumbers(void);
	void setFtinessDays(string fitnessDays);
	void setFitnessNumber(int fitnessNumber);
	 int fitnessNumberF();
	 friend ostream& operator<<(ostream& os, FitnessStaff& source);/////overloaded output operator
	 FitnessStaff& operator=(const FitnessStaff& source);
};

//end of header part

Staff::Staff()
{
	name = name_surnameF();
	age = ageF();
	nationality = nationaltyF();
	wage = wageF();
	//role = &roleF()[0];
	role = roleF();
}



//5 args
Staff::Staff(double wage, string name, int age, string nationality, string role) :wage{ wage }, name{ name }, age{ age }, nationality{ nationality }, role{ role }
{ };


//copy cons
Staff::Staff(const Staff& obj)
{
	this->wage = obj.wage;
	this->name = obj.name;
	this->age = obj.age;
	this->nationality = nationality;

	this->role = role;
}
//destrcutor
Staff::~Staff()
{
	//delete[] role;
}
//getters and setters
double Staff::getWage(void) { return wage; }

string Staff::getName(void) { return name; }

int Staff::getAge(void) { return age; }

string Staff::getNationality(void) { return nationality; }

string Staff::getRole(void) { return role; }

void Staff::setWage(int wage) { this->wage = wage; }

void Staff::setName(string name) { this->name = name; }

void Staff::setAge(int age) { this->age = age; }

void Staff::setNationality(string nationality) { this->nationality = nationality; }

void Staff::setRole(string role) { this->role = role; }

ostream& operator<<(ostream& os, Staff& source)
{
	os << "Name Surname: " << source.name << "\t" << " Age:" << source.age << "\t Nation:" << source.nationality << "\t Role:" << source.role << "\t Wage" << source.wage << " M dollar" << "\t";
	return os;
}

Staff& Staff:: operator=(const Staff& source)
{
	name = source.name;
	age = source.age;
	nationality = source.nationality;
	wage = source.wage;
	//role = &roleF()[0];
	role = source.role;
	return *this;
}

CoachStaff::CoachStaff() {
	role = "Coach";
	trainingDays = trainingDaysF();
	trainingNumber = trainingNumberF();
};
//2 args
CoachStaff::CoachStaff(string trainingDays, int trainingNumber)
{
	this->trainingDays = trainingDays;
	this->trainingNumber = trainingNumber;
}
//getter and setters
string CoachStaff::getTrainingDays(void) { return trainingDays; }

int CoachStaff::getTrainingNumbers(void) { return trainingNumber; }

void CoachStaff::setTrainingDays(string trainingDays) { this->trainingDays = trainingDays; }

void CoachStaff::setTrainingNumber(int trainingNumber) { this->trainingNumber = trainingNumber; }

ostream& operator<<(ostream& os, CoachStaff& source)
{
	os << "Name Surname: " << source.name << "\t" << " Age:" << source.age << "\t Nation:" << source.nationality << "\t Role:" << source.role << "\t Wage:" << source.getWage() << " M Dollar" << "\t";
	os << "Training days:" << source.trainingDays << "\t" << "Training numbers:" << source.trainingNumber << "\t" << endl;
	return os;
}

CoachStaff& CoachStaff::operator=(const CoachStaff& source)
{
	name = source.name;
	age = source.age;
	nationality = source.nationality;
	wage = source.wage;
	//role = &roleF()[0];
	role = source.role;
	trainingDays = source.trainingDays;
	trainingNumber = source.trainingNumber;
	return *this;

}

CoachStaff& CoachStaff::operator=(const Staff& source)
{
	name = source.name;
	age = source.age;
	nationality = source.nationality;
	wage = getWage();
	//role = &roleF()[0];
	role = source.role;
	return *this;

}



FitnessStaff::FitnessStaff()
{
	role = "Fitness trainer";
	fitnessDays = fitnessDaysF();
	fitnessNumber = fitnessNumberF();
};
//2 args
FitnessStaff::FitnessStaff(string fitnessDays, int fitnessNumber) {
	this->fitnessDays = fitnessDays;
	this->fitnessNumber = fitnessNumber;
}
string FitnessStaff::getFitnessDays(void) { return fitnessDays; }

int FitnessStaff::getFitnessNumbers(void) { return fitnessNumber; }

void FitnessStaff::setFtinessDays(string fitnessDays) { this->fitnessDays = fitnessDays; }

void FitnessStaff::setFitnessNumber(int fitnessNumber) { this->fitnessNumber = fitnessNumber; }

ostream& operator<<(ostream& os, FitnessStaff& source)
{
	os << "Name Surname: " << source.name << "\t" << " Age:" << source.age << "\t Nation:" << source.nationality << "\t Role:" << source.role << "\t Wage:" << source.wage << "M Dollar" << "\t";
	os << "Fitness Days:" << "\t" << source.fitnessDays << "\t" << "Fitness Numbers:" << source.fitnessNumber << endl;
	return os;
}

FitnessStaff& FitnessStaff:: operator=(const FitnessStaff& source)
{
	name = source.name;
	age = source.age;
	nationality = source.nationality;
	wage = source.wage;
	//role = &roleF()[0];
	role = source.role;
	fitnessDays = source.fitnessDays;
	fitnessNumber = source.fitnessNumber;
	return *this;
}

MedicalStaff::MedicalStaff() {

	role = "physiotherapist";
}

ostream& operator<<(ostream& os, MedicalStaff& source)
{
	os << "Name Surname: " << source.name << "\t" << " Age:" << source.age << "\t Nation:" << source.nationality << "\t Role:" << source.role << "\t Wage:" << source.wage << "M Dollar" << "\t";

	return os;
}

MedicalStaff& MedicalStaff:: operator=(const MedicalStaff& source)
{
	name = source.name;
	age = source.age;
	nationality = source.nationality;
	wage = source.wage;
	//role = &roleF()[0];
	role = source.role;

	return *this;
}


string name_surnameF()
{

	string name[20] = { "Zeljko ","Gergin ","Igor ","Bogdan ","Pablo ","Bobby ","Damir ","Donatos ","Pierre ","Alex ","Alperen ","Emir ","Kerem ","Allen ","Draymond ","Dwayne ","Larry ","Hakeem ","James ","Klay " };
	string choosed_name;

	choosed_name = name[randomNumber2(20)];

	string surname[20] = { "Obradovic","Tanjevic","Rivers","Bryant","Ataman","Kokoskov","Watson","Pereira","Gasly","Hamilton","Salt","Laso","Demir","Green","Jasikevicius","Wade","Bird","Ozil","Robin","Duncan" };
	string choosed_surname;

	choosed_surname = surname[randomNumber2(20)];

	string name_surname = choosed_name + choosed_surname;

	return name_surname;

}


int randomNumber2(int percentage)/////returns a number between min and max values
{
	int num;
	num = (rand() % percentage);
	return num;
}




int ageF()/////returns a number between 20 and 60
{
	int num;

	num = 20 + rand() % 40;


	return num;
}
string nationaltyF()
{

	string nations[5] = { "USA","Canada","Turkey","Africa","France" };
	string choosed_nationlty = nations[randomNumber2(5)];

	return choosed_nationlty;
}
double wageF()//returns a wage around 1M to 5.5 M
{
	double num;
	num =  0.8+ ((rand() % 10) * 0.06);;
	return num;


}
string roleF()
{
	string arr[3] = { "Coach","Medical Staff","Fitness Staff" };
	string role = arr[rand() % 3];
	return role;

}
string trainingDaysF()
{
	string arr[8] = { "None", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	string day = arr[rand() % 8];
	return day;
}
int CoachStaff::trainingNumberF()
{
	int number;
	if (trainingDays == "None")
		number = 0;
	else
		number = 1;
	return number;
}
string fitnessDaysF()
{
	string arr[8] = { "None", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	string day = arr[rand() % 8];
	return day;
}
int FitnessStaff::fitnessNumberF()
{
	int number;
	if (fitnessDays == "None")
		number = 0;
	else
		number = 1;
	return number;
}
#endif







