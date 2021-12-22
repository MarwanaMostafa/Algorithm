package prolem_2;
import static java.nio.file.Files.size;
import java.util.Hashtable;
import java.util.Scanner;
public class PairSum {





public static void getPairs(int arr[], int target, int size){
   Hashtable<Integer, Integer> hash = new Hashtable<Integer, Integer>();

    for(int i=0;i<arr.length;i++){
        int temp= target-arr[i];
        if(hash.containsKey(arr[i])){

            System.out.println("pair found");
            System.out.println("[ " + arr[i] +" , "+ hash.get(arr[i])+ " ]");}
            
        else
            
            hash.put(temp, arr[i]);
    }

}




public static void main(String[] args) {        

    Scanner input=new Scanner(System.in);
    int arr[] = {2,45,7,3,5,1,8,9};
    int size = arr.length;
    int target=0;
    System.out.println("enter target...");
    target=input.nextInt();
    getPairs(arr,target,size);
    
}
}