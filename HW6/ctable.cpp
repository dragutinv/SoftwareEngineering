#include <iostream>
#include "ctable.h"
#include <cstdlib>

using namespace std;

//empty constructor
CTable::CTable(){
    this->numOfElements = 0;
}

//constructor
CTable::CTable(int numOfElements){
    this->numOfElements = numOfElements;

    this->elements = new int[this->numOfElements];

    for (int i=0; i<this->numOfElements; i++){
        //pick random number between 0 and 100000
        this->elements[i] = rand() % 100000 + 1;
    }
}

//destructor
CTable::~CTable(){
    delete[] this->elements;
}

//display elements of array
void CTable::display(){
    cout << endl << "Elements of CTable: " << endl << endl;

    for (int i=0; i < this->numOfElements; i++){
        cout << this->elements[i] << " ";
    }
    cout << endl << endl;
}

//set value
void CTable::setAt(int position, int element){
    if (position < this->numOfElements)
        this->elements[position] = element;
}

//get value
int CTable::getAt(int position){
    if (position < this->numOfElements)
        return this->elements[position];
    else return -1;
}

//insert value
void CTable::insertAt(int position, int element){
    //@todo: find better solution, this one takes a lot of memory
    cout << "Insert element: " << element << " at position: " << position << endl;

    int* newArray = new int[this->numOfElements + 1];
    int j = 0;

    //increase number of elements
    this->numOfElements++;

    //copy previous values to new array
    for (int i=0; i < this->numOfElements; i++){
        if (i != position) {
            newArray[i] = this->elements[j];
            j++;
        }
        else newArray[i] = element;
    }


    //release memory
    delete[] this->elements;
    this->elements = newArray;
}

void CTable::swap(int positionA, int positionB){
    //cout << "Swap element " << positionA << " with " << positionB << endl;

    if (positionA < this->numOfElements && positionB < this->numOfElements){
        int tmp = this->elements[positionA];
        this->elements[positionA] = this->elements[positionB];
        this->elements[positionB] = tmp;
    }
}

//bubble sort implementation
void CTable::BubbleSort(){
    cout << "Start Bubble Sort" << endl;

    for (int i=0; i < this->numOfElements; i++){
        for (int j=i+1; j < this->numOfElements; j++){
            if (this->elements[i] > this->elements[j]) swap(i, j);
        }
    }
}

//quick sort implementation

//COMPLEXITY: Fast, recursive, non-stable sort algorithm which works by the divide and conquer principle.
//Quicksort will in the best case divide the array into almost two identical parts.
//It the array contains n elements then the first run will need O(n).
//Sorting the remaining two sub-arrays takes 2* O(n/2). This ends up in a performance of O(n log n).
//In the worst case quicksort selects only one element in each iteration.
//So it is O(n) + O(n-1) + (On-2).. O(1) which is equal to O(n^2).
//The average case of quicksort is O(n log n).

void CTable::Quicksort(int low, int high){
    //initial position
    int i = low, j = high;

    int pivot = this->elements[low + (high-low)/2];

    // Divide into two parts
    while (i <= j) {
        // If the current value from the left list is smaller then the pivot
        // element then get the next element from the left list
        while (this->elements[i] < pivot) {
            i++;
        }
        // If the current value from the right list is larger then the pivot
        // element then get the next element from the right list
        while (this->elements[j] > pivot) {
            j--;
        }

        // If we have found a values in the left list which is larger then
        // the pivot element and if we have found a value in the right list
        // which is smaller then the pivot element then we exchange the
        // values.
        // As we are done we can increase i and j
        if (i <= j) {
            swap(i, j);
            i++;
            j--;
        }
    }
    // Recursion
    if (low < j)
        this->Quicksort(low, j);
    if (i < high)
        this->Quicksort(i, high);
}

void CTable::Quicksort(){
    cout << "Perform Quick Sort" << endl;

    this->Quicksort(0, this->numOfElements);
}

//insertion sort implementation
void CTable::InsertionSort(){
    cout << "Start Insertion Sort" << endl;

    int i, j, key;

    for (j = 1; j < this->numOfElements; j++){
        key = this->elements[j];
        for(i = j-1; (i >= 0) && (this->elements[i] > key); i--){   // Smaller values are moving up
            this->elements[i+1] = this->elements[i];
        }
        this->elements[i+1] = key;    // Put the key in its proper location
    }
}

//selection sort implementation
void CTable::SelectionSort(){
    cout << "Start Selection Sort" << endl;

    int i, j, first, temp;
    for ( i = this->numOfElements-1; i > 0; i--)
    {
        first = 0;   //initialize first element
        for(j = 1; j <= i; j ++)   //locate smallest element between positions 1 and i.
        {
            if( this->elements[j] > this->elements[first] )
                first = j;
        }
        temp = this->elements[first];   //swap smallest found with element in position i.
        this->elements[first] = this->elements[i];
        this->elements[i] = temp;
    }
}
