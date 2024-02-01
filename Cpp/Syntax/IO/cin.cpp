#include <iostream>

using namespace std;

void test_cin_getline(); // cin.getline() will read the input until it meets the delimiter or the max size of the buffer

int main(int argc, char const *argv[])
{
    test_cin_getline();
    return 0;
}


void test_cin_getline() {
// description: cin.getline() will read the input until it meets the delimiter or the max size of the buffer
// parameters: 
//  - char* buffer : the buffer to store the input
//  - int size : the max size of the buffer
//  - char delimiter : the delimiter to stop reading the input

    char name[20];
    cout << "Please enter your name: ";
    cin.getline(name, 20);
    cout << "Hello " << name << endl;


    char stu[5][10];
    int i;
    for (i = 0; i < 5; i++)
        cin.getline(stu[i], 10, ',');
    for (i = 0; i < 5; i++)
        cout << stu[i] << endl;
}