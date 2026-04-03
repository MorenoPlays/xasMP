#pragma once
#include <iostream>
#include <string.h>
#include "part.hpp"
#include "../table/table.hpp"

class character
{
    private:
        std::string name;
        bool ves;
        int maxParts;
        std::vector<std::unique_ptr<part>> pecas;
        
    public:
        character();
        part * findPart(int posX, int posY);
        character(std::string name, bool vez);
        void drawPars(sf::RenderWindow & window);
        void initParts(std::string name, std::string sprite, cel * pos);
        bool getVez();
        void setVes(bool ves);
        ~character();
};
