int moisturePin = A2;
// Set this threeshold accordingly to the resistance you used
// The easiest way to calibrate this value is to test the sensor in both dry and wet soil
int threeshold = 800;
void setup() {
  Serial.begin(9600);
  while (!Serial);
  delay(2000);
}
void loop() {
  Serial.println(get_average_moisture());
  delay(5000);
}
int get_average_moisture() { // make an average of 10 values to be more accurate
  int tempValue = 0; // variable to temporarly store moisture value
  for (int a = 0; a < 10; a++) {
    tempValue += analogRead(moisturePin);
    delay(100);
  }
  return tempValue / 10;
}
