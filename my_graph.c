#include "my_mat.h"
#include <stdio.h>

int main() {
    int matrix[SIZE][SIZE];
    char choice;

    while (1) {
        int result = scanf(" %c", &choice);
        if (result == EOF || choice == 'D') {
            break; // Exit the loop on 'D' or EOF
        }

        switch (choice) {
            case 'A':
                readNumbers(matrix);
                break;

            case 'B': {
                int i, j;
                scanf("%d %d", &i, &j);
                int routeExists = hasRoute(matrix, i, j);
                printf("%s\n", routeExists ? "True" : "False");
                break;
            }

            case 'C': {
                int i, j;
                scanf("%d %d", &i, &j);
                int shortestRoute = shortestPath(matrix, i, j);
                printf("%d\n", shortestRoute);
                break;
            }
        }
    }

    return 0;
}