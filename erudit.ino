
#include <Adafruit_GFX_rus.h>
#include <Adafruit_PCD8544_rus.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); //CLK, DIN, DC, CE, RST


// генерируются 2 случайных числа от 0 до 99, генерируется математический оператор, и два возможных ответа
void getQuestion(int points){

  double temp_num;
  double ans1;
  double ans2;

  int steps = 0;
  display.clearDisplay();
  display.print("Сколько будет ");
  int rand_num1 = random(-90+steps%10, points%100);
  int rand_num2 = random(-90+points%10, points%100);
  while (rand_num1 == rand_num2){
    steps = steps +1;
    Serial.print("Были одинаковые числа в вопросе:");
    Serial.print(rand_num1);
    Serial.print(" и ");
    Serial.println(rand_num2);
    int rand_num1 = random(-90+steps%10, points%100);
    int rand_num2 = random(-90+points%10, points%100);
  }
  display.print(rand_num1);

// рандом выражения
  int rand_operator = random(4);
  if (rand_operator == 0){
    display.print(" + ");
    temp_num = rand_num1+rand_num2;
  } else if (rand_operator == 1){
    display.print(" - ");
    temp_num = rand_num1-rand_num2;
  } else if (rand_operator == 2){
    display.print(" * ");
    temp_num = rand_num1*rand_num2;
  } else if (rand_operator == 3){
    display.print(" / ");
    temp_num = rand_num1/rand_num2;
  }

  display.print(rand_num2);
  display.println("?");
  display.println();

  int rand_right = random(0,2);
  if (rand_right == 0){
    ans1 = temp_num;
    ans2 = temp_num-random(10-random(steps%10));
    while (ans1 == ans2){
      steps = steps +1;
      Serial.println("Были одинаковые числа в ответах 2.");
      ans1 = temp_num;
      ans2 = temp_num-random(10-random(steps%10));
    }
  }
  else {
    ans1 = temp_num-random(10-random(steps%10));
    ans2 = temp_num;
    while (ans1 == ans2){
      steps = steps +1;
      Serial.println("Были одинаковые числа в ответах 1.");
      ans1 = temp_num-random(10-random(steps%10));
      ans2 = temp_num;
    }
  }
  display.print("1 - ");
  display.println(ans1);
  display.print("2 - ");
  display.println(ans2);
  display.display();
}

void setup() {
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
}

 
void loop() {
  int steps = 0;
  while ((digitalRead(9) == 1) and (digitalRead(10) == 1)){
    if (digitalRead(9) == 0){
    Serial.println("Нажата левая кнопка");
    } else if (digitalRead(10) == 0){
    Serial.println("Нажата правая кнопка");
    }
  steps = steps+1;
  }
  delay(200);
randomSeed(analogRead(0));
Serial.println(12/4.5);
  getQuestion(steps);
}
