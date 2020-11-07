
// Double backlash indicates comment. compiler ignore this statemets.
/*
 * backlash plus asteris for multiple line of comment
 */

/*  Title: TTL OTG, Handler Function
 * 
 */

// This library is defualt and must include for standard syntax use by arduino.
#include <Wire.h>
/* This are some example that already use on this program, see other tutorial on web for complete Synatx https://www.arduino.cc/reference/en/
 *  _______________________________________________________________________ _____________________________________________________________________
 *  |                          Syntax                                      |                               Function                              |
 *  +--------------------------------------------------------------------------------------------------------------------------------------------+
 *  | pinMode(X, OUTPUT);  pinMode(X, INPUT) x = represent pin on Arduino  | Initialize and set the pin of arduino. either set as input or output|
 *  |--------------------------------------------------------------------------------------------------------------------------------------------|
 *  | digitalWrite(X, HIGH);  digitalReade(X, LOW);                        |  Force or Sense a Voltage or Logic on the specific Pin              |
 *  |                 X = the pin do the Force a Voltage High or Low       |   Example:  digitalWrite(2, HIGH);                                  |
 *  |                                                                      |  D2 on Arduino, pin 4 on ATMEGA328P will force High or Logic 1      |
 *  |--------------------------------------------------------------------------------------------------------------------------------------------|  
 *  | analogWrite(X, Y)  analogRead(X, Y)                                  | Force or Sense Variable Voltage 0 volts up to 5 volts               |
 *  |        X = Pin that do force/sense                                   | but represent a 0 to 255 not actual 1 to 5                          |
 *  |        Y = Value of Force/Sense Voltage (0 - 255)                    | Example:   analogWrite(A0, 30); which means force a 0.58 volts      |
 *  |                                                                      |                            (5/255) X 30 = 0.58                      | 
 *  |--------------------------------------------------------------------------------------------------------------------------------------------|
 *  | lcd.print("Hello Word");                                             | print characters that depends on Cursor.                            |
 *  +--------------------------------------------------------------------------------------------------------------------------------------------+
 *  | lcd.clear();                                                         | Clear all charcters on LCD Display                                  |
 *  +--------------------------------------------------------------------------------------------------------------------------------------------+
 */

//// This Library use for manipulating the lcd
#include <LiquidCrystal_I2C.h>
/* This are the useful methods.
 *  _______________________________________________________________________ _____________________________________________________________________
 *  |                          Syntax                                      |                               Function                              |
 *  +--------------------------------------------------------------------------------------------------------------------------------------------+
 *  | LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);       |   This is a configuration code for specific LCD Hardware do not edit|
 *  |--------------------------------------------------------------------------------------------------------------------------------------------|
 *  | lcd.begin(20, 4);                                                    |   Initialize the lcd and set the resolution.                        |
 *  |                 this code declare on setup Function                  |   (20, 4)  = 20 Characters can display Horizontaly                  |
 *  |                                                                      |            = 4 Rows or 4 lines can display                          |
 *  |--------------------------------------------------------------------------------------------------------------------------------------------|  
 *  | lcd.setCursor(Y, X)  = X,Y must be any constant number.              | pointing where to display a character.                              |
 *  |                                                                      | Y = column  X = row                                                 |
 *  |                                                                      | Example:display a letter C on specific location.                    |
 *  |                                                                      | lcd.setCursor(5, 0); column 5 , row 0 letter C will be located.     | 
 *  |--------------------------------------------------------------------------------------------------------------------------------------------|
 *  | lcd.print("Hello Word");                                             | print characters that depends on Cursor.                            |
 *  +--------------------------------------------------------------------------------------------------------------------------------------------+
 *  | lcd.clear();                                                         | Clear all charcters on LCD Display                                  |
 *  +--------------------------------------------------------------------------------------------------------------------------------------------+
 */

 //actual code
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

 //--------------------------------------------------------------------------------------------------------------------------------------------------
 

