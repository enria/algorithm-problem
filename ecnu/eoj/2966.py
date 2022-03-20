n=int(input())

for i in range(n):
    c=int(input())
    print(f"case #{i}:\n{bin(c)[2:]} {hex(c)[2:].upper()}")
