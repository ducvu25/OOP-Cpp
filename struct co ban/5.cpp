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

// Hàm tính hiệu hai số phức
SoPhuc subtract(SoPhuc a, SoPhuc b) {
    SoPhuc c;
    c.thuc = a.thuc - b.thuc;
    c.ao = a.ao - b.ao;
    return c;
}

// Hàm tính tích hai số phức
SoPhuc multiply(SoPhuc a, SoPhuc b) {
    SoPhuc c;
    c.thuc = a.thuc * b.thuc - a.ao * b.ao;
    c.ao = a.thuc * b.ao + a.ao * b.thuc;
    return c;
}

int main() {
    // Khởi tạo hai số phức
    SoPhuc a, b;
    a = Nhap();
    b = Nhap();
    Xuat(a);
    Xuat(b);
    cout << "Tong hai so phuc la: "; Xuat(add(a, b));
    cout << "Hieu hai so phuc la: "; Xuat(subtract(a, b));
    cout << "Tich hai so phuc la: "; Xuat(multiply(a, b));

    return 0;
}
