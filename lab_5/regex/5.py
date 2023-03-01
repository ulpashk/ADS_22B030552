import re
txt = input()
x = re.search("a{1}.*b$", txt)

print("The beginning and end points of the sequence are:", x.span())