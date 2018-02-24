#ifndef LEADERBOARD_H
#define LEADERBOARD_H
using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "player.h"

class Node
{
	public:
		int score;
		string name;
		int pos;

		Node* next;
		Node* prev;
};


class leaderBoard
{
	public:
		leaderBoard();
		void updateLeaderBoard(Node **head,player &playerObj,int &newScore);
		void removeDuplicatePlayers(Node **head,player &playerObj);
		void getSpecificPlayerScore(Node **head,player &playerObj) const;
		void getScoresWithinRangeInclusive(Node **head,int from,int to);

	private:

};


#endif