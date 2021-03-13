def main():
    esc=-1
    while(esc!=0):
        n = int(input("Digite o número decimal que deseja converter para binário: "))
        b = int(input("Digite a quantidade de bits que o número deverá ter: "))
        n1 = n
        num = []
        c = convert(n,b,n1,num)
        prt(c)
        print("\n1. To continue \n0. To stop")
        esc=int(input())
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
    if c == "over":
        print("Overflow")
    else:
        for x in range (len(c)-1,-1,-1):
            print(c[x],end='')
main()

