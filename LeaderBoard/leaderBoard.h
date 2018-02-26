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
		void updateLeaderBoard(player &playerObj,int &newScore);
		void removeDuplicatePlayers(player &playerObj);
		void getSpecificPlayerScore(player &playerObj) const;
		void getScoresWithinRangeInclusive(int from,int to);
		void updatePlayerList(player &playerObj,int &newScore);
		int getListLength() const;
		void FrontBackSplit(struct Node* source,struct Node** frontRef, struct Node** backRef);
        struct Node* SortedMerge(struct Node* a, struct Node* b);  
		void MergeSort(struct Node** headRef);


		void printList()const;
		std::map<string,int> mapOfPlayers;

	private:
		Node *head;
};


#endif