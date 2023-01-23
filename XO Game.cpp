#include <iostream>
using namespace std;

class XO_Game
{
private:
    char tab[9] ; 
    char current_turn;                                    
    bool playing ;                                       
    int state ;                                              
    int input;                                                   

public:
	XO_Game();
	void start(); 
    void affiche_tab();   
    int play_move(int index, char move); 
    int check_win(char move);                           
};

int main()
{
    XO_Game game;
    game.start();
    return 0;
}

XO_Game::XO_Game():tab {'0','1', '2', '3', '4', '5', '6', '7', '8'}
	{
	current_turn = 'X';                                   
    playing = true;                                         
     state = 0;  
	}

void XO_Game ::start()
{
    while (playing == true)
    {
        affiche_tab(); //affichage du tableau
        cout << "Play your move " << current_turn << endl;
        cin >> input;        // introduire l'indice de la case par le joueur
        if (play_move(input, current_turn) == 0) // verifier si la case est occupée
        {
            cout << "Box already occupied" << endl;
            continue;
        };
        state = check_win(current_turn); // verifier l'etat du jeu (si quelqu'un a gagné ou pas)
        if (state == 1)    // l'un des joueur a gagné
        {
            affiche_tab();
            cout << current_turn << " wins the game!" << endl; // afficher le gagnant
            playing=false;
        }
        else if (state == 2) // égalité entre les 2 joueurs
        {
            cout << "Draw!" << endl;
            playing=false;
        };
        current_turn = (current_turn == 'X') ? 'O' : 'X'; // changer le joueur actuel
    };
};

void XO_Game ::affiche_tab()
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 5 || i == 7 || i == 8)
        {
            cout << " | "; // ajouter "|" entre les champs du tableau
        }
        cout << tab[i]; // ajouter les numeros de 0..8 entre les "|"
        if (i == 2 || i == 5)
        {
            cout << endl;
            cout << "---------" << endl; //retour a la ligne pour separer les ligne par des tirets interrompus
        }
    }
    cout << endl;
};

int XO_Game ::play_move(int index, char move)
{
    if (index >= 0 && index < 9) // si l'indice est valable
    {
        if ((tab[index] != 'X') && (tab[index] !='O')) // test l'occupation du case
        {
            tab[index] = move; // si la case n'est pas occupée , la remplir par 'X' ou 'O'
            return 1;
        }
    }
    else return 0;
};

int XO_Game ::check_win(char move)
{
    if (
        // verifier horizontalement les lignes
        (tab[0] == move && tab[1] == move && tab[2] == move) ||
        (tab[3] == move && tab[4] == move && tab[5] == move) ||
        (tab[6] == move && tab[7] == move && tab[8] == move) ||
        // verifier verticalement les lignes
        (tab[0] == move && tab[3] == move && tab[6] == move) ||
        (tab[1] == move && tab[4] == move && tab[7] == move) ||
        (tab[2] == move && tab[5] == move && tab[8] == move) ||
        // verifier les diagonales
        (tab[0] == move && tab[4] == move && tab[8] == move) ||
        (tab[2] == move && tab[4] == move && tab[6] == move))
    {
        return 1;
    }
    else //verifier l'egalité entre les joueurs
    {
        bool draw = true; // variable qui teste l'egalité ente les 2 joueurs
        for (int i = 0; i < 9; i++)
        {
            if (tab[i] !='X' && tab[i]!='O')
            {
                draw = false; // pas d'egalité entre les 2 joueurs
                break;
            }
        }
        if (draw == true) // egalité entre les 2 joueurs
        {
            return 2;
        }
    }
    return 0;
};

