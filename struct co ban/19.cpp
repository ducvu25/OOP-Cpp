#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void Init(int n, int max, int min){
    ofstream cout("./SONGUYEN.INP");
    while(n > 0){
        cout << rand()%(max - min + 1) + min << endl;
        n--;
    }
}
void NV(){
    ofstream cout1("./SOCHAN.OUT");
    ofstream cout2("./SOLE.OUT");

    ifstream cin("./SONGUYEN.INP");
    int x;
    while(cin >> x){
        if(x%2 == 0)
            cout1 << x << endl;
        else
            cout2 << x << endl;
    }
}
int main(){
    int n, max, min;
   cout << "Nhap so luong: "; cin >> n;
   cout << "Nhap khoang min, max: "; cin >> min >> max;
   Init(n, max, min);
    NV();
    return 0;
}