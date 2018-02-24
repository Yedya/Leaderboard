#include "player.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

player::player()
{


}

player::player(std::string player_Name, int &player_Score)
{
	playerName = player_Name;
	playerScore = player_Score;
	isInLeaderboard = false;
}
	
int player::getPlayerScore() const
{

	return playerScore;
}
	
string player::getPlayerName() const
{

	return playerName;
}

void player::setScore(int &currentPlayerScore)
{
	playerScore = currentPlayerScore;

}

void player::setLeaderBoardStatus(bool isIn_LeaderBoard)
{
	isInLeaderboard = isIn_LeaderBoard;

}

bool player::getLeaderBoardStatus() const
{

	return isInLeaderboard;
}

void player::setPosInLeaderBoard(int pos)
{
	posInLeaderBoard = pos;

}
int player::getPostInLeaderBoard() const
{

	return posInLeaderBoard;
}
