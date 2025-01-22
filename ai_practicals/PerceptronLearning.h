#include "Letter.h"
#include <vector>
#pragma once
class PerceptronLearning
{

public:
	std::vector<Letter> letters;
	std::vector<float> weights;
	const char targetLetter;
	int bias;

	PerceptronLearning(std::vector<Letter> letters,const char target)
		:letters(letters),targetLetter(target)
	{
		for (int i = 0; i < 15; i++) {
			weights.push_back(0);
		}

		bias = calculate_bias();
	}

	~PerceptronLearning();
	void reset();
	bool proceed(const Letter& l);
	void decrease(const Letter& l);
	void increase(const Letter& l);
	void train_random(size_t range);
	void train_sequentially(size_t range);
	void check();
	int calculate_bias();
	
};

