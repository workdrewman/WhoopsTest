// // THIS IS A TEST FOR JOE's RFID SUBPROJECT

// // PIN MAPPING
// // 3.3    ->    3.3
// // Reset  ->    D15
// // GND    ->    GND
// // MISO   ->    D19
// // MOSI   ->    D23
// // SCK    ->    D18
// // SDA    ->    D5

// #define TESTING_RFID
// #ifdef TESTING_RFID
// #include <SPI.h>
// #include <MFRC522.h>

// #define SS_PIN 5
// #define RST_PIN 15

// MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

// MFRC522::MIFARE_Key key;
// void printHex(byte *buffer, byte bufferSize);
// void printDec(byte *buffer, byte bufferSize);

// // Init array that will store new NUID 
// byte nuidPICC[4];

// void setup() { 
//   Serial.begin(9600);
//   SPI.begin(); // Init SPI bus
//   rfid.PCD_Init(); // Init MFRC522 

//   for (byte i = 0; i < 6; i++) {
//     key.keyByte[i] = 0xFF;
//   }

//   Serial.println(F("This code scans all MIFARE tags and prints their details."));
//   Serial.print(F("Using the following key:"));
//   printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
// }
 
// void loop() {
//   // Reset the loop if no new card is present on the sensor/reader. This saves the entire process when idle.
//   if (!rfid.PICC_IsNewCardPresent())
//     return;

//   // Verify if the NUID has been read
//   if (!rfid.PICC_ReadCardSerial())
//     return;

//   Serial.print(F("PICC type: "));
//   MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
//   Serial.println(rfid.PICC_GetTypeName(piccType));

//   // Remove restrictions for MIFARE Classic only
//   if (rfid.uid.uidByte[0] != nuidPICC[0] || 
//       rfid.uid.uidByte[1] != nuidPICC[1] || 
//       rfid.uid.uidByte[2] != nuidPICC[2] || 
//       rfid.uid.uidByte[3] != nuidPICC[3]) {
//     Serial.println(F("A new card has been detected."));

//     // Store NUID into nuidPICC array
//     for (byte i = 0; i < 4; i++) {
//       nuidPICC[i] = rfid.uid.uidByte[i];
//     }
   
//     Serial.println(F("The NUID tag is:"));
//     Serial.print(F("In hex: "));
//     printHex(rfid.uid.uidByte, rfid.uid.size);
//     Serial.println();
//     Serial.print(F("In dec: "));
//     printDec(rfid.uid.uidByte, rfid.uid.size);
//     Serial.println();
//   } else {
//     Serial.println(F("Card read previously."));
//   }

//   // Halt PICC
//   rfid.PICC_HaltA();

//   // Stop encryption on PCD
//   rfid.PCD_StopCrypto1();
// }

// /**
//  * Helper routine to dump a byte array as hex values to Serial. 
//  */
// void printHex(byte *buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(buffer[i] < 0x10 ? " 0" : " ");
//     Serial.print(buffer[i], HEX);
//   }
// }

// /**
//  * Helper routine to dump a byte array as dec values to Serial.
//  */
// void printDec(byte *buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(' ');
//     Serial.print(buffer[i], DEC);
//   }
// }
// #endif


// THIS IS A TEST FOR JOE's RFID SUBPROJECT

// PIN MAPPING
// 3.3    ->    3.3
// Reset  ->    D15
// GND    ->    GND
// MISO   ->    D19
// MOSI   ->    D23
// SCK    ->    D18
// SDA    ->    D5

#define TESTING_RFID
#ifdef TESTING_RFID
#include <SPI.h>
#include <MFRC522.h>
#include <freertos/FreeRTOS.h>
#include <FastLED.h> // for FastLED
#include "led_control/tile_movement.h" // for indicate_move

#define SS_PIN 5
#define RST_PIN 15
#define NUM_LEDS 44
#define DATA_PIN 13
#define POT_Pin 2

uint8_t constexpr kInvalidCardName{99};

CRGB leds[NUM_LEDS]; // Instance of ARGB LEDs
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the rfid module
uint8_t shared_tag_id = kInvalidCardName; // Stores the most recently scanned tag

MFRC522::MIFARE_Key key;
void printHex(byte *buffer, byte bufferSize);
void printDec(byte *buffer, byte bufferSize);

// Define the list of UIDs and their corresponding names
struct Card {
  byte uid[7];           // UID of the card
  uint8_t name;      // Name of the card
};

