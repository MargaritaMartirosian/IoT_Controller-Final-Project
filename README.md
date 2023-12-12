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

# Video
https://youtu.be/Xszdq82md7Q 

# Project File Overview

This document outlines the origin and authorship of files used in the project:

1. **Files Taken from Instructor**:
   - `historian_data.db`: A database file provided by the instructor.
   - `historian.py`: A Python script for handling historical data operations, obtained from the instructor.
   - `automated_start.md`: A markdown file with instructions for automated project setup, sourced from the instructor.
   - `web_service`: A folder containing various code files for web service operations, provided by the instructor.

2. **Modified File**:
   - `IoT_Controller.py`: Originally provided by the instructor, this file has been modified by me to better suit the specific needs of our project.

3. **Files Developed Independently**:
   - `config.json`: A configuration file created by me, containing essential project settings and parameters.
   - `Esp32MQTT.ino`: An Arduino sketch written by me for the ESP32, implementing MQTT communication.
   - `RadarServo.ino`: Another Arduino sketch I developed, intended for controlling a servo motor in a radar-like mechanism.

Each file serves a specific purpose within the project, contributing to its overall functionality and effectiveness. The integration of provided and self-developed files demonstrates both the utilization of existing resources and the innovation in custom solutions.
