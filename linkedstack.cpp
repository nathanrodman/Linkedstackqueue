//
//  linkedstack.cpp
//  Lab2.260.Rodman
//
//  Created by Nathan Rodman on 5/3/14.
//  Copyright (c) 2014 nathan.rodman. All rights reserved.
//

#include "linkedstack.h"

linkedstack::linkedstack(): size(0), head(NULL)
{
    
}

linkedstack::linkedstack(const linkedstack & aStack)
{
    if(aStack.head == NULL)
		head = NULL;
	else
	{
		head = new node;
		head->item = aStack.head->item;
        
		node * destNode = head;
		node * srcNode = aStack.head->next;
		while(srcNode != NULL)
		{
			destNode->next = new node;
			destNode = destNode->next;
			destNode->item = srcNode->item;
            
			srcNode = srcNode->next;
		}
		destNode->next = NULL;
	}
}

const linkedstack& linkedstack::operator= (const linkedstack & aStack)
{
    if(this == &aStack)
		return *this;
	else
	{
		node * curr = head;
		while(head)
		{
			curr = head->next;
			delete head;
			head = curr;
		}
        
		if(!aStack.head)
			head = NULL;
		else
		{
			head = new node;
			
			head->item = aStack.head->item;
            
			node * destNode = head;
			node * srcNode = aStack.head->next;
            
			while(srcNode)
			{
				destNode->next = new node;
				destNode = destNode->next;
				destNode->item = srcNode->item;
                
				srcNode = srcNode->next;
			}
			destNode->next = NULL;
		}
        
		return *this;
	}
}

linkedstack::~linkedstack()
{
    node * curr = head;
    while(curr)
    {
        head = head->next;
        delete curr;
        curr = head;
    }
}

bool linkedstack::push(const house & aHouse)
{
    node * newNode = new node;
    
    if(!head)
    {
        head = newNode;
        head->item = aHouse;
        head->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        head->item = aHouse;
    }
    
    return true;
}

bool linkedstack::pop(house & aHouse)
{
    if(!head)
        return false;
    else
    {
        node * curr = head;
        
        aHouse = head->item;
        head = head->next;
        delete curr;
    }
    return true;
}

void linkedstack::display()
{
    node * curr = head;
    cout << "Stack contains: " << endl;
    while(curr)
    {
        curr->item.print();
        curr = curr->next;
    }
}

