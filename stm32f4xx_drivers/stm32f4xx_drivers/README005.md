# STM32F407 Button Interrupt (EXTI) Example

This project demonstrates how to control an LED using a push button with **external interrupts (EXTI)** on the STM32F407 microcontroller.

Instead of continuously polling the button state, the system uses **interrupt-driven GPIO**, which is the preferred approach in real-time embedded systems.

---

## 🧠 Why Interrupts Instead of Polling?

### Polling (GPIO Read)
- The CPU continuously checks the button state
- Wastes CPU cycles
- Not power-efficient
- Not suitable for real-time or multi-task systems

### Interrupt-Based Approach (EXTI)
- The CPU remains idle or performs other tasks
- Button press triggers an interrupt automatically
- More efficient and responsive
- Commonly used in professional embedded systems

In this project, the button press generates an **EXTI interrupt**, and the LED state is toggled inside the corresponding **IRQ handler**.

---

## ⚙️ Project Overview

- **MCU**: STM32F407
- **LED Pin**: PD12
- **Button Pin**: PA0
- **Trigger Type**: Falling Edge
- **Pull Configuration**: Internal Pull-Up
- **Interrupt Line**: EXTI0
- **IRQ Handler**: `EXTI0_IRQHandler`

---

## 🔧 How It Works

1. The button is configured as an external interrupt input.
2. EXTI is mapped to the correct GPIO port via `SYSCFG_EXTICR`.
3. NVIC is configured to enable the EXTI interrupt.
4. When the button is pressed:
   - The EXTI interrupt is triggered
   - The pending bit is cleared
   - The LED is toggled inside the IRQ handler
---

## 🛠 Debug & Pointer Fix Notes

During the lesson, I learned that incrementing a `uint32_t *` pointer multiplies the increment by 4 automatically.  
Previously, we multiplied by 4 manually, causing incorrect register addressing.  
This has been fixed in the GPIO driver code.

- Use `NVIC_PR_BASE_ADDR` directly instead of manually adjusting the address.  
- Ensure that EXTI IRQ handlers toggle the LED correctly.  

These notes complement the previous explanation and demonstration video of the button-controlled LED using interrupts.

---

## 🎥 Demo Video

A short demonstration video showing the button-controlled LED using interrupts is included below.
![Button Interrupt Demo](media005/005Button_interrupt.gif)


