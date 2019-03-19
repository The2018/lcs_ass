#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int max(int a, int b, int c, int d){
	int max = a;
	if (max < b){
		max = b;
	}if (max < c){
		max = c;
	}if (max < d){
		max = d;
	}
	return max;
}

void print_3d_array(int ***arr, int m, int n, int l){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < l; k++){
				printf("%d ",arr[i][j][k]);
			}
		} printf("\n");
	} printf("\n");
}

int *** malloc_3d(int n, int m, int l){
	int *** graph = malloc(n*sizeof(int **));
	for (int i = 0; i < n; i++){
		graph[i] = malloc(m*sizeof(int *));
		for (int j = 0; j < m; j++){
		graph[i][j] = malloc(l*sizeof(int));
		}
	} 
	return graph;
}

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	int *** graph = malloc_3d(n+1, m+1, l+1);
	for (int i = 0; i < n+1; i++){
		graph[i][0][0] = 0;
	}
	for (int j = 0; j < m+1; j++){
		graph[0][j][0] = 0;
	}
	for (int k = 0; k < l+1; k++){
		graph[0][0][k] = 0;
	}
	for (int i = 1; i < n+1; i++){
		for (int j = 1; j < m+1; j++){
			for (int k = 1; k < l+1; k++){
				int com = 0;
				if (a[i-1] == b[j-1] && b[j-1] == c[k-1]){
					com = 1;
				}
				graph[i][j][k] = max(graph[i-1][j][k], graph[i][j-1][k],graph[i][j][k-1], graph[i-1][j-1][k-1]+com);
			
			}
		}
	}

	return graph[n][m][l];
}

int main() {
	int n, m, l;  
  
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
	
	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array b:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);
	
	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);
	
	return 0;
}