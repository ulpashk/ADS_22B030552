import pygame 
import time

clock = pygame.time.Clock()
 
pygame.init() 
width = 500
height = 500
screen = pygame.display.set_mode((width, height))
done = False
x = 50
y = 50

screen.fill((255, 255, 255))

while not done:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True
                
        pressed = pygame.key.get_pressed()
        if pressed[pygame.K_UP] and y > 20: y -= 20
        if pressed[pygame.K_DOWN] and y < height-20: y += 20
        if pressed[pygame.K_LEFT] and x > 20: x -= 20
        if pressed[pygame.K_RIGHT] and x < width-20: x += 20

        screen.fill((255, 255, 255))
    
        pygame.draw.circle(screen, (255, 0, 0), (x, y), 25)
        
        pygame.display.flip()
        clock.tick(60)
        # time.sleep(1/60)