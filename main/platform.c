/*
 * Copyright (c) Riverdi Sp. z o.o. sp. k. <contact@riverdi.com>
 * Copyright (c) Skalski Embedded Technologies <contact@lukasz-skalski.com>
 */

#include "platform.h"

#include "pico/stdlib.h"
#include "hardware/spi.h"

/*
 * platform_init()
 */
bool_t
platform_init (Gpu_HalInit_t *halinit)
{
  stdio_init_all();
  return TRUE;
}

/*
 * platform_sleep_ms()
 */
void
platform_sleep_ms (uint32_t ms)
{
  sleep_ms(ms);
  return;
}

/*
 * platform_spi_init()
 */
bool_t
platform_spi_init (Gpu_Hal_Context_t *host)
{
  spi_init(SPI_DEVICE, SPI_SPEED_HZ);

  gpio_set_function(GPIO_MISO, GPIO_FUNC_SPI);
  gpio_set_function(GPIO_SCLK, GPIO_FUNC_SPI);
  gpio_set_function(GPIO_MOSI, GPIO_FUNC_SPI);

  return TRUE;
}

/*
 * platform_spi_deinit()
 */
void
platform_spi_deinit (Gpu_Hal_Context_t *host)
{
  return;
}

/*
 * platform_spi_send_recv_byte();
 */
uchar8_t
platform_spi_send_recv_byte (Gpu_Hal_Context_t  *host,
                             uchar8_t            data,
                             uint32_t            opt)
{
  uint8_t in_buf[1];

  spi_write_read_blocking(SPI_DEVICE, &data, in_buf, 1);

  return in_buf[0];
}

/*
 * platform_spi_send_data()
 */
uint16_t
platform_spi_send_data (Gpu_Hal_Context_t  *host,
                        uchar8_t           *data,
                        uint16_t            size,
                        uint32_t            opt)
{
  spi_write_blocking(SPI_DEVICE, data, size);
  return size;
}

/*
 * platform_spi_recv_data()
 */
void
platform_spi_recv_data (Gpu_Hal_Context_t  *host,
                        uchar8_t           *data,
                        uint16_t            size,
                        uint32_t            opt)
{
  /* intentionally empty */
  return;
}

/*
 * platform_gpio_init()
 */
bool_t
platform_gpio_init (Gpu_Hal_Context_t *host,
                    gpio_name          ngpio)
{
  gpio_init(ngpio);
  gpio_set_dir(ngpio, GPIO_OUT);
  return TRUE;
}

/*
 * platform_gpio_value()
 */
bool_t
platform_gpio_value (Gpu_Hal_Context_t  *host,
                     gpio_name           ngpio,
                     gpio_val            vgpio)
{
  gpio_put(ngpio, vgpio);
  return TRUE;
}
