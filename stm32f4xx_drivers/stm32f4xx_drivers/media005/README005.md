# STM32F407 Button Interrupt (EXTI) Example

This project demonstrates how to control an LED using a push button with
**external interrupts (EXTI)** on the STM32F407 microcontroller.

Instead of continuously polling the button state, the system uses
**interrupt-driven GPIO**, which is the preferred approach in real-time
embedded systems.

---

## 🧠 Why Interrupts Instead of Polling?

**Polling**
- CPU continuously checks button state
- Inefficient CPU usage
- Not suitable for real-time systems

**Interrupt-Based (EXTI)**
- CPU runs freely until an event occurs
- Button press triggers an interrupt
- Efficient and responsive
- Used in professional embedded systems

---

## ⚙️ Project Configuration

- **MCU**: STM32F407
- **LED Pin**: PD12
- **Button Pin**: PA0
- **Trigger**: Falling edge
- **Pull-up**: Internal
- **EXTI Line**: EXTI0
- **IRQ Handler**: `EXTI0_IRQHandler`

---

## 🔧 How It Works

1. Button pin is configured as external interrupt input.
2. EXTI line is mapped using SYSCFG.
3. NVIC interrupt is enabled.
4. On button press:
   - EXTI interrupt is triggered
   - Pending bit is cleared
   - LED toggles inside the IRQ handler

---

## 🎬 Demo GIF

![Button Interrupt Demo](media005/button_interrupt.gif)

---

## 📌 Notes

- This project avoids GPIO polling to improve CPU efficiency.
- Proper EXTI and NVIC configuration is essential.
- Suitable as a bare-metal STM32 interrupt example.

