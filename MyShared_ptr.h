#pragma once
#include "CObject.h"

class ControlUnit
{
private:
    int counter;
public:
    ControlUnit():counter(1){}
    int& getCounter(){return counter;}
};



class MyShared_ptr
{
private:
    ControlUnit* unit;
    CObject* ptr;
public:
    MyShared_ptr(CObject* pointer);
    MyShared_ptr(const MyShared_ptr& other);
    ~MyShared_ptr();
    ControlUnit* getControlUnit();
    MyShared_ptr& operator=(const MyShared_ptr& other);
    CObject& operator*();
    CObject* operator->();
    operator bool();
};