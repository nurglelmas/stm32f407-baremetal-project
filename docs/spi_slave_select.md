# SPI Communication – Master & Slave Selection

- SPI communication requires **both master and slave devices to support SPI**.  
  - If the slave does not support SPI, communication will fail.  

- **Slave selection (Slave Select – SS)** is a critical step in SPI:  
  1. The master selects the slave by pulling the slave's SS pin **to ground**.  
  2. Until the SS pin is grounded, the slave’s data lines remain in **HI-Z (high impedance)** state.  
     - This means the slave is not ready to send or receive data.  
  3. Once SS is pulled low, the slave activates its data lines and communication can proceed.  

- In SPI, **the clock (SCK) signal is sent along with the data**.  
  - All data communication is synchronized with this clock signal.  

- **Key takeaway:** The slave’s SS pin must be pulled to ground to enable communication.  
  - Without this, the slave’s pins remain in high impedance, and no data transfer occurs.

