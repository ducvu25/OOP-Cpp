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
void Nhap(PhanSo a[], int n){
    for(int i=0; i<n; i++)
        a[i] = Nhap();
}
void Xuat(PhanSo a[], int n){
    for(int i=0; i<n; i++)
        Xuat(a[i]);
}
PhanSo Sum(PhanSo a[], int n){
    PhanSo sum = a[0];
    for(int i=1; i<n; i++)
        sum = Tong(sum, a[i]);
    return sum;
}
PhanSo Max(PhanSo a[], int n){
    PhanSo sum = a[0];
    for(int i=1; i<n; i++)
        if(SoSanh(sum, a[i]) < 0)
            sum = a[i];
    return sum;
}
PhanSo Min(PhanSo a[], int n){
    PhanSo sum = a[0];
    for(int i=1; i<n; i++)
        if(SoSanh(sum, a[i]) > 0)
            sum = a[i];
    return sum;
}
void Sort(PhanSo a[], int n){
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        if(SoSanh(a[i], a[j]) > 0){
            PhanSo t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
}
int main(){
    int n;
   cout << "Nhap so luong: "; cin >> n;
   PhanSo a[100];
   Nhap(a, n);
   cout << "Tong: "; Xuat(Sum(a, n));
    cout << "Phan so max: "; Xuat(Max(a, n));
    cout << "Phan so min: "; Xuat(Min(a, n));
    Sort(a, n);
    Xuat(a, n);
    return 0;
}