//
//  linkedstack.h
//  Lab2.260.Rodman
//
//  Created by Nathan Rodman on 5/3/14.
//  Copyright (c) 2014 nathan.rodman. All rights reserved.
//

#ifndef Lab2_260_Rodman_linkedstack_h
#define Lab2_260_Rodman_linkedstack_h

#include "data.h"


class linkedstack
{
public:
    linkedstack();
    linkedstack(const linkedstack & aStack);
    ~linkedstack();
    
    bool push(const house & aHouse);
    bool pop(house & aHouse);
    
    const linkedstack& operator= (const linkedstack & aStack);
    
    void display();
    
private:
    int size;
    struct node
    {
        house item;
        node * next;
    };
    node * head;
};

#endif
