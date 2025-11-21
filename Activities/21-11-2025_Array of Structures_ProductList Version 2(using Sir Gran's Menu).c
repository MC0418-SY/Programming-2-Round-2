#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int prodID;
    char prodName[20];
    float prodPrice;
    int ProdQty;
} Product;

typedef struct {
    Product products[MAX];
    int count;
} ProductList;

void initProductList(ProductList *list);
//set list count to 0
Product createProduct(int id, char name[], float price, int qty);
bool addProduct(ProductList *list, Product p);
bool restock(ProductList *list, int id, int qty);
bool sell(ProductList *list, int id, int qty);
void displayProduct(Product p);
void displayProducts(ProductList *list);


int main(){
    int choiceMenu1, choiceMenu2, choiceMenu3, quantity;
    char option1[2][20] = {"Manage", "Sell"};
    char option2[3][20] = {"Add Product", "Restock", "Display Products"};
    
    ProductList list;
    initProductList(&list);
    
    int choice, manageChoice, id, qty;
    char name[20];
    float price;
    
    addProduct(&list, createProduct(1, "Milk", 550.50, 50));
    addProduct(&list, createProduct(2, "Crackers", 25.50, 80));
    addProduct(&list, createProduct(3, "Beef", 10.0, 10));
    
    do {
        printf("Main Menu\n");
        for(int i = 0; i < 2; ++i) {
            printf("[%d] %s\n", i+1, option1[i]);
        }
        printf("Enter your choice (0 - to EXIT): ");
        scanf("%d", &choiceMenu1);
        
        switch(choiceMenu1){
            case 0:
                printf("Danke schön!\nExiting...");
                break;
            case 1:
                do {
                    printf("\n\nMenu: Manage\n");
                    for(int i = 0; i < 3; ++i) {
                        printf("[%d] %s\n", i+1, option2[i]);
                    }
                    printf("Enter your choice (0 - to EXIT): ");
                    scanf("%d", &choiceMenu2);
                    
                    switch(choiceMenu2){
                        case 0:
                            printf("Exit Manage Menu..\n");
                            break;
                        case 1:
                            printf("Enter product ID: ");
                            scanf("%d", &id);
                            printf("Enter product name: ");
                            scanf("%s", name);
                            printf("Enter product price: ");
                            scanf("%f", &price);
                            printf("Enter quantity: ");
                            scanf("%d", &qty);

                            Product p = createProduct(id, name, price, qty);
                    
                            if(addProduct(&list, p))
                                printf("Product added!\n\n");
                            else
                                printf("List full!\n");
                            break;
                        case 2:
                            printf("Enter product ID: ");
                            scanf("%d", &id);
                            printf("Enter quantity to add: ");
                            scanf("%d", &qty);
        
                            if (restock(&list, id, qty))
                                printf("Restocked!\n\n");
                            else
                                printf("Product not found!\n");
                            break;
                        case 3:
                            displayProducts(&list);
                            printf("\n");
                            break;
                        default:
                            printf("Invalid Input\n\n");
                    }
                    
                } while(choiceMenu2 != 0);
                
                
                break;
            case 2:
                printf("\n\nMenu: Sell\n");
                do {
                    displayProducts(&list);
                
                    printf("\n");
                    printf("Enter product ID: ");
                    scanf("%d", &id);
                    printf("Enter quantity to sell: ");
                    scanf("%d", &qty);
        
                    if (sell(&list, id, qty))
                        printf("Sold!\n\n");
                    else
                        printf("Insufficient Quantity. Too bad!\n\n");
                    
                } while(choiceMenu2 != 0);
                
                break;
            
            default:
                printf("Invalid Input.\n\n");
        }
    } while(choiceMenu1 != 0);
    
    
    return 0;
}

void initProductList(ProductList *list){
    list->count = 0;
}

void displayProduct(Product p){
    printf("%-10d | %-15s | ₱ %-15.2f | %-10d\n", p.prodID, p.prodName, p.prodPrice, p.ProdQty);
}

void displayProducts(ProductList *list){
    printf("%-10s | %-15s |   %-15s | %-10s\n", "ID", "Name", "Price", "Quantity");
    for(int i = 0; i < list->count; ++i){
        displayProduct(list->products[i]);
    }
    
}

Product createProduct(int id, char name[], float price, int qty){
    Product memy;
    memy.prodID = id;
    strcpy(memy.prodName, name);
    memy.prodPrice = price;
    memy.ProdQty = qty;
    return memy;
}

bool addProduct(ProductList *list, Product p){
    if(list->count > MAX){
        return false;
    }

    list->products[list->count++] = p;
    return true;
}

bool restock(ProductList *list, int id, int qty){
    if(list->count > MAX){
        return false;
    }

    for(int i = 0; i < list->count; ++i){
        if(id == list->products[i].prodID){
            list->products[i].ProdQty += qty;
            break;
        }
    }
    return true;
}

bool sell(ProductList *list, int id, int qty){
    for(int i = 0; i < list->count; i++){
        if(list->products[i].prodID == id){
            if(list->products[i].ProdQty < qty)
                return false;
            list->products[i].ProdQty -= qty;
            return true;
        }
    }
    return false;
}


