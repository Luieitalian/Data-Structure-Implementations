#include <iostream>
/**
 *
 * This ARRAY type is capable of growing and shrinking its capacity, removing items, adding items and
 * inserting items.
 *
 */
template <typename T>
class Array
{
private:
    int _size = 0;
    int _capacity = 8;

    T *_array = new T[_capacity];

    void grow()
    {
        _capacity *= 2;
        T *temp = new T[capacity()];

        for (int i = 0; i < _size; i++)
        {
            *(temp + i) = *(_array + i);
        }
        delete[] _array;
        _array = temp;
    }

    void shrink()
    {
        _capacity /= 2;
        T *temp = new T[capacity()];

        for (int i = 0; i < size(); i++)
        {
            *(temp + i) = *(_array + i);
        }
        delete[] _array;
        _array = temp;
    }

public:
    /**
     *  Provides the following info:
     *  size, capacity, emptiness
     */
    const void GetInfo() const
    {
        std::cout << "Size : " << size() << "\nCapacity : " << capacity() << "\nEmpty : " << std::boolalpha << is_empty();
        std::cout << std::endl;
    }
    /**
     *  Prints the elements of the array back to back with blank spaces.
     *  At the very left is the first element, at the very right is the last element.
     */
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
    /**
     * Provides an instance of the element at index.
     */
    const T at(int index) const
    {
        if (index < 0 || index >= size())
        {
            std::cerr << "Out of Range!\n";
            std::cin.get();
            exit(1);
        }
        else
            return *(_array + index);
    }
    /**
     * Pushes the item to the back of the ARRAY. Grows if capacity is not enough for the process.
     */
    void push_back(const T &item)
    {
        if (size() == capacity())
            grow();

        *(_array + _size) = item;
        _size++;
    }
    /**
     * Inserts the item at index. Grows if capacity is not enough for the process.
     */
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
                T *temp = new T[capacity()];

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
    /**
     * Pushes the item to the front of the ARRAY. Grows if capacity is not enough for the process.
     */
    void push_front(const T &item)
    {
        insert(0, item);
    }
    /**
     * Pops the last element of the ARRAY. Shrinks if capacity is bigger than it needed to be.
     */
    void pop()
    {
        if (is_empty())
        {
            std::cerr << "ARRAY is Empty!\n";
        }
        else if (size() - 1 == capacity() / 2)
        {
            shrink();

            T *temp = new T[capacity()];

            for (int i = 0; i < size() - 1; i++)
            {
                *(temp + i) = *(_array + i);
            }
            delete[] _array;
            _array = temp;
            _size--;
        }
        else
        {
            T *temp = new T[capacity()];

            for (int i = 0; i < size() - 1; i++)
            {
                *(temp + i) = *(_array + i);
            }
            delete[] _array;
            _array = temp;
            _size--;
        }
    }
    /**
     * Erases the element at the index. Shrinks if capacity is bigger than it needed to be.
     */
    void erase(int index)
    {
        if (index < 0 || index >= size())
        {
            std::cerr << "Out of Range!\n";
            std::cin.get();
            exit(1);
        }
        else if (index == size() - 1)
        {
            pop();
        }
        else if (size() - 1 == capacity() / 2)
        {
            shrink();

            T *temp = new T[capacity()];

            for (int i = 0; i < index; i++)
            {
                *(temp + i) = *(_array + i);
            }
            for (int i = index; i < size(); i++)
            {
                *(temp + i) = *(_array + i + 1);
            }

            delete[] _array;
            _array = temp;
            _size--;
        }
        else
        {
            T *temp = new T[capacity()];

            for (int i = 0; i < index; i++)
            {
                *(temp + i) = *(_array + i);
            }
            for (int i = index; i < size(); i++)
            {
                *(temp + i) = *(_array + i + 1);
            }

            delete[] _array;
            _array = temp;
            _size--;
        }
    }
    /**
     * Finds the item starting from the front of the ARRAY. If not found returns -1.
    */
    int find(const T &item)
    {
        for (int i = 0; i < size(); i++)
        {
            if (*(_array + i) == item)
            {
                return i;
            }
        }
        return -1;
    }
    /**
     * Removes all of the occurences of the item in the ARRAY. Shrinks if capacity is bigger than it needed to be.
    */
    void remove(const T &item)
    {
        if (is_empty())
        {
            std::cerr << "ARRAY is Empty!\n";
        }
        else
        {
            while (find(item) != -1)
            {
                erase(find(item));
            }
        }
    }
};