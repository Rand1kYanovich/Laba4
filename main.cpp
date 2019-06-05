#include <stdio.h>
#include <stdlib.h>
using namespace std;
void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild])
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}

// Функция сортировки на куче
void heapSort(int *numbers, int array_size)
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}


void ShellSort(int n, int mass[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}




 void merge(int *a, int n)
{
  int mid = n / 2; // находим середину сортируемой последовательности
  if (n % 2 == 1)
    mid++;
  int h = 1; // шаг
  // выделяем память под формируемую последовательность
  int *c = (int*)malloc(n * sizeof(int));
  int step;
  while (h < n)
  {
    step = h;
    int i = 0;   // индекс первого пути
    int j = mid; // индекс второго пути
    int k = 0;   // индекс элемента в результирующей последовательности
    while (step <= mid)
    {
      while ((i < step) && (j < n) && (j < (mid + step)))
      { // пока не дошли до конца пути
        // заполняем следующий элемент формируемой последовательности
        // меньшим из двух просматриваемых
        if (a[i] < a[j])
        {
          c[k] = a[i];
          i++;
          k++;
        }
        else {
          c[k] = a[j];
          j++;
           k++;
        }
      }
      while (i < step)
      { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
        c[k] = a[i];
        i++;
         k++;
      }
      while ((j < (mid + step)) && (j<n))
      {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
        c[k] = a[j];
        j++;
        k++;
      }
      step = step + h; // переходим к следующему этапу
    }
    h = h * 2;
    // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
}

void firstTask(){
    printf("\n First Algorithm \n");
    int a[10];
      // Заполнение массива случайными числами
    for (int i = 0; i<10; i++)
        a[i] = rand() % 20 - 10;
      // Вывод элементов массива до сортировки
    for (int i = 0; i<10; i++)
        printf("%d ", a[i]);
    printf("\n");
    //сортировка методом Шелла
    ShellSort(10, a);
    //вывод отсортированного массива на экран
    for (int i = 0; i<10; i++)
        printf("%d ", a[i]);

        printf("\n");


}

void secondTask(){
    printf("\n Second Algorithm \n");
    int a[10];
  // Заполнение массива случайными числами
  for (int i = 0; i<10; i++)
    a[i] = rand() % 20 - 10;
  // Вывод элементов массива до сортировки
  for (int i = 0; i<10; i++)
    printf("%d ", a[i]);
  printf("\n");
  heapSort(a, 10); // вызов функции сортировки
  // Вывод элементов массива после сортировки
  for (int i = 0; i<10; i++)
    printf("%d ", a[i]);
  printf("\n");

}

void thirdTask(){
    printf("\n ThirdTask \n");
int a[8];
  // Заполнение массива случайными числами
  for (int i = 0; i<8; i++)
    a[i] = rand() % 20 - 10;
  // Вывод элементов массива до сортировки
  for (int i = 0; i<8; i++)
    printf("%d ", a[i]);
  printf("\n");
  merge(a, 8); // вызов функции сортировки
  // Вывод элементов массива после сортировки
  for (int i = 0; i<8; i++)
    printf("%d ", a[i]);
  printf("\n");
  }




int main()
{
    firstTask();
    secondTask();
    thirdTask();

  return 0;
}
























