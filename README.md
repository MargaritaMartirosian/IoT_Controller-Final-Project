# IoT_Controller-Final-Project
Canadian Military Base Security System 
This project showcases an advanced IoT-based system that integrates multiple components to create a cohesive and interactive environment. Utilizing the robust MQTT protocol for communication, the system includes four sensors and four output devices, all orchestrated through an ESP32 microcontroller and a Raspberry Pi.

Key Features:

- Sensors and Actuators: The system integrates four different sensors and actuators:
Two ultrasonic sensors, each linked to an individual LED that illuminates based on the sensor's proximity readings.
- An infrared sensor paired with an LED that activates in response to the sensor's detections.
- A motion sensor connected to a buzzer, alerting when motion is detected.
- ESP32 Microcontroller: Serves as the central hub, interfacing between sensors, actuators, and the MQTT broker.
- Raspberry Pi as MQTT Broker: Facilitates communication across the system's components, ensuring responsive and reliable data transfer.
-  Independent Servo Control: Incorporates two servo motors, controlled separately using an Arduino Uno, adding another dimension to the system's capabilities.
