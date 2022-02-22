#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;

class socialmedias
{
	private:
		int dislikes;
	public:
		int likes, followers;
		int getdislikes()
		{
			return dislikes;
		}
		socialmedias()
		{
			dislikes=0;
			likes=0;
			followers=0;
		}
		int likegenerator()
		{
			srand(time(0));
			likes=rand()%100000;
		    return likes;
		}
		int dislikegenerator()
		{
			srand(time(0));
			dislikes=rand()%1000;
			return dislikes;
		}
		int followergenerator()
		{
			srand(time(0));
			followers=rand()%10000;
			return followers ;
		}
};
class twitter: public socialmedias
{
	public:
		string tweet;
		twitter()
		{
			tweet=" ";
		}
		void twitteroperationselecter()
		{
			int choicefortwitteroperation;
			cout<<"Welcome to the management of NBA's official Twitter account."<<endl;
			do
			{
			cout<<"Please choose.\n1) Post Tweet.\n2) Post Photo.\n3) Post Video.\n4) Exit."<<endl;
			cin>>choicefortwitteroperation;
			if(choicefortwitteroperation==1)
			{
				twitter a;
				int uzunluk;
				cout<<"Please share your tweet here:"<<endl;
				getline(cin>>ws,tweet);
				uzunluk=tweet.size();
				cout<<"Your "<<tweet<<" tweet is gained "<<a.followergenerator()*(uzunluk/5)<<" followers. "<<endl;
				followers+=a.followergenerator()*(uzunluk/5);
				cout<<"Total Twitter Followers: "<<followers<<endl;
			}
			else if(choicefortwitteroperation==2)
			{
				twitter a;
				cout<<"~Photo Uploaded Successfully~"<<endl;
				cout<<"Photo that you upload gained "<<(a.likegenerator()-a.dislikegenerator())+a.followergenerator()<<" followers. "<<endl;
				followers+=(a.likegenerator()-a.dislikegenerator())+a.followergenerator();
				cout<<"Total Twitter Followers: "<<followers<<endl;
			}
			else if(choicefortwitteroperation==3)
			{
				twitter a;
				cout<<"~Video Uploaded Successfully~"<<endl;
				cout<<"Video that you upload gained "<<(a.likegenerator()-a.dislikegenerator())+a.followergenerator()<<" followers. "<<endl;
				followers+=(a.likegenerator()-a.dislikegenerator())+a.followergenerator();
				cout<<"Total Twitter Followers: "<<followers<<endl;
			}
			else if(choicefortwitteroperation==4)
			{
				cout<<"Exit."<<endl;
				choicefortwitteroperation==4;
			}
		}while(choicefortwitteroperation!=4);
		}
};




class instagram: public socialmedias
{
	public:
		instagram()
		{
			likes=0;
		}
		void instagramoperationselecter()
		{
			int choiceforinstagramoperation;
			cout<<"Welcome to the management of NBA's official Instagram account."<<endl;
			do
			{
			cout<<"Please choose.\n1) Post Photo.\n2) Post Video.\n3) Live Video.\n4) Exit."<<endl;
			cin>>choiceforinstagramoperation;
			if(choiceforinstagramoperation==1)
			{
				instagram a;
				cout<<"~Photo Uploaded Successfully~"<<endl;
				cout<<"Photo that you upload gained "<<(a.likegenerator()/a.dislikegenerator())*a.followergenerator()<<" followers. "<<endl;
				followers+=(a.likegenerator()/a.dislikegenerator())*a.followergenerator();
				cout<<"Total Instagram Followers: "<<followers<<endl;
			}
			else if(choiceforinstagramoperation==2)
			{
				instagram a;
				cout<<"~Video Uploaded Successfully~"<<endl;
				cout<<"Video that you upload gained "<<(a.likegenerator()/a.dislikegenerator())*a.followergenerator()<<" followers. "<<endl;
				followers+=(a.likegenerator()/a.dislikegenerator())*a.followergenerator();
				cout<<"Total Instagram Followers: "<<followers<<endl;
			}
			else if(choiceforinstagramoperation==3)
			{
				instagram a;
				cout<<"You are about to start live."<<endl;
				int livecalllength;
				srand(time(0));
				livecalllength=rand()%100;
				cout<<"The live broadcast lasted as long as "<<livecalllength<<" minutes and gained "<<(livecalllength/(livecalllength*20/100))*a.followergenerator()<<" followers."<<endl;
				followers+=(livecalllength/(livecalllength*20/100))*a.followergenerator();
				cout<<"Total Instagram Followers: "<<followers<<endl;
			}
			else if(choiceforinstagramoperation==4)
			{
				cout<<"Exit."<<endl;
				choiceforinstagramoperation==4;
			}
		    }while(choiceforinstagramoperation!=4);
		}
};




class youtube: public socialmedias
{
	public:
		youtube()
		{
			likes=0;
		}
		void youtubeoperationselecter()
		{
	    int choiceforyoutubeoperation=0;
			cout<<"Welcome to the management of NBA's official Youtube account."<<endl;
			do
			{
			cout<<"Please choose.\n1) Post Photo.\n2) Post Video.\n3) Exit."<<endl;
			cin>>choiceforyoutubeoperation;
			if(choiceforyoutubeoperation==1)
			{
				instagram a;
				cout<<"~Photo Uploaded Successfully~"<<endl;
				cout<<"Photo that you upload gained "<<(a.likegenerator()/a.dislikegenerator())*a.followergenerator()<<" followers. "<<endl;
				followers+=(a.likegenerator()/a.dislikegenerator())*a.followergenerator();
				cout<<"Total Youtube Followers: "<<followers<<endl;
			}
			else if(choiceforyoutubeoperation==2)
			{
				instagram a;
				cout<<"~Video Uploaded Successfully~"<<endl;
				int youtubevidlength;
				srand(time(0));
				youtubevidlength=rand()%100;
				cout<<"Length of the video is: "<<youtubevidlength<<" minutes and gained "<<(youtubevidlength/(youtubevidlength*10/100))*a.followergenerator()<<" followers. "<<endl;
				followers+=(youtubevidlength/(youtubevidlength*10/100))*a.followergenerator();
				cout<<"Total Youtube Followers: "<<followers<<endl;
			}
			else if(choiceforyoutubeoperation==3)
			{
				cout<<"Exit."<<endl;
				choiceforyoutubeoperation==3;
			}
		}while(choiceforyoutubeoperation!=3);
		}
};




/*int main()
{
	int choicethree;
	char choicetwo;
	twitter a;
	instagram b;
	youtube c;
	do
	{
	cout<<"Hello Welcome To NBA Social Media Management System Please Choose To Managae:\n1)Twitter.\n2)Instagram.\n3)Youtube.\n4)Exit."<<endl;
	cin>>choice;
		if(choicethree==1)
		{
	        a.twitteroperationselecter();
	        cout<<"Do you want to continue to manage other social medias? If you want, please press 'y'. If you don't press any letter except 'y'. Thanks."<<endl;
	        cin>>choicetwo;
		}
		else if(choicethree==2)
		{
			b.instagramoperationselecter();
			cout<<"Do you want to continue to manage other social medias? If you want, please press 'y'. If you don't press any letter except 'y'. Thanks."<<endl;
	        cin>>choicetwo;
		}
		else if(choicethree==3)
		{
			c.youtubeoperationselecter();
			cout<<"Do you want to continue to manage other social medias? If you want, please press 'y'. If you don't press any letter except 'y'. Thanks."<<endl;
	        cin>>choicetwo;
	    }
	}while(choicetwo=='y');
    return 0;
}*/
