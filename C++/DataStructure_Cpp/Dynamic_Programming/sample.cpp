#include <iostream>

int main(int argc, char* argv[])
{
    std::cout<<"hello world\n";
    for(int i = 0; i < 5; i++){
        std::cout<<argv[i]<<std::endl;
    }
}
