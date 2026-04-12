import paho.mqtt.client as mqtt
from gpiozero import DistanceSensor
from time import sleep

sensor = DistanceSensor(echo=24, trigger=23)
client = mqtt.Client()
client.connect("192.168.3.114", 1883) # change IP to server MQTT in group

while True:
    distance = sensor.distance * 100  
    client.publish("test/topic", f"{distance:.2f} cm")
    sleep(0.1)



client.disconnect()







