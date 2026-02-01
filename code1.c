#include <stdio.h>

int main() {
    int n ;
    scanf("%d", &n);
    int arr[n];

    for ( int i = 0 ; i< n ; i ++ ) {
        scanf("%d", &arr[i]);
    }

    int poss;
    int elem;

    scanf("%d  ",&poss);
    scanf("%d",&elem);

    n++;

    for( int i = n ; i>=poss; i--) {
        arr[i] = arr[i-1];
    }
    arr[poss-1] = elem;
    
    for ( int i = 0 ; i<n; i++) {
        printf("%d\t", arr[i]);
    }
    return 0; 

}