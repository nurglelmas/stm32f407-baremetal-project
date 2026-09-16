# 03 — HSI Clock Measurement

Routes the internal high-speed oscillator (HSI) out through `MCO1` on `PA8`
for measurement, mirroring project 02 but without switching to an external
crystal.

- **Target:** STM32F407
- **Entry point:** `Src/main.c`
- **Key registers:** `RCC_CFGR`, `RCC_AHB1ENR`, `GPIOA_MODER`, `GPIOA_AFRH`
- **Measurement pin:** PA8 (MCO1), divided by 4

## Build

Import this folder into STM32CubeIDE (**File → Open Projects from File
System…**), then Build and flash normally.

See the [main README](../../README.md#03--hsi-clock-measurement) for
context on how this fits into the rest of the repository.
