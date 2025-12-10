#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
#define STRING_SIZE 255

/*
 * 36 PROGRESSIVE POINTER AND STRUCTURE PROBLEMS
 *
 * INSTRUCTIONS:
 * - You can work on these problems in any order you prefer!
 * - Each problem is a separate function (problem_0a through problem_31)
 * - To test a problem, uncomment its function call in main()
 * - Comment out the problems you're not currently working on
 * - Step-by-step comments guide you through each problem
 * - Predefined sections marked "DO NOT TOUCH" are provided for you
 *
 * CATEGORIES:
 * 0a-0e: Pointer Basics (Warm-up)
 * 1-3:   Pointer Dereferencing
 * 4-6:   Memory Allocation Basics
 * 7-8:   Field Access & Manipulation
 * 9-11:  Field Updates
 * 12-16: String Operations
 * 17-19: Structure Assignment
 * 20-25: Function Parameters
 * 26-27: Dynamic Memory Management
 * 28-31: Advanced Operations
 */

typedef struct todo {
    char description[STRING_SIZE];
    bool isFinished;
    int priority;
} Todo, *TodoPTR;

typedef struct project {
    char projectName[STRING_SIZE];
    Todo *todos;
    int todoCount;
    int todoCapacity;
} Project, *ProjectPTR;

typedef struct person {
    char name[STRING_SIZE];
    Project *projects;
    int projectCount;
    int projectCapacity;
} Person, *PersonPTR;

// ===== CATEGORY 0: POINTER BASICS (WARM-UP) =====
// Declare a pointer and use basic pointer operations
void problem_0a() {
    // Step 1: Declare an integer variable named `num` and initialize it to 42
    int num = 42;

    // Step 2: Declare a pointer to an integer named `ptr`
    // and initialize it with the address of `num`
    int *ptr = &num;

    // Step 3: Print the value of num directly
    printf("%d", num);

    // Step 4: Print the value of num through the pointer using dereference
    printf("%d", *ptr);
    // Step 5: Print the address stored in ptr
    printf("%p", ptr);
}

// Modify a variable through a pointer
void problem_0b() {
    // Step 1: Declare an integer variable named `num` and initialize it to 10
    int num = 10;
    // Step 2: Declare a pointer to an integer and assign the address of num
    int *ptr = &num;
    // Step 3: Print the original value
    printf("%d", num);
    // Step 4: Modify the value through the pointer by dereferencing
    // Set *ptr to 99
    *ptr = 99;

    // Step 5: Print the modified value directly through num
    printf("%d", num);
}

// Work with pointers to different types
void problem_0c() {
    // Step 1: Declare a float variable named `price` and initialize it to 19.99
    float price = 19.99;
    // Step 2: Declare a pointer to float and assign the address of price
    float *ptr = &price;
    // Step 3: Print the original price through the pointer
    printf("%.2f", *ptr);
    // Step 4: Modify price through the pointer - add 5.00 to it
    *ptr += 5.00;
    // Step 5: Print the updated price
    printf("%.2f", price);
}

// Double pointers (pointer to pointer)
void problem_0d() {
    // Step 1: Declare an integer variable named `value`
    // and initialize it to 100
    int value = 100;
    // Step 2: Declare a pointer to integer and assign the address of value
    int *ptr = &value;
    // Step 3: Declare a pointer to pointer (double pointer) and assign
    // the address of ptr
    int **doubleptr = &ptr;
    // Step 4: Print the value using single dereference (*ptr)
    printf("%d", *ptr);
    // Step 5: Print the value using double dereference (**ptrToPtr)
    printf("%d", **doubleptr);
    // Step 6: Modify the value through the double pointer and set it to 200.
    **doubleptr = 200;
    // Predefined: DO NOT TOUCH
    printf("\nModified value: %d\n", value);
    // Predefined: DO NOT TOUCH
}

// Pointer to a simple structure (stack allocated)
void problem_0e() {
    // Step 1: Declare a Todo variable named `myTodo` on the stack
    Todo myTodo;
    // Step 2: Declare a pointer to Todo and assign the address of myTodo
    Todo* todoPtr = &myTodo;
    // Step 3: Set priority through the pointer
    todoPtr->priority = 1;
    // Step 4: Set isFinished through the pointer
    todoPtr->isFinished = true;
    // Step 5: Use strcpy to set description to "First pointer to struct"
    strcpy(todoPtr->description, "First pointer to struct");
    // Predefined: DO NOT TOUCH
    printf("\nPriority: %d", todoPtr->priority);
    printf("\nIsFinished: %d", todoPtr->isFinished);
    printf("\nDescription: %s\n", todoPtr->description);
    // Predefined: DO NOT TOUCH
}

// ===== CATEGORY 1: POINTER DEREFERENCING =====
// Basic single-level dereferencing (with malloc)
void problem_1() {
    // Step 1: Allocate memory for one Todo using malloc
    Todo *myTodo = malloc(sizeof(Todo));
    // Step 2: Set priority field to 5
    myTodo->priority = 5;
    // Step 3: Set isFinished field to true
    myTodo->isFinished = true;
    // Step 4: Set description to "Master pointers"
    strcpy(myTodo->description, "Master pointers");
    // Step 5: Print all values to verify
    printf("Priority: %d\n", myTodo->priority);
    printf("IsFinished: %d\n", myTodo->isFinished);
    printf("Description: %s", myTodo->description);
    // Step 6: Free allocated memory
    free(myTodo);
}

// Predefined: DO NOT TOUCH
Project *problem_2_init() {
    // Pre-initialize Project with 3 todos
    Project *proj = (Project *)malloc(sizeof(Project));
    strcpy(proj->projectName, "Dereferencing Practice");
    proj->todos = (Todo *)malloc(sizeof(Todo) * 3);
    proj->todoCount = 3;
    proj->todoCapacity = 3;

    // Initialize todos
    proj->todos[0] = (Todo){"Task A", false, 1};
    proj->todos[1] = (Todo){"Task B", true, 2};
    proj->todos[2] = (Todo){"Task C", false, 3};

    return proj;
}
// Predefined: DO NOT TOUCH

