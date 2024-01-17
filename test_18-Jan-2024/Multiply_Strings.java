// leet code problem no : 43
// problem name : Multiply Strings
// problem link : https://leetcode.com/problems/multiply-strings/

// solution: 

class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0"))
            return "0";
        StringBuilder number1 = new StringBuilder(num1);
        StringBuilder number2 = new StringBuilder(num2);
        number1 = number1.reverse();
        number2 = number2.reverse();
        int carry = 0;
        char[] result = new char[num1.length() + num2.length()];
        Arrays.fill(result, '0');

        for (int i = 0; i < number1.length(); i++) {
            int digit1 = number1.charAt(i) - '0';
            for (int j = 0; j < number2.length(); j++) {
                int digit2 = number2.charAt(j) - '0';
                int product = (digit1 * digit2);
                product += (result[i + j] - '0') + carry;
                result[i + j] = (char) ((product % 10) + '0');
                carry = product / 10;
            }
            for (int k = i + number2.length(); carry != 0; k++, carry /= 10) {
                result[k] = (char) ((carry % 10) + '0');
            }
        }

        char ch1;
        for (int i = 0, j = result.length - 1; i < j; i++, j--) {
            ch1 = result[i];
            result[i] = result[j];
            result[j] = ch1;
        }

        int offSet = 0;
        for (offSet = 0; result[offSet] == '0'; offSet++)
            ;
        String ans = new String(result);
        return ans.substring(offSet);
    }
}