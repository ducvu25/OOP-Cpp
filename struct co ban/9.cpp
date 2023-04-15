#include <iostream>
using namespace std;

// Khai báo kiểu dữ liệu phức
struct SoPhuc {
    float thuc; // Phần thực
    float ao; // Phần ảo
};
SoPhuc Nhap(){
    SoPhuc x;
    cout << "Nhap phan thuc: "; cin >> x.thuc;
    cout << "Nhap phan ao: "; cin >> x.ao;
    return x;
}
void Xuat(SoPhuc x){
    cout << x.thuc << " + " << x.ao << "i\n";
}
// Hàm tính tổng hai số phức
SoPhuc add(SoPhuc a, SoPhuc b) {
    SoPhuc c;
    c.thuc = a.thuc + b.thuc;
    c.ao = a.ao + b.ao;
    return c;
}

// Hàm tính tích hai số phức
SoPhuc multiply(SoPhuc a, SoPhuc b) {
    SoPhuc c;
    c.thuc = a.thuc * b.thuc - a.ao * b.ao;
    c.ao = a.thuc * b.ao + a.ao * b.thuc;
    return c;
}

void Nhap(SoPhuc a[], int n){
    for(int i=0; i<n; i++)
        a[i] = Nhap();
}
SoPhuc Sum(SoPhuc a[], int n){
    SoPhuc sum = a[0];
    for(int i=1; i<n; i++)
        sum = add(sum, a[i]);
    return sum;
}
SoPhuc Multiply(SoPhuc a[], int n){
    SoPhuc sum = a[0];
    for(int i=1; i<n; i++)
        sum = multiply(sum, a[i]);
    return sum;
}
int main() {
   int n;
   cout << "Nhap so luong: "; cin >> n;
   SoPhuc a[100];
   Nhap(a, n);
   cout << "Tong: "; Xuat(Sum(a, n));
    cout << "Tich: "; Xuat(Multiply(a, n));
    return 0;
}