// Multi-level dereferencing with nested structures
void problem_2() {
    // Predefined: DO NOT TOUCH
    Project *projectPtr = problem_2_init();
    // Predefined: DO NOT TOUCH

    // Step 1: Access the second todo (index 1) and change its priority to 10
    projectPtr->todos[1].priority = 10;
    // Step 2: Access first todo (index 0) and mark it finished
    // (set isFinished to true)
    projectPtr->todos[0].isFinished = true;

    // Step 3: Create a pointer to the third todo (index 2)
    // Use the address-of operator (&) to get the address
    Todo *newTodo = &(projectPtr->todos[2]);
    // Step 4: Use the new pointer to change the third todo's description
    // to "Updated Task" using strcpy
    strcpy(newTodo->description, "Updated Task");

    // Step 5: Print to verify changes
    printf("Second Todo Priority: %d\n", projectPtr->todos[1].priority);
    printf("First Todo Status: %d\n", projectPtr->todos[0].isFinished);
    printf("Third Todo Description: %s", newTodo->description);

    // Predefined: DO NOT TOUCH
    // Free allocated memory
    free(projectPtr->todos);
    free(projectPtr);
    // Predefined: DO NOT TOUCH
}

// Predefined: DO NOT TOUCH
Person *problem_3_init() {
    // Pre-initialize Person with 2 projects, each with 2 todos
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, "Alice");
    p->projects = (Project *)malloc(sizeof(Project) * 2);
    p->projectCount = 2;
    p->projectCapacity = 2;

    // Initialize first project
    strcpy(p->projects[0].projectName, "Work");
    p->projects[0].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[0].todoCount = 2;
    p->projects[0].todoCapacity = 2;
    p->projects[0].todos[0] = (Todo){"Work Task 1", false, 1};
    p->projects[0].todos[1] = (Todo){"Work Task 2", true, 2};

    // Initialize second project
    strcpy(p->projects[1].projectName, "Personal");
    p->projects[1].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[1].todoCount = 2;
    p->projects[1].todoCapacity = 2;
    p->projects[1].todos[0] = (Todo){"Personal Task 1", false, 3};
    p->projects[1].todos[1] = (Todo){"Personal Task 2", false, 4};

    return p;
}
// Predefined: DO NOT TOUCH

// Complex multi-level dereferencing with nested structures
void problem_3() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_3_init();
    // Predefined: DO NOT TOUCH
    
    // Step 1: Access the first project's (index 0) first todo (index 0)
    // and set its priority to 99
    personPtr->projects[0].todos[0].priority = 99;
    // Step 2: Create a pointer to the second project (index 1)
    // Use the address-of operator (&) to get the address
    Project *secondProject = &(personPtr->projects[1]);
    // Step 3: Use the new pointer to access the second todo (index 1)
    // and mark it finished (set isFinished to true)
    secondProject->todos[1].isFinished = true;
    // Step 4: Print to verify changes
    printf("\nPerson name: %s", personPtr->name);
    printf("First Project's First Todo: %d\n", personPtr->projects[0].todos[0].priority);
    printf("Second Project's Second Todo: %d\n", secondProject->todos[1].isFinished);
    
    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// ===== CATEGORY 2: MEMORY ALLOCATION BASICS =====
// Allocate memory for Todo, Project, and Person structures
void problem_4() {
    // Step 1: Allocate memory for ONE Todo structure using malloc
    Todo *myTodo = malloc(sizeof(Todo));
    
    // Step 2: Allocate memory for one Project structure using malloc
    Project *myProject = malloc(sizeof(Project));
    
    // Step 3: Allocate memory for the todos array inside Project
    // with size INITIAL_CAPACITY
    myProject->todos = malloc(sizeof(Todo) * INITIAL_CAPACITY);
    
    // Step 4: Allocate memory for one Person structure using malloc
    Person *myPerson = malloc(sizeof(Person));
    
    // Step 5: Allocate memory for the projects array inside Person
    // with size 3
    myPerson->projects = malloc(sizeof(Project) * 3);
    
    // Step 6: Free all allocated memory in reverse order
    free(myPerson->projects);
    free(myPerson);
    free(myProject->todos);
    free(myProject);
    free(myTodo);
}

// Allocate memory using PersonPTR typedef
void problem_5() {
    // Step 1: Allocate memory for a Person using PersonPTR typedef
    PersonPTR myPerson = malloc(sizeof(Person));
    // Step 2: Allocate memory for projects array with size as INITIAL_CAPACITY
    myPerson->projects = malloc(sizeof(Project) * INITIAL_CAPACITY);
    // Step 3: Free in reverse order
    free(myPerson->projects);
    free(myPerson);
}

// Allocate PersonPTR with nested project and todo allocation
void problem_6() {
    // Step 1: Allocate memory for a Person using PersonPTR typedef
    PersonPTR  person = malloc(sizeof(Person));
    
    // Step 2: Allocate memory for one Project
    person->projects = malloc(sizeof(Project));
    
    // Step 3: Allocate memory for todos inside the project
    // with size as INITIAL_CAPACITY
    person->projects->todos = malloc(sizeof(Todo) * INITIAL_CAPACITY);
    
    // Step 4: Free from innermost to outermost
    free(person->projects->todos);
    free(person->projects);
    free(person);
}

// ===== CATEGORY 3: FIELD ACCESS & MANIPULATION =====
// Access nested fields - person->project->todo->description
void problem_7() {
    // Step 1: Declare a Person variable on the stack
    Person person;
    
    // Step 2: Allocate memory for one Project
    person.projects = malloc(sizeof(Project));
    
    // Step 3: Allocate memory for one Todo inside the project
    person.projects->todos = malloc(sizeof(Todo));
    
    // Step 4: Access and set the first todo's isFinished field to false
    // Use array index [0]
    person.projects->todos[0].isFinished = false;

    // Step 5: Access and set the first todo's priority field to 2
    person.projects->todos[0].priority = 2;

    // Step 6: Free allocated memory
    free(person.projects);
    free(person.projects->todos);
}

