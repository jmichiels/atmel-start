# Atmel Start Example

This example makes the built-in LED of an [Adafruit Feather M0](https://learn.adafruit.com/adafruit-feather-m0-basic-proto/overview) blink. 

## Generate the Atmel Start code
```
$ atstart pull
```

## Configure with CMake
```
$ cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=".atstart/toolchain.cmake"
-- Using GCC ARM from: /path/to/gcc-arm-installation
-- The C compiler identification is GNU 10.2.1
-- The CXX compiler identification is GNU 10.2.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /path/to/gcc-arm-installation/bin/arm-none-eabi-gcc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /path/to/gcc-arm-installation/bin/arm-none-eabi-g++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: github.com/jmichiels/atmel-start/example/build
```

## Build
Tell CMake to run the make command and build the `example` target. You can leave out `-- example` to build the `all` target.
```
$ cmake --build build -- example
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/arnom/Projects/GitHub/github.com/jmichiels/atmel-start/example/build
[  4%] Building C object .atstart/CMakeFiles/atstart.dir/atmel_start.c.obj
[  8%] Building C object .atstart/CMakeFiles/atstart.dir/driver_init.c.obj
[ 12%] Building C object .atstart/CMakeFiles/atstart.dir/examples/driver_examples.c.obj
[ 16%] Building C object .atstart/CMakeFiles/atstart.dir/hal/src/hal_atomic.c.obj
[ 20%] Building C object .atstart/CMakeFiles/atstart.dir/hal/src/hal_delay.c.obj
[ 25%] Building C object .atstart/CMakeFiles/atstart.dir/hal/src/hal_gpio.c.obj
[ 29%] Building C object .atstart/CMakeFiles/atstart.dir/hal/src/hal_init.c.obj
[ 33%] Building C object .atstart/CMakeFiles/atstart.dir/hal/src/hal_io.c.obj
[ 37%] Building C object .atstart/CMakeFiles/atstart.dir/hal/src/hal_sleep.c.obj
[ 41%] Building C object .atstart/CMakeFiles/atstart.dir/hal/utils/src/utils_assert.c.obj
[ 45%] Building C object .atstart/CMakeFiles/atstart.dir/hal/utils/src/utils_event.c.obj
[ 50%] Building C object .atstart/CMakeFiles/atstart.dir/hal/utils/src/utils_list.c.obj
[ 54%] Building C object .atstart/CMakeFiles/atstart.dir/hal/utils/src/utils_syscalls.c.obj
[ 58%] Building C object .atstart/CMakeFiles/atstart.dir/hpl/core/hpl_core_m0plus_base.c.obj
[ 62%] Building C object .atstart/CMakeFiles/atstart.dir/hpl/core/hpl_init.c.obj
[ 66%] Building C object .atstart/CMakeFiles/atstart.dir/hpl/dmac/hpl_dmac.c.obj
[ 70%] Building C object .atstart/CMakeFiles/atstart.dir/hpl/gclk/hpl_gclk.c.obj
[ 75%] Building C object .atstart/CMakeFiles/atstart.dir/hpl/pm/hpl_pm.c.obj
[ 79%] Building C object .atstart/CMakeFiles/atstart.dir/hpl/sysctrl/hpl_sysctrl.c.obj
[ 83%] Building C object .atstart/CMakeFiles/atstart.dir/samd21a/gcc/gcc/startup_samd21.c.obj
[ 87%] Building C object .atstart/CMakeFiles/atstart.dir/samd21a/gcc/system_samd21.c.obj
[ 91%] Linking C static library libatstart.a
[ 91%] Built target atstart
[ 95%] Building C object CMakeFiles/example.dir/main.c.obj
[100%] Linking C executable example.elf
[100%] Built target example
```

## Upload with [bossac](https://github.com/shumatech/BOSSA)
```
$ cmake --build build -- upload
Consolidate compiler generated dependencies of target atstart
[ 91%] Built target atstart
Consolidate compiler generated dependencies of target example
[100%] Built target example
Trying to connect on ttyACM0
Set binary mode
readWord(addr=0)=0x20007ffc
readWord(addr=0xe000ed00)=0x410cc601
readWord(addr=0x41002018)=0x10010305
version()=v2.0 [Arduino:XYZ] Mar  5 2016 17:46:52
chipId=0x10010005
Connected at 921600 baud
Device found on ttyACM0
readWord(addr=0)=0x20007ffc
readWord(addr=0xe000ed00)=0x410cc601
readWord(addr=0x41002018)=0x10010305
Atmel SMART device 0x10010005 found
write(addr=0x20004000,size=0x34)
writeWord(addr=0x20004030,value=0x10)
writeWord(addr=0x20004020,value=0x20008000)
Device       : ATSAMD21G18A
readWord(addr=0)=0x20007ffc
readWord(addr=0xe000ed00)=0x410cc601
readWord(addr=0x41002018)=0x10010305
Chip ID      : 10010005
version()=v2.0 [Arduino:XYZ] Mar  5 2016 17:46:52
Version      : v2.0 [Arduino:XYZ] Mar  5 2016 17:46:52
Address      : 8192
Pages        : 3968
Page Size    : 64 bytes
Total Size   : 248KB
Planes       : 1
Lock Regions : 16
Locked       : readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
readWord(addr=0x41004020)=0xffff
none
readWord(addr=0x41004018)=0
Security     : false
Boot Flash   : true
readWord(addr=0x40000834)=0x7000a
BOD          : true
readWord(addr=0x40000834)=0x7000a
BOR          : true
Arduino      : FAST_CHIP_ERASE
Arduino      : FAST_MULTI_PAGE_WRITE
Arduino      : CAN_CHECKSUM_MEMORY_BUFFER
Erase flash
chipErase(addr=0x2000)
done in 0.755 seconds

Write 1116 bytes to flash (18 pages)
write(addr=0x20005000,size=0x480)
writeBuffer(scr_addr=0x20005000, dst_addr=0x2000, size=0x480)
[==============================] 100% (18/18 pages)
done in 0.007 seconds

Verify 1116 bytes of flash with checksum.
checksumBuffer(start_addr=0x2000, size=0x45c) = 49ea
Verify successful
done in 0.001 seconds
CPU reset.
readWord(addr=0)=0x20007ffc
readWord(addr=0xe000ed00)=0x410cc601
readWord(addr=0x41002018)=0x10010305
writeWord(addr=0xe000ed0c,value=0x5fa0004)
[100%] Built target upload
```