#include "person.h"
#include "integer.h"
#include "list.h"
#include "dlinkedlist.h"
#include "vsarray.h"
#include "sorted_double_linked_list.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::setw;
using std::fixed;
using std::setprecision;
using std::sort;
using std::vector;

void Test(List *, bool= true);

void TestSortedList();

void GradingTest(List *list);

void GradingSortedTest();

int main(int argc, char *argv[]) {
    srand(time(0));
    if (argc == 2){
        string s(argv[1]);
        if (s == "-grade"){
            GradingTest(new DoubleLinkedList());
            GradingTest(new VSArray(5));
            GradingSortedTest();
            return 0;
        }else{
            cerr << "Incorrect Command line Parameter" << endl;
        }
    }
    cout << "====================================" << endl;
    cout << endl << endl;
    cout << "There are 3 sets of unit tests:" << endl;
    cout << "   1. Double Linked List        - 55" << endl;
    cout << "   2. Variable Size Array List  - 55" << endl;
    cout << "   3. Sorted Double Linked List - 10" << endl;
    cout << "====================================" << endl;
    cout << "====================================" << endl;
    cout << endl << endl;

    cout << "- - - - - - - - 1 - - - - - - - -" << endl;
    cout << "Double Linked List Tests" << endl << endl;
    Test(new DoubleLinkedList(), false);

    cout << "- - - - - - - - 2 - - - - - - - -" << endl;
    cout << "Variable Size Array List Tests" << endl << endl;
    Test(new VSArray(5), false);

    cout << "- - - - - - - - 3 - - - - - - - -" << endl;
    cout << "Sorted Double Linked List Tests" << endl;
    TestSortedList();
    cout << endl << endl;
    cout << "- - - - - - - - - - - - - - - - - - - " << endl;
    cout << endl;
    cout << "    C O N G R A T U L A T I O N S" << endl;
    cout << "          All test passed!" << endl << endl;
    return 0;
}

void TestSortedList() {
    SortedDoubleLinkedList *list = new SortedDoubleLinkedList();
    const size_t SIZE = 10;
    vector<int> data;
    for (size_t i = 0; i < SIZE; ++i) {
        data.push_back(rand() % 1000);
    }
    for (size_t i = 0; i < SIZE; ++i) {
        list->Insert(new Integer(data[i]));
    }
    sort(data.begin(), data.end());
    size_t passed = 0;
    const double TOTAL = 10.0;
    Integer *integer = nullptr;
    for (size_t i = 0; i < SIZE; ++i) {
        integer = dynamic_cast<Integer *>(list->Get(i));
        assert(integer != nullptr);
        assert(integer->GetValue() == data[i]);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
    }
    delete list;
    cout << endl << endl;
    cout << "= = = = = = = = = = = = = = = = = = = = = " << endl;
    cout << endl << "F i n i s h e d   S u c c e s s f u l l y" << endl;
}