// Modify priority levels in nested todos
void problem_8() {
    // Step 1: Declare a Person variable on the stack
    Person person;
    
    // Step 2: Allocate memory for one Project
    person.projects = malloc(sizeof(Project));
    
    // Step 3: Allocate memory for 3 Todos
    person.projects->todos = malloc(sizeof(Todo) * 3);

    // Step 4: Loop through all 3 todos and set each todo's priority to 3
    // Use a for loop from i=0 to i<3
    for(int i = 0; i < 3; ++i){
        person.projects->todos[i].priority = 3;
    }

    // Step 5: Free allocated memory
    free(person.projects);
    free(person.projects->todos);
}

// ===== CATEGORY 4: FIELD UPDATES =====
// Predefined: DO NOT TOUCH
Person *problem_9_init() {
    // Pre-initialize Person with 3 projects
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, "Charlie");
    p->projects = (Project *)malloc(sizeof(Project) * 3);
    p->projectCount = 3;
    p->projectCapacity = 3;

    // Initialize projects
    strcpy(p->projects[0].projectName, "Old Name 1");
    p->projects[0].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[0].todoCount = 2;
    p->projects[0].todoCapacity = 2;

    strcpy(p->projects[1].projectName, "Old Name 2");
    p->projects[1].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[1].todoCount = 2;
    p->projects[1].todoCapacity = 2;

    strcpy(p->projects[2].projectName, "Old Name 3");
    p->projects[2].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[2].todoCount = 2;
    p->projects[2].todoCapacity = 2;

    // Initialize todos with old descriptions
    strcpy(p->projects[0].todos[0].description, "Old Task 1-1");
    strcpy(p->projects[0].todos[1].description, "Old Task 1-2");
    strcpy(p->projects[1].todos[0].description, "Old Task 2-1");
    strcpy(p->projects[1].todos[1].description, "Old Task 2-2");
    strcpy(p->projects[2].todos[0].description, "Old Task 3-1");
    strcpy(p->projects[2].todos[1].description, "Old Task 3-2");

    return p;
}
// Predefined: DO NOT TOUCH

// Update projectName at specific index
void problem_9() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_9_init();
    // Predefined: DO NOT TOUCH

    // Step 1: Use strcpy() to change the project name at index 1
    // to "Updated Project"
    strcpy(personPtr->projects[1].projectName, "Updated Project");
    
    // Step 2: Print all project names to verify
    for(int i = 0; i < personPtr->projectCount; ++i){
        printf("Project Name[i]: %s", personPtr->projects[i].projectName);
    }
    
    
    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// Update todo description at specific nested index
void problem_10() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_9_init();
    // Predefined: DO NOT TOUCH

    // Step 1: Use strcpy() to change the todo description at
    // project index 2, todo index 0 to "Completely New Task"
    strcpy(personPtr->projects[2].todos[0].description, "Completely New Task");

    // Step 2: Use strcpy() to change the todo description at
    // project index 0, todo index 1 to "Another Updated Task"
    strcpy(personPtr->projects[0].todos[1].description, "Another Updated Task");

    // Step 3: Set the todo to finished at project index 2, todo index 0
    // Set isFinished to true
    personPtr->projects[2].todos[0].isFinished = true;

    // Predefined: DO NOT TOUCH
    // Print all todo descriptions to verify
    printf("\nTodo descriptions after update:\n");
    for (int i = 0; i < personPtr->projectCount; i++) {
        printf("Project %d:\n", i);
        for (int j = 0; j < personPtr->projects[i].todoCount; j++) {
            printf("  Todo %d: %s\n", j,
                   personPtr->projects[i].todos[j].description);
        }
    }
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// Update multiple fields at specific indices
void problem_11() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_9_init();
    // Predefined: DO NOT TOUCH

    // Step 1: Change the person's name to "Updated Charlie" using strcpy
    strcpy(personPtr->name, "Updated Charlie");
    
    // Step 2: Change project name at index 0 to "First Project Renamed"
    strcpy(personPtr->projects[0].projectName, "First Project Renamed");

    // Step 3: Change todo description at project 1, todo 1 to "New Description"
    strcpy(personPtr->projects[1].todos[1].description, "New Description");

    // Step 4: Change priority at project 2, todo 0 to 99
    personPtr->projects[2].todos[0].priority = 99;

    // Predefined: DO NOT TOUCH
    printf("\nPerson name: %s\n", personPtr->name);
    printf("Project 0 name: %s\n", personPtr->projects[0].projectName);
    printf("Project 1, Todo 1 description: %s\n",
           personPtr->projects[1].todos[1].description);
    printf("Project 2, Todo 0 priority: %d\n",
           personPtr->projects[2].todos[0].priority);
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// ===== CATEGORY 5: STRING OPERATIONS =====
// strcpy() to todo description
void problem_12() {
    // Step 1: Declare a Todo variable named `myTodo` on the stack
    Todo myTodo;
    
    // Step 2: Use strcpy() to initialize description field to "Learn pointers"
    strcpy(myTodo.description, "Learn pointers");
}

// strcpy() to project name
void problem_13() {
    // Step 1: Allocate memory for one Project using malloc
    Project *myProject = malloc(sizeof(Project));
    
    // Step 2: Use strcpy() to initialize projectName field to "Learning C"
    strcpy(myProject->projectName, "Learning C");
    
    // Step 3: Free allocated memory
    free(myProject);
}

// strcpy() to person name
void problem_14() {
    // Step 1: Allocate memory for one Person using malloc
    Person *myPerson = malloc(sizeof(Person));
    
    // Step 2: Use strcpy() to copy "John Doe" into the name field
    strcpy(myPerson->name, "John Doe");

    // Step 3: Free allocated memory
    free(myPerson);
}

// strcpy() to nested todo description
void problem_15() {
    // Predefined - DO NOT TOUCH
    Person person;
    person.projects = (Project *)malloc(sizeof(Project));
    person.projects->todos = (Todo *)malloc(sizeof(Todo));
    // Predefined - DO NOT TOUCH

    // Step 1: Use strcpy() to copy "Complete assignment" into the
    // nested todo description at index 0
    strcpy(person.projects->todos[0].description, "Complete assignment");

    // Step 2: Free allocated memory
    free(person.projects->todos);
    free(person.projects);

}

