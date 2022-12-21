# Rpi-pico template bare metal programming

This is a sample project for bare metal programming Rpi-pico board

### setup requirements

* rpi-pico microcontroller
* sublime/vi/vim/gedit any
* ARM cross compiler toolchain
  * sudo apt-get install gcc-arm-none-eabi binutils-arm-none-eabi
* To program the controller you will need uf2tool
  * Download it from official repo [here](https://github.com/microsoft/uf2/tree/master/utils), and set it up to use utils/uf2conv.py
* linker script and the startup code(with flash and ram addresses modified)
  * The project uses them directly copied from the arm crosscompiler toolchain samples and examples
  * it is tedious and generally unproductive to write them, but a very healthy mental excercise for people not used to them like myself.

### NOTE
 * This project lacks the original work on 2nd stage bootloader required by the Rpi-pico.
 * All that I have done is to find a padded (padded with 256 bytes and last 4 bytes being the CRC32 checksum) the pico-sdk's second stage bootloader.
 * Then I objcopied it like below 
 * `arm-none-eabi-objcopy --input-target=binary --output-target=elf32-littlearm boot2_generic_03h.padded.bin boot2_generic_03h.padded.bin.elf`
 * and then inserted it right before my vector table of the application. AND IT WORKS.
 * I plan to write my own second stage bootloader for rpi-pico soon into the future...

#### [RP2040 Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)

I do not recommend baremetal programming.  
*1st May'2020 edit : I do recommend bare metal programming now, projects based on this template have made me learn immensely, since then.*
