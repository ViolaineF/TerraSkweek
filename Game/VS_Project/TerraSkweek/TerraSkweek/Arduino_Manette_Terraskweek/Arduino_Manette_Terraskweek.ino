
char envoi;

//---------------- JOYSTICK

const int X_THRESHOLD_LOW = 35;
const int X_THRESHOLD_HIGH = 515;

const int Y_THRESHOLD_LOW = 35;
const int Y_THRESHOLD_HIGH = 515;
int pot = A3;
int lux = A2;
int xPin = A1;
int yPin = A0;

int x_position = 0;
int y_position = 0;
int x_direction = 0;
int y_direction = 0;

int buttonState = 0;

//------------------LEDs
int brightness = 0;    // how bright the LED is
int fadeAmount = 2;    // how many points to fade the LED by

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

  pinMode(pot, INPUT); // Potentio

  pinMode(lux, INPUT); // Light sensor

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
    x_direction = -1;
  } else if (x_position < X_THRESHOLD_LOW) {
    x_direction = 1;
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
  analogRead(lux);

  if (analogRead(lux) > 700) {
    Serial.println('V');
  }
  else if (analogRead(lux) > 600 && analogRead(lux) <= 700){
    Serial.println('W');
  }
  else if (analogRead(lux) > 500 && analogRead(lux) <= 600){
    Serial.println('J');
  }
  else if (analogRead(lux) <= 500) {
    Serial.println('I');
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

  else if (envoi == '7') {
    analogWrite(led1Pin, 100);
    analogWrite(led2Pin, 100);
    analogWrite(led3Pin, 100);
  }
  else if (envoi == '6') {
    analogWrite(led1Pin, 25);
    analogWrite(led2Pin, 100);
    analogWrite(led3Pin, 100);
  }
  else if (envoi == '5') {
    analogWrite(led1Pin, 0);
    analogWrite(led2Pin, 100);
    analogWrite(led3Pin, 10000);
  }
  else if (envoi == '4') {
    analogWrite(led1Pin, 0);
    analogWrite(led2Pin, 25);
    analogWrite(led3Pin, 100);
  }
  else if (envoi == '3') {
    analogWrite(led1Pin, 0);
    analogWrite(led2Pin, 0);
    analogWrite(led3Pin, 100);
  }
  else if (envoi == '2') {
    analogWrite(led1Pin, 0);
    analogWrite(led2Pin, 0);
    analogWrite(led3Pin, 25);
  }
  else if (envoi == '1') {
    analogWrite(led1Pin, 0);
    analogWrite(led2Pin, 0);
    analogWrite(led3Pin, 0);
  }
  else if (envoi == '0') {
  analogWrite(led1Pin, brightness);
  analogWrite(led2Pin, brightness);
  analogWrite(led3Pin, brightness);
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 150) {
    fadeAmount = -fadeAmount ;
  }
}





  //------------- VITESSE ENNEMIS

  if (analogRead(pot) > 700) {
    Serial.println('A');
  }
  else if (analogRead(pot) > 350 && analogRead(pot) <= 700) {
    Serial.println('B');
  }
  else if (analogRead(pot) <= 350) {
    Serial.println('C');
  }

}


