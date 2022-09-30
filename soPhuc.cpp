#include <iostream>
#include <math.h>

using namespace std;
class SoPhuc{
    private:
        float thuc;
        float ao;
    public:
        SoPhuc(){
            this->thuc = 0;
            this->ao = 0;
        }
        SoPhuc(float a, float b){
            this->thuc = a;
            this->ao = b;
        }
        float modun(){
            return sqrt(thuc*thuc + ao*ao);
        }
        SoPhuc lienHop(){
            SoPhuc kq;
            kq.thuc = thuc;
            kq.ao = -ao;
            return kq;
        }
        friend istream& operator>>(istream& is, SoPhuc &x){
            cout << "Nhap phan thuc: "; cin >> x.thuc;
            cout << "Nhap phan ao: "; cin >> x.ao;
            return is;
        }
        friend ostream& operator<<(ostream& os, SoPhuc x){
            if(x.thuc == 0 && x.ao == 0){
                cout << 0;
                return os;
            }
            if(x.thuc < 0)
                cout << "(" << x.thuc << ")";
            else if(x.thuc > 0)
                cout << x.thuc;
            if(x.thuc != 0 && x.ao != 0)
                cout << " + ";
            if(x.ao < 0)
                cout << "(" << x.ao << "i)";
            else if(x.ao > 0)
                cout << x.ao << "i";
            return os;
        }
        SoPhuc operator+(SoPhuc x){
            SoPhuc kq;
            kq.thuc = this->thuc + x.thuc;
            kq.ao = this->ao + x.ao;
            return kq;
        }
        SoPhuc operator+(float x){
            SoPhuc kq;
            kq.thuc = this->thuc + x;
            kq.ao = this->ao;
            return kq;
        }
        SoPhuc operator-(SoPhuc x){
            SoPhuc kq;
            kq.thuc = this->thuc - x.thuc;
            kq.ao = this->ao - x.ao;
            return kq;
        }
        SoPhuc operator-(float x){
            SoPhuc kq;
            kq.thuc = this->thuc - x;
            kq.ao = this->ao;
            return kq;
        }
        SoPhuc operator*(SoPhuc x){
            SoPhuc kq;
            kq.thuc = this->thuc*x.thuc - this->ao*x.ao;
            kq.ao = this->ao*x.thuc + this->thuc*x.ao;
            return kq;
        }
        SoPhuc operator*(float x){
            SoPhuc kq;
            kq.thuc = this->thuc*x;
            kq.ao = this->ao*x;
            return kq;
        }
        SoPhuc operator/(float x){
            SoPhuc kq;
            kq.thuc = this->thuc/x;
            kq.ao = this->ao/x;
            return kq;
        }
        SoPhuc operator/(SoPhuc x){
            float m = x.modun();
            return (*this * x.lienHop())/(m*m);
        }
};
int main(){
    SoPhuc x;
    cin >> x;
    SoPhuc y(1, -2);
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    float z = 2.3;
    cout << x << " + " << z << " = " << x + z << endl;
    cout << x << " - " << z << " = " << x - z << endl;
    cout << x << " * " << z << " = " << x * z << endl;
    cout << x << " / " << z << " = " << x / z << endl;
    return 0;
}