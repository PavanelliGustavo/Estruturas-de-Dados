#include<stdio.h>

int main() {

    int t, n, j, idx;
    char s[200000], r[27], letra;

    scanf("%d", &t);

    while(t) {
        scanf("%d", &n);
        scanf("%s", s);

        int  temp[27] = {0};
        for(int i=0; i<n; i++) {
            temp[s[i] - 97]++;
        }

        j = 0;
        for(int i=0; i<27; i++) {
            if(temp[i] != 0) {
                r[j] = i + 97;
                j++;
            }
        }

        for(int i=0; i<n; i++) {
            for(int a=0; a<j; a++) {
                if(s[i] == r[a]) {
                    idx = a;
                }
            }
            letra = r[j-1-idx];
            printf("%c", letra);
        }
        printf("\n");

        t--;
    }


    return 0;
}
