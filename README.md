# TechAccessPro
TechAccessPro is an RFID-based access control system using the LPC2129. It authenticates users via RFID, processes data through UART, controls a door lock, and shows real-time status on an LCD. Demonstrates embedded C, hardware interfacing, and secure real-time system design.
# Project Overview

The system uses an RFID reader to capture tag data from users. The RFID module communicates with the LPC2129 microcontroller via UART protocol. The controller verifies the received ID against stored authorized credentials and makes an immediate access decision.

An LCD display provides real-time system feedback, showing messages such as:
1.“Scan Card”
2.“Access Granted”
3.“Access Denied”
4.System status prompts
When a valid card is detected, the microcontroller activates the door locking mechanism (L293D).Unauthorized attempts are rejected, ensuring security.

# System Overview

1.User scans RFID tag
2.RFID reader sends data via UART
3.LPC2129 processes and verifies ID
4.LCD displays authentication result
5.Door lock is controlled accordingly

# Key Features
- RFID-based user authentication
- Real-time access control
- UART communication with RFID module
- LCD display for live feedback
- Microcontroller-controlled door mechanism
- Embedded C firmware design
- Security-oriented system logic

# Technologies Used
- Microcontroller: LPC2129 (ARM7)
- Communication: UART
- Programming Language: Embedded C
- Display Module: 16x2 LCD
- Hardware: RFID reader, door lock actuator/relay

  
