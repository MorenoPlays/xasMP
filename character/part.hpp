#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "../table/cel.hpp"


class character;

class  part
{
    private:
        std::string name;
        sf::Texture texture;
        sf::Sprite sprite;
        cel * pos;
        character *player;
        int countMove;
    public:
     part();
     int getX()
     {
        return pos->getX();
     }

     character *  getPlayer()
     {
        return this->player;
     }
     int getY()
     {
        return pos->getY();
     }

     void setPosX(float po)
     {
        pos->setX(po);
     }

     void setPosY(float po)
     {
        pos->setY(po);
     }

     void setCell(cel * pos)
     {
        this->pos = pos;
     }
     sf::Sprite & getSprite();
     part(std::string name, std::string spritePath, cel * pos, character *player);
    ~part();
};
