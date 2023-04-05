#Importing module
import pygame  

#Initialize, (This initializes all the modules required for PyGame)
pygame.init()

#Creating variables 
WIDTH = 800
HEIGHT = 600
FPS = 60

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

#Functions:
def drawRect(color, pos, width, height):
    pygame.draw.rect(screen, color, (pos[0], pos[1], width, height), 4)  

def drawCircle(color, pos, RAD):
    pygame.draw.circle(screen, color, pos, RAD, 4)

def eraser(pos):
    pygame.draw.circle(screen, WHITE, pos, RAD)

finished = False

#to get white screen
screen.fill(WHITE)

drawing = False
color = pygame.Color('black')

#x and y coordinates for the rectangle
start_pos = 0
end_pos = 0

#Radius for the circle 
RAD = 30

shape = 0
# 0-rectangle
# 1-circle
# 2-eraser

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
                color=screen.get_at(pos)

        if event.type==pygame.MOUSEBUTTONUP:
            drawing = False
            end_pos=pos #getting the positiob of the mouse cursor 
            rect_x=abs(start_pos[0]-end_pos[0])         # center of the rectangle
            rect_y=abs(start_pos[1]-end_pos[1])
            circ_x=abs(start_pos[0]+rect_x//2)          # center of the circle 
            circ_y=abs(start_pos[1]+rect_y//2)
            if shape==0: #if the shape=0 we draw a rectangle
                drawRect(color, start_pos, rect_x, rect_y)
            if shape==1: #if the shape=1 we draw a circle 
                drawCircle(color, (circ_x, circ_y), rect_x//2)

        if event.type == pygame.MOUSEMOTION and drawing:
            if shape == 2: #if shape=2 we use eraser
                eraser(pos)
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                shape+=1 #if we type the buttom space, the value of shape will be increased by 1
                shape%=3 #and we will divide it by 3, it will count it from the begining 

    pygame.display.flip() #update the window