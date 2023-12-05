unix build for platform vexv5
CXX src/main.cpp
LINK build/prop.elf
arm-none-eabi-ld: build/src/main.o: in function `main':
main.cpp:(.text.main+0x18): undefined reference to `RangeFinderA'
arm-none-eabi-ld: main.cpp:(.text.main+0x28): undefined reference to `Drivetrain'
arm-none-eabi-ld: main.cpp:(.text.main+0x34): undefined reference to `RangeFinderA'
arm-none-eabi-ld: main.cpp:(.text.main+0x38): undefined reference to `Drivetrain'
make: *** [vex/mkrules.mk:18: build/prop.elf] Error 1
make process closed with exit code : 2
