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
- **Battery Pack** (e.g., 9V or 4xAA for the motor driver)

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
| LED (+) | 4 (via 220Ω resistor) |
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

# Arduino RC Araba 🚗📱

Arduino ile yapılmış, Bluetooth üzerinden kontrol edilebilen bir RC araba projesi. Akıllı telefon uygulaması ile aracın hareketini (ileri, geri, sol, sağ) kontrol edebilir ve buzzer ile korna çalabilirsiniz.

## 📸 Özellikler

- **Bluetooth Kontrolü:** Akıllı telefon uygulaması ile aracı kablosuz olarak kontrol edin.
- **Tam Yön Kontrolü:** İleri, Geri, Sol ve Sağ hareket.
- **Korna/Buzzer:** 'Y' komutu ile buzzer'ı çalıştırın.
- **Otomatik LED Yanıp Sönme:** Durum LED'i, ana döngüyü bloklamadan (`millis()` kullanarak) sürekli yanıp söner.
- **Motor Hız Kontrolü:** Yumuşak dönüş ve sürüş için PWM tabanlı hız kontrolü.

## 🛠️ Donanım Gereksinimleri

- **1x Arduino Uno** (veya uyumlu kart)
- **1x L298N Motor Sürücü Modülü**
- **1x HC-05 veya HC-06 Bluetooth Modülü**
- **4x DC Motor** (veya şasi ile 2x DC Motor)
- **1x Aktif Buzzer** (Pin 5'e bağlı)
- **1x LED** (Pin 4'e bağlı) + 220Ω Direnç
- **1x Robot Araba Şasisi** (tekerlekleri ile)
- **Jumper Kablolar**
- **Pil Paketi** (motor sürücü için örn. 9V veya 4xAA)

## 🔌 Bağlantı Şeması

### L298N - Arduino
| L298N Pini | Arduino Pini | Görevi |
|------------|--------------|--------|
| ENA | 11 | Sol Motor Hızı (PWM) |
| IN1 | 10 | Sağ Motor İleri |
| IN2 | 9 | Sağ Motor Geri |
| IN3 | 8 | Sol Motor İleri |
| IN4 | 7 | Sol Motor Geri |
| ENB | 6 | Sağ Motor Hızı (PWM) |
| GND | GND | **Ortak Toprak (Şart!)** |

### Bluetooth Modülü (HC-05/HC-06)
| HC-05 Pini | Arduino Pini |
|------------|--------------|
| VCC | 5V |
| GND | GND |
| TX | RX (Pin 0) |
| RX | TX (Pin 1) |

> ⚠️ **Uyarı:** Kod yüklerken Bluetooth modülünün RX/TX pinlerini çıkarın, aksi halde yükleme hatası alırsınız. Mümkünse RX pinine gerilim bölücü koyun.

### Buzzer ve LED
| Bileşen | Arduino Pini |
|---------|--------------|
| Buzzer (+) | 5 |
| Buzzer (-) | GND |
| LED (+) | 4 (220Ω direnç üzerinden) |
| LED (-) | GND |

## 📱 Nasıl Kullanılır

1. **Kodu Yükleyin:** Arduino'yu bilgisayara bağlayın ve `Arduino-RC-Car.ino` dosyasını yükleyin. **Yükleme sırasında Bluetooth modülünün RX/TX pinlerini çıkarın.**
2. **Aracı Besleyin:** Pil paketini L298N motor sürücüsüne bağlayın.
3. **Bluetooth Eşleştirin:** Aracı açın. Telefonunuzdan HC-05/HC-06 Bluetooth cihazını arayın ve eşleştirin (varsayılan şifre: `1234` veya `0000`).
4. **Uygulamayı Açın:** Bir Bluetooth RC uygulaması indirin (Android'de "Bluetooth RC Controller" gibi).
5. **Bağlanın ve Sürün:** Uygulamayı Bluetooth modülüne bağlayın ve ekrandaki butonlarla aracı sürün.

## 🎮 Komut Listesi

| Komut | Eylem |
|-------|-------|
| `F` | İleri Git |
| `B` | Geri Git |
| `L` | Sola Dön |
| `R` | Sağa Dön |
| `S` | Dur |
| `Y` | Korna (Buzzer) |

## 📂 Proje Yapısı

- `Arduino-RC-Car.ino` - Ana Arduino kaynak kodu.
- `README.md` - Proje dokümantasyonu.
- `.gitattributes` - Git yapılandırma dosyası.

## 🤝 Katkıda Bulunanlar

Bu projeye katkıda bulunan herkese teşekkürler!

- [aayggun](https://github.com/aayggun) (Sahibi)
- [oguztntoglu](https://github.com/oguztntoglu)
- [ayhancıydem](https://github.com/ayhanciydem)

*(Not: Bu listede görünmek için depoya commit göndermiş olmanız gerekir.)*

## 📄 Lisans

Bu proje açık kaynaklıdır ve [MIT Lisansı](LICENSE) altında sunulmaktadır.
