#include <bits/stdc++.h>

using namespace std;

class BigInt
{
    string digits;

public:
    // constructor
    BigInt(unsigned long long n = 0); // done
    BigInt(string &);                 // done
    BigInt(const char *);             // done
    BigInt(BigInt &);                 // done

    // Helper Functions
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);  // done
    friend int Length(const BigInt &); // done
    int operator[](const int) const;   // done

    // operator Overloading //

    // Direct assignment
    BigInt &operator=(const BigInt &);

    // Post/pre - Incrementation

    BigInt &operator++();        // pre increment
    BigInt operator++(int temp); // post increment
    BigInt &operator--();        // pre decrement
    BigInt operator--(int temp); // post decrement

    // Addition and subraction
    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);

    // Comparision operators
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);

    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);

    // Multiplication and Division
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);

    // Modulo
    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);

    // Power Function
    friend BigInt &operator^=(BigInt &, const BigInt &);
    friend BigInt operator^(BigInt &, const BigInt &);

    // Square Root Function
    friend BigInt sqrt(BigInt &a);

    // Read and write
    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt factorial(int n);
};

BigInt::BigInt(string &s)
{
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(const char *s)
{
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(unsigned long long nr)
{
    do
    {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}

// copy constructor for copying same data from same object
BigInt::BigInt(BigInt &a)
{
    digits = a.digits;
}

// Checks if number is 0 or null
bool Null(const BigInt &a)
{
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}

// returns length of the integer
int Length(const BigInt &a)
{
    return a.digits.size();
}

// for accessing digit in a number using index
int BigInt::operator[](const int index) const
{
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}

// Comparision operator overloading
bool operator==(const BigInt &a, const BigInt &b)
{
    return a.digits == b.digits;
}

bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b); // utilizing == operator function implemented earlier
}

bool operator<(const BigInt &a, const BigInt &b)
{
    int n = Length(a), m = Length(b);
    if (n != m)
    {
        return n < m;
    }
    while (n--)
    {
        if (a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    }
    return false;
}

bool operator>(const BigInt &a, const BigInt &b)
{
    return b < a; // we are using predefined < operator function
}

bool operator>=(const BigInt &a, const BigInt &b)
{
    return !(a < b); // since it means not less than so obviously it will be either == or >
}

bool operator<=(const BigInt &a, const BigInt &b)
{
    return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a)
{
    digits = a.digits;
    return *this;
}
