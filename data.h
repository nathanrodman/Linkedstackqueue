//
//  data.h
//  Lab2.260.Rodman
//
//  Created by Nathan Rodman on 5/2/14.
//  Copyright (c) 2014 nathan.rodman. All rights reserved.
//

#ifndef Lab2_260_Rodman_data_h
#define Lab2_260_Rodman_data_h

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;


class house
{
public:
    house();
    house(const house& aHouse);
    ~house();
    
    const house& operator=(const house & aHouse);
    
    
    void getAddress(char * address) const;
    int getSqFt() const;
    int getBdm() const;
    float getBath() const;
    void getFeatures(char * features) const;
    
    void setAddress(char * address);
    void setSqFt(int sqFt);
    void setBdm(int bedrooms);
    void setBath(float baths);
    void setFeatures(char * features);
    
    void print() const;
    
private:
    char * address;
    int sqFt;
    int bedrooms;
    float baths;
    char * features;
    
};

#endif
