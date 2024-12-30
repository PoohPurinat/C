#include <stdio.h>

int main(){
    int mom_height , dad_height;
    double  avgchild_height, max_height , min_height;
    printf("Enter the height of the mother(centimeters):");
    scanf("%d",&mom_height);
    printf("Enter the height of the father(centimeters):");
    scanf("%d",&dad_height);
    if(mom_height > 0 && dad_height>0){
        avgchild_height = (dad_height+mom_height)/2.0;
        min_height = avgchild_height-13.5;
        max_height = avgchild_height+13.5;
        printf("The possible height of the child is between %.1f cm to %.1f cm\n", min_height , max_height);
    }
    else{
        printf("invalid please tryagain");
    }

    return 0;
}
