#include <iostream>
#include "Labs2.h"
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


    //CartesianToPolar(10,5, p, q);
    //cout << "Modulus p is: " << p << " and the angle q is: " << q << endl;

    //IsMultipleOf(21);

    //check  = isPrime(30, 29);
    //if (check) cout << "Prime number!" << endl;
    //else cout << "Not prime number!" << endl;

    //ArraysExample1();

    //PascalTriangleStatic(8);
    PascalTriangleDynamic();

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

void ArraysExample1(){
    int staticArray[10];
    int* dynamicArray = new int[10];

    for (int i=0; i < 10; i++){
        staticArray[i] = i;
        dynamicArray[i] = i;
    }


    for (int i=0; i < 10; i++){
        cout << "Static array, element " << i << " is: " << staticArray[i] << endl;
        cout << "Dynamic array, element " << i << " is: " << dynamicArray[i] << endl;
    }
}

void PascalTriangleStatic(int n){
    int triangle[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j==0) triangle[i][j] = 1;
            else {
                if (i >= 1) triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
                else triangle[i][j] = 0;
            }
        }
    }

    //display matrix
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%3d ", triangle[i][j]);
        }
        cout << endl;
    }
}

void PascalTriangleDynamic(){
    int n;
    int** triangle;
    cout << "Please enter dimension of Pascal triangle: ";
    cin >> n;

    triangle = new int*[n];

    for (int i=0; i < n; i++){
        *(triangle + i) = new int[n];
        for (int j=0; j < n; j++){
            *((triangle + i) + j) = 0;
        }
    }

    //display matrix
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%3d ", triangle[i][j]);
        }
        cout << endl;
    }
}


