// ERUDIT
// by Ilya Katkov
// v 1.0.0

#include <Adafruit_GFX_rus.h>
#include <Adafruit_PCD8544_rus.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); //CLK, DIN, DC, CE, RST

int score = 0;
int lives = 3;

void getQuestion(){
  float temp_num;
  float ans1;
  float ans2;
  
  display.clearDisplay();
  Serial.print("Новый пример: ");
  display.print("Сколько будет ");
  float rand_num1 = random(-99, 100);
  float rand_num2 = random(-99, 100);
  while (rand_num1 == rand_num2){
    float rand_num1 = random(-99, 100);
    float rand_num2 = random(-99, 100);
  }
  Serial.print((int)rand_num1);
  display.print((int)rand_num1);

  int rand_operator = random(4);
  if (rand_operator == 0){
    display.print(" + ");
    Serial.print(" + ");
    temp_num = rand_num1+rand_num2;
  } else if (rand_operator == 1){
    display.print(" - ");
    Serial.print(" - ");
    temp_num = rand_num1-rand_num2;
  } else if (rand_operator == 2){
    display.print(" * ");
    Serial.print(" * ");
    temp_num = rand_num1*rand_num2;
  } else if (rand_operator == 3){
     if (rand_num2 == 0){
        display.print(" * ");
        Serial.print(" * ");
        temp_num = rand_num1*rand_num2;
     }
     else {
        display.print(" / ");
        Serial.print(" / ");
        temp_num = rand_num1/rand_num2;
      }
  }
  Serial.print((int)rand_num2);
  display.print((int)rand_num2);
  Serial.println("?");
  display.println("?");
  display.println();

  int rand_right = random(0,2);
  if (rand_right == 0){
    ans1 = temp_num;
    ans2 = temp_num-random(10);
    while (ans1 == ans2){
      ans1 = temp_num;
      ans2 = temp_num-random(10);
    }
    Serial.print("Правильный ответ: ");
    Serial.print(ans1);
    Serial.print(" (");
    Serial.print(rand_right+1);
    Serial.println(")");
  }
  else if (rand_right == 1){
    ans1 = temp_num-random(10);
    ans2 = temp_num;
    while (ans1 == ans2){
      ans1 = temp_num-random(10);
      ans2 = temp_num;
    }
    Serial.print("Правильный ответ: ");
    Serial.print(ans2);
    Serial.print(" (");
    Serial.print(rand_right+1);
    Serial.println(")");
  }
  display.print("1) ");
  display.println(ans1);
  display.print("2) ");
  display.println(ans2);
  display.print("Счет:");
  display.print(score);
  display.print(" Жизни:");
  display.print(lives);
  display.display();

  bool finish = true;
  while (finish){
    if (digitalRead(10) == 0 and rand_right == 0){
      Serial.println("Выбран правильный вариант 1");
      score++;
      finish  = false;
    }
    else if (digitalRead(9) == 0 and rand_right == 1){
      Serial.println("Выбран правильный вариант 2");
      score++;
      finish  = false;
    } 
    else if (digitalRead(10) == 0 and rand_right == 1){
      Serial.println("Ответ неверный!");
      lives--;
      finish  = false;
    }
    else if (digitalRead(9) == 0 and rand_right == 0){
      Serial.println("Ответ неверный!");
      lives--;
      finish  = false;
    }
  }  
    delay(1000);
    return;
}

void setup() {
  randomSeed(analogRead(micros()));
  Serial.begin(9600);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  display.begin();
  Serial.println("Game started!");
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
  delay(1000);
}

 
void loop() {
  if (lives == 0){
    display.clearDisplay();
    display.setTextSize(1);
    display.println();
    display.println("Вы проиграли!");
    display.print("Ваш счет:");
    display.println(score);
    display.println();
    display.println("Перезапуск...");
    display.display();
    delay(2000);
    lives = 3;
  }
  else {
    getQuestion();
  }
}
