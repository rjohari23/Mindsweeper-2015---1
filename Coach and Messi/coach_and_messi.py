"""If you know python then, this problem becomes a cakewalk for you.
You just have to take input print answer using pow() of python where third argument of pow() is modulo."""

"""created by : rjohari23"""

t = int(raw_input())
while t:
  x,y = map(int,raw_input().split())
  print pow(x,y,1000000007)
  t -= 1