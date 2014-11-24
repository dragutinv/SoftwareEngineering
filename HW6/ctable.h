#ifndef CTABLE_H
#define CTABLE_H

class CTable
{
private:
    int numOfElements;
    int* elements;

    void Quicksort(int low, int high);
public:
    // Constructors
    CTable();
    CTable(int numOfElements);
    // Destructor
    ~CTable();


    void display();

    //manipulation functions
    void setAt(int position, int element);
    int getAt(int position);
    void insertAt(int position, int element);
    void swap(int positionA, int positionB);


    //sorting algorithms
    void BubbleSort();
    void Quicksort();
    void SelectionSort();
    void InsertionSort();
};

#endif // CTABLE_H
