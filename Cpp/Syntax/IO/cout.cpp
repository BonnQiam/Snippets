#include<iostream>

using namespace std;

void test_cout_put();   // cout.put() will print the character
void test_cout_write(); // cout.write() will print the string

int main(int argc, char const *argv[])
{
//    test_cout_put();
    test_cout_write();

    return 0;
}

void test_cout_put() {
// Description: cout.put() will print the character
// Parameters:
// - char ch : the character to print
// Primitive function: put(char c)

    char ch = 'a';
    cout.put(ch);
    cout.put('b');
    cout.put('c');
    cout.put('\n');
    cout.put('\n');
}

void test_cout_write() {
// Description: cout.write() will print the string
// Parameters:
// - char* str : the string to print
// - int size : the size of the string
// Primitive function: write(char* str, int size)

    char str[] = "Hello World";
    cout.write(str, 5);
    cout << endl;
    cout.write(str, 11);
    cout << endl;
    cout.write(str, 20);
    cout << endl;
}