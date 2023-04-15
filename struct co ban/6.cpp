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
PhanSo Hieu(PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu*b.mau - a.mau*b.tu;
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
PhanSo Thuong(PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu*b.mau;
    c.mau = a.mau*b.tu;
    RutGon(c);
    return c;
}
void QuyDong(PhanSo &a, PhanSo &b){
    int ucln = UCLN(a.mau, b.mau);
    int mauChung = a.mau*b.mau/ucln;
    a.tu *= mauChung/a.mau;
    b.tu *= mauChung/b.mau;
    a.mau = mauChung;
    b.mau = mauChung;
}
int SoSanh(PhanSo a, PhanSo b){
    if(a.mau != 0 && b.mau != 0)
        if(a.tu*1.0/a.mau > b.tu*1.0/b.mau)
            return 1;
        else if(a.tu*1.0/a.mau < b.tu*1.0/b.mau)
            return -1;
        else
            return 0;
    return -2;
}
int main(){
    PhanSo a, b;
    a = Nhap();
    b = Nhap();
    cout << "Tong: "; Xuat(Tong(a, b));
    cout << "Hieu: "; Xuat(Hieu(a, b));
    cout << "Tich: "; Xuat(Tich(a, b));
    cout << "Thuong: "; Xuat(Thuong(a, b));
    cout << "Sau khi quy dong:\n"; QuyDong(a, b);
    cout << "a: "; Xuat(a);
    cout << "b: "; Xuat(b);
    if(SoSanh(a, b) == 1)
        cout << "a > b";
    else if(SoSanh(a, b) == 0)
        cout << "a = b";
    else if(SoSanh(a, b) == -1)
        cout << "a < b";
    else
        cout << "Loi";
    return 0;
}