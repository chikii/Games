#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int secretno,guess,tries=0;
	cout<<"Enter a Secretno : ";
	cin>>secretno;
	do 
	{
	guess=rand();
	++tries;
	guess=guess%100+1;
	cout<<endl<<"Guess a no.: "<<guess;
	if (guess<secretno)
		cout<<endl<<"Too low.";
	else if(guess>secretno)
		cout<<endl<<"Too high";
	else
		cout<<endl<<"That's it.Computer got in "<<tries<<" attempt.";
	}while(guess!=secretno);
	
	
}