void Test(List *list, bool fixedSize) {
    size_t passed = 0;
    const double TOTAL = 55.0;

    assert(list->Size() == 0);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->IsEmpty() == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    Person *person = nullptr;
    Integer *integer = nullptr;
    Object *object = nullptr;
    Person *GEORGE = new Person("George", 12);
    Integer *TEN = new Integer(10);
    Object *DUMMY = new Object();

    person = new Person("George", 12);
    assert(list->Insert(person, 2) == false);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->IsEmpty() == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Insert(person, 0) == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Get(0)->ToString() == "Person: {name: George, age: 12}");
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Size() == 1);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->IndexOf(GEORGE) == 0);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    integer = new Integer(10);
    assert(list->Insert(integer, 0) == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Get(0)->ToString() == "10");
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Get(1)->ToString() == "Person: {name: George, age: 12}");
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Size() == 2);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->IndexOf(TEN) == 0);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->IndexOf(GEORGE) == 1);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->IndexOf(DUMMY) == -1);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    person = new Person("Patrick", 1);
    assert(list->Insert(person, 1) == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Size() == 3);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    person = new Person("Natalia", 19);
    assert(list->Insert(person, 2) == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Size() == 4);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    integer = new Integer(4);
    assert(list->Insert(integer, 4) == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->Size() == 5);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    if (fixedSize) {
        for (size_t i = 0; i < list->Size(); i++) {
            assert(list->Insert(integer, i) == false);
            cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        }
        assert((object = list->Remove(0)) != nullptr);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        assert(list->Size() == 4);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        assert(object->ToString() == "10");
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        delete object;
        object = nullptr;

        TEN->SetValue(4);
        assert(list->IndexOf(TEN) == 3);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        assert(list->IndexOf(GEORGE) == 2);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        TEN->SetValue(10);
        assert(list->IndexOf(TEN) == -1);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    } else {
        assert(list->Insert(new Person("Violet", 1), list->Size()) == true);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        assert(list->Size() == 6);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        assert((object = list->Remove(5)) != nullptr);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        assert(object->ToString() == "Person: {name: Violet, age: 1}");
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        // Fixing the Leak
        delete object;
        object = nullptr;
        assert(list->Size() == 5);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        // Final Version Tests for ALL CODE
        stringstream inputData, insertedData;
        inputData.str(    // name age position | number position
                "Winston 55 0\n"
                "75 0\n"
                "Peter 43 3\n"
                "32 3\n"
                "Legolas 156 9\n"
                "99 1\n"
                "Patricia 21 0\n"
                "130 0\n"
                "Anna 23 1\n"
                "1304 14"
        );
        string name;
        size_t age, position, number;
        for (size_t i = 0; i < 5; i++) {
            inputData >> name >> age >> position;
            assert(list->Insert(new Person(name, age), position) == true);
            cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
            inputData >> number >> position;
            assert(list->Insert(new Integer(number), position) == true);
            cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        }

        assert(list->Size() == 15);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        insertedData.str(    // name age position | number position
                "Winston 55 5\n"
                "75 3\n"
                "Peter 43 8\n"
                "32 7\n"
                "Legolas 156 13\n"
                "99 4\n"
                "Patricia 21 2\n"
                "130 0\n"
                "Anna 23 1\n"
                "1304 14"
        );

        for (size_t i = 0; i < 5; i++) {
            insertedData >> name >> age >> position;
            object = new Person(name, age);
            assert(list->IndexOf(object) == static_cast<int>(position));
            cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
            insertedData >> number >> position;
            delete object;
            object = nullptr;
            object = new Integer(number);
            assert(list->IndexOf(object) == static_cast<int>(position));
            cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
            delete object;
            object = nullptr;
        }
        assert((object = list->Remove(4)) != nullptr);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        assert(list->Size() == 14);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        assert(object->ToString() == "99");
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
        delete object;
        object = nullptr;

        assert((object = list->Get(7)) != nullptr);
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

        assert(object->ToString() == "Person: {name: Peter, age: 43}");
        cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    }


    list->Clear();
    assert(list->Size() == 0);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    assert(list->IsEmpty() == true);
    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

    delete list;
    delete GEORGE;
    delete TEN;
    delete DUMMY;

    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;
    cout << endl << endl;
    cout << "= = = = = = = = = = = = = = = = = = = = = " << endl;
    cout << endl << "F i n i s h e d   S u c c e s s f u l l y" << endl << endl;

}


