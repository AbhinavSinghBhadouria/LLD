#include<iostream>
using namespace std;

class WalkableRobot{
public:
virtual void walk()=0;
virtual ~WalkableRobot(){}
};

class NormalWalk : public WalkableRobot{
    public:
    void walk() override{
        cout<<"Walking normally..."<<endl;
    }
};

class NoWalk: public WalkableRobot{
    public:
    void walk() override{
        cout<<"Cannot walk..."<<endl;
    }
};

class TalkableRobot{
    public:
    virtual void talk()=0;
    virtual ~TalkableRobot(){} //it is important beacuse it allows to delete derived class objects through base class pointers without causing undefined behavior.
};

class NormalTalk: public TalkableRobot{
    public:
    void talk() override { // here we are overriding the talk method of the base class TalkableRobot
        cout<<"Talking normally..."<<endl;
    }

};

class NoTalk: public TalkableRobot{
    public:
    void talk() override{
        cout<< "Cannot talk..."<<endl;
    }
};


class flyableRobot{
    public:
    virtual void fly()=0;
    virtual ~flyableRobot(){}
};


class NormalFly: public flyableRobot{
    public:
    void fly() override{
        cout<<"Flying normally..."<<endl;
    }
};

class Nofly: public flyableRobot{
    void fly() override{
        cout<<"cannot fly..."<<endl;
    }
};

class Robot{
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    flyableRobot* flyBehavior;

    public:
    Robot(WalkableRobot* w , TalkableRobot* t, flyableRobot* f){
        this->walkBehavior = w;
        this->talkBehavior = t;     
        this->flyBehavior = f;
    }

    void walk(){
        walkBehavior->walk();
    }

    void talk(){
        talkBehavior->talk();
    }

    void fly(){
        flyBehavior->fly();
    }

    virtual void projection() =0; // abstract method for subclasses.....
};
    class CompanionRobot : public Robot{
        public:
        CompanionRobot(WalkableRobot* w , TalkableRobot* t, flyableRobot* f): Robot(w,t,f){}
        void projection() override{
            cout<<"I am a companion robot..."<<endl;
    }
};

class WorkerRobot: public Robot{
    public: 
    WorkerRobot(WalkableRobot* w , TalkableRobot* t, flyableRobot* f): Robot(w,t,f){}
    void projection() override{
        cout<<"I am a worker robot..."<<endl;   
}
};
int main(){
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NormalFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new Nofly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();
}