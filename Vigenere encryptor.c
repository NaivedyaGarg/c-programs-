#include<stdio.h>
#include <string.h>
#include<ctype.h>
int main(){
    char msg[100];
    int len = 0;
    char key[100];
    char enc[100] = "";
    int keyindex = 0;
    printf("Enter the message\n");
    if (fgets(msg, sizeof(msg), stdin) != NULL) {
        // Remove the trailing newline character from fgets if present
        msg[strcspn(msg, "\n")] = '\0';
    }
    printf("Enter the keyword\n");
    if (fgets(key, sizeof(key), stdin) != NULL) {
        // Remove the trailing newline character from key if present
        key[strcspn(key, "\n")] = '\0';
    }
    int keylen = (int)strlen(key);
    for(int i=0; msg[i]!='\0'; i++){
        char k = key[keyindex%keylen];
        char c = msg[i];
        char en;
        int shift;
        if(isspace(c)){
            en = ' ';
        }
        if(isalpha(c)){
            shift = k-'a';
            en = ((c - 'a' + shift)%26) + 'a';
            keyindex++;
        }
        enc[len]  = en;
        len++;
        enc[len] = '\0';
    }
    printf("The encrypted message is: %s\n", enc);
    return 0;
}