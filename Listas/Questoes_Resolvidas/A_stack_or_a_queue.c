#include<stdio.h>

int main() {
    int t, contador, n, a[100], b[100];
    int isstack, isqueue;
    scanf("%d", &t);
    contador = 0;

    while(contador < t) {
        isstack = 1;
        isqueue = 1;

        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        for(int i=0; i<n; i++) {
            scanf("%d", &b[i]);
        }
        
        for(int i=0; i<n; i++) {
            if(a[i] != b[i]) isqueue = 0;
            if(a[i] != b[n-1-i]) isstack = 0;
        }
        
        if(isstack == 1 && isqueue == 1) printf("both\n");
        else if(isstack == 1) printf("stack\n");
        else if(isqueue == 1) printf("queue\n");
        else printf("neither\n");

        contador++;
    }
}
