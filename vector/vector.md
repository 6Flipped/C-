# vector

## 什么是vector

![image-20220810170128370](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810170128370.png)

> 通过查看文档我们可以知道，vector的本质就是一个可修改大小的顺序容器并且可以看出是一个模板类，说明其中存储的类型不仅仅是int也可以是char甚至string类型的数据

下面来看看vector的常用接口

# vector常用接口

## 构造函数

![image-20220810172045422](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810172045422.png)

这里我们只简单介绍其中常用的几种即可，其中const allocator_type& alloc = allocator_type()是适配器，目前不做讲解，通常情况下不用管，目前可直接忽略。

第一个构造函数就是一个简单的默认构造

```c
	vector<int> v;
```

第二个构造函数是支持用n个val来初始化vector数组

```
vector<int> v(5,1);
```

![image-20220810172644598](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810172644598.png)

第三个构造函数支持迭代器区间初始化

```c
vector<int> v(5,1);
vector<int> v1(v.begin(), v.end()-1);
```

![image-20220810172828326](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810172828326.png)

第四个构造函数支持单参数构造，默认用0填补，其中x为构造出的vector的size

```
vector<int> v2(5);
```

![image-20220810173158068](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810173158068.png)

## begin & end

![image-20220810173503845](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810173503845.png)

![image-20220810173532902](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810173532902.png)

这两个接口比较容易理解，begin返回第一个元素的迭代器，end返回最后一个元素下一个位置的迭代器，称之为正向迭代器。

## rbegin & rend

![image-20220810173736581](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810173736581.png)

![image-20220810173758632](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810173758632.png)

rbegin和rend的关系类似于begin和end，rbegin是最后一个元素的迭代器，rend是第一个元素前一个位置的迭代器，所以也称之为反向迭代器，位置图大致如下：

![image-20220810174247016](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810174247016.png)

这里需要注意的是，迭代器的++都是靠进end或者rend的方向，即正向迭代器++往右走，反向迭代器++往左走。

同时迭代器都支持const版本，如cbegin cend crbegin crend。

## size & capacity

![image-20220810174616245](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810174616245.png)

![image-20220810174636309](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810174636309.png)

size和capacity一个是大小一个是容量，怎么理解呢，其实很简单，就比如一个500ml的矿泉水瓶里面装了300ml的水，其中500ml就是容量表示最多能装多少，而300ml就是当前装了多少。

## resize & reserve

![image-20220810175151256](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810175151256.png)

![image-20220810175211517](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810175211517.png)

resize就是修改size，reserve就是修改capacity，但是reserve只支持扩容，如果缩容的话一般使用下面这个：

![image-20220810175309966](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810175309966.png)

但是一般都不推荐缩容，代价比较大

## insert & erase

![image-20220810175423302](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810175423302.png)

![image-20220810175503431](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810175503431.png)

erase看起来比较简单，我们先介绍erase，可以看到它支持删除指定迭代器位置的数据或者区间，比如下述代码:

![image-20220810180127429](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810180127429.png)

可以看到成功删除的头和尾，删除单个数据

![image-20220810180244099](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810180244099.png)

删除迭代器区间



下面看插入

第一个版本插入即在迭代器前面插入val，如：

![](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810180522337.png)

在1前面成功插入0

第二个支持在迭代器位置前插入n个val，如：

![image-20220810180618582](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810180618582.png)

成功在1前插入3个0

第三个支持在迭代器位置前插入一个迭代器区间，如：

![image-20220810180754727](C:\Users\6Flipped\AppData\Roaming\Typora\typora-user-images\image-20220810180754727.png)

# 迭代器失效



# vector模拟实现



