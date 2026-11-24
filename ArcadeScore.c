#include<stdio.h>
#include<string.h>
#define MAX_PLAYERS 100
#define NAME_LEN 50
#define TITLE_LEN 50
typedef struct{
    char name[NAME_LEN];
    int score;
    char title[TITLE_LEN];
}Players;
int title(int score){
    if(score<300){
        return 0;
    }
    else if(score>=300&&score<500){
        return 1;
    }
    else if(score>=500){
        return 2;
    }
}
int main(){
    Players players[MAX_PLAYERS];
    FILE *fp = fopen("Text.txt", "r");
    int n=0;
    while(n<MAX_PLAYERS&&(fscanf(fp, "%[^,],%d", players[n].name, &players[n].score))==2){
        int code = title(players[n].score);
        if(code==0){
            strcpy(players[n].title, "Rookie");
        }
        if(code==1){
            strcpy(players[n].title, "Challenger");
        }
        if(code==2){
            strcpy(players[n].title, "Arcade Legend");
        }
        n++;
    }
    fclose(fp);
    printf("%-20s %-8s %s\n", "Name", "Score", "Title");
    printf("------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-8d %s\n", players[i].name, players[i].score, players[i].title);
    }
    return 0;
}
