 /* This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    
    What2Eat is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    What2Eat is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with What2Eat.  If not, see <https://www.gnu.org/licenses/>.
    */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Food{
    char name[20];
    int frequency;
    int score;

} foods;

void sortArray(foods foodList[],int k){
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            if (foodList[i].score < foodList[j].score) {
                foods tmp = foodList[i];
                foodList[i] = foodList[j];
                foodList[j] = tmp;
            }
        }
    }
}
int main() {
    int peopleCount;

    printf("How many people want to eat: ");
    scanf("%d",&peopleCount);
    int size = peopleCount * 5 ;
    struct Food foodList[size];
    char foodNames [size][1024];
    int freq[size];
    int counter = 0;
    for (int i = 0; i<peopleCount; i++)
    {
        for(int k = 1; k <=5 ; k++ )
        {
            char c[20];
            printf("Person %d, choice %d is:  ",i+1,k);
            scanf("%s",c);
            if (strstr(c, "_")){
                printf("You are eating at home/dorm today!\n");
                return 0;
            }
            strcpy(foodNames[counter],c);
            freq[counter++] = -1;
        }
    }
    for(int i=0; i<size; i++)
    {
       int count = 1;
        for(int j=i+1; j<size; j++)
        {
            if(strstr(foodNames[i],foodNames[j]) != NULL)
            {
                count++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    printf("Short List of Foods:\n");
    int k = 0;
    for(int i=0; i<size; i++)
    {
        foods  f;
        if(freq[i] != 0)
        {
            //printf("%s occurs %d times\n", foodNames[i], freq[i]);
            strcpy(f.name,foodNames[i]);
            f.frequency = freq[i];
            f.score = rand() % size + 1;
            foodList[k++] = f;
        }
    }
            sortArray(foodList,k);
            for (int i = 0; i < k; i++) {
        printf("%s occurs %d times -- score is %d \n", foodList[i].name, foodList[i].frequency,foodList[i].score);
    }
    printf("Please type one food to give a final decision score: \n");
    int threshold = 10;
    for (int i = 0; i < peopleCount ; ++i) {
        char c [20] ;
        printf("Person %d choice : ",i+1);
        scanf("%s",c);
        for (int j = 0; j < k; ++j) {
            if(strstr(c,foodList[j].name)){
                foodList[j].score += threshold;
            }
        }
    }
    sortArray(foodList,k);
    printf("New Food List: \n");
    for (int i = 0; i < k; i++) {
        printf("%s occurs %d times -- score is %d \n", foodList[i].name, foodList[i].frequency,foodList[i].score);
    }
    printf("-------------------------------\n");
    printf("We will order %s\n", foodList[0].name);


    return 0;
}

