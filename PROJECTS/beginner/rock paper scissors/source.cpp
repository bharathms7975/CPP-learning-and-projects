#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
#include <sstream>

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

char inputValidation(const string &prompt)
{
    char input;
    if (!prompt.empty())
        cout << prompt;
    while (!(cin >> input) || (input != 'r' && input != 'p' && input != 's' && input != 'e'))
    {
        cout << "Invalid input, Please enter ('r' or 'p' or 's'): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

void printHeader(const string &title)
{
    cout << setw(50) << setfill('-') << "\n";
    cout << setw((50 + title.length()) / 2) << setfill(' ') << title << "\n";
    cout << setw(51) << setfill('-') << "\n\n";
}

char getComputerOption()
{
    srand(time(0));
    // Random number
    int num = rand() % 3 + 1;

    if (num == 1)
        return 'r';
    if (num == 2)
        return 'p';
    if (num == 3)
        return 's';
}

void exitApplication()
{
    clearScreen();
    cout << "Thank you for using Rock Paper Scissors game. Goodbye!\n\n";
}

void choosewinner(char uChoice)
{
    char cChoice = getComputerOption();

    if (uChoice == ROCK && cChoice == PAPER)
    {
        cout << "Computer Wins! Paper wraps Rock." << endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS)
    {
        cout << "Computer Wins! Scissors cut Paper." << endl;
    }
    else if (uChoice == SCISSORS && cChoice == ROCK)
    {
        cout << "Computer Wins! Rock smashes Scissors." << endl;
    }
    else if (uChoice == ROCK && cChoice == SCISSORS)
    {
        cout << "You Win! Paper wraps Rock." << endl;
    }
    else if (uChoice == PAPER && cChoice == ROCK)
    {
        cout << "You Win! Paper wraps Rock." << endl;
    }
    else if (uChoice == SCISSORS && cChoice == PAPER)
    {
        cout << "You Win! Scissors cut Paper." << endl;
    }
    else
    {
        cout << "Tie. Play again win the Game." << endl;
    }
}

int main()
{
    clearScreen();
    printHeader("Rock Paper Scissors");

    while (true)
    {
        clearScreen();
        printHeader("Rock Paper Scissors");

        cout << "(r) for Rock\n";
        cout << "(p) for Paper\n";
        cout << "(s) for Scissors\n";
        cout << "(e) for Exit\n";
        cout << "\nEnter yout Choice: ";

        char choice = static_cast<char>(inputValidation(""));

        switch (choice)
        {
        case 'r':
            choosewinner('r');
            break;
        case 'p':
            choosewinner('p');
            break;
        case 's':
            choosewinner('s');
            break;
        case 'e':
            exitApplication();
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option\n";
            break;
        }

        cout << " Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}