#include <stdio.h>

int main(){
    int round,i,j,k,maxin,minin;
    scanf("%d",&round);
    // ตรวจว่าเป็นบวก
    if (round <= 0 || round > 50) {
        printf("Error: Number must be a positive integer not exceeding 50.\n");
        return 1;
    }
    float num[51],maxval,minval,avg,sum = 0;
    float *pNum = num;
    //รับค่าตามจน.รอบ
    for(i=0;i<round;i++){
        scanf("%f",pNum+i);
        sum += *(pNum+i);
    }
    //เช็คค่าสูงสุด
    maxval = *pNum;
    maxin = 0;
    for(j=1;j<round;j++){
        if (*(pNum+j)>maxval){
            maxval = *(pNum+j);
            maxin = j;
        }
    }
    //เช็คค่าต่ำสุด
    minval = num[0];
    minin = 0;
    for(k=1;k<round;k++){
        if (*(pNum+k)<minval){
            minval = *(pNum+k);
            minin = k;
        }
    }
    //หาค่าเฉลี่ย
    avg = sum/round;

    printf("Maximum value: %.2f\n",maxval);
    printf("Minimum value: %.2f\n",minval);
    printf("Maximum index: %d\n",maxin);
    printf("Minimum index: %d\n",minin);
    printf("Average: %.2f\n",avg);
    //ลำกับย้อนกลับ
    printf("Reverse order: ");
    for(i= round -1 ;i>=0;i--){
        printf("%.2f ",*(pNum+i));
    }
    printf("\n");
    //ค่าทุกค่าที่มากกว่่าค่าเฉลี่ย
    printf("Above average list: ");
    for(j= round -1 ;j>=0;j--){
        if(avg<*(pNum+j)){
        printf("%.2f ",*(pNum+j));
        }
    }
    printf("\n");
    //ทุกคู่อันดับ ใน array ที่มีค่าติดลบ
    printf("Negative coordinates: ");
    for(i=0;i<round;i++){
        for(j= i+1;j<round;j++){
            if(*(pNum+i) <0 && *(pNum+j) <0){
                printf("(%.2f, %.2f), ",*(pNum+i),*(pNum+j));
            }
        }
    }
    return 0;
}

