* set dns
```bash
# 得到网络名称，如Wi-Fi
networksetup -listallnetworkservices
# 得到已有dns
networksetup -getdnsservers Wi-fi
# 设置dns
sudo networksetup -setdnsservers Wi-fi server1 server2
# 在已有dns基础上插入
sudo networksetup -setdnsservers Wi-fi 8.8.8.8 `networksetup -getdnsservers Wi-fi`
```

* 系统自带的可视化截图
快捷键`Cmd+Shift+5`，可以设置保存的目录，截图后可以调用Preview编辑。点`Capture`的时候按住`control`键可以复制到剪贴板。然而没找到Preview编辑后再复制到粘贴板的操作。相比其他的截图软件还是不好用，好在可以救急。