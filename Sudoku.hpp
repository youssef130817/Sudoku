#ifndef SUDOKU
#define SUDOKU
#include <iostream>

using namespace std;

class Sudoku{
public:
    int table[9][9];

    bool estPossible(int x,int y,int val) const;
    Sudoku();
    Sudoku(const std::string& nomFichier);
    void Afficher() const;
    int indiceBlock(int indice) const;
    bool Resoudre();
    bool trouverCaseVide(int& row, int& col) const;
    bool estResolu() const;
};
#endif