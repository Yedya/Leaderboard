#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "player.h"
#include "leaderBoard.h"
#include <algorithm>
#include <functional>
#include <array>
using namespace std;


void addOlderPlayers(leaderBoard currLeaderBoard)
{
	////Older Players
	std::vector<player> previousPlayersScores;
	std::vector<player>:: iterator itr;

	////Add Scores for older players
	int v7 = rand() % 100; 
	player Justin("Justin",v7);
	int v8 = rand() % 100; 
	player Alvin("Alvin",v8);
	int v9 = rand() % 100; 
	player Joe("Joe",v9);

	////Add to vector 
	previousPlayersScores.push_back(Justin);
	previousPlayersScores.push_back(Alvin);
	previousPlayersScores.push_back(Joe);
	
	int currPlayerScore = 0;
	//Iterate and update scores
	for(itr=previousPlayersScores.begin();itr!=previousPlayersScores.end();++itr)
	{
		currPlayerScore = itr->getPlayerScore();
		currLeaderBoard.updateLeaderBoard(*itr,currPlayerScore);

	}

}

int main()
{
	leaderBoard castAwayWK1;

	int zero = 0;
	player mike("mike",zero);
	player Smasher("Smasher",zero);
	player mark("mark",zero);
	player Daniel("Daniel",zero);

	int score1 = 5;
	int v1 = 1;
	int v2 = 1600;
	int v3 = 1700;
	int v4 = 1000;
	int v5 = 1900;
	int v6 = 2411;


	//Game was palyed
	castAwayWK1.updatePlayerList(Smasher,v5);
	castAwayWK1.updatePlayerList(mark,v1);
	castAwayWK1.updatePlayerList(mike,v4);

	castAwayWK1.updatePlayerList(Daniel,v3);
	//
	////Another was palyed
	castAwayWK1.updatePlayerList(Smasher,v1);
	castAwayWK1.updatePlayerList(mark,v1);
	castAwayWK1.updatePlayerList(mark,v1);
	castAwayWK1.updatePlayerList(Smasher,v1);

	addOlderPlayers(castAwayWK1);

	////Print list
	//castAwayWK1.updatePlayerList(Smasher,v6);
	//castAwayWK1.printList();

	//castAwayWK1.getSpecificPlayerScore(Daniel);

	castAwayWK1.getScoresWithinRangeInclusive(1,4);
	////Find scores within range



	system("pause");
	return 0;
}

