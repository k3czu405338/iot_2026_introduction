from gpiozero import AngularServo
from time import sleep

servo = AngularServo(
    18,                         # GPIO18 (Pin 12)
    min_angle=0,
    max_angle=180,
    min_pulse_width=0.0005,
    max_pulse_width=0.0024
)

while True:
    #######Rotate 45#######
    print("Rotate 45")
    print("0")
    servo.angle = 0
    sleep(3)

    print("45")
    servo.angle = 45
    sleep(3)
    
    print("90")
    servo.angle = 90
    sleep(3)
    
    print("135")
    servo.angle = 135
    sleep(3)
    
    print("180")
    servo.angle = 180
    sleep(3)
    
    print("180")
    servo.angle = 180
    sleep(3)
    
    #######Rotate 90#######
    print("Rotate 90")
    print("0")
    servo.angle = 0
    sleep(3)

    print("90")
    servo.angle = 90
    sleep(3)
    
    print("180")
    servo.angle =180
    sleep(3)

    #######Rotate 180#######
    print("Rotate 180")
    print("0")
    servo.angle = 0
    sleep(3)

    print("180")
    servo.angle = 180
    sleep(3)
