#Importing module
import pygame  

#Initialize, (This initializes all the modules required for PyGame)
pygame.init()

#Creating variables 
WIDTH = 800
HEIGHT = 600

#creating colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
PURPLE = (221,160,221)
YELLOW=(255, 255, 0)
BLUE2 = (0, 255, 255)

# This will launch a window of the desired size.
screen = pygame.display.set_mode((WIDTH, HEIGHT))

#Name of the window 
pygame.display.set_caption('PAINT')

#to make sure that the game is running at the specified frame rate.
clock = pygame.time.Clock()

img = pygame.transform.scale(pygame.image.load('paint.jpg'), (150, 150))  #putting the image of colors with new size
points = []
#Functions:
def drawRect(color, pos, width, height):
    pygame.draw.rect(screen, color, (pos[0], pos[1], width, height), 4)

def drawPolygon(color, points):
    pygame.draw.polygon(screen, color, points, 4)  

def drawCircle(color, pos, RAD):
    pygame.draw.circle(screen, color, pos, RAD, 4)

# def drawtriangle(color, pos):
#     pygame.draw.polygon(screen, color, pos, 4)

def eraser(pos):
    pygame.draw.circle(screen, WHITE, pos, RAD)


finished = False

#to get white screen
screen.fill(WHITE)

drawing = False

#default color
color = pygame.Color('black')

#beginning and end points
start_pos = 0
end_pos = 0

RAD = 30

shape = 0
# 0-rectangle
# 1-circle
# 2-square
# 3-romb ?
# 4-right triangle
# 5-equilateral triangle ?
# 6-eraser


while not finished:
    clock.tick(60)

    #getting the mouse cursors position
    pos = pygame.mouse.get_pos()

    screen.blit(img, (10, 10)) 

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
            pygame.quit()

        if event.type == pygame.MOUSEBUTTONDOWN:
            drawing = True
            start_pos = pos #getting the position of the mouse cursor
            if pos[0]>10 and pos[0]<160 and pos[1]>10 and pos[1]<160:
                color = screen.get_at(pos)

        if event.type==pygame.MOUSEBUTTONUP:
            drawing = False
            end_pos = pos #getting the position of the mouse cursor 

            #coordinates for a rectangle
            rect_x=abs(start_pos[0]-end_pos[0])         # width of the rectangle
            rect_y=abs(start_pos[1]-end_pos[1])         # height of the rectangle

            #coordinates for a circle
            circ_x=abs(start_pos[0]+rect_x//2)          # center of the circle 
            circ_y=abs(start_pos[1]+rect_y//2)

            #coordinates for a right triangle (beginning and end points)
            tr1 = (start_pos[0], start_pos[1])
            tr2 = (end_pos[0], end_pos[1])
            tr3 = (start_pos[0], start_pos[1]+rect_y)

            #coordinates for rombus 
            a = ((start_pos[0]+rect_x//2), start_pos[1])
            b = ((start_pos[0]+rect_x), (start_pos[1]+rect_y//2))
            c = ((end_pos[0]-rect_x//2), end_pos[1])
            d = (start_pos[0], (start_pos[1]+rect_y//2))

            #coordinates for equilateral triangle
            etr_a = (start_pos[0], start_pos[1]+rect_x)
            etr_b = (start_pos[0]+rect_x, start_pos[1]+rect_x)
            etr_c = (start_pos[0]+rect_x//2, start_pos[1])

            if shape == 0: #if the shape=0 we draw a rectangle
                drawRect(color, start_pos, rect_x, rect_y)
            if shape == 1: #if the shape=1 we draw a circle 
                drawCircle(color, (circ_x, circ_y), rect_x//2)
            if shape == 2: #if the shape=2 we draw a square
                drawRect(color, start_pos, rect_x, rect_x)
            if shape == 3:  #if the shape=3 we draw a rombus
                points = [a, b, c, d]
                drawPolygon(color, points)
            if shape == 4:  #if the shape=4 we draw a right triangle
                points = [tr1, tr2, tr3]
                drawPolygon(color, points)
            if shape == 5:  #if the shape=5 we draw an equilateral triangle
                points = [etr_a, etr_b, etr_c]
                drawPolygon(color, points)

        if event.type == pygame.MOUSEMOTION and drawing:
            if shape == 6: #if shape=6 we use an eraser
                eraser(pos)
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                shape+=1 #if we type the buttom space, the value of shape will be increased by 1
                shape%=7 #and we will divide it by 7, it will count it from the begining 

    pygame.display.flip() #update the window