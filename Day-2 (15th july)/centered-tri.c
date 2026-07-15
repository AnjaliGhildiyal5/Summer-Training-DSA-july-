#include <stdio.h>

// it is a daimond actually

int main() {
    for (int k = 1; k<=5; k++) {
        for (int i = 1; i<=5-k; i++) {
            printf(" ");
        }
        for (int j = 1; j<=2*k-1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int k = 5; k>=0; k--) {
        for (int i = 1; i<=6-k; i++) {
            printf(" ");
        }
        for (int j = 2*k-2; j>=2; j--) {
            printf("*");
        }
        printf("\n");
    }
}
