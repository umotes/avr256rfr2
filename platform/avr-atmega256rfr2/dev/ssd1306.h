#ifndef SSD1306_H_INCLUDED
 #define SSD1306_H_INCLUDED
 
// #include "contiki.h"
// #include "contiki-conf.h"
 #include "conf_ssd1306.h"
 #include "avr/io.h"
// #include "dev/clock-avr.h"

    // controller and OLED configuration file


  #define SSD_DC_PORT           PORTE
  #define SSD_DC_DIR            DDRE
  #define SSD_DC_PIN            PORTE2

  #define SSD_RES_PORT          PORTD
  #define SSD_RES_DIR           DDRD
  #define SSD_RES_PIN           PORTD5

  #define SSD_CS_PORT           PORTG
  #define SSD_CS_DDR            DDRG
  #define SSD_CS_PIN            PORTG0

  #define SSD_MOSI_PORT         PORTB
  #define SSD_MOSI_DIR          DDRB
  #define SSD_MOSI_PIN          PORTB2

  #define SSD_MISO_PORT         PORTB
  #define SSD_MISO_DIR          DDRB
  #define SSD_MISO_PIN          PORTB3

  #define SSD_CLK_PORT          PORTB
  #define SSD_CLK_DIR           DDRB
  #define SSD_CLK_PIN           PORTB1
 
  #define SCK          UG_2832HSWEG04_SPI_SCK      //    1  /* - Output: SPI Serial Clock (SCLK) - ATMEGA128 PORTB, PIN1 */
  #define MOSI         UG_2832HSWEG04_SPI_MOSI // 2  /* - Output: SPI Master out - slave in (MOSI) - ATMEGA128 PORTB, PIN2 */
  #define MISO         UG_2832HSWEG04_SPI_MISO   // 3  /* - Input:  SPI Master in - slave out (MISO) - ATMEGA128 PORTB, PIN3 */
  #define CSN          SSD1306_CS_PIN
 
  #define UG_2832HSWEG04_DATA_CMD   SSD_DC_PIN
  #define UG_2832HSWEG04_RESET      SSD_RES_PIN
  #define UG_2832HSWEG04_SS         SSD_CS_PIN
  #define UG_2832HSWEG04_SPI_SCK    SSD_CLK_PIN
  #define UG_2832HSWEG04_SPI_MOSI   SSD_MOSI_PIN
  #define UG_2832HSWEG04_SPI_MISO   SSD_MISO_PIN

  #define SSD1306_DC_PIN          UG_2832HSWEG04_DATA_CMD
  #define SSD1306_RES_PIN         UG_2832HSWEG04_RESET
  #define SSD1306_CS_PIN          UG_2832HSWEG04_SS

  #define SSD1306_LATENCY 10
  #define SPI_TXBUF SPDR
  #define SPI_RXBUF SPDR
  #define BV(bitno) (1<<bitno)

  #define SPI_WAITFOREOTx() do { while (!(SPSR & BV(SPIF))); } while (0)
  #define SPI_WAITFOREORx() do { while (!(SPSR & BV(SPIF))); } while (0)

  //OLED  Display Properties
  #define UG_2832HSWEG04_BAUDRATE  12000000
  #define SSD1306_CLOCK_SPEED      UG_2832HSWEG04_BAUDRATE
  #define SSD1306_DISPLAY_CONTRAST_MAX 40
  #define SSD1306_DISPLAY_CONTRAST_MIN 30
  #define LCD_WIDTH_PIXELS      128
  #define LCD_HEIGHT_PIXEl              32
 

 
 #define SSD1306_CMD_SET_LOW_COL(column)             (0x00 | (column))
 #define SSD1306_CMD_SET_HIGH_COL(column)            (0x10 | (column))
 #define SSD1306_CMD_SET_MEMORY_ADDRESSING_MODE      0x20
 #define SSD1306_CMD_SET_COLUMN_ADDRESS              0x21
 #define SSD1306_CMD_SET_PAGE_ADDRESS                0x22
 #define SSD1306_CMD_SET_START_LINE(line)            (0x40 | (line))
 #define SSD1306_CMD_SET_CONTRAST_CONTROL_FOR_BANK0  0x81
 #define SSD1306_CMD_SET_CHARGE_PUMP_SETTING         0x8D
 #define SSD1306_CMD_SET_SEGMENT_RE_MAP_COL0_SEG0    0xA0
 #define SSD1306_CMD_SET_SEGMENT_RE_MAP_COL127_SEG0  0xA1
 #define SSD1306_CMD_ENTIRE_DISPLAY_AND_GDDRAM_ON    0xA4
 #define SSD1306_CMD_ENTIRE_DISPLAY_ON               0xA5
 #define SSD1306_CMD_SET_NORMAL_DISPLAY              0xA6
 #define SSD1306_CMD_SET_INVERSE_DISPLAY             0xA7
 #define SSD1306_CMD_SET_MULTIPLEX_RATIO             0xA8
 #define SSD1306_CMD_SET_DISPLAY_ON                  0xAF
 #define SSD1306_CMD_SET_DISPLAY_OFF                 0xAE
 #define SSD1306_CMD_SET_PAGE_START_ADDRESS(page)    (0xB0 | (page & 0x07))
 #define SSD1306_CMD_SET_COM_OUTPUT_SCAN_UP          0xC0
 #define SSD1306_CMD_SET_COM_OUTPUT_SCAN_DOWN        0xC8
 #define SSD1306_CMD_SET_DISPLAY_OFFSET              0xD3
 #define SSD1306_CMD_SET_DISPLAY_CLOCK_DIVIDE_RATIO  0xD5
 #define SSD1306_CMD_SET_PRE_CHARGE_PERIOD           0xD9
 #define SSD1306_CMD_SET_COM_PINS                    0xDA
 #define SSD1306_CMD_SET_VCOMH_DESELECT_LEVEL        0xDB
 #define SSD1306_CMD_NOP                             0xE3
 
 
 #define SSD1306_CMD_SCROLL_H_RIGHT                  0x26
 #define SSD1306_CMD_SCROLL_H_LEFT                   0x27
 #define SSD1306_CMD_CONTINUOUS_SCROLL_V_AND_H_RIGHT 0x29
 #define SSD1306_CMD_CONTINUOUS_SCROLL_V_AND_H_LEFT  0x2A
 #define SSD1306_CMD_DEACTIVATE_SCROLL               0x2E
 #define SSD1306_CMD_ACTIVATE_SCROLL                 0x2F
 #define SSD1306_CMD_SET_VERTICAL_SCROLL_AREA        0xA3
 
 
 
 void ssd1306_reset_clear(void)
 	{	
        SSD_RES_DIR |= (1<<SSD1306_RES_PIN); // Reset Pin is set as Output
        SSD_RES_PORT|= (1<<SSD1306_RES_PIN); // Reset  Pin Pulled Low
 	}


 void ssd1306_reset_set(void)
 	{
        SSD_RES_DIR |= (1<<SSD1306_RES_PIN); // Reset Pin is set as Output
        SSD_RES_PORT&= ~(1<<SSD1306_RES_PIN); // Reset  Pin Pulled Low

 	}


 void ssd1306_sel_data(void)
	{	
//Set High  for Data
        SSD_DC_DIR |= (1<<SSD1306_DC_PIN); // Reset Pin is set as Output
        SSD_DC_PORT&=~(1<<SSD1306_DC_PIN); // Reset  Pin Pulled Low

	}
 
 void ssd1306_sel_cmd(void)
        {
//Low for COmmand
        SSD_RES_DIR |= (1<<SSD1306_DC_PIN); // Reset Pin is set as Output
    	SSD_RES_PORT|= (1<<SSD1306_DC_PIN); // Reset        Pin Pulled Low

        }

 void spi_deselect_device(void)
        {
    	SSD_CS_DDR |= (1<<SSD1306_CS_PIN);
        SSD_CS_PORT|= (1<<SSD1306_CS_PIN);

        }

 void spi_select_device(void)
         {
        SSD_CS_DDR |= (1<<SSD1306_CS_PIN);
        SSD_CS_PORT &= ~(1<<SSD1306_CS_PIN);

 	}

 void spi_write_single(unsigned char data )
	{
	SPDR=data;
	SPI_WAITFOREOTx();
	}
 

 static inline void ssd1306_write_command(uint8_t command)
 {
     spi_select_device();
     ssd1306_sel_cmd();
     spi_write_single(command);
  //    delay_us(SSD1306_LATENCY); // At lest 3?s

     clock_delay_usec(SSD1306_LATENCY);
     spi_deselect_device();

} 
 static inline void ssd1306_write_data(uint8_t data)
 {
 
    spi_select_device();
    ssd1306_sel_data();
    spi_write_single(data);
    clock_delay_usec(SSD1306_LATENCY);
    spi_deselect_device();

 }
 
 static inline uint8_t ssd1306_read_data(void)
 {
     return 0;
 }
 
 static inline uint8_t ssd1306_get_status(void)
 {
     return 0;
 }
 
 
 
 static inline void ssd1306_hard_reset(void)
 {
   ssd1306_reset_clear();
        //ioport_set_pin_low(SSD1306_RES_PIN);
   clock_delay_usec(SSD1306_LATENCY);
   ssd1306_reset_set();
   //  ioport_set_pin_high(SSD1306_RES_PIN);
   clock_delay_usec(SSD1306_LATENCY);
 }
 
 
 
 static inline void ssd1306_sleep_enable(void)
 {
     ssd1306_write_command(SSD1306_CMD_SET_DISPLAY_OFF);
 }
 
 static inline void ssd1306_sleep_disable(void)
 {
     ssd1306_write_command(SSD1306_CMD_SET_DISPLAY_ON);
 }
 
 
 
 static inline void ssd1306_set_page_address(uint8_t address)
 {
     // Make sure that the address is 4 bits (only 8 pages)
     address &= 0x0F;
     ssd1306_write_command(SSD1306_CMD_SET_PAGE_START_ADDRESS(address));
 }
 
 static inline void ssd1306_set_column_address(uint8_t address)
 {
     // Make sure the address is 7 bits
     address &= 0x7F;
     ssd1306_write_command(SSD1306_CMD_SET_HIGH_COL(address >> 4));
     ssd1306_write_command(SSD1306_CMD_SET_LOW_COL(address & 0x0F));
 }
 
 static inline void ssd1306_set_display_start_line_address(uint8_t address)
 {
     // Make sure address is 6 bits
     address &= 0x3F;
     ssd1306_write_command(SSD1306_CMD_SET_START_LINE(address));
 }
 
 
 
 static inline void ssd1306_display_on(void)
 {
     ssd1306_write_command(SSD1306_CMD_SET_DISPLAY_ON);
 }
 
 static inline void ssd1306_display_off(void)
 {
     ssd1306_write_command(SSD1306_CMD_SET_DISPLAY_OFF);
 }
 
 static inline uint8_t ssd1306_set_contrast(uint8_t contrast)
 {
     ssd1306_write_command(SSD1306_CMD_SET_CONTRAST_CONTROL_FOR_BANK0);
     ssd1306_write_command(contrast);
     return contrast;
 }
 
 static inline void ssd1306_display_invert_enable(void)
 {
     ssd1306_write_command(SSD1306_CMD_SET_INVERSE_DISPLAY);
 }
 
 static inline void ssd1306_display_invert_disable(void)
 {
     ssd1306_write_command(SSD1306_CMD_SET_NORMAL_DISPLAY);
 }
 
 static inline void ssd1306_clear(void)
 {
     uint8_t page = 0;
     uint8_t col = 0;
 
     for (page = 0; page < 4; ++page)
     {
         ssd1306_set_page_address(page);
         ssd1306_set_column_address(0);
         for (col = 0; col < 128; ++col)
         {
             ssd1306_write_data(0x00);
         }
     }
 }
 
 
 void ssd1306_init(void);
 
 
 void ssd1306_write_text(const char *string);
 
 #ifdef __cplusplus
 }
 #endif
 
 #endif /* SSD1306_H_INCLUDED */
