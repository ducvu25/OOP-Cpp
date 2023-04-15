#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

struct SinhVien {
    char ten[50];
    char diaChi[100];
    int namSinh;
    float diem;
};

SinhVien Nhap(){
    SinhVien a;
    cout << "\nNhap thong tin:\n";
    cout << "Nhap ten: "; cin.ignore(); cin.getline(a.ten, 50);
    cout << "Nhap dia chi: "; cin.getline(a.diaChi,100);
    cout << "Nhap nam sinh: "; cin >> a.namSinh;
    cout << "Nhap diem: "; cin >> a.diem;
    return a;
}
void Xuat(SinhVien a){
    cout << left << setw(50) << a.ten << setw(100) << a.diaChi << setw(10) << a.namSinh << a.diem << endl;
}
SinhVien* Nhap(int n){
    SinhVien *a = new SinhVien[n];
    for(int i=0; i<n; i++)
        a[i] = Nhap();
    return a;
}
void Xuat(SinhVien *a, int n){
    cout << "\n\t\tDANH SACH\n";
    for(int i=0; i<n; i++)
        Xuat(a[i]);
}
void Search(SinhVien *a, int n){
    int index = -1;
    for(int i=0; i<n; i++){
        if(index == -1 || a[i].diem > a[index].diem)
            index = i;
    }
    if(index == -1)
        cout << "Danh sach trong!\n";
    else{
        cout << "Thong tin sinh vien diem cao nhat\n";
        Xuat(a[index]);
    }
}
void nhapSinhVien(ifstream& f, SinhVien& sv) {
    f.read(reinterpret_cast<char*>(&sv.ten), sizeof(sv.ten)); // đọc trực tiếp vào mảng char
    f.read(reinterpret_cast<char*>(&sv.diaChi), sizeof(sv.diaChi)); // đọc trực tiếp vào mảng char
    f.read(reinterpret_cast<char*>(&sv.namSinh), sizeof(sv.namSinh));
    f.read(reinterpret_cast<char*>(&sv.diem), sizeof(sv.diem));
}

SinhVien* nhapDanhSachSinhVienTuFileNhiPhan(const char* tenFile, int &n) {
    ifstream f(tenFile, ios::binary);
    f.read(reinterpret_cast<char*>(&n), sizeof(n));
    SinhVien* a = new SinhVien[n];
    for(int i=0; i<n; i++){
        while (!f.eof()) {
            nhapSinhVien(f, a[i]);
        }
        f.close();
    }
    return a;
}
void xuatSinhVien(ofstream& f, const SinhVien& sv) {
    // Ghi tên sinh viên vào file
    f.write(sv.ten, strlen(sv.ten) + 1);
    f.write(sv.diaChi, strlen(sv.diaChi) + 1);
    // Ghi tuổi và điểm của sinh viên vào file
    f.write(reinterpret_cast<const char*>(&sv.namSinh), sizeof(sv.namSinh));
    f.write(reinterpret_cast<const char*>(&sv.diem), sizeof(sv.diem));
}
void xuatDanhSachSinhVienVaoFileNhiPhan(const char* tenFile, SinhVien* a, int n){
    std::ofstream f(tenFile, std::ios::binary);
    f.is_open();
    f.write(reinterpret_cast<const char*>(&n), sizeof(n));
    for (int i = 0; i < n; i++) {
        xuatSinhVien(f, a[i]);
    }
    f.close();
}
int main(){
    int n;

}
