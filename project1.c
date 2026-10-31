#include <stdio.h>
typedef struct{
    int id;
    char name[50];
    int salary;
    int departmentCode;
}Employee;
Employee readEmployee(void){
    Employee E;
    printf("Enter the record");
    scanf("%d %s %d %d", &E.id, E.name, &E.salary, &E.departmentCode);
    return E;
}
void displayAll(Employee emp[], int n) {
    printf("\n%-8s %-20s %-12s %-6s\n", "ID", "Name", "Salary", "Dept");
    printf("------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-8d %-20s %-12.2f %-6d\n",
               emp[i].id, emp[i].name, emp[i].salary, emp[i].departmentCode);
    }
}
int topperIndex(Employee emp[], int n){
    int top = 0;
    for(int i=0; i<n; i++){
        if(emp[i].salary>emp[top].salary){
            top=i;
        }
    }
    return top;
}
int countEmployee(Employee emp[], int n, int code){
    int count=0;
    for(int i=0; i<n; i++){
        if(emp[i].departmentCode==code){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    printf("Enter the size of the structure\n");
    Employee emp[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        emp[i]=readEmployee();
    }
    int topper=topperIndex(emp, n);
    printf("Highest paid employee is\n");
    printf("%d %s %d %d\n", emp[topper].id, emp[topper].name, emp[topper].salary, emp[topper].departmentCode);
    printf("Enter ID for search\n");
    int target;
    scanf("%d", &target);
    int flag = -1;
    for(int i=0; i<n; i++){
        if(emp[i].id==target){
            flag=i;
        }
    }
    if(flag!=-1){
        printf("Target found for object number %d\n", flag);
        printf("%d %s %d %d\n", emp[flag].id, emp[flag].name, emp[flag].salary, emp[flag].departmentCode);
    }
    else{
        printf("Target not found\n");
    }
    printf("Enter the department code to count off\n");
    int code;
    scanf("%d", &code);
    int count = countEmployee(emp, n, code);
    printf("Number of employees found with this department code are %d", count);
    return 0;
}














