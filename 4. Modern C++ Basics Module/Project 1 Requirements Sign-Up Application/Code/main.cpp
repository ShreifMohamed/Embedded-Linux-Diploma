/*
    Project Requirements: Sign-Up Application
    we're going to be writing a user registration application.
    This will allow users to register with the system, providing both their name and age,
    and we'll store this information in our own custom type.
    We'll also provide the ability for a user to be looked up by an ID, retrieving their information.

    Once you complete the activity, you should obtain an output similar to the following Figure GUI Project
*/
// Dependcy
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Default Integer Value 
constexpr int DEFAULT = 0 ; 

// Print Function.
void print_msg(const string & msg)
{
    std::cout<<msg;
}
// Option For user
enum class option
{
    Add_Record = 1,
    Fetch_Record = 2,
    Quit = 3
};
// Convert from number to string function
std::string to_string(const option opt)
{
    switch (opt)
    {
    case option::Add_Record:
        return "1. Add Record \n";
        break;
    case option::Fetch_Record:
        return "2. Fetch Record \n";
        break;
    case option::Quit:
        return "3. Quit \n";
        break;
    default:
        break;
    }
    return " ";
}

// Create Class For User
class Person
{
    public:
        // Variables
        std::string userName;
        int userAge = DEFAULT;    
};

// Array Of Record To Store Users Data
std::vector<Person> Records ;

// Add Record Function
void Add_record(std::string& Name , int Age) 
{
    // Create Object From Person 
    Person User;
    User.userName = Name;
    User.userAge = Age;
    Records.push_back(User);
}
// Fetch Record Finction
void Fetch_record(int userdID)
{
    if(userdID < Records.size())
    {
        std::cout << "User Name: " << Records[userdID].userName << "\n" ;
        std::cout << "User Age: " << Records[userdID].userAge << "\n" ;
    }
    else
    {
        print_msg("UserID doesn't Exist \n");
    }
}
// Creat Menu Class
class Menu {
    public:
    std::vector<option> options
             { option::Add_Record, option::Fetch_Record, option::Quit};   
    void show ()
        {
            print_msg("Please select an option: \n");
            // loop over array.
            for( option  op : options )
            {
                // for each option.
                    // print option.
                print_msg( to_string(op));
                print_msg("\n");
            }
            
        }
};
// Overloding operator>> function
std::istream& operator>>(std::istream & input_stream , option & result)
{
    int int_option = DEFAULT;
    input_stream >> int_option; // integer.

    // Convert integer ---> option enum.

    result = static_cast<option>( int_option );  

    return input_stream;  
}

int main()
{
    //a. option.
    option opt = option::Quit ;

    print_msg("User SignUP Application \n\n");

    // Create new object from menu class.
    Menu new_menu ;

    bool is_Running = true ;
    std::string name = " " ;
    int age = DEFAULT ;
    int user_id = DEFAULT ;

    while(is_Running)
        {
            new_menu.show();
            print_msg("Enter option: ");
            std::cin >> opt;
            print_msg("\n");
            
            switch (opt)
            {
            case option::Add_Record:
                print_msg("\nAdd User. Please Enter User Name and Age \n");
                print_msg("UserName: ");
                std::cin.ignore(); // Clear the input buffer
                std::getline(std::cin, name);
                print_msg("UserAge: ");
                std::cin >> age ;
                Add_record(name , age);
                print_msg("\nUser Record Added Successfully\n\n");
                break;
            
            case option::Fetch_Record:
                print_msg("\nPlease Enter User ID\n");
                print_msg("UserID: ");
                std::cin >> user_id ;
                Fetch_record(user_id);
                break;
            
            case option::Quit:
                is_Running = false ;
                break;
            
            default:
                // Do Nothing 
                break;
            }
        }
        return DEFAULT ;
}
