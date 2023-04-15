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
void Xuat(PhanSo x){
    if(x.mau == 0)
        cout << "NULL" << endl;
    else
        cout << x.tu << " / " << x.mau << endl;
}
void RutGon(PhanSo &x){
    int ucln = UCLN(x.tu, x.mau);
    x.tu /= ucln;
    x.mau /= ucln;
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
struct HonSo{
    int nguyen, tu, mau;
};
HonSo Nhap(){
    HonSo x;
    cout << "Nhap phan nguyen: "; cin >> x.nguyen;
    cout << "Nhap phan phan so: "; cin >> x.tu >> x.mau;
    return x;
}
void Xuat(HonSo x){
    cout << "Phan nguyen: " << x.nguyen << " Phan so: " << x.tu << " / " << x.mau << endl;
}
PhanSo ChuyenDoiPS(HonSo x){
    PhanSo a;
    a.tu = x.nguyen*x.mau + x.tu;
    a.mau = x.mau;
    return a;
}
HonSo ChuyenDoiHS(PhanSo x){
    HonSo a;
    a.nguyen = x.tu/x.mau;
    a.tu = x.tu % x.mau;
    a.mau = x.mau;
    return a;
}
HonSo TongHS(HonSo a, HonSo b){
    return ChuyenDoiHS(Tong(ChuyenDoiPS(a), ChuyenDoiPS(b)));
}
HonSo HieuHS(HonSo a, HonSo b){
    return ChuyenDoiHS(Hieu(ChuyenDoiPS(a), ChuyenDoiPS(b)));
}
HonSo TichHS(HonSo a, HonSo b){
    return ChuyenDoiHS(Tich(ChuyenDoiPS(a), ChuyenDoiPS(b)));
}
HonSo ThuongHS(HonSo a, HonSo b){
    return ChuyenDoiHS(Thuong(ChuyenDoiPS(a), ChuyenDoiPS(b)));
}
int main(){
    HonSo a, b;
    a = Nhap();
    b = Nhap();
    cout << "a: "; Xuat(a);
    cout << "b: "; Xuat(b);

    cout << "Tong: "; Xuat(TongHS(a, b));
    cout << "Hieu: "; Xuat(HieuHS(a, b));
    cout << "Tich: "; Xuat(TichHS(a, b));
    cout << "Thuong: "; Xuat(ThuongHS(a, b));
    return 0;
}