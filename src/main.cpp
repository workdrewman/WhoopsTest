#include <Arduino.h>
#include "OneButton.h" // for OneButton

#define HALL_SENSOR1 21
#define HALL_SENSOR2 23
#define HALL_SENSOR3 22

OneButton button1{HALL_SENSOR1, true, true};
OneButton button2{HALL_SENSOR2, true, true};
OneButton button3{HALL_SENSOR3, true, true};
int sensorToLED[3] = {5,18,19};

static void handleClick(int number);
static void switchReleased(int number);

void setup() {
  Serial.begin(9600);
  pinMode(HALL_SENSOR1, INPUT);
  pinMode(HALL_SENSOR2, INPUT);
  pinMode(HALL_SENSOR3, INPUT);
  pinMode(sensorToLED[0], OUTPUT);
  pinMode(sensorToLED[1], OUTPUT);
  pinMode(sensorToLED[2], OUTPUT);
  
  button1.attachLongPressStart([]() { handleClick(1); }); 
  button1.attachLongPressStop([]() { switchReleased(1); });
  button2.attachLongPressStart([]() { handleClick(2); }); 
  button2.attachLongPressStop([]() { switchReleased(2); });  
  button3.attachLongPressStart([]() { handleClick(3); }); 
  button3.attachLongPressStop([]() { switchReleased(3); });
}

void loop() {
  button1.tick();
  button2.tick();
  button3.tick();
}

static void handleClick(int number) {
  // do something when sensor is triggered
  digitalWrite(sensorToLED[number - 1], HIGH);
  Serial.printf("Triggered sensor %d\n", number);
}

static void switchReleased(int number) {
  // do something when sensor is released
  digitalWrite(sensorToLED[number - 1], LOW);
  Serial.printf("Moved away from sensor %d\n", number);
}