//// This Library do multiplexing fucntion to work on keypad. So that you can code with ease.
#include <Keypad.h>
/* This are the useful methods.
 *  _______________________________________________________________________ _____________________________________________________________________
 *  |                          Syntax                                      |                               Function                              |
 *  +--------------------------------------------------------------------------------------------------------------------------------------------+
 *  | char anyname = customKeypad.getKey();                                |  customKeypad.get() Function start multiplexing the keypad          |
 *  |                                                                      |                     This indicates initiative for getting           |
 *  |                                                                      |                     what user push on keypad and can be done by     |
 *  |                                                                      |                     using if statement.                             |  
 *  |                                                                      | Example:                                                            |
 *  |                                                                      |           char myKeypad = customKeypad.getKey();                    |
 *  |                                                                      |           if(myKepad == 'A')                                        |
 *  |                                                                      |           {                                                         |
 *  |                                                                      |                 //some code to execute.                             |        
 *  |                                                                      |           }                                                         |
 *  |--------------------------------------------------------------------------------------------------------------------------------------------|
 */

const byte ROWS = 4; //represent row
const byte COLS = 4; //represent column

//This Array is use by Keypad Library for reference on Actual keypad mapping. Careful if you want to edit.
 char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// This Variable is use to Assign the Kepad pins to Arduino Pins
byte rowPins[ROWS] = {9, 8, 7, 6}; // Arduino pin 6 to 9 is connected to Keypad pins Row pin 5 to 8
byte colPins[COLS] = {5, 4, 3, 2}; // Arduino pin 2 to 5 is connected to Keypad pins Column pin 1 to 4

// initialize Keypad command. Donot edit
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//---------------------------------------------------------------------------------------------------------------------------------------------------


//** Definning a Arduino Pin to Meaningful Name Tag
#define Cpin1Bin1 10 // Cpin1Bin1 = Count pin 1 for Bin 1 is Assign to Digital pin 10 of Arduino
#define Cpin8Bin8 11 // Cpin8Bin8 = Count pin 8 for bin 8 is Assign to Digital pin 11 of Arduino
#define Cpin24EOT 13 // Cpin24EOT = Count pin 24 for EOT is Assign to Digital pin 13 of Arduino
#define Cpin2 A0     // Cpin2     = Count pin 2 for Other binning cathegory is Assign to Analog pin A0
#define Cpin7 A1     // Cpin7     = Count pin 7 for Other binning cathegory is Assign to Analog pin A1 
#define Cpin10SOT 12 // Cpin10SOT = Count pin 10 for SOT is Assign to Digital pin 12 of Arduino
#define Trig A3      // Trig      = Trigger the Reset Pin of 555 Timer (pin 4)
//*******************************************************


//These Variable are used for counting or record of binning

int p = 1, f = 1, s = 1;
/*  p = Passed
 *  f = fail
 *  s = counting of SOT
 */ 
//*******************************************



// These Variable are responsible for Design Special Character.
/*   this will be the output. It will encounter in first power on of device
 *    _________________________
 *   |                         |
 *   |    ❤   TTL OTG  ❤      |
 *   |_________________________|
 */
byte edgeupright[] = {B00000, B00111, B00100, B00100, B00100, B00100, B00100, B00100};
byte edgeupleft[] = {B00000, B11100, B00100, B00100, B00100, B00100, B00100, B00100};
byte edgedownright[] = {B00100, B00100, B00100, B00100, B00100, B00100, B00111, B00000};
byte edgedownleft[] = {B00100, B00100, B00100, B00100, B00100, B00100, B11100, B00000};
byte upconnect[] = {B00000, B11111, B00000, B00000, B00000, B00000, B00000, B00000};
byte downconnect[] = {B00000, B00000, B00000, B00000, B00000, B00000, B11111, B00000};
byte heart[] = {B00000, B00000, B11011, B11111, B11111, B01110, B00100, B00000};

//*****************************************************************************************



