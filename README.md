# MIA Assistant

Smart System for communication between patients and medical professionals

The Platform we developed works as follows:

-We have four IoT devices, a button, a Voice Assistant device, an Image recognition module and a Light indicator (which is just a ESP microcontroller with some RGB LEDs.

-The button, Voice assistant and Image recognition devices send notifications to the MQTT broker when some conditions are met. Namely when the user/patient presses the button, hollers for help or when the image recog module notices he left his bed.

-The MQTT broker then sends the corresponding messages to the webapp and the light indicator module to get the notifications.

-The light module was configured in order to met a hospital required color code.

![alt text](https://github.com/altaga/BlankAssistant/blob/master/system_architecture.png)

For the voice assistant, we used a Raspberry pi 3, a microphone and some speakers. We configured it all via node-red.

For the image recognition module, we used a Raspberry pi 3 with its camera, and was also configured in node-red.

The cloud services were the free versions of each one.
