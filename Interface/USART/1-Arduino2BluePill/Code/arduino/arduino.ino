void setup() {
  Serial.begin(9600); // Set the baud rate to your Serial Monitor's baud rate
}

void loop() {
  if (Serial.available() > 0) {
    // If data is available to read from Serial Monitor
    char receivedChar = Serial.read(); // Read the incoming character
    
    // Print the received character back to the Serial Monitor
    //Serial.print("You entered: ");
    Serial.println(receivedChar);

    // You can add more processing or conditions based on the received data here
  }
}
