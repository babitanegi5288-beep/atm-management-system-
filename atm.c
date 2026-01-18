#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    int pin, choice;
    float balance, amount;

    /* ===== ACCOUNT CREATION ===== */
    printf("===== ATM ACCOUNT CREATION =====\n");

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Create a 4-digit PIN: ");
    scanf("%d", &pin);

    printf("Enter initial balance: ");
    scanf("%f", &balance);

    printf("\n✅ Account created successfully!\n");
    printf("👋 Welcome %s\n", name);

    /* ===== ATM OPTIONS ===== */
    do {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("💰 %s, your balance is: %.2f\n", name, balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("✅ Deposit successful.\n");
                } else {
                    printf("❌ Invalid amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("✅ Please collect your cash.\n");
                } else {
                    printf("❌ Insufficient balance or invalid amount.\n");
                }
                break;

            case 4:
                printf("🙏 Thank you %s for using ATM.\n", name);
                break;

            default:
                printf("❌ Invalid option. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
