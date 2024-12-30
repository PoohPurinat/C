/*
NAME: Purinat Wanthanathanaya
SID: 6709650565
*/
#include <stdio.h>



int main(){

    int N,time[20],hour,min,sec,remainsec;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&time[i]);
        }
        for(int i=0;i<N;i++){
        sec = time[i];
        hour = sec/3600;
        min = (sec%3600)/60;
        remainsec = sec%60;
        printf("%d %d %d\n",hour,min,remainsec);
        }

    return 0;
}