// strcpy() to nested project name
void problem_16() {
    // Predefined - DO NOT TOUCH
    Person person;
    person.projects = (Project *)malloc(sizeof(Project));
    person.projects->todos = (Todo *)malloc(sizeof(Todo) * INITIAL_CAPACITY);
    // Predefined - DO NOT TOUCH

    // Step 1: Use strcpy() to copy "Study pointers" into
    // the first todo's description
    strcpy(person.projects->todos[0].description, "Study pointers");

    // Step 2: Print the nested description variable
    printf("\n%s", person.projects->todos[0].description);

    // Step 3: Free allocated memory
    free(person.projects->todos);
    free(person.projects);
}

// ===== CATEGORY 6: STRUCTURE ASSIGNMENT =====
// Simple structure-to-structure assignment
void problem_17() {
    // Step 1: Declare a Todo structure named `todo1` on the stack
    Todo todo1;
    
    // Step 2: Declare a Todo structure named `todo2` on the stack
    Todo todo2;
    
    // Step 3: Use strcpy() to set todo1's description to "Original Task"
    strcpy(todo1.description, "Original Task");
    
    // Step 4: Set todo1's isFinished field to false
    todo1.isFinished = false;

    // Step 5: Set todo1's priority field to 5
    todo1.priority = 5;

    // Step 6: Copy all fields from todo1 to todo2 using structure assignment
    // (=) This performs a shallow copy of all fields
    todo1 = todo2;

    // Step 7: Use strcpy() to change todo2's description to "Modified Task"
    strcpy(todo2.description, "Modified Task");

    // Step 8: Change todo2's priority to 10
    todo2.isFinished = 10;
    
    // Predefined: DO NOT TOUCH
    // Print both to verify they are independent copies
    printf("\nTodo1: %s, Priority: %d", todo1.description, todo1.priority);
    printf("\nTodo2: %s, Priority: %d\n", todo2.description, todo2.priority);
    // Predefined: DO NOT TOUCH
}

// Predefined: DO NOT TOUCH
Person *problem_18_init() {
    // Pre-initialize Person with 4 projects
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, "Dave");
    p->projects = (Project *)malloc(sizeof(Project) * 4);
    p->projectCount = 4;
    p->projectCapacity = 4;

    // Initialize projects with different priorities
    strcpy(p->projects[0].projectName, "Alpha");
    p->projects[0].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[0].todoCount = 2;
    p->projects[0].todoCapacity = 2;
    strcpy(p->projects[0].todos[0].description, "Alpha Task 1");
    p->projects[0].todos[0].priority = 1;
    p->projects[0].todos[0].isFinished = false;
    strcpy(p->projects[0].todos[1].description, "Alpha Task 2");
    p->projects[0].todos[1].priority = 2;
    p->projects[0].todos[1].isFinished = true;

    strcpy(p->projects[1].projectName, "Beta");
    p->projects[1].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[1].todoCount = 2;
    p->projects[1].todoCapacity = 2;
    strcpy(p->projects[1].todos[0].description, "Beta Task 1");
    p->projects[1].todos[0].priority = 5;
    p->projects[1].todos[0].isFinished = true;
    strcpy(p->projects[1].todos[1].description, "Beta Task 2");
    p->projects[1].todos[1].priority = 6;
    p->projects[1].todos[1].isFinished = false;

    strcpy(p->projects[2].projectName, "Gamma");
    p->projects[2].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[2].todoCount = 2;
    p->projects[2].todoCapacity = 2;
    strcpy(p->projects[2].todos[0].description, "Gamma Task 1");
    p->projects[2].todos[0].priority = 3;
    p->projects[2].todos[0].isFinished = false;
    strcpy(p->projects[2].todos[1].description, "Gamma Task 2");
    p->projects[2].todos[1].priority = 4;
    p->projects[2].todos[1].isFinished = true;

    strcpy(p->projects[3].projectName, "Delta");
    p->projects[3].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[3].todoCount = 2;
    p->projects[3].todoCapacity = 2;
    strcpy(p->projects[3].todos[0].description, "Delta Task 1");
    p->projects[3].todos[0].priority = 7;
    p->projects[3].todos[0].isFinished = true;
    strcpy(p->projects[3].todos[1].description, "Delta Task 2");
    p->projects[3].todos[1].priority = 8;
    p->projects[3].todos[1].isFinished = false;

    return p;
}
// Predefined: DO NOT TOUCH

// Copy todo from one project to another using structure assignment
void problem_18() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_18_init();
    // Predefined: DO NOT TOUCH

    // Step 1: Assign project 0's first todo (index 0) to
    // project 2's second todo (index 1) using structure assignment (=)
    personPtr->projects[2].todos[1] = personPtr->projects[0].todos[0];
    
    // Predefined: DO NOT TOUCH
    // Print to verify the copy
    printf("\nProject 2, Todo 1 description: %s",
           personPtr->projects[2].todos[1].description);
    printf("\nProject 2, Todo 1 priority: %d\n",
           personPtr->projects[2].todos[1].priority);
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// Swap two todos using structure assignment and a temporary variable
void problem_19() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_18_init();
    printf("\nBefore swap:");
    printf("\nProject 1, Todo 0: %s (priority %d)",
           personPtr->projects[1].todos[0].description,
           personPtr->projects[1].todos[0].priority);
    printf("\nProject 3, Todo 1: %s (priority %d)",
           personPtr->projects[3].todos[1].description,
           personPtr->projects[3].todos[1].priority);
    // Predefined: DO NOT TOUCH

    // Step 1: Swap project 1's todo 0 with project 3's todo 1
    // Create a temporary Todo variable and assign project 1's todo 0 to it
    Todo temp = personPtr->projects[1].todos[0];
    
    // Step 2: Assign project 3's todo 1 to project 1's todo 0
    personPtr->projects[1].todos[0] = personPtr->projects[3].todos[1];

    // Step 3: Assign the temp variable to project 3's todo 1
    personPtr->projects[3].todos[1] = temp;

    // Predefined: DO NOT TOUCH
    printf("\n\nAfter swap:");
    printf("\nProject 1, Todo 0: %s (priority %d)",
           personPtr->projects[1].todos[0].description,
           personPtr->projects[1].todos[0].priority);
    printf("\nProject 3, Todo 1: %s (priority %d)\n",
           personPtr->projects[3].todos[1].description,
           personPtr->projects[3].todos[1].priority);
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// ===== CATEGORY 7: FUNCTION PARAMETERS =====
// Function that accepts a Todo by value and displays it
void displayTodo(Todo t) {
    printf("\nTodo Description: %s", t.description);
    printf("\nPriority: %d", t.priority);
    printf("\nFinished: %s\n", t.isFinished ? "Yes" : "No");
}

