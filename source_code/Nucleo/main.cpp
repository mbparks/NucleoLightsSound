#include "mbed.h"
 
AnalogIn leftChannel(A0);  // left channel
AnalogIn rightChannel(A1);  // right channel
 
DigitalOut leftLED_LOW(D2);
DigitalOut leftLED_MED(D3);
DigitalOut leftLED_HIGH(D4);

DigitalOut rightLED_LOW(D5);
DigitalOut rightLED_MED(D6);
DigitalOut rightLED_HIGH(D7);

void setLeftLED_OFF();
void setLeftLED_LOW();
void setLeftLED_MED();
void setLeftLED_HIGH();

void setRightLED_OFF();
void setRightLED_LOW();
void setRightLED_MED();
void setRightLED_HIGH();

int main() {
    float leftChannelSignal;
    float rightChannelSignal;
    float lowCutoff = 10;
    float mediumCutoff = 1000;
    float highCutoff = 2000;
    
    
    printf("\nTurn Sound Into Light\n");
    
    while(1) {
        leftChannelSignal = leftChannel.read(); // Converts and read the analog input value (value from 0.0 to 1.0)
        rightChannelSignal = rightChannel.read(); // Converts and read the analog input value (value from 0.0 to 1.0)
        
        
        leftChannelSignal = leftChannelSignal * 3300; // Change the value to be in the 0 to 3300 range
        rightChannelSignal = rightChannelSignal * 3300; // Change the value to be in the 0 to 3300 range
        
        printf("L Channel = %.0f mV\n", leftChannelSignal);
        printf("R Channel = %.0f mV\n", rightChannelSignal);
        
        //LEFT CHANNEL
        if (leftChannelSignal <= lowCutoff) { 
            setLeftLED_OFF();
        }
        
        else if (leftChannelSignal > lowCutoff && leftChannelSignal <= mediumCutoff) { 
            setLeftLED_LOW();
        }
        
        else if (leftChannelSignal > mediumCutoff && leftChannelSignal <= highCutoff) { 
            setLeftLED_MED();
        }
        
        else {
            setLeftLED_HIGH();
        }
        
        
        
        
        //RIGHT CHANNEL
        if (rightChannelSignal <= lowCutoff) { 
            setRightLED_OFF();
        }
        
        else if (rightChannelSignal > lowCutoff && rightChannelSignal <= mediumCutoff) { 
            setRightLED_LOW();
        }
        
        else if (rightChannelSignal > mediumCutoff && rightChannelSignal <= highCutoff) { 
            setRightLED_MED();
        }
        
        else {
            setRightLED_HIGH();
        }     
              
        //wait(0.2); // 200 ms
    }
}


//LEFT CHANNEL
void setLeftLED_OFF(){
    leftLED_LOW = 0;
    leftLED_MED = 0;
    leftLED_HIGH = 0;
}        

void setLeftLED_LOW(){
    leftLED_LOW = 1;
    leftLED_MED = 0;
    leftLED_HIGH = 0;
}

void setLeftLED_MED(){
    leftLED_LOW = 1;
    leftLED_MED = 1;
    leftLED_HIGH = 0;
}

void setLeftLED_HIGH(){
    leftLED_LOW = 1;
    leftLED_MED = 1;
    leftLED_HIGH = 1;
}







//RIGHT CHANNEL
void setRightLED_OFF(){
    rightLED_LOW = 0;
    rightLED_MED = 0;
    rightLED_HIGH = 0;
}        

void setRightLED_LOW(){
    rightLED_LOW = 1;
    rightLED_MED = 0;
    rightLED_HIGH = 0;
}

void setRightLED_MED(){
    rightLED_LOW = 1;
    rightLED_MED = 1;
    rightLED_HIGH = 0;
}

void setRightLED_HIGH(){
    rightLED_LOW = 1;
    rightLED_MED = 1;
    rightLED_HIGH = 1;
}