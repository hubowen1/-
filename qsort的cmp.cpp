#include <iostream>   
#include <cstdlib>
using namespace std;   
struct Data {  
    int count;	// 出现次数   
    int number;	// 值   
}; 
int comp(const void *a,const void *b ){
   
       
    
    if((*(Data *)a).count==(*(Data *)b).count){
        return +(*(Data *)a).number-(*(Data *)b).number;
    } 
    else return -(*(Data *)a).count+(*(Data *)b).count;
    

}
int main() {  
    int number;  
    Data data[11];  
    for(int i = 0; i < 11; ++i) {
      	data[i].count = 0;  
        data[i].number = i;  
    }  
    for(int i = 0; i < 20; ++i) {  
        cin >> number;  
        ++data[number].count;  
    }
    qsort(data, 11, sizeof(data[0]), comp);
    cout << data[0].number << endl;  
    return 0;  
}  
