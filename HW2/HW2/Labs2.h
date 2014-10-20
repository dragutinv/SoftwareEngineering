#define PI 3.14159265
int dumvar = 3;

int MyFunction1(int, int);
void MyFunction2(float);

//play with string functions
void ExampleInputOutput();

//swap values of arguments pased by value
void swap_1(int, int);

//swap values of arguments passed by refference
void swap_2(int&, int&);

//swap values of arguments passed by pointers
void swap_3(int*, int*);

//transfort catesian value to polar
void CartesianToPolar(int, int, double&, double&);

//check if number is multiple of number q
void IsMultipleOf(int, int q = 2);

//check is number is prime (e.g.: 1, 3, 5..)
bool isPrime(int, int);

//play with arrays
void ArraysExample1();

//play with static matrices
void PascalTriangleStatic();

//play with dynamic allocation
void PascalTriangleDynamic();

//play with two matrices
void MultMatrix();
