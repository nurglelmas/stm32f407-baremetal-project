# GPIO Electrical Constraints and Design Notes (STM32F407)

This document summarizes critical GPIO electrical constraints considered during bare-metal driver development for the **STM32F407** microcontroller.

The goal is to ensure safe hardware–software interfacing and to avoid electrical overstress or undefined MCU behavior.

---

## GPIO Pin Classification

STM32 GPIO pins are classified based on their **input voltage tolerance**.

### TT (Three-Volt Tolerant) Pins
- Maximum input voltage: **VDD + 0.3V**
- **Not tolerant to 5V signals**
- STM32F407 examples: `PA4`, `PA5`

### FT (Five-Volt Tolerant) Pins
- 5V tolerance applies **only in input mode**
- Not valid for output or analog modes
- General operating input range: **-0.3V to 5.5V**

---

## Unpowered MCU Input Considerations (VDD = 0V)

Special care must be taken when external devices may drive GPIO pins while the MCU is unpowered.

- **TT pins:** `Vin ≤ 0.3V`
- **FT pins:** `Vin ≤ 4.0V`

⚠️ Driving GPIO pins beyond these limits may forward-bias internal protection diodes and permanently damage the MCU.

---

## Current Characteristics

### IVDD
- Total source current drawn from **VDD**
- **Maximum: 240mA**

### IVSS
- Total sink current into **VSS (GND)**
- **Maximum: 240mA**

### IIO (GPIO Pin Current)
- **Source current (IOH):**  
  Current flows from MCU pin to the external world  
  **Maximum: 25mA per pin**
- **Sink current (IOL):**  
  Current flows from an external source into MCU pin (towards VSS)  
  **Maximum: 25mA per pin**

When multiple GPIO pins source or sink current simultaneously, the **algebraic sum** must not exceed the **IVDD** or **IVSS** limits.

---

## Injection Current

Injection current occurs when a GPIO input voltage exceeds the supply rails.

- **Positive injection (Vin > VDD):**
  - Prohibited on FT pins
  - Maximum allowed: **0mA**
- **Negative injection (Vin < VSS):**
  - Maximum allowed: **-5mA**

⚠️ Injection current beyond specified limits can damage the MCU or reduce long-term reliability.

---

## LED Driving Example

- **Sourcing:**  
  GPIO set to HIGH → current flows from VDD through GPIO pin to the load
- **Sinking:**  
  GPIO set to LOW → current flows from external supply through the load into GPIO pin and then to VSS

---

## Design Implications

- GPIO pins must never source or sink more than their rated current
- Injection currents must be strictly avoided
- Total VDD/VSS current limits must be respected to ensure MCU longevity

---

## CMOS and TTL Logic Level Compatibility

STM32 GPIOs are **CMOS-based**, but their input logic thresholds are designed to be **TTL-compatible**. Understanding this distinction is essential when interfacing STM32 with external devices.

---

## CMOS Logic Levels

**CMOS (Complementary Metal-Oxide-Semiconductor)** is a modern digital circuit technology widely used in microcontrollers and low-power devices.

### Key Characteristics
- Logic thresholds are **relative to supply voltage (VDD)**
- Very low power consumption
- Used in most modern MCUs, including STM32

### CMOS Input Thresholds (Typical)
- **Logic LOW (VIL):** `0 – 0.3 × VDD`
- **Logic HIGH (VIH):** `0.7 × VDD – VDD`

Example (STM32, VDD = 3.3V):
- `VIL(max) ≈ 0.99V`
- `VIH(min) ≈ 2.31V`

---

## TTL Logic Levels

**TTL (Transistor-Transistor Logic)** is an older digital logic standard, historically operating at 5V.

### Key Characteristics
- Logic thresholds are **fixed**
- Higher power consumption than CMOS
- Still relevant for legacy device compatibility

### TTL Input Thresholds
- **Logic LOW:** `0 – 0.8V`
- **Logic HIGH:** `≥ 2.0V`

---

## What “CMOS and TTL Compatible” Means for STM32

This means that STM32 GPIO **inputs** can correctly interpret signals from:
- Other CMOS-based devices
- TTL-level devices (within voltage and current limits)

⚠️ This does **not** mean STM32 GPIO outputs generate TTL-level voltages.  
STM32 outputs follow **CMOS voltage levels relative to VDD**.

---

## Summary Table

| Feature | CMOS | TTL |
|------|------|-----|
| Logic thresholds | Relative to VDD | Fixed |
| Typical supply voltage | 1.8V – 3.3V | 5V |
| Power consumption | Low | Higher |
| Used in STM32 | Yes | Input compatible |

---

## Key Takeaway

Understanding GPIO electrical limits and CMOS–TTL logic level compatibility is essential when designing reliable STM32-based systems, especially in mixed-voltage environments. Ignoring these constraints can result in unreliable communication or permanent hardware damage.

