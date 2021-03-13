def main():
    import sys
    n = int(input("Digite o número decimal que deseja converter para binário: "))
    b = int(input("Digite a quantidade de bits que o número deverá ter: "))
    n1 = n
    num = []
    c = convert(n,b,n1,num)
    p = prt(c)
    print(p)
    print("\n")
    sair = str(input("Caso queira sair digite 1 ou ENTER se quiser continuar."))
    print("\n")
    if sair == "1":
        sys.exit()
    main()
def convert(n,b,n1,num):
    if b != 0:
        n1 = n
        n1 = n%2
        num.append(n1)
        b = b - 1
        n = n //2
        if b == 0:
            if n != 0:
                return "over"
            else:
                return num
        return convert(n,b,n1,num)
def prt(c):
    a = ""
    if c == "over":
        a = "Overflow"
    else:
        for x in range (len(c)-1,-1,-1):
            a = a + str(c[x])
    return a
main()

