#include <iostream>
#include "vector.h"

int main() {
    vector <double> v;

    int tmp;
for(int i=0;i<3;i++)
{
    std::cin>>tmp;
    v.push_back(tmp);
}
v+=15;
    std::cout << "ivedei " << v.size()<<std::endl;
    for(int i=0; i<v.size();i++)
    {
        std::cout<<v[i]<<"  ";
    }
    std::cout<<std::endl;
    vector <double > ve(v);
    vector <double > vec;
    std::cout<<std::endl;
    vec=v;
    for(int i=0; i<ve.size();i++)
    {
        std::cout<<ve[i]<<"  ";
    }
    std::cout<<std::endl;
    vec.pop_back();

    for(int i=0; i<vec.size();i++)
    {
        std::cout<<vec[i]<<"  ";
    }
    return 0;
}