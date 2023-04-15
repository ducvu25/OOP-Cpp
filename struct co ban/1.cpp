#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Date{
    int d, m, y;
};
struct HocSinh {
    char ma[6];
    char ten[31];
    Date ngaySinh;
    char diaChi[51];
    char phai[4];
    float diem;
};
HocSinh Nhap(){
    HocSinh x;
    char c;
    cout << "\nNhap thong tin\n";
    cout << "Nhap ma: "; cin >> x.ma;
    cout << "Nhap ten: "; cin.ignore(); cin.getline(x.ten, 30);
    cout << "Nhap ngay sinh(dd/mm/yyyy): ";  cin >> x.ngaySinh.d >> c >> x.ngaySinh.m >> c >> x.ngaySinh.y;
    cout << "Nhap dia chi: "; cin.ignore(); cin.getline(x.diaChi, 50);
    cout << "Nhap diem: "; cin >> x.diem;
    return x;
}
void Xuat(HocSinh x){
    cout << left << setw(10) << x.ma << setw(35) << x.ten << setw(2) << x.ngaySinh.d << "/" << setw(2) << x.ngaySinh.m
    << "/" << setw(6) << x.ngaySinh.y << setw(35) << x.diaChi << setw(10) << x.phai << x.diem << endl; 
}

void NhapDS(HocSinh a[], int n){
    for(int i=0; i<n; i++)
        a[i] = Nhap();
}
void Xuat(HocSinh a[], int n){
    cout << "\n\t\tDANH SACH\n\n";
    for(int i=0; i<n; i++)
        Xuat(a[i]);
}
int Count(HocSinh a[], int n){
    int count = 0;
    for(int i=0; i<n; i++)
        if(a[i].diem >= 5)
            count++;
    return count;
}
int main(){
    int n;
    cout << "Nhap so luong: "; cin >> n;
    HocSinh a[50];
    NhapDS(a, n);
    Xuat(a, n);
    cout << "So hoc sinh du dieu kien: " << Count(a, n);
    return 0;
}