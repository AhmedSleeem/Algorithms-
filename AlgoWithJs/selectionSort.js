
function selectionSort(arr){
    let n = arr.length;
    let min=arr[0];
    for(let i=0;i<n;++i){
        min=arr[i];
        let idx=i;
        for(let k=i+1;k<n;++k){
            if(arr[k]<arr[idx])    idx=k;
            
        }
        let temp =arr[idx];
        arr[idx]=arr[i];
        arr[i]=temp;
        
        // arr[i]=min;
        // console.log(arr);
    }
    return arr;
}


console.log(selectionSort([19,44,38,5,47,15]));