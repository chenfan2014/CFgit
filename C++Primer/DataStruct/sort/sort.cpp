#include <iostream>
#include <string>
#include <vector>


using namespace std;

template<typename T>
void insertSort(T arr[], int size)      //直接插入排序，时间复杂度O(n2), 空间复杂度O(1),需要一个tmp，稳定排序
{
    if(size <= 1){
        return ;
    }
    //直接插入方法就是我们每次从原始数组去一个元素存入到我们排序数组
    //时间复杂度为O(n2),最好的情况是O(N),这个时候我们的数组是有序的
    for(int i = 1; i != size; i ++)
    {
        T tmp = arr[i];
        for(int j = i - 1; j >= 0; j --)
        {
            if(tmp > arr[j]){       //当我们tmp大于我们从后往前找到的值，我们把这个值插入到找到值的后面
                arr[j + 1] = tmp;
                break;
            }else{                  //否则的话，我们找到的值往后移动，让tmp和前一个进行比较
                arr[j + 1] = arr[j];
                if(j == 0){         //如果比较到了最前面的一个值，还没有交换，说明是目前的最小值，则放到arr[0]处
                    arr[j] = tmp;
                }
            }
        }
    }
}

template<typename T>
void shellSort(T arr[], int size)    
{
    if(size <= 1){
        return ;
    }
    //希尔排序方法就是我们使用步长dk,步长从len/2到1,我们对步长进行一个缩小，每次去dk/2
    //然后对0~dk个数组进行排序
    for(int stepLen = size/2; stepLen >= 1; stepLen = stepLen / 2)  //让步长逐渐的缩小，最后变成1
    {
        for(int i = stepLen; i != size; i ++)       //对每一个子数组进行排序操作，从下表为步长的元素开始
        {
            for(int j = i - stepLen; j >= 0; j -= stepLen)  //从当前下表到子数组第一个元素，进行排序，小就互换。否则继续
            {
                if(arr[j] > arr[j + stepLen])
                {
                    T tmp = arr[j];
                    arr[j] = arr[j + stepLen];
                    arr[j + stepLen] = tmp;
                }
            }
        }
    }
}

template<typename T>
void bubbleSort(T arr[], int size)
{
    //冒泡排序，我们从后往前进行元素比较，小的放在前面，大的放在后面，直到完成
    for(int i = 0; i != size - 1; i ++)
    {
        for(int j = 0; j != size - i - 1; j ++)
        {
            if(arr[j] < arr[j + 1])
            {
                T tmp = arr[j];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//快排的一次操作
template<typename T>
int partation(T arr[], int low, int high)
{
    T value = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= value){
            high --;
        }
        arr[low] = arr[high];

        while(low < high && arr[low] < value){
            low ++;
        }
        arr[high] = arr[low];
    }
    arr[low] = value;
    return low;
}
//快排的轮寻
template<typename T>
void quickSort(T arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partation(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


template<typename T>
void selectSort(T arr[], int size)      //简单选择排序
{
    T minElement;
    int index;
    for(int i = 0; i != size; i ++)
    {
        minElement = arr[i];
        index = i;
        for(int j = i; j != size; j ++)
        {
            if(minElement > arr[j])
            {
                minElement = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = minElement;
    }
}


//下面是堆排序

template<typename T>
void adjustDown(T arr[], int pos, int size)
{
    if(2 * pos < size && arr[pos] < arr[2 * pos])   //说明有左孩子,且pos位置跟节点小于左孩子
    {
        if(2 * pos + 1 < size && arr[2 * pos] < arr[2 * pos + 1]){  //右孩子存在且大于左孩子和跟节点
            T tmp = arr[pos];
            arr[pos] = arr[2 * pos + 1];
            arr[2 * pos + 1] = tmp;
        }else{
           T tmp = arr[pos];
           arr[pos] = arr[pos * 2];
           arr[pos * 2] = tmp;
        }
    }
}

template<typename T>
void buildMaxHeap(T arr[], int size)
{
    for(int i = size/2; i > 0; i --)
    {
        adjustDown(arr, i, size);        //向下调整
    }
}

//归并排序,每一趟归并的时间复杂度为O(N);一共需要进行Logn次归并，
template<typename T>
void merge(T arr[], int low, int mid, int high)
{
    T *newArr = new T[high - low + 1];
    //T *newArr = (T *)malloc(sizeof(T) * (high - low + 1));

    //表arr表示两段a[low...mid] a[mid...high]各自都是有序的，然后我们要把他们合并成为一个有序表
    for(int k = low; k != high; k ++)
    {
        newArr[k] = arr[k];
    }
    
    int i, j, k;
    for(i = low, j = mid + 1, k = i; i <= mid && j <= high; k ++)
    {
        if(newArr[i] < newArr[j]){
            arr[k] = newArr[i ++];
        }else{
            arr[k] = newArr[j ++];
        }
    }
    while(i <= mid){
        arr[k ++] = newArr[i ++];
    }
    while(j <= high){
        arr[k ++] = newArr[j ++];
    }
}

template<typename T>
void mergeSort(T arr[], int low, int high)
{
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}




int main(int argc, const char *argv[])
{
    
    int arr3[] = {8, 3, 123, 1, 21, 32, 4, 53, 31, 7};
    mergeSort(arr3, 0, sizeof(arr3)/sizeof(int));
    for(int i = 0; i != sizeof(arr3)/sizeof(int); i ++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
