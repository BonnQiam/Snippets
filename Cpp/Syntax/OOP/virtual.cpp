#include <iostream>

using namespace std;

void Test_virtual();

int main() 
{
    Test_virtual();
	
    return 0;
}

void Test_virtual()
{
	class Cpoint    //基类 
	{
	protected:
			double X,Y;
	public:    
			Cpoint(double x, double y)
				{X=x;  Y=y;} 
	//      	void print()
			virtual void print()
				{cout<<'('<<X<<','<<Y<<')'<<endl; }
	};

	class Circle:public Cpoint  //派生类 
	{private:
		double r;
	public:
			Circle(double x,double y,double r1):Cpoint(x,y) 
			{      r=r1;     } 
			void print() 
			{      
				cout<<'('<<X<<','<<Y<<')'<<endl; 
				cout<<" r= "<<r<<endl; 	 
			}
	};

	Cpoint p(0,0),*q;   
	Circle s(2,1,5); 

	q=&p;	           
	q->print();       
	
    q=&s;            
	q->print(); 
}