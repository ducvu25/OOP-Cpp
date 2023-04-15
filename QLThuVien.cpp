#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class CSach{
    private:
        char ten[30];
        int sl;
        int slMuon;
    public:
        CSach(char ts[] = " ", int sl1 = 0, int sl2 = 0){
            strcpy(ten, ts);
            sl = sl1;
            slMuon = sl2;
        }
        friend istream& operator>>(istream& is,  CSach&x){
            cout << "\nNhap thong tin:\n";
            cin.ignore();
            cout << "Nhap ten: ";   cin.getline(x.ten, 30);
            cout << "Nhap tong so sach: "; cin >> x.sl;
            cout << "Nhap so luong sach da muon: "; cin >> x.slMuon;
            return cin;
        }
        friend ostream& operator<<(ostream& os, CSach x){
            cout << left << setw(35) << x.ten << setw(15) << x.sl << x.slMuon;
            return cout;
        }
        int SoSachConLai(){
            return this->sl - this->slMuon;
        }
};      
void NhapDS(CSach a[], int n){
    cout << "Nhap danh sach:\n";
    for(int i=0; i<n; i++)
        cin >> a[i];
}
void Sort(CSach a[], int n){
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[i].SoSachConLai() > a[j].SoSachConLai()){
                CSach t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
void XuatDS(CSach a[], int n, int SachConLai = -1){
    cout << "\n\tDANH SACH\n";
    cout << left << setw(35) << "Ten sach" << setw(15) << "So sach co" << "So sach da muon\n";
    for(int i=0; i<n; i++)
        if(a[i].SoSachConLai() > SachConLai){
            cout << a[i] << endl;
        }
}
void SachConNhieu(CSach a[], int n, bool ASC){
    int index = 0;
    for(int i=1; i<n; i++)
        if(a[i].SoSachConLai() > a[index].SoSachConLai() == ASC){
                index = i;
            }
    cout << "Thong tin sach: \n" << a[index] << endl; 
}
void TimKiem(CSach a[], int n, int SachConLai){
    cout << "\n\tDANH SACH\n";
    cout << left << setw(35) << "Ten sach" << setw(15) << "So sach co" << "So sach da muon\n";
    for(int i=0; i<n; i++)
        if(a[i].SoSachConLai() == SachConLai){
            cout << a[i] << endl;
        }
}
int main(){
    int n;
    cout << "Nhap so luong: "; cin >> n;
    CSach *a = new CSach[n];
    NhapDS(a, n);
    int chuc_nang;
    do{
        cout << "\n\t\tMENU\n";
        cout << "1. Sap xep danh sach tang dan theo so sach con lai\n";
        cout << "2. In sach co so sach con lai lon hon 10\n";
        cout << "3. Thong tin sach con lai nhieu nhat trong thu vien\n";
        cout << "4. Thong tin sach con lai it nhat trong thu vien\n";
        cout << "5. Thong tin sach con lai 50 cuon\n";
        cout << "0. Thoat\n";
        cout << "Chuc nang: ";
        cin >> chuc_nang;
        switch (chuc_nang)
        {
        case 1:{
            Sort(a, n);
            XuatDS(a, n);
            break;
        }
        case 2:{
            XuatDS(a, n, 10);
            break;
        }
        case 3:{
            SachConNhieu(a, n, true);
            break;
        }
        case 4:{
            SachConNhieu(a, n, false);
            break;
        }
        case 5:{
            TimKiem(a, n, 50);
            break;
        }
        case 0:{
            return 0;
        }
        default:
            break;
        }
    }while(chuc_nang != 0);
    return 0;
} 