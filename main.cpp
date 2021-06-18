#include <iostream>
#include "MyUnique_ptr.h"
//#include "MyShared_ptr.h"

int main(){
    MyUnique_ptr smart1(new CObject);
    MyUnique_ptr smart2(std::move(smart1));
    if(smart1){
        std::cout<<"smart1 is not null\n";
    }
    else{
        std::cout<<"smart1 is null\n";
    }

    return 0;
}