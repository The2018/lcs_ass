#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c){
	int max = a;
	if (max < b){
		max = b;
	}if (max < c){
		max = c;
	}
	return max;
}

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

void print_2d_array(int **arr, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			printf("%d ",arr[i][j]);
		} printf("\n");
	} printf("\n");
}

int ** malloc_2d(int n, int m){
	int ** graph = malloc(n*sizeof(int *));
	for (int i = 0; i < n; i++){
		graph[i] = malloc(m*sizeof(int));
		} 
	return graph;
}

int lcs2(int *a, int n,  int *b, int m) {
	int ** graph = malloc_2d(n+1, m+1);
	for (int i = 0; i < n+1; i++){
		graph[i][0] = 0;
	}
	for (int j = 0; j < m+1; j++){
		graph[0][j] = 0;
	}

	for (int i = 1; i < n+1; i++){
		for (int j = 1; j < m+1; j++){
			int com = 0;
			if (a[i-1] == b[j-1]){
				com = 1;
			}
			graph[i][j] = max(graph[i-1][j], graph[i][j-1], graph[i-1][j-1]+com);
		}
	}

	//print_2d_array(graph, n+1, m+1);
	return graph[n][m];
}

int main() {
	int n, m;  
  
	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);
	
	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	
	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);
	
	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);
	
	return 0;
}