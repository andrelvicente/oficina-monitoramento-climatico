import serial
import json
import requests

arduino_port = 'COM3'  # For Linux use something like '/dev/ttyUSB0'
baud_rate = 9600

ser = serial.Serial(arduino_port, baud_rate)

server_url = 'http://your-server-url.com/api'

def send_to_server(json_data):
    try:
        response = requests.post(server_url, json=json_data)
        if response.status_code == 200:
            print("Successfully sent to server:", json_data)
        else:
            print(f"Failed to send data to server. Status code: {response.status_code}")
    except Exception as e:
        print("Error sending data to server:", e)

def read_serial_json():
    while True:
        if ser.in_waiting > 0:
            try:
                serial_data = ser.readline().decode('utf-8').strip()

                json_data = json.loads(serial_data)

                print("Received JSON data:", json_data)
                send_to_server(json_data)
                
            except json.JSONDecodeError:
                print("Error decoding JSON")
            except Exception as e:
                print("Error:", e)

read_serial_json()