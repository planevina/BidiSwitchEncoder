# BidiSwitchEncoder
Arduino library for a toggle-switch-based rotary encoder.


# Library Description
This Arduino library decodes bidirectional toggle switches (e.g., ALPS SSCM110100) as rotary encoders. It tracks switch toggling triggered by gears or mechanical rotation, determining clockwise (CW) and counterclockwise (CCW) movements.

Modified from [esp-iot-solution/knob.](https://github.com/espressif/esp-iot-solution/tree/master/components/knob)

# Key Features
Supports common toggle switches (like ALPS SSCM110100).

Detects rotation direction (CW/CCW) via switch state changes.

Lightweight and interrupt-friendly for real-time applications.

Hardware-agnostic library to emulate rotary encoders using momentary toggle switches, with debouncing and direction detection.
