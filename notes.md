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