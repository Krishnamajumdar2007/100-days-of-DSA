#include <stdio.h>
int main() {
    int n ; 
    scanf("%d", &n) ;
    int arr[n];

    for( int i = 0; i< n; i++) {
        scanf("%d", &arr[i]);

    }
    int target;
    scanf("%d", &target);

    for ( int i = 0 ; i<n; i++){
        for(int j = i + 1; j<n; j++){
            int a = arr[i] + arr[j]; 
            if ( a == target){
                printf("[%d , %d]",i,j);
                return 0;
            }
        }
    }
    return 0;
}