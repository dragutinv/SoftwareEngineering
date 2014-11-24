#include <iostream>
#include "ctable.h";
#include <time.h>

using namespace std;

int main()
{
    int numberOfElements = 10000;

    CTable objCTableBubbleSort(numberOfElements);
    CTable objCtableQuickSort(numberOfElements);
    CTable objCtableSelectionSort(numberOfElements);
    CTable objCtableInsertionSort(numberOfElements);

    //objCtable.display();

    //objCtable.insertAt(5, 111);
    //objCtable.display();


    //objCtable.swap(4,5);
    //objCtable.display();

    cout << "Number of elements: " << numberOfElements << endl << endl;

    clock_t t1, t2;
    double executionTime;



    /*** PERFORM BUBBLE SORT ***/
    t1 = clock();

    objCTableBubbleSort.BubbleSort();

    t2 = clock();

    executionTime =  (double)(t2 - t1)/CLOCKS_PER_SEC;
    cout << "Bubble Sort execution time: " << executionTime << endl << endl;

    /*** PERFORM QUICK SORT ***/
    t1 = clock();

    objCtableQuickSort.Quicksort();

    t2 = clock();
    executionTime =  (double)(t2 - t1)/CLOCKS_PER_SEC;
    cout << "Quick Sort execution time: " << executionTime << endl << endl;

    /*** PERFORM SELECTION SORT ***/
    t1 = clock();

    objCtableSelectionSort.SelectionSort();

    t2 = clock();
    executionTime =  (double)(t2 - t1)/CLOCKS_PER_SEC;
    cout << "Selection Sort execution time: " << executionTime << endl << endl;

    /*** PERFORM INSERTION SORT ***/
    t1 = clock();

    objCtableInsertionSort.InsertionSort();

    t2 = clock();
    executionTime =  (double)(t2 - t1)/CLOCKS_PER_SEC;
    cout << "Insertion Sort execution time: " << executionTime << endl << endl;

    return 0;
}

