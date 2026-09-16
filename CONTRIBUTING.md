# Contributing

This is primarily a personal learning/portfolio repository, but issues and
pull requests are welcome — especially bug reports on the register-level
driver code in `projects/04-gpio-spi-drivers/drivers/`.

## Reporting a bug

Please include:

- Which project (`projects/0X-...`) is affected
- MCU/board used
- Expected vs. actual behavior
- Relevant register values or a minimal repro snippet if possible

## Submitting changes

1. Fork the repository and create a branch from `main`.
2. Keep changes scoped to a single project/driver where possible.
3. Match the existing code style (register-level C, no HAL/LL in
   `projects/01`–`04`).
4. Open a pull request describing what changed and why.

## Code style

- English comments only.
- Prefer named bit-field `#define`s over magic numbers when adding new
  register definitions.
- Keep driver headers (`Inc/`) and sources (`Src/`) in sync — public API
  changes in a `.h` should be reflected in the matching `.c`.
