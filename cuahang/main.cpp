#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Item
{
    string name;
    float price;
};

class MenuItemType
{
private:
    Item data[100];
    int num;

public:
    MenuItemType()
    {
        num = 0;
    }
    void GetData()
    {
        ifstream in("breakfasts.txt");
        Item x;
        while (getline(in, x.name))
        {
            in >> x.price;
            data[num] = x;
            num++;
            in.ignore();
        }
    }
    void ShowData()
    {
        cout << "\n\t\tMENU\n";
        cout << left << setw(30) << "Item"
             << "Price" << endl;
        for (int i = 0; i < num; i++)
            cout << left << setw(30) << data[i].name << data[i].price << endl;
    }
    Item *Index(string name)
    {
        for (int i = 0; i < num; i++)
            if (data[i].name == name)
                return &data[i];
        return NULL;
    }
};
class Bill
{
private:
    MenuItemType data;
    Item a[100];
    int num;

public:
    Bill()
    {
        data.GetData();
        num = 0;
    }
    void Oder()
    {
        data.ShowData();
        string s;
        cout << "\nEnter name item: ";
        cin.ignore();
        getline(cin, s);
        Item *x = data.Index(s);
        if (x == NULL)
            cout << "Item not in list\n";
        else
        {
            a[num] = *x;
            num++;
        }
    }
    void Pay()
    {
        cout << "\n\t\tBill\n";
        cout << left << setw(30) << "Item"
             << "Price" << endl;
        float sum = 0;
        for (int i = 0; i < num; i++)
        {
            cout << left << setw(30) << a[i].name << a[i].price << endl;
            sum += a[i].price;
        }
        cout << "TAX: " << sum * 0.05 << endl;
        cout << "Total: " << sum * 0.95 << endl;
    }
};
int main()
{
    Bill a;
    cout << "Welcome to Jonny's Restaurant\n";
    int fun;
    while (true)
    {
        cout << "\n\t\tMenu\n";
        cout << "1. Oder\n";
        cout << "2. Pay\n";
        cout << "Choose function: ";
        cin >> fun;
        if (fun == 1)
        {
            a.Oder();
        }
        else if (fun == 2)
        {
            a.Pay();
            break;
        }
        else
            cout << "The function is invalid.";
    }
    return 0;
}