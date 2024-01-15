#include <iostream>
#include "Sudoku.hpp"
int main() {
    Sudoku *s=new Sudoku("Sudoku3.txt");

    s->Afficher();
    s->Resoudre();
    s->estResolu();
    s->Afficher();
    return 0;
}
