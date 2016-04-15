# CapstoneProject_Arduino_BluetoothCntrl

This is C++ based Arduino microcontroller Codes.

The project is to build a pitching machine that automatically tracks a user and pitch.
Ideal plan is to make this machine compatible with many other types of ball (baseball, tennis ball and soccer ball etc).
This machine is prototype, hence, only operates with tennis balls.

This part is software part of our bluetooth wireless control and loading mechanism.

1. Bluetooth Shield attached to our Arduino board will be paired with an Android device.
   The Android device will have an App called "Bluetooth Spp Pro" installed.
   This provides an interface with buttons.
   Each button will send a data to Arudino to trigger a "shoot" when pressed.
   Last 3 rows, speed control buttons are assigned (low, medium and high), and this allows the user to select the ball speed

2. There is a stepper motor with a gear attached to linear gear in a rack. 
   When "shoot" was triggered the linear gear will come out and push the ball into spinning wheels.

Overall, codes are not so complicated but it was really a good experience.
