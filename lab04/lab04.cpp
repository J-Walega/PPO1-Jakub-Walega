#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Log {
	public:
		static void info(string message = "") {
			cout << message << endl;
		}
};

class Dice {
	private:
		int sides;	
	public:	
	void getSides(int s)
		{
			this->sides=s;
		}	
		int roll() 
		{
			int result = (rand() % sides) + 1;
			
			ostringstream ss;
			ss << "Dice roll: " << result;
			Log::info(ss.str());
			
			return result;
		}
};

class Pawn {
	private:
		int players;
	public:
		int position;
		string name;
		
		void GetPlayers(int playerNr)
		{
			this->players=playerNr;
		}
		
		Pawn() {}
		
		Pawn(string name) {
			this->name = name;
			this->position = 0;
			
			Log::info(name + " joined the game.");
		}
};

class Board {
		public:
		 int maxPosition;
		 int maxTurns;
		void GetmaxPosition(int position)
		{
			this->maxPosition=position;
		}
		void GetmaxTurns(int turns)
		{
			this->maxTurns=turns;
		}
		vector<Pawn> pawns;
		Dice dice;
		Pawn winner;
		int turnsCounter;
		
		Board() {
			this->turnsCounter = 0;
		}
		
		void performTurn() {
			this->turnsCounter++;
			
			ostringstream ss;
			ss << "Turn " << this->turnsCounter;
			Log::info();
			Log::info(ss.str());
			
			for(int i = 0; i < this->pawns.size(); i++) {
				int rollResult = this->dice.roll();
				Pawn &pawn = this->pawns.at(i);
				pawn.position += rollResult;
				
				ostringstream ss;
				ss << pawn.name << " new position: " << pawn.position;
				Log::info(ss.str());
				if(turnsCounter==maxTurns)
				{
					throw "Maximum amount of turns has been reached";
				}				
				if(pawn.position >= this->maxPosition) {
					this->winner = pawn;
					throw "Winner was called!";
				}
			}
		}
};

int SetSides()
{
	int sides=0;
	cout<<"Set number of dice's sides: ";
	cin>>sides;
	if(sides<2)
	{
		cout<<"Number of dice's sides has to be higher or equal to 2.";
		exit(1);
	}
	return sides;
}

int PlayersNr()
{
	int players=0;
	cout<<"Set number of players: ";
	cin>>players;
	if(players<2)
	{
		cout<<"Number of players has to be at least 2.";
		exit(2);
	}
	return players;
}

int GetmaxPosition()
{
	int position;
	cout<<"Set max number of positions:";
	cin>>position;
	if(position<10)
	{
		cout<<"Minimum position is 10.";
		exit(3);
	}
	return position;
}

int GetmaxTurns()
{
	int turns;
	cout<<"Set max amount of turns:";
	cin>>turns;
	if(turns<2)
	{
		cout<<"Minimum amount of turns is 2.";
		exit(4);
	}
	return turns;
}

int main() {
	srand(time(NULL));
	
	int sides=0;
	int players=0;
	int position;
	int turns=0;
	
	Board board = Board();
	board.dice = Dice();
	sides=SetSides();
	board.dice.getSides(sides);
	position=GetmaxPosition();
	board.GetmaxPosition(position);
	board.GetmaxTurns(GetmaxTurns());
	
	board.pawns.push_back(Pawn("Luke Skywalker"));
	board.pawns.push_back(Pawn("Darth Vader"));
	
	try {
		while(true) {
			board.performTurn();
		}
	} catch(const char* exception) {
		Log::info();
		Log::info(board.winner.name + " won");
	}
	
	return 0;
}//NIE dokonczone
