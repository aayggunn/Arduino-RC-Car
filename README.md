# Arduino RC Car 🚗📱

A Bluetooth-controlled RC car built with Arduino. This project allows you to control the car's movement (forward, backward, left, right) and honk a buzzer using a smartphone app via Bluetooth.

## 📸 Features

- **Bluetooth Control:** Control the car wirelessly using a smartphone app (e.g., "Bluetooth RC Controller").
- **Full Directional Control:** Forward, Backward, Left, and Right movement.
- **Horn/Buzzer:** Activate a buzzer using the 'Y' command.
- **Automatic LED Blinking:** A status LED blinks continuously without blocking the main loop (using `millis()`).
- **Motor Speed Control:** PWM-based speed control for smooth turning and driving.

## 🛠️ Hardware Requirements

- **1x Arduino Uno** (or compatible board)
- **1x L298N Motor Driver Module**
- **1x HC-05 or HC-06 Bluetooth Module**
- **4x DC Motors** (or 2x DC Motors with a chassis)
- **1x Active Buzzer** (connected to Pin 5)
- **1x LED** (connected to Pin 4) + 220Ω Resistor
- **1x Robot Car Chassis** (with wheels)
- **Jumper Wires**
- **Battery Pack** (e.g., 9V for Arduino and 18650x2 battery for L298N motor driver)

## 🔌 Wiring Diagram

### L298N to Arduino
| L298N Pin | Arduino Pin | Function |
|-----------|-------------|----------|
| ENA | 11 | Left Motor Speed (PWM) |
| IN1 | 10 | Right Motor Forward |
| IN2 | 9 | Right Motor Backward |
| IN3 | 8 | Left Motor Forward |
| IN4 | 7 | Left Motor Backward |
| ENB | 6 | Right Motor Speed (PWM) |
| GND | GND | **Common Ground (Essential!)** |

### Bluetooth Module (HC-05/HC-06)
| HC-05 Pin | Arduino Pin |
|-----------|-------------|
| VCC | 5V |
| GND | GND |
| TX | RX (Pin 0) |
| RX | TX (Pin 1) |

> ⚠️ **Warning:** Disconnect the Bluetooth module's RX/TX pins before uploading the code to avoid upload errors. Use a voltage divider on the RX pin if possible.

### Buzzer & LED
| Component | Arduino Pin |
|-----------|-------------|
| Buzzer (+) | 5 |
| Buzzer (-) | GND |
| LED (+) | 4 |
| LED (-) | GND |

## 📱 How to Use

1. **Upload the Code:** Connect your Arduino to the PC and upload the `Arduino-RC-Car.ino` file. **Disconnect the Bluetooth module's RX/TX pins during upload.**
2. **Power the Car:** Connect the battery pack to the L298N motor driver.
3. **Pair Bluetooth:** Turn on the car. On your smartphone, search for the HC-05/HC-06 Bluetooth device and pair it (default password: `1234` or `0000`).
4. **Open the App:** Download a Bluetooth RC app (e.g., "Bluetooth RC Controller" on Android).
5. **Connect and Drive:** Connect the app to the Bluetooth module and use the on-screen buttons to drive.

## 🎮 Command List

| Command | Action |
|---------|--------|
| `F` | Move Forward |
| `B` | Move Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `S` | Stop |
| `Y` | Honk (Buzzer) |

## 📂 Project Structure

- `Arduino-RC-Car.ino` - Main Arduino source code.
- `README.md` - Project documentation.
- `.gitattributes` - Git configuration file.

## 🤝 Contributors

Thanks to everyone who has contributed to this project!

- [aayggun](https://github.com/aayggun) (Owner)
- [oguztntoglu](https://github.com/oguztntoglu)
- [ayhancıydem](https://github.com/ayhanciydem)

*(Note: To appear in this list, you must make a commit to the repository.)*

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).


---

