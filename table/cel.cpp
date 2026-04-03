#include "cel.hpp"

cel::cel()
{
    this->color=0;
    this->posX=0;
    this->posY=0;
    this->size=0;
}

cel::cel(uint32_t color, float posX, float posY, float size) : color(color) , posX(posX), posY(posY) , size(size)
{

}

cel & cel::operator=(const cel &obj )
{
    if(this != &obj)
    {
        this->color= obj.color;
        this->posX=obj.posX;
        this->posY=obj.posY;
        this->size = obj.size;
    }
    return *this;
}

sf::RectangleShape cel::getCell()
{
    sf::RectangleShape  ret({this->size, this->size});
    ret.setPosition(sf::Vector2f(this->posX*size, this->posY*size));
    ret.setFillColor(sf::Color(this->color));
    return (ret);
}



cel::~cel()
{

}