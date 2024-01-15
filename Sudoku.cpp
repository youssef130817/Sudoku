#include "Sudoku.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int Sudoku::indiceBlock(int indice) const {
    return  3 * (indice / 3);
}
bool Sudoku::estPossible(int x, int y, int val) const {
    if (val == 0)
        return true;

    for (int i = 0; i < 9; i++)
        if (table[x][i] == val && i!=y)
            return false;

    for (int i = 0; i < 9; i++)
        if (table[i][y] == val && i!=x)
            return false;

    for (int i = indiceBlock(x); i < indiceBlock(x) + 3; i++)
        for (int j = indiceBlock(y); j < indiceBlock(y) + 3; j++)
            if (table[i][j] == val && i!=x && j!=y)
                return false;

    return true;
}

Sudoku::Sudoku()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int val = rand() % 9 + 1;
                table[i][j] = 0;
        }
    }
}

Sudoku::Sudoku(const string& nomFichier) {
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        return;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!(fichier >> table[i][j])) {
                cout << "Erreur lors de la lecture du fichier." << endl;
                return;
            }
        }
    }
    fichier.close();
}
bool Sudoku::Resoudre() {
    int i, j;

    if (!trouverCaseVide(i, j))
        return true;

    for (int num = 1; num <= 9; ++num) {
        if (estPossible(i, j, num)) {
            table[i][j] = num;
            if (Resoudre())
                return true;
            table[i][j] = 0;
        }
    }

    return false;
}

bool Sudoku::trouverCaseVide(int& row, int& col) const {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (table[row][col] == 0)
                return true;
        }
    }
    return false;
}


bool Sudoku::estResolu() const{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!estPossible(i, j, table[i][j]) || table[i][j]==0)
            {
                cout <<"Sudoku n'est pas resolu !!"<<endl;
                return false;
            }
        }

    }

    cout <<"Sudoku est resolu !!"<<endl;
    return true;
}
void Sudoku::Afficher() const {
    int k=0,m=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++) {
                cout << table[i][j]<<"  ";
                m++;
                if(m==3)
                {
                    cout<<"    ";
                    m=0;
                }
        }
        cout<<endl;
        k++;
        if(k==3)
        {
            cout<<endl;
            k=0;
        }
    }
}

