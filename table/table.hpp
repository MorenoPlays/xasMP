#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "cel.hpp"
#include <SFML/Graphics.hpp>
class table
{
    private:
        int maxColumn;
        int maxLine;
        uint32_t colors[2];
    public:
        cel cells[8][8];
        table(uint32_t color1, uint32_t color2);
        void draw(sf::RenderWindow & window);
        ~table();
};
