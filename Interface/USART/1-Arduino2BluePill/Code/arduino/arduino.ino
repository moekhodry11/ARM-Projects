void setup() {
  Serial.begin(9600); // Set the baud rate to your Serial Monitor's baud rate
}

void loop() {
  if (Serial.available() > 0) {
    // If data is available to read from Serial Monitor
    char receivedChar = Serial.read(); // Read the incoming character
     Serial.print(receivedChar);
  }
    
    // Print the received character back to the Serial Monitor
    //Serial.print("You entered: ");
//    Serial.println('1');
// delay(1000);
//    Serial.println('0');
//
//    delay(500);

    

    // You can add more processing or conditions based on the received data here
  //}
}
