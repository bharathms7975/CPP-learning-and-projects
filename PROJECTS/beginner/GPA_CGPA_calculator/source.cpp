#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;

// Function Prototypes
void clearScreen();
void printHeader(const string &title);
void calculateGPA();
void calculateCGPA();
void displayMethod();
void exitApplication();
float inputValidation(const string &prompt);

int main()
{
    while (true)
    {
        clearScreen();
        printHeader("GPA & CGPA Calculator");

        cout << "1. Calculate GPA\n";
        cout << "2. Calculate CGPA\n";
        cout << "3. How GPA & CGPA are calculated\n";
        cout << "4. Exit\n";
        cout << "\nEnter yout Choice: ";

        int choice = static_cast<int>(inputValidation(""));

        switch (choice)
        {
        case 1:
            calculateGPA();
            break;
        case 2:
            calculateCGPA();
            break;
        case 3:
            displayMethod();
            break;
        case 4:
            exitApplication();
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option\n";
            break;
        }

        cout << "\n Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void printHeader(const string &title)
{
    cout << setw(50) << setfill('-') << "\n";
    cout << setw((50 + title.length()) / 2) << setfill(' ') << title << "\n";
    cout << setw(50) << setfill('-') << "\n\n";
}

void calculateGPA()
{
    clearScreen();
    printHeader("GPA Calculation");

    int numSubjects = static_cast<int>(inputValidation("Enter the number of subjects: "));
    vector<float> credits(numSubjects), grades(numSubjects);
    float totalCredits = 0, weightedSum = 0;

    for (int i = 0; i < numSubjects; i++)
    {
        stringstream ss;

        ss << "Enter credit hours for subjects " << i + 1 << ": ";
        credits[i] = inputValidation(ss.str());

        ss.str("");
        ss.clear();
        ss << "Enter grade (point) for subject " << i + 1 << ": ";
        grades[i] = inputValidation(ss.str());

        weightedSum += credits[i] * grades[i];
        totalCredits += credits[i];
    }

    cout << "Your GPA is: " << setprecision(2) << fixed << weightedSum / totalCredits << endl;
}

void calculateCGPA()
{
    clearScreen();
    printHeader("CGPA Calculator");

    int numSemesters = static_cast<int>(inputValidation("Enter the number of semesters: "));
    float sumGPA = 0;

    for (int i = 0; i < numSemesters; i++)
    {
        stringstream ss;
        ss << "Enter GPA for semester " << i + 1 << ": ";
        sumGPA += inputValidation(ss.str());
    }

    cout << "Your CGPA is: " << setprecision(2) << fixed << sumGPA / numSemesters << endl;
}

void displayMethod()
{
    clearScreen();
    printHeader("Calculation Method");
    cout << "GPA is calculated as the sum of (credit hours * grade points) for all subjects, dived by the credit hours.\n";
    cout << "CGPA is the average of GPA calculated across all the semesters.\n\n";
}

void exitApplication()
{
    clearScreen();
    cout << "Thank you for using GPA & CGPA Calculator. Goodbye!\n\n";
}

float inputValidation(const string &prompt)
{
    float input;
    if (!prompt.empty())
        cout << prompt;
    while (!(cin >> input) || input < 0)
    {
        cout << "Invalid input, Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}