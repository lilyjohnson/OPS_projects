#include <IMU.h>
#include <sensor_fusion.h>
extern float IMU_X;
extern float IMU_Y;
extern float IMU_Z;

#define GREEN 9
#define YELLOW 10
#define RED 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  imu_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  imu_loop();
  Serial.print( (int) (IMU_X*100));
  Serial.print("/");
  Serial.print( (int) (IMU_Y*100));
  Serial.print("/");
  Serial.print( (int) (IMU_Z*100));
  Serial.println();

  int val_x = map(IMU_X*100, -100, 100, 0, 255);
  analogWrite(GREEN, val_x);
  int val_y = map(IMU_Y*100, -100, 100, 0, 255);
  analogWrite(YELLOW, val_y);
  int val_z = map(IMU_Z*100, -100, 100, 0, 255);
  analogWrite(RED, val_z);
}
