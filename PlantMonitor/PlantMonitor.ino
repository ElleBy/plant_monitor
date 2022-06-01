const int an_in_pin = A0;
const int dig_out_pin = 8;
float moist_val_an = 0;

float max_wet = 0.20; // 0.17 is all water, so have slightly higher value
float max_dry = 0.80; // 1 is dry as bones so have slightly less than this value

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
  // Get light levels

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
