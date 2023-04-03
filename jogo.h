# ifndef jogo_h
# define jogo_h

typedef struct jogo Tabuleiro;

struct jogo{
    char **tabuleiro;
};

void LeituraTabuleiro(Tabuleiro jogo);

Tabuleiro AlocarTabuleiro(Tabuleiro jogo);

int TabuleiroEhValido(Tabuleiro jogo);

int Venceu(Tabuleiro jogo);

int Empate(Tabuleiro jogo);

void JogadaMestre(Tabuleiro jogo, int *cont);

void JogoDesalocar(Tabuleiro jogo);

# endif 
