/*592. Fraction Addition and Subtraction
Solved
Medium
Topics
Companies

Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.



Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"

Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"

Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"



Constraints:

    The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
    Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
    The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
    The number of given fractions will be in the range [1, 10].
    The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

*/

class Solution
{
public:
    string fractionAddition(string expr)
    {

        int num = 0;
        int den = 1;
        int i = 0;
        int n = expr.length();

        while (i < n)
        {
            int currNum = 0;
            int currDen = 0;
            bool isNeg = (expr[i] == '-');
            if (expr[i] == '+' || expr[i] == '-')
            {
                i++;
            }
            // making of numerator

            while (i < n && isdigit(expr[i]))
            {
                int val = expr[i] - '0';
                currNum = (currNum * 10) + val;
                i++;
            }
            i++; // skipping the divisor character '/';

            if (isNeg == true)
            {
                currNum *= -1;
            }

            // build the denominator

            while (i < n && isdigit(expr[i]))
            {
                int val = expr[i] - '0';
                currDen = (currDen * 10) + val;
                i++;
            }
            num = num * currDen + currNum * den;
            den = den * currDen;
        }
        int GCD = abs(__gcd(num, den)); //-ve
        num /= GCD;
        den /= GCD;
        // num
        //  den
        return to_string(num) + "/" + to_string(den);
    }
};