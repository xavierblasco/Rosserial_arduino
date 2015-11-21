# Rosserial_arduino
Package for listen to Arduino board node

# Arduino code
1.- We have created an Arduino project called Arduino_Sinus. This project publish the Sinus value continuously (for angles between 0 and 2 pi rad).
    These values are published on an Ros node called "sinus"
    All code is explained in the file itself.


# Listener for Arduino Sinus node
2.- Open a new Terminal window (Ctrl + Alt + T)
    Launch roscore typing:
    $ roscore
    
    run the rosserial client application that forwards your Arduino messages to the rest of ROS. 
    Make sure to use the correct serial port:

    $ rosrun rosserial_python serial_node.py /dev/ttyACM0
    
    To Know which port are your arduino board connected , go to Tools / Serial Port on your Arduino IDE menu.
    
    Know you can view data incoming from Arduino. Open a new Terminal window.
    This will print on screen data received. Our topic in Arduino node is called "sinus".You should change for your topic name.
    
    $  rostopic echo sinus
    


# Ros Package    
3.- ow we will create a launcher for these instructions. Create a new Ros Package 
    We can do that with following explession on terminal. You should execute this instruction on your ros workspace (into src directory)
    
    catkin_ws/src/$ catkin_create_pkg rosserial_arduio std_msgs rospy roscp
    
    We include std_msgs dependencie as well as rospy and roscp dependencies
    
    Now we should edit package.xml file and CMakeLists.txt with our own data information.
    



