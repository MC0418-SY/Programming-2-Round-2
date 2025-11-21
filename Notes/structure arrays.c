#include <stdio.h>
#define MAX 5


typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point points[MAX];
    int count; //how many elements inside
} PointList;

// void addPoint(Point points[], int *count, Point p);
//     // int *count is a pointer cuz yer gonna change count
void addPoint(PointList *list, Point p);    


Point createPoint(int x, int y);
int getPosition(Point p);
double getDistance(Point p1, Point p2);
void displayPoint(Point p);

int main(){
    Point p1 = {-3, 7};
    Point p2;
    Point p3 = createPoint(10, 4);
    
    p2.x = -3;
    p2.y = -4;
    
    Point points[5];
    
    //Different ways to store in structure arrays
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    
    // Using a function to create a point
    points[3] = createPoint(-5, 10);
    
    //This is directly accessing or storing
    points[4].x = 6;
    points[4].y = 20;
    
    printf("Using Normal Array:");
    for (int i = 0; i < 5; ++i){
        displayPoint(points[i]);
        printf("\n");
    }
    
    PointList mypoints;
    mypoints.count = 0;
    
    addPoint(&mypoints, p1);
    addPoint(&mypoints, createPoint(10, 10));
    addPoint(&mypoints, createPoint(5, 11));
    
    printf("\nUsing ADT Points:");
    for (int i = 0; i < mypoints.count; ++i){
        displayPoint(mypoints.points[i]);
        printf("\n");
    }
    
    
    return 0;
}

Point createPoint(int x, int y){
    Point p = {x, y};
    
    return p;
    
}

void displayPoint(Point p){
    printf("(%d, %d)", p.x, p.y);
}

void addPoint(PointList *list, Point p){
    //we gonna add at the nd    
    if(list->count < MAX){
        list->points[list->count++] = p;
        //(list->count)++;
    }
}





