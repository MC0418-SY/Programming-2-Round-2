#include <stdio.h>
#define MAX 10

typedef struct {
    int prodID;
    char prodName[20];
    int prodPrice;
    int ProdQty;
} Product;

typedef struct {
    Product products[MAX];
    int count;
} ProductList;

void initProductList(ProductList *list);
//set list count to 0
Product createProduct(int id, char name[], float price, int qty);
bool addProduct(Product *list, Product p);
bool restock(ProductList *list, int id, int qty);
bool sell(ProductList *list, int id, int qty);
void displayProduct(Product p);
void displayProducts(ProductList *list);


int main(){
    
     while (1) {
        printf("\nStudent Records Manager\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Find Student\n");
        printf("4. Update GPA\n");
        printf("5. Display All\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
    
        switch(choice){
            case 1:
                printf("Enter the students' ID: ");
                scanf("%d", &student.id);
                printf("Enter the new student's name: ");
                scanf("%s", &student.name);
                printf("Enter the GPA: ");
                scanf("%f", &student.gpa);
                addStudent(&list, student);
                printf("Student added successfully.\n");
            case 2:
                //deleteStudent();
                
            break;
            case 3:
                //findStudent();
                int findId;
                printf("Enter ID to find: ");
                scanf("%d", &findId);
                findStudent(&list, findId);
                
            break;
            case 4:
                //updateGPA();
                int matchId;
                printf("Enter ID to update GPA: ");
                scanf("%d", &matchId);
                printf("Enter new GPA: ");
                scanf("%d", &newGPA);
                updateGPA(&list, findId, newGPA);
                printf("GPA updated for student ID %d", matchId);
            break;
            case 5:
                displayStudents(&list);
            break;
            case 6:
                break;
        }
    
    
    
    return 0;
}

void initProductList(ProductList *list){
    list->count = 0;
}

Product createProduct(int id, char name[], float price, int qty){
    Product memy;
    memy.prodID = id;
    strcpy(memy.prodName, name);
    memy.prodPrice = price;
    memy.ProdQty = qty;
    return memy;
}

bool addProduct(Product *list, Product p){
    if(list->count < MAX){
        list->products[list->count++] = p;
    }
}

bool restock(ProductList *list, int id, int qty){
    
    
    
    
}


