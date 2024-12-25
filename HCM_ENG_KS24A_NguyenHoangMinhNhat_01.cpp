#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void nhapmang(int arr[], int *n) {
    printf("\nNhap so phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap gia tri cho phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void inmang(int arr[], int n) {
    printf("\nCac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d", i, arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
}

void timminmax(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("\nGia tri nho nhat: %d", min);
    printf("\nGia tri lon nhat: %d\n", max);
}

void tinhtong(int arr[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    printf("\nTong cac phan tu trong mang: %d\n", tong);
}

void themphantu(int arr[], int *n) {
    if (*n >= MAX) {
        printf("\nMang da day!\n");
        return;
    }
    int giatrimoi;
    printf("\nNhap gia tri phan tu moi: ");
    scanf("%d", &giatrimoi);
    arr[*n] = giatrimoi;
    (*n)++;
}

void xoaphantu(int arr[], int *n) {
    int vitri;
    printf("\nNhap vi tri can xoa (0 den %d): ", *n - 1);
    scanf("%d", &vitri);
    if (vitri < 0 || vitri >= *n) {
        printf("\nVi tri khong hop le!\n");
        return;
    }
    for (int i = vitri; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void sapxepgiamdan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nMang sau khi sap xep giam dan: ");
    inmang(arr, n);
}

void find(int arr[], int n) {
    int x;
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("\nPhan tu %d ton tai trong mang o vi tri %d.\n", x, i);
            return;
        }
    }
    printf("\nPhan tu %d khong ton tai trong mang.\n", x);
}

bool songuyento(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void insonguyento(int arr[], int n) {
    bool cosonguyento = false;
    printf("\nCac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (songuyento(arr[i])) {
            printf("%d ", arr[i]);
            cosonguyento = true;
        }
    }
    if (!cosonguyento) {
        printf("Khong co so nguyen to nao trong mang.\n");
    } else {
        printf("\n");
    }
}

void sapxeptangdan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minidx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minidx]) {
                minidx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }
    printf("\nMang sau khi sap xep tang dan: ");
    inmang(arr, n);
}

int main() {
    int arr[MAX], n = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In ra tong cua tat ca cac phan tu\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Bubble Sort)\n");
        printf("8. Tim kiem mot phan tu trong mang\n");
        printf("9. In ra toan bo so nguyen to trong mang\n");
        printf("10. Sap xep mang theo thu tu tang dan (Selection Sort)\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapmang(arr, &n);
                break;
            case 2:
                inmang(arr, n);
                break;
            case 3:
                timminmax(arr, n);
                break;
            case 4:
                tinhtong(arr, n);
                break;
            case 5:
                themphantu(arr, &n);
                break;
            case 6:
                xoaphantu(arr, &n);
                break;
            case 7:
                sapxepgiamdan(arr, n);
                break;
            case 8:
                find(arr, n);
                break;
            case 9:
                insonguyento(arr, n);
                break;
            case 10:
                sapxeptangdan(arr, n);
                break;
            case 0:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}