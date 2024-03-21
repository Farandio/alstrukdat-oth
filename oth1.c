#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minSwaps(int arr[], int n) {
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i) {
            swaps++;

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            printf("Pengurutan ke-%d:\n", swaps);
            printf("Setelah pertukaran: ");
            for (int k = 0; k < n; k++) {
                if (arr[k] >= 11 && arr[k] <= 13) {
                    char card;
                    switch (arr[k]) {
                        case 11:
                            card = 'J';
                            break;
                        case 12:
                            card = 'Q';
                            break;
                        case 13:
                            card = 'K';
                            break;
                    }
                    printf("%c ", card);
                } else {
                    printf("%d ", arr[k]);
                }
            }
            printf("\n\n");
        }
    }

    return swaps;
}

int main() {
    int n;
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Jumlah kartu tidak valid. Program berhenti.\n");
        return 1;
    }

    int arr[n];
    char str[3 * n]; 

    printf("Masukkan urutan kartu (pisahkan dengan spasi): ");
    getchar(); 
    fgets(str, sizeof(str), stdin); 

    char *token = strtok(str, " ");
    for (int i = 0; i < n && token != NULL; i++) {
        if (token[0] >= '2' && token[0] <= '9')
            arr[i] = atoi(token);
        else
            arr[i] = (token[0] == 'J') ? 11 : (token[0] == 'Q') ? 12 : (token[0] == 'K') ? 13 : 0;
        
        token = strtok(NULL, " ");
    }

    if (token != NULL) {
        printf("Jumlah kartu tidak sesuai. Program berhenti.\n");
        return 1;
    }

    int swaps = minSwaps(arr, n);
    printf("Jumlah minimum swaps yang diperlukan untuk mengurutkan kartu: %d\n", swaps);

    return 0;
}