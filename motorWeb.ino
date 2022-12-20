Skip to content
Product
Solutions
Open Source
Pricing
Search
Sign in
Sign up
witnessmenow
/
simple-wifi-controlled-rc-car
Public
Code
Issues
1
Pull requests
Actions
Projects
Security
Insights
simple-wifi-controlled-rc-car/MotorWeb/MotorWeb.ino
@witnessmenow
witnessmenow Making easier to adjust the drive and steer direction if they are wir…
…
Latest commit 1f0bb83 on Mar 11, 2018
 History
 1 contributor
154 lines (122 sloc)  4.14 KB

/*******************************************************************
    A sketch for controlling a toy car with using a web page 
    hosted on a ESP8266
    
    Main Hardware:
    - NodeMCU Development Board cp2102 (Look for the one with the square chip beside the USB port)
    - NodeMCU Motor Shield (L2932)
    
    Written by Brian Lough
    https://www.youtube.com/channel/UCezJOfu7OtqGzd5xrP3q6WA
 *******************************************************************/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// These are the pins used to control the motor shield

#define DRIVE_MOTOR_POWER D2 // Motor B
#define DRIVE_MOTOR_DIRECTION D4

#define STEER_MOTOR_POWER D1 // Motor A
#define STEER_MOTOR_DIRECTION D3

#define ARM_CYLIDER_VALVE D5 // Valve to activate arm cylinder
#define SCOOP_CYLINDER_VALVE D6 // Valve to activate scoop cylider
#define HITCH_HOOK_CYLINDER D7 // Valve to activate hitch hook cylinder
#define DRAIN_ARM_CYLINDER_VALVE D8 // Valve to drain air from arm cylinder

// drivePower sets how fast the car goes
// Can be set between 0 and 1023 (although car problaly wont move if values are too low)
int drivePower = 1023;

// driveDirection sets what direction the car drives
// If the car is moving backwards when you press the forward button, change this to LOW
uint8_t driveDirection = HIGH;

// steeringPower sets how fast the car turns
// Can be set between 0 and 1023 (again, car probably won't steer if the value is too low)
int steeringPower = 1023;

// steerDirection sets what direction the car steers
// If the car is steering right when you press the left button, change this to LOW
uint8_t steerDirection = HIGH;

// ----------------
// Set your WiFi SSID and Password here
// ----------------
const char* ssid = "ssid";
const char* password = "password";

ESP8266WebServer server(80);

const char *webpage = 
#include "motorPage.h"
;

void handleRoot() {

  server.send(200, "text/html", webpage);
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void){

  pinMode(DRIVE_MOTOR_POWER, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(DRIVE_MOTOR_DIRECTION, OUTPUT);
  pinMode(STEER_MOTOR_POWER, OUTPUT);
  pinMode(STEER_MOTOR_DIRECTION, OUTPUT);
  pinMode(ARM_CYLIDER_VALVE, OUTPUT);
  pinMode(SCOOP_CYLINDER_VALVE, OUTPUT);
  pinMode(HITCH_HOOK_CYLINDER, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("WifiCar")) {
    Serial.println("MDNS Responder Started");
  }

  server.on("/", handleRoot);

  server.on("/forward", [](){
    Serial.println("forward");
    analogWrite(DRIVE_MOTOR_POWER, drivePower);
    digitalWrite(DRIVE_MOTOR_DIRECTION, driveDirection);
    server.send(200, "text/plain", "forward");
  });

  server.on("/driveStop", [](){
    Serial.println("driveStop");
    analogWrite(DRIVE_MOTOR_POWER, 0);
    server.send(200, "text/plain", "driveStop");
  });

  server.on("/back", [](){
    Serial.println("back");
    analogWrite(DRIVE_MOTOR_POWER, drivePower);
    digitalWrite(DRIVE_MOTOR_DIRECTION, !driveDirection);
    server.send(200, "text/plain", "back");
  });

  server.on("/right", [](){
    Serial.println("right");
    analogWrite(STEER_MOTOR_POWER, steeringPower);
    digitalWrite(STEER_MOTOR_DIRECTION, steerDirection);
    server.send(200, "text/plain", "right");
  });

  server.on("/left", [](){
    Serial.println("left");
    analogWrite(STEER_MOTOR_POWER, steeringPower);
    digitalWrite(STEER_MOTOR_DIRECTION, !steerDirection);
    server.send(200, "text/plain", "left");
  });

  server.on("/steerStop", [](){
    Serial.println("steerStop");
    analogWrite(STEER_MOTOR_POWER, 0);
    server.send(200, "text/plain", "steerStop");
  });

   server.on("/armup", [](){
    Serial.println("armup");
    analogWrite(ARM_CYLIDER_VALVE, 1);
    server.send(200, "text/plain", "armup");
  });

   server.on("/armstop", [](){
    Serial.println("armstop");
    analogWrite(ARM_CYLIDER_VALVE, 0);
    server.send(200, "text/plain", "armstop");
  });

  server.on("/armdown", [](){
    Serial.println("armdown");
    analogWrite(ARM_CYLIDER_VALVE, 0);
    analogWrite(DRAIN_ARM_CYLINDER_VALVE, 1);
    server.send(200, "text/plain", "armdown");
  });

  server.on("/scoopdown", [](){
    Serial.println("scoopdown");
    analogWrite(SCOOP_CYLINDER_VALVE, 1);
    server.send(200, "text/plain", "scoopdown");
  });

   server.on("/scoopup", [](){
    Serial.println("scoopup");
    analogWrite(SCOOP_CYLINDER_VALVE, 0);
    server.send(200, "text/plain", "scoopup");
  });

  server.on("/hitchunlock", [](){
    Serial.println("hitchunlock");
    analogWrite(HITCH_HOOK_CYLINDER, 1);
    server.send(200, "text/plain", "hitchunlock");
  });

  server.on("/hitchlock", [](){
    Serial.println("hitchlock");
    analogWrite(HITCH_HOOK_CYLINDER, 0);
    server.send(200, "text/plain", "hitchlock");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP Server Started");
}

void loop(void){
  server.handleClient();
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
simple-wifi-controlled-rc-car/MotorWeb.ino at master · witnessmenow/simple-wifi-controlled-rc-car · GitHub