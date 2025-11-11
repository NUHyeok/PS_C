#include <stdio.h>
#include <stdlib.h>

int Queue[100000];
int visited[100001];
int parent[100001];
int front, rear;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* adj[100001];

void add_edge(int u, int v){
    Node* newnode = (Node *)malloc(sizeof(Node));
    newnode->data = v;
    newnode->next = adj[u];
    adj[u] = newnode;
}

void bfs(){
    Queue[rear++] = 1;
    visited[1] = 1;

    while(front < rear){
        int current = Queue[front++];

        Node *temp = adj[current];
        while(temp != NULL){
            int next = temp->data;

            if(visited[next] == 0){
                parent[next] = current;
                visited[next] = 1;
                Queue[rear++] = next;
            }

            temp = temp->next;
        }
    }
}

int main(void){
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        adj[i] = NULL;
    }

    for (int i = 1; i < N; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        add_edge(a,b);
        add_edge(b,a);
    }

    bfs();
    for(int i = 2; i <=N; i++){
        printf("%d\n", parent[i]);
    }

    return 0;

}