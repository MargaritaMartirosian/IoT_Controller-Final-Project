# IoT_Controller-Final-Project
Canadian Military Base Security System:
This project showcases an advanced IoT-based system that integrates multiple components to create a cohesive and interactive environment. Utilizing the robust MQTT protocol for communication, the system includes four sensors and four output devices, all orchestrated through an ESP32 microcontroller and a Raspberry Pi.

Key Features:

- Sensors and Actuators: The system integrates four different sensors and actuators:
  Two ultrasonic sensors, each linked to an individual LED that illuminates based on the sensor's proximity readings.
- An infrared sensor paired with an LED that activates in response to the sensor's detections.
- A motion sensor connected to a buzzer, alerting when motion is detected.
- ESP32 Microcontroller: Serves as the central hub, interfacing between sensors, actuators, and the MQTT broker.
- Raspberry Pi as MQTT Broker: Facilitates communication across the system's components, ensuring responsive and reliable data transfer.
- Independent Servo Control: Incorporates two servo motors, controlled separately using an Arduino Uno, adding another dimension to the system's capabilities.

# Video
Check out the project in action: [Watch the demo](https://youtu.be/Xszdq82md7Q)

# Project File Overview

This document outlines the origin and authorship of files used in the project:

#### 1. **Acknowledgments**

   This project has been developed as part of an advanced IoT system integration exercise. I would like to extend my gratitude to **[Michel Paquette](https://github.com/paquettm)** for their guidance and for         providing the following resources that served as a foundation for this work:

   - `historian_data.db`: Database file for handling historical data.
   - `historian.py`: Python script for historical data operations.
   - `automated_start.md`: Instructions for automated project setup.
   - `web_service/`: A collection of web service operation code files.

#### 2. **Modified File**
   - `IoT_Controller.py`: Originally provided by the instructor, this file has been modified by me to better suit the specific needs of our project.
     
#### 3. **Files Developed Independently**
   - `config.json`: A configuration file created by me, containing essential project settings and parameters.
   - `Esp32MQTT.ino`: An Arduino sketch written by me for the ESP32, implementing MQTT communication.
   - `RadarServo.ino`: Another Arduino sketch I developed, intended for controlling a servo motor in a radar-like mechanism.
---
### Team Contributions
This project was a collaborative effort. Special thanks to my teammate **[Kate Botto](https://github.com/KateBotto)** for her excellent work on creating the maquette for the project. Her design skills brought the project's physical representation to life and made it visually engaging.

---
Each file serves a specific purpose within the project, contributing to its overall functionality and effectiveness. The integration of provided and self-developed files demonstrates both the utilization of existing resources and the innovation in custom solutions.
