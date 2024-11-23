#include <iostream>
using std::cout;
using std::endl;

#include <array>
using std::array;

// Start (0,0)
// end (9,8)
array<array<int, 10>,10> maze = {{
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1}
}};



void print(){
    for(array<int,10>& row : maze){
        for(int element: row){
            cout << element << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    print();

    return 0;
}
