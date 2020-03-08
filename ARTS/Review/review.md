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

## [Vue.js: The Documentary](https://www.youtube.com/watch?v=OrxmtDw4pVI)
* 20200229，34分钟
* ⭐⭐⭐

关于Vue.js的记录片，有印象的点包括：
* Vue是view的法语，发音相同。想起内部某项目也是用法语命名，大概是英文不够fancy，常用词在搜索引擎中也不好搜的缘故吧。
* 作者在Google做可视化工作时发起的个人项目。side-project最好还是和工作有关，比较容易得到反馈。
* 早期的重要传播节点为Laravel的创始人。项目质量重要，大V引流同样重要。
* 重视中文社区的建设，一方面作者是中国人，另一方面中国的开发者在开源界越来越重要。

## [Writing Docs at Amazon](https://blog.usejournal.com/writing-docs-at-amazon-e025808616bd)
* 20200308, 加上一个链接约20分钟
* ⭐⭐
#### 主要内容
[这篇文章](https://slab.com/blog/jeff-bezos-writing-management-strategy/)讲，亚马逊老板Bezos在公司禁止使用PPT，而是要求写6页信息密集的故事体的结构化备忘录，因为"Clear Thinking Is Clear Writing"。原因包括：ppt信息量低，丢失很多信息，利于演讲者不利于听众；便于传播头脑风暴的结论。

本文主要讲Amazon写文档的方式。

0. 一般为段落或散文，不能光有要点，还需要有支撑性的语句。
1. 注意语法和拼写错误。
2. 理解文档要达到的目标。
3. Minimize surface area / leave out extraneous stuff。要切题，无关内容写到另外的文档中。
4. 开会时有合适的人出席。
5. Check your ego at the door. 大意是Bezos会挑战，准备好辩论、讨论或者改变心态。
6. Be sure to “show your work.” 文中举例说如果团队内有讨论的话，要把各种观点和最终结论写清楚，给出的理由是Bezos有更全面的信息，文档的观点可能明显有错误或者对于公司是不必要的。
7. 客户第一（Represent and advocate for the customer）。
8. 不要让同事或老板吃惊，不能会前悄悄改文档。
9. 文档不完备的话，延期开会。
10. 想得足够大。如果文档是确定问题或者给出方案，想清楚后面的逻辑。举例是如果某方案是把竞争对手的差距从20年减少到10年，Bezos是不满意的。
11. Read the room（意思是to understand the emotions and thoughts of the people in the room）。说服不了老板的话，准备更多的论据或者换种方式，或者被老板说服。
12. 不能模糊或者过于戏剧化，要有数字。

#### 评论
文档的信息量反而不如引文大，大多数条款是众所周知的，正如作者说"the rules of the road for an Amazon document are no different than those for good, clear writing in general"。比较有启发的是2和10，永远不要忘记目标，要有大局观。

引文只读了关于写作的部分，后面有时间再全部读下。

再强调下，Clear Thinking Is Clear Writing。