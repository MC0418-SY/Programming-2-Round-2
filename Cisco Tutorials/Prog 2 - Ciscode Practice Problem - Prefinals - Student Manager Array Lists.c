// Write your boilerplate code here...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define INITIAL_CAPACITY 2

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;


typedef struct {
    Student *data;
    int count;
    int capacity;
} ArrayList;

void initList(ArrayList *list) {
    // initialize struct array,count and initial capacity here
    list->data = (Student*)malloc(INITIAL_CAPACITY * sizeof(Student));
    list->count = 0;
    list->capacity = INITIAL_CAPACITY;
}


void resizeList(ArrayList *list, int newCapacity) {
   //Finish resizeList code
   list->data = (Student*)realloc(list->data, newCapacity * sizeof(Student));
   list->capacity = newCapacity;
}

//TIP: You should use the existing resizeList() function to avoid repeating yourself.
void addStudent(ArrayList *list, int id, char *name, float gpa) {
    // if list is full -> resize
    // add new student to data[size]
    if(list->count == list->capacity){
        resizeList(list, list->capacity * 2);
    }

    Student newStudent;
    newStudent.id = id;
    newStudent.gpa = gpa;
    strcpy(newStudent.name, name);

    list->data[list->count++] = newStudent;
}

Student* findStudent(ArrayList *list, int id) {
  // return pointer to matching student or NULL
  int *studentFound;
    for(int i = 0; i < list->count; ++i){
        if(list->data[i].id == id){
            return &list->data[i];
        }
    }
    return NULL;
}

void updateGPA(ArrayList *list, int id, float newGPA) {
    // find student and update GPA
    Student *studentFound = findStudent(list, id);
    
    if(studentFound != NULL) {
        studentFound->gpa = newGPA;
    }
    
}

void displayStudents(ArrayList list) {
      for(int i = 0 ;i < list.count; i++){
         printf("ID: %d | Name: %s | GPA: %.2f\n",
               list.data[i].id,
               list.data[i].name,
               list.data[i].gpa);
      }
}


int main() {
    ArrayList list;
    initList(&list);

    int choice;
    while (1) {
        printf("\nStudent Records Manager\n");
        printf("1. Add Student\n");
        printf("2. Find Student\n");
        printf("3. Update GPA\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);


        int id;
        char name[NAME_LENGTH];
        float gpa;
        Student *found;

        if(choice == 1){
            // implement add user here
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter GPA: ");
            scanf("%f", &gpa);
            
            addStudent(&list, id, name, gpa);
            printf("Student added successfully.");
        }
        if(choice == 2){
            // implement find student here
            printf("Enter ID to find: ");
            scanf("%d", &id);
            found = findStudent(&list, id);
            if(found != NULL) {
                printf("Found -> ID: %d | Name: %s | GPA: %.2f\n",
                                            found->id,
                                            found->name,
                                            found->gpa);
            } else {
                printf("Student with ID %d not found.\n", id);
            }
        }
        if(choice == 3){
            printf("Enter ID to update GPA: ");
            scanf("%d", &id);
            printf("Enter new GPA: ");
            scanf("%f", &gpa);
            
            // implement update GPA here
            updateGPA(&list, id, gpa);
          
            printf("GPA updated for student ID %d.\n", id);
        }
        if(choice == 4){
            displayStudents(list);
        }
        if(choice == 5) break;


    }


    printf("Program exited.\n");
    return 0;
}
