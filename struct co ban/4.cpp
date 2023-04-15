#include <iostream>

using namespace std;

// Khai báo struct lưu trữ thông tin ngày tháng năm
struct Date {
    int day;
    int month;
    int year;
};
Date Nhap(){
    Date x;
    char c;
    cout << "Nhap ngay(dd / mm / yyyy): "; cin >> x.day >> c >> x.month >> c >> x.year;
    return x;
}
void Xuat(Date x){
    cout << x.day << "/" << x.month << "/" << x.year << endl;
}
// Tìm ngày tối đa
int Check(Date date) {
    if (date.year < 0 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31) {
        return false;
    }

    switch (date.month) {
        case 4:
        case 6:
        case 9:
        case 11:
            if (date.day > 30) {
                return false;
            }
            break;
        case 2:
            if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
                if (date.day > 29) {
                    return false;
                }
            } else {
                if (date.day > 28) {
                    return false;
                }
            }
            break;
    }
    return true;
}


int main() {
    // Nhập thông tin về ngày tháng năm
    Date date1, date2;
    date1 = Nhap();
    date2 = Nhap();
    if(Check(date1))
        Xuat(date1);
    else
        cout << "Ngay nhap khong hop le\n";
    
    if(Check(date2))
        Xuat(date2);
    else
        cout << "Ngay nhap khong hop le\n";
    return 0;
}
