#If you do not know the number of arguments that will be passed into your function, there is a prefix you can add in the function definition, which prefix?:

def my_function(*kids):
    print("The youngest child is " + kids[2])

my_function("Ulpash", "Mereika", "Dori", "Sakonai")