#include <fstream>
#include <iostream>

#include <cstring>
#include <vector>

using namespace std;

void test_put_get();
void test_example_1();
void test_example_2();

int main(){
    //test_put_get();
    //test_example_1();
    test_example_2();
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

void test_example_1(){
    class Employee {
        private:
        int number, age;
        char name[20];
        double sal;

        public:
        Employee() {}
        //Employee(int num, char *Name, int Age, double Salary) {
        Employee(int num, const char *Name, int Age, double Salary) {
            number = num;
            strcpy(name, Name);
            age = Age;
            sal = Salary;
        }
        void display() {
            cout << number << "\t" << name << "\t" << age << "\t" << sal << endl;
        }
    };


    ofstream out("Employee.dat", ios::out); //定义随机输出文件
    Employee e1(1, "A", 23, 2320);
    Employee e2(2, "B", 32, 3210);
    Employee e3(3, "C", 34, 2220);
    Employee e4(4, "D", 27, 1220);
    out.write((char *)&e1, sizeof(e1)); //!按 e1,e2,e3,e4 顺序写入文件
    out.write((char *)&e2, sizeof(e2));
    out.write((char *)&e3, sizeof(e3));
    out.write((char *)&e4, sizeof(e4));

    //下面的代码将e3（即王五）的年龄改为40岁
    Employee e5(3, "D", 40, 2220);
    out.seekp(
        2 *sizeof(e1) //!指针定位到第3（起始为0）个数据块，这里写错了应该是2*sizeof（e1）
        ); 
    out.write((char *)&e5, sizeof(e5)); //将e5写到第3个数据块位置，覆盖e3
    out.close();                        //关闭文件
    
    // read the file
    cout << "Read the file" << endl;

    ifstream in("Employee.dat", ios::in); //定义随机读文件
    Employee e;
    in.read((char *)&e, sizeof(e)); //读取第一个数据块
    while (!in.eof()) {
        e.display();
        in.read((char *)&e, sizeof(e)); //读取下一个数据块
    }
    in.close(); //关闭文件
}

void test_example_2(){
    class Person {
        private:
        char name[20];
        char id[18];
        int age;
        char addr[20];

        public:
        Person() {}
        Person(char *n, const char *pid, int Age, char *Addr) {
            strcpy(name, n);
            strcpy(id, pid);
            age = Age;
            strcpy(addr, Addr);
        }
        void display() {
            cout << name << "\t" << id << "\t" << age << "\t" << addr << endl;
        }
    };

    vector<Person> v;
    vector<Person>::iterator pos;
    
    char ch;
    ofstream out("person.dat", ios::out | ios::app | ios::binary);
    char Name[20], ID[18], Addr[20];
    int Age;
    
    cout << "------Input personal file------" << endl << endl;
    do {
        cout << "Name: ";
        cin >> Name;
        cout << "ID: ";
        cin >> ID;
        cout << "Age: ";
        cin >> Age;
        cout << "Address: ";
        cin >> Addr;
        Person per(Name, ID, Age, Addr);
        out.write((char *)&per, sizeof(per));
        cout << "Enter another Person(y/n)?";
        cin >> ch;
    } while (ch == 'y');
    out.close();

    ifstream in("person.dat", ios::in | ios::binary);
    Person s;
    in.read((char *)&s, sizeof(s));
    while (!in.eof()) {
        v.push_back(s);
        in.read((char *)&s, sizeof(s));
    }
    
    cout << "\n---------Read from file--------" << endl << endl;
    pos = v.begin();
    for (pos = v.begin(); pos != v.end(); pos++)
        (*pos).display();
}