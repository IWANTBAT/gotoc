void PrintMinNumber(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        return;
    stringstream ss;//用来数字和字符串转换；
    string* str=new string[length];
    for(int i = 0; i < length; ++i)
    {
        ss.clear();
        ss<<numbers[i];
        ss>>str[i];
     }
 
    sort(str,str+length, compare);
 
    for(int i = 0; i < length; ++i)
        cout << str[i];
    printf("\n");
 
}
 
bool compare(const string strNumber1, const string strNumber2)
{
    string str1 = strNumber1+strNumber2;
    string str2 = strNumber2+strNumber1;
    return str2>str1;
}
