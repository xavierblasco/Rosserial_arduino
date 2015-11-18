# Rosserial_arduino
Package for listen to Arduino board node

# Arduino code
1.- We have created an Arduino project called Arduino_Sinus. This project publish the Sinus value continuously (for angles between 0 and 2 pi rad).
    These values are published on an Ros node called "sinus"
    All code is explained in the file itself.

# Ros Package    
2.- After then we have to create a new Ros Package 
    We can do that with following explession on terminal. You should execute this instruction on your ros workspace (into src directory)
    
    catkin_ws/src/$ catkin_create_pkg rosserial_arduio std_msgs rospy roscp
    
    
    We include std_msgs dependencie as well as rospy and roscp dependencies
    
    Now we should edit package.xml file and CMakeLists.txt with our own data information.
    
3.- Now we will create a cpp file for listener code.


