#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
    public:
    //constructor
    Hero(){
        cout<<"Constructor called"<<endl;
    }
    char level;
    void print(){
        cout<<level<<endl;
    }
    int getHealth(){
        return health;
    }
    char getLevel(){return level;}
    void setHealth(int h){
        health=h;
    }
    void setLevel(char ch){
        level=ch;
    }
};

int main(){
    Hero *geralt=new Hero;
    // Hero geralt;
    int n;
    cout<<"enter health of hero: "<<endl;
    cin>>n;
    geralt->setHealth(n);
    cout<<"Health of hero is: "<<geralt->getHealth()<<endl;
    // geralt.setHealth(n);
    // cout<<"Health of hero is: "<<geralt.getHealth()<<endl;
    return 0;
}