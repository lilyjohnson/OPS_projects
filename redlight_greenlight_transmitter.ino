//transmitter, buttons
char byteWrite;
#define GAS 7
#define BRAKE 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BRAKE, OUTPUT);
  pinMode(GAS, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(GAS) == HIGH){
    byteWrite = Serial.write('1');
  }
  else if(digitalRead(BRAKE) == HIGH){
    byteWrite = Serial.write('0');
  }
}
