## Keypad ChibiOS driver

This project aims to create a general ChibiOS driver for keypads.
It's meant to work with all keypads that respect these features:
* rows are digital output lines
* columns are digital input lines
* rows are enabled one at time
* columns read value are related to current enabled row

Matrix's size, as number of rows and columns, are set through a configuration object,
that is passed as argument to all driver's methods.

## Technical informations

Since this driver is for general keypads, I provide only an example of 4x4 keypad at 
[this site](https://components101.com/misc/4x4-keypad-module-pinout-configuration-features-datasheet)

## How to integrate

To integrate this driver in your project, you must place this folder under your project directory, 
and include the driver makefile in the project global makefile, as shown below:

```makefile
include ./$(PATH_TO_KEYPAD)/keypad.mk
```

## Legal notes

This project is released under the [Apache 2.0 License](http://www.apache.org/licenses/LICENSE-2.0.html)