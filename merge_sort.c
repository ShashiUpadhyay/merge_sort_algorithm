//
//  ada_project.c
//
//
//  Created by Shashi Upadhyay on 19/02/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function prototypes (Start)
int find_maximum_element(int *array, int size);
void Insertion_sort(int *random_number_array,int number_of_elements);
void printTextualVisualization(int *array, int size);
void print_array_elements(int *random_number_array, int number_of_elements);
int *random_number_generator(int user_choice,int *random_number_array, int num_elements);
void merge_sort(int *inputarray, int size_array);
void merge_sort_recursive(int *inputarray, int lowest_element, int highest_element,int size_array);
void merge(int *array,int lowest_element,int middle_element,int highest_element);
void swap_element(int* inputarray, int left_element, int right_element);
int partition_quick_sort(int *inputarray, int lowest_element, int highest_element);
void quick_sort_recursion(int *inputarray, int lowest_element, int highest_element, int size_array);
void randomised_quick_sort(int *inputarray,int size_array);
int partition_quick_sort(int *inputarray, int lowest_element, int highest_element);
void counting_sort_execution(int *inputarray, int maximum_element, int size);
void counting_sort(int *inputarray,int size_array);
int print_menu();
int userInput_Range(int user_choice);
//Function prototypes (End)

// Insertion Sort Starts
void Insertion_sort(int *random_number_array,int number_of_elements){
    int index,temp,next_element;
    
    for(index=1;index<number_of_elements;index++){
        temp = random_number_array[index];
        next_element = index-1;
        while((temp<random_number_array[next_element]) && (next_element>=0)){
            random_number_array[next_element+1] = random_number_array[next_element];
            next_element--;
            
        }
        random_number_array[next_element+1] = temp;
        printf("Sorting step : %d \n", index);
        print_array_elements(random_number_array, number_of_elements);
    }
}
// Insertion Sort Ends

// Function to find maximum element from the array
int find_maximum_element(int *array, int size){
    int current_element = 0;
    int maximum_element = 0;
    for (current_element = 0; current_element < size; current_element++) {
        if(array[current_element] > maximum_element){
            maximum_element = array[current_element];
        }
    }
    return maximum_element;
}

