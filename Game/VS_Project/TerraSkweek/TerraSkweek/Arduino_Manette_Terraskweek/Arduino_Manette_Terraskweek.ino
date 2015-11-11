
char envoi;

//---------------- JOYSTICK

const int X_THRESHOLD_LOW = 35;
const int X_THRESHOLD_HIGH = 515;

const int Y_THRESHOLD_LOW = 35;
const int Y_THRESHOLD_HIGH = 515;

int xPin = A1;
int yPin = A0;

int x_position = 0;
int y_position = 0;

int x_direction = 0;
int y_direction = 0;

int buttonState = 0;


//------------------LEDs
int led1Pin = 9;
int led2Pin = 10;
int led3Pin = 11;

//-----

int statePause = 0;

int hautParleurPin = 3;

void setup()
{
  Serial.begin(9600);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(2, INPUT); // Potentio

  pinMode(4, INPUT); // Light sensor

  pinMode(hautParleurPin, OUTPUT); // Haut parleur

  pinMode(led1Pin, OUTPUT); // LEDs
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);

  pinMode(12, INPUT); // Fire button
  pinMode(13, INPUT); // Pause button

  int Led1_Value;
  int Led2_Value;
  int Led3_Value;
}

void loop()
{
  envoi = Serial.read(); // On receptionne les données envoyées par le PC

  //------------ DEPLACEMENT PLAYER
  x_position = analogRead(xPin);
  y_position = analogRead(yPin);


  if (x_position > X_THRESHOLD_HIGH) {
    x_direction = 1;
  } else if (x_position < X_THRESHOLD_LOW) {
    x_direction = -1;
  }

  if (y_position > Y_THRESHOLD_HIGH) {
    y_direction = 1;
  } else if (y_position < Y_THRESHOLD_LOW) {
    y_direction = -1;
  }

  if ((y_position < Y_THRESHOLD_HIGH) && (y_position > Y_THRESHOLD_LOW) && (x_position < X_THRESHOLD_HIGH) && (x_position > X_THRESHOLD_LOW) ) {
    x_direction = 0;
    y_direction = 0;
  }

  if (x_direction == -1) {
    Serial.println('u');
  }
  else if (x_direction == 1) {
    Serial.println('d');
  }
  else if (y_direction == 1) {
    Serial.println('l');
  }
  else if (y_direction == -1) {
    Serial.println('r');
  }

  //----------- TIR
  
 if (digitalRead(12) == HIGH) {
    Serial.println('F');
    // + PLAY TIR SOUND
    tone(hautParleurPin, 932, 20);
  }


  //----------- PAUSE
  if (digitalRead(13) == HIGH && statePause == 0) {
    Serial.println('P');
    // + PLAY Pause SOUND
    tone(hautParleurPin, 700, 20);
    statePause = 1;
  }
  if (digitalRead(13) == LOW && statePause == 1) {
    statePause = 0;
  }

  //------------ INVISIBILITE
  if (digitalRead(4) > 150) {
    Serial.println('I');
  }
  else {
    Serial.println('V');
  }

  //------------- SON
  if (envoi == 'H') {
    // PLAY HURT SOUND
    tone(hautParleurPin, 700, 20);
  }
  else if (envoi == 'G') {
    // PLAY GET DROP SOUND
    tone(hautParleurPin, 1200, 20);
  }


  //------------ LEDs VIE
  else if (envoi == '3') {
    analogWrite(led1Pin, HIGH);
    analogWrite(led2Pin, HIGH);
    analogWrite(led3Pin, HIGH);
  }
  else if (envoi == '2') {
    analogWrite(led1Pin, LOW);
    analogWrite(led2Pin, HIGH);
    analogWrite(led3Pin, HIGH);
  }
  else if (envoi == '1') {
    analogWrite(led1Pin, LOW);
    analogWrite(led2Pin, LOW);
    analogWrite(led3Pin, HIGH);
  }
  else if (envoi == '0') {
    analogWrite(led1Pin, LOW);
    analogWrite(led2Pin, LOW);
    analogWrite(led3Pin, LOW);
  }


  //------------- VITESSE ENNEMIS

  if (digitalRead(2) > 250) {
    Serial.println('9');
  }
  else if (digitalRead(2) > 150) {
    Serial.println('8');
  }
  else if (digitalRead(2) > 50) {
    Serial.println('7');
  }

}







//
//  // fade in from min to max in increments of 5 points:
//  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
//    // sets the value (range from 0 to 255):
//    analogWrite(led1Pin, fadeValue);
//    // wait for 30 milliseconds to see the dimming effect
//    delay(30);
//  }
//
//  // fade out from max to min in increments of 5 points:
//  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
//    // sets the value (range from 0 to 255):
//    analogWrite(led1Pin, fadeValue);
//    // wait for 30 milliseconds to see the dimming effect
//    delay(30);
//  }
//
//
//
//
//  char instruction;
//  //COLLIDING BORDERS
//  if(Serial.read() > 0){
//    analogWrite(led1Pin, Led1_Value);
//  }
//  else{
//    digitalWrite(led1Pin,LOW);
//  }

