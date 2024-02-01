#include <fstream>
#include <iostream>

using namespace std;

void test_fstream();

int main(int argc, char const *argv[]) {
    test_fstream();

    return 0;
}


void test_fstream() {
    fstream ioFile;
    ioFile.open("./a.dat", ios::out);
    
    ioFile << "A"
            << "  " << 76 << " " << 98 << " " << 67 << endl; // L3
    ioFile << "B"
            << "  " << 89 << " " << 70 << " " << 60 << endl;
    ioFile << "C"
            << "  " << 91 << " " << 88 << " " << 77 << endl;
    ioFile << "D"
            << "  " << 62 << " " << 81 << " " << 75 << endl;
    ioFile << "E"
            << "  " << 90 << " " << 78 << " " << 67 << endl;
    ioFile.close();
    
    ioFile.open("./a.dat", ios::in | ios::binary); // ios::in | ios::binary means read the file in binary mode
    
    char name[10];
    
    int chinese, math, computer;
    
    cout << "Name\t"
        << "English\t"
        << "Math\t"
        << "Computer\t"
        << "Sum" << endl;
    
    ioFile >> name;

    while (!ioFile.eof()) {
        ioFile >> chinese >> math >> computer;
        cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t"
            << chinese + math + computer << endl;
        ioFile >> name;
    }
    ioFile.close();
}