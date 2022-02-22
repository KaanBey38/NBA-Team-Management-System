#include<iostream>
#include<string>
#include<time.h>
#include<vector>


using namespace std;

int randomNumber(int percentage);///creates a random number between 0 and percentage
string name_surnameF2();/// picks a  random name and surname from our litte name and surmane pool
string nationaltyF2();///picks a random nation
string positionF();///picks a random position
int ageF2();/// creates a random age between 18 and 37
int heightF();///creates a random height between 185 adn 215
int weightF();/// creates a random weight between 95 and 125
int averageF();/// creates a random average between 65 and 100
double playerWageF();//returns a wage around 1M-10M

 
class Player {


	friend ostream& operator<<(ostream& os,  Player& source)/////overloaded output operator
	{
		os << "Name Surname: " << source.name_surnameGetter() << "\t" << " Age:" << source.ageGetter() << "\t Nation:" << source.nationaltyGetter() << "\t Pos:" << source.positionGetter() << "\t Height:" << source.heightGetter() << "\t Weight:" << source.weightGetter() << "\t Average:" << source.averageGetter() << "\t Wage:" << source.playerWageGetter() << "M Dolar";
		return os;
	}

	friend	istream& operator>>(istream& in, Player& source)//// overloaded input operator
	{
		string temp_name_surname, temp_position, temp_nationalty;
		int temp_age, temp_height, temp_weight, temp_average;
		double temp_wage;
		getline(cin >> ws, temp_name_surname);
		getline(cin >> ws, temp_position);
		getline(cin >> ws, temp_nationalty);
		in >> temp_age>>temp_height>>temp_weight>>temp_average>>temp_wage;
		source = Player{ temp_name_surname, temp_position, temp_nationalty,temp_age, temp_height, temp_weight, temp_average,temp_wage};

		return in;
	}
private:
	string name_surname, position, nationalty;
	int age, height, weight, average;
	double wage;
public:

	Player() :name_surname{ name_surnameF2() }, position{ positionF() }, nationalty{ nationaltyF2() }, age{ ageF2() }, height{ heightF() }, weight{ weightF() }, average{ averageF() }, wage{ playerWageF() }
	{
		///default const
	}
	Player(string pos) :name_surname{ name_surnameF2() }, position{ pos }, nationalty{ nationaltyF2() }, age{ ageF2() }, height{ heightF() }, weight{ weightF() }, average{ averageF() }, wage{ playerWageF() }
	{
		///1 arg cost
	}
	Player(string name_sur,string pos,string nation,int age,int height,int weight,int average, double wage) :name_surname{ name_sur	}, position{ pos }, nationalty{ nation }, age{ age }, height{ height }, weight{ weight }, average{ average }, wage{ wage }
	{
		///8 arg const
	}

	Player(const Player& source) :name_surname{ source.name_surname }, position{ source.position }, nationalty{ source.nationalty }, age{ source.age }, height{ source.height }, weight{ source.weight }, average{ source.average }, wage{ source.wage }
	{
		////Copy const
	}

	 Player(Player&& source) noexcept :name_surname{ source.name_surname }, position{ source.position }, nationalty{ source.nationalty }, age{ source.age }, height{ source.height }, weight{ source.weight }, average{ source.average }, wage{ source.wage }
	{
		//Move const
	}

	 ~Player()
	 {
		 ///Destructor
	 }

	 Player& operator=(const Player& source)/////overloaded = operator
	 {
		
		name_surname = source.name_surname;
		position = source.position;
		nationalty = source.nationalty;
		age = source.age;
		height = source.height;
		weight = source.weight;
		average = source.average;
		wage = source.wage;
		return *this;

	 }

	 Player operator--(int var)/////overloaded -- operator
	 {
		 name_surname = "";
		 position = "";
		 nationalty ="";
		 age = 0;
		 height = 0;
		 weight =0;
		 average = 0;
		 wage = 0;
		 
			
		 return *this;
	 }


	 //////////////////////  name_surname

	string name_surnameGetter()
	 {
		 return name_surname;
	 }

	void name_surnameSetter(string str)
	{
		name_surname=str;
	}
	//////////////////////  position
	string positionGetter()
	{
		return position;
	}

	void positionSetter(string str)
	{
		position = str;
	}

	//////////////////////  nationalty

	string nationaltyGetter()
	{
		return nationalty;
	}

	void nationaltySetter(string str)
	{
		nationalty = str;
	}

	//////////////////////  age

	int ageGetter()
	{
		return age;
	}

	void ageSetter(int age)
	{
		this->age = age;
	}

	//////////////////////  height

	int heightGetter()
	{
		return height;
	}

	void heightSetter(int height)
	{
		this->height = height;
	}

	//////////////////////  weight
	int weightGetter()
	{
		return weight;
	}

	void weightSetter(int weight)
	{
		this->weight = weight;
	}
	
	//////////////////////  avr
	int averageGetter()
	{
		return average;
	}

	void averageSetter(int average)
	{
		this->average = average;
	}
	
	/// ///// wage

	double playerWageGetter()
	{
		return wage;
	}

	void playerWageSetter(double wage)
	{
		this->wage = wage;
	}
	
};


string name_surnameF2()
{
	
	string name[20] = { "Lebron ","Stephen ","Kevin ","Kobe ","Michael ","Bobby ","Damir ","Kyrie ","Furkan ","Cedi ","Kaan ","Emir ","Kerem ","Allen ","Draymond ","Dwayne ","Larry ","Hakeem ","James ","Klay " };
	string choosed_name;

	choosed_name = name[randomNumber(20)];

	string surname[20] = { "James","Curry","Durant","Bryant","Jordan","Dixon","Hoca","Irving","Korkmaz","Osman","Salt","Allen","Demir","Green","Smith","Wade","Bird","Thompson","Robin","Duncan" };
	string choosed_surname;

	choosed_surname = surname[randomNumber(20)];

	string name_surname = choosed_name + choosed_surname;

	return name_surname;
	
}

string nationaltyF2()
{
	
	string nations[5] = { "USA","Canada","Turkey","Africa","France" };
	string choosed_nationlty = nations[randomNumber(5)];

	return choosed_nationlty;
}

string positionF()
{
	
	string pos[] = { "Point Guard","Shooter Guard","Small Forward","Power Forward","Center" };

	string choosed_pos = pos[randomNumber(5)];

	return choosed_pos;
}


int ageF2()/////returns a number between 18 and 37
{
	int num;

	num = 18 + rand() % 20;


	return num;
}

int heightF()/////returns a number between 185 and 215
{
	int num;

	num = 185 + rand() % 30;

	return num;
}

int weightF()/////returns a number between 95 and 125
{
	int num;

	num = 95 + rand() % 30;

	return num;
}

int averageF()/////returns a number between 65 and 100
{
	int num;

	num = 65 + rand() % 36;

	return num;
}

double playerWageF()//returns a wage around 1M-31M
{
	double num;
	num = 1 + ((rand() % 100) * 0.3);

	return num;


}

int randomNumber(int percentage)/////returns a number between min and max values
{
	int num;

	num = (rand() % percentage);


	return num;
}



