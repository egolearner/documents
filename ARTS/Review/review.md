## [Your Life is Driven by Network Effects](https://www.nfx.com/post/your-life-network-effects)
* 20200207， 20分钟阅读时间+10分钟看[youtube视频](https://www.youtube.com/watch?v=HdnXuKi_2Zw)，文章太长，没有完整看完。
* ⭐⭐
#### 摘抄
* What that means is that the little decisions you make daily, the ones you fret over, are orders of magnitude less important than the crossroads decisions you make.
* The most lasting and effective way to change your life is to change who you’re surrounded by. Since networks so powerfully shape who we are and what we do, the best way to change ourselves is to change our networks.
* Zipf’s Law 100年前，研究发现使用第二频繁的英文单词是第一频繁的1/2，第三频繁是第一的1/3。
* 邓巴数：150认识/45熟人/15朋友/5密友
#### 评论
人是群居动物，所在的群体反过来也影响我们，作者说得更直接，人生由网络效应驱动。影响最大的事件称为人生十字路口，有下面的条件：
* 高频重复接触。
* 群体内有高度的重合性。
* 人们处于倾向于改变或进化身份认同的变更期。
* 距离上的稠密性
* 处于困难的阶段

于是定义了七个对人生有重大影响的十字路口：
* 家庭
* 高中
* 大学
* 第一份工作
* 人生伴侣
* 所在城市
* 反思。人有自由意志，永远可以做出新的选择。

除第七个外，其中影响最大的个人觉得是家庭和人生伴侣，基本会影响一生，像高中、大学、第一份工作在某个阶段无疑会有很重要的影响，但随着时间推移，影响越来越小。所在城市这点想到最近的新冠肺炎，心有戚戚，君子不立危樯之下，一定要主动做好选择。

## [Fun with NULL pointers](https://lwn.net/Articles/342330/)
* 20200215，大概30分钟
* ⭐⭐
#### 主要内容
文章讲了一系列问题导致的内核漏洞。
```c
+	struct sock *sk = tun->sk;
	if (!tun)
	    return POLLERR;
```
上面带+号的一栏，在检查空指针前先解引用了指针，gcc的逻辑是dereference空指针是UB行为，前面dereference了指针，gcc认为指针一定不为空，因此将后面的if检查优化没了。LLVM之父有篇关于LLVM利用UB做优化的[博客](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html)，后面有空再好好看下。\
正常内存第0页是通过`mmap_min_addr`保护的，不允许映射第0页，但是SELinux开启之后反而允许了。攻击者mmap到第0页后，`sk`受攻击者控制，可以继续运行后面的攻击逻辑。
#### 评论
安全问题就像木桶效应，有一个环节有问题就前功尽弃。\
以前没考虑过0地址也是可以有内容的。

## [Move, simply](https://herbsutter.com/2020/02/17/move-simply/)
* 20200222，大概20分钟
* ⭐⭐
#### 主要内容
`move`和一般的接收非常量引用参数的函数没区别，可能修改也可能不修改对象，move后对象处于“没有具体说明的有效状态”（“valid but unspecified state,”）。move之后需要继续满足类的不变式。
#### 评论
C++11之后的概念越来越多，就像C++之父说的"C++11 is like a new language"。不过一切为了性能都是值得的，毕竟c++是多范式语言，提供了各种选择但没有强制要求用或不用，条件是团队内关于使用的语言特性要达成一致。另外没想到2020年Herb Sutter还会再写一篇类似move FAQ的博客。