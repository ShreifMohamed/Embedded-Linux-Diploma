#include <iostream>

// include Glibc library
#include <unisted.h>
#include <sys/types.h>

using namespace std;


/*
    The application give us the :
    * User process id
    * Parent process id
    * Child process id
*/

int main()
{
    auto CHPID = getpid();
    auto PPID = getppid();
    auto USERID = getuid();

    // Get the child process id
    auto child_id = fork();
    if(child_id == 0)
    {
        sleep(50);
    }
    else
    {
        std::cout << "User ID: " << USERID << "\n";
        std::cout << "Parent process ID: " << PPID << "\n";
        std::cout << "Child process ID: " << CHPID << "\n";
        sleep(50);
    }
    return 0;
}