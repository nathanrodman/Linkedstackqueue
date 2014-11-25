//
//  data.cpp
//  Lab2.260.Rodman
//
//  Created by Nathan Rodman on 5/2/14.
//  Copyright (c) 2014 nathan.rodman. All rights reserved.
//

#include "data.h"

house::house(): address(NULL), sqFt(0), bedrooms(0), baths(0), features(NULL)
{
    
}

house::house(const house& aHouse)
{
    char tempadd[100];
    char tempfeat[100];
    
    aHouse.getAddress(tempadd);
    this->address = new char[strlen(tempadd) + 1];
    strcpy(this->address, tempadd);
    
    this->sqFt = aHouse.getSqFt();
    this->bedrooms = aHouse.getBdm();
    this->baths = aHouse.getBath();
    
    aHouse.getFeatures(tempfeat);
    this->address = new char[strlen(tempfeat) + 1];
    strcpy(this->features, tempfeat);
    
}

house::~house()
{
    if(address)
        delete address;
    if(features)
        delete features;
}

void house::getAddress(char * address) const
{
    strcpy(address, this->address);
}

int house::getSqFt() const
{
    return this->sqFt;
}

int house::getBdm() const
{
    return this->bedrooms;
}

float house::getBath() const
{
    return this->baths;
}

void house::getFeatures(char *features) const
{
    strcpy(features, this->features);
}

void house::setAddress(char *address)
{
    if (this->address)
        delete [] this->address;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

void house::setSqFt(int sqFt)
{
    this->sqFt = sqFt;
}

void house::setBdm(int bedrooms)
{
    this->bedrooms = bedrooms;
}

void house::setBath(float baths)
{
    this->baths = baths;
}

void house::setFeatures(char * features)
{
    if (this->features)
        delete [] this->features;
    this->features = new char[strlen(features) + 1];
    strcpy(this->features, features);
}

const house& house::operator=(const house & aHouse)
{
    if(this == &aHouse)
        return *this;
    else
    {
        setAddress(aHouse.address);
        setSqFt(aHouse.sqFt);
        setBdm(aHouse.bedrooms);
        setBath(aHouse.baths);
        setFeatures(aHouse.features);
        return *this;
    }
}

void house::print() const
{
    cout << address << endl;
    cout << sqFt << " sqft" << endl;
    cout << bedrooms << " bedrooms" << endl;
    cout << baths << " baths" << endl;
    cout << "Featuring: " << features << endl;
    cout << '\n';
}
