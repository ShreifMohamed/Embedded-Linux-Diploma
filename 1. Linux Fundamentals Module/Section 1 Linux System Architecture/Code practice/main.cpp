#include <iostream>

// include Glibc library
#include <unisted.h>
#include <sys/types.h>

using namespace std;


/*
    The application give us the :
                                    * User  id
                                    * User name
*/

int main()
{
    auto USERID = getuid();
    auto Name = getlogin();

    std::cout << "User ID: " << USERID << "User name: " << Name << "\n";
    
    return 0;
}