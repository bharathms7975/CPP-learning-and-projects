#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void addStudent(string filename, int *studentCount, int *inStateFees, int *outStateFees)
{
     cout << "Press any key to add Students detils";
     getchar();
     ofstream file(filename, ios::app);
     char name[50];
     cout << endl
          << "\n Enter Name of Student : ";
     gets(name);

     file << endl
          << name;

     int state = -1;
     cout << endl
          << "\n Press 1 for In-State or 2 for Out-Of-State : ";
     cin >> state;
}

void generateReport(string filename, int *studentCount, int *inStateFees, int *outStateFees)
{
     return;
}

int main(int argc, char **argv)
{
     int choice = 0;
     string fileName = "tution_report.txt";
     int StudentCount = 0;
     int inStateFees = 0;
     int outStateFees = 0;

     ofstream file(fileName, ios::out);
     file.close();

     while (choice != -1)
     {
          cout << endl
               << "## (College Student Details) ##" << endl;
          cout << endl
               << "1 Add Student Details";
          cout << endl
               << "2 Generate Report";
          cout << endl
               << "-1 Exit";
          cout << "\n\n Enter your choice : ";
          cin >> choice;

          switch (choice)
          {
          case 1:
               addStudent(fileName, &StudentCount, &inStateFees, &outStateFees);
               break;
          case 2:
               generateReport(fileName, &StudentCount, &inStateFees, &outStateFees);
               break;
          case -1:
               cout << endl
                    << "Thank you for using software!!";
               break;
          default:
               cout << endl
                    << "Invalid choice..";
               getchar();
               break;
          }
     }

     return 0;
}