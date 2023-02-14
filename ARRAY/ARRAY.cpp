#include <iostream>

template <typename T>
class ARRAY
{
private:
    int _size = 0;
    int _capacity = 8;

    T *_array = new T[_capacity];

public:
    const void GetInfo() const
    {
        std::cout << "Size : " << size() << "\nCapacity : " << capacity() << "\nEmpty : " << std::boolalpha << is_empty();
        std::cout << std::endl;
    }
    const void print() const
    {
        for (int i = 0; i < size(); i++)
        {
            std::cout << *(_array + i) << " ";
        }
        std::cout << std::endl;
    }

    const int size() const
    {
        return _size;
    }
    const int capacity() const
    {
        return _capacity;
    }
    const bool is_empty() const
    {
        if (_size == 0)
            return true;
        return false;
    }
    T at(int index)
    {
        if (index < 0 || index >= size())
            exit(0);
        else
            return *(_array + index);
    }
    void push(const T &item)
    {
        if (size() == capacity())
        {
            _capacity *= 2;
            T *temp = new int[capacity()];

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
    void insert(int index, const T &item)
    {
        if (index < 0 || index >= size())
        {
            std::cerr << "Out of Range!\n";
        }
        else
        {
            if (size() == capacity())
            {
                _capacity *= 2;
                T *temp = new int[capacity()];

                for (int i = 0; i < index; i++)
                {
                    *(temp + i) = *(_array + i);
                }
                *(temp + index) = item;
                for (int i = index + 1; i <= size(); i++)
                {
                    *(temp + i) = *(_array + i - 1);
                }
                _size++;
                delete[] _array;
                _array = temp;
            }
            else
            {
                for (int i = size() - 1; i >= index; i--)
                {
                    *(_array + i + 1) = *(_array + i);
                }
                *(_array + index) = item;
                _size++;
            }
        }
    }

    void prepend(const T &item)
    {
        insert(0, item);
    }

    void pop()
    {
        if (is_empty())
        {
            std::cerr << "ARRAY is Empty!\n";
        }
        else
        {
            if (size() - 1 == capacity() / 2)
            {
                _capacity /= 2;
                T *temp = new int[capacity()];

                for (int i = 0; i < size(); i++)
                {
                    *(temp + i) = *(_array + i);
                }
                _size--;
                delete[] _array;
                _array = temp;
            }
            else
            {
                T *temp = new int[capacity()];

                for (int i = 0; i < size() - 1; i++)
                {
                    *(temp + i) = *(_array + i);
                }
                _size--;
                delete[] _array;
                _array = temp;
            }
        }
    }

    void erase(int index)
    {
        if(index < 0 || index >= size())
        {
            std::cerr << "Out of Range!\n";
        }
        else if(index == size() - 1)
        {
            this->pop();
        }
        else
        {
            
        }
    }
};