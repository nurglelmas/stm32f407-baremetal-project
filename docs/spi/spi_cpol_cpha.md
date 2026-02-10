# SPI Clock Polarity (CPOL) and Clock Phase (CPHA)

This document is a personal learning note about SPI clock configuration
in STM32F407 (bare-metal).

## Why CPOL and CPHA Matter
Master and slave devices must use the same SPI mode. Otherwise,
data corruption or invalid sampling may occur.

## CPOL – Clock Polarity
- CPOL = 0 → SCK idle low
- CPOL = 1 → SCK idle high

## CPHA – Clock Phase
- CPHA = 0 → Data sampled on leading edge
- CPHA = 1 → Data sampled on trailing edge

## SPI Modes Summary

| Mode | CPOL | CPHA | Idle State | Sampling Edge |
|------|------|------|------------|---------------|
| 0 | 0 | 0 | Low | Rising (1st edge) |
| 1 | 0 | 1 | Low | Falling (2nd edge) |
| 2 | 1 | 0 | High | Falling (1st edge) |
| 3 | 1 | 1 | High | Rising (2nd edge) |

## Sampling Rule (Interview Friendly)
- CPHA = 0 → Leading edge
- CPHA = 1 → Trailing edge

## References
- STM32F407 Reference Manual – SPI section
- Personal learning notes

