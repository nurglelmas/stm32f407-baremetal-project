# 01 — Peripheral Clock Enable

Register-level example that enables the peripheral clock for ADC1 via
`RCC_APB2ENR` and sets a bit in `ADC_CR1`, with no framework involved.

- **Target:** STM32F407
- **Entry point:** `Src/main.c`
- **Key registers:** `RCC_APB2ENR`, `ADC_CR1`

## Build

Import this folder into STM32CubeIDE (**File → Open Projects from File
System…**), then Build and flash normally.

See the [main README](../../README.md#01--peripheral-clock-enable) for
context on how this fits into the rest of the repository.
