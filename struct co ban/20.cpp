#include <iostream>
#include <fstream>

using namespace std;

void writeToFile() {
    ofstream outfile;
    outfile.open("SOCHAN.DAT", ios::out | ios::binary);

    for (int i = 0; i <= 100; i += 2) {
        outfile.write(reinterpret_cast<const char*>(&i), sizeof(int));
    }
}

void readFromFile() {
    ifstream infile;
    infile.open("SOCHAN.DAT", ios::in | ios::binary);

    int count = 0;
    int num;
    while (infile.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        cout << num << " ";
        count++;
        if (count % 30 == 0) {
            cout << endl;
        }
    }
}

int main() {
    writeToFile();
    readFromFile();
    return 0;
}
