#include <iostream>
#include "vector.h"
using std::cout;

int main() {
    vector <int> v;

    int tmp;
for(int i=0;i<5;i++)
{

    v.push_back(i);
}
v+=15;
    std::cout << v.size()<<" - SIZE"<<std::endl;
    for(int i=0; i<v.size();i++)
    {
        std::cout<<v[i]<<"  ";
    }
    std::cout <<" - PUSH BACK, OPERATOR +="<<std::endl;
    cout<<v.capacity()<<" - CAPACITY"<<std::endl;
    v.insert(v.begin()+3, 20);


    for(int i=0; i<v.size();i++)
    {
        std::cout<<v[i]<<"  ";
    }
    cout<<" - INSERT "<<std::endl;
    /*v.emplace(v.begin()+7,25);
    for(int i=0; i<v.size();i++)
    {
        std::cout<<v[i]<<"  ";
    }*/
    v.resize(3);
    std::cout << v.size()<<" - SIZE"<<std::endl;

    for(int i=0; i<v.size();i++)
    {
        std::cout<<v[i]<<"  ";
    }
    cout<<" - RESIZE "<<std::endl;
    for(int i=7;i<11;i++)
    {
        v.push_back(i);
    }
    for(int i=0; i<v.size();i++)
    {
        std::cout<<v[i]<<"  ";
    }
    cout<<" - PUSH BACK"<<std::endl;

    v.clear();
    cout<<" - CLEAR "<<std::endl;

}