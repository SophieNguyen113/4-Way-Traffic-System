/* ==========================================================
 * 4 – Way Traffic System Project  
 * Author: Sophie Nguyen
 * October 2022  
 * 
 * Designed a 4-way traffic system simulation in Proteus Professional software with pedestrian button to interrupt the system and allow the pedestrian to cross.  
 * Created an Arduino program, an open-source platform that uses a programming language based on C++, to compile and debug the project.
 * 
 * This is a 4-way Arduino traffic system that has a main and a pedestrian lighting circuit.  
 * As soon as the pedestrian button is pressed, the system waits until the main process attempts to jump to the next state before performing a pedestrian cycle. 
 * The pedestrian cycle will allow pedestrians to cross the street for a predefined period of time. 
 * After the time elapsed, the system resumes the main traffic control cycle from the state where the pedestrian cycle interrupts occurred.
 * ==========================================================
 */
 

// Using Arduino Uno Board.
const int g1 = 2;
const int y1 = 3; 
const int r1 = 4;
const int g2 = 5;
const int y2 = 6;
const int r2 = 7;
const int g3 = 8;
const int y3 = 9;
const int r3 = 10;
const int g4 = 11;
const int y4 = 12;
const int r4 = 13;
const int pRed = A2;
const int pgreen = A3;
const int pIN = A4;

// The setup function runs once when you press reset or power the board.
void setup()
{

// Initialize digital pins as an output.
pinMode (r1, OUTPUT);
pinMode (y1, OUTPUT);
pinMode (g1, OUTPUT);
pinMode (r2, OUTPUT);
pinMode (y2, OUTPUT);
pinMode (g2, OUTPUT);
pinMode (r3, OUTPUT);
pinMode (y3, OUTPUT);
pinMode (g3, OUTPUT);
pinMode (r4, OUTPUT);
pinMode (y4, OUTPUT);
pinMode (g4, OUTPUT);
pinMode (pRed, OUTPUT);
pinMode (pgreen, OUTPUT);

// Initialize digital pin pIN as an input.
pinMode (pIN, INPUT);

// Turn the LED on (HIGH is the voltage level)
digitalWrite (r1, HIGH); 
digitalWrite (r2, HIGH);
digitalWrite (r3, HIGH);
digitalWrite (r4, HIGH);
digitalWrite (pRed, HIGH);

}

// The loop function runs over and over again forever.
void loop() 
{ 

int crossIn1 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn1 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the g1 light is turned on, processing the traffic in g1 side.
{
  delay(100);
  digitalWrite(r1,LOW);    
  digitalWrite(g1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  delay(4000); 
}

int crossIn2 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn2 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the y1 light is turned on.
{
  digitalWrite(g1,LOW);
  digitalWrite(y1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  delay(2000);
}

int crossIn3 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn3 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the g2 light is turned on, processing the traffic in g2 side.
{  
  digitalWrite(y1,LOW);
  digitalWrite(r2,LOW); 
  digitalWrite(r1,HIGH);
  digitalWrite(g2,HIGH);              
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  delay(4000);
}

int crossIn4 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn4 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the y2 light is turned on.
{
  digitalWrite(g2,LOW);
  digitalWrite(y2,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  delay(2000);
}

int crossIn5 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn5 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the g3 light is turned on, processing the traffic in g3 side.
{
  digitalWrite(y2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(g3,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r4,HIGH);
  delay(4000);
}

int crossIn6 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn6 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the y3 light is turned on.
{
  digitalWrite(g3,LOW);
  digitalWrite(y3,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r4,HIGH);
  delay(2000);
}

int crossIn7 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn7 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the g4 light is turned on, processing the traffic in g4 side.
{
  digitalWrite(y3,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  digitalWrite(g4,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  delay(4000);
}

int crossIn8 = digitalRead (pIN); // Check if the pedestrian button is pressed or not.
if (crossIn8 == HIGH)             // If the pedestrian button is pressed, a pedestrian cycle is performed.
{
  WalkCycle();
}
else                              // If the pedestrian button is NOT pressed, the y4 light is turned on.
{
  digitalWrite(g4,LOW);
  digitalWrite(r4,LOW);
  digitalWrite(y4,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  delay(2000);
}

digitalWrite(y4,LOW);
digitalWrite(r4,LOW);
digitalWrite(r1,LOW);

}

// If the pedestrian button is pressed, a pedestrian cycle is performed.
void WalkCycle() 
{
  delay(400);
  // Turn off all green and yellow lights.
  digitalWrite (g1, LOW); digitalWrite (g2, LOW); digitalWrite (g3, LOW); digitalWrite (g4, LOW);
  digitalWrite (y1, LOW); digitalWrite (y2, LOW); digitalWrite (y3, LOW); digitalWrite (y4, LOW);

  // Turn on all red lights.
  digitalWrite (r1, HIGH); digitalWrite (r2, HIGH); digitalWrite (r3, HIGH); digitalWrite (r4, HIGH);

  digitalWrite (pgreen, HIGH); // Turn on all pedestrian green lights 
  digitalWrite (pRed, LOW);    // Turn off all pedestrian red lights 
  delay (3000);
  
  digitalWrite (pgreen, LOW); // Turn off all pedestrian green lights after the pedestrian crosses the street for a predefined period of time.
  delay(250);

  for (int x = 0; x < 5; x++) // Flash pedestrian green lights 5 times to signal the crossing time is up. 
  {  
    digitalWrite(pgreen, HIGH);
    delay(250);
    digitalWrite(pgreen, LOW);
    delay(250);
  }

  digitalWrite(pRed, HIGH);   // Turn on all pedestrian red lights to end the pedestrian cycle. 
  
}
