#include<stdio.h>
#include<string.h>
typedef struct{
    char name[50];
    int score;
}Players;
int main(){
    printf("Enter the details\n");
    Players players[10];
    for(int i=0; i<3; i++){
        printf("Enter for player number %d\n", i);
        scanf("%s %d", players[i].name, &players[i].score);
    }
    printf("Writing....\n");
    FILE *fp = fopen("Players.dat", "wb");
    if(fp==NULL){
        perror("Error");
        return 1;
    }
    fwrite(players, sizeof(Players), 3, fp);
    fclose(fp);
    printf("Succesfully written\n");
    FILE *rp = fopen("Players.dat", "rb");
    Players back[10];
    int n;
    n= fread(back, sizeof(Players), 10, rp);
    fclose(rp);
    for(int i=0; i<n; i++){
        printf("%-20s %-8d %s\n", back[i].name, back[i].score);
    }
    return 0;
}