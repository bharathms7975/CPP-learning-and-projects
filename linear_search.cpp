#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int target)
{

    if (n == 0)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int target = 7;
    if (linearSearch(arr, n, target))
    {
        cout << "target found" << endl;
    }
    else
    {
        cout << "target not in array" << endl;
    }
}