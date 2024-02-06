#include "my_mat.h"
#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
#define INPUT_SIZE 100
#define INF 99999
#define MAX_NODES 10
#define False 0

void readNumbers(int matrix[SIZE][SIZE]) {
    int numbers[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    // Build the matrix row by row
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = numbers[k];
            k++;
        }
    }
}

int hasRouteUtil(int graph[SIZE][SIZE], int start, int end, int visited[MAX_NODES]) {
    if (start == end) {
        return 1; // Found a route
    }

    visited[start] = 1;

    for (int i = 0; i < SIZE; i++) {
        if (graph[start][i] != 0 && !visited[i]) {
            if (hasRouteUtil(graph, i, end, visited)) {
                return 1;
            }
        }
    }

    return 0;
}

int hasRoute(int graph[SIZE][SIZE], int start, int end) {
    if (start == end) {
        return False;
    }
    int visited[MAX_NODES] = {0};
    return hasRouteUtil(graph, start, end, visited);
}


int shortestPath(int mat[SIZE][SIZE], int i, int j) {
    int ans = hasRoute(mat, i, j);
    if (ans == False) {
        return -1;
    }

    int shortestMat[SIZE][SIZE];
    // Initialization to infinity
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            shortestMat[x][y] = INF;
        }
    }

    // Assigning direct paths
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (x == y) {
                shortestMat[x][y] = 0;
            } else if (mat[x][y] != 0) {
                shortestMat[x][y] = mat[x][y];
            } else {
                shortestMat[x][y] = INF;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < SIZE; k++) {
        for (int x = 0; x < SIZE; x++) {
            for (int y = 0; y < SIZE; y++) {
                if ((shortestMat[x][k] != INF) && (shortestMat[k][y] != INF) && (shortestMat[x][k] + shortestMat[k][y] < shortestMat[x][y])) {
                    shortestMat[x][y] = shortestMat[x][k] + shortestMat[k][y];
                }
            }
        }
    }

    // Return -1 if there's no path, otherwise return the shortest path
    return shortestMat[i][j] == INF ? -1 : shortestMat[i][j];
}
