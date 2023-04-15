#include<iostream>
#include<string.h>
using namespace std;

class KH{
    private:
        char ten[30];
        struct NS
        {
            int d, m, y;
        };
        NS date;
        char cmnd[10];
        char hoKhau[50];
    public:
        KH(){
            strcpy(this->ten, "");
            this->date.d = this->date.m = this->date.y = 0;
            strcpy(this->cmnd, "");
            strcpy(this->hoKhau, "");
        }
        KH(char* tens, int d, int m, int y, char* cmnds, char* hoKhaus){
            strcpy(this->ten, tens);
            this->date.d = d;
            this->date.m = m;
            this->date.y = y;
            strcpy(this->cmnd, cmnds);
            strcpy(this->hoKhau, hoKhaus);
        }
        friend ostream& operator<<(ostream& os, KH x){
            cout << "Thong tin khach hang:\n";
            cout << "Ho ten: " << x.ten << endl;
            cout << "Ngay sinh: " << x.date.d << "/" << x.date.m << "/" << x.date.y  << endl;
            cout << "CMND: " << x.cmnd << endl;
            cout << "Ho khau: " << x.hoKhau << endl;
            return cout;
        } 
        ~KH(){
        }
};      
int main(){
    char ten[30];
    int d, m, y;
    char cmnd[10];
    char hoKhau[50];
    char c;
    cout << "Nhap thong tin:\n";
    cout << "Nhap ten: ";   cin.getline(ten, 30);
    cout << "Nhap ngay sinh(dd/mm/yyyy): "; cin >> d >> c >> m >> c >> y;
    cout << "Nhap cmnd: "; cin >> cmnd;
    cout << "Nhap ho khau: "; fflush(stdin); cin.getline(hoKhau, 50);
    KH a(ten, d, m, y, cmnd, hoKhau);
    cout << a;
    return 0;
}