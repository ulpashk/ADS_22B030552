#Write a Python program to split a string at uppercase letters.
import re
txt = input()
x = re.split("[A-Z]", txt)
print(x)