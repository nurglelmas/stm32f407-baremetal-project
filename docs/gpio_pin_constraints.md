# GPIO Electrical Constraints and Design Notes (STM32F407)

This document summarizes critical GPIO electrical constraints considered
during bare-metal driver development for the STM32F407 microcontroller.

The goal is to ensure safe hardware–software interfacing and avoid
electrical overstress or undefined MCU behavior.

---

## GPIO Pin Classification

STM32 GPIO pins are classified based on input voltage tolerance:

- **TT (Three-Volt Tolerant) Pins**
  - Maximum input voltage: `VDD + 0.3V`
  - Not tolerant to 5V signals
  - STM32F407 examples: `PA4`, `PA5`

- **FT (Five-Volt Tolerant) Pins**
  - 5V tolerance applies **only in input mode**
  - Not valid for output or analog modes
  - General operating Vin range: `-0.3V to 5.5V`

---

## Unpowered MCU Input Considerations

Special care was taken for scenarios where external devices may drive
GPIO pins while the MCU is unpowered (`VDD = 0`).

- **TT pins**:  
  - `Vin ≤ 0.3V`

- **FT pins**:  
  - `Vin ≤ 4.0V`

Driving GPIO pins beyond these limits may forward-bias internal protection
diodes and permanently damage the MCU.

---

## Design Implications

The following design rules were applied during driver development:

- GPIO mode configuration is validated before enabling peripherals
- 5V signals are applied only to FT pins configured in input mode
- No external signal is allowed to drive GPIOs while the MCU is unpowered
- Datasheet *General Operating Conditions* are prioritized over AMR values

---

## Engineering Rationale

Understanding and applying GPIO electrical limits is essential for
robust embedded system design, especially in mixed-voltage environments
and safety-critical applications.

