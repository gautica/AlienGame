#ifndef TILE_H
#define TILE_H

class Tile {
private:
    char Sym;
public:
    Tile() : Sym(' ') {}
    Tile(char sym) : Sym(sym) {}
    char getSym();
    void setSym(char sym);
};
#endif
