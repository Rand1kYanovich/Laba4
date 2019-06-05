#include <stdio.h>
#include <stdlib.h>
using namespace std;
void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // ������ ������������� �������
  int done = 0; // ���� ����, ��� ���� ������������
  // ���� �� ����� �� ���������� ����
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)    // ���� �� � ��������� ����,
      maxChild = root * 2;    // ���������� ����� �������
    // ����� ���������� ������� ������� �� ����
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // ���� ������� ������� ������ ������������� �������
    if (numbers[root] < numbers[maxChild])
    {
      int temp = numbers[root]; // ������ �� �������
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // �����
      done = 1; // �������� ������������
  }
}

// ������� ���������� �� ����
void heapSort(int *numbers, int array_size)
{
  // ��������� ������ ��� ��������
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // ���������� ����� �������� ��������� ��������
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
  int mid = n / 2; // ������� �������� ����������� ������������������
  if (n % 2 == 1)
    mid++;
  int h = 1; // ���
  // �������� ������ ��� ����������� ������������������
  int *c = (int*)malloc(n * sizeof(int));
  int step;
  while (h < n)
  {
    step = h;
    int i = 0;   // ������ ������� ����
    int j = mid; // ������ ������� ����
    int k = 0;   // ������ �������� � �������������� ������������������
    while (step <= mid)
    {
      while ((i < step) && (j < n) && (j < (mid + step)))
      { // ���� �� ����� �� ����� ����
        // ��������� ��������� ������� ����������� ������������������
        // ������� �� ���� ���������������
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
      { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
        c[k] = a[i];
        i++;
         k++;
      }
      while ((j < (mid + step)) && (j<n))
      {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
        c[k] = a[j];
        j++;
        k++;
      }
      step = step + h; // ��������� � ���������� �����
    }
    h = h * 2;
    // ��������� ������������� ������������������ (������������� �������) � �������� ������
    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
}

void firstTask(){
    printf("\n First Algorithm \n");
    int a[10];
      // ���������� ������� ���������� �������
    for (int i = 0; i<10; i++)
        a[i] = rand() % 20 - 10;
      // ����� ��������� ������� �� ����������
    for (int i = 0; i<10; i++)
        printf("%d ", a[i]);
    printf("\n");
    //���������� ������� �����
    ShellSort(10, a);
    //����� ���������������� ������� �� �����
    for (int i = 0; i<10; i++)
        printf("%d ", a[i]);

        printf("\n");


}

void secondTask(){
    printf("\n Second Algorithm \n");
    int a[10];
  // ���������� ������� ���������� �������
  for (int i = 0; i<10; i++)
    a[i] = rand() % 20 - 10;
  // ����� ��������� ������� �� ����������
  for (int i = 0; i<10; i++)
    printf("%d ", a[i]);
  printf("\n");
  heapSort(a, 10); // ����� ������� ����������
  // ����� ��������� ������� ����� ����������
  for (int i = 0; i<10; i++)
    printf("%d ", a[i]);
  printf("\n");

}

void thirdTask(){
    printf("\n ThirdTask \n");
int a[8];
  // ���������� ������� ���������� �������
  for (int i = 0; i<8; i++)
    a[i] = rand() % 20 - 10;
  // ����� ��������� ������� �� ����������
  for (int i = 0; i<8; i++)
    printf("%d ", a[i]);
  printf("\n");
  merge(a, 8); // ����� ������� ����������
  // ����� ��������� ������� ����� ����������
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
























