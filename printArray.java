package recursion;
import java.util.Arrays;

/*
* The following class prints an array by returning the first element in the array along with
* a recursive call using a truncated sub-array without the first element
*/
public class printArray {

    static String printArray(int[] myarray) {
        if (myarray.length < 2) return Integer.toString(myarray[0]);
        return Integer.toString(myarray[0]) + " " + printArray(Arrays.copyOfRange(myarray, 1, myarray.length));
    }

    public static void main(String[] args) {
        int[] myarray = {1, 2, 3, 4, 5, 6, 7, 8};
        System.out.println(printArray(myarray));
    }
}