void GradingTest(List *list) {

    size_t passed = 0;
    const double TOTAL = 55.0;

    if (list->Size() == 0) { ++passed; }
    if (list->IsEmpty() == true) { ++passed; }

    Person *person = nullptr;
    Integer *integer = nullptr;
    Object *object = nullptr;
    Person *GEORGE = new Person("George", 12);
    Integer *TEN = new Integer(10);
    Object *DUMMY = new Object();

    person = new Person("George", 12);
    if (list->Insert(person, 2) == false) { ++passed; }
    if (list->IsEmpty() == true) { ++passed; }
    if (list->Insert(person, 0) == true) { ++passed; }
    if (list->Get(0)->ToString() == "Person: {name: George, age: 12}") { ++passed; }
    if (list->Size() == 1) { ++passed; }
    if (list->IndexOf(GEORGE) == 0) { ++passed; }

    integer = new Integer(10);
    if (list->Insert(integer, 0) == true) { ++passed; }
    if (list->Get(0)->ToString() == "10") { ++passed; }
    if (list->Get(1)->ToString() == "Person: {name: George, age: 12}") { ++passed; }
    if (list->Size() == 2) { ++passed; }
    if (list->IndexOf(TEN) == 0) { ++passed; }
    if (list->IndexOf(GEORGE) == 1) { ++passed; }
    if (list->IndexOf(DUMMY) == -1) { ++passed; }

    person = new Person("Patrick", 1);
    if (list->Insert(person, 1) == true) { ++passed; }
    if (list->Size() == 3) { ++passed; }

    person = new Person("Natalia", 19);
    if (list->Insert(person, 2) == true) { ++passed; }
    if (list->Size() == 4) { ++passed; }

    integer = new Integer(4);
    if (list->Insert(integer, 4) == true) { ++passed; }
    if (list->Size() == 5) { ++passed; }
    if (list->Insert(new Person("Violet", 1), list->Size()) == true) { ++passed; }
    if (list->Size() == 6) { ++passed; }
    if ((object = list->Remove(5)) != nullptr) { ++passed; }
    if (object->ToString() == "Person: {name: Violet, age: 1}") { ++passed; }
    // Fixing the Leak
    delete object;
    object = nullptr;
    if (list->Size() == 5) { ++passed; }
    // Final Version Tests for ALL CODE
    stringstream inputData, insertedData;
    inputData.str(    // name age position | number position
            "Winston 55 0\n"
            "75 0\n"
            "Peter 43 3\n"
            "32 3\n"
            "Legolas 156 9\n"
            "99 1\n"
            "Patricia 21 0\n"
            "130 0\n"
            "Anna 23 1\n"
            "1304 14"
    );
    string name;
    size_t age, position, number;
    for (size_t i = 0; i < 5; i++) {
        inputData >> name >> age >> position;
        if (list->Insert(new Person(name, age), position) == true) { ++passed; }
        inputData >> number >> position;
        if (list->Insert(new Integer(number), position) == true) { ++passed; }
    }
    if (list->Size() == 15) { ++passed; }
    insertedData.str(    // name age position | number position
            "Winston 55 5\n"
            "75 3\n"
            "Peter 43 8\n"
            "32 7\n"
            "Legolas 156 13\n"
            "99 4\n"
            "Patricia 21 2\n"
            "130 0\n"
            "Anna 23 1\n"
            "1304 14"
    );
    for (size_t i = 0; i < 5; i++) {
        insertedData >> name >> age >> position;
        object = new Person(name, age);
        if (list->IndexOf(object) == static_cast<int>(position)) { ++passed; }
        insertedData >> number >> position;
        delete object;
        object = nullptr;
        object = new Integer(number);
        if (list->IndexOf(object) == static_cast<int>(position)) { ++passed; }
        delete object;
        object = nullptr;
    }
    if ((object = list->Remove(4)) != nullptr) { ++passed; }
    if (list->Size() == 14) { ++passed; }
    if (object->ToString() == "99") { ++passed; }

    delete object;
    object = nullptr;

    if ((object = list->Get(7)) != nullptr) { ++passed; }
    if (object->ToString() == "Person: {name: Peter, age: 43}") { ++passed; }

    list->Clear();
    if (list->Size() == 0) { ++passed; }
    if (list->IsEmpty() == true) { ++passed; }


    delete list;
    delete GEORGE;
    delete TEN;
    delete DUMMY;

    cout << setw(10) << fixed << setprecision(2) << ++passed / TOTAL * 100.0 << endl;

}

void GradingSortedTest() {
    SortedDoubleLinkedList *list = new SortedDoubleLinkedList();
    const size_t SIZE = 10;
    vector<int> data;
    for (size_t i = 0; i < SIZE; ++i) {
        data.push_back(rand() % 1000);
    }
    for (size_t i = 0; i < SIZE; ++i) {
        list->Insert(new Integer(data[i]));
    }
    sort(data.begin(), data.end());
    size_t passed = 0;
    const double TOTAL = 10.0;
    Integer *integer = nullptr;
    for (size_t i = 0; i < SIZE; ++i) {
        integer = dynamic_cast<Integer *>(list->Get(i));
        assert(integer != nullptr);
        if (integer->GetValue() == data[i]) {
            ++passed;
        }
    }
    cout << setw(10) << fixed << setprecision(2) << passed / TOTAL * 100.0 << endl;
    delete list;

}
