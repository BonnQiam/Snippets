#include <cstring>
#include <iostream>

using namespace std;

struct Person { //职工基本信息的结构
  double salary;
  char *name;
};

class SalaryManaege {
  Person *employ; //存放职工信息的数组
  int max;        //数组下标上界
  int n;          //数组中的实际职工人数

public:
  SalaryManaege(int Max = 0) {
    max = Max;
    n = 0;
    employ = new Person[max];
  }
  //返回引用特性是可以直接在放在左值，直接使用
  double &operator[](char *Name) { //重载[]，返回引用
    Person *p;
    for (p = employ; p < employ + n; p++)
      //如果存在处理
      if (strcmp(p->name, Name) == 0)
        return p->salary;
    //不存在情况处理
    p = employ + n++;
    p->name = new char[strlen(Name) + 1];
    strcpy(p->name, Name);
    p->salary = 0;
    return p->salary;
  }

  void display() {
    for (int i = 0; i < n; i++)
      cout << employ[i].name << "   " << employ[i].salary << endl;
  }
  
  ~SalaryManaege() { delete[] employ; }
};


int main() {
  SalaryManaege s(3);
  s["A"] = 2188.88;
  s["B"] = 1230.07;
  s["C"] = 3200.97;
  cout << "A\t" << s["A"] << endl;
  cout << "B\t" << s["B"] << endl;
  cout << "C\t" << s["C"] << endl;

  cout << "-------Display output--------\n\n";
  s.display();
}
