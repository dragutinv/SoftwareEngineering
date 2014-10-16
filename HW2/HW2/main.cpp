#include <iostream>
#include "Labs.h"
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    float p, q;
    bool check;

    //MyFunction1(2,3);
    //MyFunction2(2);
    //ExampleInputOutput();


    CartesianToPolar(10,5, p, q);
    cout << "Modulus p is: " << p << " and the angle q is: " << q << endl;

    //IsMultipleOf(21);

    //check  = isPrime(30, 29);
    //if (check) cout << "Prime number!" << endl;
    //else cout << "Not prime number!" << endl;

    return 0;
}

int MyFunction1 (int a, int b){
    return (a+b+dumvar);
}

void MyFunction2(float x){
    if (x == 0) cout << "x is null" << endl;
    else cout << "x is not null" << endl;
}

void ExampleInputOutput(){
    string name;

    cout << "Please, enter your full name: ";
    getline (std::cin,name);
    cout << "Hello, " << name << "!\n";
}

void CartesianToPolar(int a, int b, float& p, float& q)
{
    p = sqrt (float(a*a + b*b));
    q = atan2 (float(b),float(a)) * 180 / PI;
}

void IsMultipleOf(int p, int q){
    if (p % q > 0) cout << "The number " << p << " is not multiple of number " << q << endl;
    else cout << "The number " << p << " is multiple of number " << q << endl;
}

bool isPrime(int n, int d)
{
    if(n<2)
        return 0;
    if(d == 1)
        return true;
    else
    {
        if(n % d == 0)
            return false;
        else
            return isPrime(n, d - 1);
    }
}
