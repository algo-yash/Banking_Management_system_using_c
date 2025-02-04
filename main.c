#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void viewAccounts() {
    printf("Account List:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void deposit(int accountNumber, float amount) {
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    accounts[accountNumber - 1].balance += amount;
    printf("Deposited %.2f to account number %d. New balance: %.2f\n", 
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw(int accountNumber, float amount) {
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }
    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrew %.2f from account number %d. New balance: %.2f\n", 
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void menu() {
    int choice;
    do {
        printf("\nBanking Management System\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3: {
                int accNum;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accNum, amount);
                break;
            }
            case 4: {
                int accNum;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accNum, amount);
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
