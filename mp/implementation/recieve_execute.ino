String readString;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.write('1'); 
}

void loop() {
    while(!Serial.available()) {}
  while (Serial.available()) // this will be skipped if no data present, leading to the code sitting in the delay function below
 {
    if (Serial.available() > 0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
      Serial.println(readString);
      Serial.flush();
    }
    if (readString.length() > 0)
    {
        if (readString.equals(String("YES"))) {
            digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        }
        else {
            digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltag
        }
    }
 }
}

