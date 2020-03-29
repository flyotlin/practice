#include <iostream>
#include "d_arr.h"

using namespace std;

int main()
{

    d_arr hi(3);
    hi.push(3);
    hi.push(2);
    hi.push(2);
    cout << "Hello world!" <<  hi.get_size() << " " << hi.get_capacity() << endl;
    cout << hi.is_empty() << endl;
//    for(int i = 0; i < 2; i++)
//        cout < hi.at(i) << endl;
    for(int j = 0; j < 3; j++) {
        cout << hi.at(j) << " ";
    }
    hi.push(4);
    hi.push(2);
    hi.push(2);
    cout << "Hello world!" <<  hi.get_size() << " " << hi.get_capacity() << endl;

    for(int j = 0; j < 6; j++) {
        cout << hi.at(j) << " ";
    }
    cout << endl;
    hi.push(3);
    hi.push(2);
    hi.push(2);
    cout << hi.get_size() << endl;
    hi.insert(2, 7);
    for(int j = 0; j < hi.get_size(); j++) {
        cout << hi.at(j) << " ";
    }
    cout << endl;
    cout << hi.get_size() << endl;
    cout << hi.get_capacity() << endl;

    hi.remove(3);
    for(int j = 0; j < hi.get_size(); j++) {
        cout << hi.at(j) << " ";
    }
    cout << endl;
    cout << hi.get_size() << endl;
    cout << hi.get_capacity() << endl;
//    cout << hi.pop() << endl;
//    cout << hi.get_size() << endl;
//    cout << hi.get_capacity() << endl;

//    for(int j = 0; j < hi.get_size(); j++) {
//        cout << hi.at(j) << " ";
//    }
//    cout << endl;
//    cout << hi.find_value(4) << endl;
    return 0;
}