// Function to print the textual visualization of the array (This function is specifically created for counting sort)
void printTextualVisualization_countingsort(int *array, int size){
    int index, current_element;
    index =0; current_element=0;
    if(size <= 20){
        for(index=0;index<size;index++){
            current_element = array[index];
            if(current_element == 0){
                printf("0\n");
                continue;
            }
            while(current_element-- > 0){
                printf("*");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Function to print the textual visualization of the array
void printTextualVisualization(int *array, int size){
    int index, current_element;
    index =0; current_element=0;
    if(size <= 20){
        for(index=0;index<size;index++){
            current_element = array[index];
            if(current_element == 0){
                printf("0\n");
                continue;
            }
            while(current_element-- > 0){
                printf("*");
            }
            printf("\n");
        }
    }
    printf("\n");
}


// Function to print the elements of the array
void print_array_elements(int *random_number_array, int number_of_elements){
    int index;
    for(index=0;index<number_of_elements;index++){
        printf("%d ", random_number_array[index]);
    }
    printf("\n");
    printTextualVisualization(random_number_array,number_of_elements);
}

// Function to print the elements of the array (This function is specifically created for counting sort)
void print_array_elements_countingSort(int *random_number_array, int number_of_elements){
    int index;
    for(index=0;index<number_of_elements;index++){
        printf("%d ", random_number_array[index]);
    }
    printf("\n");
    printTextualVisualization_countingsort(random_number_array,number_of_elements);
}

// Counting Sort Start here
void counting_sort_execution(int *inputarray, int maximum_element, int size_array){
    int current = 0;
    int index;
    int counting_array[maximum_element];
    int sorted_array[size_array],current_element;
    
    for(current_element = 0; current_element<=maximum_element; current_element++){
        counting_array[current_element] = 0;
        sorted_array[current_element] = 0;
    }
    
    //    Counting the frequency of each element and storing it in counting array
    for(current_element = 0; current_element<size_array; current_element++){
        counting_array[inputarray[current_element]] = counting_array[inputarray[current_element]] + 1;
    }
    
    for(current_element = 1; current_element<=maximum_element; current_element++){
        counting_array[current_element] = counting_array[current_element] + counting_array[current_element-1];
    }
    
    for(current_element=(size_array-1); current_element>=0; current_element--)
    {
        sorted_array[counting_array[inputarray[current_element]]-1] = inputarray[current_element];
        counting_array[inputarray[current_element]] = counting_array[inputarray[current_element]] - 1;
        
        printf("Step by Step Sorting progress : \n");
        for(index=0;index<size_array;index++){
            printf(" %d ", sorted_array[index]);
        }
        printf("\n");
        
        printTextualVisualization_countingsort(sorted_array,size_array);
    }
    
    printf("Final Counting Sort Output \n");
    print_array_elements_countingSort(sorted_array,size_array);
    
    printf("\n");
}


void counting_sort(int *inputarray,int size_array){
    int maximum_element = find_maximum_element(inputarray,size_array);
    counting_sort_execution(inputarray, maximum_element,size_array);
}
// Counting Sort Ends here

// Merge Sort Algorithm (Starts)
void merge_sort_recursive(int *inputarray, int lowest_element, int highest_element,int size_array){
    int middle_element;
    if(lowest_element < highest_element){
        middle_element = lowest_element + ((highest_element-lowest_element)/2);
        merge_sort_recursive(inputarray,lowest_element,middle_element,size_array);
        merge_sort_recursive(inputarray,middle_element+1,highest_element,size_array);
        merge(inputarray,lowest_element,middle_element,highest_element);
        printf("Step by Step Sorting progress : \n");
        print_array_elements(inputarray, size_array);
    }
}
void merge_sort(int* inputarray, int size_array){
    merge_sort_recursive(inputarray, 0, size_array-1,size_array);
}

void merge(int *array , int lowest_element , int middle_element , int highest_element){
    int first_list_size = middle_element - lowest_element +1;
    int second_list_size = highest_element- middle_element;
    int first_list[first_list_size];
    int second_list[second_list_size];
    int i,j,k;
    for(i=0 ; i < first_list_size ; i ++ )
        first_list[i] = array[lowest_element+i];
    for(i=0 ; i < second_list_size ; i ++ )
        second_list[i] = array[middle_element+1+i];
    
    i=0,j=0,k=lowest_element;
    while ( i < first_list_size && j < second_list_size){
        if(first_list[i] < second_list[j]){
            array[k++] = first_list[i++];
        }
        else{
            array[k++] = second_list[j++];
        }
    }
    while(i < first_list_size){
        array[k++] = first_list[i++];
    }
    while(j < second_list_size){
        array[k++] = second_list[j++];
    }
}
// Merge Sort Algorithm (Ends)


//Print Menu
int print_menu(){
    int input;
    printf("\n");
    printf("============================\n");
    printf("|   MENU SELECTION          |\n");
    printf("============================\n");
    printf("|   Options:                |\n");
    printf("|  1. Insertion Sort        |\n");
    printf("|  2. Counting Sort         |\n");
    printf("|  3. Merge Sort            |\n");
    printf("|  4. Randomized Quick Sort |\n");
    printf("| --------------------------|\n");
    printf("|  0. Exit                  |\n");
    printf("============================\n");
    printf("\n");
    printf("Kindly select the action you want to perform : \n");
    scanf("%d", &input);
    printf("\n");
    return input;
}

//Function to accept user input
int userInput_Range(int user_choice){
    int input;
    if(user_choice == 2){
        printf("Kindly specify the input range between 1 and 100  \n");
        scanf("%d", &input);
        if(input < 1 || input > 00){
            printf("Entered value must be between 0 and 99 \n");
        }
    }else{
        printf("Kindly specify the input range between 1 and 1000 \n");
        scanf("%d", &input);
        if(input < 1 || input > 1000){
            printf("Entered value must be >= 1 and <= 1,000 \n");
        }
    }
    return input;
}

/* Function to generate ramdom number */
int* random_number_generator(int user_choice,int *random_number_array, int num_elements){
    int i,random_number;
    random_number_array = malloc(num_elements*sizeof(int));
    srand(time(NULL));
    if(user_choice == 2){
        for (i=0; i<num_elements; i++) {
            random_number_array[i] = rand()%100;
        }
    }else{
        if(num_elements < 20){
            for (i=0; i<num_elements; i++) {
                random_number_array[i] = rand()%15 + 1;
            }
        }else{
            for (i=0; i<num_elements; i++) {
                random_number_array[i] = rand()%999;
            }
        }
    }
    
    printf("Generated Random Number : ");
    for(i=0;i<num_elements;i++){
        printf("%d ",random_number_array[i]);
    }
    printf("\n");
    return random_number_array;
    
}

void swap_element(int* inputarray, int left_element, int right_element){
    int temp = inputarray[left_element];
    inputarray[left_element] = inputarray[right_element];
    inputarray[right_element] = temp;
}

int partition_quick_sort(int *inputarray, int lowest_element, int highest_element){
    int range_of_array = highest_element - lowest_element + 1;
    int pivot_element = lowest_element + rand() % range_of_array;
    swap_element(inputarray,lowest_element,pivot_element);
    
    int key_element = inputarray[lowest_element];
    int i = lowest_element;
    int j = highest_element + 1;
    
    while(1){
        while(inputarray[++i] < key_element){
            if(i == highest_element){
                break;
            }
        }
        
        while(key_element < inputarray[--j]){
            if(j == lowest_element){
                break;
            }
        }
        if(i >= j){
            break;
        }
        swap_element(inputarray,i,j);
    }
    swap_element(inputarray,j,lowest_element);
    return j;
}

void quick_sort_recursion(int *inputarray, int lowest_element, int highest_element, int size_array){
    if(lowest_element >= highest_element){
        return;
    }
    
    int pivot_element;
    pivot_element = partition_quick_sort(inputarray, lowest_element, highest_element);
    print_array_elements(inputarray, size_array);
    quick_sort_recursion(inputarray,lowest_element, pivot_element-1, size_array);
    quick_sort_recursion(inputarray,pivot_element+1, highest_element, size_array);
}

void randomised_quick_sort(int *inputarray,int size_array){
    quick_sort_recursion(inputarray, 0, size_array-1, size_array);
}

int main(){
    int user_choice,number_of_elements;
    int *random_number_array;
    user_choice = (int) print_menu();
    printf("Selected choice : %d \n", user_choice);
    if(user_choice == 0){
        printf("Exiting \n");
        exit(0);
    }
    do{
        
        if(user_choice == 1){
            printf("Insertion Sort \n");
        }else if(user_choice == 2){
            printf("Counting Sort \n");
        }else if(user_choice == 3){
            printf("Merge Sort \n");
        }else if(user_choice == 4){
            printf("Randomised Quick Sort \n");
        }
        
        if(user_choice>=1 && user_choice<=4){
            number_of_elements = userInput_Range(user_choice);
            printf("Entered Number : %d \n", number_of_elements);
            if(user_choice == 2 && (number_of_elements < 1 || number_of_elements > 100)){
                user_choice = 6;
            }else if(number_of_elements < 1 || number_of_elements > 1000){
                user_choice = 5;
            } else{
                random_number_array = random_number_generator(user_choice,random_number_array,number_of_elements);
            }
        }
        
        switch (user_choice) {
                // Insertion Sort
            case 1:
                printf("Output before Insertion sort \n");
                print_array_elements(random_number_array,number_of_elements);
                Insertion_sort(random_number_array,number_of_elements);
                printf("Final Insertion Sort Output \n");
                print_array_elements(random_number_array,number_of_elements);
                free(random_number_array);
                break;
                // Counting Sort
            case 2:
                printf("Output before Counting sorting \n");
                print_array_elements_countingSort(random_number_array,number_of_elements);
                counting_sort(random_number_array, number_of_elements);
                free(random_number_array);
                break;
                // Merge Sort
            case 3:
                printf("Output before Merge Sort \n");
                print_array_elements(random_number_array,number_of_elements);
                merge_sort(random_number_array, number_of_elements);
                printf("Final Merge Sort Output \n");
                print_array_elements(random_number_array,number_of_elements);
                free(random_number_array);
                break;
                // Randomised Quick Sort
            case 4:
                printf("Output before Randomised sort \n");
                print_array_elements(random_number_array,number_of_elements);
                randomised_quick_sort(random_number_array,number_of_elements);
                printf("Final Randomised Sort Output \n");
                print_array_elements(random_number_array,number_of_elements);
                free(random_number_array);
                break;
            case 5:
                printf("Kindly enter the value greater than 1 and less than 1000 \n");
                break;
            case 6:
                printf("Permissible limit for counting sort is between 1 to 100 \n");
                break;
            case 0:
                printf("Exiting \n");
                exit(0);
                break;
            default:
                printf("Error: Invalid Choice");
                break;
        }
        user_choice = print_menu();
    }while(user_choice != 0);
}











