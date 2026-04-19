import network
import time

ssid = 'SSID'
password = 'password'

wlan = network.WLAN(network.STA_IF)
wlan.active(True)

if not wlan.isconnected():
    print('Connecting to network...')
    wlan.connect(ssid, password)

    timeout = 10  
    start = time.time()

    while not wlan.isconnected():
        if time.time() - start > timeout:
            print("Failed to connect.")
            break
        time.sleep(1)

if wlan.isconnected():
    print('Connected!')
    print('IP address:', wlan.ifconfig()[0])
