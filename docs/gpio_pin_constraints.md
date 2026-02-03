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
