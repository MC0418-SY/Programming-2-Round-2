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

//Additional Functions to make
// deleteProduct()
// updatePrice()
// InsertAt


int main(){
    ProductList list;
    initProductList(&list);

    int choice, manageChoice, id, qty;
    char name[20];
    float price;
    
    addProduct(&list, createProduct(1, "Milk", 550.50, 50));
    addProduct(&list, createProduct(2, "Crackers", 25.50, 80));
    addProduct(&list, createProduct(3, "Beef", 10.0, 10));

    while (1) {
        printf("MAIN MENU\n");
        printf("[1] Manage\n");
        printf("[2] Sell\n");
        printf("Enter choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Danke schön!\n");
            break;
        }

        if (choice == 1) {
            printf("\nMENU:MANAGE\n");
            printf("[1] Add Product\n");
            printf("[2] Restock Product\n");
            printf("[3] Display Products\n");
            printf("Enter choice (0 to exit): ");
            scanf("%d", &manageChoice);

            if (manageChoice == 0){
                printf("\n");
                continue;
            } 

            switch (manageChoice) {
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
                        printf("List full!\n\n");
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
                    printf("Invalid choice.\n");
            }
        }

        if (choice == 2) {
            printf("\nMENU:SELL\n");
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
        }
    }

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
            if(list->products[i].ProdQty < qty){
                return false;
            } else {
                list->products[i].ProdQty -= qty;
                return true;
            }
        }
    }
    return false;
}


