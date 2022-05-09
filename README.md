# GPS-receiver 

Esp-32 based GPS tracker, which sends its position to a web server via in built wifi.

- [GPS-receiver](#gps-receiver)
    - [General info](#general-info)
    - [Images](#images)
    - [Schematics](#schematics)
    - [Technologies](#technologies)
    - [Base of components](#base-of-components)
    - [Programing environment](#programing-environment)
    - [Status](#status)

### General info

Goal of creating this project was to design a device which can be used for tracking position, which displays information about its location on 16x2 LCD screen and also transmits this data to a web server on Blynk platform over in built wifi module.

### Images
![image](https://user-images.githubusercontent.com/56251965/167475300-e2e0ed19-a089-4b05-8e62-577d0e2e54e3.png)
![image](https://user-images.githubusercontent.com/56251965/167475353-ab295d8a-6f90-4b2d-8d1b-5643531ba926.png)

![image](https://user-images.githubusercontent.com/56251965/167475394-a0e04d91-76fa-4eef-ab29-4d39ff2baf9a.png)
![image](https://user-images.githubusercontent.com/56251965/167475409-19195ef7-8832-418a-a593-a3690661ba08.png)


### Schematics

- ##### Connection diagram
![image](https://user-images.githubusercontent.com/56251965/167475106-b09506ef-2902-4a1c-bac7-66400ffe4de1.png)


- ##### PCB project
![image](https://user-images.githubusercontent.com/56251965/167475222-b3636a26-094e-4168-9d69-df2511e97135.png)

### Technologies

- C++

### Base of components

- DFRobot FireBeetle ESP32 IOT
- GPS module – Ublox neo 6m with antenna
- LCD 16x2 display
- Universal board
- Potentiometer

### Programing environment

-Visual Studio code with PlatformIO extension

### Status

Completed
