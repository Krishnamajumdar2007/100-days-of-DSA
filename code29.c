# include <stdio.h> 

int main() {
    int arr[100][100]; 
    int m, n; 
    scanf("%d %d", &m, &n );

    for ( int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j<n; j++) {
            scanf("%d", &arr[i][j]); 
        }
        printf("\n"); 
    }
    for ( int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j<n; j++) {
            printf("%d", arr[i][j]); 
        }
        printf("\n"); 
    }
    int sum = 0 ; 
    for ( int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j<n; j++) {
             if ( i == j ) {
                sum += arr[i][j]; 
             }
        }
        
    }
    printf("sum = %d", sum ) ; 
    
}