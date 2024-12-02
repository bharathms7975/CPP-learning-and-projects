#include <iostream>
using namespace std;

void NewRegister();
bool validFirstname(string);
bool validLastname(string);
bool validEmail(string);
bool validPassword(string);
void VerificationCode();
void Login();

int main()
{
    cout << "Hey.." << endl;
    cout << "Welcome to our website!" << endl;
    cout << "Let's begin our journey..." << endl;

    NewRegister();

    return 0;
}