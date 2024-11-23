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
    array<int,2> maze_end = {8,9};

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

        if(is_valid_pos(row, column)){
            maze[current_position.top()[0]][current_position.top()[1]] = 0; // Relabels current positon as path
            current_position.push({row,column});
            maze[current_position.top()[0]][current_position.top()[1]] = 8; // Labels new position as player
        }
        else{cout << "Invalid Position" << endl;}
        print_maze();
    };
    void move_right(){
        int row = current_position.top().at(0);
        int column = current_position.top().at(1) + 1;

        if(is_valid_pos(row, column)){
            maze[current_position.top()[0]][current_position.top()[1]] = 0; // Relabels current positon as path
            current_position.push({row,column});
            maze[current_position.top()[0]][current_position.top()[1]] = 8; // Labels new position as player
        }
        else{cout << "Invalid Position" << endl;}
        print_maze();
    };
    void move_down(){
        int row = current_position.top().at(0) + 1;
        int column = current_position.top().at(1);

        if(is_valid_pos(row, column)){
            maze[current_position.top()[0]][current_position.top()[1]] = 0; // Relabels current position as path
            current_position.push({row,column});
            maze[current_position.top()[0]][current_position.top()[1]] = 8; // Labels new position as player
        }
        else{cout << "Invalid Position" << endl;}
        print_maze();
    };
    void move_up(){
        int row = current_position.top().at(0) - 1;
        int column = current_position.top().at(1);

        if(is_valid_pos(row, column)){
            maze[current_position.top()[0]][current_position.top()[1]] = 0; // Relabels current positon as path
            current_position.push({row,column});
            maze[current_position.top()[0]][current_position.top()[1]] = 8; // Labels new position as player
        }
        else{cout << "Invalid Position" << endl;}
        print_maze();

    };
    
    void undo(){
        current_position.pop();
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

    bool win(){
        if(current_position.top().at(0) == maze_end.at(0))
            if(current_position.top().at(1) == maze_end.at(1)){
                cout << "YOU WIN BIG" << endl;
                return true;
            }
        return false;
    }

    MazeGame(){
        current_position.push(maze_start);
        maze.at(maze_start[0]).at(maze_start[1]) = 8;
    };

};


int main(int argc, char const *argv[])
{
    MazeGame start = MazeGame();
    start.print_maze();

    while(!start.win()){
        char user;
        cout << "UP:w | DOWN:s | LEFT:a | RIGHT:d | UNDO: u" << endl;
        std::cin >> user;

        switch (user)
        {
        case 'w':
            start.move_up();
            break;
        case 's':
            start.move_down();
            break;
        case 'a':
            start.move_left();
            break;
        case 'd':
            start.move_right();
            break;
        default:
            break;
        }
    }


    return 0;
}
