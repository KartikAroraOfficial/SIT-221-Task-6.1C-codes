#include <iostream>


class Stack_With_Min
{
    int  *min;
    int *arr;
    int arr_count = 0;
    int min_count = 0;
    int _size = 0;

public:
    Stack_With_Min(int size)
    {
        arr = new int[size];
        min = new int[size];
        _size = size;
    }

    ~Stack_With_Min()
    {
        delete[] arr;
    }

    void push(int data)
    {
        if (isFull())
        {
            std::cout << "Stack Full" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (isEmpty()) 
        {
            min[min_count++] = data;
        }
        if (data - min[min_count -1] > 0) min[min_count++] = data;
        
        arr[arr_count++] = data;
    }
    void pop()
    {
        if (isEmpty()) 
        {
            std::cout << "Nothing there in the stack" << std::endl;
            exit(EXIT_FAILURE);
        }
        int val = arr[arr_count--];

        if (min[min_count - 1] == val)
        {
            min[--min_count] = 0;
        }
        std::cout << "Popped the value. " << std::endl;
    }

    bool isFull()
    {
        return arr_count == _size-1 ? 1 : 0;
    }

    int disp_Min()
    {
        if (isEmpty()) 
        {
            std::cout << "Nothing there in the stack" << std::endl;
            exit(EXIT_FAILURE);
        }
        else return min[min_count -1];
    }

        
    bool isEmpty()
    { 
        return arr_count == 0 ? 1 : 0;
    }
};