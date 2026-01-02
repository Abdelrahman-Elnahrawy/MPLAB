# Microchip MPLAB Projects 🛰️
**Firmware Development for PIC Microcontrollers**

![MCU](https://img.shields.io/badge/Architecture-PIC16_/_PIC18-red?style=for-the-badge&logo=microchip)
![IDE](https://img.shields.io/badge/IDE-MPLAB_X_v6.x-blue?style=for-the-badge&logo=microchip)
![Compiler](https://img.shields.io/badge/Compiler-XC8_/_XC16-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-AGPL--3.0-red?style=for-the-badge)

This repository is a central archive for my firmware development projects using the **MPLAB X IDE**. It focuses on low-level drivers, peripheral configuration using **MCC (MPLAB Code Configurator)**, and manual register-level programming for Microchip's PIC architecture.

---

## 🎯 Engineering Objectives
* **PIC Architecture Mastery:** Implementing firmware for 8-bit and 16-bit PIC microcontrollers.
* **Peripheral Integration:** Configuration of MSSP (I2C/SPI), EUSART, CCP (PWM), and ADC modules.
* **Power Management:** Implementing Sleep modes and Watchdog Timers for low-power applications.
* **Logic Simulation:** Utilizing MPLAB SIM and Proteus for logic validation.
---

## 🏗️ Hardware & Software Stack
* **Target MCUs:** PIC16F877A, PIC18F4550, and other common Microchip variants.
* **Compilers:** Microchip XC8 / XC16.
* **Programming Tools:** PICkit 3 / PICkit 4.
* **Frameworks:** MPLAB Code Configurator (MCC) and Harmony (for 32-bit).


---

🛠️ Typical Workflow
Peripherals Init: Configuring the internal oscillator and I/O pins.
Interrupt Service Routines (ISR): Handling time-critical events via Timer or External interrupts.
Application Loop: Managing the state machine for the specific project logic.
Debugging: Using the MPLAB IPE and PICkit for real-time hardware debugging.

👤 Author
Abdelrahman Elnahrawy Embedded Systems Developer

📄 License
This project is licensed under the GNU Affero General Public License v3.0 (AGPL-3.0). Copyleft Warning: Commercial use in networked services requires source disclosure.


### 💡 Tips for MPLAB Repos:
1. **The `.X` Folders:** Make sure you are uploading the entire `.X` folder so that you don't lose your compiler settings and project properties.
2. **Ignore Files:** Ensure your `.gitignore` excludes the `dist/` and `build/` folders to keep the repo clean and only save the source code.
