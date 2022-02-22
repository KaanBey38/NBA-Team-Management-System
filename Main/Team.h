#include<iostream>
#include "Player.h"
#include "Staff.h"
#include "marketing.h"
#include "socialmedia.h"

#include<vector>

using namespace std;


////////lengthOfArray(sizeof(arr),sizeof(arr[0]));     returns any type of array length
int lengthOfArray(int fullSize, int elementSize)
{
	int len{ };

	len = (fullSize / elementSize);
	return len;

}






class Team {

private:


	/// Team

	string name;

	//Players
	vector<Player> Players;

	//Staff
	
	Staff  staffs[15];
	int staff_length = lengthOfArray(sizeof(staffs), sizeof(staffs[0]));
	
	///Social Media
	


	///Marketing 



public:

	friend class Covid;
	twitter Twitter;
	instagram Instagram;
	youtube Youtube;
	select Select;
	
	
	Team() : name{}///def const
	{
		for (int i = 0; i < 10; i++)
		{
			Players.push_back(Player());
		}
	
		Player pg("Point Guard"), sg("Shooter Guard"), sf("Small Forward"), pf("Power Forward"), c("Center");
		/// <summary>
		/// / because of random luck there might be a lack of position so we add one for all of them incase lack
		/// </summary>
		Players.push_back(pg);
		Players.push_back(sg);
		Players.push_back(sf);
		Players.push_back(pf);
		Players.push_back(c);

	}

	Team(string name) :name{ name }
	{
		for (int i = 0; i < 10; i++)
		{
			Players.push_back(Player());
		}

		Player pg("Point Guard"), sg("Shooter Guard"), sf("Small Forward"), pf("Power Forward"), c("Center");
		/// <summary>
		/// / because of random luck there might be a lack of position so we add one for all of them incase lack
		/// </summary>
		Players.push_back(pg);
		Players.push_back(sg);
		Players.push_back(sf);
		Players.push_back(pf);
		Players.push_back(c);
	}



	
	Team(const Team& source)/////copy const
	{
		/////copying name
		name = source.name;
		/////copying players
		for (int i = 0; i < (unsigned)Players.size(); i++)
		{
			Players[i] = source.Players[i];
		}
		/////copying staff
		
		for (int i = 0; i < (unsigned)Players.size(); i++)
		{
			staffs[i] = source.staffs[i];
		}
		

	}


	void printTeam()/////prints whole team
	{
		cout << name << "'s Team lineup:" << endl;

		for (int i = 0; i < (unsigned)Players.size(); i++)
		{
			cout << "#" << i + 1 << " " << Players[i] << endl;
		}

	}

	void printTeam(int len)/////amount  for to decide how many players will be printed (OVERLOADED FUNC OF printTeam() )
	{

		for (int i = 0; i < len; i++)
		{
			cout << "#" << i + 1 << " " << Players[i] << endl;
		}

	}

	int getTeamLen()
	{
		 return Players.size();
	}

	void createBestStarting()
	{
		int place{};
		Player temp;


		place =findBestPosPlayer("Point Guard");
		temp=Players[0] ;
		Players[0] = Players[place];
		Players[place] = temp;

		place = findBestPosPlayer("Shooter Guard");
		temp = Players[1];
		Players[1] = Players[place];
		Players[place] = temp;

		place = findBestPosPlayer("Small Forward");
		temp = Players[2] ;
		Players[2] = Players[place];
		Players[place] = temp;


		place = findBestPosPlayer("Power Forward");
		temp = Players[3] ;
		Players[3] = Players[place];
		Players[place] = temp;


		place = findBestPosPlayer("Center");
		temp = Players[4] ;
		Players[4] = Players[place];
		Players[place] = temp;

		cout << "Recomended Starting 5 is:"<<endl;
		printTeam(5);

	}


	/// 
	/// PLAYER CLASS
	/// special functions for players
	/// 


	void setStarting5()///// setting the teams starting lineup
	{
		Player temp(" ", " ", " ", 0, 0, 0, 0, 0);
		int place;
		for (int i = 0; i < 5; i++)
		{
			cout << "Choose " << i + 1 << ". player to  pick for starting 5" << endl;
			printTeam();
			cout << endl << "Your choice:";
			cin >> place;
			place--;

			temp = Players[place];

			Players[place] = Players[i];

			Players[i] = temp;
		}
		cout << endl << name << "'s starting 5 is:" << endl;

		printTeam(5);////team's starting 5


	}

	void cutPlayer()/// kick player from team lineup
	{
		Player temp;
		int place{};
		printTeam();
		cout << endl << "Choose player to kick:";
		cin >> place;
		place--;/// simple use at arrays
		cout << "Team decided to kick:" << endl << Players[place] << endl << endl;

		for (int temp_place = place; temp_place < (signed)Players.size() - 1; temp_place++)///// transfering our player to last element of vector so we can use pop_back()
		{
			temp = Players[temp_place];

			Players[temp_place] = Players[temp_place + 1];

			Players[temp_place + 1] = temp;

		}
		Players.pop_back();/// 

		cout << "New team is:" << endl;
		printTeam();

	}

	int findBestPosPlayer(string pos) /////finds highest avr player's place by its position
	{
		int hightest_avr{ 0 };
		int location{ 0 };//////players loc at vector

		for (int i = 0; i < (unsigned)Players.size(); i++)
		{	
			for (int k = 0; k < (unsigned)Players.size(); k++)
			{
				if (Players[k].positionGetter() == pos && Players[k].averageGetter() > hightest_avr)
				{
					hightest_avr = Players.at(k).averageGetter();
					location = k;
				}
			}
		}

		return location;
	}



	/// <summary>
	/// STAFF CLASS
	/// special functions for staff members
	/// 
	/// 
	/// 
	/// </summary>

	int getStaffLength(void)
	{
		return staff_length;

	}

	void printStaff(int length)
	{

		for (int i = 0; i < length; i++)
			cout << "#" << i + 1 << " " << staffs[i] << endl;

	}
	void printCoachStaff(int length)
	{
		//vector<CoachStaff> temp;
		CoachStaff temp[15];
		int counter = 0;

		for (int i = 0; i < length; i++)
		{
			if (staffs[i].getRole() == "Coach")
			{
				temp[counter] = staffs[i];
				counter++;
			}

		}
		cout << "The Coachs: " << endl;
		for (int i = 0; i < counter; i++)
			cout << "#" << i + 1 << " " << temp[i] << endl;

	}
	void printStaffCost(int length)
	{
		double cost = 0;
		for (int i = 0; i < length; i++)
			cost = cost + staffs[i].getWage();
		cout << "Total cost of staff to the team is: " << cost << "M dollars" << endl;
	}
	
	
};





/// <summary>
/// /// TEST MAÝN
/// </summary>
/// <returns></returns>

