# Embedded Driver Development – GPIO & Interrupt (Bare-Metal)

This directory contains **bare-metal embedded driver implementations** for the **STM32F4 (Cortex-M4)** series,  
developed as part of the **Udemy – Mastering Microcontroller and Embedded Driver Development (Kiran Nayak)** course.

All peripherals are configured using **direct register-level access**, without relying on HAL or vendor abstraction layers.

---

## Technical Scope
- ARM Cortex-M architecture fundamentals  
- Memory map and memory-mapped I/O  
- Volatile usage and direct register access  
- RCC clock configuration  
- GPIO configuration (mode, pull-up/down, output type)  
- Polling vs interrupt-driven design  
- EXTI (External Interrupt) configuration  
- NVIC interrupt enabling and priority management  
- Interrupt Service Routine (ISR) design principles  

---

## Development Environment
- Language: **C**
- Target: **ARM Cortex-M (STM32F4 series)**
- IDE: **STM32CubeIDE**
- Programming model: **Bare-metal / Register-level**

---

## Design Notes
- No HAL or high-level libraries used  
- Peripheral registers accessed directly via memory-mapped addresses  
- ISRs kept minimal to follow real-time embedded best practices  

---

## Purpose
This module focuses on building a **strong low-level understanding of STM32 peripherals**,  
interrupt handling, and hardware–software interaction required in production-grade embedded systems.

---

## Status
Ongoing – additional peripherals such as **Timers, UART, and SPI** will be added.

