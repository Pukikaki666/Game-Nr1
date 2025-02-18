#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS  // Отключаем предупреждения для небезопасных функций

int main() {
    char playAgain = 'y';  // Переменная для хранения ответа пользователя на вопрос "Хотите сыграть еще раз?"
    int totalScore = 0;    // Общий счет игрока

    while (playAgain == 'y' || playAgain == 'Y') {  // Основной цикл игры, пока пользователь хочет играть
        // Инструкции для игрока
        printf("Dobro pozhalovat' v igru! Ya zagadal chislo ot 0 do 10.\n");
        printf("U vas est' 3 popytki, chtoby ugadat' chislo.\n");

        // Инициализация генератора случайных чисел
        srand((unsigned int)time(NULL));  // Инициализируем генератор случайных чисел текущим временем
        int secretNumber = rand() % 11;   // Генерируем случайное число от 0 до 10

        int attempts = 0;  // Счетчик попыток
        int maxAttempts = 3;  // Максимальное количество попыток

        while (attempts < maxAttempts) {  // Цикл для попыток угадать число
            int userGuess;
            printf("Vvedite vashe predpolozhenie: ");
            scanf_s("%d", &userGuess);  // Считываем число, введенное пользователем

            attempts++;  // Увеличиваем счетчик попыток

            // Проверяем, угадал ли пользователь число
            if (userGuess < secretNumber) {
                printf("Slishkom malo! Poprobuyte eshche raz.\n");
            }
            else if (userGuess > secretNumber) {
                printf("Slishkom mnogo! Poprobuyte eshche raz.\n");
            }
            else {
                printf("Pozdravlyayu! Vy ugadali chislo %d za %d popytok.\n", secretNumber, attempts);
                totalScore += (maxAttempts - attempts + 1) * 10;  // Начисляем очки: чем меньше попыток, тем больше очков
                printf("Vash tekushchiy schet: %d\n", totalScore);

                // Определяем ранг игрока
                if (totalScore < 20) {
                    printf("Vash rang: Bronze\n");
                }
                else if (totalScore < 40) {
                    printf("Vash rang: Silver\n");
                }
                else {
                    printf("Vash rang: Gold\n");
                }

                break;
            }

            // Подсказка: больше или меньше 5
            if (attempts == 1) {  // Даем подсказку после первой попытки
                if (secretNumber > 5) {
                    printf("Podskazka: chislo bol'she 5.\n");
                }
                else {
                    printf("Podskazka: chislo men'she ili ravno 5.\n");
                }
            }

            // Если попытки закончились
            if (attempts == maxAttempts) {
                printf("K sozhaleniyu, vy ne ugadali chislo. Eto bylo %d.\n", secretNumber);
            }
        }

        // Спрашиваем, хочет ли пользователь сыграть еще раз
        printf("Khotite sygrat' eshche raz? (y/n): ");
        scanf_s(" %c", &playAgain);  // Считываем ответ пользователя
    }

    // Завершение игры
    printf("Spasibo za igru! Vash itogovyy schet: %d. Do svidaniya!\n", totalScore);

    // Определяем итоговый ранг
    if (totalScore < 20) {
        printf("Vash rang: Bronze\n");
    }
    else if (totalScore < 40) {
        printf("Vash rang: Silver\n");
    }
    else {
        printf("Vash rang: Gold\n");
    }

    return 0;  // Завершаем программу
}