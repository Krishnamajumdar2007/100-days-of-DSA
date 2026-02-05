#include <stdio.h>
int main(){
    int a[100], b[100], n1, n2;

    scanf("%d",&n1);
    for(int i=0; i<n1; i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    for(int i=0; i<n2; i++){
        scanf("%d",&b[i]);
    }

    for(int i=0; i<n2; i++){
        a[n1]=b[i];
        n1++;
    }
    int temp;
     for (int i = 0; i < n1 - 1; i++) {
        for (int j = 0; j < n1 - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i=0; i<n1; i++){
        printf("%d ",a[i]);
    }
}