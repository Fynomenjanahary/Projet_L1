# import py5
# import random

# pos_y = 300
# speed = 5

# def setup():
#     py5.size(800,600)
#     py5.background(207)

# def key_pressed():
#     global pos_y,speed
#     if py5.key == " ":
#         speed = -5

# def key_released():
#     global pos_y
#     global speed
#     if py5.key == " ":
#         speed = 5

# def draw():
#     global pos_y,speed

#     py5.background(207)
#     py5.fill(252, 110, 204)
#     py5.ellipse(80 , pos_y , 45 ,45)
#     pos_y += speed
    

# py5.run_sketch()


import py5
import random
import math

pos_y = 300
speed = 15
img = 0
bird = 0
tuyau_x = []
up_width = []
up_height = []
down_height = []
down_width = []
distance = []
score = 0

def setup():
    global img,bird
    py5.size(800, 600)
    img = py5.load_image("bg_flappy.jpeg")
    bird = py5.load_image("bird.png")
    coordonne()

def chagement(i):
    global up_height,up_width,down_height,down_width,distance,tuyau_x
    up_height[i]=(random.randint(0,400))
    down_height[i]=(up_height[i] + 100)
    up_width[i]=(random.randint(50 , 100))
    down_width[i]=(random.randint(50 , 100))
    distance[i]=(350)
    tuyau_x[i]=(py5.width)

def coordonne():
    global up_height,up_width,down_height,down_width,distance,tuyau_x
    for i in range (3):
        up_height.append(random.randint(0,400))
        down_height.append(up_height[i] + 100)
        up_width.append(random.randint(50 , 100))
        down_width.append(random.randint(50 , 100))
        distance.append(350 * i)
        tuyau_x.append(py5.width + distance[i])

def key_pressed():
    global pos_y,speed
    if py5.key == " ":
        speed = -10  

def key_released():
    global pos_y
    global speed
    if py5.key == " ":
        speed = 6

def printf():
    global up_height,up_width,down_height,down_width,distance,tuyau_x
    for i in range (3):
        py5.stroke(000)
        py5.stroke_weight(5)
        if i == 0:
            py5.fill(255, 149, 207)

        elif i==1:
              py5.fill(0, 0, 0)

        else :
            py5.fill(255, 255, 255)
        py5.rect( tuyau_x[i], 0 , up_width[i] , up_height[i] , 0 , 0 , 10 , 10)
        py5.rect(tuyau_x[i] , up_height[i]+150 , down_width[i] , py5.height-(up_height[i]+150) , 10 , 10 , 0 , 0)

def draw():
    global up_height,up_width,down_height,down_width,distance,tuyau_x,bird,pos_y,speed,score

    py5.image(img, 0, 0, py5.width, py5.height)
    py5.image(bird,80 , pos_y , 50 ,50) 
    py5.stroke_weight(5)
    pos_y += speed

    printf()
    for i in range (3):
        tuyau_x[i] = tuyau_x[i] - 5

        if tuyau_x[i] == -300:
            chagement(i)

        if tuyau_x[i] == 80 - 50:
            score = score + 1

        if (abs(tuyau_x[i]-80) <= 50 and pos_y + 10 <= up_height[i]) or (abs(tuyau_x[i]-80) <= 50 and pos_y +45 >= up_height[i]+150):
            py5.text_size(50)
            py5.text("Game Over!!!",270,py5.height//2)
            py5.no_loop()
        
    py5.text_size(25)
    game = "Score : " + str(score)
    py5.text(game,20,20)

    if pos_y + 40>= py5.height or pos_y + 15<= 0:
        py5.text_size(50)
        py5.text("Game Over!!!",270,py5.height//2)
        py5.no_loop()

py5.run_sketch()