# 02 — HSE Clock Measurement

Enables the external oscillator (HSE), waits for `HSERDY`, switches the
system clock to HSE, then routes it out through `MCO1` on `PA8` for
measurement with a scope or logic analyzer.

- **Target:** STM32F407
- **Entry point:** `Src/main.c`
- **Key registers:** `RCC_CR`, `RCC_CFGR`, `RCC_AHB1ENR`, `GPIOA_MODER`, `GPIOA_AFRH`
- **Measurement pin:** PA8 (MCO1), divided by 4

## Build

Import this folder into STM32CubeIDE (**File → Open Projects from File
System…**), then Build and flash normally.

See the [main README](../../README.md#02--hse-clock-measurement) for
context on how this fits into the rest of the repository.
