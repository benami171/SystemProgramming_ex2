#ifndef MY_MAT_H
#define MY_MAT_H
#define SIZE 10
#define INF 99999

void readNumbers(int matrix[SIZE][SIZE]);
int hasRoute(int graph[SIZE][SIZE], int start, int end);
int shortestPath(int graph[SIZE][SIZE], int start, int end);

#endif