//
// Created by MD on 2018-05-30.
//

#ifndef INC_4_UZDUOTIS_VECTOR_H
#define INC_4_UZDUOTIS_VECTOR_H
#include <string>
#include <iterator>

template <class T> class vector
{
private:
    int vSize, maxSize;
    T* array;
    T* argument;
    void alloc_new();

public:
    vector();
    typedef T* iterator;
    typedef const T* const_iterator;
    vector(int);
    vector(const vector&);
    ~vector();
    vector& operator+=(T);
    int capacity();
    void push_back(T);
    void pop_back();
    int size();
    void insert(const_iterator, T);
    T operator[] (int);
    T existing(int);
    vector&operator=(const vector&);
    iterator begin();
    iterator end();
    void clear();
    template <class ... Args>
    iterator emplace(const_iterator , Args && ... args);
    void resize(int);



};
template <class T> vector<T>::vector()
{
    maxSize = 4;
    array = new T[maxSize];
    vSize = 0;

}
template <class T>
typename vector<T>::iterator vector<T>::begin()
{
    return array;
}
template  <class T>
typename vector<T>::iterator vector<T>::end()
{
    return array + vSize;
}
template <class T> vector<T>::vector(int i)
{
    maxSize = i;
    array = new T[maxSize];
    vSize = 0;

}
template <class T>
template <class ... Args>
typename vector<T>::iterator vector<T>::emplace(const_iterator it, Args && ... args)
{
    /*if (vSize+1>maxSize)
        alloc_new();
    iterator ite = &argument[it - argument];
    argument[vSize - *ite] = std::move( T( std::forward<Args>(args)...) );
    *ite =  T( std::forward<T>(args)...);
    ++vSize;
    return ite;*/
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
template <class T> void vector<T>::clear()
{
    delete[] array;
    maxSize = 0;
    array = new T[maxSize];
    vSize = 0;
}
template <class T> void vector<T>::insert(vector<T>::const_iterator it, T i)
{
   T * tmp;
    if (vSize+1>maxSize)
        alloc_new();
    int index = it - begin();
    T laikinas = array[index];
    T laikinas2;
    array[index] = i;
    for(auto k = index; k!=end()-begin()+2; k++ )
    {
        laikinas2 = array[k+1];
        array[k+1] = laikinas;
        laikinas = laikinas2;
    }
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
template <class T> void vector<T>::resize(int i)
{
    if(i<vSize)
    {
        for(int k = vSize; k>i;k--)
        {
            delete &array[k];
            vSize--;
        }
        vSize = i;
    }
    if(i>=vSize)
    {
        for(int k = 0;k < i; k++)
        {
            push_back(0);
        }
    }
}
template <class T> int vector<T>::capacity()
{
    return maxSize;
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
