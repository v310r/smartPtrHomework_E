#pragma once
#include "CObject.h"

class MyUnique_ptr
{
private:
    CObject* ptr;
public:
    MyUnique_ptr(CObject* pointer = nullptr);
    MyUnique_ptr(MyUnique_ptr&& other);
    ~MyUnique_ptr();
    MyUnique_ptr(const MyUnique_ptr&) = delete;
    MyUnique_ptr& operator=(const MyUnique_ptr& other) = delete;
    MyUnique_ptr& operator=(MyUnique_ptr&& other);
    CObject& operator*();
    CObject* operator->();
    operator bool();
};