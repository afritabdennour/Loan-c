#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
// Get Informations from User:
// Get Other info:
    printf("Loan Details:\n");
    float loan;
    printf("Loan Amount: ");
    scanf("%f",&loan);
    while (loan > 99999997952) {
        printf("ERROR: Many Numbers");
        return 1;
    }
    float interest;
    printf("Interest Rate: ");
    scanf("%f",&interest);
    while (interest < 0) {
        printf("ERROR: error in the Interest");
        return 1;
    }
    int months;
    printf("Loan Term (Months): ");
    scanf("%i",&months);
    while (months > 1200) {
        printf("ERROR: error in the months");
        return 1;
    }
    float interestpayments = loan * interest / 100;
    float allloan = loan + interestpayments;
// Get Time:
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int month = local->tm_mon + 4;
    int year = local->tm_year + 1900;
    int monthe = months;
    int later = month + monthe;
    while(later > 12) {
        later -= 12;
        year += 1;
    }
// Result:
    printf("\n");
    printf("Your Loan Estimate:\n");
    printf("Total Payment:           %f $\n", loan);
    printf("Total Interest Payments: %f $\n", interestpayments);
    printf("Total Loan Payments:     %f $\n", allloan);
    printf("Monthly Payment:         %f $\n", allloan / months);
    printf("Payoff Date:             %d / %d\n", later, year);
    return 0;
}