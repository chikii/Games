#include<bits/stdc++.h>
using namespace std;

void Instruction()
{
	cout<<"\t\tWelcome To Game.\n";
	cout<<"\n A farmer must move a Goat, Khana and Wolf from one bank of the river to the other by boat. \n The boat can hold only the farmer and one other object at a time. \n If the Goat is left unattended on a bank with the Khana, it will eat it. \n The Wolf will also eat the Goat if they are left unattended.";
	cout<<"\nUse -> \n";
	cout<<"Farmer = Farmer\n";
	cout<<"Wolf = Wolf\n";
	cout<<"Goat = Goat\n";
	cout<<"Khana = Khana\n";
	cout<<"No One = No\n\n\n";
}
string N="0";
void Show(vector<string>& sBank,char pBoat,vector<string>& dBank)
{
	cout<<"\n Source Bank \t\t    Destination Bank\n\n";
	for(int i=0;i<4;i++)
	{
		if(sBank[i]!=N)
		{
		cout<<sBank[i];
		if(i==0)
			cout<<"      | "<<endl;
		else if(i==1)
			cout<<"        | "<<endl;
		else if(i==2)
			cout<<"        | "<<endl;
		else
			cout<<"       | "<<endl;
		}	
	}
	if(pBoat=='S')
		cout<<"              Boat\n";
	else
		cout<<"             \t\tBoat\n";
	for(int i=0;i<4;i++)
	{
		if(dBank[i]!=N)
			cout<<"        \t\t    | "<<dBank[i]<<endl;
	}
}

void Add(vector<string>& Bank,string Boat[])
{
	if(Boat[0]=="Farmer" || Boat[1]=="Farmer")
		Bank[0]="Farmer";
	if(Boat[0]=="Wolf" || Boat[1]=="Wolf")
		Bank[1]="Wolf";
	if(Boat[0]=="Goat" || Boat[1]=="Goat")
		Bank[2]="Goat";
	if(Boat[0]=="Khana" || Boat[1]=="Khana")
		Bank[3]="Khana";
}

void Remove(vector<string>& Bank,string Boat[])
{
	if(Boat[0]=="Farmer" || Boat[1]=="Farmer")
		Bank[0]=N;
	if(Boat[0]=="Wolf" || Boat[1]=="Wolf")
		Bank[1]=N;
	if(Boat[0]=="Goat" || Boat[1]=="Goat")
		Bank[2]=N;
	if(Boat[0]=="Khana" || Boat[1]=="Khana")
		Bank[3]=N;
}
inline bool farmer(vector<string>& Bank)
{
	if(find(Bank.begin(),Bank.end(),"Farmer")!=Bank.end())
		return true;
	else 
		return false;
}
inline bool Wolf(vector<string>& Bank)
{
	if(find(Bank.begin(),Bank.end(),"Wolf")!=Bank.end())
		return true;
	else 
		return false;
}
inline bool Goat(vector<string>& Bank)
{
	if(find(Bank.begin(),Bank.end(),"Goat")!=Bank.end())
		return true;
	else 
		return false;
}
inline bool Khana(vector<string>& Bank)
{
	if(find(Bank.begin(),Bank.end(),"Khana")!=Bank.end())
		return true;
	else 
		return false;
}
int R=0;
bool Fail(vector<string>& Source,vector<string>& Destination)
{
	if(Goat(Source) && Khana(Source) && !farmer(Source) || Goat(Destination) && Khana(Destination) && !farmer(Destination))
	{	R=1;return true;}
	if(Wolf(Source) && Goat(Source) && !farmer(Source) || Wolf(Destination) && Goat(Destination) && !farmer(Destination))
		return true;
	if(Wolf(Source) && Goat(Source) && Khana(Source) && !farmer(Source) || Wolf(Destination) && Goat(Destination) && Khana(Destination) && !farmer(Destination))
		return true;
		
	return false;
}
void Reason()
{
	if(R==1)
		cout<<"\nGoat eat all Khana.\n";
	else 
		cout<<"\nWolf eat goat.\n";
}
inline char Change(char& pBoat)
{
	if(pBoat=='S')
		return 'D';
	else 
		return 'S';
}
int main()
{
	vector<string> Source(4);
	Source[0]="Farmer";Source[1]="Wolf";Source[2]="Goat";Source[3]="Khana";
	vector<string> Destination(4,N);
	vector<string> Success(Source);
	string Boat[2]=N;
	char pBoat='S';
	
	Instruction();
	Show(Source,'S',Destination);
	
	while(Destination!=Success && !Fail(Source,Destination))
	{
		Boat[0]="Farmer";
		do
		{
			char c;
		cout<<"\n\nWhom You Want in Boat : Farmer and ";
		cin>>Boat[1];
		}while(Boat[1]!="Wolf" && Boat[1]!="Goat" && Boat[1]!="Khana" && Boat[1]!="No");
		
		
		if(pBoat=='S')
		{
			Remove(Source,Boat);
			Add(Destination,Boat);
		}
		else
		{
			Remove(Destination,Boat);
			Add(Source,Boat);
		}
		pBoat=Change(pBoat);
		system("cls");
		Instruction();
		Show(Source,pBoat,Destination);
	}
	
	if(Destination==Success)
		cout<<"\n\nYOU WIN!!!";
	else
	{
		cout<<"\n\nYOU LOSE!!!";
		Reason();
	}
	system("pause");
}
