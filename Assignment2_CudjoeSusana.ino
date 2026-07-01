int buzzer_pin=8;
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};   // a, b, c, d, e, f, g
int numSegments = 7;
 
// The pattern for each digit. 1 = segment ON, 0 = segment OFF.
byte digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},   // 0
    {0, 1, 1, 0, 0, 0, 0},   // 1
    {1, 1, 0, 1, 1, 0, 1},   // 2
    {1, 1, 1, 1, 0, 0, 1},   // 3
    {0, 1, 1, 0, 0, 1, 1},   // 4
    {1, 0, 1, 1, 0, 1, 1},   // 5
    {1, 0, 1, 1, 1, 1, 1},   // 6
    {1, 1, 1, 0, 0, 0, 0},   // 7
    {1, 1, 1, 1, 1, 1, 1},   // 8
    {1, 1, 1, 1, 0, 1, 1},   // 9
};
void showDigit(int n) {
    if (n < 0 || n > 9) return;
    for (int i = 0; i < numSegments; i++) {
        digitalWrite(segmentPins[i], digits[n][i]);
    }
}
void setup() {
      Serial.begin(9600);
 
    // Set every segment pin as OUTPUT.
    for (int i = 0; i < numSegments; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
    Serial.println("");
    Serial.println("===Beeping Countdown Starting===");

    int count=9;

    while(count>=1){
      Serial.print("Counting:");
      Serial.println(count);


      // call the show_digit function and pass in counter

      showDigit(count);

      tone(buzzer_pin,492,500);

      delay(2000);

      count-=1;

    }

  showDigit(count);
  tone(buzzer_pin,262,1500);        
// longer completion tone
  Serial.println("===Countdown Complete===");


}

void loop() {
  // put your main code here, to run repeatedly:

}
