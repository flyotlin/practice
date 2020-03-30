#ifndef D_ARR_H
#define D_ARR_H


class d_arr {
    public:
        d_arr(int capacity);
        bool is_empty();
        int get_size();
        int get_capacity();
        int at(int index);  // starting from 0
        int find_value(int value);
        int pop();
        void push(int num);
        void resize_capacity();
        void insert(int index, int value);
        void remove(int index);
    private:
        int size = 0;
        int capacity = 0;
        int *data;  // later allocate the memory space to pointer data
};

#endif // D_ARR_H
