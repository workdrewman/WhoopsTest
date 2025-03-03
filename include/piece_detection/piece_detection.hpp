// =======================================================
// Description: This header file contains the defition
//              of helper functions to bring I2C piece detection
//              to the Whoops! game
// =======================================================

#ifndef PIECE_DETECTION_H
#define PIECE_DETECTION_H

#include <stdint.h> // for c types
#include <vector> // for vector of data
#include <mutex> // for mutex to make sensorData threadsafe

namespace piece_detection
{
const auto kMCP23017_StartAddr{0x20};
const auto kMaxChips{8};

class PieceDetection{
 public:
  /// @brief Constructor
  /// @param chips The number of chips to be used
  PieceDetection(size_t chips);

  /// @brief Reads all the IO Expanders and updates the data
  void readMCPInputs();

  /// @brief Initialize all the IO Expanders
  void initMCP23017();

  /// @brief Get a single sensor data
  /// @param index The sensor's index
  /// @return 0 or 1 based on value of sensor
  uint8_t getDataSingle(uint8_t index);

  /// @brief Gets the 8 bit data block of a chip[port]
  /// @param chip The chip number
  /// @param port Port A, Port B (0/1)
  /// @return 8 bit data block
  uint8_t getDataBlock(uint8_t chip, uint8_t port);

  /// @brief returns a copy of the data vector
  /// @return copy of sensor data
  std::vector<uint8_t> getDataCopy();

  /// @brief returns a vector of all the changed sensors in order
  /// @return vector of sensor ids
  std::vector<uint8_t> getChangedSensors();

  
 private:
  void initMCP23017(uint8_t addr);
  uint8_t readMCPInput(uint8_t addr, uint8_t gpioReg);
  void writeData(uint8_t chip, uint8_t port, uint8_t value);
  uint8_t getData(uint8_t chip, uint8_t index);

  std::vector<uint8_t> _sensor_data;
  std::mutex _data_mutex;
  uint8_t _num_chips;
  std::vector<uint8_t> _changed_sensors;
};
} // namespace piece_detection
#endif // PIECE_DETECTION_H
