#include <stdio.h>
#include <stdlib.h>

// Hàm để đọc dữ liệu đầu vào
int main() {
    int N, k = 0;
    scanf("%d", &N);  // Đọc số nguyên N
    int B[N], C[N];   // Khai báo mảng B và C

    // Đọc dữ liệu vào mảng B
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        C[i] = B[i];  // Sao chép giá trị từ B sang C
    }

    if (N == 1) {
        printf("%d\n", k);
        for (int i = 0; i < N; i++) {
            printf("%d ", C[i]);
        }
        printf("\n");
        return 0;
    }

    // Sử dụng vòng lặp while để duyệt qua mảng A
    while (1) {

        for (int i = 0; i < N - 1; i++) {
            if (C[i + 1] <= C[i]) {
                k = k + (C[i] - C[i + 1]) / 2 + 1;
                break;
            }

            if (i == N - 2) {
                printf("%d\n", k);
                for (int i = 0; i < N; i++) {
                    printf("%d ", C[i]);
                }
                printf("\n");
                return 0;
            }
        }



        C[0] = B[0] - k;
        for (int i = 1; i < N; i++) {
            if ((B[i] - k <= C[i - 1] + 1) && (C[i - 1] + 1 <= B[i] + k)) {
                C[i] = C[i - 1] + 1;
            } else if (B[i] - k >= C[i - 1] + 1) {
                C[i] = B[i] - k;
            } else if (B[i] + k < C[i - 1] + 1) {
                C[i] = B[i] + k;
            }
        }
    }

    return 0;
}
