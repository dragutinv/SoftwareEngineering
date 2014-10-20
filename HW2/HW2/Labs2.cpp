#include <iostream>
#include "Labs2.h"
#include <string>
#include <math.h>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main()
{
    double p, q;
    bool check;
    int a, b;

    a = 3;
    b = 5;

    MyFunction1(2,3);
    MyFunction2(2);
    ExampleInputOutput();

    cout << "Swaping arguments passed by value, a = " << a << ", b = " << b << endl;
    swap_1(a, b);
    cout << "Swaping arguments has no effect! Values of a and b: a = " << a << ", b = " << b << endl << endl;

    cout << "Swaping arguments passed by reference, a = " << a << ", b = " << b << endl;
    swap_2(a, b);
    cout << "Swaping arguments works! Values of a and b: a = " << a << ", b = " << b << endl << endl;

    cout << "Swaping arguments passed as pointers, a = " << a << ", b = " << b << endl;
    swap_3(&a, &b);
    cout << "Swaping values works! Values of a and b: a = " << a << ", b = " << b << endl << endl;


    CartesianToPolar(10,5, p, q);
    cout << "Modulus p is: " << p << " and the angle q is: " << q << endl;

    IsMultipleOf(21);

    check  = isPrime(30, 29);
    if (check) cout << "Prime number!" << endl;
    else cout << "Not prime number!" << endl;

    ArraysExample1();

    PascalTriangleStatic();
    PascalTriangleDynamic();

    MultMatrix();

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

void swap_1(int a, int b) {
    int c;

    c = a;
    a = b;
    b = c;
}

void swap_2(int &a, int &b) {
    int c;

    c = a;
    a = b;
    b = c;
}

void swap_3(int *a, int *b) {
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void CartesianToPolar(int a, int b, double& p, double& q)
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

void PascalTriangleStatic(){
    int n = 5;
    int triangle[5][5];

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
            if (j==0) *(*(triangle + i) + j) = 1;
            else {
                if (i >= 1) *(*(triangle + i) + j) = *(*(triangle + i-1) + j) + *(*(triangle + i-1)+ j-1);
                else *(*(triangle + i) + j) = 0;
            }
        }
    }

    //display matrix
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%3d ", *(*(triangle + i) + j));
        }
        cout << endl;
    }
}

void MultMatrix(){
    int n = 3;
    int s;

    int** matrixA = new int*[n];
    int** matrixB = new int*[n];
    int** matrixC = new int*[n];


    //initialize random 3x3 matrices
    for (int i=0; i < n; i++){
        *(matrixA + i) = new int[n];
        *(matrixB + i) = new int[n];
        for (int j=0; j < n; j++){
            //pick random number between 0 and 10
            *(*(matrixA + i) + j) = rand() % 10 + 1;
            *(*(matrixB + i) + j) = rand() % 10 + 1;
        }
    }

    cout << "Random matrix A: " << endl;

    //display matrix A
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%3d ", *(*(matrixA + i) + j));
        }
        cout << endl;
    }

    cout << "Random matrix B: " << endl;

    //display matrix B
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%3d ", *(*(matrixB + i) + j));
        }
        cout << endl;
    }

    //multiply matrixA and matrixB
    for (int i=0; i < n; i++){
        *(matrixC + i) = new int[n];
        for (int j=0; j < n; j++){
            s = 0;
            for (int k=0; k < n; k++){
                //pick random number between 0 and 10
                s += *(*(matrixA + i) + k) * *(*(matrixB + k) + j);
            }
            *(*(matrixC + i) + j) = s;
        }
    }


     cout << "Result of A x B is matrix: " << endl;

    //display matrix c
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%3d ", *(*(matrixC + i) + j));
        }
        cout << endl;
    }
}


