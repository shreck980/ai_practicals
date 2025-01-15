// ai_practicals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Generalizer.h"
#include <iostream>
#include <fstream>
#include <string>



void first_practical(); 

int main()
{
    std::cout << "Hello World!\n";
    first_practical();
}

void first_practical() {

    Generalizer generalizer;

    std::string str;
    char fchoise;
    std::ofstream prtcl; 
    bool leave = false;

    while (!leave) {
        std::cout << "\n(P)rint protocol,(C)reate new one, (L)eave program: ";
        std::cin >> fchoise;
        if (std::tolower(fchoise) == 'p') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::ifstream iprtcl;
            std::cout << "\nEnter a name of your protocol, please: ";
            std::getline(std::cin, str);
            str += ".ptc";
            iprtcl.open(str, std::ios::in | std::ios::binary);

            if (!iprtcl.is_open()) {
                std::cout << "\nFile \"" << str << "\" couldn't be opened for writing.\n";
                std::exit(1);
            }
            else {
                std::cout << "\nFile \"" << str << "\" is opened for protocol.\n";
            }

            std::cout << "\n\n Protocol " << str << ":\n";
            std::string line;
            while (std::getline(iprtcl, line)) {
                std::cout << line << "\n";
            }
            iprtcl.close();

        }
        else if (std::tolower(fchoise) == 'l') {
            leave = true;
        }
        else if (std::tolower(fchoise) == 'c') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nEnter a name of your task, please\n";
            std::getline(std::cin, str);
            str += ".ptc";  // Add file extension

            prtcl.open(str, std::ios::out | std::ios::binary);  // Open file for writing in binary mode
            if (!prtcl.is_open()) {
                std::cout << "\nFile \"" << str << "\" couldn't be opened for writing.\n";
                std::exit(1);
            }
            else {
                std::cout << "\nFile \"" << str << "\" is opened for protocol.\n";
            }

            char choice;
            while (true) {
                std::cout << "(L)earn, (D)isplay, or (Q)uit? ";
                prtcl << "(L)earn, (D)isplay, or (Q)uit? ";
                std::cin >> choice;
                prtcl << " " << choice;

                choice = std::tolower(choice);
                switch (choice) {
                case 'l':
                    generalizer.learn(prtcl);
                    break;
                case 'd':
                    generalizer.display(prtcl);
                    break;
                case 'q':
                    prtcl.close();
                    std::cout << "\nThat is all!\n";
                    std::exit(0);
                    break;
                default:
                    std::cout << "\nInvalid choice! Please choose again.\n";
                }
                std::cout << "\n";
                prtcl << "\n\n";
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
