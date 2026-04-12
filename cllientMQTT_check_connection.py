import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect("192.168.3.114", 1883) #change IP to broker MQTT server

client.publish("test/topic", "Hello from client MQTT")
client.disconnect()
