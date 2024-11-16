#ifndef DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP
#define DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP

// #include <cstring>
#include <sstream>
// #include <cstdlib>
#include <libserial/SerialPort.h>
#include <iostream>

/*
    This is a wrapper around the Libserial C++ lib which allows you to read and write over Serial
    with other devices. I am implementing an easier interface to connect, disconnect, read, and write
    specific for connecting 2 motors. 

    I am constructing an object ie. class that is designed to have the following functions.
        Basic Functions
        1. connect
        2. disconnect
        3. send_msg
        4. read_msg

        Higher Level Functions
        5. send_empty_msg
        6. read_encoder_vals
        7. set_motor_values
        8. set_pid_values
*/ 

// Function to take int and return a LibSerial::BaudRate type
LibSerial::BaudRate convert_baude_rate(int baude_rate)
{
  // Just handle some common baud rates
  switch (baude_rate)
  {
    case 1200: return LibSerial::BaudRate::BAUD_1200;
    case 1800: return LibSerial::BaudRate::BAUD_1800;
    case 2400: return LibSerial::BaudRate::BAUD_2400;
    case 4800: return LibSerial::BaudRate::BAUD_4800;
    case 9600: return LibSerial::BaudRate::BAUD_9600;
    case 19200: return LibSerial::BaudRate::BAUD_19200;
    case 38400: return LibSerial::BaudRate::BAUD_38400;
    case 57600: return LibSerial::BaudRate::BAUD_57600;
    case 115200: return LibSerial::BaudRate::BAUD_115200;
    case 230400: return LibSerial::BaudRate::BAUD_230400;
    default:
      std::cout << "Error! Baud rate " << baude_rate << " not supported! Default to 57600" << std::endl;
      return LibSerial::BaudRate::BAUD_57600;
  }
}

class ArduinoComms
{
    // write the public implementation first so that when 
    // people read it they only see what they need to see

    // We define the public variables.
    public:
        ArduinoComms() = default; // We construct the class when it is called.

    /*
        We are referencing the serial device (ie. &serial_device) by using the & operator bc 
        in C/C++ you can pass a variable as an arg using the & which means that any operations on
        the &var will affect the original variable var. We can ensure that the variable can't be changed
        while we are using it by setting the const qualifier const [type] &var ie.
        (const std::string & serial_device). This allows us to reference the original data instead of 
        making a copy and we wont be allowed to change it while we are using the data.

        The benefit of doing this is that we save memory and enforce programmer intention ie. the var
        wont't change while we are using it.   
    */
    void connect(const std::string &serial_device, int32_t baude_rate, int32_t timeout_ms)
    {
        timeout_ms = timeout_ms;
        baude_rate = baude_rate;
        serial_conn_.Open(serial_device); // we are opening the serial device at the path of the device
        serial_conn_.SetBaudRate(convert_baude_rate(baude_rate));
    }

    void disconnect()
    {
        serial_conn_.Close();
    }

    void read_msg(std::string msg)
    {
        serial_conn_.ReadLine(msg);
    }

    private:
        LibSerial::SerialPort serial_conn_;

}

#endif // DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP