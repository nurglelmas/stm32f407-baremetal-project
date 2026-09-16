# 05 — SPI Slave (STM32F103C8T6)

An STM32F103C8T6 configured as an SPI slave that receives data from the
STM32F407 master in [project 04](../04-gpio-spi-drivers) and toggles its
onboard LED on each message.

- **Target:** STM32F103C8T6
- **Entry point:** `Src/main.c`

**Configuration**

| Setting | Value |
|---|---|
| SPI mode | Slave |
| Clock | 8 MHz |
| NSS | Hardware-controlled |

**Connections**

| STM32F103 Pin | SPI Function |
|---|---|
| PB12 | NSS |
| PB13 | SCLK |
| PB14 | MISO |
| PB15 | MOSI |

> **Note:** unlike every other project in this repository, this one is
> generated from STM32CubeMX and links against ST's `STM32F1xx_HAL_Driver`
> (see `Drivers/`). This is intentional — it exists to provide a realistic
> communication partner for the register-level SPI master in project 04. The
> bundled vendor HAL/CMSIS files retain ST's own license terms.

## Build

Import this folder into STM32CubeIDE (**File → Open Projects from File
System…**), then Build and flash normally.

See the [main README](../../README.md#05--spi-slave-stm32f103c8t6) for demo
media and wiring photos.
