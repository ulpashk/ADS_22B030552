#Write a Python program that matches a string that has an 'a' followed by two to three 'b'.
import re

txt = input()
x = re.findall("ab{2,3}", txt)
print(x)