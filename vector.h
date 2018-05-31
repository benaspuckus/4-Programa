//
// Created by MD on 2018-05-30.
//

#ifndef INC_4_UZDUOTIS_VECTOR_H
#define INC_4_UZDUOTIS_VECTOR_H
#include <string>
#include <unordered_set>

template <class T> class vector
{
private:
    int vSize, maxSize;
    T* array;
    void alloc_new();

public:
    vector();
    vector(int);
    vector(const vector&);
    ~vector();
    vector& operator+=(T);
    void push_back(T);
    void pop_back();
    int size();
    T operator[] (int);
    T existing(int);
    vector&operator=(const vector&);
    typedef T* iterator;
    iterator begin();
    iterator end();




};
iterator.
template <class T> vector<T>::vector()
{
    maxSize = 20;
    array = new T[maxSize];
    vSize = 0;

}
template <class T> vector<T>::vector(int i)
{
    maxSize = i;
    array = new T[maxSize];
    vSize = 0;

}

template <class T> void vector<T>::alloc_new()
{
    maxSize = vSize*2;
    T* laikinas = new T[maxSize];
    for(int i = 0; i < vSize;i++)
    {
        laikinas[i]=array[i];
    }
    delete[] array;
    array = laikinas;
}
template <class T> vector<T>::vector(const vector& v)
{
        maxSize = v.maxSize;
        vSize = v.vSize;
        array = new T [maxSize];
        for(int i=0; i<v.vSize; i++)
        {
            array[i] = v.array[i];
        }
}
template <class T> vector<T>::~vector()
{
    delete[] array;
}
template <class T> void vector<T>::push_back(T i)
{
    if (vSize+1>maxSize)
        alloc_new();
    array[vSize] = i;
    vSize++;
}
template <class T> void vector<T>::pop_back()
{
    delete &array[vSize-1];
    vSize--;
}
template <class T> T vector<T>::operator[](int i)
{
    return array[i];
}
template <class T> vector<T>& vector<T>::operator+=(T i)
{
    this->push_back(i);
    return *this;
}
template <class T> T vector<T>::existing(int i)
{
    if(i<vSize)
        return array[i];
    throw 10;

}
template <class T> int vector<T>::size()
{
    return vSize;
}
template <class T> vector<T>& vector<T>::operator=(const vector& v)
{
if(this!=&v)
{
    maxSize = v.maxSize;
    vSize = v.vSize;
    delete[] array;
    array = new T [maxSize];
    for(int i=0; i<v.vSize; i++)
    {
        array[i] = v.array[i];
    }
}
return *this;

}

#endif //INC_4_UZDUOTIS_VECTOR_H