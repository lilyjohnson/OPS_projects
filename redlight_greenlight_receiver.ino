//receiving, stop lights
#define GREEN 3
#define RED 6
#define LED 2
int randNum;
char byteRead;
int score = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  randNum = random(2);
  //Serial.println("rand num:"+randNum);

  //read data only when receiving data
  if (Serial.available() > 0){
    byteRead = Serial.read(); 
  }

  //randomly switching red and green lights
  if (randNum == 1){
    digitalWrite(GREEN, HIGH);
    delay(200);
  }
  else{
    digitalWrite(RED, HIGH);
    delay(200);
  }
  
 
  if (randNum == 1){ //light is green
    if(byteRead == '1'){ //user presses gas
      score++;
      Serial.print("Score: ");
      Serial.println(score);
      digitalWrite(LED, HIGH);
      delay(200);
    }
    else if(byteRead == '0'){ //user presses brake
      Serial.print("You lost! Score: ");
      Serial.println(score);
      score=0;
      digitalWrite(LED, HIGH);
      delay(1000);
    }
  }
  else{ //light is red
    if(byteRead == '0'){ //user presses brake
      score++;
      Serial.print("score: ");
      Serial.println(score);
      digitalWrite(LED, HIGH);
      delay(200);
    }
    else if(byteRead == '1'){ //user presses gas
      Serial.print("You lost! Score: ");
      Serial.println(score);
      score=0;
      digitalWrite(LED, HIGH);
      delay(1000);
    }
  }
  
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(LED, LOW);
}
