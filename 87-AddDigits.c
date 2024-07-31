

int check(int checknum)
{
    int rem = 0;
    while (checknum > 0)
    {
        rem += checknum % 10;
        checknum = checknum / 10;
    }
    return rem;
}
int addDigits(int num)
{
    if (num < 10)
    {
        return num;
    }
    int ret = check(num);
    if (ret < 9)
    {
        return ret;
    }
    return addDigits(ret);
}


//  Method 2 using Digital root formula having both space and time complexity O(1)

int addDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return 1 + (num - 1) % 9;
}
