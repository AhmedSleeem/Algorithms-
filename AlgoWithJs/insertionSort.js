function insertionSort(arr){
    let n = arr.length;
    for(let i=1;i<n;++i){
        let current = arr[i];
        for(var k=i-1;k>=0&&arr[k]>current;k--){
            arr[k+1]=arr[k];
        }
        arr[k+1]=current;
    }

    return arr;

}

console.log(insertionSort([19,44,38,5,47,15]));