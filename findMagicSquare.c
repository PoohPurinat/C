#include <stdio.h>

int i,j;

void readSquare(int arr[8][8],int N){
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

int  findMagicNumber(int arr[8][8],int N){
    //�礤�����е��˹�
    int checkNum[N*N+1];
    for(i=1;i<=N*N;i++){
        checkNum[i] = 0;
    }
    //����ҵ���Ţ����㹪�ǧ����˹�
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            int num = arr[i][j];
            if (num < 1 || num > N*N || checkNum[num]){
                return -1; //�觡�Ѻ��� -1 ���ͺ͡�������� magic square
            }
            checkNum[num] = 1;//�Ţ���١�������
        }
    }
    //�ӹǳ���������ͧ���������� �������  �����鹷�§���
    int magicSum = 0 ;
    for(j=0;j<N;j++){
        magicSum += arr[0][j];
    }
    //��Ǩ�ͺ������������
    for(i=0;i<N;i++){
        int rowSum = 0;
        for(j=0;j<N;j++){
            rowSum += arr[i][j];
        }
        if(rowSum != magicSum){
            return -1;
        }
    }
    //��Ǩ�ͺ��������Ф������
    for(j=0;j<N;j++){
        int columnSum = 0;
        for(i=0;i<N;i++){
            columnSum += arr[i][j];
        }
        if(columnSum != magicSum){
            return -1;
        }
    }
    //��Ǩ�ͺ������ͧ���§ ��ѡ
    int diagonal1Sum = 0;
    for(i=0;i<N;i++){
        diagonal1Sum += arr[i][i];
    }
    if(diagonal1Sum != magicSum){
        return -1;
    }
    //��Ǩ�ͺ������ͧ���§ �ͧ
    int diagonal2Sum = 0;
    for(i=0;i<N;i++){
        diagonal2Sum += arr[i][N-i-1];
    }
    if(diagonal2Sum != magicSum){
        return -1;
    }

    return magicSum;
}

int main(){

    int arr[8][8];
    int N;

    scanf("%d", &N);
    readSquare(arr, N);

    int magicNumber = findMagicNumber(arr, N);

    if (magicNumber == -1) {
        printf("Your square is NOT a magic square.");
    } else {
        printf("Your square is a magic square!! with the magic constant = %d.", magicNumber);
    }

    return 0;
}
