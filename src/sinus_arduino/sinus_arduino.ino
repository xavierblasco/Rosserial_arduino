//include math Library for sinus function
#include <math.h>

//include ros Libraries
#include <ros.h>
#include <std_msgs/Float32.h>

//Define Ros Node
ros::NodeHandle  nh;

//We need to instantiate the publishers and subscribers that we will be using. 
//Here we instantiate a Publisher with a topic name of "sinus"
std_msgs::Float32 ros_sin_msg;
ros::Publisher pub_sin("sinus", &ros_sin_msg);


const float myPI = 3.141593; //Define Pi value
float alpha = 0;  //Define a new variable for get angle value
int led = 13; //Set into a variable the pin number for led 




void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  //Init Node Object
  //We need to initialize ROS node handle, 
  //advertise any topics being published, and subscribe to any topics we wish to listen to. 
  nh.initNode();
  nh.advertise(pub_sin);
  
  //Define pin led as OUTPUT
  pinMode(led, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  //increase aplha value
  alpha = alpha + 0.1;
  
  //if aplpha > 2 pi then reset to 0
  if(alpha > 2*myPI) alpha = 0 ;
  
  if (alpha>myPI)
      digitalWrite(led, LOW); //turn the LED off
  else
      digitalWrite(led, HIGH); //turn the LED on
      
  //Assign data message value
  ros_sin_msg.data = sin(alpha);
  
  //publish message. Here the Node publish the sinus value
  pub_sin.publish(&ros_sin_msg);
  
  //Here with spinOnce all ROS communication callbacks are handled. 
  nh.spinOnce();
  
  //Show on terminal
  Serial.print("Sin: ");Serial.println(sin(alpha));
  
  //sleep
  delay(500);        // delay in between reads for stability
}
