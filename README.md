# SHAS

## A smart home automation system with voice control and user authorization

## Team members

| Name                              | TAMUCC ID | Email                              |
|-----------------------------------|-----------|------------------------------------|
| `Venkata Sai Pavan Arepalli`      | A04268973 | varepalli@islander.tamucc.edu      |
| `Siva Parvathi Chirumamilla`      | A04269507 | schirumamilla2@islander.tamucc.edu |
| `Ramya Reddy Dhudipala`           | A04267473 | rdhudipala@islander.tamucc.edu     |
| `Venkata Hemanth reddy manchala ` | A04269074 | hmanchala@islander.tamucc.edu      |


&nbsp;

## We divided our project into 4 major modules in regards with code.

- Android App - The UI of the application
- Machine learning module - Authorizing speaker
- Python Flask Api - Api used as a connection between android app and Ml module - hosted in ubuntu server
- Arduino code - Code that runs on ESP8266 chip, works with and controls electronic appliances, according to the codes
  received from Android App.

### Execution and testing

* Pre- requisites
    * Java installed
    * Python installed
    * Android studio IDE to run the Android app code
    * Jupyter book or Google Colab to train the model.
    * Pycharm IDE installed.
    * Arduino IDE installed.
    * A working NodeMcu ESP8266.
      * 3 LED'S
      * One bread board.
      * 10 Jumper cables (Male - Male)
    * Ubuntu or any linux server with python installed to serve flask Api.
    * We have one already installed and running on http://142.93.57.145:5000
    * Mosquitto or any other MQTT broker - connection between android device an IOT device.
    * We have one already installed and running on http://142.93.57.145:1883
    * Downloaded source code.

#### Android app execution:

* Open the android project in IDE, and wait for gradle sync.
* Build and run apk file or use the already built apk file included with source code.

#### Ml execution:

- Open the code in python folder from downloaded source code using Jupyter notebook or Google Colab.
- Install Required modules.
- Execute Preprocessingfile.ipynb File to extract features.
- Execute ModelTraining_ANN.ipynb File to build the model.
- Execute TestFile.ipynb File to test the model/system built.

Things to do:
- Change all the paths in code as per your directory.
- Four options are there when you run Speakerverification.py 
- i) Record audio for training 
- ii) Train Model 
- iii) Record Audio for Testing 
- iv) Test Model(Follow the same order).
- Store your audio recorded for training in training_set and testing audio in testing_set Folder.

#### Python Flask Api execution:
- Open shas-flas folder in PyCharm IDE
- Install all requirements from requirement.txt file
- Run the code.


#### Arduino app execution:
- Open the sketch from Arduino folder from downloaded source code.
- Install the libraries Arduinowebsockets, MD_MAX72XX, PubSubClient, and WebSockets.
- Attach the NODE MCU to the computer's USB port.
- Connect the LED's and cable to the device as shown in the picture, added with arduino code.
- Edit in the code and added the following details:
  - Wi-Fi login information
  - mqtt_server information
  - and MQTT port information.
- Save the file and upload the sketch to the ESP8266 chip.
- You may view the serial monitor window for output.
- It displays the  Wi-Fi and MQTT connection information after the sketch has been uploaded.

## Now that everything is set up please open the Android app and give commands.

### Commands supported as of now:

#### Open access - Any once can give these commands:
- Turn on bedroom lights
- Turn off bedroom lights
- Turn on living room lights
- Turn off living room lights

#### Restricted access - Only parents have access to these commands:
- Open garage door
- Close garage door
- Open main door
- Close main door


