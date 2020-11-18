#!/bin/python3
from random import randint
player=input('sissors(r)\tstone(s)\tpaper(p):')
print('player has chosen '+str(player))
rand = randint(1,3) #generates random integers from the range
if rand==1:
  computer='r'
elif rand==2:
  computer='s'
elif rand==3:
  computer='p'
if computer==player:
  print(player+' vs '+player+"--> Its a Draw!" )
elif player=='r' and computer=='p':
  print(player+' vs '+computer+"--> Player Wins!")
elif player=='s' and computer=='r':
  print(player+' vs '+computer+"--> Player Wins!")
elif player=='p' and computer=='s':
  print(player+' vs '+computer+"--> Player Wins!")
else :
  print(player+' vs '+computer+"--> Computer Wins!")
