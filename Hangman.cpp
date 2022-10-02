#include<iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
using namespace std;

//function for displaying Hangman
void HangMan(int tries)
{
	cout << endl << endl;
	cout << "  -----" << endl;
	cout << "  |   |" << endl;
	cout << "  |"; if (tries < 5) cout  << "   O    "; cout << endl;
	cout << "  |"; if (tries <= 3) cout << "  /|\\   "; cout << endl;
	cout << "  |"; if (tries <= 1) cout << "  / \\    "; cout << endl;
	cout << "  |" << endl;
	cout << "__|__" << endl;
}

int main()
{
	srand(time(0));  //seeding time into rand function

	//Below string array stores the list of countries to be guessed by the user
	//Program chooses one element using rand function
	string wordList[10] =
	{
		"pakistan",
		"turkey",
		"azerbaijan",
		"malaysia",
		"bangladesh",
		"australia",
		"iran",
		"japan",
		"oman",
		"iraq"
	};

	string word;  //randomly chosen country name is stored here
	string guessed;  //Already guessed letters are stored here

	word = wordList[rand() % 10]; //randomly chosen name is being assigned

	int wordLength = word.length();  //assigning length of secret name to variable
	string dispWord(wordLength, 'X');  //function to display multiple characters

	int found = 0; //variable to store the number of letters found by user
	char guess = ' '; //variable to store the input letter by the user
	int tries = 5; //number of total tries
	int flagFound = 0; //variable for identifing if the user entered wrong input

	while (tries >= 0) //loop will only run if there are enough tries left
	{
		system("cls"); //for clearing the screen
		cout << " Welcome to Hangman Game\n\n Guess a Country Name Or Else The Poor Guy Will Die :(" << endl
			<< endl << " Country Name: ";

		//loop for displaying the secret name in hidden form e.g "xxxx"
		for (int i = 0; i < wordLength; i++)
		{
			cout << " " << dispWord[i];
		}
		cout << endl << endl << endl;

		cout << " Wrong Attempts: " << tries << " / " << 5 << endl;
		cout << " Already Guessed Letters: " << guessed << endl;

		HangMan(tries); //calling the Hangman diplaying function

		//if statement if the user wins
		if (found == wordLength)
		{
			cout << endl;
			cout << "*****************" << endl;
			cout << "**** You Win ****" << endl;
			cout << "*****************" << endl;
			break;
		}

		//if no tries left, the while loop will break
		if (tries == 0)
		{
			break;
		}

		cout << "Guess a Letter: ";
		guess = _getche(); //fetching chracter while displaying it

		//adding the chracters already gussed by the user
		guessed = guessed + " " + guess;

		//identifying wether the guess of the user is true or not
		if (dispWord.find(guess) != string::npos)
		{
			tries++;
		}

		flagFound = 0; //reseting the identifier

		//loop will run if the guess is not already guessed by the user
		for (int i = 0; i < wordLength; i++)
		{
			if (word[i] == guess && dispWord[i] == 'X')
			{
				dispWord[i] = guess;
				found++;
				flagFound = 1;
			}
		}

		//statment to minus the tries if the guess was wrong
		if (!flagFound)
		{
			tries--;
		}
	}//while loop ends here

	//display in case the user fails all the tries
	if (found != wordLength)
	{
		cout << endl;
		cout << "************************" << endl;
		cout << "******* You Lose *******" << endl;
		cout << "*  Please Try Again :( *" << endl;
		cout << "************************" << endl;
	}

	system("pause"); //function for pausing the program
	return 0;
}
