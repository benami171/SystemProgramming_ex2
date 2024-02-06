#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 5
#define MAX_WEIGHT 20

int knapSack(int weights[], int values[], int selected_bool[]) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];
    int i, w;

    for (i = 0; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]]) > dp[i - 1][w] ? (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int maxProfit = dp[MAX_ITEMS][MAX_WEIGHT];
    int currentWeight = MAX_WEIGHT;

    for (i = MAX_ITEMS; i > 0 && maxProfit > 0; i--) {
        if (maxProfit == dp[i - 1][currentWeight])
            continue;
        else {
            selected_bool[i - 1] = 1;
            maxProfit = maxProfit - values[i - 1];
            currentWeight = currentWeight - weights[i - 1];
        }
    }

    return dp[MAX_ITEMS][MAX_WEIGHT];
}

int main() {
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];
    int selected_bool[MAX_ITEMS] = {0};

    printf("Enter the values for items A, B, C, D, E: ");
    for (int i = 0; i < MAX_ITEMS; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the weights for items A, B, C, D, E: ");
    for (int i = 0; i < MAX_ITEMS; i++) {
        scanf("%d", &weights[i]);
    }
    int maxProfit = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", maxProfit);
    printf("Items that give the maximum profit: [");
    for (int i = MAX_ITEMS - 1; i >= 0; i--) {
        if (selected_bool[i] == 1) {
            printf("%c, ", 'A' + i);
        }
    }
    printf("\b\b]\n");

    return 0;
}
