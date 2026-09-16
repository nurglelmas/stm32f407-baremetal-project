# 04 — GPIO / SPI Driver Library

The core of this repository: a reusable, register-level GPIO and SPI driver
library for the STM32F407, plus example applications built on top of it.

- **Target:** STM32F407
- **Driver library:** `drivers/Inc/`, `drivers/Src/`
  - `stm32f407xx.h` — memory map, peripheral base addresses, bit definitions
  - `stm32f407xx_gpio_driver.[c|h]` — GPIO init/read/write/interrupt handling
  - `stm32f407xx_spi_driver.[c|h]` — SPI init/send/receive, interrupt handling
- **Examples:** `Src/001led_toggle.c` … `Src/007spi_txonly_stm.c`

## Switching the active example

STM32CubeIDE only compiles one `main()` at a time. All example files except
the currently active one are excluded from the build:
**right-click a file → Resource Configurations → Exclude from Build**.
To run a different example, exclude the current one and include the file you
want instead.

| File | What it does |
|---|---|
| `001led_toggle.c` | Basic GPIO output — toggles an LED |
| `002led_button.c` | Polls an onboard button to control the LED |
| `003led_button_ext.c` | Same, with an externally wired button and debounce |
| `005button_interrupt.c` | EXTI + NVIC — interrupt-driven button handling |
| `006spi_tx_testing.c` | Bring-up test for the SPI driver |
| `007spi_txonly_stm.c` | Sends data over SPI to the F103 slave (project 05) |

## Build

Import this folder into STM32CubeIDE (**File → Open Projects from File
System…**), then Build and flash normally.

See the [main README](../../README.md#04--gpio--spi-driver-library) for demo
GIFs and further context.
