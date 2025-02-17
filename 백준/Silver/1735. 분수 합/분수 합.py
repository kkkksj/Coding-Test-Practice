def get_gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

up1, bottom1 = map(int, input().split())
up2, bottom2 = map(int, input().split())

up = bottom2*up1 + bottom1*up2
bottom = bottom1*bottom2

gcd = get_gcd(up, bottom)

print(int(up/gcd), int(bottom/gcd))