#include <stdio.h> 
int main() {
    int arr[100]; 
    int n ;
    scanf("%d", &n) ; 
    for ( int i = 0 ; i< n ; i++) {
        scanf("%d", &arr[i]); 
    }
    int m ;
    scanf("%d", &m);
    int k = 0 ; 
    while (  k < m ) {
        int temp = arr[n-1]  ; 
        for ( int i = n-1 ; i>= 0 ; i--) {
        arr[i ] = arr[i-1]; 
        if ( i == 0 ) {
            arr[0] = temp ;
        }
        }
        k++;
    }
    for ( int i = 0 ; i< n ; i++) {
        printf("%d ", arr[i]); 
    }   
}