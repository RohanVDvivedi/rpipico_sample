# Rpi-pico template bare metal programming

This is a sample project for bare metal programming Rpi-pico board

### setup requirements

* rpi-pico microcontroller
* sublime/vi/vim/gedit any
* ARM cross compiler toolchain
  * sudo apt-get install gcc-arm-none-eabi binutils-arm-none-eabi
* To program the controller we need uf2 file, build from the binary.
  * For thsi purpose I am using a utility tool called bin2uf2.js (I forgot the source I got it from), hence you will need nodejs.
* linker script and the startup code(with flash and ram addresses modified)
  * The project uses them directly copied from the arm crosscompiler toolchain samples and examples
  * it is tedious and generally unproductive to write them, but a very healthy mental excercise for people not used to them like myself.

### NOTE
 * This project lacks the original work on 2nd stage bootloader required by the Rpi-pico.
 * All that I have done is to find a padded (padded to 252 bytes and last 4 bytes being the CRC32 checksum) the pico-sdk's second stage bootloader.
 * Then I left started my FLASH leaving 256 bytes for this second stage bootloader.
 * Then finally concatenated the second stage bootloader binary file with my main.bin to eventually create final.uf2 file.
 * AND IT WORKS. (*Read my makefile to understanf how I did this.*)
 * I do plan to write my own second stage bootloader for rpi-pico soon into the future...
 * You can find other padded binary bootloaders [here](https://github.com/rp-rs/rp2040-boot2/blob/main/bin/)

#### [RP2040 Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)

I do not recommend baremetal programming.  
*1st May'2020 edit : I do recommend bare metal programming now, projects based on this template have made me learn immensely, since then.*
