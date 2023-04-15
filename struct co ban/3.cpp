#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct ThoiGian{
    int h, m, s;
};
ThoiGian Nhap(){
    ThoiGian x;
    char c;
    cout << "Nhap thoi gian: "; cin >> x.h >> c >> x.m >> c >> x.s;
    if(x.h < 0 || x.h > 23 || x.m > 59 || x.m < 0 || x.s > 59 || x.s < 0)
        x.h = -1;
    return x;
}
void Xuat(ThoiGian x){
    if(x.h == -1)   cout << "NULL";
    else
        cout << x.h << ":" << x.m << ":" << x.s << endl;
}
ThoiGian Denta(ThoiGian a, ThoiGian b){
    ThoiGian x;
    if(a.h == -1 || b.h == -1){
        x.h = -1;
        return x;
    }
    if(a.h < b.h) 
        return Denta(b, a);
    x.s = a.s - b.s;
    if(x.s < 0){
        x.m = a.m - b.m - 1;
        x.s += 60;
    }else
        x.m = a.m - b.m;
    
    if(x.m < 0){
        x.h = a.h - b.h - 1;
        x.m += 60;
    }else
        x.h = a.h - b.h;
    return x;
}

int main(){
    ThoiGian x, y;
    x = Nhap();
    y = Nhap();
    cout << "Chenh lech thoi gian: ";
    Xuat(Denta(x, y));
    return 0;
}