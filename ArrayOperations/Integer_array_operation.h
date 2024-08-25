#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <error_handling.h> //user defined function for handlling user input error 
void graphics()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");//use path  where your turboc is stored
}
//function to display 1d array
void display(int *Array1, int *size)
{
  int i, element, x_cord_of_element = 0, x_cord_of_index = 0, x_cord_of_element_address = 0;

  char str[50];
  // loop for making rectangles
  for (i = 0; i < *size * 50; i = i + 50)
  {
    rectangle(50 + i, 150, 100 + i, 200);
    delay(200);
  }
  // loop for printing index of array
  for (i = 0; i < *size; i++)
  {
    sprintf(str, "%d", i);
    outtextxy(70 + x_cord_of_index, 135, str);
    x_cord_of_index = x_cord_of_index + 50;
    delay(200);
  }
  // loop for printing address of the element of array
  for (i = 0; i < *size; i++)
  {

    element = &Array1[i];
    sprintf(str, "%u", element);
    outtextxy(55 + x_cord_of_element_address, 210, str);
    delay(200);
    x_cord_of_element_address = x_cord_of_element_address + 50;
  }
  // loop for printing the elements of array
  for (i = 0; i < *size; i++)
  {

    element = Array1[i];
    sprintf(str, "%d", element);
    outtextxy(65 + x_cord_of_element, 175, str);
    delay(200);
    x_cord_of_element = x_cord_of_element + 50;
  }
}

void insert_element(int *Array1, int *size)
{
  int num, i, position;
  printf("enter the position: ");
  position = position_validation(*size);

  printf("enter the elements you want to insert: ");
  num = integer_validation();
  *size = *size + 1;
  for (i = *size; i > position; i--)
    Array1[i] = Array1[i - 1];
  Array1[position] = num;
  cleardevice();
}
void delete_element(int *Array1, int *size)
{
  int i, position;
  printf("enter the position where you want to delete: ");
  position = position_validation(*size-1);

  for (i = position; i < *size; i++)
    Array1[i] = Array1[i + 1];
  *size = *size - 1;
  cleardevice();
}
void sort_element(int *Array1, int *size)
{
  int i, j, temp;
  for (i = 0; i < *size - 1; i++)
  {
    for (j = 0; j < *size - i - 1; j++)
    {
      if (Array1[j] > Array1[j + 1])
      {
        temp = Array1[j];
        Array1[j] = Array1[j + 1];
        Array1[j + 1] = temp;
      }
    }
  }
    cleardevice();
}

void Array_1d()
{

  int i, size, Array1[40], j;
  int choi, choice;

  clrscr();
  graphics();

  printf("Enter the size of array ");
  size = input_validation_size();

  printf("Enter Elements ");
  for (i = 0; i < size; i++)
    Array1[i] = integer_validation();
  cleardevice();
  display(Array1, &size);
  delay(200);
  while (1)
  {
    outtextxy(20, 30, "press 0 for see opeartions");
    scanf("%d", &choi);
    if (choi != 0)
      exit(0);
    cleardevice();

    printf("1.Insertion\n2.Deletion\n3.Sort\n4.Exit");
    choice = input_validation_choice();
    switch (choice)
    {
    case 1:
      insert_element(Array1, &size);
      display(Array1, &size);
      break;
    case 2:
      delete_element(Array1, &size);
      display(Array1, &size);
      break;
    case 3:
      sort_element(Array1, &size);
      display(Array1, &size);
      break;
    case 4:
      exit(0);
    }
  }
}
//function to display bubble sort
void display_bubble(int a[], int k, int p, int o)
{

  int i, e, m = 0;
  char str[50];
  // loop for making rectangles
  for (i = 0; i < k * 50; i = i + 50)
  {
    rectangle(30 + i, 30 + p, 80 + i, 80 + p);
    delay(200);
  }
  // loop for printing elements
  for (i = 0; i < k; i++)
  {
    e = a[i];
    sprintf(str, "%d", e);
    outtextxy(45 + m, 45 + o, str);
    delay(200);
    m = m + 50;
  }
}
void bubble()
{
  int i, size, a[40], j, b[40], temp, k, p = 0, o = 0;

  clrscr();
  graphics();
  printf("Enter Size ");
  size = input_validation_size();
  printf("Enter Elements");
  for (i = 0; i < size; i++)
    a[i] = integer_validation();
  cleardevice();
  outtextxy(60, 10, "Bubble Sort");

  for (i = 0; i < size; i++)
    b[i] = a[i];

  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (b[j] > b[j + 1])
      {
        temp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = temp;
        for (k = 0; k < size; k++)
          a[k] = b[k];
      }
    }
    display_bubble(a, k, p, o);
    p = p + 60;
    o = o + 60;
  }
}

void display_2d(int b[], int r, int p)
{

  int i, e, m = 0;
  char str[50];
  for (i = 0; i < r * 50; i = i + 50)
  {
    rectangle(50 + i, 50 + p, 100 + i, 100 + p);
    delay(200);
  }
  for (i = 0; i < r; i++)
  {
    e = b[i];
    sprintf(str, "%d", e);
    outtextxy(65 + m, 65 + p, str);
    delay(200);
    m = m + 50;
  }
}

void Array_2d()
{
  int gd = DETECT, gm;
  int i, size, a[6][5], j, temp, k, r, p = 0;
  int b[30], f;

  clrscr();
  graphics();

  printf("Enter Size ");
  size = input_validation_size();
  r = input_validation_size();
  printf("Enter Elements");
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < r; j++)
    {
      printf("enter a[%d][%d]", i, j);
      a[i][j] = integer_validation();
    }
  }
  cleardevice();
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < r; j++)
    {
      f = a[i][j];
      b[j] = f;
    }
    display_2d(b, r, p);
    p = p + 50;
  }
  getch();
}

void display_circle(int a[], int k, int p, int o)
{

  int i, e, m = 0;
  char str[50];
  // loop for making rectangles
  for (i = 0; i < k * 50; i = i + 50)
  {
    circle(30 + i, 30 + p, 20);
    delay(200);
  }
  // loop for printing elements
  for (i = 0; i < k; i++)
  {
    e = a[i];
    sprintf(str, "%d", e);
    outtextxy(30 + m, 30 + o, str);
    delay(200);
    m = m + 50;
  }
}
void bubble_circle()
{
  int gd = DETECT, gm;
  int i, size, a[40], j, b[40], temp, k, p = 0, o = 0;

  clrscr();
  graphics();

  printf("Enter Size ");
  size = input_validation_size();
  printf("Enter Elements");
  for (i = 0; i < size; i++)
    a[i] = integer_validation();
  cleardevice();

  for (i = 0; i < size; i++)
    b[i] = a[i];

  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (b[j] > b[j + 1])
      {
        temp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = temp;
        for (k = 0; k < size; k++)
          a[k] = b[k];
      }
    }
    display_circle(a, k, p, o);
    p = p + 60;
    o = o + 60;
  }
}