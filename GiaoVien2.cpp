#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class GV{
    private:
        char ten[30];
        int tuoi;
        char bangCap[15];
        char chuyenNganh[20];
        float luong;
    public:
        friend istream& operator>>(istream& is,  GV&x){
            cout << "Nhap thong tin:\n";
            cin.ignore();
            cin.getline(x.ten, 30);
            cin >> x.tuoi;
            fflush(stdin);
            cin.getline(x.bangCap, 15);
            cin.getline(x.chuyenNganh, 20);
            cin >> x.luong;
            return cin;
        }
        friend ostream& operator<<(ostream& os, GV x){
            // cout << "Thong tin giao vien:\n";
            // cout << "Ho ten: " << x.ten << endl;
            // cout << "Tuoi: " << x.tuoi << endl;
            // cout << "Bang cap: " << x.bangCap << endl;
            // cout << "Chuyen nganh: " << x.chuyenNganh << endl;
            // cout << "Bac luong: " << x.luong << endl;
            cout << left << setw(30) << x.ten << setw(15) << x.tuoi << setw(20) << x.bangCap << setw(25) << x.chuyenNganh << x.luong;
            return cout;
        }
        float Luong(){
            return this->luong*610;
        }
        char* GetTen(){
            return this->ten;
        }
};      
int main(){
    int n;
    cout << "Nhap n: "; cin >> n;
    if(n <= 0) return 0;
    GV *a = new GV[n+1];
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << "\n\tDANH SACH GIAO VIEN CO LUONG < 2000:\n";
    for(int i=0; i<n; i++)
        if(a[i].Luong() < 2000)
            cout << a[i] << endl;
    char s[30];
    cin.ignore();
    cout << "\nNhap ten: "; cin.getline(s, 30);
    for(int i=0; i<n; i++)
        if(strcmp(a[i].GetTen(), s) == 0){
            cout << "Thong tin giao vien: " << s << endl;
            cout << a[i];
            return 0;
        }
    cout << "Giao vien co ten khong co trong danh sach! Vui long nhap thong tin.";
    cin >> a[n];
    return 0;
}