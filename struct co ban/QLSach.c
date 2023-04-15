#include"QLSach.h"

int main(){
    int chuc_nang;
    do{
        chuc_nang = Menu();
        switch (chuc_nang)
        {
        case 1:{
            TaoFile("FU.txt");
            break;
        }
        case 2:{
            Xuat();
            break;
        }
        case 3:{
            Sort();
            break;
        }
        case 4:{
            SearchName();
            break;
        }
        case 5:{
            SearchAuthor();
            break;
        }
        case 6:{
            printf("\n\t\tTam biet!");
            break;
        }
        default:
            break;
        }
    }while(chuc_nang != 6);
    return 0;
}