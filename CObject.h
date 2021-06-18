#pragma once

class CObject
{
public:
    CObject(){};
    virtual ~CObject(){};
    CObject(const CObject& other){};
    CObject(const CObject&& other){};
    //virtual CObject& operator=(const CObject& other);
    //virtual CObject& operator=(CObject&& other);
};