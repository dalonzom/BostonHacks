import serial
import sys
import numpy as np

def main():

    serial_port = '/dev/tty96B0';
    baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
    write_to_file_path = "night_data_" + sys.argv[1] + ".txt";

    print(write_to_file_path)

    output_file = open(write_to_file_path, "a+");
    ser = serial.Serial(serial_port, baud_rate)
    while True:
        line = ser.readline();
        line = line.decode("utf-8") #ser.readline returns a binary, convert to string
        print(line);
        output_file.write(line);

main()
