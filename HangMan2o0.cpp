#include<bits/stdc++.h>
using namespace std;
void gameover(int ,ofstream& ,ifstream& );
void show(int ,string ,string ,int );
char getguess();
bool checkguess(char ,string &,string);

	const int max_wrong=8;
	int life=3;
	int score=0;
int main()
{
	ofstream fout;
	fout.open("HighScores.dat",ios::app);
	ifstream fin;
	fin.open("HighScores.dat",ios::in);
	vector<string> word;
	word.push_back("AWESOME");
	word.push_back("PRIZE");
	word.push_back("AMAZING");
	word.push_back("NEWSPAPER");
	word.push_back("WINNER");
	word.push_back("FANTASTIC");
	
		
	do
	{
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(word.begin(),word.end());
		string secWord=word[0];
		
		string used="";
		string sofar(secWord.size(),'-');
		int wrong=0;
		
		show(life,used,sofar,wrong);		
		
		
		
		while(secWord!=sofar && wrong<max_wrong)
		{
			char guess;
		    guess=getguess();
		    
			if(checkguess(guess,used,secWord))
			{
				for(int i=0;i<secWord.size();i++)
				{
					if(secWord[i]==guess)
					{
						sofar[i]=guess;
					}
				}
				system("CLS");
				cout<<"That's right! "<<guess<<" is in word.";
				if(sofar==secWord)
				{	break;			}
				show(life,used,sofar,wrong);				
			}
			else
			{
				system("CLS");
				cout<<"Wrong! "<<guess<<" is not in word.";
				++wrong;
				if(wrong==max_wrong)
				{	break;				}
				show(life,used,sofar,wrong);				
			}
		
		}
		if(sofar==secWord)
		{
			cout<<"\nCongrats! you guessed it right.";
			cout<<"\nYou score 100 points.";
			score+=100;
		}
		else
		{
			cout<<"\nYou are hanged.";
			cout<<"\nYou lost you 1 life.";
			--life;
		}
		cout<<"\n\nThe word is "<<secWord<<endl;
		
		
	if(life==0)	
	{	gameover(score,fout,fin);}
	
	}while(life!=0);
}
void gameover(int score,ofstream& fout,ifstream& fin)
{
	cout<<"\nYou have lost all your lives.";
	cout<<"\nYour Total score : "<<score;
	cout<<"\nEnter your name : ";
	string name;cin>>name;
	cout<<"\n\nHigh Scores-\n";
	fout<<name<<"  -  "<<score<<endl;
	fout.close();
	char ch;
	ch=fin.get();
	while(!fin.eof())
	{
		cout<<ch;
		ch=fin.get();
	}
	fin.close();
	cout<<"\n-------------------Game Over-------------------\n";
}
void show(int life,string used,string sofar,int wrong)
{
	cout<<"\n---------------------------------------------";
	cout<<"\n\t*****Welcome To Hangman*****";
	cout<<"\n\nYou have "<<life<<" lives.";
	cout<<"\n\nWord so far is : \n"<<sofar;
	cout<<"\n\nLetters you have used already : "<<used;
	cout<<"\nYou have left "<<max_wrong-wrong<<" incorrect guess.\n";
	cout<<"\n---------------------------------------------\n";
}
char getguess()
{
	char guess;
	cout<<"\n\nEnter your guess : ";cin>>guess;
	guess=toupper(guess);
	return guess;
}
bool checkguess(char guess,string& used,string secWord)
{
	while(used.find(guess)!=string::npos)
	{
		cout<<"\nYou have already enter this letter.";
		guess=getguess();
		
	}
	used+=guess;
	
	if(secWord.find(guess)!=string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

