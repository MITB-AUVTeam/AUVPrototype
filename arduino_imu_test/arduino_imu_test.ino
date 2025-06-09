#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

unsigned long lastTime;
float roll = 0, pitch = 0;
const float alpha = 0.98;

void setup() {
  Serial.begin(9600);
  Wire.begin();  // SDA, SCL for arduino

  byte status = mpu.begin();
  Serial.print("MPU6050 status: ");
  Serial.println(status);
  while (status != 0) {
    Serial.println("MPU6050 not connected. Retrying...");
    delay(1000);
    status = mpu.begin();
  }

  Serial.println("MPU6050 initialized successfully!");
  delay(1000);

  mpu.calcOffsets(true, true);  // Calibrate both gyro and accel
}

void loop() {
  mpu.update();
  
  float ax=mpu.getAccX();
  float ay=mpu.getAccY();
  float az=mpu.getAccZ();
  float gx=mpu.getGyroX();
  float gy=mpu.getGyroY();
  float gz=mpu.getGyroZ();

  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;
  lastTime = now;

  // Convert gyro to deg/s
  float gyroXrate = gx / 131.0;
  float gyroYrate = gy / 131.0;

  // Calculate accel angle (degrees)
  float accRoll  = atan2(ay, az) * 180 / PI;
  float accPitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180 / PI;

  // Complementary filter
  roll  = alpha * (roll + gyroXrate * dt) + (1 - alpha) * accRoll;
  pitch = alpha * (pitch + gyroYrate * dt) + (1 - alpha) * accPitch;

  Serial.print("Roll: "); Serial.print(roll);
  Serial.print(" | Pitch: "); Serial.println(pitch);

  

  delay(10);  // ~100 Hz
}
