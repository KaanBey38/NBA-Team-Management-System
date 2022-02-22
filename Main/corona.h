#include <iostream>
#include <string>

#include <time.h>
using namespace std;


int randomNumber5(int percentage)/////returns a number between min and max values
{
	int num;

	num = (rand() % percentage);


	return num;
}

string name_surnameF3()
{

	string name[20] = { "Lebron ","Stephen ","Kevin ","Kobe ","Michael ","Bobby ","Damir ","Kyrie ","Furkan ","Cedi ","Kaan ","Emir ","Kerem ","Allen ","Draymond ","Dwayne ","Larry ","Hakeem ","James ","Klay " };
	string choosed_name;

	choosed_name = name[randomNumber5(20)];

	string surname[20] = { "James","Curry","Durant","Bryant","Jordan","Dixon","Hoca","Irving","Korkmaz","Osman","Salt","Allen","Demir","Green","Smith","Wade","Bird","Thompson","Robin","Duncan" };
	string choosed_surname;

	choosed_surname = surname[randomNumber5(20)];

	string name_surname = choosed_name + choosed_surname;

	return name_surname;

}

string TeamName()
{

	string name[10] = { "Brooklyn Nets"," Boston Celtics","Los angeles Lakers","Los Angeles Clippers","Dallas Mavericks","Memphis Grizzlies","Phoenix Suns","Milwaukee Bucks","Miami Heat","Chicago Bulls" };

	string choosed_name;

	choosed_name = name[randomNumber5(10)];

	return choosed_name;

}

class Covid
{
public:

	string* name;


public:

	void Info()
	{
		DiseaseImpact();

		CovidList();

	}



	string getName() { return *name; }

	Covid() {

		name = new string;

		//cout << "no args cons for covid" << endl;

		*name = "unkown";

	}

	Covid(const Covid& obj);//copy cons

	~Covid();


private:

	virtual void DiseaseImpact(void) = 0;//pure virtual function

	virtual void CovidList(void) = 0;


};
Covid::Covid(const Covid& obj)
{
	*(this->name) = *(obj.name);


}

Covid::~Covid()
{
	//cout << "covid destructor has come" << endl;

	delete name;

}



class Omicron :public Covid
{
public:

	Omicron()
	{
		//string hold = "Omicron";

		//cout << "no args cons for omicron" << endl;



		*name = "Omicron";

	}

	virtual void CovidList() override;

	virtual void DiseaseImpact(void) override;

	Omicron(const Omicron& obj);

	~Omicron()
	{
		//cout << "omicron destructor has come" << endl;


	}

};


Omicron::Omicron(const Omicron& obj)
{
	//cout << "Omicron copy cons has come" << endl;

	*(this->name) = *(obj.name);


}



void Omicron::DiseaseImpact()
{

	cout << "Players can not play for 10 days Cause of Omicron:" << endl;

}



void Omicron::CovidList()
{
	int counter = 0;
	for (int i = 0; i < 15; i++)
	{

		if (rand() % 5 == 2)//this is the chance that a player has a covid(1 in 5)
		{

			cout << "Positive Case:" << "  Player#" << counter + 1 << ":" << name_surnameF3() << "      Team: " << TeamName() << "   Variant Type:Omicron" << endl;
			counter++;
		}


	}
	cout << "Totaly " <<  counter << " Nba players has Omicron Virus" << endl;
}

class Delta :public Covid
{
public:

	Delta()
	{
		//string hold = "Omicron";

		//cout << "no args cons for delta" << endl;



		*name = "Delta";

	}

	virtual void CovidList(void) override;

	virtual void DiseaseImpact(void) override;

	Delta(const Delta& obj);

	~Delta()
	{
		//cout << "delta destructor has come" << endl;


	}

};

Delta::Delta(const Delta& obj)
{


	*(this->name) = *(obj.name);


}



void Delta::DiseaseImpact()
{

	cout << " Players can not play for 14 Days cause of Delta" << endl;

}


void Delta::CovidList(void)
{

	int counter = 0;
	for (int i = 0; i < 15; i++)
	{

		if (rand() % 5 == 2)//this is the chance that a player has a covid(1 in 15)
		{

			cout << "Positive Case:" << "  Player#" << counter + 1 << ":" << name_surnameF3() << "      Team: " << TeamName() << "   Variant Type:Delta" << endl;
			counter++;
		}

	}


	cout << "Totaly " <<  counter << " Nba players has Delta Virus" << endl;

}


