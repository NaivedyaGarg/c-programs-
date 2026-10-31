#include<stdio.h>
#include<string.h>
typedef struct{
    char name[30];
    char role[20];
    int health;
}Character;
Character readCharacter(void){
    Character c;
    printf("Enter the character details\n");
    scanf("%s %s %d", c.name, c.role, &c.health);
    return c;
}
void displayAll(Character c[], int n){
    printf("\n%-20s %-10s %-6s\n", "Name", "Role", "Health");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10s %-6d\n", c[i].name, c[i].role, c[i].health);
    }
}
float average(Character c[], int n){
    float sum = 0;
    for(int i=0; i<n; i++){
        sum+=c[i].health;
    }
    return sum/n;
}
int countOfCharacterHealth(Character c[], int n, int health){
    int count=0;
    for(int i=0; i<n; i++){
        if(c[i].health>health){
            count++;
        }
    }
    return count;
}
void countOfCharacters(Character c[],int n){
    int count_warrior=0;
    int count_mage=0;
    int count_healer=0;
    for(int i=0; i<n; i++){
        if(strcmp(c[i].role, "Warrior")==0){
            count_warrior++;
        }
        if(strcmp(c[i].role, "Mage")==0){
            count_mage++;
        }
        if(strcmp(c[i].role, "Healer")==0){
            count_healer++;
        }
    }
    printf("The count of roles is\n");
    printf("Warriors: %d, Mage: %d, Healer: %d\n", count_warrior, count_mage, count_healer);
}
int main(){
    int n;
    printf("Enter the size of the structure\n");
    scanf("%d", &n);
    Character c[50];
    for(int i=0; i<n; i++){
        c[i] = readCharacter();
    }
    displayAll(c,n);
    printf("Enter the threshold health\n");
    int health;
    scanf("%d", &health);
    int countofhealth = countOfCharacterHealth(c,n,health);
    printf("The count of characters with health above the threshold is %d\n", countofhealth);
    countOfCharacters(c,n);
    float avg = average(c,n);
    printf("The average of the health of the characters is %0.2f\n",avg);
    printf("END OF PROGRAM\n");
    return 0;
}