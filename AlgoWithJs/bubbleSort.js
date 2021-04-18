

function bubbleSort(arr){
    const n =arr.length;

    let madeMove = true;
    for(let i=0;i<n&&madeMove;++i){

        madeMove= false;
        for(let k = 0;k<n-i-1 ;++k){
            if(arr[k+1]<arr[k]){
                let temp =arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
                madeMove=true;
            }
        }
    }

    return arr;
}

console.log(bubbleSort([90,37,45,29,8,23,1,0,-2]));