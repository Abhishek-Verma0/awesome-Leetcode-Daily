/*726. Number of Atoms
Solved
Hard
Topics
Companies
Hint

Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

    For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.

Two formulas are concatenated together to produce another formula.

    For example, "H2O2He3Mg4" is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.

    For example, "(H2O2)" and "(H2O2)3" are formulas.

Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.



Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.

Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.



Constraints:

    1 <= formula.length <= 1000
    formula consists of English letters, digits, '(', and ')'.
    formula is always valid.

*/

typedef struct
{
    char name[3];
    int count;
} Element;

int compare(const void *s1, const void *s2)
{
    Element *e1 = (Element *)s1;
    Element *e2 = (Element *)s2;
    return strcmp(e1->name, e2->name);
}

char *countOfAtoms(char *formula)
{
    int formulalen = strlen(formula), i, j, coel = 0, num, inpar = 0, valpar, copar, multiplier;
    Element *element = (Element *)malloc(sizeof(Element) * formulalen);

    for (i = 0; i < formulalen; i++)
    {
        if (formula[i] == '(')
            inpar++;
        else if (formula[i] == ')')
            inpar--;

        if (formula[i] < 91 && formula[i] > 64)
        {
            element[coel].name[0] = formula[i];
            if (formula[i + 1] < 123 && formula[i + 1] > 96)
            {
                element[coel].name[1] = formula[++i];
                element[coel].name[2] = '\0';
            }
            else
            {
                element[coel].name[1] = '\0';
            }
            num = 0;
            while (formula[i + 1] < 58 && formula[i + 1] > 47)
            {
                i++;
                num = num * 10 + (formula[i] - 48);
            }
            if (num > 1)
                element[coel].count = num;
            else
                element[coel].count = 1;
            valpar = 0;
            multiplier = 1;
            copar = 0;
            for (j = i + 1; copar < inpar; j++)
            {
                if (formula[j] == '(')
                    valpar++;
                else if (formula[j] == ')' && valpar > 0)
                    valpar--;
                else if (formula[j] == ')')
                {
                    copar++;
                    num = 0;
                    while (formula[j + 1] < 58 && formula[j + 1] > 47)
                    {
                        j++;
                        num = num * 10 + (formula[j] - 48);
                    }
                    multiplier *= num > 1 ? num : 1;
                }
            }
            element[coel].count *= multiplier;
            coel++;
        }
    }

    qsort(element, coel, sizeof(Element), compare);
    j = 0;
    for (i = 0; i < coel; i++)
    {
        strcpy(element[j].name, element[i].name);
        element[j].count = element[i].count;
        j++;
        if (j > 1 && !strcmp(element[j - 2].name, element[j - 1].name))
        {
            element[j - 2].count += element[j - 1].count;
            j--;
        }
    }
    coel = j;

    int dig;
    j = 0;
    for (i = 0; i < coel; i++)
    {
        j++;
        if (element[i].name[1] != '\0')
            j++;
        num = element[i].count;
        if (num > 1)
        {
            for (dig = 10; num % dig != num; dig *= 10)
                ;
            for (dig; dig > 9; dig /= 10)
                j++;
        }
    }
    char *res = (char *)malloc(j + 1);
    res[j] = '\0';
    j = 0;
    for (i = 0; i < coel; i++)
    {
        res[j++] = element[i].name[0];
        if (element[i].name[1] != '\0')
            res[j++] = element[i].name[1];
        num = element[i].count;
        if (num > 1)
        {
            for (dig = 10; num % dig != num; dig *= 10)
                ;
            for (dig; dig > 9; dig /= 10)
                res[j++] = ((num % dig * 10) / dig) + 48;
        }
    }

    free(element);
    return res;
}