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
    Product p1;
    ProductList list;
    
    
    p1 = createProduct(1, "Milk", 10.50, 50);
    
    
    addProduct(&list, p1);
    displayProducts(&list);
    
    return 0;
}

void initProductList(ProductList *list){
    list->count = 0;
}

void displayProduct(Product p){
    printf("%d\t%s\t%.2f\t%d\n", p.prodID, p.prodName, p.prodPrice, p.ProdQty);
}

void displayProducts(ProductList *list){
    printf("ID\tName\tPrice\tQuantity\n");
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
            list->products[i].ProdQty + qty;
            break;
        }
    }
    return true;
}

bool sell(ProductList *list, int id, int qty){
    if(list->count > MAX){
        return false;
    }
    
    for(int i = 0; i < list->count; ++i){
        if(id == list->products[i].prodID){
            if(list->products[i].ProdQty - qty < 0){
                return false;
            } else {
                list->products[i].ProdQty - qty;
                break; 
                return true;
            }
            
        }
    }
    
    
}

