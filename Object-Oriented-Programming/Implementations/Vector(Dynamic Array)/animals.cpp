#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Animal{
public:
    Animal(){
    number = 0;
    type = "";
    }
    Animal(string _type, int _number){
     this->setType(_type);
     this->setNumber(_number);
    }
    void setType(string _type){
      this->type = _type;
    }
    void setNumber(int _number){
       this->number = _number;
    }
    void print()const{
    cout<<"Animal: "<<type<<" "<<number<<endl;
    }
private:
    string type;
    int number;
};

/*int main(){

Animal an1("bear",3);
an1.print();
vector<Animal>animals;
animals.push_back(an1);
animals[0].print();
//animals[0] = Animal("bear", 10);
//animals[0].print();
}
*/
