def game(mGame,x):#função principal, onde todas as outea funções são chamadas
    st = True
    jogo = step(mGame,x)
    x = jogo[1]
    stt = status(mGame,x,st)
    time(x)
    if jogo[2] == True:#nesse if verificamos a partir das funções chamadas a cima o que acontecerá com o jogo.
        if stt[2] == 2:
            print("PLAYER 2 WON")
            print("Status:",stt[2])
        elif stt[2] == 1:
            print("PLAYER 1 WON")
            print("Status:",stt[2])
        elif stt[2] == 0:
            print("Empate")
            print("Status:",stt[2])
        else:
            print("Status:",stt[2])
            game(mGame,x)
    else:
        print("Posição inválida")
        game(mGame,x)
def time(x):
    if x%2 == 0:
        print("Player 1 playing")
    else:
        print("Player 2 playing")
def initialize():#Função onde tudo iniciar e são declaradas variáveis e a matriz.
    x = 0#essa variável serve para identificar de quem é a vez de jogar, jogador X ou O.
    time(x)
    mGame = [[" "," "," "],[" "," "," "],[" "," "," "]]#Matriz declarada
    printMat(mGame)
    game(mGame,x)
def printMat(mGame):#Função que executa o print da matriz.
    tabuleiro = '''
   0   1   2 
0| {} | {} | {} |
1| {} | {} | {} |
2| {} | {} | {} |
'''
    print(tabuleiro.format(mGame[0][0],mGame[0][1],mGame[0][2],mGame[1][0],mGame[1][1],mGame[1][2],mGame[2][0],mGame[2][1],mGame[2][2]))#print do tabuleiro.
def step(mGame,x):#variável x serve para identificar de que jogador é a vez.
    lin = int(input("Linha:"))
    colun = int(input("Coluna:"))
    if x%2 == 0:
        codJogador = "X"
    elif x%2 != 0:
        codJogador = "O"
    if mGame[lin][colun] == " ":
        mGame[lin][colun] = codJogador
        x = x + 1#a cada repetição é somado 1, se o valor for divisível por 2, o jogado X joga caso contrário o O.
        return mGame,x,True
    else:
        return mGame,x,False
def status(mGame,x,st):#Função status verifica a situação do jogo.
        vdd = False
        printMat(mGame)
        for h in range(2):
            if h == 0:
                cod = "X"
            else:
                cod = "O"
            for z in range(3):
                if mGame[z][0] == cod and mGame[z][1] == cod and mGame[z][2] == cod:
                    vdd = True
            for z in range(3):
                if mGame[0][z] == cod and mGame[1][z] == cod and mGame[2][z] == cod:
                    vdd = True
            if mGame[0][0] == cod and mGame[1][1] == cod and mGame[2][2] == cod:
                vdd = True
            elif mGame[0][2] == cod and mGame[1][1] == cod and mGame[2][0] == cod:
                vdd = True
            if vdd == True:
                if cod == "X":
                    return mGame,x,2
                else:
                    return mGame,x,1
        if x != 9:
            return mGame,x,-1
        return mGame,x,0
initialize()
