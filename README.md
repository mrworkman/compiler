# Digital Mars C/C++ compiler back-end hacked & slashed to run on MacOS 🤪

This is probably of no use to anyone but me.

Original source at https://github.com/DigitalMars/Compiler

## Building:

```shell
meson setup build
cd build
meson compile
```

Compiler: `scppn`.

Can generate code for Win32, 16 bit DOS, 16 and 32 bit Windows, 286 DOS
extenders, and 386 DOS extenders.
