* push new branch to remote
```bash
git push -u origin <branch>
```
* clone and switch to branch
```bash
git clone -b branch xxx
```
* set credential cache for http checkout
```bash
git config --global credential.helper "cache --timeout=3600"
```
* range a..b，b中有a中没有的commit，大致可以理解为左开右闭区间，更多[参考](https://git-scm.com/book/en/v2/Git-Tools-Revision-Selection)。
* clone depth，只包含部分历史，用于节省空间，但不能push代码
```
git clone --depth 1 xxx
```
* 查看历史代码文件
```
git show commit:main.cpp > old_main.cpp
```
* 查看包含某个commit的tag或分支
```
git tag/branch --contains commit
git describe --contains commit
```
* submodule操作
```
# 递归初始化
git submodule update --init --recursive
# 更新
git submodule update --remote
```
* 解决冲突
```
git checkout --theirs .
git checkout --ours .
git mergetool path
```
* 得到短commit
```
git rev-parse --short HEAD
```

* 显示没有track的文件
```
git ls-files -o
```

* stash with custom message
```
git stash push -m xxx
```

* use diff tool to show commit
```
git difftool -y 15dc8^!
```
