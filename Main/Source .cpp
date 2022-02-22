#include<iostream>
#include"Team.h"
#include "corona.h"
#include <time.h>
using namespace std;

int main()
{
	srand((signed)time(NULL));
	Team BrooklynNets("Brooklyn Nets");


	int choice{ 0 };////// menu decider
	int inside_choice{};/// in menu decider
	
	
	do
	{

		cout << "Select part for manage:" << endl << "1.Inside the team (Players)" << endl << "2.Inside the team(staffs)" << endl << "3.Social Media" << endl << "4.Marketing" << endl << "5.Nba Covid report" << endl <<"6.Exit"<<endl<< "Your choice:";
		cin >> choice;

		if (choice == 1)
		{

			cout << endl << "Select :" << endl;
			cout << "1.Print Team Roaster" << endl << "2.Select starting 5" << endl << "3.Cut a player" << endl << "4.Create best starting 5" << endl;
			cin >> inside_choice;

			if (inside_choice == 1)
			{
				BrooklynNets.printTeam();

			}

			else if (inside_choice == 2)
			{
				BrooklynNets.setStarting5();
			}

			else if (inside_choice == 3)
			{
				BrooklynNets.cutPlayer();
			}
			else if (inside_choice == 4)
			{
				BrooklynNets.createBestStarting();
			}

		}

		else if (choice == 2)
		{

			cout << "1.Print Staff" << endl << "2.Print Coachs" << endl << "3.Print total Cost of Staff " << endl << "Press any number to turn back to main menu" << endl << "Your choice : ";
			cin >> inside_choice;

			if (inside_choice == 1)
			{
				BrooklynNets.printStaff(BrooklynNets.getStaffLength());
			}
			else if (inside_choice == 2)
			{

				BrooklynNets.printCoachStaff(BrooklynNets.getStaffLength());
			}
			else if (inside_choice == 3)
			{

				BrooklynNets.printStaffCost(BrooklynNets.getStaffLength());
			}


		}
		else if (choice == 3)
		{
			int choicethree;
			char choicetwo='y';

			do
			{
				cout << "Hello Welcome To NBA Social Media Management System Please Choose To Managae:\n1)Twitter.\n2)Instagram.\n3)Youtube.\n4)Exit." << endl;
				cin >> choicethree;
				if (choicethree == 1)
				{
					BrooklynNets.Twitter.twitteroperationselecter();
					cout << "Do you want to continue to manage other social medias? If you want, please press 'y'. If you don't press any letter except 'y'. Thanks." << endl;
					cin >> choicetwo;
				}
				else if (choicethree == 2)
				{
					BrooklynNets.Instagram.instagramoperationselecter();
					cout << "Do you want to continue to manage other social medias? If you want, please press 'y'. If you don't press any letter except 'y'. Thanks." << endl;
					cin >> choicetwo;
				}
				else if (choicethree == 3)
				{
					BrooklynNets.Youtube.youtubeoperationselecter();
					cout << "Do you want to continue to manage other social medias? If you want, please press 'y'. If you don't press any letter except 'y'. Thanks." << endl;
					cin >> choicetwo;
				}
			} while (choicetwo == 'y' && choicethree!=4);
		}
		else if (choice == 4)
		{
			BrooklynNets.Select.marketselecter();

		}


		else if (choice == 5)
		{
			cout << "Pls make a choice to see the report of variant" << endl << "1.Omicron" << endl << "2.Delta" << endl;
			cin >> inside_choice;
			if (inside_choice == 1)
			{
				Covid* obj = new Omicron;
				obj->Info();
			}
			else if (inside_choice == 2)
			{
				Covid* obj = new Delta;
				obj->Info();
			}
		}

		else if (choice == 6)
		{

			cout << "Bye" << endl;
		}

		try {
			if (choice<1 || choice>6)
				throw - 1;
		}
		catch (int& ex) {
			cerr << "Entered  wrong number please make choose carefully!!!";
		}
		/*
		else
		{
			cout << "Entered  wrong number please make choose carefully!!!" << endl;

		}
		*/
		cout << endl;
	} while (choice != 6);







	return 0;
}
