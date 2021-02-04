// ВНИМАНИЕ! Файл с примерном не является родным форматом для IDE, поэтому при его компиляции 
// вместо русских букв на экране возможны "кракозяблы". Во вновь созданных проектах (*.INO)
// компилироваться все будет верно.

#include <Adafruit_GFX_rus.h>
#include <Adafruit_PCD8544_rus.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); //CLK, DIN, DC, CE, RST

//char questions[5][4][70] = {{"Сколько будет 2+2*2?", "1 - 6", "2 - 8", "1"},
//                            {"Сколько будет 4+3*0?", "1 - 7", "2 - 4", "2"},
//                            {"Столица Франции?", "1 - Лондон", "2 - Париж", "2"},
//                            {"Столица Англии?", "1 - Лондон", "2 - Нью-Йорк", "1"},
//                            {"Где проходила олимпиада 2014?", "1 - Сочи", "2 - Москва", "2"}};

void choiceQuestion(){
  display.clearDisplay();
  display.print("Сколько будет ");
  int rand1 = random(100);
  display.print(rand1);
  display.print(" + ");
  int rand2 = random(100);
  display.print(rand2);
  display.println("?");
  int ans1 = rand1+rand2;
  int ans2 = rand1+rand2-random(10);
  display.println();
  display.print("1 - ");
  display.println(ans1);
  display.print("2 - ");
  display.println(ans2);
  display.display();
}

void setup() {
  display.begin();
  display.clearDisplay();
  display.setContrast(60);
  display.setCursor(0, 0); 
  display.setTextSize(2); 
  display.println("ЭРУДИТ");
  display.setTextSize(1);
  display.println();
  display.println("Автор:");
  display.println("Катков Илья");
  display.display();
  delay(3000);
}

void loop() {
  for (int q = 0; q < 3; q++){
      int randint = random(3);
      choiceQuestion();
      delay(3000);
  }
  
}
