int joyStickY; 
int joyStickX;
int Turnvalue1 == 0;
int Turnvalue2 == 0;
int enable1;
int enable2;
int input1 = 3;
int input2 = 5;
int input3 = 6;
int input4 = 10;
int wheelDirection1;
int wheelDirection2;
int wheelTurn;
int wheelSpeed1;
int wheelSpeed2;
int resultY;
int resultX;
void setup()
{
Serial.begin(9600);
pinMode(input1, OUTPUT);
pinMode(input2, OUTPUT);
pinMode(input3, OUTPUT);
pinMode(input4, OUTPUT);
pinMode(enable1, OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}

void loop()
{
joyStickY = analogRead(A0);
if(joyStickY > 530){
 resultY = map(joyStickY,0,1023,0,255);
 wheelDirection1 = 1;
 wheelDirection2 = 1;
}else if(joyStickY < 490){
 resultY = map(joyStickY,0,1023,255,0);
 wheelDirection1 = 2;
 wheelDirection2 = 2;
}else{
 resultY = 0;
 wheelDirection1 = 3
 wheelDirection2 = 3
}
if (wheelDirection1 = 1){ 
 digitalWrite(input1, LOW);
 digitalWrite(input2, HIGH);
}else if (wheelDirection1 = 2){
 digitalWrite(input1, HIGH);
 digitalWrite(input2, LOW);
}else{
 digitalWrite(input1, LOW);
 digitalWrite(input2, LOW);
}
if (wheelDirection2 = 1){ 
 digitalWrite(input3, LOW);
 digitalWrite(input4, HIGH);
}else if (wheelDirection2 = 2){
 digitalWrite(input3, HIGH);
 digitalWrite(input4, LOW);
}else{
 digitalWrite(input3, LOW);
 digitalWrite(input4, LOW);
}
joyStickX = analogRead(A1);
if(joyStickY > 530){
 resultX = map(joyStickY,0,1023,0,100);
 wheelTurn = 1;
}else if(joyStickY < 490){
 resultX = map(joyStickY,0,1023,100,0);
 wheelTurn = 2
}else{
 resultX = 0;
 wheelTurn = 3
}

 if (wheelTurn = 1){ 
  turnValue1 = resultX;
  turnValue2 = ((resultultX)* -1);
 }else if (wheelTurn = 2){
  turnValue1 = ((resultultX)* -1);
  turnValue2 = resultX;
 }else{
  turnValue1 = 0;
  turnValue2 = 0;
}
Serial.printl(resultY); 
}
