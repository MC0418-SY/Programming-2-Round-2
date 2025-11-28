#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
  int x;
  int y;
} MyPoint;

typedef struct {
  MyPoint list[MAX];
  int count;
} PointList;

typedef struct {
  MyPoint *points;
  int count;
} PointListDynamic;

// //return all points that are in quadrant 1
// //They all do the same thing, but have a different implementation
// PointList getPointsInQ1(PointList list); //Static Array
// PointListDynamic getPointsInQ1(PointListDynamic list); //Structured Dynamic Arrau
// MyPoint * getPointsInQ1(MyPoint points[], int num); //Unstructured, but pass in array

int main(){
    PointListDynamic list;
    MyPoint p = {-2, -4};
    
    list.count = 0;
    list.points = malloc(sizeof(MyPoint) * 2);
    
    // Access it the same way as you would in a normal array
    list.points[0].x = 5;
    list.points[0].y = 10;
    
    //No need to access the individual elements
    list.points[1] = p;
    
    for(int i = 0; i < 2; i++){
        printf("{%d, %d}\n", list.points[i].x, list.points[i].y);
    }
    
    free(list.points);
    
    return 0;
}
