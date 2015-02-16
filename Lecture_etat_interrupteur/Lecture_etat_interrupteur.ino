int bouton1 = 50;
int bouton2 = 51;
int bouton3 = 52;
int led = 13;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(bouton1, INPUT_PULLUP);
  pinMode(bouton2, INPUT_PULLUP);
  pinMode(bouton3, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
  // print out the state of the button1:
 int buttonState1 = digitalRead(bouton1);
 int buttonState2 = digitalRead(bouton2);
 int buttonState3 = digitalRead(bouton3);
  
  Serial.print("Bouton1="); 
  Serial.print("\t");
  Serial.println(buttonState1);
  Serial.print("Bouton2="); 
  Serial.print("\t");
  Serial.println(buttonState2);
  Serial.print("Bouton3="); 
  Serial.print("\t");
  Serial.println(buttonState3);
  delay(200);
}

