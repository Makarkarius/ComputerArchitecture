import random
import string
from random import randint

def randInt(left, right):
    return randint(left, right)

def randName():
    letters = string.ascii_letters
    return (''.join(random.choice(letters) for i in range(20)))