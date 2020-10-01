#include <FastLED.h>
#define NUM_LEDS 48
#define DATA_PIN 4
CRGB leds[NUM_LEDS];

int tension, val;

//============================================================

void setup()  
{ 
   
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); 
   
} 

//============================================================

void loop()  
{  
   
tension = analogRead(A0); // on lit la valeur du Potentiomètre
val = map(tension,0,1023,0,2*255);
if( val < 255)
ledRVBpwm(0,val,255-val);

if( val >= 255 && val <= 2*255)
ledRVBpwm(val-255, 255-(val-255),0);

}

//============================================================

void ledRVBpwm(int pwmRouge, int pwmVert, int pwmBleu) { // reçoit valeur 0-255 par couleur
//leds[0] = CRGB(pwmRouge, pwmVert, pwmBleu);
for (int i=0; i<48; i++){
  leds[i] = CRGB(pwmRouge, pwmVert, pwmBleu);
  FastLED.show();
}
}
