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
    MyShared_ptr(CObject* pointer):ptr(pointer),unit(new ControlUnit()){}
    MyShared_ptr(const MyShared_ptr& other):ptr(other.ptr),unit(other.unit)
    {
        (unit->getCounter())++;
    }
    ~MyShared_ptr()
    {
        (unit->getCounter())--;
        if(unit->getCounter() == 0)
        {
            delete unit;
            delete ptr;
        }
    }
    MyShared_ptr& operator=(const MyShared_ptr& other){
        if(this == &other){return *this;}
        ptr = other.ptr;
        unit = other.unit;
        (unit->getCounter())++;
        return *this;
    }
CObject& operator*(){
    return *ptr;
}
CObject* operator->(){
    return ptr;
}
operator bool(){
    return ptr;
}
};