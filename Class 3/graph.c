#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
typedef struct Graph {
	int n; // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}Graph;

// 그래프 초기화
void init(Graph* g)
{
	int row, col;
	g->n = 0;
	for (row = 0; row < MAX_VERTICES; row++)
		for (col = 0; col < MAX_VERTICES; col++)
			g->adj_mat[row][col] = 0;
}

// 정점 삽입 연산
void insert_vertex(Graph* g, int vertex)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "최대 정점 개수 초과\n");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(Graph* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "정점 번호 오류\n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
// 인접 행렬 출력 함수
void print_graph(Graph* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("[%d] ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_graph(g);

	free(g);
}