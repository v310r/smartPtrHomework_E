#include <iostream>
#include "CObject.h"
#include "MyUnique_ptr.h"

int main(){
    MyUnique_ptr smart(new CObject);
    return 0;
}