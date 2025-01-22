// ai_practicals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Generalizer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Letter.h"
#include "PerceptronLearning.h"
#include <locale>



void first_practical(); 
void second_practical(); 

int main()
{
    setlocale(LC_CTYPE, "ukr");
    std::cout << "Hello World!\n";
    second_practical();
}

void second_practical() {

    std::vector<Letter> letters = {
         Letter("Á", {1,1,1,
                      1,0,0,
                      1,1,1,
                      1,0,1,
                      1,1,1}),

         Letter("Â", {1,1,1,
                      1,0,1,
                      1,1,1,
                      1,0,1,
                      1,1,1}),

         Letter("Ã", {1,1,1,
                      1,0,0,
                      1,0,0,
                      1,0,0,
                      1,0,0}),

         Letter("Å", {1,1,1,
                      1,0,0,
                      1,1,1,
                      1,0,0,
                      1,1,1}),

         Letter("Ç", {1,1,1,
                      0,0,1,
                      1,1,1,
                      0,0,1,
                      1,1,1}),

         Letter("Í", {1,0,1,
                      1,0,1,
                      1,1,1,
                      1,0,1,
                      1,0,1}),

         Letter("Î", {1,1,1,
                      1,0,1,
                      1,0,1,
                      1,0,1,
                      1,1,1}),

         Letter("Ï", {1,1,1,
                      1,0,1,
                      1,0,1,
                      1,0,1,
                      1,0,1}),

         Letter("Ð", {1,1,1,
                      1,0,1,
                      1,1,1,
                      1,0,0,
                      1,0,0}),

         Letter("Ñ", {1,1,1,
                      1,0,0,
                      1,0,0,
                      1,0,0,
                      1,1,1}),

         Letter("Ò", {1,1,1,
                      0,1,0,
                      0,1,0,
                      0,1,0,
                      0,1,0}),

         Letter("×", {1,0,1,
                      1,0,1,
                      1,1,1,
                      0,0,1,
                      0,0,1})
    };


    std::vector<Letter> letterP = {
         Letter("Ï0",{1,0,1,
                      1,0,1,
                      1,0,1,
                      1,0,1,
                      1,0,1}),

         Letter("Ï1",{1,1,1,
                      1,0,0,
                      1,0,1,
                      1,0,1,
                      1,0,1}),
         
         Letter("Ï2",{1,1,1,
                      1,0,1,
                      0,0,1,
                      1,0,1,
                      1,0,1}),

         Letter("Ï3",{1,1,1,
                      1,0,1,
                      1,0,1,
                      1,0,1,
                      0,0,1}),

         Letter("Ï4",{0,1,1,
                      1,0,1,
                      1,0,1,
                      1,0,1,
                      1,0,1}),

         Letter("Ï5",{1,1,1,
                      1,0,1,
                      1,0,0,
                      1,0,1,
                      1,0,1}),

    };


    PerceptronLearning perceptron(letters,letters[7].letterName);
    int random_train_ranges[] = { 1000,10000,50000};
    int sequentially_train_ranges[] = { 100,1000 };

    for (int i = 0; i < 3; i++) {
        perceptron.train_random(random_train_ranges[i]);
        perceptron.check();
        perceptron.reset();
    }
    for (int i = 0; i < 2; i++) {
        perceptron.train_sequentially(sequentially_train_ranges[i]);
        perceptron.check();
       
    }

    perceptron.setLetters(letterP);
    perceptron.check();
    
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
            str += ".ptc"; 

            prtcl.open(str, std::ios::out | std::ios::binary);  
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
