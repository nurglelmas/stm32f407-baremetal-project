
## 🛠️ Driver Update & Debug Notes

- GPIO driver kodunda bir pointer aritmetiği problemi tespit edildi:  
  `uint32_t*` tipindeki pointer üzerinde yapılan increment işlemleri beklenenden 4 kat fazla adres artışına sebep oluyordu.
- Çözüm: `iprx * 4` çarpımı kaldırıldı ve pointer doğru adresi gösterecek şekilde güncellendi.  
- NVIC_PR_BASE_ADDR kullanılarak doğru I/O register erişimi sağlandı.
- Debug ve test:
  - Pointer adresleri ve I/O register değerleri adım adım kontrol edildi.
  - Örneğin, ilgili register’a yazılan değer `15` doğru sekmede yer aldı.
- Not: GPIO driver’da **alternate functionality** henüz test edilmedi; bu testler diğer periferaller (I2C, SPI vb.) ile yapılacaktır.


## 🛠️ Driver Update & Debug Notes

- GPIO driver kodunda bir pointer aritmetiği problemi tespit edildi:  
  `uint32_t*` tipindeki pointer üzerinde yapılan increment işlemleri beklenenden 4 kat fazla adres artışına sebep oluyordu.
- Çözüm: `iprx * 4` çarpımı kaldırıldı ve pointer doğru adresi gösterecek şekilde güncellendi.  
- NVIC_PR_BASE_ADDR kullanılarak doğru I/O register erişimi sağlandı.
- Debug ve test:
  - Pointer adresleri ve I/O register değerleri adım adım kontrol edildi.
  - Örneğin, ilgili register’a yazılan değer `15` doğru sekmede yer aldı.
- Not: GPIO driver’da **alternate functionality** henüz test edilmedi; bu testler diğer periferaller (I2C, SPI vb.) ile yapılacaktır.

