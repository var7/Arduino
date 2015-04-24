int redPin = 11;                  // Red LED connected to digital pin 12
int greenPin = 10;  // Green LED connected to digital pin 11
int yellowPin = 12;

void setup()                      // run once, when the sketch starts
{
  pinMode(redPin, OUTPUT);        // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
  pinMode(yellowPin, OUTPUT);
}

void loop()                       // run over and over again
{
  digitalWrite(redPin, HIGH);    // sets the Red LED on
  delay(200);
  digitalWrite(greenPin, HIGH);  // sets the Green LED on
  delay(200);
  digitalWrite(yellowPin, HIGH);
  delay(500);                     // waits for half a second
  digitalWrite(redPin, LOW);      // sets the Red LED off
  delay(200);
  digitalWrite(greenPin, LOW);    // sets the Green LED off
  delay(200);
  digitalWrite(yellowPin, LOW);
  delay(500);                     // waits for half a second
}

