#include "MazeSolver.hpp"
#include "MazeException.hpp"
#include <fstream>
#include <iostream>

MazeSolver::MazeSolver(const std::string & file)
{
    std::ifstream inFile;

    inFile.open(file);

    std::string line;

    std::getline(inFile, line);
    this->m_width = std::stoi(line);

    std::getline(inFile, line);
    this->m_height = std::stoi(line);

    this->m_map = new char*[this->m_width];

    for (int i = 0; i < this->m_height; i++)
    {
        this->m_map[i] = new char[this->m_height];
    }

    for (int i = 0; i < this->m_height; i++)
    {
        std::getline(inFile, line);

        for (int j = 0; j < this->m_width; j++)
        {
            this->m_map[i][j] = line[j];
        }
    }

    uint8_t m_status = 0;

    for (int i = 0; i < this->m_height; i++)
    {
        for (int j = 0; j < this->m_width; j++)
        {
            if (this->m_map[i][j] == 'M')
            {
                this->m_mario_pos = {i, j};

                m_status ++;
            }

            if (this->m_map[i][j] == 'P')
            {
                this->m_princess_pos = {i, j};

                m_status ++;
            }
        }
    }

    if (m_status != 2)
    {
        std::string errMsg = "Mario can’t save the Princess!";

        throw MazeException(errMsg);
    }
}

void MazeSolver::display_maze()
{
    for (int i = 0; i < this->m_height; i++)
    {
        for (int j = 0; j < this->m_width; j++)
        {
            std::cout << this->m_map[i][j];
        }

        std::cout << std::endl;
    }
}

void MazeSolver::move_north()
{
    this->m_mario_pos.y ++;
}

void MazeSolver::move_south()
{
    this->m_mario_pos.y --;
}

void MazeSolver::move_east()
{
    this->m_mario_pos.x ++;
}

void MazeSolver::move_west()
{
    this->m_mario_pos.x --;
}

bool MazeSolver::search_path()
{
    if (this->m_map[this->m_mario_pos.x + 1][this->m_mario_pos.y] == ' ')
    {
        this->move_east();
    }

    else if (this->m_map[this->m_mario_pos.x - 1][this->m_mario_pos.y] == ' ')
    {
        this->move_west();
    }

    else if (this->m_map[this->m_mario_pos.x][this->m_mario_pos.y + 1] == ' ')
    {
        this->move_north();
    }

    else if (this->m_map[this->m_mario_pos.x][this->m_mario_pos.y - 1] == ' ')
    {
        this->move_south();
    }

    if (this->m_mario_pos.x == this->m_princess_pos.x && this->m_mario_pos.y == this->m_princess_pos.y)
    {
        return true;
    }

    if (search_path() == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}

MazeSolver::~MazeSolver()
{
    for (int i = 0; i < (this->m_height - 2); i++)
    {
        delete this->m_map[i];
    }

    delete this->m_map;
}
