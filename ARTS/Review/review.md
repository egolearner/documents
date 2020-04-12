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

## [Off-CPU Analysis](http://www.brendangregg.com/offcpuanalysis.html)
* 20200315
* ⭐⭐⭐
#### 主要内容
Off-cpu性能分析，即分析程序block的时间，如等待io、等待mutex等的分析，对应下图蓝色部分。
![](http://www.brendangregg.com/Perf/thread_states.png)
文中使用的工具依赖eBPF，需要4.8以上kernel，公司内还用不了。

题外话，动态追踪技术之前听说过systemtap，翻过eBPF的书，但没有实战过。本来觉得eBPF比stap领先，但看了openresty的[这篇文章](https://blog.openresty.com.cn/cn/dynamic-tracing/)，里面说“eBPF 在设计上一直有严重的限制，使得那些基于 eBPF 开发的动态追踪工具始终停留在较为简单的水平上”，再加上公司内用不了eBPF，还是先学下stap吧。

## [The Problem with Saying “Don’t Bring Me Problems, Bring Me Solutions”](https://hbr.org/2017/09/the-problem-with-saying-dont-bring-me-problems-bring-me-solutions)
* 20200322
* ⭐⭐
#### 主要内容
“提出解决方案而非问题”的问题在于并非所有问题都有简单的解决方案，每个人只用自己的视角解决问题，引导“报喜不报忧”的氛围。解决变法为
* Make it safe. 让人们不怕带来坏消息。（想到了王小波的《花刺子模信使问题》）。
* 要求提供问题描述而非抱怨。抱怨的特点是很多绝对性的语句（总是，每次)，缺失事实性的描述，把人们描述为恶棍（他们）和英雄（我们）。而问题描述提供客观事实，分析底层原因，包括每个人在导致问题上的角色，甚至不避讳问题提出者自身。（类似于《非暴力沟通》中的区分事实和判断）。
* 找到解决问题的正确的人。提出者有能力解决但可能需要授权或者指导，或者需要其他人来解决。
#### 评论
带着方案提问题 > 提出问题 >> 让问题悄悄发酵。

## [Peeking into Linux kernel-land using /proc filesystem for quick’n’dirty troubleshooting](https://tanelpoder.com/2013/02/21/peeking-into-linux-kernel-land-using-proc-filesystem-for-quickndirty-troubleshooting/)
* 20200329
* ⭐⭐⭐
#### 主要内容
利用/proc定位进程hang的分析过程
1. top查看进程的使用率为0，说明进程要么完全卡住、要么周期性的从等待状态醒来再去等待
2. strace和psatck都卡住
3. `ps -flp pid`查看WCHAN列，其含义为进程sleep时kernel执行的函数。确定是在等rpc。
```shell
[root@oel6 ~]# ps -flp 27288
F S UID        PID  PPID  C PRI  NI ADDR SZ WCHAN  STIME TTY          TIME CMD
0 D root     27288 27245  0  80   0 - 28070 rpc_wa 11:57 pts/0    00:00:01 find . -type f
# 显示不完整，通过cat命令查看完整的wchan
[root@oel6 ~]# cat /proc/27288/wchan
rpc_wait_bit_killable
```
4. 通过查看context swich count看进程是否完全卡住，发现上下文切换数没有增加
```shell
[root@oel6 ~]# cat /proc/27288/status
State:	D (disk sleep)
voluntary_ctxt_switches:	9950
nonvoluntary_ctxt_switches:	17104

# 也可以从sched查看
cat /proc/27288/sched
nr_switches                        :                27054
nr_voluntary_switches              :                 9950
nr_involuntary_switches            :                17104
```
5. 查看进程正在执行的系统调用
```shell
[root@oel6 ~]# cat /proc/27288/syscall
262 0xffffffffffffff9c 0x20cf6c8 0x7fff97c52710 0x100 0x100 0x676e776f645f616d 0x7fff97c52658 0x390e2da8ea

[root@oel6 ~]# grep 262 /usr/include/asm/unistd_64.h
#define __NR_newfstatat				262
```
6. 查看newfstatat的调用栈
```shell
[root@oel6 ~]# cat /proc/27288/stack
[] rpc_wait_bit_killable+0x24/0x40 [sunrpc]
[] __rpc_execute+0xf5/0x1d0 [sunrpc]
[] rpc_execute+0x43/0x50 [sunrpc]
[] rpc_run_task+0x75/0x90 [sunrpc]
[] rpc_call_sync+0x42/0x70 [sunrpc]
[] nfs3_rpc_wrapper.clone.0+0x35/0x80 [nfs]
[] nfs3_proc_getattr+0x47/0x90 [nfs]
[] __nfs_revalidate_inode+0xcc/0x1f0 [nfs]
[] nfs_revalidate_inode+0x36/0x60 [nfs]
[] nfs_getattr+0x5f/0x110 [nfs]
[] vfs_getattr+0x4e/0x80
[] vfs_fstatat+0x70/0x90
[] sys_newfstatat+0x24/0x50
[] system_call_fastpath+0x16/0x1b
[] 0xffffffffffffffff
```

##### 穷人的内核线程profile
```shell
[root@oel6 ~]# export LC_ALL=C ; for i in {1..100} ; do cat /proc/29797/syscall | awk '{ print $1 }' ; cat /proc/29797/stack | /home/oracle/os_explain -k ; usleep 100000 ; done | sort -r | uniq -c
@oel6 ~]# export LC_ALL=C ; for i in {1..100} ; do cat /proc/29797/syscall | awk '{ print $1 }' ; cat /proc/29797/stack | /home/oracle/os_explain -k ; usleep 100000 ; done | sort -r | uniq -c
     69 running
      1 ffffff81534c83
      2 ffffff81534820
      6 247
     25 180

    100    0xffffffffffffffff
      1     thread_group_cputime
     27     sysenter_dispatch
      3     ia32_sysret
	  ...
```

#### 评论
`proc`文件系统有必要系统性的看下，文章提到的很多文件都是第一次看到。

## [Tips From The Top: One On One With Eric Yuan, Founder & CEO Of Zoom](https://thriveglobal.com/stories/tips-from-the-top-one-on-one-with-eric-yuan-founder-ceo-of-zoom/)
* 20200405 7分钟
* ⭐⭐
#### 主要内容
ZOOM CEO兼创始人Eric Yuan的采访，比较偏鸡汤。新冠期间ZOOM股票有大涨？又正好看到了这篇采访。

##### 主要经历
大学时要坐10个小时火车去看女朋友，所以埋下了做视频聊天的种子。在webex做视频会议系统做了14年。创业契机是和消费者打交道时发现当前方案在易用性、可靠性、视频质量上存在根本缺陷，需要完全推倒重来，没有成功说服Cisco高层，因而2011年创立了ZOOM。

##### 创业最重要的教训
客户第一

##### 好的领导者的标准
* 自驱
* 不断学习新科技、新技术、新东西
* 关心下属和客户

##### 给创业者的建议
* 创业维坚，但也令人兴奋、妙趣横生。
* 不要过于看重招聘纸面上最合适的人才，自驱和自我学习是最重要的要素。
* 发展正确的企业文化是最重要的事。

##### 别人给的最有用的建议
* 找到愿意投资“你”的投资人，而不仅仅是你的公司，可以得到更多的信任和支持。

## [How Complex Systems Fail ](http://web.mit.edu/2.75/resources/random/How%20Complex%20Systems%20Fail.pdf)
* 20200412，约25分钟
* ⭐⭐
* [视频](http://www.itskeptic.org/great-paper-failure-complex-systems)
#### 主要内容
关于复杂系统为什么失败的小论文，一些有体会的点包括
* 1 复杂系统本质上就是高风险的。内部的各种风险驱动了防御式的设计（也就是2）。
* 3 灾难需要多个失败，单点故障不足以导致灾难。虽然每个失败都有可能造成灾难，但因为有2的防御，多个失败才足够导致灾难。换句话说，可能的失败机会远比表现出的系统故障要多。
* 4 复杂系统包含多个潜在风险的可变混合物。经济成本和可行性决定了风险无法彻底消除。
* 5 因此系统永远运行在降级模式。
* 7 事后灾难归因根本上就是错的。故障需要多个错误（3），因此没有完全隔离的根因。
* 8 后见之明导致事后评估人员表现出现偏差。事后看导致问题的原因比当时看更加显而易见。
* 9 从业者的双重身份：生产者和事故预防者。事故前强调生产者的身份，事故后强调预防者的身份。
* 10 所有从业者行为都是在赌博。发生事故时如此，正常运行时也是如此。
* 13-14 人的经验一直在变，改变又会引入新的失败。
#### 评论
面对复杂系统我们能做什么？
* 设立规章制度。人是最不可靠的，需要将过去的规律、事故分析总结成规章制度，要求严格按照制度来做，一如飞行员的检查清单一样。至于制度束缚人的创造力就是另一话题了。
* 自动化测试和定期演练。这里主要针对软件系统。通过自动化测试及时发现系统的降级，使用类似chaos monkey的手段来倒逼系统的可靠性。
* 积累经验。从自己的失败甚至是别人的失败学习经验。