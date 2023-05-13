#include <iostream>
#include <fstream>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void Push(int _value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->value = _value;
            head->next = NULL;
        }
        else
        {
            Node *j = NULL;
            Node *i = head;
            while (i != NULL)
            {
                if (i->value >= _value)
                    break;
                j = i;
                i = i->next;
            }
            if (j == NULL)
            {
                Node *p = new Node;
                p->value = _value;
                p->next = head;
                head = p;
            }
            else
            {
                Node *p = new Node;
                p->value = _value;
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
    bool Remove(int _value)
    {
        if (head == NULL)
            return false;
        if (head != NULL && head->value == _value)
        {
            Node *p = head;
            head = head->next;
            delete p;
            return true;
        }
        Node *i = head;
        while (i->next != NULL)
        {
            if (i->next->value == _value)
            {
                Node *p = i->next;
                i->next = p->next;
                delete p;
                return true;
            }
            else
                i = i->next;
        }
        return false;
    }
    void Print()
    {
        for (Node *i = head; i != NULL; i = i->next)
            cout << i->value << " ";
    }
};
LinkedList *Init(string s, int &num)
{
    ifstream in(s.c_str());
    LinkedList *a = new LinkedList;
    string c;
    num = 0;
    while (in >> c)
    {
        int d;
        in >> d;
        if (c == "I,")
            a->Push(d);
        else if (!a->Remove(d))
            num++;
        // cout << c << " " << d << endl;
        // system("pause");
    }
    return a;
}
int main()
{
    int num;
    LinkedList *a = Init("input.txt", num);
    cout << num << endl;
    a->Print();
    return 0;
}