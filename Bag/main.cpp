#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct BagNode
{
    string data;
    int count;
    BagNode *next;
};
string Print(BagNode *head)
{
    stringstream out;
    for (BagNode *i = head; i != NULL; i = i->next)
        if (i->count > 1)
            out << i->data << " (" << i->count << ")" << endl;
        else if (i->count == 1)
            out << i->data << endl;
    return out.str();
}
string Low(string &s)
{
    string a = "";
    string s2 = "";
    int len = s.size();
    for (int i = 0; i < len; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            a.push_back(s[i] + 32);
            s2.push_back(s[i]);
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            a.push_back(s[i]);
            s2.push_back(s[i]);
        }
    s = s2;
    return a;
}

void Push(BagNode *&head, string s)
{
    string s1 = Low(s);
    if (s == "")
        return;
    if (head == NULL)
    {
        head = new BagNode;
        head->data = s;
        head->count = 1;
        head->next = NULL;
    }
    else
    {
        BagNode *j = NULL;
        BagNode *i = head;
        while (i != NULL)
        {
            string s2 = Low(i->data);
            if (s2 == s1)
            {
                if (i->data[0] < s[0])
                    i->data = s;
                i->count++;
                return;
            }
            if (s2 > s1)
                break;
            j = i;
            i = i->next;
        }
        if (j == NULL)
        {
            BagNode *p = new BagNode;
            p->data = s;
            p->count = 1;
            p->next = head;
            head = p;
        }
        else
        {
            BagNode *p = new BagNode;
            p->data = s;
            p->count = 1;
            if (j->next == NULL)
            {
                p->next = NULL;
                j->next = p;
            }
            else
            {
                p->next = j->next;
                j->next = p;
            }
        }
    }
}
void Delete(BagNode *head, string s)
{
    string s1 = Low(s);
    for (BagNode *i = head; i != NULL; i = i->next)
        if (Low(i->data) == s1)
            if (i->count > 0)
                i->count--;
}
bool Init(BagNode *&head, string s)
{
    ifstream in(s.c_str());
    if (!in)
        return false;
    string s2;
    while (in >> s2)
    {
        Push(head, s2);
        // cout << s2 << endl;
    }
    in.close();
    return true;
}
int main()
{
    cout << "Welcome to the dictionary\n";
    string s; // = "input.txt";
    BagNode *head = NULL;
    int fun;
    do
    {
        cout << "\n\t\tMenu\n";
        cout << "1. File processing\n";
        cout << "2. Print results\n";
        cout << "3. Refresh\n";
        cout << "0. Quit\n";
        cout << "Choose the function: ";
        cin >> fun;
        switch (fun)
        {
        case 1:
        {
            cin.ignore();
            cout << "Enter the file name: ";
            getline(cin, s);
            if (!Init(head, s))
                cout << "No find file\n";
            break;
        }
        case 2:
        {
            cin.ignore();
            cout << "Enter the file name: ";
            getline(cin, s);
            ofstream out(s.c_str());
            if (!out)
                cout << "No open file\n";
            else
            {
                out << Print(head);
                out.close();
            }
            break;
        }
        case 3:
        {
            head = NULL;
            break;
        }
        case 0:
        {
            cout << "BYE!";
            break;
        }
        default:
            cout << "The function not in menu\n";
            break;
        }
    } while (fun != 0);

    return 0;
}
