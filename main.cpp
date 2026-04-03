// #include "./Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "./table/table.hpp"
#include "character/character.hpp"

uint32_t light1 = 0xF0D9B5FF; // bege claro
uint32_t dark1 = 0xB58863FF; // castanho

uint32_t light2 = 0x3C3C3CFF; // cinza médio
uint32_t dark2  = 0x1E1E1EFF; // quase preto

uint32_t light3 = 0xEEEED2FF; // verde claro suave
uint32_t dark3  = 0x769656FF; // verde clássico

uint32_t light4 = 0xA8DADCFF; // azul claro
uint32_t dark4  = 0x457B9DFF; // azul escuro

uint32_t light5 = 0xCDB4DBFF; // roxo claro
uint32_t dark5 = 0x6A4C93FF; // roxo escuro

uint32_t light6 = 0xFAEDCDFF; // dourado claro
uint32_t dark6  = 0xD4A373FF; // dourado escuro

float cellSize = 60;

int selectedX = -1;
int selectedY = -1;

bool pieceSelected = false;

int main()
{
    
    std::string player1Name;
    std::string player2Name;

    std::cout << "Player 1 Name: " << std::endl;
    std::cin >> player1Name;
    character player1(player1Name, true);
    std::cout << "Player 2 Name: " << std::endl;
    std::cin >> player2Name ;
    character player2(player2Name, true);
    sf::RenderWindow window(sf::VideoMode({60*8, 60*8}), "XasMP", sf::Style::Close);
    table ta(light5, dark5);
    sf::RectangleShape selecteds({cellSize, cellSize});
    selecteds.setFillColor(sf::Color(255, 0, 0, 100));
    part * partSelect;
    //pecas de tras
    /************************************************************************ */
    player1.initParts("Rook", "./ChessAssets/b_Rook.png", &ta.cells[0][7]);
    player1.initParts("Knight", "./ChessAssets/b_Knight.png", &ta.cells[1][7]);
    player1.initParts("Bishop", "./ChessAssets/b_Bishop.png", &ta.cells[2][7]);
    player1.initParts("Queen", "./ChessAssets/b_Queen.png", &ta.cells[3][7]);
    player1.initParts("King", "./ChessAssets/b_King.png", &ta.cells[4][7]);
    player1.initParts("Bishop", "./ChessAssets/b_Bishop.png", &ta.cells[5][7]);
    player1.initParts("Knight", "./ChessAssets/b_Knight.png", &ta.cells[6][7]);
    player1.initParts("Rook", "./ChessAssets/b_Rook.png", &ta.cells[7][7]);
    //Peoes
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[0][6]);
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[1][6]);
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[2][6]);
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[3][6]);
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[4][6]);
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[5][6]);
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[6][6]);
    player1.initParts("Pawn", "./ChessAssets/b_Pawn.png", &ta.cells[7][6]);

    //player 2
    //pecas de tras
    player2.initParts("Rook", "./ChessAssets/w_Rook.png", &ta.cells[0][0]);
    player2.initParts("Knight", "./ChessAssets/w_Knight.png", &ta.cells[1][0]);
    player2.initParts("Bishop", "./ChessAssets/w_Bishop.png", &ta.cells[2][0]);
    player2.initParts("Queen", "./ChessAssets/w_Queen.png", &ta.cells[3][0]);
    player2.initParts("King", "./ChessAssets/w_King.png", &ta.cells[4][0]);
    player2.initParts("Bishop", "./ChessAssets/w_Bishop.png", &ta.cells[5][0]);
    player2.initParts("Knight", "./ChessAssets/w_Knight.png", &ta.cells[6][0]);
    player2.initParts("Rook", "./ChessAssets/w_Rook.png", &ta.cells[7][0]);
    //Peoes
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[0][1]);
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[1][1]);
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[2][1]);
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[3][1]);
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[4][1]);
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[5][1]);
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[6][1]);
    player2.initParts("Pawn", "./ChessAssets/w_Pawn.png", &ta.cells[7][1]);
    //********************************************************************* */
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {


                    int mousex = event.mouseButton.x;
                    int mousey = event.mouseButton.y;

                    int cellx = mousex/cellSize;
                    int celly = mousey/cellSize;
                    std::cout <<  "X: " << cellx << "Y: " << celly << std::endl;
                    selecteds.setPosition({cellx*cellSize, celly*cellSize});
                    if(pieceSelected)
                    {
                        partSelect->setCell(&ta.cells[cellx][celly]);
                        pieceSelected= false;
                        continue;
                    }
                    if(player1.getVez() == true)
                    {
                        partSelect = player1.findPart(cellx, celly);
                        if(!partSelect)
                        { 
                            std::cerr << "Nao e sua peca" << std::endl;
                            continue;
                        }
                        pieceSelected=true;
                        selectedX = cellx;
                        selectedY = celly;
                        player1.setVes(false);
                        player2.setVes(true);
                        continue;
                    }
                    else
                    {
                        partSelect = player2.findPart(cellx, celly);
                        if(!partSelect)
                        { 
                            std::cerr << "Nao e sua peca" << std::endl;
                            continue;
                        }
                        pieceSelected=true;
                        selectedX = cellx;
                        selectedY = celly;
                        player1.setVes(true);
                        player2.setVes(false);
                        continue;
                    }
                    
                }
            }

            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }
        window.clear(sf::Color::Black);
        ta.draw(window);
        if(pieceSelected==true)
            window.draw(selecteds);
        player1.drawPars(window);
        player2.drawPars(window);
        window.display();
    }
    
}