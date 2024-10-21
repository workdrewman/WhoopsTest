import serial
import csv
import time

# Configure the Serial port
ser = serial.Serial('COM3', 9600)  # Use 'COM3' for Windows
time.sleep(2)  # Wait for the serial connection to initialize

# Open a CSV file for writing
with open('output.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    
    # Write the header
    writer.writerow(['Sensor1', 'Sensor2'])
    
    try:
        while True:
            # Read a line from the serial port
            line = ser.readline().decode('utf-8', errors='ignore').strip()  # Ignore decoding errors
            # Split the data into separate values
            data = line.split(',')
            # Check if data has the expected number of values
            if len(data) == 2:
                # Write the data to the CSV file
                writer.writerow(data)
                print(f"Written: {data}")  # Print the data for debugging
            else:
                print(f"Unexpected data format: {line}")  # Debugging output for unexpected format
    except KeyboardInterrupt:
        print("Exiting...")
    finally:
        ser.close()  # Close the serial connection
