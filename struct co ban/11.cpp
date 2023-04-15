#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

const int MAX = 100;

struct SinhVien {
    string maSV;
    string tenSV;
    int namSinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTB;
};
SinhVien Nhap(){
    SinhVien a;
    cout << "Ma sinh vien: ";
    cin >> a.maSV;
    cout << "Ten sinh vien: ";
    cin.ignore();
    getline(cin, a.tenSV);
    cout << "Nam sinh: ";
    cin >> a.namSinh;
    cout << "Diem toan: ";
    cin >> a.diemToan;
    cout << "Diem ly: ";
    cin >> a.diemLy;
    cout << "Diem hoa: ";
    cin >> a.diemHoa;
    a.diemTB = (a.diemToan + a.diemLy + a.diemHoa) / 3;
    return a;
}
void Xuat(SinhVien x){
    cout << left << setw(10) << x.maSV << setw(30) << x.tenSV << setw(10) << x.namSinh 
    << setw(10) << x.diemToan << setw(10) << x.diemLy << setw(10) << x.diemHoa << x.diemTB << endl;
}
void NhapDS(SinhVien a[], int& n) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
        a[i] = Nhap();
    }
}

//b) Xuất danh sách sinh viên ra màn hình.
void Xuat(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        Xuat(a[i]);
    }
}

//c) Tìm sinh viên có điểm trung bình cao nhất.
void timSinhVienDiemCaoNhat(SinhVien a[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].diemTB > a[index].diemTB) {
            index = i;
        }
    }
    cout << "Sinh vien co diem TB cao nhat:\n";
    Xuat(a[index]);
}
//e) Sắp xếp danh sách lớp theo thứ tự giảm dần của điểm toán.
void Yd(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diemTB > a[j].diemTB) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "\n\tDANH SACH SAU KHI SAP XEP\n";
    Xuat(a, n);
}

//e) Sắp xếp danh sách lớp theo thứ tự giảm dần của điểm toán.
void sapXepDiemToanGiamDan(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diemToan < a[j].diemToan) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "\n\tDANH SACH SAU KHI SAP XEP\n";
    Xuat(a, n);
}

//f) Tìm kiếm và in ra các sinh viên có điểm trung bình lớn hơn 5 và không có môn nào dưới 3.
void timSinhVienDiemTB5KhongDuoi3(SinhVien a[], int n) {
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (a[i].diemTB > 5 && a[i].diemToan >= 3 && a[i].diemLy >= 3 && a[i].diemHoa >= 3) {
            timThay = true;
            Xuat(a[i]);
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien nao." << endl;
    }
}

//g) Tìm sinh viên có tuổi lớn nhất.
void timSinhVienTuoiLonNhat(SinhVien a[], int n) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (index == -1 || (a[i].namSinh < a[index].namSinh)) {
            index = i;
        }
    }
    if (index != -1) {
        cout << "Sinh vien co tuoi lon nhat: " << endl;
        Xuat(a[index]);
    } else {
        cout << "Khong tim thay sinh vien nao." << endl;
    }
}

//h) Nhập vào tên của một sinh viên. Tìm và in ra các thông tin liên quan đến sinh viên đó (nếu có).
void timSinhVienTheoTen(SinhVien a[], int n, string ten) {
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (a[i].tenSV.find(ten) != -1) {
            timThay = true;
            Xuat(a[i]);
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien nao." << endl;
    }
}
int main(){
    SinhVien a[100];
    int n;
    NhapDS(a, n);
    Xuat(a, n);
    timSinhVienDiemCaoNhat(a, n);
    Yd(a, n);
    sapXepDiemToanGiamDan(a, n);
    timSinhVienDiemTB5KhongDuoi3(a, n);
    timSinhVienTuoiLonNhat(a, n);
    string ten;
    cout << "nhap ten: ";
    cin.ignore(); getline(cin, ten);
    timSinhVienTheoTen(a, n, ten);
    return 0;
}