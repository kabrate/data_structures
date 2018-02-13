#include<stdio.h>  
   
 #define LEN 12  
 //��ӡ����  
 void print_array(int *array, int length)  
 {  
     int index = 0;  
     printf("array:\n");  
     for(; index < length; index++){  
         printf(" %d,", *(array+index));  
     }  
     printf("\n\n");  
 }  
 //�ѻ�����  
 void _heapSort(int *array, int i, int length)  
 {  
     int child, tmp;  
     //����Ǹı����ĸ��ڵ㣬�ʹӸýڵ㿪ʼ���Ըýڵ�Ϊ���ڵ��������������  
     for (; 2*i + 1 < length; i = child){//���ε�����������������������  
         child = 2*i + 1;  
         if ((child +1  < length) && (array[child+1] > array[child])) child++;//ѡ�����ĺ��ӽڵ�  
         if (array[i] < array[child]){//����ӽڵ�͸��ڵ���н���  
             tmp = array[i];  
             array[i] = array[child];  
             array[child] = tmp;  
         }else break;  
     }     
 }  
    
 void heapSort(int *array, int length)  
 {  
     int i, tmp;  //i�Ǹ߶� 
   
     if (length <= 1) return;//���Ԫ��С��1�����˳�  
     //��һ�����Ȱ�Ԫ�ض��ѻ��ã�����Ļ� �ĸ��ڵ��޸Ĺ����ʹ��ĸ��ڵ㿪ʼ������Ϊ���ڵ���������жѻ�  
     for (i = length/2 - 1; i >= 0; i--)  _heapSort(array, i, length);//�ӵ�һ����Ҷ�ӽڵ㿪ʼ����һֱ�����ڵ�  
       
     // �ȳ�ȡ�����ڵ㣬Ȼ���ٶ�Ԫ�ؽ��жѻ���Ȼ���ֳ�ȡ���ڵ㣬�ٶ�Ԫ�ؽ��жѻ�������������ѭ��  
     for (i = 0; i < length; i++ ){  
         tmp = array[0];  
         array[0] = array[length-i-1];  
         array[length -i-1] = tmp;  
         _heapSort(array, 0, length-1-i);//�ѻ�����  
     }  
 }  
   
 int main(void)  
 {  
     int array[LEN] = {2, 1, 4, 0, 12, 520, 2, 9, 5, 3, 13, 14};  
     print_array(array, LEN);  
     heapSort(array, LEN);  
     print_array(array, LEN);  
     return 0;  
 }  
