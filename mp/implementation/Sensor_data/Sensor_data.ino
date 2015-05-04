// these are the pins we will use for this sketch
#include <Time.h>

#define TEMPERATURE_PIN 0 // analog pin 0
#define LIGHT_SENSOR_PIN 2 // analog pin 2
#define BUTTON_PIN 2 // digital pin 2


// run this one on startup
void setup() {
  Serial.begin( 9600 );
  pinMode( BUTTON_PIN, INPUT );
}


// run this repeatedly forever (until Arduino is reset or unplugged)
void loop() {
  
  int lightThreshold = 1024;
  int tcold = 20;
  int thot = 30;
  // read sensor values
  int temp = analogRead( TEMPERATURE_PIN );
  int light = analogRead( LIGHT_SENSOR_PIN );
  int button = digitalRead( BUTTON_PIN );
  int time = hour();
  String morn = "morning";
  String an = "afternoon";
  String nt = "night";
  String timeVal;
  
  String tc = "cool";
  String tcd = "cold";
  String hot = "hot";
  String tempVal;
  
  String dim = "dim";
  String dark = "dark";
  String mod = "moderate";
  String lightVal;
  
  if(time < 12) {
    timeVal = morn;
  }
  else if(time > 5) {
    timeVal = nt;
  }
  else {
    timeVal = an;
  }
  
  if (temp <= tcold) {
    tempVal = tcd;
  }
  else if(temp >= thot) {
    tempVal = hot;
  }
  else {
    tempVal = tc;
  }
  
  if (light > lightThreshold)
  {
    lightVal = mod;
  }
  else if(light > 600)
  {
    lightVal = dim;
  }
  else
  {
    lightVal = dark;
  }
  
  // send to serial console
  Serial.print( day() );
  Serial.print( "," );
  Serial.print( timeVal );
  Serial.print( "," );
  Serial.print( tempVal );
  Serial.print(",");
  Serial.print( lightVal );
  Serial.print(",");
  Serial.print( button );
  Serial.println(); // end of line

  // sleep for 200 milliseconds
  delay( 200 );
}
