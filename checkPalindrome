package recursion;
import java.util.Scanner; // import Scanner class

/*
* The following class verifies if a string is a palindrome by recursively calling itself,
* each time with a smaller substring while checking if the first and last characters are equal
*/
public class checkPalindrome {

    static boolean checkPalindrome(String str) {
        if (str.length() < 2) return true;
        return checkPalindrome(str.substring(1, str.length() - 1)) && (str.charAt(0) == str.charAt(str.length() - 1));
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in); // create Scanner object to read input
        System.out.println("Enter a string:");
        String str = myObj.nextLine(); // read string and assign to "str"

        System.out.println("Is " + str + " a palindrome?");
        System.out.println((checkPalindrome(str)) ? "Yes!" : "No!");
    }
}
