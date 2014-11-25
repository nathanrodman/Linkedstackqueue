//
//  main.cpp
//  Lab2.260.Rodman
//
//  Created by Nathan Rodman on 5/2/14.
//  Copyright (c) 2014 nathan.rodman. All rights reserved.
//

#include "data.h"
#include "linkedqueue.h"
#include "linkedstack.h"


int main()
{
	char fileName[] = "data.dat";
	linkedqueue housesOnList(fileName);
	house aHouse;
	linkedstack houseInterested;
	char response;
    
	cout << "\nThe houses we will visit today:" << endl << endl;
	housesOnList.display ();
	while(housesOnList.dequeue (aHouse))
	{
		cout << "\nNext house to be visited:" << endl;
        aHouse.print();
		cout << "\nWould you like to revisit this house on our way back? (y, n): ";
		cin >> response;
		cin.ignore(100, '\n');
		
		if(response == 'y' || response == 'Y')
		{
			cout << "\nThe house is saved for revisiting" << endl;
			houseInterested.push (aHouse);
		}
	}
    
	cout << "\nWe have finished the first round of screening" << endl << endl;
	cout << "\nOn the way back to the office: " << endl << endl;
    
	while(houseInterested.pop (aHouse))
	{
		cout << "\nNext house to be revisited: " << endl;
        aHouse.print();
	}
    
	cout << "\nWe've finished the second round. ready to make an offer? (y, n):";
	cin >> response;
	cin.ignore (100, '\n');
	cout << "\nlet's talk about that in my office. " << endl << endl;
    
    
	return 0;
}