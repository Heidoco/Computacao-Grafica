#include "ponto.h"

/**
 * @brief Construtor da classe ponto no r2
 * 
 * @param x coordenada x
 * @param y coordenada y
 */
Ponto::Ponto(int x, int y)
:x(x+400),y(-y+400)
{

}

Ponto::Ponto()
{
    
}

int Ponto::xcart(){
    return (x-400);
}

int Ponto::ycart(){
    return (-y+400);
}


ostream & operator<< (ostream &out, const Ponto &p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

