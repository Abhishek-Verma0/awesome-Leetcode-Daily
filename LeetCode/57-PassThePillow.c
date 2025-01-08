/*Approach 🪜

Steps :

  1:  Find division and remainder between time and (n - 1).
    

   2: If div is even i.e. it will pass from 1st person to 2nd person to 3rdand so on.. otherwise will pass from n - 1th to n - 2th and so on..

   3: Therefore when div is even we will return rem + 1 otherwise will return
    n - rem.

*/

int passThePillow(int n, int time) {
    int div = time / (n - 1);
    int rem = time % (n - 1);

    return div % 2 == 0 ? rem + 1 : n - rem;
}