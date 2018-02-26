#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
#include <iostream>
#include <string>

class player
{
	public:
		player();
		player(std::string player_Name, int &player_Score);
		int getPlayerScore() const;
		string getPlayerName() const;
		void setScore(int &currentScore);
		void setLeaderBoardStatus(bool status);
		bool getLeaderBoardStatus() const;
		void setPosInLeaderBoard(int pos);
		int getPostInLeaderBoard() const;

	private:
		std::string playerName;
		int playerScore;
		bool isInLeaderboard;
		int posInLeaderBoard;
};	

#endif