// Pass structure by value to a function
void problem_20() {
    // Step 1: Declare a Todo variable on the stack

    // Step 2: Initialize the todo's description to "Learn function parameters"

    // Step 3: Initialize the todo's priority to 8

    // Step 4: Initialize the todo's isFinished to false

    // Step 5: Call displayTodo() and pass myTodo by value
}

// Function that accepts a pointer to Todo and modifies it
void markTodoAsFinished(Todo *t) {
    // Set isFinished to true
    t->isFinished = true;
    // Set priority to 0
    t->priority = 0;
}

// Pass address of structure to a function (allows modification)
void problem_21() {
    // Step 1: Declare a Todo variable on the stack

    // Step 2: Initialize the todo's description to "Task to complete"

    // Step 3: Initialize the todo's priority to 5

    // Step 4: Initialize the todo's isFinished to false

    // Step 5: Print before modification

    // Step 6: Call markTodoAsFinished() and pass the address using &myTodo

    // Step 7: Print after modification
}

// Function that accepts a Project pointer and displays all todos
void displayAllTodos(Project *proj) {
    printf("\nProject: %s", proj->projectName);
    printf("\nTodos (%d):", proj->todoCount);
    for (int i = 0; i < proj->todoCount; i++) {
        printf("\n  %d. %s (Priority: %d)", i + 1, proj->todos[i].description,
               proj->todos[i].priority);
    }
    printf("\n");
}

// Predefined: DO NOT TOUCH
Project *problem_22_init() {
    // Create a project with 3 todos
    Project *proj = (Project *)malloc(sizeof(Project));
    strcpy(proj->projectName, "My Project");
    proj->todos = (Todo *)malloc(sizeof(Todo) * 3);
    proj->todoCount = 3;
    proj->todoCapacity = 3;

    strcpy(proj->todos[0].description, "First task");
    proj->todos[0].priority = 1;
    proj->todos[0].isFinished = false;

    strcpy(proj->todos[1].description, "Second task");
    proj->todos[1].priority = 2;
    proj->todos[1].isFinished = true;

    strcpy(proj->todos[2].description, "Third task");
    proj->todos[2].priority = 3;
    proj->todos[2].isFinished = false;

    return proj;
}
// Predefined: DO NOT TOUCH

// Pass nested structure pointer to function for display
void problem_22() {
    // Predefined: DO NOT TOUCH
    Project *project = problem_22_init();
    // Predefined: DO NOT TOUCH

    // Step 1: Call displayAllTodos() and pass the project pointer

    // Predefined: DO NOT TOUCH
    // Free allocated memory
    free(project->todos);
    free(project);
    // Predefined: DO NOT TOUCH
}

// Function that returns a Todo structure
Todo createTodo(const char *desc, int priority, bool finished) {
    // Step 1: Declare a Todo variable on the stack

    // Step 2: Copy the description parameter to newTodo's description field

    // Step 3: Assign priority parameter to newTodo's priority field

    // Step 4: Assign finished parameter to newTodo's isFinished field

    // Step 5: Return the newTodo structure
}

// Return a structure from a function
void problem_23() {
    // Step 1: Call createTodo() with arguments ("Returned task", 7, true)
    // and assign the returned structure to myTodo

    // Predefined: DO NOT TOUCH
    // Print the returned todo's fields to verify
    printf("\nReturned Todo Description: %s", myTodo.description);
    printf("\nPriority: %d", myTodo.priority);
    printf("\nFinished: %s\n", myTodo.isFinished ? "Yes" : "No");
    // Predefined: DO NOT TOUCH
}

// Function that accepts a Project pointer and updates its name
void renameProject(Project *proj, const char *newName) {
    // Use strcpy() to copy newName to the project's projectName field
}

// Predefined: DO NOT TOUCH
Person *problem_24_init() {
    // Create a person with 3 projects
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, "Diana");
    p->projects = (Project *)malloc(sizeof(Project) * 3);
    p->projectCount = 3;
    p->projectCapacity = 3;

    // Initialize projects
    strcpy(p->projects[0].projectName, "Project A");
    p->projects[0].todos = (Todo *)malloc(sizeof(Todo) * 1);
    p->projects[0].todoCount = 1;
    p->projects[0].todoCapacity = 1;

    strcpy(p->projects[1].projectName, "Project B");
    p->projects[1].todos = (Todo *)malloc(sizeof(Todo) * 1);
    p->projects[1].todoCount = 1;
    p->projects[1].todoCapacity = 1;

    strcpy(p->projects[2].projectName, "Project C");
    p->projects[2].todos = (Todo *)malloc(sizeof(Todo) * 1);
    p->projects[2].todoCount = 1;
    p->projects[2].todoCapacity = 1;

    return p;
}
// Predefined: DO NOT TOUCH

// Pass address of nested Project to a function
void problem_24() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_24_init();
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    printf("\nBefore:");
    printf("\nProject 0: %s", personPtr->projects[0].projectName);
    printf("\nProject 2: %s", personPtr->projects[2].projectName);
    // Predefined: DO NOT TOUCH

    // Step 1: Call renameProject() and pass the address of project at index 0
    // Use &(personPtr->projects[0]) to get the address
    // Rename it to "Updated Project A"

    // Step 2: Call renameProject() and pass the address of project at index 2
    // Use &(personPtr->projects[2]) to get the address
    // Rename it to "Updated Project C"

    // Predefined: DO NOT TOUCH
    printf("\n\nAfter:");
    printf("\nProject 0: %s", personPtr->projects[0].projectName);
    printf("\nProject 2: %s\n", personPtr->projects[2].projectName);
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// Function that accepts a Todo pointer and increases its priority
void increasePriority(Todo *t, int amount) {
    // Add amount to the todo's priority field
}

