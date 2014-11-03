#include <iostream>
#include "main.h";

using namespace std;

struct Point2d {
    float x;
    float y;

    //Polygon attributes
    Point2d *prev;
    Point2d *next;
};

struct Polygon2d {
    Point2d *start;
};

int main()
{
    /*Point2d point;

    BuildPoint(point);
    displayPoint(point);

    BuildPointPointer(&point);
    displayPointPointer(&point);*/

    Polygon2d polygon = BuildPolygon();
    //DisplayPolygon(polygon);

    Point2d *element = GetElement(polygon, 2);
    displayPointPointer(element);

    return 0;
}

void displayPoint(Point2d point) {
    cout << "Point (x,y) = (" << point.x << ", " << point.y << ")" << endl;
}

void displayPointPointer(Point2d *point) {
    cout << "Point (x,y) = (" << point->x << ", " << point->y << ")" << endl;
}

void BuildPoint(Point2d &point){
    cout << "Enter coordinate x: " << endl;
    cin >> point.x;

    cout << "Enter coordinate y: " << endl;
    cin >> point.y;
}

void BuildPointPointer(Point2d *point){
    cout << "Enter coordinate x: " << endl;
    cin >> (*point).x;

    cout << "Enter coordinate y: " << endl;
    cin >> (*point).y;
}

Polygon2d BuildPolygon(){
    int n;
    Polygon2d polygon;
    Point2d *point, *first, *previous;

    cout << "Enter number of points:" << endl;
    cin >> n;


    for (int i=0; i<n; i++){
        point = new Point2d;

        BuildPointPointer(point);

        if (i == 0) {
            polygon.start = point;
            first = point;
        }else{
            previous->next = point;
            point->prev = previous;
        }

        previous = point;
    }

    //connect first and last element
    first->prev = point;
    point->next = first;

    return polygon;
}

void DisplayPolygon(Polygon2d polygon){
    Point2d point;

    point = *(polygon.start);

    while (true){
        displayPoint(point);

        cout << "Previous " << endl;
        displayPointPointer(point.prev);
        cout << "Next " << endl;
        displayPointPointer(point.next);


        cout << endl << endl;


        //last point
        if (point.next == polygon.start) break;
        else point = *(point.next);
    }
}

Point2d* GetElement(Polygon2d polygon, int position){
    Point2d point;
    int n = 0;

    point = *(polygon.start);

    while (true){
        if (n+1 == position) {
            return point.next;
        }

        point = *(point.next);
        n++;
    }
}
