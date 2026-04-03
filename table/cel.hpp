#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class cel
{
    private:
        uint32_t color;
        float posX;
        float posY;
        float size;
        
    public:
        cel();
        cel(uint32_t color, float posX, float posY, float size);
        cel & operator=(const cel & obj);
        float getX()
        {
            return posX;
        }

        void setX(float x)
        {
            posX= x;
        }

        void setY(float y)
        {
            posY = y;
        }

        float getY()
        {
            return posY;
        }

        float getSize()
        {
            return size;
        }
        sf::RectangleShape getCell();
        ~cel();
};
