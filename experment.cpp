
#include <bits/stdc++.h>

using namespace std;

int getRandomNumber(){
    std::random_device device;     
    std::mt19937 generator(device());    
    std::uniform_int_distribution<int> dist(1,10000);
    int number = dist(generator);
    return (int)number;
}

void getRandomList(int* list,int len){
    for(int i=0;i<len;i++){
        list[i]=getRandomNumber();
    }
}

void getnewRandomList(int* list,int len){
    srand(time(0));
    int MAX = 100000;
    for(int i=0;i<len;i++){
        int random_number = rand();
        list[i]=(int)random_number/MAX;;
    }
}


void bubbleSort(int* list,int len){
    int i,j;
    int n =len;
    for (i = 0; i<n; i++) {
        for (j = i+1; j<n; j++) {
            if (list[i]>list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void countSort(int *arr, int length) {
	int max = -1, i;
	int result[length];

	for (i = 0; i<length; i++) {
		if (max < arr[i]) max = arr[i];
	}

	long count[max+1];

	for (i = 0; i<max+1; i++) {
		count[i] = 0;
	}

	for (i = 0; i<length; i++) {
		count[arr[i]]++;
	}

	for (i = 1; i<max+1; i++) {
		count[i] = count[i]+ count[i-1];
	}

	for (int i = length-1; i>=0; i--) {
		result[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
}

void merge(int *arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid; 

    int left[n1], right[n2], i = 0, j = 0, k = start;

    for (i = 0; i < n1; i++) {
        left[i] = arr[start+i];
    }

    for (j = 0; j < n2; j++) {
        right[j] = arr[mid+1+j];
    }

    i = 0; j = 0;
    while (i<n1 && j<n2) {
        if (left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while (i<n1) arr[k++] = left[i++];
    while (j<n2) arr[k++] = right[j++];
}

void mergeSort(int *arr, int start, int end) {
    if (start != end) {
        int mid = start + (end - start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using last element as pivot
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
   
//quicksort algorithm
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        //partition the array 
        int pivot = partition(arr, low, high); 
   
        //sort the sub arrays independently 
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
int main(){
    std::chrono::time_point<std::chrono::system_clock> start, end;    
    double time_spent;
    int len_arr [10];
    for(int i=0;i<10;i++)
        len_arr[i]=10000*(i+1);
    
    cout<<"X\tBubbleSort\tQuickSort\tMergeSort\tCountSort\n";
    
    for(int i=0;i<10;i++){
        int * list = (int*) malloc(sizeof(int)*len_arr[i]);
        
        getRandomList(list,len_arr[i]);

        // for(int j=0;j<len_arr[i];j++)
        //     cout<<list[j]<<"\t";
        // cout<<"\n";

        cout<<len_arr[i]<<"\t";

        start = std::chrono::system_clock::now();
        bubbleSort(list,len_arr[i]);
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        cout<< elapsed_seconds.count() << "\t";

        start = std::chrono::system_clock::now();
        quickSort(list,0,len_arr[i]);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout<< elapsed_seconds.count() << "\t";

        start = std::chrono::system_clock::now();
        mergeSort(list,0,len_arr[i]);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout<< elapsed_seconds.count() << "\t";

        start = std::chrono::system_clock::now();
        countSort(list,len_arr[i]);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout<< elapsed_seconds.count() << "\n";

        free(list);
    }
    return 0;
}