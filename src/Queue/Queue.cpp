#include <iostream>

/**
 * Linked list style Queue
 */
template <typename T>
class LinkedQueue
{
private:
    struct node
    {
        T value;
        node *next;
        node() : value(0), next(nullptr) {}
        node(const T &val) : value(val), next(nullptr) {}
        node(const T &val, node *n) : value(val), next(n) {}
    };

    node *root = nullptr;
public:

    ~LinkedQueue()
    {
        if (empty())
            delete root;
        else
        {
            node *tmp = nullptr;
            while (root->next != nullptr)
            {
                tmp = root->next;

                delete root;
                root = tmp;
            }
            delete root;
        }
    }

    void enqueue(const T &value)
    {
        if (empty())
        {
            root = new node(value, nullptr);
        }
        else
        {
            node *tmp = root;

            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = new node(value);
        }
    }

    const T front() const
    {
        if (!empty())
            return root->value;
        else
            exit(-1);
    }
    const T back() const
    {
        if (!empty())
        {
            node *tmp = root;

            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            return tmp->value;
        }
        else
            exit(-1);
    }

    void dequeue()
    {
        if (!empty())
        {
            node *tmp = root->next;

            delete root;
            root = tmp;
        }
        else
        {
            std::cerr << "Queue is Empty!\n";
        }
    }

    const bool empty() const
    {
        if (root == nullptr)
            return true;
        return false;
    }
};

/**
 * Static array style Queue
 */
template <typename T, int size>
class StaticQueue
{
private:
    T *array = new T[size];
    int index = 0;

public:
    ~StaticQueue() { delete[] array; }
    void enqueue(const T &value)
    {
        if (index == size)
        {
            exit(-1);
        }
        else
        {
            *(array + index) = value;
            index++;
        }
    }

    const T front() const
    {
        return *(array);
    }
    const T back() const
    {
        if (!empty())
            return *(array + index - 1);
        else
        {
            exit(-1);
        }
    }

    void dequeue()
    {
        if (empty())
            exit(-1);
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                *(array + i) = *(array + i + 1);
            }
        }
    }

    const bool empty() const
    {
        if (index == 0)
            return true;
        else
            return false;
    }
};