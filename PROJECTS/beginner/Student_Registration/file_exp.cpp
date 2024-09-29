#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream file("bharath.txt", ios::out);
    // file.close();
    if (file.is_open())
    {
        file << "This is example file to check\n";
        file << "if the fstream working or not\n";
        file.close();
    }
    else
    {
        cerr << "Unable to open file!!";
    }
}