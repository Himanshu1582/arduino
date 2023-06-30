//---------------------------------------------------------------------
//  Program:      dual_chaser
//
//  Description:  12 LED dual chaser. One led moves from left to right
//                while the second LED moves from right to left.
//                LEDs and series resistors connected to pins 2 to 13.
//
//  Date:         8 April 2016      Author: W.A. Smith
//                http://startingelectronics.org
//---------------------------------------------------------------------

// change speed of display here
#define SPEED_MS  100

void setup() {
  // set up pins 2 to 13 as outputs
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

uint16_t chase2 = 13; // keeps track of second LED movement

void loop() {
  // move first LED from left to right and second from right to left
  for (int i = 2; i < 13; i++) {
    allLEDsOff();
    digitalWrite(i, HIGH);      // chaser 1
    digitalWrite(chase2, HIGH); // chaser 2
    chase2--;
    // stop LEDs from appearing to stand still in the middle
    if (chase2 != 7) {
      delay(SPEED_MS);
    }
  }

  // move first LED from right to left and second LED from left to right
  for (int i = 13; i > 2; i--) {
    allLEDsOff();
    digitalWrite(i, HIGH);      // chaser 1
    digitalWrite(chase2, HIGH); // chaser 2
    chase2++;
    
    if (chase2 != 8) {
      delay(SPEED_MS);
    }
  }
}

// function to switch all LEDs off
void allLEDsOff(void)
{
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
}
