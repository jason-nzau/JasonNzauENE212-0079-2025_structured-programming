#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

double balance = 1000.00;

int   login(void);
void  checkBalance(void);
void  deposit(double amount);
int   withdraw(double amount);
void  showMenu(void);


int main(void)
{
    int choice;
    double amount;


    if (login() == 0)
    {
        printf("\nToo many failed attempts. Card blocked. Goodbye.\n");
        return 1;
    }

    printf("\nLogin successful! Welcome.\n");
    while (1)
    {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                checkBalance();
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (withdraw(amount) == 1)
                    printf("Withdrawal successful. New balance: %.2f\n", balance);
                break;
            case 4:
                printf("\nThank you for using the ATM. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1-4.\n");
        }
    }

    return 0;
}
int login(void)
{
    const int STORED_PIN = 1234;
    int enteredPin;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    while (attempts < MAX_ATTEMPTS)
    {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == STORED_PIN)
            return 1;
        attempts++;
        printf("Incorrect PIN. Attempts left: %d\n", MAX_ATTEMPTS - attempts);
    }

    return 0;
}
void showMenu(void)
{
    printf("\n========== ATM MENU ==========\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("==============================\n");
}
void checkBalance(void)
{
    printf("Your current balance is: %.2f\n", balance);
}
void deposit(double amount)
{
    if (amount <= 0)
    {
        printf("Error: Deposit amount must be positive.\n");
        return;
    }
    balance += amount;
    printf("Deposit successful. New balance: %.2f\n", balance);
}
int withdraw(double amount)
{
    if (amount <= 0)
    {
        printf("Error: Withdrawal amount must be positive.\n");
        return 0;
    }
    if (amount > balance)
    {
        printf("Error: Insufficient balance. Your balance is %.2f\n", balance);
        return 0;
    }
    balance -= amount;
    return 1;
}
