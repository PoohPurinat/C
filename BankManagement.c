#include <stdio.h>
#include <string.h>
#define maxcustomers 100

struct Customerinfo{
    int accountNumber;
    char name[50];
    float balance;
};

struct Customerinfo customers[maxcustomers];
int count=0;

void displaymenu(){
        printf("\nBank Management System\n");
        printf("1. Add New Customer\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display All Customers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
}

void addCustomer(){
    if(count<maxcustomers){
        struct Customerinfo newcustomer;

        printf("Enter account number: ");
        scanf("%d",&newcustomer.accountNumber);
        getchar();

        printf("Enter customer name: ");
        fgets(newcustomer.name, sizeof(newcustomer.name), stdin);
        newcustomer.name[strcspn(newcustomer.name, "\n")] = 0;

        printf("Enter initial balance: ");
        scanf("%f", &newcustomer.balance);

        customers[count++] = newcustomer;
        printf("Customer added successfully.\n");
    }else {
        printf("Customer full limit.\n");
    }
}
void deposit(){
    int accn;
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%d", &accn);

    for (int i = 0; i < count; i++) {
        if (customers[i].accountNumber == accn) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                customers[i].balance += amount;
                printf("Deposit successful. New balance: %.2f\n", customers[i].balance);
            } else {
                printf("Invalid deposit amount.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(){
    int accn;
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%d", &accn);

    for (int i = 0; i < count; i++) {
        if (customers[i].accountNumber == accn) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", customers[i].balance);
            } else {
                printf("Invalid withdrawal amount or insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayCustomers() {
    if (count == 0) {
        printf("No customers available.\n");
        return;
    }
    printf("Customer List:\n");
    for (int i = 0; i < count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n",
               customers[i].accountNumber, customers[i].name, customers[i].balance);
    }
}


int main(){
    int choice;

    while(1){
        displaymenu();
        scanf("%d",&choice);


        switch(choice){
            case 1:
                addCustomer();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayCustomers();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

