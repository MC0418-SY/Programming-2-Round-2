# [CIS 1201 MIDTERM #2] Data Governance

by Sabrinah Yonell Yap

You are hired as a data governance officer to clean and validate new student records.

At the beginning of the program, ask for user input three strings:

1. name -> complete name (first, middle, last names -> no commas nor periods)
2. id -> alphanumeric
3. dob -> date of birth (in MM/DD/YYYY format)

You are to create a function `bool cleanRecords(char name[], char id[], char dob[])` that accepts the three strings above as parameters, cleans the records and determines whether the given record is valid or not.

The cleaning tasks involve:

1. Converting the name field to title case. The original string can be of mixed cases everywhere  
    1. Example: `caTE yoNEll sAbADo` -> change to `Cate Yonell Sabado`
    2. To be handled with the function `void cleanName(char str[]);`
2. Converting the date of birth field to YYYY-MM-DD format. The original string here is of MM/DD/YYYY format.  
    1. Example: `10/01/2025` -> change to `2025-10-01`
    2. To be handled with the function `void cleanDOB(char str[]);`

The validation tasks involve:

1. Date of birth field string (cleaned version) is beyond the current date (October 29, 2025) - mark as invalid  
    1. This check will be handled by the function `bool isValidDOB(char str[]);`
2. ID field contains alphabetic characters - mark as invalid  
    1. This check will be handled by the function `bool isValidID(char str[]);`

**Use ONLY the following functions below in building your code for this problem. STRICTLY NO OTHER FUNCTIONS ALLOWED.**

- **string.h -> memcpy(), strcpy(), strcat(), strlen(), strcmp()**
- **ctype.h -> isuper(), islower(), isspace(), toupper(), tolower()**
- **stdlib.h -> malloc(), calloc(), free()**

**Submissions violating this constraint will be given a zero (0) for this problem.**

Sample Output 1

```
Input user details:
Name: caTE yoNEll sAbADo
ID  : 123456
DOB : 01/01/2000

Cleaned result:
Name: Cate Yonell Sabado
ID  : 123456
DOB : 2000-01-01
Record is VALID!
```

Sample Output 2

```
Input user details:
Name: grAN roBERT NOOB
ID  : 1234aa
DOB : 10/10/2010

Cleaned result:
Name: Gran Robert Noob
ID  : 1234aa
DOB : 2010-10-10
Record is INVALID!
```

Sample Output 3

```
Input user details:
Name: ambot nimo sir
ID  : 555555
DOB : mm/dd/yyyy

Cleaned result:
Name: Ambot Nimo Sir
ID  : 555555
DOB : yyyy-mm-dd
Record is INVALID!
```
