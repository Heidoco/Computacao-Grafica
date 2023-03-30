#pragma once
#include<SDL2/SDL.h>
#include <iostream>
using namespace std;
class Ponto
{
    public:
        int x;
        int y;
        Ponto(int x,int y);
        Ponto();
        int xcart();
        int ycart();
};

ostream & operator<<(ostream &out, const Ponto &p);