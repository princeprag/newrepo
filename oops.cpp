#include<bits/stdc++.h>
using namespace std;
class Animal
{
   
    public:
     int id;
     string name;
     string colour;

    Animal()
    {
        cout<<"Animal Def Cons"<<endl;
    }

    Animal(int i,string nm,string clr)
    {
        this->id=i;
        this->name=nm;
        this->colour=clr;
        cout<<"Animal Par Cons"<<endl;
    }

    

    
    void display()
    {
        cout<<id<<" "<<name<<" "<<colour<<endl;
    }
    virtual void getId()
    {
        cout<<"The Id of Animal is: "<<id<<endl;
    }
    ~Animal()
    {
        cout<<"Animal Destructor Here"<<endl;
    }

};

class Dog : public Animal
{
   bool army;  // instance member variable
   
   public:  
   static int num; // class member variable
   Dog(bool f,int i,string nm,string clr):Animal(i,nm,clr)
   {
        army=f;
        cout<<"Dog par cons here"<<endl;
       
   }
   ~Dog()
   {
       cout<<"Dog destructor here"<<endl;
   }
    void getId()
    {
        cout<<"The Id of Dog is: "<<id<<endl;
    }
   void display() // the display function is overwritten in the case (polymorphism)
   {
        cout<<"Is this an Army Dog? ==  "<<army<<endl;
   }

  static void setNum(int n) // class member function
  {
      num=n;
  }
 
};

int Dog:: num=10;




int main()
{

  Animal* dog= new Dog(true,1,"bruno","white"); 
  dog->display();
  dog->getId();
  delete dog;

//   Dog* dog= new Dog(true,1,"bruno","white"); 
//   dog->display();
//   delete dog;
  
// Dog dog(true,1,"ss","aa");
// dog.display();
  
//   Animal am(1,"bruno","white");
//   am.display();

//   Animal* am=new Animal(1,"bruno","white");
//   am->display();
//   delete am;




  cout<<Dog::num<<endl;
  Dog::setNum(100); // static function can be called without actually creating an object
  cout<<Dog::num<<endl;
  
  

  return 0;
}