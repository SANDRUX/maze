#pragma once

#include <string>

struct Position
{
    int x;
    int y;
};

class MazeSolver
{
private:
    Position m_mario_pos;
    Position m_princess_pos;
    char ** m_map;
    int m_width;
    int m_height;
    void move_north();
    void move_south();
    void move_west();
    void move_east();

public:
    MazeSolver(const std::string &);
    ~MazeSolver();
    void display_maze();
    bool search_path();
};
