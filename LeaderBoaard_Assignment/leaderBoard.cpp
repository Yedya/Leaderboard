#include "player.h"
#include "leaderBoard.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;



leaderBoard::leaderBoard()
{
	head = NULL;
}



void leaderBoard::printList() const
{

	Node* curr = head;
	while(curr!=NULL)
	{
		cout << "\n    " <<endl;
		cout << "Position # " << curr->pos  <<endl;
		cout << "Name " << curr->name <<endl;
		cout << "Score " << curr->score <<endl;
		cout << "\n    " <<endl;
		curr = curr->next;
	}

}


/*
	Time : 0(1)
	Space: 0(1) 
*/
void leaderBoard::updatePlayerList(player &playerObj,int &newScore)
{
	std::map <string, int>::iterator mainItr;
	int updatedScore =0;
	if(playerObj.getLeaderBoardStatus() && playerObj.getPlayerScore()>newScore) return;

	else if(playerObj.getLeaderBoardStatus() && playerObj.getPlayerScore()<newScore)
	{
		//Update our player's new score in our map.
		mainItr = mapOfPlayers.find(playerObj.getPlayerName());
		mainItr->second=newScore;

		updatedScore =mainItr->second;
		updateLeaderBoard(playerObj,updatedScore);	
	}
	else
	{
		playerObj.setScore(newScore);
		mapOfPlayers.insert(std::make_pair(playerObj.getPlayerName(),newScore));

		mainItr = mapOfPlayers.find(playerObj.getPlayerName());
		updatedScore= mainItr->second;
		updateLeaderBoard(playerObj,updatedScore);
		return;
	}

}


/*
	Time : 0(log n)
	Space: 0(log n)
*/
void leaderBoard::updateLeaderBoard(player &playerObj,int &newScore)
{
    int pos = 1;
    Node *curr = head; 

    //If the player is already in the leaderboard
	if(playerObj.getLeaderBoardStatus() && playerObj.getPlayerScore()<newScore)
    {
		while(curr!=NULL)
		{
			if(curr->name==playerObj.getPlayerName())
			{
				curr->score=newScore;
				cout << "Merge Sort" << endl;
				MergeSort(&head);
				return ;	
			}
			curr= curr->next;
		}
    }


    if(head==NULL)
    {
			Node *newNode =  new Node;
            newNode->score  = playerObj.getPlayerScore();
            newNode->name =  playerObj.getPlayerName();
			playerObj.setLeaderBoardStatus(true);
			newNode->pos = 1;

            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            return;
    }
        
    //If the new score is greater than the head, and the player isn't in the leaderboard
    if(newScore>curr->score && !playerObj.getLeaderBoardStatus())
    {   
		Node *newNode =  new Node;
        newNode->score  = playerObj.getPlayerScore();
        newNode->name =  playerObj.getPlayerName();
		playerObj.setLeaderBoardStatus(true);
		newNode->pos = 1;
        newNode->next = curr;
		//insert the player at front of the list  
        curr->prev = newNode;
        newNode->prev = NULL;
        
		//set it to be the head
        head = newNode;
        curr = head;
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

			Node *newNode =  new Node;
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
            curr = head;
        }
    }
}

/*
	Time : 0(N)
	Space: 0(1) 
*/
void leaderBoard::getSpecificPlayerScore(player &playerObj) const
{
	Node *curr =  head;
	while(curr!=NULL)
	{
		if(curr->name==playerObj.getPlayerName())
		{
			cout << "Score For " << curr->name   << " is : " << playerObj.getPlayerScore() <<endl;
			cout << "His position is   " << curr->pos   << endl;
			break;
		}
		curr=curr->next;
	}
}


/*
	Time : 0(N)
	Space: 0(1) 
*/
void leaderBoard::getScoresWithinRangeInclusive(int from,int to)
{
	if(from<=0|| to<=0  || to> getListLength()|| from> getListLength()-1) 
	{
		cout << "Please Enter a valid position in the leaderboard!" <<endl;
		return;
	}

	Node *curr = head;
	for(int i =0;i<from-1;i++)
    {
        curr= curr->next;
    }

	while(curr->pos<=to+1 && curr->next!=NULL)
    {
		cout << "\n" <<endl;
        cout << "Position: " << curr->pos <<endl;
        cout << "Player Name " << curr->name << endl;
        cout << "Player Score " << curr->score << endl;
        cout << "\n" <<endl;
        
        curr= curr->next;
    }
	cout << "\n" <<endl;
    cout << "Position: " << curr->pos <<endl;
    cout << "Player Name " << curr->name << endl;
    cout << "Player Score " << curr->score << endl;
    cout << "\n" <<endl;
}

/*
	Time : 0(N)
	Space: 0(N) 
*/
void leaderBoard::FrontBackSplit(struct Node* source,struct Node** frontRef, struct Node** backRef)         
{
	struct Node* fast;
	struct Node* slow;
	if (source==NULL || source->next==NULL)
	{
		/* length < 2 cases */
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
 
		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
			slow = slow->next;
			fast = fast->next;
			}
		}
 
	/* 'slow' is before the midpoint in the list, so split it in two
		at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
	}
}

/*
	Time : 0(N)
	Space: 0(N) 
*/
struct Node* leaderBoard::SortedMerge(struct Node* a, struct Node* b)
{
  struct Node* result = NULL;
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->score >= b->score)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

/*
	Time : 0(log n)
	Space: 0(N) 
*/
void leaderBoard::MergeSort(struct Node** headRef)
{
  struct Node* head = *headRef;
  struct Node* a;
  struct Node* b;
 
  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
 
  /* Split head into 'a' and 'b' sublists */
  FrontBackSplit(head, &a, &b); 
 
  /* Recursively sort the sublists */
  MergeSort(&a);
  MergeSort(&b);
 
  /* answer = merge the two sorted lists together */
  *headRef = SortedMerge(a, b);
}

/*
	Time : 0(N)
	Space: 0(1) 
*/
int leaderBoard::getListLength() const
{
	int lenght=0;
	Node *curr = head;

	while(curr!=NULL)
	{
		
		lenght+=1;
		curr=curr->next;
	}
	return lenght;
	
}