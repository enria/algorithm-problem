from math import gcd


class Rational:
    def __init__(self, _a=0, _b=1):
        self.a, self.b = _a, _b

    def __add__(self, other):
        result = Rational()
        lcm = other.b*self.b//gcd(other.b, self.b)
        result.b = lcm
        result.a = self.a*lcm//self.b+other.a*lcm//other.b
        return result

    def __sub__(self, other):
        result = Rational()
        lcm = other.b*self.b//gcd(other.b, self.b)
        result.b = lcm
        result.a = self.a*lcm//self.b-other.a*lcm//other.b
        return result

    def __mul__(self, other):
        result = Rational()
        result.b = self.b*other.b
        result.a = self.a*other.a
        return result

    def __truediv__(self, other):
        result = Rational()
        if other.a == 0:
            result.b = 0
            return result
        sg=1
        if other.a < 0:
            sg=-1
        result.a = self.a*other.b*sg
        result.b = self.b*other.a*sg
        return result

    def __str__(self):
        result = ""
        s = ""
        a = self.a
        b = self.b
        if b == 0:
            result = "Inf"
            return result
        if a < 0:
            s, a = "-", abs(a)
        result = s
        inte = a//b
        a = a % b
        fragcd = gcd(a, b)
        if a == 0:
            result += str(inte)
        elif inte == 0:
            result += "{}/{}".format(a//fragcd, b//fragcd)
        else:
            result += "{} {}/{}".format(inte, a//fragcd, b//fragcd)
        if s == "-":
            result = "("+result+")"
        return result


raw = input()
raw = raw.split()
n1 = Rational(int(raw[0].split("/")[0]), int(raw[0].split("/")[1]))
n2 = Rational(int(raw[1].split("/")[0]), int(raw[1].split("/")[1]))

print("{} + {} = {}".format(n1, n2, n1+n2))
print("{} - {} = {}".format(n1, n2, n1-n2))
print("{} * {} = {}".format(n1, n2, n1*n2))
print("{} / {} = {}".format(n1, n2, n1/n2))