int Data_Serial;
bool result = true;
bool str = true;
bool pause = false;
byte str2 = 0;
byte stp = 0;
byte nxt = 0;
int CurrentPin;
int Hold;
int num1, num2, num3, num4;
byte INcount;
bool Stat = true;
bool pinCont;
bool Bining;
byte FinalCont = 0;
byte rst = 0;
int CountSOT = 0, CountBin1 = 0, CountBin8 = 0, CountEOT = 0;
bool Dmode = true;
String mode;
bool End;



// Funtion that responsible for simulation on Handler Mode ---------------------------------------//
// This function will run if Loop/Main function call this.
void HandlerRun() {
 
    // ---- Display Initial or Updated Binning Count
    lcd.setCursor(7, 1);
    lcd.print(String(CountBin1));
    lcd.setCursor(17, 1);
    lcd.print(String(CountBin8));
    lcd.setCursor(15, 3);
    lcd.print(String(CountEOT));
    //
    //----------------------------------------
    
    //------- Send SOT
    delay(100);
    digitalWrite(Cpin10SOT, LOW);
    delay(10);
    digitalWrite(Cpin10SOT, HIGH);
    ////
    lcd.setCursor(17, 0);
    lcd.print("X");
    lcd.setCursor(15, 2);
    lcd.print(String(CountSOT += 1));
    lcd.setCursor(17, 0);
    lcd.print("+");
    Bining = true;
    End = false;
    while (Bining) {
         if(digitalRead(Cpin1Bin1) == LOW){
           CountBin1 += 1;
           Bining = false;
           End = true;
         }
         
         if(digitalRead(Cpin8Bin8) == LOW){
           CountBin8 += 1;
           Bining = false;
           End = true;
         }
      }

   while(End){
        if(digitalRead(Cpin24EOT) == HIGH ){
          CountEOT += 1;
   
          analogWrite(Trig,0); // Trigger the reset of 555 timer
          delay(5);
          analogWrite(Trig,255); // back to defualt status
          End = false;
        }
   }
      /*
                                                                                                                                                                                                                                                                                                                                                                                  for continuation error promp when no longer detect bining
        if(tym == 49){
        PrompError();
        }
      */
    }




//------------------------------------------------------------------------------
/*
 * setup Function will run once 
 * 
 * 
 */

void setup() {
  Serial.begin(9600);                    // initialize Serial communication and set bound rate to communicate to other IC. initialize for later use. not actual running.
  lcd.begin(20, 4);                      // initialize and set the resolution of LCD

//--------------------------------------------------------------------------------------- 
  //Varialbe that use on Disign Display
  /*   this will be the output. It will encounter in first power on of device
 *    _________________________
 *   |                         |
 *   |    ❤   TTL OTG  ❤      |
 *   |_________________________|
 */
  lcd.createChar(0, edgeupright);        
  lcd.createChar(1, edgeupleft);
  lcd.createChar(2, edgedownright);
  lcd.createChar(3, edgedownleft);
  lcd.createChar(4, upconnect);
  lcd.createChar(5, downconnect);
  lcd.createChar(6, heart);
//---------------------------------------------------------------------------------------

}




//------------------------------------------------------------------------------------------
/*
 * loop function run the code repeatedly. represent main function.
 * 
 */

