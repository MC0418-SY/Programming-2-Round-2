#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int x;
    int y;
} Point;


Point newPoint(int x, int y);
void displayPoint(Point p);
// sir wants to display it like this
// (x, y) -> (5, 7);

int main(){
    Point p1, p2;
    
    p1 = newPoint(5, -7);
    
    
    p2.x = 15;
    p2.y = 30;
    
    displayPoint(p1);
    displayPoint(p2);
    
    return 0;
}

Point newPoint(int x, int y){
    Point newPoint;
    newPoint.x = x;
    newPoint.y = y;
    return newPoint;
}

void displayPoint(Point p){
    printf("Coordinates: (%d, %d)", p.x, p.y);
    printf("\n");
}
