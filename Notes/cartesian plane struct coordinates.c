#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;


Point newPoint(int x, int y);
void displayPoint(Point p);
// sir wants to display it like this
// (x, y) -> (5, 7);

int getPosition(Point p);
// 0 - origin
// 1 - Q1
// 2 - Q2
// 3 - Q3 
// 4 - Q4
// 5 - x-axis
// 6 - y-axis

double getDistance(Point start, Point end);
bool isSquare(Point p1, Point p2);

int main(){
    Point p1, p2, p3, p4, p5, p6;
    
    p1 = newPoint(5, -7);
    p2 = newPoint(0, 0);
    p3 = newPoint(-2, -3);
    p4 = newPoint(-2, 10);
    p5 = newPoint(5, 5);
    p5 = newPoint(5, 5);
    
    displayPoint(p1);
    displayPoint(p2);
    displayPoint(p3);
    displayPoint(p4);
    displayPoint(p5);
    
    int pos2 = getPosition(p2);
    printf("The point is at Quadrant %d.\n", pos2);
    
    int pos5 = getPosition(p5);
    printf("The point is at Quadrant %d.\n", pos5);
    
    int pos4 = getPosition(p4);
    printf("The point is at Quadrant %d.\n", pos4);
    
    int pos3 = getPosition(p3);
    printf("The point is at Quadrant %d.\n", pos3);
    
    int pos1 = getPosition(p1);
    printf("The point is at Quadrant %d.\n", pos1);
    
    if (isSquare(p1, p2) == true){
        printf("It is a square.\n");
    } else {
        printf("It is not a square.\n");
    }
    
    double distance1 = getDistance(p1,p2);
    printf("Distance: %.2lf km\n", distance1);
    
    double distance2 = getDistance(p3,p4);
    printf("Distance: %.2lf km\n", distance2);
    
    // double distance3 = getDistance(p1,p2);
    // printf("Distance: %.2lf km", distance3);
    
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

int getPosition(Point p){
    if (p.x == 0 && p.y == 0){
        return 0;
    } else if (p.x > 0 && p.y > 0){
        return 1;
    } else if (p.x < 0 && p.y > 0){
        return 2;
    } else if (p.x < 0 && p.y < 0){
        return 3;
    } else if (p.x > 0 && p.y < 0){
        return 4;
    } else if (p.x > 0 || p.x < 0 && p.y == 0){
        return 5;
    } else if (p.y > 0 || p.y < 0 && p.x == 0){
        return 6;
    }
}

double getDistance(Point p1, Point p2){
    // int a, b;
    
    double a, b, c;
    
    a = abs(p2.y - p1.y);
    b = abs(p2.x - p1.y);
    
    c = sqrt((a * a) + (b * b));
    
    return c;
}


bool isSquare(Point p1, Point p2){
    double a, b;
    
    a = abs(p2.y - p1.y);
    b = abs(p2.x - p1.x);
    
    if ((a * a) == (b * b)){
        return true;
    }
    
    return false;
}















































