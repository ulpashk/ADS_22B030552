#Write a Python program to find sequences of lowercase letters joined with a underscore.
import re
txt = input()
x = re.findall("[a-z]+_[a-z]+", txt)
print(x)