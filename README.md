# Cardputer GNSS Compass

A lightweight **GNSS-based compass application** for the M5Stack Cardputer using the LoRaWAN 1262 CAP module with integrated GNSS.

This project turns the **M5Stack Cardputer ADV** into a portable **navigation tool** that displays heading, satellite data, and movement information using GNSS positioning.

Unlike magnetic compasses, this system calculates direction based on **course-over-ground derived from satellite positioning**.

---

## Hardware

This project was developed for:

* M5Stack Cardputer ADV
* M5Stack LoRaWAN 1262 CAP Module (with integrated GNSS)

The GNSS receiver supports multiple satellite constellations:

* GPS (USA)
* GLONASS (Russia)
* Galileo (European Union)
* BeiDou (China)
* QZSS (Japan)

Using multiple constellations improves:

* positioning accuracy
* satellite lock time
* reliability in urban environments

---

## Features

* GNSS-based compass
* Real-time heading display
* Satellite count display
* Speed calculation
* Heading smoothing filter
* Lightweight firmware for ESP32-S3

Optional future features:

* waypoint navigation
* distance-to-target indicator
* breadcrumb trail
* logging to SD card

---

## How It Works

The GNSS module continuously outputs NMEA messages containing:

* latitude
* longitude
* speed
* course-over-ground (COG)

The firmware extracts the **course value** and renders a compass on the Cardputer display.

Heading is filtered using a smoothing algorithm to reduce jitter.

---

## Important Note

GNSS compasses determine direction based on movement.

This means:

* Direction is accurate while moving.
* Direction may be undefined while stationary.

Typical accuracy improves once speed exceeds **~5 km/h**.

---

## Software

The project is built using the following libraries:

* TinyGPSPlus
* M5Cardputer
* M5Unified
* M5GFX

Framework:

* Arduino / ESP32-S3

---

## Installation

1. Install Arduino IDE
2. Install the ESP32 board package
3. Install required libraries
4. Compile and upload to the Cardputer

---

## Use Cases

* Hiking navigation
* Field navigation tool
* GNSS experiments
* Embedded GNSS development
* Educational GNSS projects

---

## License

MIT License

---

## Future Development

Planned improvements:

* graphical compass UI
* waypoint navigation
* GNSS constellation selection
* track recording
* LoRa-based position sharing
