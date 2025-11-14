#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char name[MAX];
    char sex;
    int age;
} Person;

Person createPerson (char name[], char sex, int age);
void displayPerson(Person p);

int main(){
    Person p1, p2;
    
    p1 = createPerson("Maria", 'f', 18);
    
    strcpy(p2.name, "Charles");
    newPerson.sex = 'm';
    newPerson.age = 20;
    
    
    return 0;
}

Person createPerson (char name[], char sex, int age){
    Person newPerson;
    strcpy(newPerson.name, name);
    newPerson.sex = sex;
    newPerson.age = age;
    return newPerson;
}

void displayPerson(Person p){
    printf("Name: %s\n", p.name);
    printf("Sex: %s\n", toupper(p.sex) == 'M' ? "Male": "Female");
    printf("Age: %d\n", p.age);
}
