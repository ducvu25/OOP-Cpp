#include<iostream>
#include<math.h>
using namespace std;

struct ToaDo {
    float x, y;
};
ToaDo Nhap(){
    ToaDo x;
    cout << "Nhap toa do: "; cin >> x.x >> x.y;
    return x;
}
void Xuat(ToaDo x){
    cout << "(" << x.x << ", " << x.y << ")\n";
}

ToaDo Ox(ToaDo x){
    ToaDo a;
    a.x = -x.x;
    a.y = x.y;
    return a;
}
ToaDo Oy(ToaDo x){
    ToaDo a;
    a.x = x.x;
    a.y = -x.y;
    return a;
}
float KhoangCach(ToaDo x, ToaDo y){
    return sqrt((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y));
}
int main(){
    ToaDo a, b;
    a = Nhap();
    b = Nhap();
    Xuat(a);
    cout << "Doi xung qua Ox: "; Xuat(Ox(a));
    Xuat(b);
    cout << "Doi xung qua Oy: "; Xuat(Oy(b));
    cout << "Khoang cach AB: " << KhoangCach(a, b);
    return 0;
}