## 6 Button Esp32 based Matrix

Simple 6 button matrix control panel firmware written in C++ using the Arduino framework based on a Esp32 C3 Supermini devboard

# Required Hardware
*Esp32 C3-Supermini devboard
*6 buttons (any type works)
*Wires (or something to wire the buttons to the microcontroller)

# Setup
This piece of code was built using [PlaformIO](https://platformio.org/)

Download the PlatformIO VSCode extension [here](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) or from the "Extensions" tab in VSCode

Clone this repo 

"""bash
git clone https://github.com/notnotdaniel111/esp32-based-6-button-matrix
"""

Open the cloned repo in VSCode and then flash the devboard, after that it should work.

# Working principle

The chip sends a 12 character long string through uart and when a button is pressed down, one of the button state monitoring numbers (always an uneven character) changes.

# Example with a Flipper Zero

<img src="">
When fully inactive

<img src="">
When a button (fourth) is pressed down

# Init 

To make your job easier, there is an initialization string (############) that the device sends when it's ready.
*When you design anything using this project, I recommend only powering on the board after the main hardware (for example a Raspberry Pi) is fully booted up and are ready.

# Wiring

| Button | ESP32-C3 Pin | Connected Pin / Function | Notes |
| :--- | :--- | :--- | :--- |
| **Button 1** | `GPIO 10` | Leg 1 $\rightarrow$ Pin, Leg 2 $\rightarrow$ 3.3V | Clean GPIO |
| **Button 2** | `GPIO 4`  | Leg 1 $\rightarrow$ Pin, Leg 2 $\rightarrow$ 3.3V | Replaced GPIO 9 |
| **Button 3** | `GPIO 3`  | Leg 1 $\rightarrow$ Pin, Leg 2 $\rightarrow$ 3.3V | Replaced GPIO 8 |
| **Button 4** | `GPIO 7`  | Leg 1 $\rightarrow$ Pin, Leg 2 $\rightarrow$ 3.3V | Clean GPIO |
| **Button 5** | `GPIO 6`  | Leg 1 $\rightarrow$ Pin, Leg 2 $\rightarrow$ 3.3V | Clean GPIO |
| **Button 6** | `GPIO 5`  | Leg 1 $\rightarrow$ Pin, Leg 2 $\rightarrow$ 3.3V | Clean GPIO |

### UART Output
| ESP32-C3 Pin | Target Device | Notes |
| :--- | :--- | :--- |
| `GPIO 21 (TX)` | `RX` | Serial transmission line |
| `GPIO 20 (RX)` | `TX` | Optional (if bidirectional) |
| `GND` | `GND` | Common ground reference |
