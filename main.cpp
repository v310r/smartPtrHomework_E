#include <iostream>
#include "MyUnique_ptr.h"
#include "MyShared_ptr.h"

int main(){
    MyUnique_ptr smart1(new CObject);
    MyUnique_ptr smart2(std::move(smart1));
    if(smart1){
        std::cout<<"smart1 is not null\n";
    }
    else{
        std::cout<<"smart1 is null\n";
    }

    MyShared_ptr groupSmart1(new CObject);
    {
        MyShared_ptr groupSmart2(groupSmart1);
        {
            MyShared_ptr groupSmart3(groupSmart2);
            std::cout<<"Amount of shared_ptrs that indicate on obtained resource: "<<groupSmart3.getControlUnit()->getCounter()<<"\n\n";
        }
        std::cout<<"Amount of shared_ptrs that indicate on obtained resource: "<<groupSmart2.getControlUnit()->getCounter()<<"\n\n";
    }
    std::cout<<"Amount of shared_ptrs that indicate on obtained resource: "<<groupSmart1.getControlUnit()->getCounter()<<"\n\n";

    return 0;
}