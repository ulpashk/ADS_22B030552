#Write a Python program to convert a given camel case string to snake case.
import re 
 
def func(txt): 
    return txt.group("g1")+ "_" + txt.group("g2").lower() 
 
txt = "mySuperVar"
pattern = "(?P<g1>[a-z])(?P<g2>[A-Z])+" 
 
print(re.sub(pattern, func, txt))