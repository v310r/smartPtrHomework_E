#pragma once

class CObject
{
public:
    CObject();
    virtual ~CObject();
    CObject(const CObject& other);
    CObject(const CObject&& other);
    CObject& operator=(const CObject& other);
    CObject& operator=(CObject&& other);
};