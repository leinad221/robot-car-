int joyStickY; //upward, downward motion of joystick
int joyStickX; //sidewards motion of joystick
int turnValue1; //how much left wheel turns
int turnValue2; // how much right wheel turns
int turnRange = 127; // range of possible turning values
int enable1 = 10; // PWD output for left wheel
int enable2 = 9; // PWD output for right wheel
int input1 = 3; // first input for direction of left wheel
int input2 = 5; // second input for direction of left wheel
int input3 = 6; // first input for direction of right wheel
int input4 = 7; // second input for direction of right wheel
int wheelDirection; // direction of left wheel
int wheelDirection2;  // direction of right wheel
int wheelTurn; // which side the car is turning to
int wheelSpeed1; // speed of left wheel
int wheelSpeed2; // speed of right wheel
int resultY; // place holder variable for y axis
int resultX; // place holder variable for x axis
int slideSwitch; // Slideswitch input if we are using one
int centreLowY = 490; // lowest value when Joystick is considered in the center of the Y axis
int centreHighY = 530; // highest value when Joystick is considered in the center of the Y axis
int centreLowX = 490; // lowest value when Joystick is considered in the center of the X axis
int centreHighX = 540; // highest value when Joystick is considered in the center of the X axis
int lowestSpeed = 0; // twice as low as lowest PWD speed (cannot be lower than -255)
int highestSpeed = 255; // highest PWD speed
void setup()
{
 Serial.begin(9600);
 pinMode(input1, OUTPUT); // output to L289N Driver
 pinMode(input2, OUTPUT); // output to L289N Driver
 pinMode(input3, OUTPUT); // output to L289N Driver 
 pinMode(input4, OUTPUT); // output to L289N Driver
 pinMode(enable1, OUTPUT); // output to L289N Driver 
 pinMode(enable2, OUTPUT); // output to L289N Driver 
 pinMode(A0,INPUT); // input from joystick Y axis (can be accomodated with joystick code)
 pinMode(A1,INPUT); // input from joystick Y axis (can be accomodated with joystick code)
 pinMode(2, INPUT); // checks whether slideswitch is turned on or not
}

void loop()
{
 joyStickY = analogRead(A0);
 if(joyStickY > centreHighY){
  resultY = map(joyStickY,0,1023,lowestSpeed,highestSpeed);
  wheelDirection = 1;
  wheelDirection2 = 1;
 }else if(joyStickY < centreLowY){
  resultY = map(joyStickY,0,1023,highestSpeed,lowestSpeed);
  wheelDirection = 2;
  wheelDirection2 = 2;
 }else if(joyStickY <= centreHighY, joyStickY >= centreLowY){
  resultY = 0;
  wheelDirection = 3;
  wheelDirection2 = 3;
 }
 joyStickX = analogRead(A1);
 if(joyStickX > centreHighX){
  resultX = map(joyStickX,0,1023,0,turnRange);
  wheelTurn = 1;
 }else if(joyStickX < centreLowX){
  resultX = map(joyStickX,0,1023,turnRange,0);
  wheelTurn = 2;
 }else if(joyStickX <= centreHighX, joyStickX >= centreLowX){
  resultX = 0;
  wheelTurn = 3;
 }
 if (wheelTurn == 1){ 
  turnValue1 = resultX;
  turnValue2 = ((resultX)* -1);
 }else if (wheelTurn == 2){
  turnValue1 = ((resultX)* -1);
  turnValue2 = resultX;
 }else if (wheelTurn == 3){
  turnValue1 = 0;
  turnValue2 = 0;
 }
 if(wheelDirection == 1){ 
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
 }else if (wheelDirection == 2){
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
 }else if (wheelDirection == 3){
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
 }
 if (wheelDirection2 == 1){ 
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
 }else if (wheelDirection2 == 2){
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);
 }else if (wheelDirection2 == 3){
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
 }
 slideSwitch = digitalRead(2);
 if(slideSwitch, HIGH){
  wheelSpeed1 = (resultY + turnValue1);
  wheelSpeed2 = (resultY + turnValue2);
 }else if(slideSwitch, LOW){
  wheelSpeed1 = 0;
  wheelSpeed2 = 0;
 }
 if (wheelSpeed1 >= 255){
  wheelSpeed1 = 255;
 }
 if (wheelSpeed1 <= 0){
  wheelSpeed1 = 0;
  //wheelDirection = 2;//turns the left wheel backwards
  //wheelSpeed1 = ((wheelspeed1) * -1)// speeds up according to how much minus(get rid of wheelSpeed1 = 0 line if you want to use this)
 }
 if (wheelSpeed2 >= 255){
  wheelSpeed2 = 255;
 }
 if (wheelSpeed2 <= 0){
  wheelSpeed2 = 0;
  //wheelDirection2 = 2;//turns the right wheel backwards
  //wheelSpeed2 = ((wheelspeed2) * -1)// speeds up according to how much minus(get rid of "wheelSpeed2 = 0" line if you want to use this)
 }
 analogWrite(enable1,wheelSpeed1);
 analogWrite(enable2,wheelSpeed2);
 Serial.println(wheelSpeed2); // used for debugging
 delay(300);
