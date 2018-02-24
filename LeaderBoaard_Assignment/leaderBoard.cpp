#include "player.h"
#include "leaderBoard.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;



leaderBoard::leaderBoard()
{

}
	/*
		Time : 0(N)
		Space: 0(N) 
	*/
void leaderBoard::updateLeaderBoard(Node **head,player &playerObj,int &newScore)
{
    int pos = 1;
    Node *curr = *head; 
    Node *newNode = new Node;

    //If the player is already in the leaderboard
    if(playerObj.getLeaderBoardStatus())
    {
        //And their current score is less than the their new score
        if(playerObj.getPlayerScore()<newScore)
        {
           //Remove Duplicate
           removeDuplicatePlayers(&curr,playerObj);
        }
        else
        {
            //If they already have a higher score,exit the function
            return;
        }
    }
    
    //If the player is the intial player/ if the list is empty
    if(*head==NULL)
    {
            playerObj.setScore(newScore);
            playerObj.setLeaderBoardStatus(true);
            newNode->score  = playerObj.getPlayerScore();
            newNode->name =  playerObj.getPlayerName();
			newNode->pos = 1;

            newNode->next = NULL;
            newNode->prev = NULL;
            (*head)  = newNode;
            return;
    }
        
    //If the new score is greater than the head, and the player isn't in the leaderboard,insert the player at front of the list and set it to be the head
    if(newScore>curr->score && !playerObj.getLeaderBoardStatus())
    {   
        playerObj.setScore(newScore);
        playerObj.setLeaderBoardStatus(true);
        newNode->score  = playerObj.getPlayerScore();
        newNode->name =  playerObj.getPlayerName();
		newNode->pos = 1;
        newNode->next = curr;
        curr->prev = newNode;
        newNode->prev = NULL;
        
        (*head) = newNode;
        curr = (*head);
        return;
    }

    else
    {   
        //If the current isn't NULL and the new score is less than the next score in the list,keep iterating with curr pointer
        while(curr->next!=NULL && newScore<curr->next->score)
        {
            curr = curr->next;
        }
		    
        //If the player is new, insert him into the linked list
        if(!playerObj.getLeaderBoardStatus())
        {   
            playerObj.setScore(newScore);
            playerObj.setLeaderBoardStatus(true);

            newNode->score  = playerObj.getPlayerScore();
            newNode->name =  playerObj.getPlayerName();
            newNode->next = curr->next;
            newNode->prev = curr;

			Node **tempPos = &curr;
			pos = (*tempPos)->pos;
			newNode->pos=pos+1;	
			if(curr->next!=NULL)
			{
				Node *tempPo2s = curr->next;
				tempPo2s->pos = pos+2;
			}
			curr->pos = pos;

            curr->next = newNode;
			curr->next->prev=newNode;
            curr = (*head);
        }
		else
		{
			newNode->score  = newScore;
            newNode->name =  playerObj.getPlayerName();
			newNode->next = curr->next;
			newNode->prev = curr->prev;
			curr->prev = newNode;
			curr->next=newNode;

			Node **tempPos = &curr;
			pos = (*tempPos)->pos;
			newNode->pos=pos+1;
			if(curr->next!=NULL)
			{
				Node *tempPo2s = curr->next;
				tempPo2s->pos = pos+2;
			}

			curr->pos = pos;

		}
    }
}


	/*
		Time : 0(N)
		Space: 0(1) 
	*/
void leaderBoard::removeDuplicatePlayers(Node **head,player &playerObj)
{			
			Node *curr =  (*head);
			if(playerObj.getPlayerName()==curr->name)
			{	
				Node *temp =curr;
				//Tentative joining of the list list
				curr = curr->next;
				curr->prev=NULL;
				delete temp;
			}
			while(curr->next!=NULL)
			{
				if(curr->next->name==playerObj.getPlayerName() )
				{	
					Node *temp =curr->next;
					//Tentative joining of the list list
					curr->next= curr->next->next;
					delete temp;
					return;
				}
				else
				{
					curr = curr->next;
				}
			}
}


	/*
		Time : 0(N)
		Space: 0(1) 
	*/
void leaderBoard::getSpecificPlayerScore(Node **head,player &playerObj) const
{
	Node *curr =  (*head);
	while(curr!=NULL)
	{
		if(curr->name==playerObj.getPlayerName())
		{
			cout << "Score For " << curr->name   << " is : " << playerObj.getPlayerScore() <<endl;
			break;
		}
		curr=curr->next;
	}
}


	/*
		Time : 0(N)
		Space: 0(1) 
	*/
void leaderBoard::getScoresWithinRangeInclusive(Node **head,int from,int to)
{
	Node *curr = (*head);
	
	while(curr->next!=NULL)
	{
		if(curr->pos==from)
		{
			cout << "Position # " << curr->pos  <<endl;
			cout << "Name " << curr->name <<endl;
			cout << "Score " << curr->score <<endl;
		}
		if(curr->pos==to+1)
		{
			break;
		}
		curr = curr->next;
	}





}