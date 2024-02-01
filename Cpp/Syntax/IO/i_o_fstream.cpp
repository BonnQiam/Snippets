#include <fstream>
#include <iostream>

using namespace std;

void test_put_get();

int main(){
    test_put_get();
    return 0;
}

void test_put_get(){
    
    char ch;
    ofstream out("/test.dat", ios::out | ios::binary); // L1
    
    for (int i = 0; i < 90; i++) {
        if (i > 0 && (i % 30) == 0)
        out.put('\n');
        out.put(i);
        out.put(' ');
    }
    out.close();
    
    ifstream in("/test.dat", ios::in | ios::binary);
    while (in.get(ch))
        cout << ch;
    in.close();
}