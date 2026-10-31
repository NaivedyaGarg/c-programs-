#include<stdio.h>
#include<ctype.h>
#include<string.h>
void reverseString(char str[]);
void convertToUpper(char str[]);
int count(char str[]);
void palindrome(char str[]);
int main(){
    int restart = 1;
    char str[100];
    int choice;
    int cont;
    while(cont){
        printf("Enter the text\n");
        fgets(str, sizeof(str), stdin);
        while(restart){
            printf("=====THE MENU====\n");
            printf("1. Reverse the text 2. Convert to UPPERCASE 3. Count words 4. Check palindrome 5.Enter new text\n");
            printf("Enter the choice\n");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    reverseString(str);
                    break;
                case 2:
                    convertToUpper(str);
                    break;
                case 3:
                    int words = count(str);
                    printf("Number of words %d\n", words);
                    break;
                case 4:
                    palindrome(str);
                    break;
                case 5:
                    restart = 0;
                default:
                    printf("Invalid choice\n");
                    break;
            }
        }
        printf("Enter 1 to wrtie a new text\n");
        scanf("%d", &cont);
        if(cont!=1){
            break;
        }
    }
    printf("SHUTTING DOWN.....\n");
    return 0;
}
void reverseString(char str[]){
    int length = (int)strlen(str);
    for(int i =0; i<length/2; i++){
        char c = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = c;
    }
    printf("%s\n", str);
}
void convertToUpper(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        char c = str[i];
        if(islower(c)){
            str[i] = toupper(c);
        }
    }
    printf("%s\n", str);
}
int count(char str[]){
    int i = 0;
    int words = 0;
    int in_word=0;
    while (str[i] != '\0' && str[i] != '\n') {
        char c = str[i];

        if (!isspace(c)) {
            // If it's a non-whitespace character and we aren't already in a word, it's a new word start
            if (!in_word) {
                words++;
                in_word = 1; 
            }
        } else {
            // When we hit whitespace, we exit the current word
            in_word = 0;
        }
        i++;
    }
    return words;
}
void palindrome(char str[]){
    int length = (int)strlen(str);
    char b[100];
    strcpy(b,str);
    for(int i =0; i<length/2; i++){
        char c = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = c;
    }
    if(strcmp(str,b)==0){
        printf("It is a palindrome\n");
    }
    else{
        printf("Not a palindrome\n");
    }
}
//END



