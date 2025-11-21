#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int prodID;
    char prodName[20];
    float prodPrice;
    int prodQty;
} Product;

typedef struct {
    Product products[MAX];
    int count;
} ProductList;

void initProductList(ProductList *list);
Product createProduct(int id, char name[], float price, int qty);

int main() {
    int choiceMenu1, choiceMenu2, choiceMenu3, quantity;
    char option1[2][20] = {"Manage", "Sell"};
    char option2[2][20] = {"Add Product", "Restock"};
    
    ProductList prodList;
    initProductList(&prodList);
    
    prodList.products[prodList.count++] = createProduct(1, "Binagkal", 2.5, 10);
    prodList.products[prodList.count++] = createProduct(2, "Budbud", 20, 10);
    prodList.products[prodList.count++] = createProduct(3, "Ampao", 30, 10);
    
    do {
        printf("Main Menu\n");
        for(int i = 0; i < 2; ++i) {
            printf("[%d] %s\n", i+1, option1[i]);
        }
        printf("Enter your choice (0 - to EXIT): ");
        scanf("%d", &choiceMenu1);
        
        switch(choiceMenu1){
            case 0:
                printf("EXIT");
                break;
            case 1:
                do {
                    printf("\n\nMenu: Manage\n");
                    for(int i = 0; i < 2; ++i) {
                        printf("[%d] %s\n", i+1, option2[i]);
                    }
                    printf("Enter your choice (0 - to EXIT): ");
                    scanf("%d", &choiceMenu2);
                    
                    switch(choiceMenu2){
                        case 0:
                            printf("Exit Manage Menu..\n");
                            break;
                        case 1:
                            printf("%s\n", option2[0]);
                            break;
                        case 2:
                            printf("%s\n", option2[1]);
                            break;
                        default:
                            printf("Invalid Input\n\n");
                    }
                    
                } while(choiceMenu2 != 0);
                
                
                break;
            case 2:
                printf("\n\nMenu: Sell\n");
                do {
                    for(int i = 0; i < prodList.count; ++i) {
                        printf("[%d] %s - Php %.2f - %d pcs.\n", prodList.products[i].prodID, prodList.products[i].prodName, prodList.products[i].prodPrice, prodList.products[i].prodQty);
                    }
                
                    printf("Enter your choice (0 - to EXIT): ");
                    scanf("%d", &choiceMenu3);
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    // do more here to add into the items to buy....
                    
                } while(choiceMenu2 != 0);
                
                break;
            
            default:
                printf("Invalid Input\n\n");
        }
    } while(choiceMenu1 != 0);
    
    
    return 0;
}

void initProductList(ProductList *list) {
    list->count = 0;    
}

Product createProduct(int id, char name[], float price, int qty) {
    Product p;
    
    p.prodID = id;
    strcpy(p.prodName, name);
    p.prodPrice = price;
    p.prodQty = qty;
    
    return p;
}
