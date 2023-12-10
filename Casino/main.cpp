#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    system("clear");
    for(;;) {
    
    string userName;
    string userPassword;
    
    int userInput = 0;

    cout << "\t██████╗░██████╗░░█████╗░░░░░░██╗███████╗░█████╗░████████╗  ░█████╗░░█████╗░░██████╗██╗███╗░░██╗░█████╗░\n";
    cout << "\t██╔══██╗██╔══██╗██╔══██╗░░░░░██║██╔════╝██╔══██╗╚══██╔══╝  ██╔══██╗██╔══██╗██╔════╝██║████╗░██║██╔══██╗\n";
    cout << "\t██████╔╝██████╔╝██║░░██║░░░░░██║█████╗░░██║░░╚═╝░░░██║░░░  ██║░░╚═╝███████║╚█████╗░██║██╔██╗██║██║░░██║\n";
    cout << "\t██╔═══╝░██╔══██╗██║░░██║██╗░░██║██╔══╝░░██║░░██╗░░░██║░░░  ██║░░██╗██╔══██║░╚═══██╗██║██║╚████║██║░░██║\n";
    cout << "\t██║░░░░░██║░░██║╚█████╔╝╚█████╔╝███████╗╚█████╔╝░░░██║░░░  ╚█████╔╝██║░░██║██████╔╝██║██║░╚███║╚█████╔╝\n";
    cout << "\t╚═╝░░░░░╚═╝░░╚═╝░╚════╝░░╚════╝░╚══════╝░╚════╝░░░░╚═╝░░░  ░╚════╝░╚═╝░░╚═╝╚═════╝░╚═╝╚═╝░░╚══╝░╚════╝░\n";


    cout << "[1]Sign up\n[2]Sign in\n[3]Exit\n\nInput: "; cin >> userInput;

    if(userInput == 1)
    {
        system("clear");
        cout << "User_Name: "; cin >> userName;
        cout << "Password: "; cin >> userPassword;

        std::ofstream out("dataUser.txt");
        if(out.is_open())
        {
            out << userName << endl << userPassword;
        }

        out.close();

        cout << "You registered\n\n\n\n";
    }

    else if(userInput == 2)
    {
        system("clear");
        cout << "User_Name: "; cin >> userName;
        cout << "Password: "; cin >> userPassword;

        string lineFirst;
        string lineSecond;

        std::ifstream in("dataUser.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            while ((std::getline(in, lineFirst)) && (std::getline(in, lineSecond))) 
            {
                if(lineFirst == userName && lineSecond == userPassword) cout << "You logined\n\n\n\n";
    	           else { cout << "Error\n"; return 0; }
            }
        }
        in.close();     // закрываем файл

        char checkBalance;
        cout << "You want to check your balance: [y]es, [n]o: "; cin >> checkBalance;

        if(checkBalance == 'y')
        {
            string lineBalance;
            std::ifstream inBalance("balance.txt");

            if(inBalance.is_open())
            {
                while(std::getline(inBalance, lineBalance)) 
                {
                    cout << "Your balance: " << lineBalance << "\n\n\n\n";
                }
            }

            inBalance.close();
        }

        else{

        char choice;
        cout << "You want to play in casino [y]es, [n]o: "; cin >> choice;

        if(choice == 'y')
        {
            srand(time(NULL));
            int random = rand() % 2;
            int balance = 0;

            std::ofstream out("balance.txt");
            if(out.is_open())
            {
                if(random == 0)
                { 
                    cout << "\n██╗░░░░░░█████╗░░██████╗████████╗\n██║░░░░░██╔══██╗██╔════╝╚══██╔══╝\n██║░░░░░██║░░██║╚█████╗░░░░██║░░░\n██║░░░░░██║░░██║░╚═══██╗░░░██║░░░\n███████╗╚█████╔╝██████╔╝░░░██║░░░\n╚══════╝░╚════╝░╚═════╝░░░░╚═╝░░░\n\n\n\n";

                    balance -= 100; 
                    out << balance << endl; 
                } 
                else if(random == 1)
                {
                    cout << "\n░██╗░░░░░░░██╗██╗███╗░░██╗███╗░░██╗███████╗██████╗░\n░██║░░██╗░░██║██║████╗░██║████╗░██║██╔════╝██╔══██╗\n░╚██╗████╗██╔╝██║██╔██╗██║██╔██╗██║█████╗░░██████╔╝\n░░████╔═████║░██║██║╚████║██║╚████║██╔══╝░░██╔══██╗\n░░╚██╔╝░╚██╔╝░██║██║░╚███║██║░╚███║███████╗██║░░██║\n░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚══╝╚══════╝╚═╝░░╚═╝\n\n\n\n";
                   
                    balance += 100;
                    out << balance << endl; 
                }
                
                else if(random == 2)
                {
                    cout << "\n██████╗░░█████╗░██╗░░░██╗██████╗░██╗░░░░░███████╗  ░██╗░░░░░░░██╗██╗███╗░░██╗███╗░░██╗███╗░░██╗███████╗██████╗░\n██╔══██╗██╔══██╗██║░░░██║██╔══██╗██║░░░░░██╔════╝  ░██║░░██╗░░██║██║████╗░██║████╗░██║████╗░██║██╔════╝██╔══██╗\n██║░░██║██║░░██║██║░░░██║██████╦╝██║░░░░░█████╗░░  ░╚██╗████╗██╔╝██║██╔██╗██║██╔██╗██║██╔██╗██║█████╗░░██████╔╝\n██║░░██║██║░░██║██║░░░██║██╔══██╗██║░░░░░██╔══╝░░  ░░████╔═████║░██║██║╚████║██║╚████║██║╚████║██╔══╝░░██╔══██╗\n██████╔╝╚█████╔╝╚██████╔╝██████╦╝███████╗███████╗  ░░╚██╔╝░╚██╔╝░██║██║░╚███║██║░╚███║██║░╚███║███████╗██║░░██║\n╚═════╝░░╚════╝░░╚═════╝░╚═════╝░╚══════╝╚══════╝  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚══╝╚═╝░░╚══╝╚══════╝╚═╝░░╚═╝\n\n\n\n"; 
                    balance += 300; 
                    out << balance << endl; 
                }
            }
            
            out.close();
        }

        else if(choice == 'n') { cout << "Ok.!\n"; return 0; }
        
        }
    }

    else if(userInput == 3) { cout << "Exit\n"; return 0; }

    else { cout << "Error\n"; return 0; }
    }
}
