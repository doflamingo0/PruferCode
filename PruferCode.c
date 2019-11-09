#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int E, V, x, y;
	// Nhap so canh cua cay
	scanf("%d", &E);
	
	// tinh chat cua cay: |V| = |E| + 1
	V = E+1;
	
	int **A;
	int i, j;
	
	A = (int **) malloc(V*sizeof(int *));
	for(i = 0; i < V; i++)
		A[i] = (int *) malloc(V*sizeof(int));
		
	// Khoi tao tat ca cac phan tu cua mang A = 0
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
			A[i][j] = 0;
	
	// Nhap cac canh cua cay
	// Neu  canh (x,y) thi A[x][y] = A[y][x] = 1
	// A[x][x] = deg(x)
	for(i = 0; i < E; i++){
		scanf("%d",&x);
		scanf("%d",&y);
		A[x][y] = 1;
		A[y][x] = 1;
		A[x][x] += 1;
		A[y][y] += 1;
	}
	printf("\n");
	
	// PruferCode
	// lap lai 2*E lan vi tong so bac cua cac dinh la 2E
	int k;
	for(k = 1; k <= 2*E; k++){
		i = 1;
		while(i < V){
			//tim dinh co deg = 1
			if(A[i][i] != 1){
				i++;
				continue;
			}
			else{
				// tim dinh ke voi dinh i tren
				for(j = 0; j < V; j++){
					if(j == i) continue;
					if(A[j][i] == 1 && A[i][j] == 1){
						A[i][i] -= 1;
						A[j][j] -= 1;
						A[j][i] = 0;
						A[i][j] = 0;
						
						// Kiem tra neu deg(0) = 0 thi khong in
						if(A[0][0] != 0) {
							printf("%d ", j); // tai sao lai in j, ma khong phai in i?
								// vi deg(i) = 1 nen prufer code khi chua xoa dong 1 la:
								// dong 1:   i 	
								// dong 2:   j
						}
					break; // khi da tim duoc 1 canh theo prufer code
						  // thi thoat ra khoi tat ca vong lap de tim dinh co deg = 1 khac
					}
				} 
			} 
			break; 
		} 
	}
	
	for(i = 0; i < V; i++)
		free(A[i]);
	free(A);
	
	getch();
 	return 0;
}

