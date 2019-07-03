#include<iostream>

using namespace std;

class Critter
{
private:
	int m_Hunger;
	int m_Boredom;
	
	int	GetMood() const;
	void PassTime(int time = 1);

public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food=4);
	void Play(int fun=4);
	void Show();
	void Ask();

};
Critter::Critter(int hunger, int boredom) :m_Hunger(hunger), m_Boredom(boredom)
{}
 inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}
 inline void Critter::PassTime(int time)
{
	m_Boredom += time;
	m_Hunger += time;
}
void Critter::Talk()
{
	cout << "\nHi! I am Critter and I feel";
	int mood = GetMood();
	if (mood > 15)
		cout << " Mad.\n";
	else if (mood > 10)
		cout << " Frusted.\n";
	else if (mood > 5)
		cout << " Okay\n";
	else
		cout << " Happy.\n";
	PassTime();
}
void Critter::Eat(int food)
{
	cout << " Brrupp.\n";
	m_Hunger -= food;
	if (m_Hunger < 0)
		m_Hunger = 0;
	PassTime();
}
void Critter::Play(int fun)
{
	cout << " Wheee!\n";
	m_Boredom -= fun;
	if (m_Boredom < 0)
		m_Boredom = 0;
	PassTime();
}
void Critter::Show()
{
	if (m_Hunger < 0)
		m_Hunger = 0;
	else if (m_Boredom < 0)
		m_Boredom = 0;
	cout << "\n My hunger level is : " << m_Hunger;
	cout << " \N My boredom level is : " << m_Boredom<<endl;
	PassTime();
}
void Critter::Ask()
{
	if (m_Hunger > 5)
		cout << " Critter is hungry.\n";
	if (m_Boredom > 5)
		cout << " I am bored!!!\n";
	else
		cout << " You are a good Caretaker.\n";
		PassTime();
}
int main
()
{
	Critter crit;
	
	int choice;
	do {
		cout << " \nCritter Caretaker\n\n";
		cout << " 0 - Quit\n";
		cout << " 1 - Listen to your Critter.\n";
		cout << " 2 - Feed your Critter.\n";
		cout << " 3 - Play with your Critter.\n";
		cout << " 4 - Show Critter's Hunger and Boredom Level.\n";
		cout << " 5 - Ask Critter what it wants.\n\n";
		cout << " Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4:
			crit.Show();
			break;
		case 5:
			crit.Ask();
			break;
		case 0:
			cout << " Thanks for Playing.\n\n";
			break;
		default:
			cout << " \nSorry but " << choice << " isn't a valid choice.\n\n";

		}
		system("pause");
		system("cls");
	} while (choice != 0);
		return 0;

}

