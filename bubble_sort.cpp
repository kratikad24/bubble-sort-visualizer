#include "graphics.h" 
#include <bits/stdc++.h> 
  
using namespace std; 
  

vector<int> numbers; 
int size = 200; 
int gap = 4; 
  

void swap(int i, int j, int x, int y) 
{ 

  
    setcolor(GREEN); 
    line(i, size, i, size - x); 
    setcolor(BLACK); 
    line(i, size, i, size - x);  
    setcolor(WHITE); 
    line(i, size, i, size - y);  
   
    setcolor(GREEN); 
    line(j, size, j, size - y); 
    setcolor(BLACK); 
    line(j, size, j, size - y); 
    setcolor(WHITE); 
    line(j, size, j, size - x); 
} 
  
// Bubble sort function 
void bubbleSort() 
{ 
    int temp, i, j; 
  
    for (i = 1; i < size; i++) { 
        for (j = 0; j < size - i; j++) { 
            if (numbers[j] > numbers[j + 1]) { 
                temp = numbers[j]; 
                numbers[j] = numbers[j + 1]; 
                numbers[j + 1] = temp; 

                swap(gap * j + 1, 
                     gap * (j + 1) + 1, 
                     numbers[j + 1], 
                     numbers[j]); 
            } 
        } 
    } 
} 
  
 
int main() 
{ 
  
    int gd = DETECT, gm; 
    int wid1; 
  
    // Graph initialization 
    initgraph(&gd, &gm, NULL); 
  
    // setting up window size (gap*size) * (size) 
    wid1 = initwindow(gap * size + 1, size + 1); 
    setcurrentwindow(wid1); 
  
    // Initializing the array 
    for (int i = 1; i <= size; i++) 
        numbers.push_back(i); 
   
    unsigned seed 
        = chrono::system_clock::now() 
              .time_since_epoch() 
              .count(); 
  
    shuffle(numbers.begin(), 
            numbers.end(), 
            default_random_engine(seed)); 
  
  
    for (int i = 1; i <= gap * size; i += gap) { 
        line(i, size, i, (size - numbers[i / gap])); 
    } 
  
    // Delay the code 
    delay(200); 
  
    // Call sort 
    bubbleSort(); 
  
    for (int i = 0; i < size; i++) { 
        cout << numbers[i] << " "; 
    } 
    cout << endl; 
  
    // Wait for sometime . 
    delay(5000); 
  
    // Close the graph 
    closegraph(); 
  
    return 0; 
} 
