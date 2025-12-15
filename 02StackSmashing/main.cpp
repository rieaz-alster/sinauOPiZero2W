#include <iostream>
#include <cstring>

int main() {
    
    while(true)
    {
        char buffer[10];
        strcpy(buffer, "This is a very long string that will overflow the buffer and smash the stack");
        //std::cout << buffer << std::endl;
    }

    return 0;
}
