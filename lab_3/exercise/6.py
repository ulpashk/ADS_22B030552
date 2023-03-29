#If you do not know the number of keyword arguments that will be passed into your function, there is a prefix you can add in the function definition, which prefix?:

def my_function(**kid):
    print("Her last name is " + kid["lname"])

my_function(fname = "Ulpash", lname = "Kuanyshbek")