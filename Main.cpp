#include "MazeSolver.hpp"
#include <iostream>

int main(int argc, char * argv[])
{
    std::string file(argv[1]);

    MazeSolver * obj;

    try
    {
        obj = new MazeSolver(file);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what();
        exit(EXIT_FAILURE);
    }

    obj->display_maze();

    bool status = obj->search_path();

    if (status == true)
    {
        std::cout << "Mario can save the princess!";
    }

    else
    {
        std::cout << "Mario cant save the princess!";
    }

    delete obj;

    return 0;
}
