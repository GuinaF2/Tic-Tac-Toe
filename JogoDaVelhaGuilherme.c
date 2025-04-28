#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#define SIZE 3
#define JOGADORX 'X'
#define JOGADORO 'O'

void DefineTabela(char **tab, bool *ptplayer, FILE *arquivo, char *usuario1, char *usuario2)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tab[i][j] = '_';
        }
        printf("\n");
    }
    *ptplayer = true;
    PlayerJogada(tab, ptplayer, arquivo, usuario1, usuario2);
}

bool checaVitoria(char **tab, int pos, bool *playerAtual)
{
    bool jogoContinua = true;
    // VERIFICA CADA LINHA DA TABELA
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if ((tab[i][j]) && (tab[i][j + 1]) && (tab[i][j + 2]) != '_')
            {
                if ((tab[i][j]) == (tab[i][j + 1]) && (tab[i][j + 2]) == (tab[i][j]))
                {
                    return !jogoContinua;
                }
            }
        }
    }
    // VERIFICA CADA COLUNA DA TABELA
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 1; i++)
        {
            if ((tab[i][j]) && (tab[i + 1][j]) && (tab[i + 2][j]) != '_')
            {
                if ((tab[i][j]) == (tab[i + 1][j]) && (tab[i + 2][j]) == (tab[i][j]))
                {
                    return !jogoContinua;
                }
            }
        }
    }
    // VERIFICA DIAGONAIS DA TABELA

    if ((tab[0][0]) && (tab[1][1]) && (tab[2][2]) != '_')
    {

        if ((tab[0][0]) == (tab[1][1]) && (tab[2][2]) == (tab[0][0]))
        {
            return !jogoContinua;
        }
    }
    if ((tab[0][2]) && (tab[1][1]) && (tab[2][0]) != '_')
    {

        if ((tab[0][2]) == (tab[1][1]) && (tab[2][0]) == (tab[0][2]))
        {
            return !jogoContinua;
        }
    }
    *playerAtual = !*playerAtual;
    return jogoContinua;
}

void checaPlayer(char **tab, int pos, bool *player1Agora, int linha, int coluna)
{
    if (*player1Agora)
    {
        tab[linha][pos - coluna] = JOGADORX;
    }
    else
    {
        tab[linha][pos - coluna] = JOGADORO;
    }
}

void PlayerJogada(char **tab, bool *ptPlayerAtual, FILE *arquivo, char *usuario1, char *usuario2)
{
    int jogadas = 0;
    char op;
    int posicao;
    bool gameContinua = true;
    // Inicializa no player 1
    while (gameContinua)
    {
        if (!*ptPlayerAtual)
        {
            printf("Insira a letra %c em uma posicao\n", JOGADORO);
        }
        else
        {
            printf("Insira a letra %c em uma posicao\n", JOGADORX);
        }
        scanf("%d", &posicao);
        fflush(stdin);
        if (!(posicao >= 1 && posicao <= 9))
        {
            printf("Numero Indisponivel para preenchimento\n");
            continue;
        }

        if (posicao >= 1 && posicao <= 3)
        {
            if (tab[0][posicao - 1] != '_')
            {
                printf("Numero Indisponivel para preenchimento\n");
                continue;
            }
            checaPlayer(tab, posicao, ptPlayerAtual, 0, 1);
        }

        if (posicao >= 4 && posicao <= 6)
        {
            if (tab[1][posicao - 4] != '_')
            {
                printf("Numero Indisponivel para preenchimento\n");
                continue;
            }
            checaPlayer(tab, posicao, ptPlayerAtual, 1, 4);
        }

        if (posicao >= 7 && posicao <= 9)
        {
            if (tab[2][posicao - 7] != '_')
            {
                printf("Numero Indisponivel para preenchimento\n");
                continue;
            }
            checaPlayer(tab, posicao, ptPlayerAtual, 2, 7);
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                printf("%c ", tab[i][j]);
            }
            printf("\n");
        }
        jogadas++;
        if (!checaVitoria(tab, posicao, ptPlayerAtual))
        {
            printf("\nParabens %s, voce venceu!\n", *ptPlayerAtual ? usuario1 : usuario2);
            atualizarEstatisticas(*ptPlayerAtual ? usuario1 : usuario2, "vitoria");
            atualizarEstatisticas(*ptPlayerAtual ? usuario2 : usuario1, "derrota");
            gameContinua=false;
            break;
        }
        if (jogadas == 9 && gameContinua==true)
        {
            printf("\nEmpate!\n");
            atualizarEstatisticas(usuario1, "empate");
            atualizarEstatisticas(usuario2, "empate");
            gameContinua=false;
            break;
        }
    }
    while (1)
    {
        printf("Escolha como prosseguir\n");
        printf("1.Menu\n");
        printf("2.Sair\n");
        printf("Insira uma opcao\n");
        scanf("%c", &op);
        fflush(stdin);
        switch (op)
        {
        case '1':
            ExibirMenu(tab, ptPlayerAtual, arquivo, usuario1, usuario2);
            break;
        case '2':
            exit(0);
            break;
        default:
            printf("Insira um numero valido\n");
            break;
        }
    }
}
void ExibirMenu(char **tab, bool *ptPlayer, FILE *arquivo, char *usuario1, char *usuario2)
{   
    
    char op;
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        printf(" -* ");
    }
    printf("\n\n");
    printf("    |   ___    ___    ___\n");
    printf("    |  |  |   |  _   |  |   \n");
    printf("  \\_|  |__|   \\__|   |__|   \n");
    printf("      ___                       \n");
    printf("      |  \\    /\\ \n");
    printf("      |   \\  /__\\ \n");
    printf("      |___/ /    \\ \n\n");
    printf("  \\     / _____   |    |     |     _  \n");
    printf("   \\   /  |____   |    |_____|    /_\\  \n");
    printf("    \\_/   |____   |___ |     |   /   \\ \n\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf(" -* ");
    }
    printf("\n");
    while (1)
    {
        printf("1.Iniciar Jogo\n\n");
        printf("2.Ultimos Ganhadores\n\n");
        printf("3.Sair\n\n\n");
        printf("Made By Guilherme Henrique\n\n");
        printf("Insira uma opcao\n");
        scanf("%c", &op);
        fflush(stdin);
        switch (op)
        {
        case '1':
            DefineTabela(tab, ptPlayer, arquivo, usuario1, usuario2);
            break;
        case '2':
            listarGanhadores(arquivo);
            break;
        case '3':
            exit(0);
            break;
        default:
            printf("Insira um numero valido\n");
            continue;
        }
    }
}

