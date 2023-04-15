#include<stdio.h>
#include<string.h>

typedef struct Sach{
    char ten[31];
    char tg[31];
    char nxb[21];
    int namXB;
    float gia;
}Sach;

int Menu(){
    int chuc_nang;
    printf("\n\t\tMENU\n");
    printf("\t1. Nhap thong tin cua n cuon sach\n");
    printf("\t2. In ra man hinh thong tin vua nhap\n");
    printf("\t3. Sap xep thong tin giam dan theo nam xuat ban va hien thi\n");
    printf("\t4. Tim kiem theo ten sach\n");
    printf("\t5. Tim kiem theo ten tac gia\n");
    printf("\t6. Thoat\n");
    printf("\tChuc nang: ");
    scanf("%d", &chuc_nang);
    return chuc_nang;
}
void TaoFile(char* s){
    FILE *fo;
    fo = fopen(s, "w+");
    int n;
    Sach a[100];

    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    fprintf(fo, "%d\n", n);
    int i;
    for(i=0; i<n; i++){
        printf("\nNhap thong tin sach:\n");
        printf("Nhap ten: "); scanf("%s", a[i].ten);
        printf("Nhap tac gia: "); scanf("%s", a[i].tg);
        printf("Nhap nha xuat ban: "); scanf("%s", a[i].nxb);
        printf("Nhap nam xuat ban: "); scanf("%d", &a[i].namXB);
        printf("Nhap gia: "); scanf("%f", &a[i].gia);
        fprintf(fo, "%s\n%s\n%s\n%d\n%0.2f\n\n", a[i].ten, a[i].tg, a[i].nxb, a[i].namXB, a[i].gia);
    }
    fclose(fo);
}
void NhapFile(Sach a[], int *n, char* s){
    FILE *fi;
    fi = fopen(s, "r+");
    fscanf(fi, "%d", n);
    int i;
    for(i=0; i<*n; i++)
        fscanf(fi, "%s%s%s%d%f\n", a[i].ten, a[i].tg, a[i].nxb, &a[i].namXB, &a[i].gia);
    fclose(fi);
}
void XuatFile(Sach a[], int n, char* s){
    FILE *fo;
    fo = fopen(s, "w+");

    fprintf(fo, "\nTong sach hien co: %d\n", n);
    fprintf(fo, "\n\t\tDANH SACH\n");
    fprintf(fo, "|%-30s|%-30s|%-10s|%-10s|\n", "Ten sach", "Tac gia", "Nam XB", "Gia ban");
    int i;
    for(i=0; i<n; i++)
        fprintf(fo, "|%-30s|%-30s|%-10d|%-10.2f|\n", a[i].ten, a[i].tg, a[i].namXB, a[i].gia);

    fclose(fo);
}
void Xuat(){
    int n;
    Sach a[100];
    NhapFile(a, &n, "FU.txt");

    printf("\nTong sach hien co: %d\n", n);
    printf("\n\t\tDANH SACH\n");
    printf("|%-30s|%-30s|%-10s|%-10s|\n", "Ten sach", "Tac gia", "Nam XB", "Gia ban");
    int i;
    for(i=0; i<n; i++)
        printf("|%-30s|%-30s|%-10d|%-10.2f|\n", a[i].ten, a[i].tg, a[i].namXB, a[i].gia);
}
void Sort(){
    int n, i, j;
    Sach a[100];
    NhapFile(a, &n, "FU.txt");

    for(i=0; i<n-1; i++)
        for(j=0; j<n; j++)
            if(a[i].namXB > a[j].namXB 
            || (a[i].namXB == a[j].namXB && a[i].gia < a[j].gia)){
                Sach t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    Xuat();
    XuatFile(a, n, "FU2022.txt");
}
void SearchName(){
    int n, i, j;
    Sach a[100];
    NhapFile(a, &n, "FU.txt");

    char s[31];
    printf("Nhap ten cuon sach: ");
    scanf("%s", s);
    int check = 0;
    for(i=0; i<n; i++)
        if(strcmp(a[i].ten,s) == 0){
            printf("|%-30s|%-30s|%-20s|\n", a[i].ten, a[i].tg, a[i].nxb);
            check = 1;
        }
    if(check == 0)
        printf("Khong tim thay cuon sach nao!\n");
}
void SearchAuthor(){
    int n, i, j;
    Sach a[100];
    NhapFile(a, &n, "FU.txt");

    char s[31];
    printf("Nhap ten tac gia: ");
    scanf("%s", s);
    int count = 0;
    for(i=0; i<n; i++)
        if(strcmp(a[i].tg, s) == 0){
            //printf("|%-30s|%-30s|%-10d|%-10.2f|\n", a[i].ten, a[i].tg, a[i].namXB, a[i].gia);
            count++;
        }
    if(count == 0)
        printf("Khong tim thay tac gia tren!\n");
    else
        for(i=0; i<n; i++)
            if(strcmp(a[i].tg,s) == 0){
                printf("|%-30s|%-30s|%-10d|\n", a[i].tg, a[i].ten, count);
            }
}