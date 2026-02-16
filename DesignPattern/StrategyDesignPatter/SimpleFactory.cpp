#include<iostream>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0; // pure virtual function
    virtual ~Burger(){};   // virtual destructor
};


class BasicBurger: public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a basic burger..."<<endl;
    }
};


class StandardBurger: public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a standard burger..."<<endl;
    }
};


class PremiumBurger: public Burger{
    public:
    void prepare() override{
        cout<<"Preparing a Premium burger..."<<endl;
    }
};

class BurgerFactory{
    public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }

        else if(type =="premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"Invalid Burger Type! "<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type ="premium";

    BurgerFactory* myBurgerFactory = new BurgerFactory();

    Burger* burger = myBurgerFactory->createBurger(type);
//this is a comment
    burger->prepare();
    delete burger;
    delete myBurgerFactory;
    return 0;
}