// Define pin numbers
const int IR_PIN = A0;    // IR sensor pin
const int LDR_PIN = A1;  // LDR sensor pin
const int LED_PIN = 9;   // LED dimmer pin

// Define variables
int irState = 0;    // Current IR sensor state
int ldrValue = 0;   // Current LDR sensor value
int brightness = 0; // Current LED brightness

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes
  pinMode(IR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read IR sensor state
  irState = analogRead(IR_PIN);

  // Read LDR sensor value
  ldrValue = analogRead(LDR_PIN);

  // Print sensor values to serial monitor
  Serial.print("IR state: ");
  Serial.println(irState);
  Serial.print("LDR value: ");
  Serial.println(ldrValue);

  // If IR sensor detects an object and it's dark outside
  if (ldrValue < 10 && irState < 500) {
    analogWrite(LED_PIN, 255);
  } 
  // If there's no object or it's not dark outside
  else if(ldrValue < 10) {
    analogWrite(LED_PIN, 10);
  }
  else{
    analogWrite(LED_PIN, 0);
  }
}