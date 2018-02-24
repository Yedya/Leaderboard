#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "player.h"
#include "leaderBoard.h"
using namespace std;

//class leaderBoard
//{
//
//	private:
//		Node *head, *tail;  
//
//	public:
//		leaderBoard()
//		{
//			head = NULL;
//			tail = NULL;
//		}
//		/*Sorted Insert, expensive enough
//		Time : 0(N)
//		Space : 0(1)
//		*/
//		void updateLeaderBoard(Node **head,player &playerObj,int newScore)
//		{
//			
//			bool exists = false;
//			Node *curr = *head;
//			Node *newNode = new Node;
//			
//			if(playerObj.getLeaderBoardStatus())
//			{
//				if(playerObj.getPlayerScore()<newScore)
//				{
//					newNode = updateExisting_Node(head,playerObj,newScore);
//				}
//				else{
//					return;
//				}
//			}
//
//			
//			if(*head==NULL)
//			{
//					
//					Node *newNode = new Node;
//					playerObj.setScore(newScore);
//					newNode->score  = playerObj.getPlayerScore();
//					newNode->name =  playerObj.getPlayerName();
//					playerObj.setLeaderBoardStatus(true);
//					newNode->next = NULL;
//					newNode->prev = NULL;
//					(*head)    = newNode;
//					return;
//			}
//			
//			exists = doesPlayerExist(&curr,playerObj);
//
//			if(newScore<curr->score && !playerObj.getLeaderBoardStatus())
//			{
//				Node *newNode = new Node;
//				playerObj.setScore(newScore);
//				newNode->score  = playerObj.getPlayerScore();
//				newNode->name =  playerObj.getPlayerName();
//				playerObj.setLeaderBoardStatus(true);
//				newNode->next = curr;
//				curr->prev = newNode;
//				newNode->prev = NULL;
//				(*head) = newNode;
//				curr = (*head);
//				return;
//			}
//
//			else
//			{
//				
//				while(curr->next!=NULL && newScore>curr->next->score)
//				{
//					
//					curr = curr->next;
//				}
//				
//				 New Score > curr->next
//				if(!playerObj.getLeaderBoardStatus())
//				{
//					Node *newNode = new Node;
//					playerObj.setScore(newScore);
//					newNode->score  = playerObj.getPlayerScore();
//					newNode->name =  playerObj.getPlayerName();
//					playerObj.setLeaderBoardStatus(true);
//				
//					newNode->next = curr->next;
//					newNode->prev = curr;
//
//					curr->next = newNode;
//					curr = (*head);
//				}
//				
//				else if(playerObj.getLeaderBoardStatus())
//				{	
//					cout << "Higher Score " << newScore << " " << playerObj.getPlayerScore()<< " NAME "<< playerObj.getPlayerName() << "" << newNode->name << endl;
//					curr = (*head);
//				}
//			}
//		}
//
//
//
//		bool doesPlayerExist(Node **head,player &playerObj)
//		{
//			bool result = false;
//			Node *curr =  (*head);
//			while(curr!=NULL)
//			{
//				if(curr->name==playerObj.getPlayerName())
//				{
//					result = true;
//				}
//				curr=curr->next;
//			}
//		return result;
//		}
//
//		Node* updateExisting_Node(Node **head,player &playerObj,int score)
//		{
//			Node *newNode = new Node;
//			Node *curr =  (*head);
//			while(curr!=NULL)
//			{
//				if(curr->name==playerObj.getPlayerName())
//				{
//					
//					
//
//					cout << "Score For " << curr->name   << " Updated From " << playerObj.getPlayerScore()   << " to " <<  score   <<endl;
//					//playerObj.setScore(score);
//					//newNode->score  = playerObj.getScore();
//					//newNode->name =  playerObj.getName();
//
//					playerObj.setScore(score);
//					curr->score  = playerObj.getPlayerScore();
//					curr->name =  playerObj.getPlayerName();
//					
//					break;
//
//
//					//playerObj.setScore(*score);
//					//curr->score = *score;
//				}
//
//				curr=curr->next;
//			}
//		return newNode;
//		}
//
//		void updateExistingNode_(Node **head,player &playerObj,int newScore)
//		{
//					
//					Node *newNode = new Node;
//					Node *temp = new Node;
//					Node *nodeToDelete = new Node;
//					newNode->next = NULL;
//					newNode->prev = NULL;
//					newNode->score = newScore;
//					newNode->name = playerObj.getPlayerName();
//    
//					Node *curr = (*head);
//					cout << "Curr" <<  playerObj.getPlayerScore() << newScore << endl;
//					//while(curr->next!=NULL)
//					//{
//					//	if(curr->next->name==playerObj.getName())
//					//	{
//					//		//cout << "\n " ;
//					//		//cout << "Working " << curr->next->score<<endl;
//					//		//cout << curr->next->name;
//					//		//nodeToDelete = curr->next;
//					//		//curr->next->score=newScore;
//					//		//curr->next = curr->next->next;
//
//
//
//					//		//curr->next = curr->next->next;
//					//		//delete nodeToDelete;
//					//		/*temp->score=newScore;*/
//					//		//return updateLeaderBoard(head,playerObj,newScore);
//
//					//		break;
//
//					//	}
//					//	else
//					//	{
//					//		curr = curr->next;
//					//	}
//					//	
//					//}
//					curr = (*head);
//					
//					if(newNode->score>curr->score)
//					{
//						newNode->next = curr;
//
//						(*head) = newNode;
//						
//						return;
//					}
//					else
//					{
//						while(curr->next!=NULL && newNode->score<curr->next->score)
//						{
//							curr =curr->next;
//						}
//						newNode->next = curr->next;
//						newNode->prev = curr;
//						curr->next = newNode;
//						curr = (*head);
//					}
//					
//
//		}
//
//
//};

