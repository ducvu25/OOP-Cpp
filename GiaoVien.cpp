#include<iostream>
#include<string.h>
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
            cin.getline(x.ten, 30);
            cin >> x.tuoi;
            fflush(stdin);
            cin.getline(x.bangCap, 15);
            cin.getline(x.chuyenNganh, 20);
            cin >> x.luong;
            return cin;
        }
        friend ostream& operator<<(ostream& os, GV x){
            cout << "Thong tin giao vien:\n";
            cout << "Ho ten: " << x.ten << endl;
            cout << "Tuoi: " << x.tuoi << endl;
            cout << "Bang cap: " << x.bangCap << endl;
            cout << "Chuyen nganh: " << x.chuyenNganh << endl;
            cout << "Bac luong: " << x.luong << endl;
            return cout;
        }
        float Luong(){
            return this->luong*1490;
        }
};      
int main(){
    GV a;
    cin >> a;
    cout << a;
    cout << "Tien luong: " << a.Luong();
    return 0;
}