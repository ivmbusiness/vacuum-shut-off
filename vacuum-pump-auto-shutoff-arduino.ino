
#include <SPI.h>
#include <TFT.h>

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8

TFT screen = TFT(TFT_CS, TFT_DC, TFT_RST);

String lines[5]={};

int sensorPin=A4;
int dOut=4; 

void setup() {
   pinMode(dOut, OUTPUT); 
  // put your setup code here, to run once:
  screen.begin();
  screen.background(0,0,0);

  screen.setTextSize(3);
  
  outputText(1, "line 1");
  outputText(2, "line 1.1");
  delay(1000);

  outputText(1, "line 2");
  outputText(2, "line 2.1");
}


void outputText(int lineNum, String newText){
  if (lines[lineNum])
  {
    if (newText.equals(lines[lineNum]))
    {
      return;
    }
    _clearText(lineNum, lines[lineNum]);
  }
  
  screen.stroke(255,255,255);
  _writeText(lineNum, newText);
  lines[lineNum]=newText;
}

void _writeText(int lineNum, String newText)
{
  int yOffset=lineNum*30;
  screen.text(newText.c_str(), 10, yOffset);
}


void _clearText(int lineNum, String newText)
{
  screen.stroke(0,0,0);
  _writeText(lineNum, newText);
}


const float vConst=0.004882813;
const float zV=1.9336;
const float onLimit=-60;
const float offLimit=-70;

int cnt=0;
void loop() {
  delay(1000);
  int val = analogRead(sensorPin);

  float vCurrent=(float)val*vConst;
  float pr=-1*(zV-vCurrent)*100.0/(zV-0.5);
  outputText(1, String(pr,1));

  if (pr>onLimit)
  {
    digitalWrite(dOut, HIGH);
    outputText(3, String("ON"));
  }
  else if (pr<offLimit) {
    digitalWrite(dOut, LOW);
    outputText(3, String("OFF"));
  }
  cnt++;
  outputText(2, String(cnt));
}
