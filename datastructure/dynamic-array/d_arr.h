#ifndef D_ARR_H
#define D_ARR_H


class d_arr
{
    public:
        d_arr(int capacity);
        int get_size();
        int get_capacity();
        bool is_empty();
        void push(int num);
        int at(int index);  // starting from 0
        void resize_capacity();
        int find_value(int value);
        void insert(int index, int value);
        int pop();
        void remove(int index);
    private:
        int size = 0;
        int capacity = 0;
        int *data;  // later allocate the memory space to pointer data
};

#endif // D_ARR_H
