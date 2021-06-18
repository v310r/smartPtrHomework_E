#include "MyUnique_ptr.h"
MyUnique_ptr::MyUnique_ptr(CObject* pointer = nullptr):ptr(pointer)
{

}
MyUnique_ptr::MyUnique_ptr(MyUnique_ptr&& other): ptr(other.ptr)
{
    other.ptr = nullptr;
}
MyUnique_ptr::~MyUnique_ptr()
{
    delete ptr;
}
MyUnique_ptr& MyUnique_ptr::operator=(MyUnique_ptr&& other){
    if(this == &other){return *this;}
    delete ptr;
    ptr = other.ptr;
    other.ptr = nullptr;
    return *this;
}
CObject& MyUnique_ptr::operator*(){
    return *ptr;
}
CObject* MyUnique_ptr::operator->(){
    return ptr;
}
MyUnique_ptr::operator bool(){
    return ptr;
}