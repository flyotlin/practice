#include "d_arr.h"

d_arr::d_arr(int capacity)
{
    this->capacity = capacity;

    //we need to allocate the memory space to int *data
    data = new int[capacity];
}

int d_arr::get_size() {
    return size;
}

int d_arr::get_capacity() {
    return capacity;
}

bool d_arr::is_empty() {
    if(size == 0)
        return true;
    else
        return false;
}

void d_arr::push(int num) {
    if(size > capacity)
        resize_capacity();

    *(data+size) = num;
    size++;
}

int d_arr::at(int index) {
    if(index > size-1 || index < 0)
        return -1;
    return *(data+index);
}

void d_arr::resize_capacity() {
    capacity *= 2;
    int *p = new int[capacity * 2]; // new array allocated

    for(int i = 0; i < size; i++) {
        *(p+i) = *(data+i);
    }

    delete data;
    data = p;
}

int d_arr::find_value(int value) {
    for(int i = 0; i < size; i++) {
        if(value == *(data+i))
            return i;
    }

    return -1;
}

void d_arr::insert(int index, int value) {
    if(size+1 > capacity)
        resize_capacity();

    int *temp = new int[capacity];
    for(int i = 0; i < index; i++) {
        *(temp+i) = *(data+i);
    }
    *(temp+index) = value;
    for(int i = index+1; i < size+1; i++) {
        *(temp+i) = *(data+i-1);
    }
    delete data;
    data = temp;
    size++;
}

int d_arr::pop() {
    int n = *(data+size-1);
    size--;
    return n;
}

void d_arr::remove(int index) {
    int *temp = new int[capacity];
    for(int i = 0; i < index; i++) {
        *(temp+i) = *(data+i);
    }
    for(int i = index; i < size-1; i++) {
        *(temp+i) = *(data+i+1);
    }
    delete data;
    data = temp;
    size--;
}