void printList(Node **head)
{
	Node* curr = *head;
	while(curr!=NULL)
	{
		cout << "Position # " << curr->pos  <<endl;
		cout << "Name " << curr->name <<endl;
		cout << "Score " << curr->score <<endl;
		cout << "\n    " <<endl;
		curr = curr->next;
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
	Node* head = NULL;

	int score1 = 800000;
	castAwayWK1.updateLeaderBoard(&head,Smasher,score1);
	int v2 = rand() % 80;   
	castAwayWK1.updateLeaderBoard(&head,Daniel,v2);
	int v3 = rand() % 8000;  
	castAwayWK1.updateLeaderBoard(&head,mike,v3);
	int v4 = rand() % 800;  
	castAwayWK1.updateLeaderBoard(&head,mark,v4);
	int v5 = rand() % 800;  
	castAwayWK1.updateLeaderBoard(&head,mike,v5);
	castAwayWK1.updateLeaderBoard(&head,Smasher,v2);
	//Posistion Bug, found @ 8.20 this morning, weh :(
	//castAwayWK1.updateLeaderBoard(&head,mark,score1);
	


	//Older Players
	std::vector<player> previousPlayersScores;
	std::vector<player>:: iterator itr;

	//Add Scores for older players
	int v7 = rand() % 100; 
	player Justin("Justin",v7);
	int v8 = rand() % 100; 
	player Alvin("Alvin",v8);
	int v9 = rand() % 100; 
	player Joe("Joe",v9);

	//Add to vector 
	previousPlayersScores.push_back(Justin);
	previousPlayersScores.push_back(Alvin);
	previousPlayersScores.push_back(Joe);
	
	int currPlayerScore = 0;
	//Iterate and update scores
	for(itr=previousPlayersScores.begin();itr!=previousPlayersScores.end();++itr)
	{
		currPlayerScore = itr->getPlayerScore();
		castAwayWK1.updateLeaderBoard(&head,*itr,currPlayerScore);

	}

	//Print list
	printList(&head);
	castAwayWK1.getSpecificPlayerScore(&head,Daniel);

	/*
		Not working anymore :(
	*/
	castAwayWK1.getScoresWithinRangeInclusive(&head,1,3);
	//Find scores within range



	system("pause");
	return 0;
}

