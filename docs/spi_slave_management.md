# SPI Slave Management in STM32 Microcontrollers

This document explains the two types of SPI slave (NSS) management supported by STM32 microcontrollers:
software slave management and hardware slave management. Understanding these concepts is essential for
reliable SPI communication, especially when developing bare-metal drivers.

---

## Overview

In SPI communication, the slave device becomes active only when its **NSS (Slave Select)** signal is asserted.
STM32 devices allow this signal to be managed either internally by software or externally by hardware.

The selection is controlled using the **SSM (Software Slave Management)** bit in the SPI control register.

---

## Software Slave Management (SSM)

In software slave management, the external NSS pin is not used.  
Instead, the slave select signal is controlled internally by the SPI peripheral.

### Configuration

- `SSM = 1` → Software slave management enabled
- `SSI` bit controls the internal NSS level

### Behavior

- `SSI = 0` → NSS internally driven LOW (slave selected)
- `SSI = 1` → NSS internally driven HIGH (slave not selected)

When `SSM = 1` and `SSI = 0`, the slave is considered **always selected**, allowing communication
without using the physical NSS pin.

### Use Cases

- Single master, single slave systems
- Simple SPI topologies
- Bare-metal driver development where NSS timing is not critical

This is the most commonly used approach in basic STM32 SPI examples.

---

## Hardware Slave Management

In hardware slave management, the NSS pin is physically used and controlled externally.

### Configuration

- `SSM = 0`
- `SSI` bit is ignored
- NSS pin must be driven by hardware (usually the master)

### Behavior

- NSS = LOW → Slave is active
- NSS = HIGH → Slave is inactive (Hi-Z state)

The slave will not participate in communication unless NSS is asserted LOW.

### Use Cases

- Systems requiring strict hardware control
- Designs where NSS timing must be precise
- Multi-slave SPI configurations

---

## Multi-Slave SPI Systems

When a single master communicates with multiple slaves:

- Software slave management **cannot be used**
- Each slave must have a dedicated NSS line
- NSS signals are typically driven using GPIO pins from the master

### Example

- GPIO1 → Slave 1 NSS
- GPIO2 → Slave 2 NSS
- GPIO3 → Slave 3 NSS

To select a slave:
- Drive its NSS LOW
- Keep all other NSS lines HIGH

Unselected slaves remain in a high-impedance state and do not interfere with the bus.

---

## Master NSS Pin Considerations

In multi-slave configurations:

- The master’s NSS pin is usually not used
- If configured as NSS (alternate function), it should be tied to VDD
- Alternatively, it can be left unconfigured and used as a regular GPIO

---

## Key Takeaways

- `SSM = 1` enables software slave management
- `SSI` controls the internal NSS level when SSM is enabled
- Software NSS is suitable only for single-slave systems
- Hardware NSS is mandatory for multi-slave SPI designs
- Incorrect NSS handling is a common cause of SPI communication failures

---

This document reflects practical considerations encountered during STM32 bare-metal SPI driver development.