Card allowedCards[] = {
  {{0x04, 0xCD, 0x89, 0xA6, 0x67, 0x26, 0x81}, 1},
  {{0x04, 0x67, 0x4D, 0xA4, 0x67, 0x26, 0x81}, 2},
  {{0x04, 0x1D, 0xCF, 0xA5, 0x67, 0x26, 0x81}, 3},
  {{0x04, 0x8B, 0xF4, 0xA7, 0x67, 0x26, 0x81}, 4},
  {{0x04, 0x2A, 0x8C, 0xA2, 0x67, 0x26, 0x81}, 5},
  {{0x04, 0x75, 0xDF, 0xA5, 0x67, 0x26, 0x81}, 7},
  {{0x04, 0xC4, 0x63, 0xA5, 0x67, 0x26, 0x81}, 8},
  {{0x04, 0x31, 0x98, 0xA9, 0x67, 0x26, 0x81}, 10},
  {{0x04, 0x8C, 0xDD, 0xA5, 0x67, 0x26, 0x81}, 11},
  {{0x04, 0x6D, 0x78, 0xA2, 0x67, 0x26, 0x81}, 12},
  {{0x04, 0x7F, 0x36, 0xA4, 0x67, 0x26, 0x81}, 0},
};
const int numAllowedCards = sizeof(allowedCards) / sizeof(allowedCards[0]);

// Function to find if the scanned UID matches an allowed card
uint8_t getCardName(byte *scannedUID, byte uidSize) {
  for (int i = 0; i < numAllowedCards; i++) {
    // Check if UID sizes match
    if (uidSize != sizeof(allowedCards[i].uid)) {
      continue;
    }

    // Compare each byte of the UID
    bool match = true;
    for (byte j = 0; j < uidSize; j++) {
      if (scannedUID[j] != allowedCards[i].uid[j]) {
        match = false;
        break;
      }
    }

    // If a match is found, return the card name
    if (match) {
      return allowedCards[i].name;
    }
  }

  return kInvalidCardName; // No matches found
}

void RFIDTask(void *parameter) {
    while (true) {
        if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
            uint8_t new_card_id = getCardName(rfid.uid.uidByte, rfid.uid.size);
            if (new_card_id != kInvalidCardName) {
              Serial.println(F("Tag accepted"));
              Serial.print(F("Card Name: "));
              Serial.println(new_card_id);
              shared_tag_id = new_card_id;
            } 
            
            else {
              Serial.println(F("Tag not recognized"));
            }

            rfid.PICC_HaltA(); // Stop reading after one scan
        }

        vTaskDelay(100 / portTICK_PERIOD_MS); // Avoid overwhelming the CPU
    }
}

void LEDPotTask(void *parameter) {
  uint16_t pot_read = 0; // Stores the most recent reading from the potentiometer
  uint32_t scaled_pot = 0; // Scaled value of the potentiometer
  while (true) {
    pot_read = analogRead(POT_Pin);
    scaled_pot = pot_read * 200 / 4095; // Scale 0-4095 to 0-100
    set_max_power_in_volts_and_milliamps(5, scaled_pot); // Set brightness
    Serial.print(("Setting LED brightness to: "));
    Serial.println(scaled_pot);
    vTaskDelay(10000 / portTICK_PERIOD_MS); // Avoid overwhelming the CPU
  }
}

void setup() { 
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // Add LEDs
  set_max_power_in_volts_and_milliamps(5, 120); // Set brightness
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  xTaskCreate(
      RFIDTask,         // Task function
      "RFID Read",      // Name of the task
      2048,             // Stack size (in bytes)
      NULL,             // Task parameter
      1,                // Priority
      NULL              // Task handle
  );
  xTaskCreate(
      LEDPotTask,         // Task function
      "Potentiometer read",      // Name of the task
      2048,             // Stack size (in bytes)
      NULL,             // Task parameter
      2,                // Priority
      NULL              // Task handle
  );
  Serial.println(F("This code is intended as a demo for the RFID and LED system."));
}

void loop() {
  uint8_t card_id = shared_tag_id;
  if (card_id != kInvalidCardName && card_id != 0) {
    if (card_id == 12) { card_id = 11; }
    led_control::demo_move(card_id + 1);

  }
  vTaskDelay(500 / portTICK_PERIOD_MS);
}

/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
 * Helper routine to dump a byte array as dec values to Serial.
 */
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(' ');
    Serial.print(buffer[i], DEC);
  }
}
#endif
