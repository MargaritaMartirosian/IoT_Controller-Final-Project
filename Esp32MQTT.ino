/*This ESP32 IoT code demonstrates the integration of multiple sensors and WiFi/MQTT communication for IoT applications. 
It establishes WiFi connectivity, connects to an MQTT broker, and handles both sensor data acquisition and remote actuator control. 
The code includes functionalities for reading ultrasonic, infrared, and motion sensors, and controlling LEDs and a buzzer based on MQTT messages. 
It's designed for real-time interaction with an MQTT server \, facilitating remote monitoring and control 
in applications such as smart homes, security systems, or environmental monitoring. 
*/

#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid ="iot_wireless";
const char* password ="Unsecure!";
const char* mqtt_server = "margakate-pi";
const int mqtt_port = 1883;

unsigned long lastSensorReadTime = 0;
const long sensorReadInterval = 3000;  // 3 second

String name = "ESP32Client_";
String distance1;
String distance2;
unsigned long previousMillis = 0;
const long interval = 1000;

WiFiClient espClient;
PubSubClient client(espClient);

// Pin Definitions
#define ULTRASONIC_TRIG1 23
#define ULTRASONIC_ECHO1 19
#define ULTRASONIC_TRIG2 22
#define ULTRASONIC_ECHO2 21
#define PIR_PIN 4   //27
#define LED_PIN 27  //14
#define LED_PIN2 14
#define BUZZER_PIN 32
#define IR_PIN 33
#define LED_PIN3 25


void setup() {
  Serial.begin(115200);                      // Start serial communication at 115200 baud
  setup_wifi();                              // Connect to WiFi
  client.setServer(mqtt_server, mqtt_port);  // Set the MQTT server and port
  client.setCallback(callback);              // Set the MQTT callback
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ULTRASONIC_TRIG1, OUTPUT);
  pinMode(ULTRASONIC_ECHO1, INPUT);
  pinMode(ULTRASONIC_TRIG2, OUTPUT);
  pinMode(ULTRASONIC_ECHO2, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
}


void setup_wifi() {
  WiFi.begin(ssid, password);              // Start WiFi connection
  while (WiFi.status() != WL_CONNECTED) {  // Wait until connected
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");  // Print confirmation once connected
}

int readUltrasonicDistance(int triggerPin, int echoPin)
   //  function used to calculate the distance for the ultrasonic sensors 
{
  // Clear the triggerPin condition
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // Sets the triggerPin HIGH (active) for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measures the time for the echoPin to receive a pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  int distance = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
  return distance;
}


void loop() {

  unsigned long currentMillis = millis();

  if (!client.connected()) {
    reconnect();  
  }
  client.loop();
  // Uses the ultrasonic function for each sensor and converts the values into strings 
  distance1 = String(readUltrasonicDistance(ULTRASONIC_TRIG1, ULTRASONIC_ECHO1));
  distance2 = String(readUltrasonicDistance(ULTRASONIC_TRIG2, ULTRASONIC_ECHO2));
  
  if (currentMillis - lastSensorReadTime >= sensorReadInterval) {
  lastSensorReadTime = currentMillis;
  // compare current time with last sensor read time

  // Motion sensor getting published 
    bool motionDetected = digitalRead(PIR_PIN);
  if (motionDetected == 1) {

    client.publish("sensor/motion", "Detected");
  } else {
    client.publish("sensor/motion", "Not Detected");
  }
  
  // Ultrasonic sensor 1 & 2 getting published 
  client.publish("sensor/ultrasonic1", distance1.c_str());
  client.publish("sensor/ultrasonic2", distance2.c_str());
  
  // Infrared sensor getting published 
  bool infraredDetected = digitalRead(IR_PIN);
  if (infraredDetected == 0) {
    client.publish("sensor/infrared", "Detected");

  } else {
    client.publish("sensor/infrared", "Not Detected");
 
  }


} }

void callback(char* topic, byte* payload, unsigned int length) {

  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];

  // callback function is used to handle the message comming 
  // from the Raspberry Pi and executing them with the use of an ESP32.

  }  // Handle led control messages
  if (String(topic) == "control/led") {
    if (message == "On") {
      digitalWrite(LED_PIN, HIGH);
    } else if (message == "Off") {
      digitalWrite(LED_PIN, LOW);
    }  
   }  // Handle led2 control messages
  if (String(topic) == "control/led2") {
    if (message == "On") {
      digitalWrite(LED_PIN2, HIGH);
    } else if (message == "Off") {
      digitalWrite(LED_PIN2, LOW);
    }
  }  // Handle led3 control messages
  if (String(topic) == "control/led3") {
    if (message == "On") {
      digitalWrite(LED_PIN3, HIGH);
    } else if (message == "Off") {
      digitalWrite(LED_PIN3, LOW);
    }
  }
  // Handle Buzzer control messages
  if (String(topic) == "control/buzzer") {
    if (message == "On") {
      digitalWrite(BUZZER_PIN, HIGH);
    } else if (message == "Off") {
      digitalWrite(BUZZER_PIN, LOW);
    }
  }
} 

void reconnect() { 
  
// function used to signal if the MQTT broker is connected. 
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect(name.c_str())) {
      Serial.println("Connected to MQTT broker");
      client.subscribe("control/led");
      client.subscribe("control/led2");
      client.subscribe("control/led3");
      client.subscribe("control/buzzer");
    } else {
      Serial.print("Failed to connect to MQTT broker, rc=");
      Serial.print(client.state());
      Serial.println("Try again in 5 seconds");
      delay(5000);
    }
  }
}
