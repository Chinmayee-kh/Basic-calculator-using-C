#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct {
    int a;  
    int b;  
} State;
int visited[5][4];
State queue[MAX];
int front = 0, rear = 0;
void addState(int a, int b) {
    if (!visited[a][b]) {
        visited[a][b] = 1;
        queue[rear].a = a;
        queue[rear].b = b;
        rear++;
    }
}
int main() {
    addState(0, 0);
    while (front < rear) {
        State current = queue[front++];
        int a = current.a;
        int b = current.b;
        printf("(%d, %d)\n", a, b);
        if (a == 2) {
            printf("\nGoal reached!\n");
            return 0;
        }
        addState(4, b);
        addState(a, 3);
        addState(0, b);
        addState(a, 0);
        int pour = (a < 3 - b) ? a : (3 - b);
        addState(a - pour, b + pour);
        pour = (b < 4 - a) ? b : (4 - a);
        addState(a + pour, b - pour);
    }
    printf("No solution found.\n");
    return 0;
}