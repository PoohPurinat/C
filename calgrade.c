/*
NAME: Purinat Wanthanathanya
SID: 6709650565
*/
#include <stdio.h>

int main(){
    int grade;
    scanf("%d",&grade);
    if(grade >= 90){
        printf("A");
    }
    else if(grade >= 85){
        printf("B+");
    }
    else if(grade >= 75){
        printf("B");
    }
    else if(grade >= 70){
        printf("C+");
    }
    else if(grade >= 60){
        printf("C");
    }
    else{
        printf("See you next semester");
    }
    return 0;
}
