# Arcade Pico

## The Switch Board
### Mechanical Switch
* Use either SW1 or SW2 footprint for Kailh Choc V1/V2 switches.
* Solder-short the corresponding jumper (sw1 or sw2) to enable the switch.
* You can solder the other switch, but it's only for the feel, so don't solder the jumper.

* To connect to controller's main board:
  * "SW" connector (Out, GND) is for the switch signal;
  * "LED In" connector (+, -) is for the LED light.

### Optical Switch
* Solder IR1 (IR908-7C), PT1 (PT908-7C) at proper height;
* Solder R3 (500 ohm for 3.3V supply, 1k ohm for 5V supply);
* Resistors: R4, R5; Jumpers: c, e; Zener: Z1.
  * Low-active logic (most systems are): R4 (0-10 ohm), R5 (2k ohm), solder-short jumper c.
  * High-active logic: R4 (2k ohm), R5 (0-10 ohm), solder-short jumper e.
  * When power supply is 5V but the target system IO is 3.3V, solder Z1 (3.3V SOD-123F Zener diode) to protect the IO pin.
* You can solder a mechanical switch on SW1 footprint for some tactile feel, but don't solder the jumper sw1.
* On some systems, one LED line is a constant 5V or 3.3V power supply, you can borrow that to power the optical switch - just solder-short jumper "LEDP-V".

* To connect to controller's main board:
  * "SW" connector (V, Out, GND) is for the switch signal;
  * "LED In" connector (+, -) is for the LED light.

### Magnetic (Hall Effect) Switch
* Solder U1 (SS49E SOT23-3) and C1 (0.1uF 0603).
* You can solder a mechanical switch on SW2 footprint for some tactile feel, but don't solder the jumper sw2.

* To connect to controller's main board:
* "SW" connector (V, Out, G) connects to the **Arcade Pico IO** board. Then the IO board connects to the main board.
* "LED In" connector (+, -) is for the LED light.

* Note that Arcade Pico IO board is need for this setup.

## The LED Daughter Board
It is snapped off from the **Arcade Pico Button** board.
...

## The IO Board
...

