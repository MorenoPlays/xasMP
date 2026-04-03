
#include "part.hpp"

part::part()
{
    this->name="Peao";
    this->player = NULL;
    this->pos= NULL;
    this->countMove = 0;
}

part::part(std::string name, std::string spritePath, cel * pos, character *player)
{
    this->name = name;
    this->pos = pos;
    this->player = player;

    if (!this->texture.loadFromFile(spritePath))
    {
        std::cout << "Erro ao carregar textura\n";
    }

    this->sprite.setTexture(this->texture);

    float cellSize = 60.0f;
    sf::Vector2u texSize = this->texture.getSize();

    this->sprite.setScale(cellSize / texSize.x, cellSize / texSize.y);

    // posicionar dentro da célula
    this->sprite.setPosition(pos->getX() * pos->getSize(), pos->getY() * pos->getSize());
}

sf::Sprite & part::getSprite()
{
    this->sprite.setPosition(pos->getX() * pos->getSize(), pos->getY() * pos->getSize());
    return this->sprite;
}
part::~part()
{

}

