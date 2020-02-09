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
