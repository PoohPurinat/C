#include <stdio.h>

int main(){
    char data[51];
    scanf("%50s",data);
    // ตรวจ่าความยาวข้อความอยู่ในช่วงที่กำหนด
    if (data < 1 || data > 50) {
        printf("Error: length must be between 1 and 50 characters.\n");
        return 1;
    }
    //หาความยาว
    int size = 0,consonants = 0,vowels = 0 ,up = 0 ,low = 0;
    while(data[size] != '\0'){
        //หาสระกับพยัญชนะ
        char ch = data[size];
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
           ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ){
            vowels++;
        }else if ((ch >= 'b' && ch <= 'z') || (ch >= 'B' && ch <= 'Z')) {
            consonants++;
        }
        //เช็คตัวเล็กตัวใหญ่
        if (ch >= 'A' && ch <= 'Z'){
            up++;
        }
        else if (ch >= 'a' && ch <= 'z'){
            low++;
        }
        size++;
    }
    //เช็คว่าเป็นpalindrome
    int ispalindrome = 1;
    for(int i=0;i<size/2;i++){
        if(data[i] != data[size-i-1]){
            ispalindrome = 0;
            break;
        }
    }
    printf("Size of input string is %d\n",size);
    printf("#Consonants: %d\n",consonants);
    printf("#Vowels: %d\n",vowels);
    printf("#Upper-case letters: %d\n",up);
    printf("#Lower-case letters: %d\n",low);
    printf("Is a palindrome string: ");
    if(ispalindrome){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
