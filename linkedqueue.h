//
//  linkedqueue.h
//  Lab2.260.Rodman
//
//  Created by Nathan Rodman on 5/2/14.
//  Copyright (c) 2014 nathan.rodman. All rights reserved.
//

#ifndef Lab2_260_Rodman_linkedqueue_h
#define Lab2_260_Rodman_linkedqueue_h
#include "data.h"


class linkedqueue
{
public:
    linkedqueue();
    linkedqueue(const char * fileName);
    linkedqueue(const linkedqueue & aQueue);
    ~linkedqueue();
    
    bool enqueue(const house & aHouse);
    bool dequeue(house & aHouse);
    void display() const;
    
    const linkedqueue& operator= (const linkedqueue & aQueue);
private:
    int size;
    
    struct node
    {
        house item;
        node * next;
    };
    
    node * front;
    node * rear;
};


#endif
