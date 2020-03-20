//Keywords II
//Author: Zack Driscoll

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

void WordOne(const int MAX_WRONG, const string THE_WORD1, int& wrong, string soFar1, string used);
void WordTwo(const int MAX_WRONG, const string THE_WORD2, int& wrong, string soFar2, string used);
void WordThree(const int MAX_WRONG, const string THE_WORD3, int& wrong, string soFar3, string used);

void Shutdown(const int MAX_WRONG, int& wrong, string THE_WORD1, string THE_WORD2, string THE_WORD3);


int main()
{
	//Maximum number of incorrect guesses allowed
	const int MAX_WRONG = 8;

	int numWords = 0;

	//Collection of possible words to guess
	vector<string> words;
	words.push_back("CLUE");
	words.push_back("GUESS");
	words.push_back("BREAKER");
	words.push_back("CODE");
	words.push_back("SECRET");
	words.push_back("DISGUISE");
	words.push_back("WEAPON");
	words.push_back("SUIT");
	words.push_back("VEHICLE");
	words.push_back("TRAVEL");

	//Generate 3 words at random from the list
	//Note: Had issue making it choose 3 different words. Currently does the same word 3 times.
	while (numWords < 3)
	{
		srand(static_cast<unsigned int>((time(0))));
		random_shuffle(words.begin(), words.end());

		numWords++;
	}	

	//Words to guess
	const string THE_WORD1 = words[0];
	const string THE_WORD2 = words[0];
	const string THE_WORD3 = words[0];
	
	//Number of incorrect guesses
	int wrong = 0;

	//Words guessed so far
	string soFar1(THE_WORD1.size(), '-');
	string soFar2(THE_WORD2.size(), '-');
	string soFar3(THE_WORD3.size(), '-');

	//Letters guessed
	string used = "";

	cout << "\n\n\t *** Welcome to KeywordsII. Guess the three word code phrase. Good luck! *** \n";

	//Run the functions to guess each word
	WordOne(MAX_WRONG, THE_WORD1, wrong, soFar1, used);
	WordTwo(MAX_WRONG, THE_WORD2, wrong, soFar2, used);
	WordThree(MAX_WRONG, THE_WORD3, wrong, soFar3, used);

	Shutdown(MAX_WRONG, wrong, THE_WORD1, THE_WORD2, THE_WORD3);

	return 0;
}

void WordOne(const int MAX_WRONG, const string THE_WORD1, int& wrong, string soFar1, string used)
{
	//Loop for the first word
	while ((wrong < MAX_WRONG) && (soFar1 != THE_WORD1))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar1 << endl;

		//Get the player's guess
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;

		//Make uppercase since the secret word is in uppercase
		guess = toupper(guess);

		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD1.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";

			//Update soFar to include newly guessed letter.
			for (int i = 0; i < THE_WORD1.length(); i++)
			{
				if (THE_WORD1[i] == guess)
				{
					soFar1[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't in the word.\n";
			wrong++;
		}
	}
}

void WordTwo(const int MAX_WRONG, const string THE_WORD2, int& wrong, string soFar2, string used)
{
	//Loop for the first word
	while ((wrong < MAX_WRONG) && (soFar2 != THE_WORD2))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar2 << endl;

		//Get the player's guess
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;

		//Make uppercase since the secret word is in uppercase
		guess = toupper(guess);

		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD2.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";

			//Update soFar to include newly guessed letter.
			for (int i = 0; i < THE_WORD2.length(); i++)
			{
				if (THE_WORD2[i] == guess)
				{
					soFar2[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't in the word.\n";
			wrong++;
		}
	}
}

void WordThree(const int MAX_WRONG, const string THE_WORD3, int& wrong, string soFar3, string used)
{
	//Loop for the first word
	while ((wrong < MAX_WRONG) && (soFar3 != THE_WORD3))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar3 << endl;

		//Get the player's guess
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;

		//Make uppercase since the secret word is in uppercase
		guess = toupper(guess);

		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD3.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";

			//Update soFar to include newly guessed letter.
			for (int i = 0; i < THE_WORD3.length(); i++)
			{
				if (THE_WORD3[i] == guess)
				{
					soFar3[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't in the word.\n";
			wrong++;
		}
	}
}

void Shutdown(const int MAX_WRONG, int& wrong, string THE_WORD1, string THE_WORD2, string THE_WORD3)
{
	//Shutdown
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou've been hanged!";
	}
	else
	{
		cout << "\nYou guessed it!";
	}

	cout << "\nThe words were " << THE_WORD1 << " " << THE_WORD2 << " " << THE_WORD3 << endl;
}