// Predefined: DO NOT TOUCH
Person *problem_25_init() {
    // Create a person with 2 projects
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, "Eve");
    p->projects = (Project *)malloc(sizeof(Project) * 2);
    p->projectCount = 2;
    p->projectCapacity = 2;

    // First project with 2 todos
    strcpy(p->projects[0].projectName, "Work");
    p->projects[0].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[0].todoCount = 2;
    p->projects[0].todoCapacity = 2;
    strcpy(p->projects[0].todos[0].description, "Work Task 1");
    p->projects[0].todos[0].priority = 3;
    p->projects[0].todos[0].isFinished = false;
    strcpy(p->projects[0].todos[1].description, "Work Task 2");
    p->projects[0].todos[1].priority = 5;
    p->projects[0].todos[1].isFinished = false;

    // Second project with 2 todos
    strcpy(p->projects[1].projectName, "Home");
    p->projects[1].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[1].todoCount = 2;
    p->projects[1].todoCapacity = 2;
    strcpy(p->projects[1].todos[0].description, "Home Task 1");
    p->projects[1].todos[0].priority = 2;
    p->projects[1].todos[0].isFinished = false;
    strcpy(p->projects[1].todos[1].description, "Home Task 2");
    p->projects[1].todos[1].priority = 4;
    p->projects[1].todos[1].isFinished = false;

    return p;
}
// Predefined: DO NOT TOUCH

// Pass address of deeply nested structure element to a function
void problem_25() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_25_init();
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Print before modification
    printf("\nBefore:");
    printf("\nProject 0, Todo 1 priority: %d",
           personPtr->projects[0].todos[1].priority);
    printf("\nProject 1, Todo 0 priority: %d",
           personPtr->projects[1].todos[0].priority);
    // Predefined: DO NOT TOUCH

    // Step 1: Call increasePriority() and pass the address of
    // project 0's second todo (index 1)
    // Use &(personPtr->projects[0].todos[1]) to get the address
    // Increase priority by 10

    // Step 2: Call increasePriority() and pass the address of
    // project 1's first todo (index 0)
    // Use &(personPtr->projects[1].todos[0]) to get the address
    // Increase priority by 5

    // Predefined: DO NOT TOUCH
    // Print after modification
    printf("\n\nAfter:");
    printf("\nProject 0, Todo 1 priority: %d",
           personPtr->projects[0].todos[1].priority);
    printf("\nProject 1, Todo 0 priority: %d\n",
           personPtr->projects[1].todos[0].priority);
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

// ===== CATEGORY 8: DYNAMIC MEMORY MANAGEMENT =====
// Realloc todos array in a project
void problem_26() {
    // Predefined: DO NOT TOUCH
    // Allocate memory for one Project
    Project *project = (Project *)malloc(sizeof(Project));
    // Allocate memory for `todos` with size INITIAL_CAPACITY
    project->todos = (Todo *)malloc(INITIAL_CAPACITY * sizeof(Todo));
    project->todoCapacity = INITIAL_CAPACITY;
    // Predefined: DO NOT TOUCH

    // Step 1: Calculate new capacity (double the current capacity)

    // Step 2: Use realloc() to resize the todos array to newCapacity
    // Store the result in a temporary pointer

    // Step 3: Check if realloc succeeded (returned non-NULL)
    // If successful, update the project's todos pointer and todoCapacity

    // Step 4: Free allocated memory
}

// Realloc projects array in a person
void problem_27() {
    // Step 1: Allocate memory for one Person

    // Step 2: Allocate memory for INITIAL_CAPACITY projects

    // Step 3: Set projectCapacity to INITIAL_CAPACITY

    // Step 4: Calculate new capacity (double the current capacity)

    // Step 5: Use realloc() to resize the projects array to newCapacity
    // Store the result in a temporary pointer

    // Step 6: Check if realloc succeeded (returned non-NULL)
    // If successful, update the person's projects pointer and projectCapacity

    // Step 7: Free allocated memory
}

// ===== CATEGORY 9: ADVANCED OPERATIONS =====
// Predefined: DO NOT TOUCH
Person problem_28_init() {
    // Pre-initialize Person with 10 todos (4 unfinished, 6 finished) using
    // direct structure assignment
    Person A = {"Test Person", malloc(sizeof(Project)), 1, 1};

    // Initialize project with direct structure assignment
    A.projects[0] =
        (Project){"Test Project", malloc(sizeof(Todo) * 10), 10, 10};

    // Initialize 10 todos with direct structure assignment
    A.projects[0].todos[0] = (Todo){"Todo 1", false, 1};
    A.projects[0].todos[1] = (Todo){"Todo 2", false, 2};
    A.projects[0].todos[2] = (Todo){"Todo 3", false, 3};
    A.projects[0].todos[3] = (Todo){"Todo 4", false, 4};
    A.projects[0].todos[4] = (Todo){"Todo 5", true, 5};
    A.projects[0].todos[5] = (Todo){"Todo 6", true, 6};
    A.projects[0].todos[6] = (Todo){"Todo 7", true, 7};
    A.projects[0].todos[7] = (Todo){"Todo 8", true, 8};
    A.projects[0].todos[8] = (Todo){"Todo 9", true, 9};
    A.projects[0].todos[9] = (Todo){"Todo 10", true, 10};

    return A;
}
// Predefined: DO NOT TOUCH

void problem_28() {
    // Predefined: DO NOT TOUCH
    Person data = problem_28_init();
    Todo unfinishedTodos[10];
    int unfinishedCount = 0; // Update when necessary
    // Predefined: DO NOT TOUCH

    // Step 1: Loop through the first project's todos inside `data`
    // Use a for loop with variable x from 0 to data.projects[0].todoCount

    // Step 2: Check if the current todo is NOT finished
    // If not finished, copy it to unfinishedTodos array

    // Step 3: Assign the unfinished todo to
    // unfinishedTodos[unfinishedCount]

    // Step 4: Increment unfinishedCount

    // Step 5: Print the unfinishedCount (should be 4)

    // Predefined: DO NOT TOUCH
    free(data.projects[0].todos);
    free(data.projects);
    // Predefined: DO NOT TOUCH
}

