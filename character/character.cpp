
#include "character.hpp"

character::character()
{
    this->name="Anonimo";
    this->ves=false;
    this->maxParts=16;
    pecas.reserve(16);
}

character::character(std::string name, bool vez) : name(name), ves(vez)
{
    this->maxParts=16;
    pecas.reserve(16);
}

void character::initParts(std::string name, std::string sprite, cel * pos)
{
    pecas.push_back(std::make_unique<part>(name, sprite, pos, this));
}

part * character::findPart(int posX, int posY)
{
    for (auto& p : this->pecas)
    {
        if (p->getX() == posX && p->getY() == posY)
        {
            return p.get();
        }
    }
    return nullptr; //
}

void character::drawPars(sf::RenderWindow &window)
{
    for (auto it = pecas.begin(); it != pecas.end(); ++it)
    {
        // *it é um std::unique_ptr<part>, então usamos -> para acessar métodos
        window.draw((*it)->getSprite());
    }
}

void character::setVes(bool vez)
{
    this->ves=vez;
}

bool character::getVez()
{
    return this->ves;
}

character::~character()
{

}