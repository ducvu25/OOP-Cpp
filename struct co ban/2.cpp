#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int UCLN(int a, int b){
    if(b == 0) return a;
    return UCLN(b, a%b);
}
struct PhanSo {
    int tu, mau;
};
void RutGon(PhanSo &x){
    int ucln = UCLN(x.tu, x.mau);
    x.tu /= ucln;
    x.mau /= ucln;
}
PhanSo Nhap(){
    PhanSo x;
    char c;
    cout << "Nhap phan so(a / b): "; cin >> x.tu >> c >> x.mau;
    RutGon(x);
    return x;
}
void NghichDao(PhanSo x){
    cout << "Nghich dao cua: " << x.tu << "/" << x.mau << " la: " << x.mau << "/" << x.tu << endl;
}
void Xuat(PhanSo x){
    if(x.mau == 0)
        cout << "NULL" << endl;
    else
        cout << x.tu << " / " << x.mau << endl;
}
PhanSo Tong(PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu*b.mau + a.mau*b.tu;
    c.mau = a.mau*b.mau;
    RutGon(c);
    return c;
}
PhanSo Tich(PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu*b.tu;
    c.mau = a.mau*b.mau;
    RutGon(c);
    return c;
}
void NhapDS(PhanSo a[], int n){
    for(int i=0; i<n; i++)
        a[i] = Nhap();
}
void Xuat(PhanSo a[], int n){
    cout << "\n\t\tDANH SACH\n\n";
    for(int i=0; i<n; i++)
        Xuat(a[i]);
}
PhanSo TongDS(PhanSo a[], int n){
    PhanSo x = a[0];
    for(int i=1; i<n; i++)
        x = Tong(x, a[i]);
    return x;
}
PhanSo TichDS(PhanSo a[], int n){
    PhanSo x = a[0];
    for(int i=1; i<n; i++)
        x = Tich(x, a[i]);
    return x;
}
void DSNghichDao(PhanSo a[], int n){
    cout << "\n\t\tDANH SACH NGHICH DAO\n\n";
    for(int i=0; i<n; i++)
        NghichDao(a[i]);
}

int main(){
    int n;
    cout << "Nhap so luong: "; cin >> n;
    PhanSo a[50];
    NhapDS(a, n);
    Xuat(a, n);
    cout << "Tong: ";   Xuat(TongDS(a, n));
    cout << "Tich: ";   Xuat(TichDS(a, n));
    DSNghichDao(a, n);
    return 0;
}