// Predefined: DO NOT TOUCH
Person problem_29_init() {
    // Pre-initialize Person with 10 projects using direct structure assignment
    Person A = {"Test Person", malloc(sizeof(Project) * 10), 10, 10};

    // Initialize 10 projects with direct structure assignment
    A.projects[0] = (Project){"Project One", malloc(sizeof(Todo) * 2), 2, 2};
    A.projects[1] = (Project){"Project Two", malloc(sizeof(Todo) * 3), 3, 3};
    A.projects[2] = (Project){"Project Three", malloc(sizeof(Todo) * 1), 1, 1};
    A.projects[3] = (Project){"Project Four", malloc(sizeof(Todo) * 4), 4, 4};
    A.projects[4] = (Project){"Project Five", malloc(sizeof(Todo) * 2), 2, 2};
    A.projects[5] = (Project){"Project Six", malloc(sizeof(Todo) * 3), 3, 3};
    A.projects[6] = (Project){"Project Seven", malloc(sizeof(Todo) * 1), 1, 1};
    A.projects[7] = (Project){"Project Eight", malloc(sizeof(Todo) * 2), 2, 2};
    A.projects[8] = (Project){"Project Nine", malloc(sizeof(Todo) * 3), 3, 3};
    A.projects[9] = (Project){"Project Ten", malloc(sizeof(Todo) * 2), 2, 2};

    // Initialize todos for each project
    // Project One todos
    A.projects[0].todos[0] = (Todo){"Task 1-1", false, 1};
    A.projects[0].todos[1] = (Todo){"Task 1-2", true, 2};

    // Project Two todos
    A.projects[1].todos[0] = (Todo){"Task 2-1", true, 1};
    A.projects[1].todos[1] = (Todo){"Task 2-2", false, 2};
    A.projects[1].todos[2] = (Todo){"Task 2-3", false, 3};

    // Project Three todos
    A.projects[2].todos[0] = (Todo){"Task 3-1", true, 1};

    // Project Four todos
    A.projects[3].todos[0] = (Todo){"Task 4-1", false, 1};
    A.projects[3].todos[1] = (Todo){"Task 4-2", true, 2};
    A.projects[3].todos[2] = (Todo){"Task 4-3", false, 3};
    A.projects[3].todos[3] = (Todo){"Task 4-4", true, 4};

    // Project Five todos
    A.projects[4].todos[0] = (Todo){"Task 5-1", false, 1};
    A.projects[4].todos[1] = (Todo){"Task 5-2", false, 2};

    // Project Six todos
    A.projects[5].todos[0] = (Todo){"Task 6-1", true, 1};
    A.projects[5].todos[1] = (Todo){"Task 6-2", true, 2};
    A.projects[5].todos[2] = (Todo){"Task 6-3", false, 3};

    // Project Seven todos
    A.projects[6].todos[0] = (Todo){"Task 7-1", false, 1};

    // Project Eight todos
    A.projects[7].todos[0] = (Todo){"Task 8-1", true, 1};
    A.projects[7].todos[1] = (Todo){"Task 8-2", true, 2};

    // Project Nine todos
    A.projects[8].todos[0] = (Todo){"Task 9-1", false, 1};
    A.projects[8].todos[1] = (Todo){"Task 9-2", false, 2};
    A.projects[8].todos[2] = (Todo){"Task 9-3", true, 3};

    // Project Ten todos
    A.projects[9].todos[0] = (Todo){"Task 10-1", true, 1};
    A.projects[9].todos[1] = (Todo){"Task 10-2", false, 2};

    return A;
}
// Predefined: DO NOT TOUCH

void problem_29() {
    // Predefined: DO NOT TOUCH
    Person data = problem_29_init();
    Project highestTodoProject;
    // Predefined: DO NOT TOUCH

    // Step 1: Loop through all projects in `data` and find the project
    // with the highest number of todos
    // Initialize a max variable to -1

    // Step 2: Use a for loop with variable x from 0 to data.projectCount

    // Step 3: Check if current project's todoCount is greater than max

    // Step 4: If greater, assign this project to highestTodoProject

    // Step 5: Update max to current project's todoCount

    // Step 6: Print projectName using highestTodoProject to verify

    // Predefined: DO NOT TOUCH
    // Free allocated memory
    for (int i = 0; i < data.projectCount; i++) {
        free(data.projects[i].todos);
    }
    free(data.projects);
    // Predefined: DO NOT TOUCH
}

// Predefined: DO NOT TOUCH
Person problem_30_init() {
    // Pre-initialize Person with projects that have room for more todos
    Person A = {"Test Person", malloc(sizeof(Project) * 3), 3, 3};

    // Initialize 3 projects with capacity for more todos
    A.projects[0] = (Project){"Project Alpha", malloc(sizeof(Todo) * 5), 2, 5};
    A.projects[1] = (Project){"Project Beta", malloc(sizeof(Todo) * 4), 1, 4};
    A.projects[2] = (Project){"Project Gamma", malloc(sizeof(Todo) * 6), 3, 6};

    // Initialize existing todos
    // Project Alpha todos (2 out of 5 capacity)
    A.projects[0].todos[0] = (Todo){"Task A1", false, 1};
    A.projects[0].todos[1] = (Todo){"Task A2", true, 2};

    // Project Beta todos (1 out of 4 capacity)
    A.projects[1].todos[0] = (Todo){"Task B1", false, 1};

    // Project Gamma todos (3 out of 6 capacity)
    A.projects[2].todos[0] = (Todo){"Task G1", true, 1};
    A.projects[2].todos[1] = (Todo){"Task G2", false, 2};
    A.projects[2].todos[2] = (Todo){"Task G3", true, 3};

    return A;
}
// Predefined: DO NOT TOUCH

