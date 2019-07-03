#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<vector>
#include<string>

using namespace std;

int main()
{
	const int max_wrong = 8;
	vector<string> words;
	words.push_back("GAMING");
	words.push_back("STUNNING");
	words.push_back("INCRIDIBLE");
	words.push_back("ULTIMATE");
	words.push_back("LEAGUE");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(),words.end());
	string secret_word = words[0];
	 
	string sofar(secret_word.size(), '-' );
	string used = "";
	int wrong=0;

	cout << "\t*****Welcome to Hangman. Good Luck!*****\n";

	while ((wrong < max_wrong) && (sofar != secret_word))
	{
		cout << "\n-------------------------------------------\n";
		cout << "\nYou have " << max_wrong - wrong;
		cout << " incorect guess left.\n";
		cout << "\nYou have used the following letters : ";
		cout << used;
		cout << "\n\nSo far,the word is : \n";
		cout << sofar;

		cout << "\n\nEnter your guess : ";
		char guess; cin >> guess;
		guess = toupper(guess);

		while (used.find(guess) != string::npos)
		{
			cout << "\nYou have already enter this letter.";
			cout << "\n\nEnter your guess : ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (secret_word.find(guess) != string::npos)
		{
			system("CLS");
			cout << "\nThat's right!. " << guess << " is in the letter.";
			for (int i = 0; i < secret_word.size(); i++)
			{
				if (guess == secret_word[i])
				{
					sofar[i] = guess;
				}
			}
			getchar();
			
		}
		else
		{
			system("CLS");
			cout << "\nWRONG!. You didn't get the right one.";
			++wrong;
			getchar();
			
		}

	}
	if (wrong == max_wrong)
	{
		cout << "\n\nYou  have been HANGED.\tBetter luck next time.";
	
	}
	else
	{
		cout << "\n\nCONGRATS!!!\tYou guessed it.";
	}

	cout << "\n\nThe word was " << secret_word << "."<<endl;
	
	getchar();

}
