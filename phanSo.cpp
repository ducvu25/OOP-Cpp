#include <iostream>
#include <math.h>

using namespace std;

class PhanSo{
    private:
        int tu;
        int mau;
    public:
        friend istream& operator>>(istream &is, PhanSo &x){
            cout << "Nhap tu so: "; cin >> x.tu;
            cout << "Nhap mau so: "; cin >> x.mau;
            return is;
        }
        friend ostream& operator<<(ostream& os, PhanSo x){
            if(x.tu == 0)
                cout << 0;
            else{
                if(x.tu*x.mau < 0)
                    cout << "(" << x.tu << " / " << x.mau << ")";
                else
                    cout << x.tu << " / " << x.mau;
            }
            return os;
        }
        int UCLN(){
            int a = this->tu > 0 ? this->tu : -this->tu;
            int b = this->mau > 0 ? this->mau : -this->mau;
            while(a != 0){
                int t = a;
                a = b % a;
                b = t;
            }
            return b;
        }
        void RutGon(){
            int uc = this->UCLN();
            this->tu /= uc;
            this->mau /= uc;
        }
        PhanSo PSDoi(){
            PhanSo kq;
            kq.tu = -this->tu;
            kq.mau = this->mau;
            return kq;
        }
        PhanSo NghichDao(){
            PhanSo kq;
            kq.tu = this->mau;
            kq.mau = this->tu;
            return kq;
        }
        PhanSo operator+(PhanSo x){
            PhanSo kq;
            kq.tu = this->tu*x.mau + this->mau*x.tu;
            kq.mau = this->mau*x.mau;
            kq.RutGon();
            return kq;
        }
        PhanSo operator-(PhanSo x){
            return *this + x.PSDoi();
        }
        PhanSo operator*(PhanSo x){
            PhanSo kq;
            kq.tu = this->tu*x.tu;
            kq.mau = this->mau*x.mau;
            kq.RutGon();
            return kq;
        }
        PhanSo operator/(PhanSo x){
            return *this * x.NghichDao();
        }
        
};
int main(){
    PhanSo x, y;
    cin >> x;
    cin >> y;
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
}