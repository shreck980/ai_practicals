#include "PerceptronLearning.h"
#include <cstdlib>  
#include <ctime>
#include <iostream>

PerceptronLearning::~PerceptronLearning()
{

}

void PerceptronLearning::reset()
{
    weights.clear();
    for (int i = 0; i < 15; i++) {
        weights.push_back(0);
    }
}

bool PerceptronLearning::proceed(const Letter& l)
{

	float net = 0.0;
	for (int i = 0; i < 15;i++) {
		net += l.letterCode[i] * weights[i];
	}
    return net >= (float)bias;
}

void PerceptronLearning::decrease(const Letter& l)
{

    for (int i = 0; i < 15; i++) {
        if (l.letterCode[i] == 1) {
            weights[i] -= 1;
        }
    }
}

void PerceptronLearning::increase(const Letter& l)
{
    for (int i = 0; i < 15; i++) {
        if (l.letterCode[i] == 1) {
            weights[i] += 1;
        }
    }
}
void PerceptronLearning::train_sequentially(size_t range) {
    
    size_t letterCount = letters.size();
    std::cout << "Training sequentially with " << range*letterCount << " iterations...\n";
    
    for (size_t i = 0; i < range; i++) {

        for (int j = 0; j < letterCount; j++) {
            if (letters[j].letterName != targetLetter) {
                if (proceed(letters[j])) {
                    decrease(letters[j]);
                }
            }
            else {

                if (!proceed(letters[j])) {
                    increase(letters[j]);
                }
            }
        }
    }
}

void PerceptronLearning::train_random(size_t range)
{
    std::cout << "Training random with " << range << " iterations...\n";
    srand(time(0));
    for (size_t i = 0; i < range; i++) {
        int option = rand() % 12;

        if (letters[option].letterName != targetLetter) {
            if (proceed(letters[option])) {
                decrease(letters[option]);
            }
        }
        else {
            
            if (!proceed(letters[option])) {
                increase(letters[option]);
            }
        }
    }
}

void PerceptronLearning::check()
{
    std::cout << "Weights:\n";
    for (float w : weights) {
        std::cout << w << "  ";
    }
    std::cout << "\nResults:\n";
    for (Letter letter : letters) {
        std::cout << letter.letterName << " is "<<targetLetter<<"? " << proceed(letter) << "\n";
    }

}

int PerceptronLearning::calculate_bias()
{
    std::vector<float> net_e;
    std::vector<float> net_other;
    float net = 0;

    for (Letter l : letters) {

        for (size_t i = 0; i < weights.size(); i++) {
            net += l.letterCode[i] * weights[i];
        }

       
        if (l.letterName == targetLetter) {
            net_e.push_back(net);  
        }
        else {
            net_other.push_back(net);  
        }
    }

  
    float mean_e = 0, mean_other = 0;

    for (float val : net_e) {
        mean_e += val;
    }
    mean_e /= net_e.size();

    for (float val : net_other) {
        mean_other += val;
    }
    mean_other /= net_other.size();

    
    return static_cast<int>((mean_e + mean_other) / 2);
}

void PerceptronLearning::setLetters(std::vector<Letter> letters)
{
    this->letters.clear();

    for (int i = 0; i < letters.size(); i++) {
        this->letters.push_back(letters[i]);
    }

    
}

