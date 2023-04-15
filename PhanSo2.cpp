#include<iostream>
using namespace std;

class PS{
    private:
        int tu;
        int mau;
    public:
        PS(){
            this->tu = 0;
            this->mau = 1;
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
            int ucln = this->UCLN();
            this->tu /= ucln;
            this->mau /= ucln;
        }
        friend istream& operator>>(istream& is, PS &x){
            char c;
            cout << "Nhap phan so: ";
            cin >> x.tu >> c >> x.mau;
            return cin;
        }
        friend ostream& operator<<(ostream& os, PS x){
            cout << x.tu << "/" << x.mau;
            return cout;
        }
        PS operator+(PS b){
            PS x;
            x.tu = this->tu*b.mau + b.tu*this->mau;
            x.mau = this->mau * b.mau;
            x.RutGon();
            return x;
        }
        PS operator-(PS b){
            PS x;
             x.tu = this->tu*b.mau - b.tu*this->mau;
            x.mau = this->mau - b.mau;
            x.RutGon();
            return x;
        }
        PS operator*(PS b){
            PS x;
            x.tu = this->tu*b.tu;
            x.mau = this->mau * b.mau;
            x.RutGon();
            return x;
        }
        PS operator/(PS b){
            PS x;
            x.tu = this->tu*b.mau;
            x.mau = this->mau * b.tu;
            x.RutGon();
            return x;
        }
        ~PS(){
            //cout << "Da huy doi tuong\n";
        }
};      
int main(){
    PS a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " : " << b << " = " << a / b << endl;
    return 0;
}