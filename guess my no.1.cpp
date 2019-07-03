#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int secretno,guess,tries=0;
	secretno=rand();
	secretno=secretno%100+1;
	cout<<endl<<"             ...Welcome To The Guess My Number..."<<endl<<endl;
	string alpha;
	do
	{
		cout<<endl<<"     Guess a Number : ";
		cin>>guess;
	
		++tries;
		
			 if(guess<secretno)
				cout<<"    Too Low !"<<endl;
			else if(guess>secretno)
				cout<<"    Too High !"<<endl;
			else
				cout<<endl<<"That's it..CONGRATULATION!!!"<<endl<<"You got in "<<tries<<" Attempt.";
 	}while(guess!=secretno);
				
}

