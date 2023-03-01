def snake_to_camel(snake):
    comp = snake.split('_')
    return comp[0] + ''.join(x.title() for x in comp[1:])

# example 
snake = "snake_case_string"
camel = snake_to_camel(snake)
print(camel)