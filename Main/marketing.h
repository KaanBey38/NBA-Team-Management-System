#include <iostream>
using namespace std;

class marketing
{
private:
	int totalmoney;
protected:
	void settotalmoney(int totalmoney)
	{
		this->totalmoney = totalmoney;
	}
	int gettotalmoney()
	{
		return totalmoney;
	}
};

class merchsale {
public:
	int cap=50, shirt=100, jersey=150, earningfrommerch = 0, parameterformerch = 0;
	void ticketsale()
	{
	}
	void salingmerch()
	{
		int choice, choicetwo;
		char choicethree;
		do
		{
			cout << "Please choose which merchandise you want.\n1) Caps(50$).\n2) Shirts(100$).\n3) Jerseys(150$)." << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please input the number of caps you want: " << endl;
				cin >> choicetwo;
				earningfrommerch = choicetwo * cap;
			}
			else if (choice == 2)
			{
				cout << "Please input the number of shirts you want: " << endl;
				cin >> choicetwo;
				earningfrommerch = choicetwo * shirt;
			}
			if (choice == 3)
			{
				cout << "Please input the number of caps you want: " << endl;
				cin >> choicetwo;
				earningfrommerch = choicetwo * jersey;
			}
			parameterformerch += earningfrommerch;
			cout << "Do you want to buy another merchandise? If you want, please press 'y'. If you don't please press 'n'." << endl;
			cin >> choicethree;
		}

		while (choicethree == 'y');
	}
};




class ticketsale
{
public:
	int frontseat = 1000, sideseat = 500, backseat = 100, earningfromtickets = 0, parameterforticket = 0;
	ticketsale()
	{
	}
	void salingtickets()
	{
		int choice, choicetwo;
		char choicethree;
		do
		{
			cout <<"Please choose which location you want.\n1) Front Seat(1000$).\n2) Side Seat(500$).\n3) Back Seat(100$)."<< endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please input the number of front seat you want: " << endl;
				cin >> choicetwo;
				earningfromtickets = choicetwo * frontseat;
			}
			else if (choice == 2)
			{
				cout << "Please input the number of side seat you want: " << endl;
				cin >> choicetwo;
				earningfromtickets = choicetwo * sideseat;
			}
			if (choice == 3)
			{
				cout << "Please input the number of back seat you want: " << endl;
				cin >> choicetwo;
				earningfromtickets = choicetwo * backseat;
			}
			parameterforticket+= earningfromtickets;
			cout << "Do you want to buy more tickets? If you want, please press 'y'. If you don't please press 'n'." << endl;
			cin >> choicethree;
		} while (choicethree == 'y');
	}
};

class select : protected marketing, public merchsale, public ticketsale
{
public:
	void marketselecter()
	{
		int choice, totalofbothsales;
		cout << "Please choose.\n1) Buy Merchandise.\n2) Buy Tickets." << endl;
		cin >> choice;
		if (choice == 1)
		{
			salingmerch();
		}

		else if (choice == 2)
		{
			salingtickets();
		}

		totalofbothsales = parameterforticket+parameterformerch;
		settotalmoney(totalofbothsales);
		cout << "Total price is: " << gettotalmoney()<<"$" << " Have a nice day." << endl;
	}
};