void loop() {

lcd.setCursor(0, 0);
lcd.write(byte(0));



//----------------- This code is a process to Display a Design Pattern of Home Display
  /*   this will be the output. It will encounter in first power on of device
 *    _________________________
 *   |                         |
 *   |    ❤   TTL OTG  ❤      |
 *   |_________________________|
 */
  for (int c = 1; c <= 18; c++)
  {
    lcd.setCursor(c, 0);
    lcd.write(byte(4));
  }
  lcd.setCursor(19, 0);
  lcd.write(byte(1));
  lcd.setCursor(0, 1);
  lcd.print("|");
  lcd.setCursor(3, 1);
  lcd.write(byte(6));
  lcd.setCursor(6, 1);
  lcd.print("TTL  OTG ");
  lcd.setCursor(16, 1);
  lcd.write(byte(6));
  lcd.setCursor(19, 1);
  lcd.print("|");
  lcd.setCursor(0, 2);
  lcd.write(byte(2));
  for (int c = 1; c <= 18; c++) {
    lcd.setCursor(c, 2);
    lcd.write(byte(5));
  }
  lcd.setCursor(19, 2);
  lcd.write(byte(3));
  lcd.setCursor(0, 3);

//-----------------------------------------------------------------


  
  delay(2000); // delay next code to execute by 2000 mili seconds


//------------------- This code will Display This ---------
/*
 *     ___________________________________________________
 *    |                                                   |
 *    |                 Choose OTG Mode                   |
 *    | (A) Tester                                        |
 *    | (B) handler                                       |
 *    | (C) Cable                                         |
 *    |___________________________________________________|
 */
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Choose OTG Mode");
  lcd.setCursor(0,1);
  lcd.print("(A) Tester");
  lcd.setCursor(0,2);
  lcd.print("(B) Handler");
  lcd.setCursor(0,3);
  lcd.print("(C) Cable");

//---------------------------------------------------------------------

  
  
  
 //---- Waiting for user input 
 /* 
  *  Expected to sense from Keypad 
  *  This Loop will not End until user will be choose the Device Mode
  *  
  */
  while (Dmode) {
    char customKey = customKeypad.getKey(); 
    if (customKey == 'A') {
      mode = "tester";
      delay(10);
      Dmode = false;
    }
    if (customKey == 'B') {
      mode = "handler";
      delay(10);
      Dmode = false;
    }
    if(customKey == 'C'){
      mode = "cable";
      delay(10);
      Dmode = false;
    }
  }

//------------------------------------------------------




//---- this Loop will run Handler Mode

  while (mode == "handler") {
        
        lcd.clear();
        //
        //initialize and set Arduino pin and ready for Handler run function.
        pinMode(Cpin10SOT, OUTPUT);
        pinMode(Cpin24EOT, INPUT);
        pinMode(Cpin1Bin1, INPUT);
        pinMode(Cpin8Bin8, INPUT);
        //----------------------------------------------------------------
        
        delay(1);
        
        digitalWrite(Cpin10SOT,HIGH);  // Send SOT
        delay(100); // Width of SOT 100 Miliseconds
        
        //initial of 555 timer reset pin
        analogWrite(Trig,255);  // 
        //
        
        lcd.clear();

//------------------- This code will Display This ---------
/*
 *     ___________________________________________________
 *    |                                                   |
 *    | Run (B)  Stop (A)                                 |
 *    | Bin 1 :                   Bin 8:                  |
 *    | Bin 2 :                   SOT:                    |
 *    | Bin 7 :                   EOT:                    |
 *    |___________________________________________________|
 */      
        lcd.setCursor(0, 0);
        lcd.print("Run(B)");
        lcd.setCursor(6, 0);
        lcd.print("Stop(C)");
        lcd.setCursor(0, 1);
        lcd.print("Bin 1: ");
        lcd.setCursor(10, 1);
        lcd.print("Bin 8: ");
        lcd.setCursor(0, 2);
        lcd.print("Pin 2: ");
        lcd.setCursor(10, 2);
        lcd.print("SOT: ");
        lcd.setCursor(0, 3);
        lcd.print("Pin 7: ");
        lcd.setCursor(10, 3);
        lcd.print("EOT: ");

 //------------------------------------------------------

 
 //--------- This Loop wait for user input to start the handler run
 /*
  *   if B is press on Keypad This loop will call another Function called HandlerRun()
  *    and if C Handler Function must Stop. but currently Has Bug. For Fix.
  * 
  */
    
  while(Stat){      
        while(str){
        char customKey = customKeypad.getKey();
        if(customKey == 'C'){
          pause = true;
            while(pause){
                   if(customKey == 'B'){
                    pause = false;
                    break;
                   }
            }
        }
        
        if(customKey == 'B'){
       
        HandlerRun();
        }
        
        }
        
  }//while stat curly brace

        
  }//handler mode curly brace




// This Loop is responsible for tester Mode ----
/*
 *   in this Mode Serial Comminication involve via RX (Pin 2 Atmega)  TX (Pin 3 Atmega)
 *  
 */
  while (mode == "tester") {
    
    Serial.write(2); // Serial Write Send a String of data(1 and 0 that represent a Value of 2 as of code you see) via pin 3 of Atmega TX(Transmitter) 

    
    delay(10);

//------------------- This code will Display This ---------
/*
 *     ___________________________________________________
 *    |                                                   |
 *    |                  Tester Mode                      |
 *    | Passed:                                           |
 *    | Failed:                                           |
 *    | SOT:                                              |
 *    |___________________________________________________|
 */ 
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Tester Mode");
    lcd.setCursor(0, 1);
    lcd.print("Passed: ");
    lcd.setCursor(0, 2);
    lcd.print("Failed: ");
    lcd.setCursor(0, 3);
    lcd.print("SOT: ");

//----------------------------------------------------------


//------------------ This Loop run the tester mode function

    while (1) {
      // Serial.available is a code waiting for serial data to recieve
      if (Serial.available() > 0) {
        Data_Serial = Serial.read(); // assign a recieved data to a variable.

        
     // Determin and Sort what signal receive from tester IC 
     /* We decide and assign a serial data to specific binning
      *  Serial data 10 for SOT
      *  Serial data 8 for bin 8
      *  Serial data 1 for bin 1
      */
        if (Data_Serial == 10) {
          lcd.setCursor(5, 3);
          lcd.print(String(s++));
        }
        if (Data_Serial == 1) {
          lcd.setCursor(8, 1);
          lcd.print(String(p++));
        }
        if (Data_Serial == 8) {
          lcd.setCursor(8, 2);
          lcd.print(String(f++));
        }

      }
    }

  } //tester mode




////---------------------  This is Cable mode option
/*
 *  Do not use this code. this is ongoing experimentation.
 *  ongoing development.
 * 
 */
  while(mode == "cable"){
    Serial.write(3);
    delay(10);
    lcd.clear();
     pinMode(Cpin10SOT, INPUT);
     pinMode(Cpin24EOT, INPUT);
     pinMode(Cpin1Bin1, INPUT);
     pinMode(Cpin8Bin8, INPUT);

     lcd.setCursor(3,0);
     lcd.print("Cable Checking");
     lcd.setCursor(0,1);
     lcd.print("PIN 1:");
     lcd.setCursor(9,1);
     lcd.print("PIN 8:");
     lcd.setCursor(0,2);
     lcd.print("PIN 10:");
     lcd.setCursor(9,3);
     lcd.print("PIN 24:");

     while(1){

       if(digitalRead(Cpin1Bin1) == HIGH){
        lcd.setCursor(6,1);
        lcd.print("OK");
       }
       else{
        lcd.setCursor(6,1);
        lcd.print("fail");
       }

       if(digitalRead(Cpin8Bin8) == HIGH){
        lcd.setCursor(15,1);
        lcd.print("OK");
       }
       else{
        lcd.setCursor(15,1);
     lcd.print("fail");
       }

       if(digitalRead(Cpin10SOT) == HIGH){
        lcd.setCursor(6,2);
          lcd.print("OK");
       }
       else{
        lcd.setCursor(6,2);
     lcd.print("fail");
       }
       if(digitalRead(Cpin24EOT) == HIGH){
       lcd.setCursor(15,3);
          lcd.print("OK");
       }
       else{
       lcd.setCursor(15,3);
     lcd.print("fail");
       }
      
     }
}

//---------------------------------------------------------------------------------

  
} // loop curly brace
