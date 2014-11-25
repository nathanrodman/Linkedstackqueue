//
//  linkedqueue.cpp
//  Lab2.260.Rodman
//
//  Created by Nathan Rodman on 5/2/14.
//  Copyright (c) 2014 nathan.rodman. All rights reserved.
//

#include "linkedqueue.h"

linkedqueue::linkedqueue(): front(NULL), rear(NULL), size(0)
{
    
}

linkedqueue::linkedqueue(const linkedqueue & aQueue)
{
    if(aQueue.front == NULL)
	{
		front = rear = NULL;
	}
	else
	{

		front = new node;
		
		front->item = aQueue.front->item;
        
		
		node * destNode = front;
		node * srcNode = aQueue.front->next;
		while(srcNode != NULL)
		{
			destNode->next = new node;
			destNode = destNode->next;
			destNode->item = srcNode->item;
            
			srcNode = srcNode->next;
		}
		destNode->next = NULL;
        
		rear = destNode;
	}
}

linkedqueue::~linkedqueue()
{
    node * curr = front;
	while(front)
	{
		curr = front->next;
		delete front;
		front = curr;
	}
	front = rear = NULL;
}

const linkedqueue& linkedqueue::operator= (const linkedqueue & aQueue)
{
    if(this == &aQueue)
		return *this;
	else
	{
		node * curr = front;
		while(front)
		{
			curr = front->next;
			delete front;
			front = curr;
		}

		if(aQueue.front == NULL)
		{
			front = rear = NULL;
		}
		else
		{
			front = new node;
			front->item = aQueue.front->item;
			
			node * destNode = front;
			node * srcNode = aQueue.front->next;
			while(srcNode != NULL)
			{
				destNode->next = new node;
				destNode = destNode->next;
				destNode->item = srcNode->item;
                
				srcNode = srcNode->next;
			}
			destNode->next = NULL;

			rear = destNode;
		}	
		return *this;
	}
}


linkedqueue::linkedqueue(const char * fileName)
{
    ifstream in;
    house aHouse;
    
    size = 0;
    
    char address[100];
    int sqft;
    int bedrooms;
    float bathrooms;
    char features[100];
    
    in.open(fileName);
    if (!in)
    {
        cerr << "Unable to open " << fileName << "!!";
        exit(1);
    }
    
    in.get(address, 100, ';');
    while(!in.eof())
    {
        in.ignore(100, ';');
        in >> sqft;
        in.ignore(100, ';');
        in >> bedrooms;
        in.ignore(100, ';');
        in >> bathrooms;
        in.ignore(100, ';');
        in.get(features, 100, '\n');
        in.ignore(100, '\n');
        
        aHouse.setAddress(address);
        aHouse.setSqFt(sqft);
        aHouse.setBdm(bedrooms);
        aHouse.setBath(bathrooms);
        aHouse.setFeatures(features);
        
        enqueue(aHouse);
        size++;
        
        in.get(address, 100, ';');
    }
    
}

bool linkedqueue::enqueue(const house &aHouse)
{
    node * newNode = new node;
    newNode->item = aHouse;
    newNode->next = nullptr;
    
    if(!rear)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    
    return true;
}

bool linkedqueue::dequeue(house &aHouse)
{
    if(!front || !rear)
        return false;
    else
    {
        node * curr = front;
        if(front == rear)
            front = rear = NULL;
        else
            front = front->next;
        
        curr->next = NULL;
        aHouse = curr->item;
        delete curr;
        return true;
    }
}

void linkedqueue::display() const
{
    node * curr;
    
    cout << "Queue contains: " << endl;
    for(curr=front; curr; curr=curr->next)
    {
        curr->item.print();
    }

}
