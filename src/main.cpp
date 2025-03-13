#include <Arduino.h>
#include "piece_detection/piece_detection.hpp" // for PieceDetection

piece_detection::PieceDetection* pieceDetection = new piece_detection::PieceDetection(2);

void setup() {
  Serial.begin(9600);
  pieceDetection->initMCP23017();

  // Create the FreeRTOS task
  xTaskCreate(
    [](void* pvParameters) {
      while (true) {
        pieceDetection->readMCPInputs();
        vTaskDelay(pdMS_TO_TICKS(50));
      }
    },   // Task function
    "ReadMCPInputs",     // Name of the task
    2048,                // Stack size (in words, not bytes)
    NULL,                // Task input parameter
    1,                   // Priority of the task
    NULL                 // Task handle
  );
}

void loop() {
  if (pieceDetection->hasChangedSensor()) {
    auto changedSensors = pieceDetection->getChangedSensors();
    for (auto sensor : changedSensors) {
      uint8_t data = pieceDetection->getDataSingle(sensor);
      Serial.printf("Sensor changed: %d Value: %d\n", sensor, data);
    }
  }
  vTaskDelay(pdMS_TO_TICKS(10000));
}
