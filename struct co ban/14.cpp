#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct MayTinh{
    string loai;
    string noisx;
    float time;
};
MayTinh Nhap(){
    MayTinh x;
    cout << "\nNhap thong tin:\n";
    cout << "Nhap loai: "; cin >> x.loai;
    cout << "Nhap noi sx: "; cin.ignore(); getline(cin, x.noisx);
    cout << "Nhap thoi gian bao hanh: "; cin >> x.time;
    return x;
}
void Xuat(MayTinh x){
    cout << left << setw(10) << x.loai << setw(35) << x.noisx << x.time << endl;
}
void Nhap(MayTinh a[], int n){
    for(int i=0; i<n; i++)
        a[i] = Nhap();
}
void Yb(MayTinh a[], int n){
    cout << "\nDANH SACH MAY CO THOI HAN BAO HANH 1 NAM\n";
    for(int i=0; i<n; i++)
        if(a[i].time == 1)
            Xuat(a[i]);
}
void Yc(MayTinh a[], int n){
    cout << "\nDANH SACH MAY SX TAI MY\n";
    for(int i=0; i<n; i++)
        if(a[i].noisx == "My")
            Xuat(a[i]);
}
int main(){
    int n;
   cout << "Nhap so luong: "; cin >> n;
   MayTinh a[100];
   Nhap(a, n);
   Yb(a, n);
    Yc(a, n);
    return 0;
}