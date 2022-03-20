while True:
    try:
        n=int(input())
        p=int(input())
        print(round(p**(1/n)))
    except EOFError:
        break