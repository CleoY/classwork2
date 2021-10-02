//gcc employeeMain.c employeeTable.c employeeOne.c -o employeeMainONE
//gcc employeeMain.c employeeTable.c employeeTwo.c -o employeeMainTWO
 
#include <string.h> 
#include <stdlib.h> 
#include "employee.h" 

int main(void){ 
    
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * targetPhone);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double targetSalary);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;
 
    PtrToEmployee matchPtr;


    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);    
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
    else 
        printf("Employee ID is NOT found in the record\n");
 

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n"); 

    
    //Example 1: Phone number WAS found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749"); 
    if (matchPtr != NULL) 
        printf("Employee phone number 714-555-2749 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("The phone number 714-555-2749 was NOT found in the record\n"); 
    

    //Example 2: Phone number was NOT found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "888-888-8888"); 
    if (matchPtr != NULL) 
        printf("Employee phone number 888-888-8888 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("The phone number 888-888-8888 was NOT found in the record\n"); 


    //Example 3: Given salary WAS found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50); 
    if (matchPtr != NULL) 
        printf("Employee salary of $4.50 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee salary of $4.50 was NOT found in the record\n"); 

    
    //Example 4: Given salary was NOT found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 14.70); 
    if (matchPtr != NULL) 
        printf("Employee salary of $14.70 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee salary of $14.70 was NOT found in the record\n"); 

    return EXIT_SUCCESS; 
}