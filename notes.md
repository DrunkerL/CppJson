### 1.C++中一个类中出现string str() const;
函数声明后加const表示该函数不能在函数实现中更改成员变量的值

### 2.使用初始化列表来初始化字段
```c++
Line::Line( double len): length(len){
    
}
```
等价于（length是成员变量）
```c++
Line::Line( double len)
{
    length = len;
}
```
### 3.operator int()用法
* operator int() 是类型转换运算符
* 该函数的返回值类型就是函数名，所以不用显式地表示出。
  返回类型是int，函数名也是int，就是说不写成 int operator int() const { return value; }，
  返回类型被省去了。

### 4. vector.erase()用法
`erase函数可以用于删除vector容器中的一个或者一段元素，在删除一个元素的时候，其参数为指向相应元素的迭代器，而在删除一段元素的时候，参数为指向一段元素的开头的迭代器以及指向结尾元素的下一个元素的迭代器；
在进行单个元素删除后，传入的迭代器指向不变，仍然指向被删除元素的位置，而被删除元素之后的所有元素都向前移动一位，也就是该迭代器实际上是指向了原来被删除元素的下一个元素。
删除一段元素后，传入的迭代器指向也是不变的，仍然指向原来传进去时候的位置，修改的是删除段后面的元素的位置。`
```c++
#include<iostream>
#include<vector>
using namespace std;
 
int main(void)
{
    vector<int>array;
    array.push_back(200);
    array.push_back(30);
    array.push_back(300);
    array.push_back(50);
    array.push_back(60);
    vector<int>::iterator itor;
    //删除单个元素
    for (itor = array.begin(); itor != array.end(); itor++)
    {
        if (*itor == 300)
        {
            itor = array.erase(itor);
        }
    }
    for (itor = array.begin(); itor != array.end(); itor++)
    {
        cout << *itor << " ";
    }
    cout << endl;
    //删除一段元素
    vector<int>::const_iterator iter_begin = array.begin() + 1;
    vector<int>::const_iterator iter_end = array.end() - 1;
    array.erase(iter_begin, iter_end);
    for (itor = array.begin(); itor != array.end(); itor++)
    {
        cout << *itor << " ";
    }
    //删除最后一个元素
    vector<int>::iterator iter_last = array.end() - 1;
    array.erase(iter_last);
    for (itor = array.begin(); itor != array.end(); itor++)
    {
        cout << *itor << " ";
    }
    return 0;
}
```