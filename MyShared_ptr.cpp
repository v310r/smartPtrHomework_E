#include "MyShared_ptr.h"
MyShared_ptr::MyShared_ptr(CObject* pointer = nullptr):ptr(pointer),unit(new ControlUnit()){}
MyShared_ptr::MyShared_ptr(const MyShared_ptr& other):ptr(other.ptr),unit(other.unit)
{
    (unit->getCounter())++;
}
MyShared_ptr::~MyShared_ptr()
{
    (unit->getCounter())--;
    if(unit->getCounter() == 0)
    {
        delete unit;
        delete ptr;
    }
}
MyShared_ptr& MyShared_ptr::operator=(const MyShared_ptr& other){
    if(this == &other){return *this;}
    ptr = other.ptr;
    unit = other.unit;
    (unit->getCounter())++;
    return *this;
}
CObject& MyShared_ptr::operator*(){
    return *ptr;
}
CObject* MyShared_ptr::operator->(){
    return ptr;
}
MyShared_ptr::operator bool(){
    return ptr;
}
ControlUnit* MyShared_ptr::getControlUnit(){return unit;}