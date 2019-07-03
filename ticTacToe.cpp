#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

const char x='X';
const char o='O';
const char tie='T';
const char empty=' ';
const char no_one='N';

void instruction();
char humanpiece();
char opponent(char);
void displayboard(vector<char>& );
char winner(const vector<char>& );
int humanmove(vector<char>& ,char );
int computermove(vector<char> , char );
void announcewinner(char ,char ,char );
char askyesno();
int asknumber();
bool islegal(int ,const vector<char>& );

int main()
{
	int move;
	const int squares=9;
	vector<char> board(squares,empty);
	
	instruction();
	
	char human=humanpiece();
	char computer=opponent(human);
	char turn=x;
	
	displayboard(board);
	
	while(winner(board)==no_one)
	{
		if(turn==human)
		{
			move=humanmove(board,human);
			board[move]=human;
		}
		else
		{
			move=computermove(board,computer);
			board[move]=computer;
		}
		displayboard(board);
		turn=opponent(turn)	;
	}
	announcewinner(winner(board),computer,human);
	
	return 0;
}


void instruction()
{
	cout<<"\nWelcome to the ultimate man-machine showdown : Tic-Tac-Toe.\n";
	cout<<"--where human brain is pit against silicon processor\n\n";
	cout<<"Make your move known by entering a number,0-8.The number\n";
	cout<<"corresponds to the desired board position,as illustrated : \n\n";
		cout<<"0 | 1 | 2 \n";
		cout<<"----------\n";
		cout<<"3 | 4 | 5 \n";
		cout<<"----------\n";
		cout<<"7 | 8 | 9 \n\n";
		cout<<"Prepare youself,human.The battle is about to begin.\n\n";
}

void displayboard(vector<char>& board)
{
	cout<<"\n\t"<<board[0]<<" | "<<board[1]<<" | "<<board[2];
	cout<<"\n\t"<<"----------";
	cout<<"\n\t"<<board[3]<<" | "<<board[4]<<" | "<<board[5];
	cout<<"\n\t"<<"----------";
	cout<<"\n\t"<<board[6]<<" | "<<board[7]<<" | "<<board[8];
	cout<<"\n\n";
}


char askyesno()
{
	char r;
	do{
	cout<<"\nDo you require the first move? (y/n) : ";
	cin>>r;
	}while(r!='y' && r!='n');
	return r;
}
char humanpiece()
{
	char gofirst=askyesno();
	if(gofirst=='y')
	{
		cout<<"\nThen take it. You wil need it.\n";
		return x;
	}
	else
	{
		cout<<"\nYou bravery will be your undoing...I will go first.\n";
		return o;
	}
}


char opponent(char opp)
{
	if(opp==x)
	{	return o;	}
	else
	{	return x;	}
}


char winner(const vector<char>& board)
{
	const int winning_rows[8][3]={{0,1,2},
								  {3,4,5},
								  {6,7,8},
								  {0,3,6},
								  {1,4,7},
								  {2,5,8},
								  {0,4,8},
								  {2,4,6} };
		
	for(int row=0;row<8;++row)
	{
	if((board[winning_rows[row][0]]!=empty) && (board[winning_rows[row][0]]==board[winning_rows[row][1]]) && (board[winning_rows[row][1]]==board[winning_rows[row][2]]))
	{
		return (board[winning_rows[row][0]]);	
		
	}
	}
	if(count(board.begin(),board.end(),empty)==0)
	{
		return tie;

	 } 
	
	
	 	return  no_one;
		
	}
	



inline bool islegal(int move,const vector<char>& board)
{
	return (board[move]==empty);
}
int humanmove(vector<char>& board,char human)
{
	int move=asknumber(); 
	while(!islegal(move,board))
	{
		cout<<"\nThat square is already uccuoied, foolish.\n";
		move=asknumber();
		
	}
	cout<<"\nFine...\n";
	return move;
	
}
int asknumber()
{
	int number;
	do{
		cout<<"\nWhere will you move ? (0 - 8) : ";
		cin>>number;	
	}while(number>8 || number<0);
	return number;
}


int computermove(vector<char> board,char computer)
{
	int move=0;
	bool found=false;
	while(!found && move<board.size())
	{
	if(islegal(move,board))
	{
		board[move]=computer;
		found=winner(board)==computer;
		board[move]=empty;
	}
	if(!found)
		{
			++move;
		}
	}
	
	if(!found)
	{
		move=0;
		char human=opponent(computer);
		while(!found && move<board.size())
		{
			if(islegal(move,board))
			{
		board[move]=human;
		found=winner(board)==human;
		board[move]=empty;
			}
			if(!found)
			{
				++move;
			}
		}
	}
	
	if(!found)
	{
		move=0;
		int i=0;
		srand(static_cast<unsigned int>(time(0)));
		//{4,0,2,8,6,1,3,5,7};
		
		while(!found && move<board.size())
		{
		int best_move=rand()%9;
			move=best_move;
			if(islegal(move,board))
			{
				found=true;
			}
			
		}
		
	}
	
	cout<<"\nI shall take square number "<<move << endl;
	return move;
}


 void announcewinner(char winner,char computer,char human)
 {
 	if(winner==computer)
 	{
 		cout<<winner<< " 's won!\n";
 		cout<<"As I predicted, I am triumphant once more--proof\n";
 		cout<<"that computers are superior to humans in all regards.\n";
	 }
	 else if(winner==human)
	 {
	 	cout<<winner<<" 's won!";
	 	cout<<"NO,no!.somehow you tricked me.\n";
	 	cout<<"But never again! I,the computer,so swear it!\n";
	 }
	 else
	 {
	 	cout<<"It's a tie.\n";
	 	cout<<"You were most lucky,human, and somehow managed to tie me.\n";
	 	cout<<"Celebrate...for this is the best you will ever achieve.\n";
	 }
 }
