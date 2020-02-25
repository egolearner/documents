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
