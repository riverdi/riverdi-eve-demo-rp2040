OVERVIEW
--------
This repository contains example of [*riverdi-eve-lib*](https://github.com/riverdi/riverdi-eve-lib) library integration for [*Raspberry Pi Pico (RP2040)*](https://www.raspberrypi.com/products/raspberry-pi-pico/) platform. Please check [*riverdi-eve-lib*](https://github.com/riverdi/riverdi-eve-lib) project repository for more info.

PREREQUISITES
-------------

To get started, please make sure, that all libraries and tools for C/C++ development on RP2040 microcontrollers (*Raspberry Pi Pico C/C++ SDK*) are properly installed and configured on your machine - visit [*Getting started with Raspberry Pi Pico*](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) for more info.

CONNECTIONS
-----------

|  RiBUS connector    | Raspberry Pi Pico |
| ---- | ----- |
| VDD  | 3.3V  |
| GND  | GND   |
| SCLK | 6     |
| MISO | 4     |
| MOSI | 7     |
| CS   | 5     |
| INT  | 3     |
| PD   | 2     |

COMPILATION
-----------

__Note:__ *before compilation, please edit CMakeLists.txt file to choose Embedded Video Engine series (-DEVE_1, -DEVE_2, -DEVE_3 or -DEVE_4 flags), choose type and size of connected TFT module (choose predefined macros for Riverdi EVE modules or edit timings manually in modules.h file for custom displays) or to adjust compilation settings.*

[1] Set *PIC_SDK_PATH* variable:

`export PICO_SDK_PATH=../../pico-sdk`

[2] Clone *'riverdi-eve-demo-rp2040'* repository (with *'riverdi-eve-lib'* submodule):

`git clone --recursive git@github.com:riverdi/riverdi-eve-demo-rp2040.git`

[3] Create *'build'* directory:

`cd riverdi-eve-demo-rp2040`
`mkdir build`
`cd build`

[4] Prepare your *cmake* build directory by running:

`cmake ..`

[5] Build main application:

`make`

[6] Load *'riverdi-eve-demo-rp2040.elf'* file via a debugger or *'riverdi-eve-demo-rp2040.uf2'* file via drag and drop method.

GETTING HELP
------------

Please contact Riverdi support - [*<contact@riverdi.com>*](contact@riverdi.com)

LICENSE
-------

See *LICENSE.txt* file for details.

