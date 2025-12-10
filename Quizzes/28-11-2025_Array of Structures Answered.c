//1. Defining and Allocating
typedef struct {
    int id;
    float price;
} Product;

Product *prod = malloc(sizeof(Product) * 1);

prod->id = 1;
prod->price = 1.5;

// You can also do this.
// The only difference is that ur dereferencing the *prod to directly access the values
(*prod).id = 5;
(*prod).price = 2.5;


//2. Dynamic Array
printf("Enter a number: ");
int n;
scanf("%d", &n);

Product *prods = malloc(sizeof(Product) * n);

//3. POinter Arithmetic Access
//Index Array Access
Product *ptr; //This shit points to the first element of an array of Products
ptr[2].price;

//Pointer Arithmetic Access
*(ptr + 2).price;

//4. Initialization
void initializeArray(struct Product *arr, int size){
    for(int i = 0; i < size; ++i){
        arr[i].price = 0.0;
        arr[i].id = i;
    }
}

//5. Reallocating with realloc
p_array = realloc(p_array, sizeof(Product) * 20);


//6. Deep Copy vs. SHallow Copy
typedef struct {
    char *name;
    int age;
} Person

Person P = malloc(sizeof(Person));
char *name = malloc(sizeof(char) * 30)

strcpy(name, "Alice");
strcpy(p->name, name);


//7. Structs containing Arrays
typedef struct{
    int roomNumber;
    Student *studs;
    int studentCount;
} Classroom;

Classroom *createClassroom(int size){
    Classroom *classA = malloc(sizeof(Classroom));
    
    classA->students = malloc(sizeof(Student) * size);
    classA->studentCount = 0;
    
    return classA;
    
}

Classroom createClassroom(int size){
    Classroom classA;
    
    classA.students = malloc(sizeof(Student) * size);
    classA.studentCount = 0;
    
    return classA;
}

//8. Filtering Data
Product *filterData(Product *data, int count, int *retCount){
    Product tempData[100];
    *retCount = 0;
    Product *filtered;
    
    for(int i = 0; i < count; ++i){
        if(data[i].price > 100){
            tempData[(*retCount)++] = data[i];
        }
    }
    
    filtered = malloc(sizeof(Product) * (*retCount));
    memcpy(filtered, tempData, sizeof(Product) * (*retCount));
    
    return filtered;
}

//9. The "Free" Hierarchy
void freePeople(Person * people, int count){
    free(people);
}

//You can free each of the people, but according to sir Gran, "ngano ipa lisod imonng kinabuhi?"















