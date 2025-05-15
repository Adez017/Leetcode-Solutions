class odd_even {
    public static void main(String[] args){
        int [] arr = {1,2,3,4,5,6,7,8,0,4,7};

        // Note : it is the best time complexity if you are not allowed to change the order of 
        //the elements
        // int [] res = new int[arr.length];
        // int j=0;
        // for(int i=0;i<arr.length;i++){
        //     if(arr[i]%2==0){
        //         res[j] = arr[i];
        //         //even
        //         j++;
        //     }
        // }
        // for(int i=0;i<arr.length;i++){
        //     if(arr[i]%2!=0){
        //         //odd
        //         res[j]=arr[i];
        //         j++;
        //     }
        // }
        // //printing the loop 
        // for(int i=0;i<arr.length;i++){
        //     System.out.printf("%d ",res[i]);
        // }

        //swaping the odd and even things   
        //drawback is the order is not  maintained
        int low =0;
        int high = arr.length-1;
        while(low < high){
            if(arr[low]%2!=0){ //if it is odd one
                if(arr[high]%2==0){ //it is even
                    int temp = arr[low];
                    arr[low] = arr[high];  //swap th efirst and last elemnt and increase the pointer
                    arr[high] = temp;

                    low++;
                    high--;
                }
                else{
                    high--; //we had to check the next odd from back
                }
            }
            else{
                //if first is even 
                low++;
            }
        }
        for(int i=0;i<arr.length;i++){
            System.out.printf("%d ",arr[i]);
        }
        
    }

    
}