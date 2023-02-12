#include<iostream>

template<typename T>
class ARRAY
{
private:

    int _size = 0;
    int _capacity = 8;

    T* _array = new T[_capacity];



public:

    void GetInfo()
    {
        std::cout << "Size : "<<size()<<"\nCapacity : "<<capacity()<<"\nEmpty : "<<std::boolalpha<< is_empty();
        std::cout << std::endl;
    }
    void print()
    {
        for (int i = 0; i < size(); i++)
        {
            std::cout << *(_array + i) << " "; 
        }
        std::cout << std::endl;        
    }

    int size()
    {
        return _size;
    }
    int capacity()
    {
        return _capacity;
    }
    bool is_empty()
    {
        if(_size == 0)
            return true;
        return false;
    }
    T at(int index)
    {
        return *(_array + index);
    }
    void push(T item)
    {
        if (_size == _capacity)
        {
            _capacity *= 2;
            T* temp = new int[_capacity];
            
            for (int i = 0; i < _size; i++)
            {
                *(temp + i) = *(_array + i);
            }
            *(temp + _size) = item; 
            delete[] _array;
            _array = temp;
            _size++;
        }
        else
        {
            *(_array + _size) = item;
            _size++;
        }
    }
};