GPIO Electrical Constraints and Design Notes (STM32F407)

This document summarizes critical GPIO electrical constraints considered during bare-metal driver development for the STM32F407 microcontroller.

The goal is to ensure safe hardware–software interfacing and avoid electrical overstress or undefined MCU behavior.

GPIO Pin Classification

STM32 GPIO pins are classified based on input voltage tolerance:

TT (Three-Volt Tolerant) Pins
- Maximum input voltage: VDD + 0.3V
- Not tolerant to 5V signals
- STM32F407 examples: PA4, PA5

FT (Five-Volt Tolerant) Pins
- 5V tolerance applies only in input mode
- Not valid for output or analog modes
- General operating Vin range: -0.3V to 5.5V

Unpowered MCU Input Considerations
- TT pins: Vin ≤ 0.3V
- FT pins: Vin ≤ 4.0V
- Driving GPIO pins beyond these limits may forward-bias internal protection diodes and permanently damage the MCU.

Current Characteristics

- **IVDD**: Total source current drawn from VDD. Max 240mA.
- **IVSS**: Total sink current into VSS. Max 240mA.
- **IIO (GPIO pin current)**:
  - Source current (IOH): Current flows from MCU pin to external world. Max 25mA per pin.
  - Sink current (IOL): Current flows from external source into MCU pin (to VSS). Max 25mA per pin.
- When multiple pins are sourcing or sinking, the sum must not exceed IVDD or IVSS limits.

Injection Current

- Current forced into a pin by input voltage beyond supply rails:
  - Positive injection (Vin > VDD) – prohibited on FT pins, max 0mA
  - Negative injection (Vin < VSS) – max -5mA
- Injection current beyond limits can damage MCU or reduce reliability.

LED Example:

- Sourcing: GPIO HIGH → current flows from VDD through
- Sinking: GPIO LOW → current flows from external supply through pin into VSS

Design Implications

- GPIO pins must never source or sink more than rated current
- Injection currents must be avoided
- Current limits must be respected for safe operation and MCU longevity

## CMOS and TTL Logic Level Compatibility

STM32 microcontrollers use GPIO pins that are **CMOS-based**, but their input logic thresholds are designed to be **TTL-compatible**. Understanding the difference between CMOS and TTL logic levels is critical for safe and reliable interfacing with external devices.

---

### CMOS Logic Levels

**CMOS (Complementary Metal-Oxide-Semiconductor)** is a modern digital circuit technology widely used in microcontrollers, processors, and low-power devices.

#### Key Characteristics
- Logic thresholds are **relative to the supply voltage (VDD)**
- Very **low power consumption**
- Used in most modern MCUs, including STM32

#### CMOS Input Thresholds (Typical)
For a CMOS device:
- **Logic LOW (VIL):** 0 – 0.3 × VDD  
- **Logic HIGH (VIH):** 0.7 × VDD – VDD  

Example (STM32 with VDD = 3.3V):
- VIL(max) ≈ 0.99V  
- VIH(min) ≈ 2.31V  

This means CMOS logic levels scale with the supply voltage.

---

### TTL Logic Levels

**TTL (Transistor-Transistor Logic)** is an older digital logic standard, historically operating at 5V.

#### Key Characteristics
- Logic thresholds are **fixed**, not dependent on VDD
- Higher power consumption compared to CMOS
- Still relevant for compatibility with legacy devices

#### TTL Input Thresholds
- **Logic LOW:** 0 – 0.8V  
- **Logic HIGH:** ≥ 2.0V  

These fixed thresholds simplify interfacing but reduce flexibility across voltage domains.

---

### What “CMOS and TTL Compatible” Means for STM32

When STM32 documentation states that GPIOs are *CMOS and TTL compatible*, it means:

- STM32 GPIO inputs can correctly interpret signals from:
  - Other **CMOS-based devices**
  - **TTL-level devices** (within voltage and current limits)
- Input thresholds are selected to safely detect TTL HIGH and LOW levels

⚠️ This does **not** mean STM32 GPIO outputs generate TTL-level voltages.  
STM32 outputs follow **CMOS voltage levels** relative to VDD.

---

### Design Implications

- STM32 can **read TTL outputs**, but may not reliably **drive TTL inputs**
- Direct interfacing with 5V devices may require:
  - Logic level shifters
  - Series resistors
  - Protection diodes
- Extra caution is required when the STM32 is **unpowered (VDD = 0V)**

---

### Summary Table

| Feature | CMOS | TTL |
|------|------|-----|
| Logic thresholds | Relative to VDD | Fixed |
| Typical supply voltage | 1.8V – 3.3V | 5V |
| Power consumption | Low | Higher |
| Used in STM32 | Yes | Input compatible |

---

### Key Takeaway

Understanding CMOS and TTL logic level compatibility is essential when interfacing STM32 GPIOs with external peripherals, especially in mixed-voltage systems. Ignoring these constraints can lead to unreliable communication or permanent hardware damage.

