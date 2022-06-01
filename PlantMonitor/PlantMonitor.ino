const int an_in_pin = A0;
float moist_val_an = 0;

float max_wet = 0.20; // 0.17 is all water, so have slightly higher value
float max_dry = 0.80; // 1 is dry as bones so have slightly less than this value

const int temp_sensor_pin = A1;
float temperature = 0.00;

const int light_sensor_pin = A2;
int light_value = 0;
int max_light = 1000; // 1023 is highest but we want to be aware before that
int min_light = 0; 

void setup() {
  Serial.begin(9600);

}

void loop() {
    // get moisture levels
    moist_val_an = get_moisture_levels();

    Serial.println(moist_val_an);
    
    if (moist_val_an >= max_dry){
      Serial.println("Plant needs more water");
    }
    if (moist_val_an <= max_wet){
      Serial.println("Plant has been over watered");
    }
    if (moist_val_an > max_wet && moist_val_an < max_dry) {
      Serial.println("Plant doesn't need watering");
    }
  
  // Get surrounding temperature
  temperature = get_temp();

  Serial.print("Surrounding temperature: ");
  Serial.println(temperature);
  
  // Get light levels
  light_value = get_light();

  Serial.print("Light levels: ");
  Serial.println(light_value);

  if (light_value >= max_light) {
    Serial.println("Plant is being exposed to too much light");
  }
  if (light_value <= min_light) {
    Serial.println("Plant does not have enough light");
  }
  

  delay(1000);
}

float get_moisture_levels() {
   /*
   * Get value from analogue in, do some maths so the value is between 0-1 value
   * 1 = dry, 0 = all wet
   * Rarely gets to 0 though, so 0.17 is going to be used as wet
   */
  float an_value = float(analogRead(an_in_pin))/1023.0;
  return an_value;
}

float get_temp() {
  /*
   * Get value from temp sensor, then 
   */
  float sensor_value = float(analogRead(temp_sensor_pin));
  float voltage = (sensor_value/1024.0) *5.0;

  // convert voltage to degrees
  float temp = (voltage - 0.5) * 100;

  return temp;
}

int get_light() {
  int sensor_value = analogRead(light_sensor_pin);

  return sensor_value;
}
