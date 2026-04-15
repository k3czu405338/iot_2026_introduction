from gpiozero import AngularServo
from time import sleep
import paho.mqtt.client as mqtt
from gpiozero import DistanceSensor
from time import sleep

servo = AngularServo(
    18,                         # GPIO18 (Pin 12)
    min_angle=0,
    max_angle=180,
    min_pulse_width=0.0005,
    max_pulse_width=0.0024
)

client = mqtt.Client()
client.username_pw_set("test3", "test3")
client.connect("192.168.0.40", 1883, 60) # change IP to server MQTT in group

while True:
    #######Rotate 45#######
    print("Rotate 45")
    print("0")
    servo.angle = 0
    sleep(2)
    client.publish("test/test3", "0 posistin rotate")

    print("45")
    servo.angle = 45
    sleep(2)
    client.publish("test/test3", "45 posistin rotate")
    
    print("90")
    servo.angle = 90
    sleep(2)
    client.publish("test/test3", "90 posistin rotate")
    
    print("135")
    servo.angle = 135
    sleep(2)
    client.publish("test/test3", "135 posistin rotate")
    
    print("180")
    servo.angle = 180
    sleep(2)
    client.publish("test/test3", "180 posistin rotate")
    
    #######Rotate 90#######
    print("Rotate 90")
    print("0")
    servo.angle = 0
    sleep(2)
    client.publish("test/test3", "0 posistin rotate")
    
    print("90")
    servo.angle = 90
    sleep(2)
    client.publish("test/test3", "0 posistin rotate")

    print("180")
    servo.angle = 180
    sleep(2)
    client.publish("test/test3", "180 posistin rotate")

    #######Rotate 180#######
    print("Rotate 180")
    print("0")
    servo.angle = 0
    sleep(2)
    client.publish("test/test3", "0 posistin rotate")

    print("180")
    servo.angle = 180
    sleep(2)
    client.publish("test/test3", "180 posistin rotate")
    
client.disconnect()
