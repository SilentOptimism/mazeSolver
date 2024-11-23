#include <iostream>
using std::cout;
using std::endl;

#include <array>
using std::array;

#include <stack>
using std::stack;

const int row_count = 10;
const int column_count = 10;

class MazeGame
{
private:

    array<array<int, row_count>,column_count> maze = {{
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 1}}};

    array<int,2> maze_start = {0,0};
    array<int,2> maze_end = {9,8};

    stack<array<int,2>> current_position;
    
public:
    void print_maze(){
        for(array<int,10>& row : maze){
            for(int element: row){
                cout << element << " ";}
            cout << endl;
        }
        cout << endl;
    }

    void move_left(){
        int row = current_position.top().at(0);
        int column = current_position.top().at(1) - 1;

        if(is_valid_pos(row, column))   {current_position.push({row,column});}
    };

    void move_right(){};

    void move_down(){
        int row = current_position.top().at(0) + 1;
        int column = current_position.top().at(1);

        if(is_valid_pos(row, column)){
            maze[current_position.top()[0]][current_position.top()[1]] = 0;
            current_position.push({row,column});
            maze[current_position.top()[0]][current_position.top()[1]] = 8;
        }
        else{cout << "Invalid Position" << endl;}
        print_maze();
    };

    void move_up(){};
    void undo(){

    };

    bool is_valid_pos(int row, int column){
        // Checks if in bounds of maze
        if(row >= row_count){return false;}
        if(column >= column_count){return false;}
        if(row < 0){return false;}
        if(column < 0){return false;}

        // Checks if it is a wall or a path and returns
        return !maze[row][column];
    }

    MazeGame(){
        current_position.push(maze_start);
        maze.at(maze_start[0]).at(maze_start[1]) = 8;
    };

};








/*
void print_position(){
    cout << "(" << position.at(0) << "," << position.at(1) << ")" << endl;
}

// Returns true if maze point is zero, Returns false if maze point is true
bool is_valid_pos(array<int,2> position){
    return !maze[position[0]][position[1]];
}



*/

int main(int argc, char const *argv[])
{
    MazeGame start = MazeGame();
    start.print_maze();
    cout << endl;
    start.move_down();


    return 0;
}
