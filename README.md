# STM32 GPIO Button Interrupt with Debounce

## Overview
This project demonstrates interrupt-driven GPIO input handling on the STM32L475
microcontroller using EXTI and software debouncing. The design avoids polling and
blocking delays, resulting in responsive and deterministic button handling suitable
for real embedded systems.

The project emphasizes clean firmware architecture, ISR minimization, and clear
separation between hardware abstraction and application logic.

---

## Target Platform
- MCU: STM32L475VGT6 (ARM Cortex-M4F)
- Board: B-L475E-IOT01A (STM32 IoT Discovery)
- Button: PC13 (User Button)
- LED: PB14 (User LED)

---

## Software Environment
- STM32CubeIDE
- STM32CubeMX
- STM32 HAL (L4 series)

---

## Design Objectives
- Implement GPIO input using EXTI interrupts
- Eliminate polling-based button detection
- Handle mechanical button bounce in software
- Keep interrupt service routines minimal and deterministic
- Provide a clean, reusable button driver interface

---

## Key Concepts Demonstrated
- EXTI-based GPIO interrupts
- Software debouncing using system tick timing
- ISR-to-driver event forwarding
- Separation of ISR logic and application logic
- Push-button electrical behavior (pull-up + falling edge)

---

## Firmware Architecture
The firmware is structured into clearly defined layers:

- **Application Layer (`main.c`)**
  - Initializes the system
  - Reacts to button events
  - Contains no hardware-specific logic

- **Driver Layer**
  - `button.c` handles debouncing and event detection
  - `led.c` abstracts LED control

- **HAL Layer**
  - Manages low-level peripheral configuration and interrupts

HAL EXTI callbacks are forwarded to the button driver to maintain ISR cleanliness
and modularity.

---

## GPIO and Interrupt Configuration
- Button input configured with internal pull-up
- EXTI triggered on falling edge (button press)
- Interrupt priority configured explicitly via NVIC
- LED configured as push-pull output with low slew rate

---

## Build and Run
1. Open the `.ioc` file in STM32CubeMX
2. Generate code for STM32CubeIDE
3. Build and flash the project
4. Press the user button to toggle the LED

---

## Design Limitations
- Single-button support
- Debounce timing is fixed at compile time
- Blocking delays are avoided, but no RTOS is used

---

## Possible Extensions
- Support multiple buttons
- Make debounce time configurable
- Integrate low-power sleep modes
- Replace system tick timing with hardware timers
- Add RTOS task notification support

---

## Author
**Gurnoor Singh**  
Embedded Systems | Firmware Development | MCU Software