void atualizarEstatisticas(char *usuario, char *resultado) {
    if(strcmp(usuario, "Convidado_X") == 0 || strcmp(usuario, "Convidado_O") == 0) {
        return;
    }

    FILE *arquivo = fopen("jogodaVelha.txt", "r");
    if(!arquivo) {
        printf("Erro ao abrir arquivo de estatisticas.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if(!temp) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arquivo);
        return;
    }

    char linha[100];
    char nome[11], senha[6];
    int partidas, vitorias, empates, derrotas;
    bool encontrado = false;

    while(fgets(linha, sizeof(linha), arquivo)) {
        if(strstr(linha, "Nome:") != NULL) {
            sscanf(linha, "Nome: %10s", nome);
            
            fprintf(temp, "%s", linha);
            
            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Senha: %5s", senha);
            fprintf(temp, "Senha: %s\n", senha);
            
            fgets(linha, sizeof(linha), arquivo);
            if(strcmp(nome, usuario) == 0) {
                encontrado = true;
                sscanf(linha, "%10[^,],%d,%d,%d,%d", nome, &partidas, &vitorias, &empates, &derrotas);
                
                partidas++;
                if(strcmp(resultado, "vitoria") == 0) vitorias++;
                else if(strcmp(resultado, "empate") == 0) empates++;
                else if(strcmp(resultado, "derrota") == 0) derrotas++;
                
                fprintf(temp, "%s,%d,%d,%d,%d\n", nome, partidas, vitorias, empates, derrotas);
            } else {
                fprintf(temp, "%s", linha);
            }
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("jogodaVelha.txt");
    rename("temp.txt", "jogodaVelha.txt");

    if(!encontrado) {
        printf("Usuario %s nao encontrado para atualizacao de estatisticas.\n", usuario);
    }
}
void listarGanhadores(FILE *arquivo)
{
    system("cls");
    char nome[11], senha[6], linha[100];
    int partidas, vitorias, empates, derrotas;
    
    arquivo = fopen("jogodaVelha.txt", "r");
    if (!arquivo)
    {
        printf("Nenhuma estatistica encontrada.\n");
        return;
    }
    
    printf("\nEstatisticas dos Jogadores\n");
    printf("--------------------------\n");
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (sscanf(linha, "%10[^,],%d,%d,%d,%d", nome, &partidas, &vitorias, &empates, &derrotas) == 5)
        {
            printf("Nome: %-10s,Partidas: %d,Vitorias: %d,Empates: %d,Derrotas: %d\n",
                   nome, partidas, vitorias, empates, derrotas);
        }
        else if (strstr(linha, "Nome:") || strstr(linha, "Senha:"))
        {
            continue;
        }
    }
    fclose(arquivo);
    printf("\nPressione qualquer tecla para voltar...");
    getch();
    fflush(stdin);
    system("cls");
}
void realizarCadastro(FILE *arquivo)
{
    system("cls");
    char nomeUser[11], senhaUser[6];
    char nomeExistente[11];
    bool existente = false;

    printf("Insira o Nome de Usuario (max 10 caracteres): ");
    scanf("%10s", nomeUser);
    fflush(stdin);

    printf("Insira uma Senha (max 5 caracteres): ");
    scanf("%5s", senhaUser);
    fflush(stdin);

    FILE *verifica = fopen("C:\\Users\\Guina\\Desktop\\jogodaVelha.txt", "r");
    if (verifica)
    {
        while (fscanf(verifica, "Nome: %10s\n", nomeExistente) == 1)
        {
           
            while (fgetc(verifica) != '\n' && !feof(verifica));
            while (fgetc(verifica) != '\n' && !feof(verifica)); 

            if (strcmp(nomeUser, nomeExistente) == 0)
            {
                existente = true;
                break;
            }
        }
        fclose(verifica);
    }

    if (existente)
    {
        printf("Usuario ja existe.\n");
        return;
    }

    arquivo = fopen("jogodaVelha.txt", "a");
    if (!arquivo)
    {
        printf("Erro ao abrir arquivo para cadastro.\n");
        return;
    }

    fprintf(arquivo, "Nome: %s\nSenha: %s\n%s,0,0,0,0\n", nomeUser, senhaUser, nomeUser);
    fclose(arquivo);
    printf("Cadastro realizado com sucesso!\n");
}

bool realizarLogin(FILE *arquivo, char *user)
{
    system("cls");
    char nomeUser[11], senhaUser[6];
    char nomeArquivo[11], senhaArquivo[6];
    int i = 0;
    char ch;

    printf("Insira o Nome de Usuario: ");
    scanf("%10s", nomeUser);
    fflush(stdin);

    printf("Insira a Senha: ");
    while (1)
    {
        ch = getch();
        if (ch == 13) 
            break;
        else if (ch == 8 && i > 0) 
        {
            i--;
            printf("\b \b");
        }
        else if (ch >= 32 && ch <= 126 && i < 5)
        {
            senhaUser[i++] = ch;
            printf("*");
        }
    }
    senhaUser[i] = '\0';
    printf("\n");

    arquivo = fopen("jogodaVelha.txt", "r");
    if (!arquivo)
    {
        printf("Erro ao abrir arquivo.\n");
        return false;
    }

    while (fscanf(arquivo, "Nome: %10s\nSenha: %5s\n", nomeArquivo, senhaArquivo) == 2)
    {
        while (fgetc(arquivo) != '\n' && !feof(arquivo));
        if (strcmp(nomeUser, nomeArquivo) == 0 && strcmp(senhaUser, senhaArquivo) == 0)
        {
            strcpy(user, nomeUser);
            fclose(arquivo);
            return true;
        }
    }

    fclose(arquivo);
    printf("Usuario ou senha incorretos.\n");
    return false;
}

int main()
{
    char *usuario1 = malloc(11 * sizeof(char));
    char *usuario2 = malloc(11 * sizeof(char));
    char **tab = malloc(SIZE * sizeof(char *));
    for (int i = 0; i < SIZE; i++)
        tab[i] = malloc(SIZE * sizeof(char));

    bool player1Atual = true;
    bool *ptPlayerAtual = &player1Atual;

    FILE *arquivo = NULL;

    char op;
    while (1)
    {
        printf("1. Realizar Cadastro\n2. Realizar Login\n3. Jogar sem Login\n4. Sair\nOpcao: ");
        scanf(" %c", &op);
        fflush(stdin);
        switch (op)
        {
        case '1':
            realizarCadastro(arquivo);
            break;
        case '2':
            printf("Login do Jogador X:\n");
            if (!realizarLogin(arquivo, usuario1))
            {
                printf("Login do Jogador X falhou.\n");
                break;
            }

            printf("Login do Jogador O:\n");
            if (!realizarLogin(arquivo, usuario2))
            {
                printf("Login do Jogador O falhou.\n");
                break;
            }
            ExibirMenu(tab, ptPlayerAtual, arquivo, usuario1, usuario2);
            break;
        case '3':
            strcpy(usuario1, "Jogador_X");
            strcpy(usuario2, "Jogador_O");
            ExibirMenu(tab, ptPlayerAtual, arquivo, usuario1, usuario2);
            break;
        case '4':
            exit(0);
        default:
            printf("Opcao invalida.\n");
        }
    }

    for (int i = 0; i < SIZE; i++)
        free(tab[i]);
    free(tab);
    free(usuario1);
    free(usuario2);
    return 0;
}