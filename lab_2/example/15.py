#Logical Operators:
#and : returns True if both statements are true
x = 5
print(x > 3 and x < 10) #True
print(x == 6 and x > 3) #False

#or: returns True if one of the statements is true
x = 5
print(x < 5 or x > 4) #True
print(x < 3 or x > 15) #False

#not: reverse the result, returns False if the result is true
x = 5 
print(not(x < 6 and x > 4)) #True-> False
print(not(x > 6 and x < 10)) #False-> True