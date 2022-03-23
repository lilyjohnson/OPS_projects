long zero;
#define IR 17
#define LED 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR, INPUT);
  zero = 0;
  for (int i =0; i < 100; i++) {
    zero += analogRead(IR);
  }
  zero /= 100;
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A4);
  val = map(val, 0, 1023, 0, 255);
  int constrainedVal = constrain(val, 0, 255);
  Serial.println(constrainedVal);
  analogWrite(LED, constrainedVal);  
}
