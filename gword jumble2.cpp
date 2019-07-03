#include<iostream>
#include<string.h>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	//enter words
	enum{word,hint,num_option};
	const int num_word=11;
	const string WORDS[num_word][num_option]={ {"game","play it."},
	{"yash","Even you can not guess your name."},{"saya","Made for each other"},
	{"gamer","Game is life."},{"keepgoing","do not stop."},{"passion","doing for "}
	,{"niceplay","god going"},{"fantastic","kamal kr dita"},{"fuck","wtf"},{"enough","bahut ho gya"},
	{"strong","takat vala"}	};
	string guess,c;
	//choice random word with respective hint
	cout<<"         Welcome To The WORD JUMBLE "<<endl<<endl;
	cout<<" Guess the word to win the game."<<endl;
	cout<<" Enter 'hint' for a hint."<<endl;
	cout<<" Enter 'quit' to quit a game."<<endl;
	int score=0;
	do{
	srand(static_cast<unsigned int>(time(0)));
	int choice=rand()%num_word;
	string theWord=WORDS[choice][word];
	string theHint=WORDS[choice][hint];
	
	//jumble the word
	string jumble=theWord;
	int length=jumble.size();
/*	int index1,index2;
	char temp;*/
	for(int i=0;i<length;++i)
	{
		int index1=(rand()%length);
		int index2=(rand()%length);
		char temp=jumble[index1];
		jumble[index1]=jumble[index2];
		jumble[index2]=temp;
	}
	
	//welcome to the player.
	
	cout<<endl<<" The jumble is : "<<jumble<<endl<<endl;

	cout<<" Your Guess : ";
	cin>>guess;
	int point=jumble.size();
	
	
	//starting the loop.
	while((guess != theWord) && (guess != "quit"))
	{
		cout<<endl<<" ";
		if(guess=="hint")
		  {		  cout<<theHint;
				--point;
			}
		else 
		 cout<<"Wrong!,Try Again.";
	cout<<endl<<" Your Guess : ";
	cin>>guess;	 
	}
	
	if(guess==theWord)
	{ 	cout<<endl<<"That's it! You guessed it ! ";
		cout<<endl<<"You Scored : "<<point<< " points out of "<<length;	}
	cout<<endl<<"Do u want to play more(y=yes/n=no) : ";
	cin>>c;
	
	score+=point;
}while(guess!="quit"||c!="n");
cout<<endl<<"Your total score : "<<score<<endl<<"Thank's for Playing. Bye!!!";		
}