// Insert a todo at the end of a project's todo array
void insertLast(Project *project, Todo newTodo) {
    // Step 1: Check if there's capacity (todoCount < todoCapacity)

    // Step 2: Assign newTodo to the project's todos at index todoCount

    // Step 3: Increment the project's todoCount
}

void problem_30() {
    // Predefined: DO NOT TOUCH
    Person data = problem_30_init();
    int targetProjectIndex = 1; // Target Project Beta
    // Predefined: DO NOT TOUCH

    // Step 1: Construct a new Todo with description "New Task",
    // isFinished false, and priority 5
    // Use structure initialization syntax: {"New Task", false, 5}

    // Step 2: Use insertLast() to add newTodo to the project
    // at targetProjectIndex
    // Pass the address of the project using &data.projects[targetProjectIndex]

    // Step 3: Print the updated todo count to verify

    // Predefined: DO NOT TOUCH
    // Free allocated memory
    for (int i = 0; i < data.projectCount; i++) {
        free(data.projects[i].todos);
    }
    free(data.projects);
    // Predefined: DO NOT TOUCH
}

// Predefined: DO NOT TOUCH
Person *problem_31_init() {
    // Pre-initialize Person with 6 projects with specific todoCounts
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, "Bob");
    p->projects = (Project *)malloc(sizeof(Project) * 6);
    p->projectCount = 6;
    p->projectCapacity = 6;

    // Initialize projects with different todoCounts: {2, 9, 3, 7, 10, 5}
    strcpy(p->projects[0].projectName, "Project Alpha");
    p->projects[0].todos = (Todo *)malloc(sizeof(Todo) * 2);
    p->projects[0].todoCount = 2;
    p->projects[0].todoCapacity = 2;

    strcpy(p->projects[1].projectName, "Project Beta");
    p->projects[1].todos = (Todo *)malloc(sizeof(Todo) * 9);
    p->projects[1].todoCount = 9;
    p->projects[1].todoCapacity = 9;

    strcpy(p->projects[2].projectName, "Project Gamma");
    p->projects[2].todos = (Todo *)malloc(sizeof(Todo) * 3);
    p->projects[2].todoCount = 3;
    p->projects[2].todoCapacity = 3;

    strcpy(p->projects[3].projectName, "Project Delta");
    p->projects[3].todos = (Todo *)malloc(sizeof(Todo) * 7);
    p->projects[3].todoCount = 7;
    p->projects[3].todoCapacity = 7;

    strcpy(p->projects[4].projectName, "Project Epsilon");
    p->projects[4].todos = (Todo *)malloc(sizeof(Todo) * 10);
    p->projects[4].todoCount = 10;
    p->projects[4].todoCapacity = 10;

    strcpy(p->projects[5].projectName, "Project Zeta");
    p->projects[5].todos = (Todo *)malloc(sizeof(Todo) * 5);
    p->projects[5].todoCount = 5;
    p->projects[5].todoCapacity = 5;

    return p;
}
// Predefined: DO NOT TOUCH

// Sort projects by todoCount in ascending order
void problem_31() {
    // Predefined: DO NOT TOUCH
    Person *personPtr = problem_31_init();
    printf("\nOriginal order:\n");
    for (int i = 0; i < personPtr->projectCount; i++) {
        printf("%s: %d todos\n", personPtr->projects[i].projectName,
               personPtr->projects[i].todoCount);
    }
    // Predefined: DO NOT TOUCH

    // Step 1: Implement bubble sort to sort projects by todoCount
    // in ascending order

    // Step 2: Outer loop - iterate through all projects
    // Use i from 0 to projectCount - 1

    // Step 3: Inner loop - compare adjacent projects
    // Use j from 0 to projectCount - i - 1

    // Step 4: Compare todoCount of current and next project
    // If current > next, swap them

    // Step 5: Swap the two projects using a temporary variable
    // Create temp, assign projects[j] to it
    // Assign projects[j+1] to projects[j]
    // Assign temp to projects[j+1]

    // Predefined: DO NOT TOUCH
    // Print sorted order
    printf("\nSorted order (by todoCount):\n");
    for (int i = 0; i < personPtr->projectCount; i++) {
        printf("%s: %d todos\n", personPtr->projects[i].projectName,
               personPtr->projects[i].todoCount);
    }
    // Predefined: DO NOT TOUCH

    // Predefined: DO NOT TOUCH
    // Free all allocated memory
    for (int i = 0; i < personPtr->projectCount; i++) {
        free(personPtr->projects[i].todos);
    }
    free(personPtr->projects);
    free(personPtr);
    // Predefined: DO NOT TOUCH
}

int main() {
    printf("36 Progressive Pointer and Structure Problems\n");
    printf("=== INSTRUCTIONS ===\n");
    printf("Uncomment the problems you want to work on below.\n");
    printf("You can work on them in any order!\n");
    printf("Comment out (with //) the ones you're not testing.\n\n");

    // ===== 0a-0e: Pointer Basics (Warm-up) =====
    // problem_0a();
    // problem_0b();
    // problem_0c();
    // problem_0d();
    // problem_0e();

    // ===== 1-3: Pointer Dereferencing =====
    // problem_1();
    // problem_2();
    // problem_3();

    // ===== 4-6: Memory Allocation Basics =====
    // problem_4();
    // problem_5();
    // problem_6();

    // ===== 7-8: Field Access & Manipulation =====
    // problem_7();
    // problem_8();

    // ===== 9-11: Field Updates =====
    // problem_9();
    // problem_10();
    // problem_11();

    // ===== 12-16: String Operations =====
    // problem_12();
    // problem_13();
    // problem_14();
    // problem_15();
    // problem_16();

    // ===== 17-19: Structure Assignment =====
    // problem_17();
    // problem_18();
    // problem_19();

    // ===== 20-25: Function Parameters =====
    // problem_20();
    // problem_21();
    // problem_22();
    // problem_23();
    // problem_24();
    // problem_25();

    // ===== 26-27: Dynamic Memory Management =====
    // problem_26();
    // problem_27();

    // ===== 28-31: Advanced Operations =====
    // problem_28();
    // problem_29();
    // problem_30();
    // problem_31();

    return 0;
}
