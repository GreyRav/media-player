#include <Arduino.h>
#include <HID-Project.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


// Defi des pin pour les boutons
const int PREV_BTN = 5; // bouton back 
const int PLAY_BTN = 6; // bouton de play & pause
const int NEXT_BTN = 7; // bouton suivant

// Conf de l'ecran
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // bouton reset inexistant

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {

  Wire.begin();
  
  // config des pins en entrée pull-up
  pinMode(PREV_BTN, INPUT_PULLUP);
  pinMode(PLAY_BTN, INPUT_PULLUP);
  pinMode(NEXT_BTN, INPUT_PULLUP);

  // initianilisation des touches media 
  Consumer.begin();
  
  // initialiser l'ecran
  if (display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("Erreure");
  }

  display.clearDisplay();
  display.setTextSize(1, 2); // (1, 1)
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,32);
  display.println("Media Controller");
  display.display();  

}

void loop() {

  // Gestion bouton back
  if (digitalRead(PREV_BTN) == LOW)
  {
    Consumer.write(MEDIA_PREVIOUS);
    // affichage sur l'ecran
    display.clearDisplay();
    display.setCursor(0,32);
    display.println("Back");
    display.display();
    delay(200);
    Consumer.releaseAll();
    delay(1000);
    display.clearDisplay();
    display.setCursor(0,32);
    display.println("Media Player");
    display.display();
  }

  // Gestion bouton play/pause
  if (digitalRead(PLAY_BTN) == LOW)
  {
    Consumer.write(MEDIA_PLAY_PAUSE);
    // affichage sur l'ecran
    display.clearDisplay();
    display.setCursor(0,32);
    display.println("Play/pause");
    display.display();
    delay(200);
    Consumer.releaseAll();
    delay(1000);
    display.clearDisplay();
    display.setCursor(0,32);
    display.println("Media Player");
    display.display();
    
  }

  if (digitalRead(NEXT_BTN) == LOW)
  {
    Consumer.write(MEDIA_NEXT);
    // affichage sur l'ecran
    display.clearDisplay();
    display.setCursor(0,32);
    display.println("Next");
    display.display();
    delay(200);
    Consumer.releaseAll();
    delay(1000);
    display.clearDisplay();
    display.setCursor(0,32);
    display.println("Media Player");
    display.display();
  }
  
}

