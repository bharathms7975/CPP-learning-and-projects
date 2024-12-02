#include <iostream> // input & output related modules
#include <cstdlib>  // for rand() and srand() functions
#include <ctime>    // for time module
using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

int main()
{
    clearScreen();
    cout << "\n\t\t Welcome to GuessTheNumber game!\n"
         << endl;
    cout << "You'll have to guess a number between 1 and 100. "
            "You'll have limited choices based on the "
            "level you choose. Good Luck!"
         << endl;

    while (true)
    {
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\n2 for medium!\n3 for difficulty!\n0 for ending the game!\n"
             << endl;

        int difficultyChoice;
        cout << "Enter the number: ";
        cin >> difficultyChoice;

        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerchoice;

        if (difficultyChoice == 1)
        {
            cout << "\n You have 10 choices for finding the secret number between 1 to 100.";
            int choicesLeft = 10;
            for (int i = 1; i <= 10; i++)
            {
                cout << "\nEnter the number: ";
                cin >> playerchoice;

                if (secretNumber == playerchoice)
                {
                    cout << "Well played! You won, " << playerchoice << " is the secret number." << endl;
                    cout << "play the gain again with us!\n\n"
                         << endl;
                    break;
                }
                else
                {
                    cout << "Nope, " << playerchoice << " is not the right number\n";
                    if (playerchoice < secretNumber)
                    {
                        cout << "The number is greater than " << playerchoice << endl;
                    }
                    else
                    {
                        cout << "The number is lesser than " << playerchoice << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left. " << endl;
                    if (choicesLeft == 0)
                    {
                        cout << "You couldn't find the secret number, it was " << secretNumber << ", You lose!!\n\n";
                    }
                }
            }
        }

        else if (difficultyChoice == 2)
        {
            cout << "\n You have 7 choices for finding the secret number between 1 to 100.";
            int choicesLeft = 7;
            for (int i = 1; i <= 7; i++)
            {
                cout << "\nEnter the number: ";
                cin >> playerchoice;

                if (secretNumber == playerchoice)
                {
                    cout << "Well played! You won, " << playerchoice << " is the secret number." << endl;
                    cout << "play the gain again with us!\n\n"
                         << endl;
                    break;
                }
                else
                {
                    cout << "Nope, " << playerchoice << " is not the right number\n";
                    if (playerchoice < secretNumber)
                    {
                        cout << "The number is greater than " << playerchoice << endl;
                    }
                    else
                    {
                        cout << "The number is lesser than " << playerchoice << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left. " << endl;
                    if (choicesLeft == 0)
                    {
                        cout << "You couldn't find the secret number, it was " << secretNumber << ", You lose!!\n\n";
                    }
                }
            }
        }

        else if (difficultyChoice == 3)
        {
            cout << "\n You have 5 choices for finding the secret number between 1 to 100.";
            int choicesLeft = 5;
            for (int i = 1; i <= 5; i++)
            {
                cout << "\nEnter the number: ";
                cin >> playerchoice;

                if (secretNumber == playerchoice)
                {
                    cout << "Well played! You won, " << playerchoice << " is the secret number." << endl;
                    cout << "play the gain again with us!\n\n"
                         << endl;
                    break;
                }
                else
                {
                    cout << "Nope, " << playerchoice << " is not the right number\n";
                    if (playerchoice < secretNumber)
                    {
                        cout << "The number is greater than " << playerchoice << endl;
                    }
                    else
                    {
                        cout << "The number is lesser than " << playerchoice << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left. " << endl;
                    if (choicesLeft == 0)
                    {
                        cout << "You couldn't find the secret number, it was " << secretNumber << ", You lose!!\n\n";
                        cout << "Play the game again to win!!\n\n";
                    }
                }
            }
        }

        else if (difficultyChoice == 0)
        {
            exit(0);
        }
        else
        {
            cout << "Wrong choice, Enter valid choice to play the game! (0,1,2,3)" << endl;
        }
    }
    return 0;
}
