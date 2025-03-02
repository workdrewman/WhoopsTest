#include <Arduino.h>
#include "piece_detection/piece_detection.hpp" // for PieceDetection

piece_detection::PieceDetection* pieceDetection = new piece_detection::PieceDetection(2);

void setup() {
  Serial.begin(9600);
  pieceDetection->initMCP23017();
}

void loop() {
  pieceDetection->readMCPInputs();
  std::vector<uint8_t> data = pieceDetection->getDataCopy();
  for (int i = 0; i < data.size(); i++) {
    Serial.println(data[i], BIN); // Print as binary
  }
  delay(1000); // Poll every 1s
}
