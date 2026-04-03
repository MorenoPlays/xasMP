#include "table.hpp"


table::table(uint32_t color1, uint32_t color2) : maxColumn(8), maxLine(8)
{
    int color=0;
    int size = 60;
    for(int i =0 ; i <= maxColumn; i++)
    {
        for (int j = 0; j <= maxLine; j++)
        {
            if(color==0)
            {
                cells[i][j] = cel(color1, i , j, size);
                color=1;
            }
            else
            {
                cells[i][j] = cel(color2, i , j, size);
                color=0;
            }
        }
        
    }
}

void table::draw(sf::RenderWindow & window)
{
    for (int i = 0; i < this->maxLine; i++)
    {
        for (int j = 0; j < this->maxLine; j++)
        {
            window.draw(this->cells[i][j].getCell());
        }
        
    }
    
}

table::~table()
{

}