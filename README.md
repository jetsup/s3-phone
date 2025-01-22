# S3-Phone

S3-Phone is a simple MCU-based phone that uses the ESP32-S3 and the SIM800L module. It is designed to be a simple and easy-to-use phone that can be used for making and receiving calls and sending and receiving SMS messages. The phone also has a stylish and modern UI design that gives it a premium look and feel.

## Setup

**Note:** All the commands below are for _Linux_. If you are using _Windows_, you can use the _Windows_ equivalent commands.

### Software

1. Install PlatformIO.
2. Clone the repository.

    ```bash
    git clone https://www.github.com/jetsup/s3-phone
    ```

3. Copy the [Credentials.example.hpp](include/Credentials.example.hpp) file to `include/Credentials.hpp` and fill in the necessary credentials.
4. Copy [resources/lv_conf.sample.h](resources/lv_conf.sample.h) to `.pio/libdeps/4d_systems_esp32s3_gen4_r8n16/lv_conf.h`.
    ```bash
    cp resources/lv_conf.sample.h .pio/libdeps/4d_systems_esp32s3_gen4_r8n16/lv_conf.h
    ```
    **Note:** The path may vary depending on the board you are using. The path above is for the `4D Systems ESP32-S3 Gen4 R8N16` board.
5. Build and upload the project to the ESP32-S3.

### Hardware

Wire your components as defined in [include/Config.hpp](include/Config.hpp) file.

| ESP32-S3 | ILI9341 TFT Display |
| -------- | ------------------- |
| 3V3      | VCC                 |
| GND      | GND                 |
| 15       | CS                  |
| 16       | RST                 |
| 17       | DC                  |
| 18       | MOSI/SD1            |
| 8        | SCK                 |
| 3        | LED                 |
| 9        | MISO/SD0            |
| 8        | T_CLK               |
| 10       | T_CS                |
| 18       | T_DIN               |
| 9        | T_DO                |
| N/C      | T_IRQ               |

## Future improvements

Replace all the callback directive strings with enum.
