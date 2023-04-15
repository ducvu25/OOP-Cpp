#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void Init(){
    int a[32768] = {0};
    ofstream cout("./SONGUYEN.INP");
    int n = 0;
    while(n < 10000){
        int r;
        do{
            r = rand()%32767 + 1;
        }while(a[r] == 1);
        a[r] = 1;
        cout << r << endl;
        n++;
    }
}
int main(){
   Init();
    return 0;
}